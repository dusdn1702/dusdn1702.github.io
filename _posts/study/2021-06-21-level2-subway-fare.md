---
title: "level2 학습 로그"
excerpt: 지하철 요금 미션
permalink: /study/48
categories:
  - techcourse
tags:
  - techcourse

last_modified_at: 2021-06-21
---  

## 협업미션 - 지하철 요금 적용

### [infra] SSL/TLS  
- Secure Sockets Layer  
웹사이트와 브라우저 사이에 전송된 데이터를 암호화하여 보안을 유지하는 표준 기술(프로토콜)  

- Trasport Layer Security  
Application Layer <----TLS Layer----> Transport Layer  
[핸드셰이크 과정](https://namu.wiki/w/TLS#s-1.3.5)  
1. Client Hello: 클라이언트는 서버에게 지원 가능한 방식(암호, 키교환, 서명 등)을 서버에 알려준다.  
2. Server Hello: 서버는 클라이언트에게 지원 가능한 방식을 응답  
3. Certificate Message: 서버는 공개키(RSA 암호)가 포함된 서버 인증서 클라이언트에 발송  
4. Server Hello Done: 서버의 전송 끝나면 메시지 전달  
5. Client Certificate: 서버가 클라이언트 인증서를 요구할 때 클라이언트가 서버에 인증하기 위한 SSL 인증서 전송  
6. 클라이언트는 전송받은 서버 인증서가 유효한지 확인하고, 세션키로 사용될 `Pre-Master Key`를 랜덤으로 생성해 공개키로 암호화해 서버로 전송,  ClientKeyExchange 메시지에 Pre-Master Key가 포함된다.  
7. 서버는 자신의 개인키로 클라이언트에게 전송받은 세션키(대칭키) 복호화해서 `Pre-Master key`를 알아낸뒤 이를 이용해 master secret 생성  
이후로 master secret에서 세션 키 생성해내고 서버-클라이언트 간 통신을 암호화하는 데에 사용한다.  
8. 서로에게 `ChangeCipherSpec` 메시지를 보내고, `Finished` 메시지를 보내 과정이 끝남을 알린다.  

### [network] LAN vs WAN  
- Local Area Network  
공유기나 스위치를 이용해 연결된 회사, 집 등의 지역 네트워크  
ethernet 프로토콜 TCP/IP 사용  
- Wide Area Network  
LAN과 LAN 사이를 광범위한 지역 단위로 구성하는 네트워크  
전용선, 회선 교환, 패킷 교환, 셀 릴레이 사용해 연결  

### [infra] Reverse Proxy  
Internet <--> Proxy <--> Web server  
was가 비즈니스 로직만 담당하도록 하고 TLS와 같은 부수적인 기능으로 영향을 주고 싶지 않을 때 사용  
보안성(백엔드 infra 숨김), 확장성, 웹 속도 향상, 압축/ssl 처리로 백엔드 자원 확보/캐싱  

`Reverse Proxy`는 클라이언트로부터 요청을 받아서 적절한 웹 서버로 요청 전송 -> 웹 서버는 요청 받아 처리 후 `reverse proxy`로 반환 -> `reverse proxy`는 응답을 클라이언트로 반환  
- (foward) proxy: LAN -> WAN 요청 대리 수행, 여러 클라이언트에 대한 프록시  
- reverse proxy: WAN -> LAN 요청 대리 수행, 여러 서버에 대한 프록시  
ex) nginX  
[참고](https://brainbackdoor.tistory.com/113)  

### [network] load balancer
서버에 접근하는 작업량을 분산시켜 부하를 분산해주고, 서버상태를 체크하고, 세션 관리를 해준다.  

사용 알고리즘
- round robin: 요청을 순서대로 각 서버에 배분  
- Least Connection: 서버에 연결되어 있는 수가 가장 적은 서버에 연결  
- Weighted Least Connection: 서버의 처리 능력에 가중치를 두어 가중치와 least conneciton을 종합 판단해 적절한 서버에 연결  
- Fastest Response Time: 가장 빨리 응답하는 서버에 연결 
- Hashing: 사용자의 IP를 해싱해 연결, 동일한 사용자는 동일한 서버에 연결  

종류
- L4: Transport layer에서 수행, 패킷 레벨에서 밸런싱해 빠르고 안전, 저렴, 섬세한 라우팅 불가능, 연속적인 서비스 제공 불가  
- L7: Application layer애서 수행, 캐싱 기능, 섬세한 라우팅, 비정상적인 트래픽 사전 필터링 가능, 비쌈, 보안 상 위험  

이점  
- 비용 절감  
- SPOF 해결: 단일 서버 에러 발생 시 모든 동작 불가능한 것 해결  
- 확장 용이성: 더 많은 사용자에 대해 서버 확장 시 용이  

### [network] 네트워크 스캐닝  
네트워크를 통해 제공하고 있는 서비스, 포트, host 정보 등을 알아내는 것  
Nmap, WPScan, Nikto, Netcat 등을 이용해 스캔할 수 있음  
서버의 상태, 사양, 취약점과 같은 각종 정보를 쉽게 탐색  
- WPScan을 사용한 탐색 방법  
--url : 해당 url의 워드프레스 사이트를 스캐닝한다.  
--username : 해당 사용자 이름으로 Brute Force Attack을 실행한다.  
--wordlist : 지정한 워드리스트를 이용하여 패스워드 Brute Force Attack을 실행한다.  
--enumerate p : 해당 워드프레스에 설치된 플러그인을 열거한다. (u: 사용자 이름, vp: 취약점 있는 플러그인, vt: 취약점 있는 테마)  
위 옵선을 이용해 원하는 값 도출 ex) `wpscan --url http:128.0.0.1/hi --enumerate p`  

