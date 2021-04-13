---
title: "Spring MVC"
excerpt: 개념 정리
permalink: /study/28
categories:
  - study
  - spring
tags:
  - study
  - spring
  
last_modified_at: 2021-04-13
---  
### Spring MVC 학습 테스트  
1. mapping: 요청을 메서드에 연결하는 부분  
- Request Mapping  
class 선언부 앞에 @RequestMapping(baseURL)  
`@GetMapping`, `@PostMapping`, `@PutMapping`, `@DeleteMapping`, `@PatchMapping`으로 선언하고 사용  
```java
@RestController
@RequestMapping("/persons")
class PersonController {

    @GetMapping("/{id}")
    public Person getPerson(@PathVariable Long id) {
        // ...
    }

    @PostMapping
    @ResponseStatus(HttpStatus.CREATED)
    public void add(@RequestBody Person person) {
        // ...
    }
}
```  

- @Controller vs @RestController  
HTTP Response Body가 생성되는 방식의 차이  
@Controller: View/Data를 반환하기 위해 사용  
`Client -> Request -> Dispatcher Servlet -> Handler Mapping -> Controller -> View -> Dispatcher Servlet -> Response -> Client`
@RestController: Json 형태로 객체 데이터 반환  
`Client -> HTTP Request -> Dispatcher Servlet -> Handler Mapping -> RestController (자동 ResponseBody 추가)-> HTTP Response -> Client`  
Controller에 ResponseBody 추가해서 처리할 수도 있음  

- URI patterns  
@RequestMapping("여기에 매핑할 url")  
`/resources/ima?e.png` - 한글자 매칭  
`/resources/*.png` - 없거나 여러 글자 매칭  
`/resources/**` - 여러 개 매핑  
`/projects/{project}/versions` - @PathVariable String project로 매핑  
```java
@GetMapping(path = "/users/{id}")
public ResponseEntity<User> pathVariable(@PathVariable Long id) {
    User user = new User(id, "이름", "email");
    return ResponseEntity.ok().body(user);
}
@GetMapping(path = "/patterns/?")
public ResponseEntity<String> pattern() {
    return ResponseEntity.ok().body("pattern");
}

@GetMapping(path = "/patterns/**")
public ResponseEntity<String> patternStars() {
    return ResponseEntity.ok().body("pattern-multi");
}
```  
`/projects/{project:[a-z]+}/versions` - 정규표현식으로 매핑  

- consumable media types  
```java
@PostMapping(path = "/pets", consumes = "application/json") 
```  
!text/plain 하면 text/plain 말고 모든 형식  
값이 보내져서 사용될 형태(수신 데이터 포맷 정의)    

- producible media types  
```java
@GetMapping(path = "/pets/{petId}", produces = "application/json") 
@GetMapping(path = "/users", produces = "text/html")
```  
값을 얻어서 사용할 형태(출력 데이터 포맷 정의)  

- Parameters, headers  
```java
    @GetMapping(path = "/message", params = "name=hello")
    public ResponseEntity<String> messageForParam() {
        return ResponseEntity.ok().body("hello");
    }

    @GetMapping(path = "/message", headers = "HEADER=hi")
    public ResponseEntity<String> messageForHeader() {
        return ResponseEntity.ok().body("hi");
    }
}
```
HEADER: headerName  
hi: headerValue  

<br>

2. handler: 요청을 처리하는 부분  
- [method arguments](https://docs.spring.io/spring-framework/docs/current/reference/html/web.html#mvc-ann-arguments)  

- [return values](https://docs.spring.io/spring-framework/docs/current/reference/html/web.html#mvc-ann-return-types)  

- @RequestParam  
```java
    @GetMapping("/users")
    public ResponseEntity<List<User>> requestParam(@RequestParam("name") String userName) {
        List<User> users = Arrays.asList(
                new User(userName, "email"),
                new User(userName, "email")
        );
        return ResponseEntity.ok().body(users);
    }
```  
생략 가능: @RequestParam의 어노테이션의 required 플래그를 `false`로 설정하거나 `java.util.Optional` 래퍼로 인수를 선언하면 메서드 매개 변수가 선택 사항임을 지정할 수 있다.  
@RequestParam의 선언 자체가 선택 사항이다. Map<>으로 선언되면은 request parameter의 값들로 이름이 지정된다.  

- @ModelAttribute  
주석을 이용해 모델의 속성에 접근하거나 존재하지 않으면 인스턴스화하기도 한다.  
모델 속성은 필드 이름과 일치하는 http servlet 요청 매개 변수의 값으로 데이터 바인딩 된다.  
이는 @RequestParam과 달리 도메인 값/요청 파라미터에 바인딩된다.  

- @RequestBody  
`HttpMessageConverter`를 이용해 body에 객체 자체를 전달해서 사용할 수 있다.  
```java
    @PostMapping("/users/body")
    public ResponseEntity requestBody(@RequestBody User user) {
        User newUser = new User(1L, user.getName(), user.getEmail());
        return ResponseEntity.created(URI.create("/users/" + newUser.getId())).body(newUser);
    }
```  

- @ResponseBody  
`HttpMessageConverter`를 이용해 나온 값 자체를 body로 넣을 수 있다.  

- @ResponseEntity  
@ResponseBody랑 유사하지만 ResponseEntity 자체를 만들어서 status와 headers가 같이 간다.  
body는 body에 들어갈 것만 생각했다면 entity자체를 보내는 것이다.  
```java
   @GetMapping(path = "/users/{id}")
   public ResponseEntity responseEntity(@PathVariable Long id) {
       return ResponseEntity.ok(new User("name", "email")); //얘네가 body가 된다.
   }

   @GetMapping(path = "/members")
   public ResponseEntity responseEntityFor400() {
       return ResponseEntity.badRequest().build();
   }
```  
<br>  

3. exception: 요청에 대한 예외처리 부분  
- ExceptionHandler  
메서드에 어노테이션 선언하고 Class선언이 꼭 필요하다.  
ExceptionHandler가 따로 있어서 그 class와 관련된 exception이 던져지면 동작하는 것이다.  

```java
@RestController
@RequestMapping("/exceptions")
public class ExceptionsController {
    @GetMapping("/hello")
    public ResponseEntity exceptionHandler() {
        throw new CustomException();
    }
    @GetMapping("/hi")
    public ResponseEntity exceptionHandler2() {
        throw new HelloException();
    }
    @ExceptionHandler(CustomException.class)
    public ResponseEntity<String> handle() {
        return ResponseEntity.badRequest().body("CustomException");
    }
}
```  
@Controller나 @ControllerAdvice 어노테이션을 가진 클래스들은 @ExceptionHandler를 가질 수 있다.  
```java
@ControllerAdvice()
public class HelloAdvice {
    @ExceptionHandler(HelloException.class)
    public ResponseEntity<String> handle() {
        return ResponseEntity.badRequest().body("HelloException");
    }
}
```  