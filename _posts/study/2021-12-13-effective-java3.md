---
title: "Effective Java - item3"
excerpt: 2장 객체 생성과 파괴
permalink: /study/70
categories:
  - java
tags:
  - java 
---  

## [effective java] 2장 객체 생성과 파괴

### item3. private 생성자나 열거 타입으로 싱글턴임을 보증하라.

싱글턴이란 인스턴스를 오직 하나만 생성할 수 있는 클래스

1. private으로 생성자 감추고 public static 멤버가 final 필드인 방식

   새로 인스턴스를 생성하려면 reflection의 setAccessible 사용해야한다.

   api에 명시적으로 싱글턴임을 알 수 있고 간결하다.

2. private으로 생성자 감추고 정적 팩터리 메서드를 public static 멤버로 제공하는 방식

   getInstance 메서드는 항상 같은 객체의 참조를 반환한다.

   필요에 따라 비교적 자유롭게 싱글턴이 아니게 변경할 수 있다.

   제네릭 싱글턴 팩터리(매개변수에 따라 객체 타입 변경)로 만들 수 있다.

   함수형 프로그래밍에서 정적 팩터리의 메서드 참조를 Supplier로 사용할 수 있다. 

private으로 생성자를 감춰두고 public static 으로 인스턴스를 만들어 사용하는 방식

ex. 함수같은 무상태 객체, 설계상 유일해야하는 시스템 컴포넌트

싱글턴 클래스를 직렬화하려면 Serializable을 구현하고 인스턴스 필드를 일시적으로 선언하고 readResolve 메서드(만들어진 객체 반환)를 제공해야 새로운 클래스가 만들어지지 않는다.

3. 원소가 하나인 Enum 생성

   직렬화에도 용이하고 reflection에서도 하나의 인스턴스가 보장되어 효과적이다.

   상속하는 싱글턴에는 사용할 수 없다.