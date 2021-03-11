---
title: "독서 정리 - 모던 자바 인 액션"
excerpt: "9장"
permalink: /study/26
categories:
  - study
  - java
tags:
  - study
  - java
  
last_modified_at: 2021-03-09
---  
# 모던 자바 인 액션

## [9장] 리팩터링, 테스팅, 디버깅  
람다 표현식을 이용해 리팩토링하고, 각 객체지향 디자인 패턴을 간소화할 수 있다.  
### 9.1 가독성과 유연성을 개선하는 리팩터링  
람다 표현식을 사용하면 코드가 더 간결해지고 가독성이 좋아진다.  
1. 코드 가독성 개선  
`코드 가독성이 좋다` == `다른 사람이 이해하기 쉽다` + 유지보수가 쉽다  
2. 익명 클래스를 람다 표현식으로 리팩터링하기  
```java
//익명 클래스 사용 
Runnable ex = new Runnable() {
    public void run() {
        System.out.println("sleepy");
    }
}
```  
```java
//람다 표현식 사용  
Runnable ex = () -> System.out.println("happy");
```  
위 아래 코드를 비교해보면 아래가 훨씬 이해하기 좋다.  
하지만 아래 두 경우를 유의해야 한다.  
- 익명 클래스와 람다가 가리키는 `this`와 `super`은 다르다. this 호출 시 익명 클래스는 자기 자신, 람다는 자신이 호출된 객체를 뱉어낸다.  
```java

public class Hi{
    public void example() {
        Runnable r = new Runnable() {
            @Override
            public void run() {
                System.out.println("익명: " + this.toString());
            }
        };
        r.run();
        System.out.println("익명 Runnable 객체: " + r.toString());
    }

    public void lambda_example() {
        Runnable r = () -> {
                System.out.println("람다: " + this.toString());
        };
        r.run();
        System.out.println("람다 Runnable 객체: " + r.toString());
        System.out.println("Hi 객체: " + this.toString());
    }
    /* 실행결과
    익명: Hi$1@21d003b7
    익명 Runnable 객체: Hi$1@21d003b7
    람다: Hi@246eb230
    람다 Runnable 객체: Hi$$Lambda$228/2006442694@774a35a
    Hi 객체: Hi@246eb230
     */
}
```  
- 익명 클래스는 자신이 사용하는 변수가 공유되지 않지만, 람다식은 공유되어 같은 변수의 값을 바꿀 수 없다.  
```java
int a = 1;
Runnable r = () -> {
    int a = 2;
    System.out.println("람다: " + a + super.toString());
};
```  
- 익명클래스와 달리 형식이 정해지지 않으므로 오버로딩에 따른 모호함을 캐스팅을 통해 제거해주는 것이 좋다. 인텔리제이가 해줄거다.  
3. 람다 표현식을 메서드 참조로 리팩터링하기  
`groupingBy`,`comparing`, `maxBy`와 같은 메서드들의 인자로 람다표현식을 메서드로 추출해 전달해주면 가독성이 좋아진다. 내장 컬렉터를 이용하면 이해가 더 쉽다.  
4. 명령형 데이터 처리를 스트림으로 리팩토링하기  
스트림은 의도가 명확히 드러날 뿐만 아니라 강렬한 최적화, parallelStream을 사용하면 병렬화로 멀티코어 아키텍쳐까지 제공한다.  
명령형 코드를 스트림 API로 바꾸긴 쉽지 않다. 인텔리제이의 도움을 받자.  
5. 코드 유연성 개선  
- 함수형 인터페이스 적용  
    - 조건부 연기 실행  
    Logger 클래스 사용  
    ```java
    if(logger.isLoggable(Log.FINER)) {
        logger.finer("hi: " + generateDiagnostic());
    }
    ```  
    ```java
    logger.log(Level.FINER, () -> "hi: " + generateDiagnostic());
    ```  
    위 코드를 아래 코드로 수정하면 logger의 상태가 노출되는 것도, 메시지 로깅마다 logger 객체 활성화와 무관하게 그 상태도 확인해야 하는 것을 해결할 수 있다.  
    `특정 조건에서만 생성하도록 연기`한 것이다.  
    - 실행 어라운드  
    실행 어라운드도 람다를 이용해서 다양한 방식으로 파일을 처리할 수 있는 예시가 책에 들어져 있다.  
<br>

