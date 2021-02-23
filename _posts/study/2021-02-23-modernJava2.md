---
title: "독서 정리 - 모던 자바 인 액션"
excerpt: "2장"
permalink: /study/19
categories:
  - study
  - java
tags:
  - study
  - java
  
last_modified_at: 2021-02-23
--- 
# 모던 자바 인 액션
<br> 

## [2장] 동작 파라미터화 코드 전달하기  
동작 파라미터화란 아직은 어떻게 실행할 것이니 결정하지 않은 코드 블럭을 의미한다.  
코드 블록은 나중에 실행한다.  
기존 자바 API에 포함된 클래스와 인터페이스를 이용해 리스트를 정렬하거나 파일 이름을 필터링하거나, 스레드로 코드 블록을 실행하거나, gui 이벤트를 처리하면서 동작 파라미터화 패턴을 적용할 수 있다.  
동작 파라미터화를 통해 변화하는 요구사항에 잘 대응하는 코드를 통해 비용을 줄이고, 깔끔한 코드를 만들 수 있게 한다.  
<br> 

### 2.1 변화하는 요구사항에 대응하기  
- 거의 비슷한 코드가 반복 존재한다면 코드를 추상화하자  
<br>

### 2.2 동작 파라미터화  
메서드가 다양한 동작을 받아서 내부적으로 다양한 동작을 수행할 수 있다.  
- 퀴즈 2-1: 사과 리스트를 인수로 받아 다양한 방법으로 문자열을 생성할 수 있도록 파라미터화된 prettyPrintApple 메서드를 구현하라. 각각의 사과가 무거운지 가벼운지 출력하거나, 각각의 사과 무게를 출력하도록 하는 일    
```java
public interface AppleMaker {
    String accept(Apple a);
}
public class AppleMaking implements AppleMaker {
    public String accept(Apple apple){
    String character = apple.getWeight() > 150 ? "heavy" : "light";
    return apple.getName() + character + apple.getColor();
}
public static void prettyPrintApple(List<Apple> inventory, AppleMaker appleMaker) {
    for(Apple apple : inventory) {
        System.out.print(apple.accept(apple));
    }
} 
public static void main(String[] args) {
    prettyPrintApple(inventory, new AppleMaking());
}
```  
위처럼 인터페이스를 건네주는 것을 동작파라미터화라고 볼 수 있다.  
<br>  

### 2.3 복잡한 과정 간소화  
로직과 관련 없는 코드의 중복이 많다보니 클래스의 선언과 인스턴스활르 동시에 수행할 수 있도록 하는 **익명 클래스**가 나왔다.  
1. 익명 클래스  
```java
List<> apples = filterApples(inventory, new AppleMake() {
    public String appleName(Apple apple) {
        return apple.getName();
    }
})
```  
이와 같이 인자로 함수 자체를 전달할 수도 있다.  
하지만 익명 클래스도 반복되어 지저분한 코드는 분명히 존재하고 읽기가 쉽지 않다.  
이에 자바 8부터 **람다 표현식**이 나왔다.  
2. 람다 표현식  
```java
List<Apple> apples = filterApples(inventory, (Apple apple) -> RED_APPLE.equals(apple.getColor()));
```  
람다는 지금까지 값의 파라미터화 보다 유연하면서, 가장 간결한 동작 파라미터화의 방식이다.  
3. 리스트 형식으로 추상화  
```java
public interface Predicate<T> {
    boolean test(T t);
}  
```  
이와 같이 리스트에 타입을 전달해줌으로써 리스트 자체에 메서드를 사용할 수 있도록 더욱 간결해졌다.  
<br>  

### 2.4 실전 예제  
자바 API의 많은 메서드를 다양한 동작으로 파라미터화할 수 있다.  
1. Comparator로 정렬하기  
```java
public interface Comparator<T> {
    int compare(T t1, T t2);
} // 이 메서드를 이용해  
inventory.sort((A a, A b) -> a.getWeight().compareTo(b.getWeight()); //와 같이 구현할 수 있다.
```  
2. Runnable로 코드 블록 실행하기  
스레드를 이용하면 병렬로 코드 블록을 실행할 수 있다. 스레드에게 이를 전달하면 각 스레드가 서로 다른 코드를 실행해 효율적으로 운영할 수 있다.  
자바에서는 Runnable 인터페이스를 이용해 실행할 코드 블록을 지정할 수 있다.  
```java
Thread t = new Thread(new Runnable() {
    public void run() {
        System.out.print("hi");
    }
})
```  
위와 같이 스레드 안의 Runnable 코드를 실행할 수 있다.  
자바 8부터는 람다 형식을 이용할 수도 있다.  
```java
Thread t = new Thread(()-> System.out.println("hi"));
```  
3. GUI 이벤트 처리하기  
ExecutorService란: 태스크 제출과 실행 과정의 연관성을 끊어주어 태스크를 스레드 풀로 보내고 Future로 저장할 수 있다. 이는 Callable 인터페이스를 통해 실행한다.  
