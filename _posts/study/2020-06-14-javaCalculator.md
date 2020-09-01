---
title: "test 공부 && 계산기 만들기"
excerpt: "java 공부"
permalink: /study/2
categories:
  - study
tags:
  - study
last_modified_at: 2020-06-25
---

java로 계산기 만들기 했다.  

enum 처음 써봤다.

<br>

## enum   
열거형으로 서로 연관된 거 집합으로 정돈하기에 좋다. 예를 들어 사칙연산. 문맥을 담아 정리한다고 생각하자.  
- 데이터 간의 관계 표현에 용이  
- 상태와 행위를 한번에 정리  
- 데이터 그룹 관리에 용이  

## 함수형 인터페이스  
```java
public enum Operator {
    PLUS((operand1, operand2) -> operand1 + operand2, "+"),
    MINUS((operand1, operand2) -> operand1 - operand2, "-"),
    MULTIPLY((operand1, operand2) -> operand1 * operand2, "*"),
    DIVIDE((operand1, operand2) -> operand1 / operand2, "/");

    private final String operator;
    private BiFunction<Double, Double, Double> calculate;

    Operator(BiFunction<Double, Double, Double> calculate, String operator) {
        this.calculate = calculate;
        this.operator = operator;
    }
}
```
위와 같다고 보면 된다. 상당히 많은 function들이 존재한다.  
- 내가 사용한 BiFunction의 경우 두개의 매개변수를 받아서 하나의 자료형으로 리턴하는 것이다.  
- Function의 경우 하나의 매개변수, 하나의 return한다. 가장 기본형이다. 여기서 기본을 받아 특정 타입을 리턴할 수도, 특정 타입을 받아 기본을 리턴할 수도, 두개 받아서 특정 타입/기본을 리턴할 수도 있다.  
- Suppliers는 매개변수를 받지 않고 하나 return  
- Consumers는 매개변수 받고 리턴은 없다.  
- Predicates는 하나 매개변수 받아 boolean으로 리턴한다.  
- Operators는 하나의 매개변수 받아 동일한 타입으로 리턴
<br>

## 함수/클래스 명명
클래스는 첫문자 대문자.  
클래스는 명사형 명명.  
함수는 동사형 명명.  
is는 주로 boolean에 적용.  
void 타입의 경우 적용하고 exception 있으면 check 사용.  
<br>

## 단위테스트 어노테이션
- @ValueSource
배열이나 값, 문자열을 메소드로 전달  
- @EnumSource
enum, 집합을 효율적으로 테스트, iterator 적용에도 용이  
- @CsvSource
csv 포맷으로 테스팅 편리하게 진행   
csv 포맷이란 , 단위로 구분하는 것  
따라서 , 단위로 편리하게 값 넘길 수 있다.
- @MethodSource  
보다 복잡한 객체를 쉽게 생성해서 테스트