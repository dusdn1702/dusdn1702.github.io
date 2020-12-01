---
title: "자바 공부"
excerpt: "우아한테크코스와 함께"
permalink: /study/17
categories:
  - study
  - java
tags:
  - study
  - java
  
last_modified_at: 2020-11-26
--- 
# 우아한테크코스와 함께 하는 자바 공부

## 1주차 - 숫자야구게임

### 요구사항
- 자바 코드 컨벤션 지키기
- indent 2까지만
- 3항 연산자 쓰지 않기
- 함수가 한가지 일만 하도록 최대한 작게 만들기
- System.exit 이용하지 않기
- 비정상적 입력에 대해 IllegalArgumentException 발생

### 배운 것

#### static과 final
- static : 클래스의, 공통적인 의미로 인스턴스 변수는 하나의 클래스로부터 만들어졌더라도 다른 값을 갖지만, static 변수는 인스턴스에 관계없이 같은 값을 갖는다. static은 멤버변수, 메서드, 초기화 블럭에 사용 가능하며 사용하는 것이 더 편리하고 속도도 빠르다.
- final : 마지막의, 변경될 수 없는 의미로 거의 모든 대상에 사용될 수 있다. 사용하면 값을 바꿀 수 없는 상수가 되고 메서드는 오버라이딩 불가, 클래스는 자식 클래스 정의 불가하게 된다.

#### Random 함수의 사용
new Random() 으로 선언하고 random.nextInt(n)을 하면 0~n-1까지의 난수를 출력하므로 1+random.nextInt(9-1+1)를 하면 1부터 9까지가 출력된다. 

#### Integer와 int의 차이
Integer는 Wrapping 객체이다. 따라서 .equals로 비교, int는 자료형으로 ==와 같은 산술 연산 가능 비교

#### stream의 사용
- 배열의 stream 생성: Stream.of(array)
- List의 stream 생성: list.stream()
- match: anyMatch(i->i==number), noneMatchanyMatch(i->i==number), allMatchanyMatch(i->i==number)와 같이 조건에 따라 true, false로 출력
- filter(): filter(i->i%2==0)과 같이 조건에 맞게 걸러내기
- forEach(): 걸러낸 것들이나 뭐 각각에 forEach(System.out.print("h"))와 같이 함수 적용하기
- sorted(): 정렬 가능
- distinct(): 중복 제거
- map(): map(s->s.substring(0, 1))과 같이 형의 변환하면서 매핑
- collect(): stream의 요소들을 List나 Set 자료형으로 변환, joining(ex; .stream().map(Card::toStringInfo).collect(Collectors.joining(","))), sorting, 평균값 등 리턴
+ intStream은 sum(), average(), max(), min() 계산 가능
+ intStream.range(0, 3).filter(index -> numbers.get(index).equals(randomnumbers.get(index))).count() 하면은 index에 따른 비교할 수 있다.

#### 메서드의 참조
Player::calculate() 과 같이 메서드 참조 사용 가능

#### 상수 분리
private static final int CONSTANT_NAME = 1; 과 같이 변하지 않는 고정 상수, 문자열 빼서 정의해주기, 얘네들도 올바른 객체에 필요한 위치에 있는지 확인해주기

#### 객체 다루기
컨트롤러는 무상태 객체, 따라서 필드변수는 필요 없다.  
생성자를 사용해서 객체 내에 객체를 선언하고 다루면 더 좋다.  
컨트롤러에 모든걸 다 넣는게 좋은게 아니다.  
static은 올려놓고 가져다 쓰는 것.  
정적 클래스는 쓸때마다 호출하는 것.  
\*객체에 필드변수 갖는 것은 관리해야할게 느는 것. 이 객체가 변수를 가지고 다루는게 맞는지 항상 생각하자\*

#### List, Map, Set
- List : 순서가 있고 중복 허용, Arrays.asList, List.of 로 생성
- Set : 순서가 없고 중복 비허용, Set.of로 생성
- Map : key-value의 쌍, Map.of로 생성

## 1주차 - 블랙잭게임

### 배운 것

#### String 다루기
- string.split(",")하면 string[]으로, Arrays.asList(string[])하면 List<>으로 나눠짐
- String.join("", array)하면 String 하나로 합쳐짐
- String은 불변임, StringBuffer나 StringBuilder가 가변적임. 따라서 문자열에 변화가 빈번하면 가변적인거 사용. StringBuilder는 동기화를 지원하지 않아 멀티쓰레드에서는 부적합하지만 단일쓰레드에서 성능은 더 좋고, StringBuffer는 동기화 되어 멀티쓰레드 환경에서 안전, String도 안전.

#### Collections
- Collections.shuffle(list) 하면 리스트 셔플

### 앞으로
- 좀 더 세분화해서 기능 별로 커밋하는 습관을 가지고, 구현 목록도 세분화해서 작성하자
- 객체의 역할과 책임에 대해 끊임없이 생각하자
- 어떻게 하면 요구사항이 바뀌어도 사용할 수 있는 코드일까 고민하자
- 가독성이 좋은 코드인지 고민하자
- 컨벤션 지키기를 잊지 말자
- 하지 말아야 할 것(객체 내 불필요한 필드 변수의 선언, getter의 남발, depth 2 이상, else의 사용)을 최대한 줄이려고 고민하자