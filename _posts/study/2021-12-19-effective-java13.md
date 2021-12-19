---
title: "Effective Java - item13"
excerpt: 3장 모든 객체의 공통 메서드
permalink: /study/74
categories:
  - java
tags:
  - java 
---  

## [effective java] 3장 모든 객체의 공통 메서드

### item13. Clone 재정의는 주의해서 진행하라

Cloneable은 복제해도 되는 클래스임을 명시하는데에 사용되는 인터페이스이다.

문제는 Object 클랫스에 clone 메서드가 protected로 선언되어 있다는 것이다.

따라서 Cloneable을 구현하는 것만으로 외부 객체에서 clone 메서드를 호출할 수 없다. 

Cloneable을 구현한 클래스의 인스턴스에서 clone을 호출하면 객체의 필드들을 하나하나 복사한 객체를 반환하고 그렇지 않은 클래스의 인스턴스에서 호출하면 CloneNotSupportedException이 발생된다.

실제로 Cloneable을 구현한 클래스는 clone 메서드를 public으로 제공하며 당연히 복제가 제대로 이뤄지리라 기대한다.

Clone 메서드의 일반 규약은 아래와 같다.

- 객체의 복사본을 생성해 반환한다.

- 이 메서드가 반환하는 객체는 super.clone을 호출해 얻어야 한다.

- 반환된 객체와 원본 객체는 독립적이어야 한다.

- 아래 메서드가 대체로 참이다.

  ```
  x.clone() != x
  x.clone().getClass() == x.getClass()
  x.clone().equals(x)
  x.clone().getClass() == x.getClass()
  ```

Clone 메서드의 대표적인 예시는 아래와 같다.

```
@Override
public PhoneNumber clone() {
  try {
    return (PhoneNumber) super.clone();
  } catch (CloneNotSupportedException e) {
    throw new AssertionError();
  }
}
```

불변 객체인 경우 생성자를 통해 clone 메서드를 구현해도 무방하지만 가변 객체인 경우 재앙이 될 것이다.

따라서 clone 메서드는 원본 객체에 아무런 해를 끼치지 않는 것과 동시에 복제된 객체의 불변식을 보장해야 한다.

가변 객체를 복제하고 싶다면 요소를 깊은 복사하여 해결할 수 있고, super.clone을 호출해 얻은 객체의 모든 필드를 초기 상태로 설정한 다음 원본 객체의 상태를 재생성하는 고수준 메서드들을 호출해 해결할 수 있다.

복사 생성자(Conversion constructor)와 복사 팩터리(Conversion factory)라는 객체 복사 방식을 이용해서도 이 문제를 해결할 수 있다.