### 9.2 람다로 객체지향 디자인 패턴 리팩터링하기  
디자인 패턴은 공통적인 소프트웨어 문제를 설계할 때 재사용할 수 있는, 검증된 청사진을 제공한다.  
이러한 디자인 패턴에 ㅍ람다를 더하면 더 많은 디자인 패턴을 제거하거나, 간결하게 할 수 있다.  
1. 전략  
전략 패턴이란? 특정 컨텍스트에서 알고리즘을 분리하는 방법이다.  
전략 패턴을 이용하면 확장에는 용이하고 변경에는 닫혀있게 된다.  
- 전략 객체를 사용하는 하나 이상의 클라이언트
- 하나 이상의 전략 인터페이스 구현  
- 알고리즘을 나타내는 인터페이스  
이렇게 세가지로 구성된 전략 패턴이 있다.  
```java
public interface ValidationStrategy {
    boolean execute(String s);
}
public class isAllUpperCase implements ValidationStrategy {
    public boolean execute(String s) {
        return s.matches("[A-Z]+");
    }
}
public class Validator {
    private final ValidationStrategy strategy;
    public Validator(ValidationStrategy v) {
        this.strategy = v;
    }
    public boolean validate(String s) {
        return strategy.execute(s);
    }
}
Validator validator = new Validator(new IsAllUpperCase());
boolean hi = validator.validate("BBBB");
```  
이 코드를 기존 방식대로 사용하면 아래와 같다.  
우리는 이 코드를 람다 표현식을 사용해서 아래와 같이 바꿀 수 있다.  
```java
Validator validator = new Validator((String s) -> s.matches("[A-Z]+"));
boolean hi = validator.validate("BBBB");
```  
위와 같이 표현하면 더 간단하고 쓸데 없는 전략 패턴이 불필요해진다. 람다 표현식은 실행 코드를 캡슐화하므로 전략 패턴을 대신할 수 있다.  
<br>

