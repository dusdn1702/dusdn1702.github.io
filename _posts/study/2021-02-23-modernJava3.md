---
title: "독서 정리 - 모던 자바 인 액션"
excerpt: "3장"
permalink: /study/20
categories:
  - study
  - java
tags:
  - study
  - java
  
last_modified_at: 2021-02-25
--- 
# 모던 자바 인 액션
<br> 

## [3장] 람다 표현식  
동작 파라미터화, 익명 클래스, 람다 이렇게 더 발전한 코드를 구현해간다!  
<br>

### 3.1 람다란 무엇인가?  
람다 표현식은 메서드로 전달할 수 있는 익명 함수를 단순화한 것으로 파라미터 리스트, 화살표, 람다 바디로 구성되어 있다.  
`(parameter) -> parameter.getSomething()` 과 같이 구현할 수 있다.  
- 퀴즈 3.1  
return 문은 {} 안에 존재해야 한다.  
<br>

### 3.2 어디에, 어떻게 람다를 사용할까?
1. 함수형 인터페이스  
Comparator, Runnable, ActionListener, Callable, PrivilegedAction과 같은 API가 함수형 인터페이스로, 정확히 하나의 추상 메서드만을 지원하는 인터페이스이다.  
```java
public interface Comparator<T> {
    int compare(T t1, T t2);
}
```  
람다 표현식 전체를 함수형 인터페이스의 인스턴스로 취급할 수 있다.  
2. 함수 디스크립터  
함수형 인터페이스의 추상 메서드 시그니처는 람다 표현식의 시그니처이다. 이 때 람다 표현식의 시그니처를 서술하는 메서드가 함수 디스크립터이다.  
`(int, int) -> boolean`과 같이 표현할 수 있다.  
+ @FunctionalInterface는 함수형 인터페이스로, 한 개 이상의 추상 메서드를 가지고 있으면 에러가 발생한다.  
<br>

### 3.3 람다 활용: 실행 어라운드 패턴  
초기화와 마무리가 `작업 코드`를 감싸고 있는 것을 실행 어라운드 패턴이라고 칭한다.  
1. 동작 파라미터화  
```java 
String result = processFile((BufferedReader br) -> br.readLint());
```  
위와 같이 processFile의 인자로 동작을 전달하는 것에 람다를 사용할 수 있다.  
2. 함수형 인터페이스  
```java
@FunctionalInterface
public interface BufferedReaderProcessor {
    String process(BufferedReader b) throws IOException;
}
(BufferedReadber b) -> process(b);
```  
위와 같이 사용할 수 있다. 
3. 동작 실행
```java
public String processFile(BufferReaderProcessor p) {
    return p.process(br);
}
```  
위와 같이 동작의 실행을 명령한다.  
4. 람다 전달  
```java
String str = processFile((BufferReader br) -> br.readLine());
```  
그러고 이처럼 활용하면 된다.  
<br>

### 3.4 함수형 인터페이스 사용  
1. Predicate: 불리언 표현  
`java.util.function.Predicate<T>`로 boolean 반환  
```java
Predicate<String> p = (String s) -> s.isEmpty();
```  
2. Consumer: 객체에서 소비  
`java.util.function.Consumer<T>`로 void 반환  
```java 
Consumer<T> c = (Integer i) -> System.out.print(i); //c.accept(t); 로 실행
```  
3. Function: 객체에서 선택/추출  
`java.util.function.Function<T, R>`로 T를 인수로 받아 R을 반환
```java
Function<T, R> f = (String s) -> s.length(); //f.apply(t); 로 실행  
```  
+ `Supplier<T> s = () -> T`: 객체 생성  
+ `UnaryOperator<T> u = T -> T`, `BinaryOperator<T> b = (T, T) -> T`: 두 값 조합, `BiPredicate<L, R> b = (T, U) -> boolean`, `BiConsumer<T, U> b = void`, `BiFunction<T, U, R> b = (T, U) -> R`: 두 객체 비교  

- 참조형: Byte, Integer, List, Character  
- 기본형: int, double, byte, char  
위와 같이 언박싱된 기본형에 특화된 인터페이스도 존재한다. 

+ 예외 잡기  
```java
Function<BufferedReader, String> f = (BufferedReader b) -> {
    try {
        return b.readLine();
    } catch (IOException e) {
        throw new RuntimeException(e);
    }
}
```  
<br>

