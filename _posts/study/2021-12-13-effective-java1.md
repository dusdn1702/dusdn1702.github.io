---
title: "Effective Java - item1"
excerpt: 2장 객체 생성과 파괴
permalink: /study/68
categories:
  - java
tags:
  - java 
---  

## [effective java] 2장 객체 생성과 파괴

### item1. 생성자 대신 정적 팩터리 메서드를 고려하라.

Public 생성자와 정적팩터리메서드는 각각의 쓰임새가 있으니 장단점을 잘 이해하고 사용해야 한다. 무작정 public 생성자만 제공하지 말자.

일반 public 생성자

```java
public Boolean(boolean b) {
  this.b = b;
}
```

정적 팩터리 메서드

```java
public static Boolean valueOf(boolean b) {
  return new Boolean(b);
}
```

#### 장점

1. 이름을 가질 수 있다.

   BigInteger vs probablePrime 처럼 메서드명을 통해 직관적으로 이해하기 쉬워진다.

   생성자는 같은 시그니처로 하나씩만 만들 수 있다. 정적팩터리메서드를 사용하면 제약 없이 차이를 드러내는 이름으로 표현할 수 있다.

2. 호출될 때마다 새로운 인스턴스를 생성하지 않아도 된다.

   불변 객체인 경우 인스턴스를 미리 만들거나 캐싱을 통해 재활용하여 동일한 인스턴스가 생기는 것을 방지해 성능 향상에 도움이 된다.

   * **플라이웨이트 패턴(Flyweight pattern)** 

     동일하거나 유사한 객체들 사이에 가능한 많은 데이터를 서로 공유하여 사용하도록 하여 메모리 사용량을 최소화하는 디자인 패턴

     flyweight: 인터페이스

     concreteFlyweight: 인터페이스 구현체

     flyweightFactory: 인스턴스 생성과 공유

     Client: 패턴 사용자

3. 반환 타입의 하위 타입 객체를 반환할 수 있는 능력이 있다.

   반환할 객체의 클래스를 자유롭게 선택할 수 있게하여 유연한 구현이 가능하다. 

   인터페이스를 정적팩터리메서드의 반환 타입으로 사용함으로써 api를 작게 유지할 수 있다.

   사용자는 인터페이스에 정적팩터리메서드를 선언할 수 있게 되면서 구현을 모르고도 동작하는 객체를 얻을 수 있게 되었다.

4. 입력 매개변수에 따라 매번 다른 클래스의 객체를 반환할 수 있다.

   하위 타입이기만 하면 어떤 클래스의 객체를 반환하든 상관 없다.

   EnumSet 클래스가 public 생성자 없이 오직 정적 팩터리만 이용해 원소 수에 따라 RegularEnumSet, JumboEnumSet 이용하는 것

5. 정적팩터리메서드를 작성하는 시점에는 반환할 객체의 클래스가 존재하지 않아도 된다.

   서비스 제공자 프레임워크(ex. JDBC)는 제공자인 서비스의 구현체를 클라이언트에 제공하는 역할을 통제해 클라이언트를 구현체로부터 분리해준다.

   서비스 인터페이스(Connection), 제공자 등록 API(DriverManager.registerDriver), 서비스 접근 API(DriverManager.getConnection), 서비스 제공자 인터페이스(Driver)로 이루어져 있다.

#### 단점

1. 상속을 하려면 public, protected가 필요해 정적팩터리메서드만 제공하면 하위 클래스를 만들 수 없다.

   이는 상속보다 조합, 불변 객체를 만들도록 하여 장점이 될 수 있다.

2. 정적팩터리메서드는 프로그래머가 찾기 어렵다.

   개발자가 api 문서화를 잘 하지 않으면 명확히 드러나지 않아 인스턴스화할 정적팩터리메서드를 찾아야 한다.

   - From: 매개변수 하나
   - of: 여러 매개변수
   - valueOf: from과 of의 자세한 버전
   - instance, getInstance: 매개변수로 명시한 인스턴스 반환, 같은 인스턴스는 아님
   - create, newInstance: 매번 새로운 인스턴스 생성
   - getType: getInstance와 같으나 생성할 클래스가 아닌 다른 클래스에 팩터리 메서드 정의할 때 사용
   - newType: newInstance와 같으나 생성할 클래스가 아닌 다른 클래스에 팩터리 메서드 정의할 때 사용
   - type: getType, newType의 간결한 버전