2. [템플릿 메서드] (https://gmlwjd9405.github.io/2018/07/13/template-method-pattern.html)  
템플릿 메서드 패턴이란? 실행 과정이나 단계는 동일한데 단계 중 일부의 구현이 다른 경우에 사용하는 패턴이다.  
실행 과정을 구현한 상위 클래스, 실행 과정의 일부 단계를 구현한 하위 클래스로 이루어져 있다.  
서로 다른 A, B 클래스가 있다. 이들이 동일하게 sum() 메서드를 필요로 하는데, A는 0을 곱하고, B는 1을 곱하는 서로 다른 메서드를 필요로 한다고 하자.  
이 경우 아래와 같이 구현할 수 있다.  
```java
public abstract example {
    public int sum(int a, int b) {  //템플릿 메서드  
        int res = a + b;
        return multiply(res);
    }
    abstract int multiply(int res);
}
```  
위와 같이 동일하게 적용되는 실행 과정을 제공하는 메서드를 템플릿 메서드라고 한다.  
템플릿 메서드 패턴을 사용해서 코드 중복 문제를 제거할 수 있다.  
이 경우도 람다 표현식을 사용해서 클래스를 생성하지 않고도 더욱 간단히 구현할 수 있다.
```java
	public void foo(int a, int b, Function<Integer, Integer> f){
		int sum = a + b;
		f.apply(sum);
	}

	public void fee() {
		foo(1, 2, (Integer i) -> i * 0);
	}
```  
<br>

3. 옵저버  
옵저버란? 한 객체의 상태 변화를 정해지지 않은 여러 다른 객체에게 통지하고 싶을 때 사용되는 패턴이다. GUI애플리케이션에서 자주 사용한다.  
주제 객체가 옵저버 객체 목록을 관리하는 메서드를 제공한다. 상태가 변경되면 등록된 옵저버에게 알린다.  
주제 객체의 통지 기능 실행 주체, 옵저버 인터페이스의 분리, 통지 시점에서의 주제 객체 상태, 옵저버 객체의 실행 제약 조건을 고려해야한다.  
```java
interface Observer {    //옵저버 인터페이스
    void notify(String tweet);
}
class sbs implements Observer { //옵저버 객체
    public void notify(String tweet) {
        System.out.println(tweet);
    }
}
interface Subject { //주제 객체
    void register(Observer o);
    void delete(Observer o);
    void notifyObserver(String tweet);
}
class Feed implements Subject { //기능 실행
    private List<Observer> observers;
    public notifyObserver(String tweet) {
        observers.forEach(o -> o.notify(tweet));
    }
}
```  
이러한 간단한 옵저버 패턴은 람다 표현식으로 간단하게 구현할 수 있다.  
```java
Feed f = new Feed();
f.register((String tweet) -> {
    System.out.println("hi"+tweet);
});
```  
이렇게 간단한 패턴이라면 몰라도, 옵저버가 상태를 가지고 있다거나, 여러 메서드를 정의하고 있다면 기존 방식을 사용하자.  
<br>

4. [의무 체인] (https://ocblog.tistory.com/35) 
의무 체인이란? 한 객체가 어떠한 작업을 처리한 다음에 다른 객체로 결과를 전달하고, 또 그 객체가 작업을 처리하고 또 전달하는 방식이다.  
```java 
public abstract class ProcessingObject<T> {
    protected ProcessingObject<T> successor;
    public void setSuccessor(ProcessingObject<T> p) {
        this.successor = p;
    }
    public T handle(T input) {
        T r = handleork(input);
        return r;
    }
    abstract protected T handleWork(T input);
}
public class Header extends ProcessingObject<String> {
    public String handleWork(String input){
        return "sleepy" + input;
    }
}
public class Tail extends ProcessingObject<String> {
    public String handleWork(String input){
        return input.replaceAll("y", "");
    }
}
ProcessingObject<String> p1 = new Header();
ProcessingObject<String> p2 = new Tail();
p1.setSuccessor(p2);
String result = p1.handle("im so sad..."); //sleep im so sad  
```  
이것 또한 람다 표현식을 적용할 수 있다.  
안봐도 알겠다.  
```java
UnaryOperator<String> head = (String t) -> "sleepy" + t;
UnaryOperator<String> tail = (String t) -> t.replaceAll("y", "");
Function<String, String> f = head.andThen(tail);
String result = f.apply("im so sad...");
```   
그래도 본 것 중에 얘가 제일 신선하다.  
`UnaryOperator<T>`는 T를 받아서 T를 반환한다. 
`Function`의 `A.andThen(B)`은 두 개의 함수형 인터페이스를 순차적으로 연결한다. A, B 순. B, A 순은 `A.compose(B)`  
<br> 

5. 팩토리  
객체를 만드는 것을 노출하지 않고 클래스 내에서 만들어 내는 것이 팩토리 패턴이다.  
생성자와 설정을 외부로 노출하지 않고 생산해내는게 큰 장점이다.  
```java
public class CarFactory {
    public static Car of(String name) {
        if("AVANTE".equals(name)){
            return new Avante();
        }
        if("BMW".equals(name)){
            return new BMW();
        }
    }
}
Car newCar = CarFactory.of("BMW");
```  
이것 또 람다 표현식으로 간단하게 할 수 있다.  
이번엔 Map을 만들어서 코드를 구현한다고 한다.  
```java
final static Map<String, Car> map = new HashMap<>();
static {
    map.put("BMW", BMW::new);
    map.put("AVANTE", Avante::new);
}
Car newCar = map.get("AVANTE");
```  
위와 같이 구현할 수 있다. 책에서는 Supplier 메서드를 사용했다.   
그치만 그 경우에는 생성자의 인수가 여러 개가 되면 적용하기 어렵다고 한다.  
나라면 그냥 사용하지 않을 것 같다.  
<br>  

### 9.3 람다 테스팅  
우리가 만드는 단위 테스트에도 람다를 적용할 수 있다.  
1. 보이는 람다 표현식의 동작 테스팅  
람다는 이름이 없다. 그래서 람다를 필드에 저장해서 재사용하면서 테스트할 수 있다.  
```java
public final static Comparator<Point> compareBy = comparing(Point::getX).thenComparing(Point::getY);
```  
이렇게 선언해두고, `.compare(a, b)`를  사용할 수 있는 것이다.  
람다는 함수형 인터페이스의 인스턴스를 생성해 가능한 일이다.  
그 인스턴스를 실행해 테스트하는 것이다.  
2. 람다를 사용하는 메서드의 동작에 집중하라  
람다는 정해진 동작을 다른 메서드에서 사용할 수 있도록 하나로 캡슐화하고자 한다. 이는 안에 내용을 노출하지 않도록 해야하는 것이고, 람다를 사용하는 메서드가 하는 일이 무엇인지를 테스트함으로써 람다를 보여주지 않고도 테스트 할 수 있다.  
예를 들어 숫자를 합쳐서 `map(i -> i + j)` `List<Integer>`를 만들었다면, 만들어진 내용을 검사하먄 되지 람다를 보지 말자는 것이다.  
```java
List<Integer> n = Arrays.asList(1, 2);
List<N> newN = n.stream().map(i -> new N(i + 2)).collect(toList());

assertEquals(List.of(new N(3), new N(4)), newN);
```  
3. 복잡한 람다를 개별 메서드로 분할하기  
복잡한 람다는 개별 메서드로 나눠서 참조해서 테스트 하도록 하자  
4. 고차원 함수 테스팅  
함수를 인자로 받으면 다른 람다로 동작을 테스트할 수 있다.  
다른 함수를 반환한다면 그 메서드를 함수형 인터페이스의 인스턴스로 간주하고 테스트할 수 있다.  
<br>

### 9.4 디버깅  
에러가 발생한 코드를 디버깅 할 때 우리는 `스택 트레이스`, `로깅`을 활용한다.  
1. 스택 트레이스 확인 [하는법](https://jamie95.tistory.com/98)   
스택 트레이스란, 프레임별로 메서드 호출 위치, 호출 시 인수값, 호출된 메서드의 지역 변수와 같은 호출 정보가 저장된다.  
하지만 람다 표현식에는 이름이 없어서 이상한 기호가 출력되는 것을 볼 수 있다.  
이는 미래의 자바 컴파일러가 개선한다고 한다 ㅋㅋㅋ  
2. 정보 로깅  
`peek` 이라는 스트림 연산은 스트림의 각 요소를 소비한 것처럼 동작을 실행한다.  
호출하고 나면 모두 소비되어 버리는 `for-each`와 대비되는 것을 알 수 있다.  
```java
List<String> numbers = new ArrayList<>("1", "2");
numbers.stream().peek(s -> System.out.println(s)).map(s -> Integer.parseInt(s)).collect(toList());
```  
스트림이 소모되지 않고 한 요소씩 출력해 로그를 찍을 수 있다! 