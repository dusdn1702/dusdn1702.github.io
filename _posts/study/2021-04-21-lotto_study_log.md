---
title: "lotto 학습 로그 정리"
excerpt: level 1
permalink: /study/33
categories:
  - study
  - java
  - techcourse
tags:
  - study
  - java
  - techcourse

last_modified_at: 2021-04-21
---  
# 로또  

## 1단계  
### [JDK] Stream API - 2
#### 내용
- Stream API와 친해지려고 노력하였으나, 아직은 어색해 많이 사용하지 못했다.
- distinct()를 사용해 중복을 확인할 때, 1~45까지의 배열을 생성할 때, 일치하는 값을 찾아낼 때 사용하였다. 

### [JDK] JCF - 5
#### 내용
- 되도록 제공되는 프레임워크를 사용하고, 배열을 사용하지 않으려고 노력하였다.
- Collections로 제공되는 shuffle, reverse, sort와 같은 함수도 적극 활용하였다.
#### 링크 
- https://github.com/woowacourse/java-lotto/pull/242/commits/c7f077ce67ffd9d74727b96f65761cb054b0fb87
- https://github.com/woowacourse/java-lotto/pull/242/commits/8044946f160e3b6625bc86406e45e10233b7eb90

### [Design Patterns] Strategy Pattern - 3
#### 내용
- 랜덤 숫자 리스트 생성에 전략 패턴을 적용해 원하는 숫자로 테스트할 수 있도록 하였다.
- NumbersGenerator라는 인터페이스를 RandomNumbersGenerator로 구현하였다.
#### 링크
- https://github.com/woowacourse/java-lotto/pull/242/commits/c7f077ce67ffd9d74727b96f65761cb054b0fb87

### [Design Patterns] MVC Pattern - 3
#### 내용
- 최대한 controller에서 domain을 view에 전달하고자 하였다.
- package-by-feature를 적용하면서 경계가 애매해진 것 같다.

### [JDK] Optional - 1
#### 내용
- Ranking을 찾는 과정에서 .orElse(NOTHING) 메서드를 적용해 아닌 경우를 처리하도록 하였다.
#### 링크
- https://github.com/woowacourse/java-lotto/pull/242/commits/af921011479bae08f4ee7681da44750b4d4760a6 
- [Optional 사용에 대해 나온 글](http://homoefficio.github.io/2019/10/03/Java-Optional-%EB%B0%94%EB%A5%B4%EA%B2%8C-%EC%93%B0%EA%B8%B0/)  

### [JDK] Map - 2
#### 내용
- Map<Ranking, Integer>를 이용해 등수와 그 등수의 갯수를 관리하였다.
- 생성 시에 초기 값을 0으로 put해주며 초기화하는 방식에 대해 의문이다.
#### 링크
- https://github.com/woowacourse/java-lotto/pull/242/commits/d4e7f1b80ff68e89ca44a0d803cc92b6b672ffee

### [JDK] Enum - 2
#### 내용
- Ranking의 관리에 enum을 적용하도록 하였다.
- enum을 클래스처럼 사용하는 것에 대해 의문이다. 
#### 링크
- https://github.com/woowacourse/java-lotto/pull/242/commits/af921011479bae08f4ee7681da44750b4d4760a6
- [enum에 대해 잘 나와있는 글](https://woowabros.github.io/tools/2017/07/10/java-enum-uses.html)  

### [설계] TDD - 5
#### 내용
- 테스트를 먼저 구현하고, 테스트 코드를 통과하기 위한 프로덕션 코드를 구현하는 방식으로 진행하였다.
- TDD 연습에 가장 주 목적을 두어 도메인 객체에서는 테스트를 되도록 생성하고 구현하도록 하였다.

### [OOP] 원시값 포장 - 5
#### 내용
- 모든 원시값을 포장하고 일급 컬렉션을 사용했다.
- 불변의 객체로 관리하도록 하였다.

### [JDK] EnumMap - 2
#### 내용
- 로또 미션에서 Statistics라는 클래스에서 Map으로 Rankings와 그 개수를 관리하고 있었는데 여기에 enumMap을 적용했다.  

<br>

## 2단계  
### [Java] Exception - 4
#### 내용
- 사용자가 입력하는 모든 부분에서 발생할 수 있는 예외들을 unchecked Exception으로 관리하였다.
- 완전히 프로그램에 문제를 일으킬 여지가 있는 예외를 checked, 사용자의 잘못된 입력으로 인한 예외를 unchecked로 처리하고자 하여, 본 프로그램에는 uncheckedException만 사용하였다.  
#### 링크
- [참고](https://cheese10yun.github.io/checked-exception/)

### [Java] 정적 팩토리 메서드 - 2
#### 내용
- LottoNumber에 1부터 45까지의 숫자를 캐싱하여 사용하였다.
- LottoCount에 정적 팩토리 메서드를 적용해보았다.  
    - 이름을 가질 수 있다.  
    - 호출 될 때마다 인스턴스를 새로 생성하지 않아도 된다.  
    - 반환 타입의 하위 타입 객체를 반환할 수 있다.  
    - 입력 매개변수에 따라 매번 다른 클래스의 객체를 반환할 수 있다.  
    - 상속이 불가능한 불변타입을 보장한다.  
#### 링크 
- https://github.com/woowacourse/java-lotto/pull/321/commits/b12b53f422f4f93865568bc288e5206b483047f0
- https://github.com/woowacourse/java-lotto/pull/321/commits/03a8f83c6fe86cb0afd581925fa139980e4ddb11
- [참고](https://woowacourse.github.io/javable/post/2020-05-26-static-factory-method/)

### [Design Patterns] MVC 패턴 - 4
#### 내용
    1. model은 controller와 view에 의존하지 않아야 한다.
    2. view는 model에만 의존해야 하고 controller에는 의존하면 안된다.  
    3. view가 model로부터 데이터를 받을 때는 사용자마자 다르게 보여주어야 하는 데이터에 대해서만 받아야 한다.  
    4. controller에는 model과 view에 의존해도 된다.  
    5. view가 model로부터 데이터를 받을 때 반드시 controller에서 받아야 한다.  

### [Java] 상속과 조합 - 2
#### 내용
- 메서드의 중복을 제거하고자 ManualLottoCount와 LottoCount, WinnerTicket과 LottoTicketMaker 사이의 상속 관계를 생성해주었다. 
#### 링크
- https://github.com/woowacourse/java-lotto/pull/321/commits/1c82db31e46552a47f254b20b905d592513967dd


### 링크
- [TIL 정리 2/17](https://dusdn1702.github.io/techcourse/11)
- [TIL 정리 2/18](https://dusdn1702.github.io/techcourse/12)
- [TIL 정리 2/19](https://dusdn1702.github.io/techcourse/13)
- [TIL 정리 2/22](https://dusdn1702.github.io/techcourse/16)