---
title: "java 공부"
excerpt: "자동차 경주게임"
permalink: /study/

categoriem:
  - study
tags:
  - study

last_modified_at: 2020-06-23
---

#자동차 경주게임 

<br>
## TDD 란
요구사항에 맞추어 TEST 코드를 구현하고, 테스트가 성공하도록 실제 프로덕션 코드를구현하는 것이다!  
**단위 테스트를 작성하고production code를 작성한다.**  
<br>
## 자동차 경주 게임 요구사항
- 사용자는 이름을 쉼표 기준으로 구분해 입력
- 이름은 5자 이내
- 사용자는 몇 번의 이동을 할 것인지 입력
- 주어진 횟수 동안 n대의 자동차는 전진 또는 멈춤
- 전진은 각 자동차 0-9의 random 값이 4이상이면 전진, 3이하면 멈춤
- 전진하는 자동차 출력할 때 이름도 같이 출력
- 우승자 출력
- 공동 우승이면 우승자 모두 출력
<br>
### 새로 배운 함수
1. 스트림
  - stream은 컬렉션, 배열 등의 저장 요소를 하나씩 참조하며 함수형 인터페이스를 적용하며 반복적으로 처리할 수 있도록 해주는 기능  
  - stream.collectors.tolist 에 있는 .collect(toList())는 list로 모아준다.  
  - boxed는 stream을 매핑해준다.  
2. int 와 Integer의 차이  
  - int는 내가 흔히 아는 long, float, double 등과 같은 정수 자료형이고 산술 연산이 가능하며 null로는 초기화할 수 없는 wrapping 된 정수이다.  
  - Integer는 wrapper 클래스로 객체이며, unboxing하지 않으면 연산이 불가능하지만 null은 처리할 수 있다.  
  - Integer.valueOf(String)은 클래스로 리턴되어 계산이 안되지만 Integer.parseInt(String)은 자료형으로 계산 가능하다.  
3. 단위 테스트를 하는 경우
  - 로직이 필요하다면 단위 테스트를 해야하지만 이미 만들어진 라이브러리로 할 경우 필요없다..  
4. 배열 테스트 하기
  - String[]의 경우 = {"abc", "de"}로 actual, expected 나눠서 확인
  - List<>의 경우 = Arrays.asList("abc", "de")로 actual, expected 나눠서 확인