---
title: "blackjack 학습 로그 정리"
excerpt: level 1
permalink: /study/34
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
# 블랙잭  

## 1단계 
### [Java] Exception - 1
#### 내용
- 사용자가 입력하는 모든 부분에서 발생할 수 있는 예외들을 unchecked Exception으로 관리하였다.
#### 링크
- https://github.com/woowacourse/java-blackjack/pull/154/commits/8e148a05d5f11e26d8ab415f91ca0ca644752e0d

### [Design Patterns] MVC 패턴 - 2
#### 내용
- 처음으로 뒤늦게 controller를 생성해 구현해보았다.  
- controller, view, domain이 각자의 역할에 맞게 책임을 수행하도록 했다.
#### 링크
- https://github.com/woowacourse/java-blackjack/pull/154/commits/3399a72ddc12c2da48ce91c61aaf45bab3838e4d
- https://github.com/woowacourse/java-blackjack/pull/154/commits/a919c2af25729c4e9fbc3924f3db184e52390999
- https://github.com/woowacourse/java-blackjack/pull/154/commits/89722141776aa8367bdce91935ee94f7ed31fc96

### [Java] 상속과 조합 - 4
#### 내용
- 메서드의 중복을 제거하고자 Dealer와 Player를 Gamer로부터 상속받았다.
- 게임 참가자들을 모두 관리하고자 Players 객체에 List<Player>와 Dealer를 조합해 사용하였다. 
#### 링크
- https://github.com/woowacourse/java-blackjack/pull/154/commits/975027a3410c155379c483faf379116a98d4c66c 

### [Java] 일급컬렉션 - 3
#### 내용
- Player가 가진 List<Card>를 Cards라는 객체로 생성해 관리하였다.
#### 링크
- https://github.com/woowacourse/java-blackjack/pull/154/commits/73bd245b11380b57de22638b98b0fbbdbc2d099d
- https://github.com/woowacourse/java-blackjack/pull/154/commits/1079ed45d6a89f4dcb81d2c13ed83bf0cc70be97

### [Java] stream API - 3
#### 내용
- 카드를 생성할 때 두 개의 스트림을 순회하며 deck을 생성하도록 하였다.  
#### 링크
- https://github.com/woowacourse/java-blackjack/pull/154/commits/91ee66e2742701b36f20c8cf7c80107e40b1ec01

### [Java] Enum - 3
#### 내용
- 카드의 패턴과 숫자를 Enum으로 관리하였다.
- 승, 패, 무를 Enum으로 관리하였다.
#### 링크
- https://github.com/woowacourse/java-blackjack/pull/154/commits/c95ce7f392a6d9c6824ad5cd2a6271f5db680c6d

<br>

## 2단계
### [Design Patterns] 상태 패턴 - 4
#### 내용
- blackjack, bust, stay, hit 상태에 대해서 객체로 생성하고 관리하도록 하였다.  
#### 링크
- https://github.com/woowacourse/java-blackjack/pull/186/commits/ab9e132f6d46eeee2f1e6b2332a6ef011565b9b5
- [참고](https://victorydntmd.tistory.com/294)

### [java] 추상 메서드 - 3
#### 내용
- Finished 추상 메서드를 blackjack, bust, stay가 상속하고 있다.
- Running 추상 메서드를 hit이 상속하고 있다.

### [Java] 인터페이스 - 3
#### 내용
- 상태를 관리하는 PlayerState 인터페이스를 생성했다. 

### [Testing] 단위테스트 - 2
#### 내용 
- public으로 사용되는 모든 메서드를 단위 테스트 구현했다.

### [Java] 전략 패턴 - 2
#### 내용 
- card들을 만드는 CardsGenerator 인터페이스를 구현했다.
#### 링크
- https://github.com/woowacourse/java-blackjack/pull/186/commits/f2255a04cb7e0d7e83aa01a8d47b1b41e8798573

### [Java] 캐싱 - 3
#### 내용  
- deck을 static 상수로 캐싱하여 필요할 때 가져다 쓰는 방식으로 구현했다.  

### [Java] 객체의 캡슐화 - 1
#### 내용 
- 객체의 완전한 캡슐화를 보장하기 위해 객체를 반환할 때 방어적 복사를 사용했다.  

### 링크
- [TIL 정리 3/9](https://dusdn1702.github.io/techcourse/26)
- [TIL 정리 3/15](https://dusdn1702.github.io/techcourse/30)