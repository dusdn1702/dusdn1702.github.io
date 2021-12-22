---
title: "Effective Java - item14"
excerpt: 3장 모든 객체의 공통 메서드
permalink: /study/75
categories:
  - java
tags:
  - java 
---  

## [effective java] 3장 모든 객체의 공통 메서드

### item14. Comparable을 구현할지 고려하라

compareTo 메서드는 Comparable 인터페이스의 유일한 메서드이다. 단순 동치성 비교와 순서 비교가 가능하고 generic 하다. 따라서 순서가 있다는 의미이다.

검색, 극단값 계산, 컬렉션 관리도 손쉽게 할 수 있다. 

compareTo의 규약은 아래와 같다

- 자신과 주어진 객체의 순서를 비교한다. 자신이 작으면 음의 정수, 같으면 0, 크면 양의 정수를 반환한다. 비교할 수 없는 타입인 경우 ClassCastException을 던진다.
- 모든 x, y에 대해 sgn(x.compareTo(y)) == -sgn(y.compareTo(x))여야 한다.
- (x.compareTo(y) > 0) && (y.compareTo(z) > 0) 이면 x-z도
- x.compareTo(y) == 0이면 x.compareTo(z) == y.compareTo(z)
- 반사성, 대칭성, 추이성 충족

규약을 지키지 않으면 비교 활용 클래스(ex. TreeSet, TreeMap, Collections, Arrays)를 사용할 수 없다.

compareTo 메서드의 인수타입은 컴파일타임에 정해지므로 입력 인수의 타입을 확인하거나 형변환할 필요가 없다. 인수타입이 잘못됐으면 컴파일도 안되고 null을 인수로 넣어 호출하면 예외가 발생한다.

compareTo 메서드는 객체 참조 필드 비교 시 compareTo 메서드를 재귀적으로 호출해 각 필드가 동치인지를 비교하는 것이 아니고 순서를 비교한다. 이 때 비교자는 자바에서 제공하는 compare 메서드를 사용하거나, 비교자를 직접 만들 수 있다.

compareTo 메서드에서 관계 연산자 `<`와 `>`를 사용하는 이전 방식은 거추장스럽고 오류를 유발해 사용하지 않는 것이 좋다.

```java
public int compareTo(PhoneNumber pn) {
    int result = Short.compare(areaCode, pn.areaCode);
    if(result == 0) {
        result = Short.compare(prefix, pn.prefix);
        if(result == 0) {
            result = Short.compare(lineNum, pn.lineNum);
        }
    }
    return result;
}
```

메서드 연쇄 방식으로 비교자를 만들 수 있다. (.then~~) 편리하지만 약간의 성능 저하가 있다.

```java
private static final Comparator<PhoneNumber> COMP = comparingInt((PhoneNumber pn) -> pn.areaCode)
.thenComparingInt(pn -> pn.prefix)
.thenComparingInt(pn -> pn.lineNum);

public int compareTo(PhoneNumber pn) {
    return COMP.compare(this, pn);
}
```

값의 차를 기준으로 compareTo나 compare 하는 경우 정수 오버플로나 부동소수점 계산 방식에 따른 오류가 생길 수 있으므로 `Integer.compare(1, 2)`나 `Comparator.comparingInt(1 -> 1.hashCode());` 의 방식을 사용하도록 하자.