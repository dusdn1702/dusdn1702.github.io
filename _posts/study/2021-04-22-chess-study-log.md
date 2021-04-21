---
title: "chess 학습 로그 정리"
excerpt: level 1
permalink: /study/35
categories:
  - study
  - java
  - techcourse
tags:
  - study
  - java
  - techcourse

last_modified_at: 2021-04-22
---  
# 체스  
## 1단계  
### [Java] 추상 메서드 - 4
#### 내용
- Piece 추상메서드를 각 기물들이 상속하여 각자의 규칙에 맞게 구현하도록 하였다.

### [Testing] 단위테스트 - 2
#### 내용 
- public으로 사용되는 모든 메서드를 단위 테스트 구현했다.
- TDD로 구현하고 싶었지만 리팩토링을 진행하는 과정에서 많이 실패하였다.

### [Java] stream API - 4
#### 내용
- board 객체를 순회하기 위해 stream을 사용하였다.
- point 객체 캐싱에 있어서 stream을 이용해 구현하였다.

### [Java] enum - 4
#### 내용
- Color 이름을 상수로 enum에서 관리하였다.
- 8방향의 direction을 각 방향의 +1, 0, -1 을 가지고 있도록 하여 enum으로 관리하였다. 
- 초기 기물들을 위치시키는데에 있어서 Enum으로 각 기물을 위치시키도록 하였다.

### [Java] OOP - 4
#### 내용
- 객체 지향 프로그래밍을 지키면서 구현하고자 노력하였다.
- 원시값 포장을 위해 노력하고, 일급 컬렉션을 만들고자 하였다.  

### [Java] 정적팩토리 메서드 - 3
#### 내용  
- point를 캐싱해 정적팩토리 메서드를 적용해 필요한 객체를 얻도록 했다.  

### [Java] Optional - 3
#### 내용  
- 방향을 찾다가 null이 반환 되는 경우 Optional.empty()가 반환되도록 했다.  
- 하지만 optional은 비싸서 null을 비교해 값을 얻도록 수정했다.  

<br>

## 2단계  
### [Java] try-with-resources - 3
#### 내용
- try-with-resources를 사용해 connection 자원들을 autocloseable 하도록 해주었다.  

### [Web] web 계층 - 4
#### 내용
- service 계층을 생성하여 비즈니스 로직을 수행하도록 했다. 
- controller 계층으로 client와 service 간의 통신을 담당하도록 했다.
- dto가 계층간 데이터를 이동하도록 했다.

### [Network] http - 3
#### 내용
- 적절한 method로 통신하도록 구현했다.
- 적절한 응답 코드를 보내도록 구현했다.

### [Testing] 단위테스트 - 2
#### 내용 
- public으로 사용되는 모든 메서드를 단위 테스트 구현했다.

### [Java] 객체지향 - 2
#### 내용 
- domain을 담당하는 객체들을 규칙에 맞춰 객체지향적으로 구현해 domain을 건드리지 않고 웹 컨트롤러와 연결하도록 했다.

### [SQL] mysql - 2
#### 내용 
- sql과 프로젝트를 연결해 테이블을 제작하고 적당한 쿼리문을 사용해서 필요한 값을 넣고 받을 수 있도록 하였다.  
#### 링크  
- [sql 관련 TIL](https://dusdn1702.github.io/techcourse/43)  

### 링크
- [TIL 정리 3/17](https://dusdn1702.github.io/techcourse/32)
- [TIL 정리 3/19](https://dusdn1702.github.io/techcourse/34)
- [TIL 정리 3/24](https://dusdn1702.github.io/techcourse/37)
- [TIL 정리 4/5](https://dusdn1702.github.io/techcourse/45)
- [TIL 정리 4/6](https://dusdn1702.github.io/techcourse/46)
- [TIL 정리 4/8](dhttps://usdn1702.github.io/techcourse/48)