### [network] wireshark의 사용  
네트워크 패킷을 캡처하고 분석하는 도구  
네트워크로 돌아다니는 패킷(데이터)을 수신해 저장  
- 패킷 스니핑  
네트워크 상에서 자신 이외의 사용자들의 패킷을 엿보는 것  
tcp/ip 통신은 평문 통신을 하기에 스니핑에 취약  
display filter -> string, packet details로 바꾸고 날라가는거 찍어보면 평문화인지 볼 수 있음  
따라서 스니핑을 방지하기 위해 TLS 사용  

### [Spring] Configuration
xml 파일로 bean 등록하기  
학습테스트 해보기
@Configuration 주면 메타 데이터 줄 수 있어진다.
```java
@Bean 
public AuthService authService() {
    return new AuthService();
}
```  

@PropertiesSource, @Value를 통해 외부 파일의 값 받아오기

### [IntelliJ] 내가 원하는 설정 적용해서 돌리기
application-local, application-test, application-prod와 같이 설정이 나뉠때  
빌드 망치 옆에 select box -> edit configurations -> active profiles에서 원하는 설정 선택  
혹은, active profiles 이므로 `@Profile("local")`를 주고 특정 클래스를 상황에 따라 돌리거나, `@ActiveProfiles("test")` 같이 설정을 주고 돌릴 수도 있다.  