### 3.5 형식 검사, 형식 추론, 제약  
1. 형식 검사  
람다가 사용되는 곳을 보면 형식을 추론할 수 있고 그 형식을 `대상 형식`이라 한다.  
2. 같은 람다, 다른 함수형 인터페이스  
문맥에 따라 같은 람다식이더라도 다른 함수형 인터페이스가 적용될 수 있는 것이다.  
+ 다이아몬드 연산자 `new ArrayList<>();`의 <>는 콘텍스트를 통해 제네릭 형식을 추론할 수 있다.  
+ 바디에 일반 표현식이 있으면 `void 함수`와 호환된다.  
- 퀴즈 3-5  
캐스팅하거나 명확한 대상 형식을 명시해주어야 작동한다.  
3. 형식 추론  
자바 컴파일러는 대상 형식을 이용해 관련된 함수형 인터페이스를 추론한다.  
하지만 명시적으로 형식을 포함하는 것이 좋을 수도 있다.  
```java
Comparator<Apple> c = (a1, a2) -> a1.getWeight().compareTo(a2.getWeight());
```  
4. 지역 변수 사용  
람다 캡쳐링: 외부에서 정의된 변수를 람다 표현식에서 활용하는 것  
final로 불변인 인스턴스 변수와 정적 변수를 참조할 수 있다.  
이는 인스턴스 변수가 힙, 지역 변수가 스택에 위치해서 변수를 할당한 스레드가 람다가 사용하려는 때에 사라져버릴 수 있어서 그렇다.  
```java
int port = 1337;
Runnable r = () -> System.out.print(port);
```  
+ 클로저란? 함수의 비지역 변수를 자유롭게 참조할 수 있는 함수의 인스턴스  
<br> 

### 3.6 메서드 참조  
1. 메서드 참조는 :: 가독성이 높아진다.  
- 정적 메서드 참조
- 다양한 형식의 인스턴스 메서드 참조  
- 기존 객체의 인스턴스 메서드 참조  
2. 생성자 참조  
`Integer::new`로 구현한다.  
함수형 인터페이스 BiFunction은 두개, TriFunction은 세개의 인자를 가진 생성자를 만들도록 도와준다.  
<br> 

### 3.7 람다, 메서드 참조 활용하기  
1. 코드 전달  
sort의 동작 파라미터화  
```java
void sort(Comparator<? super E> c)

public class AppleComparator implements Comparator<Apple> {
    public int compare(Apple a1, Apple a2) {
        return a1.getWeight().compareTo(a2.getWeight());
    }
}
inventory.sort(new AppleComparator());
```  
2. 익명 클래스 사용  
```java
inventory.sort(new Comparator<Apple>() {
    public ...
})
```  
3. 람다 표현식 사용  
```java
inventory.sort((a1, a2) -> a1.getWeight().compareTo(a2.getWeight()));
```  
4. 메서드 참조 사용  
가장 간소화, 명확성 
```java
inventory.sort(comparing(Apple::getWeight));
```  
<br> 

### 3.8 람다 표현식을 조합할 수 있는 유용한 메서드  
여러 람다 표현식을 조합해 복잡한 람다 표현식을 만들 수 있다.  
추상 메서드가 아니므로 함수형 인터페이스의 정의를 벗어나지 않는다!(디폴트 메서드)    
1. Comparator 조합  
`inventory.sort(comparing(Apple::getWeight).reversed());` 역정렬  
`inventory.sort(comparing(Apple::getWeight).reversed().thenComparing(Apple:getCountry));` 같은거 나올경우까지  
2. Predicate 조합  
- negate: 특정 값의 반전
```java
Predicate<Apple> a = redApple.negate();
```
- and, or  
```java
Predicate<Apple> a = redApple.and(apple -> apple.getWeight() > 150);
Predicate<Apple> b = redApple.or(apple -> apple.colot() == GREEN);
```
3. Function 조합  
- andThen: `h = g(f(x))`와 같다.  
```java
Function<Integer, Integer> f = x -> x + 2;
Function<Integer, Integer> g = x -> x * 3;
Function<Integer, Integer> h = f.andThen(g);
int result = h.apply(1); // = 9
```  
      
- compose: `h = f(g(x))`와 같다.  
```java
Function<Integer, Integer> h = f.compose(g);
int result = h.apply(1); // = 5
```