### [Spring] validation
- validation으로 잘못된 거를 customException으로 잡아서 던지기
```java
    @ExceptionHandler(MethodArgumentNotValidException.class)
    public ResponseEntity<ExceptionResponse> validExceptionHandle(MethodArgumentNotValidException e) {
        String message = Objects.requireNonNull(e.getBindingResult().getFieldError()).getDefaultMessage();
        ExceptionResponse exceptionResponse = new ExceptionResponse(new InvalidInputException(message));
        return ResponseEntity.badRequest().body(exceptionResponse);
    }
```  
- Notnull vs NotEmpty vs NotBlank  
NotNull: null만 비허용
NotEmpty: null과 Blank(""만) 다 비허용
NotBlank: Blank만 비허용 "", " "
- `@Email`
이메일 형식에 맞는지 확인  
null이 가능하다고 보므로 NotNull 확인 필요
- `@Pattern`
```java
    @Pattern(regexp = "^[a-zA-Z0-9._%+]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]*$", message = "이메일에는 특수문자가 포함될 수 없습니다.")
```  
[정규표현식](https://m.blog.naver.com/PostView.naver?blogId=bsos1202&logNo=220785976962&proxyReferer=https:%2F%2Fwww.google.com%2F)  

### [Spring] dto 변환의 위치  
- dto 변환을 service에서  
controller는 presentation 계층이다.  
controller는 dto들만 알고 있다.  
controller에서 보낸 요청을 수행한 service는 dto로 변환하는 과정까지 거친다.  
이를 통해서 우리의 소중한 domain 로직에 대해서 숨길 수 있다.  
하지만 요청, 응답은 언제든 바뀔 수 있을텐데, controller가 아닌 service에서 변환 로직을 가지면 특정 controller에 service가 의존하게 되어 종속적이라는 단점이 존재한다.  
애초에 layered architecture가 나타난 이유가 계층간 종속성을 줄이기 위해서라는 관점에서 보면 이게 과연 옳은가? 라고 생각할 법 하다.  

- dto 변환을 controller에서  
controller가 우리의 소중한 도메인 로직까지 모두 알고 있다.  
기껏 캡슐화로 관리한 도메인 로직이 표현 계층까지 진출하는 것이 옳을까?  
controller에서 만들어낸 도메인 로직을 service에 전달하기 때문에 service는 비즈니스 로직을 수행하는 책임만 담당하면 된다.  
단 이경우, dto와 도메인이 1:1로 매핑되어야할 것 같다는 샌각이 든다.  

### [Spring] SimpleJdbcInsert  
기존 jdbc로 삽입하고 auto increment를 가져오려면 keyHolder의 사용이 필요했다.  
spring에서 제공하는 SimpleJdbcInsert를 사용하면 리턴 값으로 id를 준다.  
```java
    private final JdbcTemplate jdbcTemplate;
    private final SimpleJdbcInsert simpleJdbcInsert;

    public SectionDao(JdbcTemplate jdbcTemplate, DataSource dataSource) {
        this.jdbcTemplate = jdbcTemplate;
        this.simpleJdbcInsert = new SimpleJdbcInsert(dataSource)
            .withTableName("SECTION")
            .usingGeneratedKeyColumns("id");
    }
```  

SimpleJdbcInsert로 주입 받고 `Long lineId = insertAction.executeAndReturnKey(params).longValue();`로 사용할 수 있다.  

이와 유사하게 urd도 NamedParameterJdbcTemplate, BeanPropertySqlParameterSource과 같이 간단히 해주는 클래스들이 있다.  

### [Spring] API 문서 자동화 하기  
- Swagger로 자동화하기  
    1. build.gradle에 의존성 추가  
    ```
	compile group: 'io.springfox', name: 'springfox-swagger2', version: '3.0.0'
	compile group: 'io.springfox', name: 'springfox-swagger-ui', version: '3.0.0'

	implementation "io.springfox:springfox-boot-starter:3.0.0"
    ```  
    2. 프로젝트에 Swagger 설정 Bean 등록  
    SwaggerConfig.java 생성  
    ```java
    @Configuration
    @EnableSwagger2
    public class SwaggerConfig {
        @Bean
        public Docket api() {
            return new Docket(DocumentationType.SWAGGER_2)
                    .select()
                    .apis(RequestHandlerSelectors.any()) // 현재 RequestMapping으로 할당된 모든 URL 리스트를 추출
                    .paths(PathSelectors.ant("/api/**")) // 그중 /api/** 인 URL들만 필터링
                    .build();
        }
    }
    ```  
    설정 파일의 조작으로 원하는 것을 다양하게 얻어낼 수 있다.  
    안될 경우 [여기](https://apitools.dev/swagger-parser/online/)서 swagger 문법에 문제 없는지 확인  
    3. `localhost:8080/swagger-ui/`에 접속해서 확인  
    인터셉터에 걸려서 안나올 경우 `.excludePathPatterns("/v2/api-docs", "/swagger-resources/**", "/swagger-ui.html", "/webjars/**")`로 해결  

- Spring Rest Docs 적용  
제품 코드에 영향이 없다. 테스트가 성공해야 문서가 작성된다.  
[참고](https://woowabros.github.io/experience/2018/12/28/spring-rest-docs.html)  
### [Spring] DTO 검증 테스트  
[참고](https://woowacourse.github.io/javable/post/2020-09-20-validation-in-spring-boot/)  
- mockMvc를 통한 테스트

- mockito를 통한 mock 객체 생성  

- dto의 검증  
기본 설정  
```java
    private static Validator validator;

    @BeforeAll
    static void setUp() {
        ValidatorFactory factory = Validation.buildDefaultValidatorFactory();
        validator = factory.getValidator();
    }
```  
검증  
```java
    @Test
    @DisplayName("이메일 공백")
    public void emptyEmail() {
        TokenRequest tokenRequest = new TokenRequest("", "asdf");
        Set<ConstraintViolation<TokenRequest>> violations = validator.validate(tokenRequest);
        assertTrue(violations.stream()
            .anyMatch(violation -> violation.getMessage().contains("이메일은 공백이 아닙니다.")));
    }
```  
검증이 전부 통과하면 set이 empty이고, 통과하지 못하면 violations에 message가 들어있다.  

### [Spring] @Email vs @Pattern  
pattern: `@Pattern(regexp = "^[a-zA-Z0-9._%+]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]*$", message = "이메일에는 특수문자가 포함될 수 없습니다.")`  
email: @없는 것만 확인하고 @ 뒤에 . 오는 것, 아이디에 특수문자가 들어오는 경우에 대해서 처리가 되지 않는다.  
pattern을 적용하도록 하자.  

### [Java] IllegalArgumentException  
> Thrown to indicate that a method has been passed an illegal or inappropriate argument.  

올바르지 않은/적절하지 않은 argument(**인자**)에 의해서 에러가 발생하는 경우이다.  
반면에 RuntimeException의 경우는 아래와 같다.  
> RuntimeException and its subclasses are unchecked exceptions. Unchecked exceptions do not need to be declared in a method or constructor's throws clause if they can be thrown by the execution of the method or constructor and propagate outside the method or constructor boundary.  

unchecked의 모든 예외를 포괄하고 있는 것이 RuntimeException이다.  
적절한 상황에서 상속해서 사용하도록 하자.  

### [Spring] Validation 사용  
Spring Boot의 ValidationAutoConfiguration => LocalValidatorFactoryBean, MethodValidationPostProcessor 설정  
- LocalValidatorFactoryBean: Validator 사용  
- MethodValidationPostProcessor: parameter, return 값 검증  

1. 파라미터나 리턴 값 검증을 하려면 클래스 상단에 `@Validated` 적용  
기본적으로 @Controller에는 존재  
이렇게 되면 controller뿐만 아니라 모든 클래스에서 사용 가능  
붙어있는게 있으면 MethodValidationPostProcessor를 통해 프록시 객체 생성  
실제 validation 처리는 MethodValidationInterceptor에서 진행  

2. @RequestParam, @PathVariable 값 검증에 실패하면 `ConstraintViolationException` 발생  
기본 500 에러, 예외 잡아서 처리 필요  
검증에서 준 message를 아래와 같이 활용 가능  
```java
@ExceptionHandler(value = {ConstraintViolationException.class})
protected ResponseEntity<Object> handleConstraintViolation(ConstraintViolationException e, WebRequest request) {
    return handleExceptionInternal(e, e.getMessage(), new HttpHeaders(), HttpStatus.BAD_REQUEST, request);
}
```  

3. 요청 값 검증하려면 @RequestBody 앞에 `@Valid` 적용  
RequestResponseBodyMethodProcessor를 통해 메서드 파라미터 바인딩하는데 여기서 valid, validation도 같이 처리  
여기서 에러가 생기면 `MethodArgumentNotValidException` 발생  
기본 400에러  

4. MessageCodesResolver  
spring에서 오류 메시지 코드관리를 위해 사용하는 것  
자동으로 설정하는 DefaultMessageCodesResolver가 있고, setMessageCodeFormatter()를 통해 설정 가능  

5. @Valid와 @Validated 차이  
- @Valid: jakarta.validation-api에서 제공  
- @Validated: groups 설정 가능  
 
[참고](https://kapentaz.github.io/spring/Spring-Boo-Bean-Validation-%EC%A0%9C%EB%8C%80%EB%A1%9C-%EC%95%8C%EA%B3%A0-%EC%93%B0%EC%9E%90/#)  

### [Spring] dao와 service의 역할  
dao: 도메인으로부터 저장을 위한 table이 나오고, 그 table을 관리한다.  
필요에 따라 도메인을 주면 수정/삭제가 일어날 수 있고  
id로부터 도메인을 얻어낼 수 있다.  
table로부터 도메인을 가져오는 아이  

service: 도메인에게 로직을 수행시킨다.  
그 도메인은 요청으로부터 dao에게서 얻어왔을 거다.  

종속성을 가진 관계에서는 service가 여러 dao를 가질 수 있다.  
왜냐? 종속 관계니까. Line이 Section을 가지니, 하나의 서비스에서 lineDao와 sectionDao를 사용하는 건 당연하다.  
하지만 전혀 관계가 없는 station의 경우는 service에 있는 a나의 검증로직을 드러내고 싶지 않다.  
따라서 line이 station service에 요청해야지 않을까?  

### [Spring] custom exception 관리  
enum으로 error name, message 관리  

### [Spring] db 예외 처리에 대해  
- insert 중복 확인  
    1. insert 시에 중복인 경우 duplicated~~ 이 발생하는 것을 catch 해 throw 하는 방안  
    2. isExistByName 과 같은 메서드로 같은 이름의 요소가 존재하는지 확인하고, 있으면 throw 하는 방안  

- update/delete 존재 확인  
    1. jdbc update/delete 메서드는 바꾸거나/삭제한 요소의 개수를 반환한다. 이것이 0이면 throw 하는 방안  
    2. isExistByName 과 같은 메서드로 같은 이름의 요소가 존재하는지 확인하고, 없으면 throw 하는 방안  

### [Spring] domain이 dto를 알 필요가 있는가?  
domain 생성자에 dto를 전달한 이유: 서비스 로직에서 getter로 모든 정보를 빼고 전달하는 것에 있어 자연스럽지 않고 구문이 길어진다고 생각해 dto 자체를 전달해 생성하도록 했다.  
하지만 내가 controller에서 끊을까 했던 dto의 침투력이 도메인까지 들어올 필요가 있을까?  
변수가 추가되면 line 로직까지 영향을 미쳐야 하는가?  

### [network] 201 vs 200  
- 201: created는 보통 생성하고 location uri를 반환할 때 사용한다. 매번 지켜지지는 않지만 201의 경우에 uri가 넘어올 것을 기대하기 때문에 없는 경우에는 200을 사용하는 것이 좋다.  
> The response SHOULD include an entity containing a list of resource characteristics and location(s) from which the user or user agent can choose the one most appropriate.  