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
- throw한 exception들 catch로 잡아서 System.out.println(e.getMessage());로 출력하자

## 2주차 - 자동차경주게임

### 요구사항
- 자바 코드 컨벤션 지키기
- indent 2까지만
- 3항 연산자 쓰지 않기
- 함수가 한가지 일만 하도록 최대한 작게 만들기
- System.exit 이용하지 않기
- 비정상적 입력에 대해 IllegalArgumentException 발생, 에러 문구 [ERROR]로 출력
- 함수의 길이 15라인 이하
- else 예약어 쓰지 않기: if 조건절에서 값 return

### 배운것

#### MVC 패턴
- model: 모델은 데이터를 가지고 있는 객체로 데이터가 바뀌었을 때 컨트롤러의 데이터를 업데이트하는 로직도 포함한다. 
- view: 모델에 포함된 데이터의 시각화
- controller: 컨트롤러는 모델과 뷰에 모두 영향을 미치고 데이터 흐름을 제어하고 뷰를 갱신한다.
+ 따라서 데이터와 관련된 작업을 할때는 모델, 뷰는 건드릴 필요 없이 컨트롤러 객체만 건드리면 되도록 만들어야 한다.

#### 객체지향 원칙 9가지
1. 한 메서드에 하나의 들여쓰기만 한다. 
메서드의 일이 적을수록 재사용성이 높고 디버깅도 쉽기 때문이다.
2. else 사용하지 않는다
조건문은 복제의 원인이 되고 가독성도 좋지 않기 때문이다. if에 return을 사용하면 각 분기마다 값을 return하도록 해서 안쓸 수 있다.
3. 모든 원시값과 문자열을 포장한다
사소한 값이더라도 정보를 전달할 수 있도록 포장한다.
4. 한 줄에 하나의 점을 찍는다.
스트림 등 체이닝을 하는 경우 외에는 점이 둘 이상 나오지 않도록 해야한다.  
내가 가진 객체, 내가 만든 객체, 파라미터로 넘겨받은 객체에만 메시지를 보내야한다.  
메시지를 받은 객체는 작업을 해야지 내 속을 보여주면 안된다.
5. 줄여쓰지 않는다.
과도한 축약은 코드 가독성을 저해하므로 삼가한다. 메서드 이름이 길어지면 책임이 너무 많아서일 수 있으니 확인할 것.
6. 모든 entity를 작게 유지한다.
50줄 이상 되는 클래스, 10개 파일 이상의 패키지는 안된다.
7. 2개 이상의 인스턴스 변수를 가진 클래스는 쓰지 않는다.
기본형 또는 자료구조형 객체들은 두개 이상 인스턴스 변수로 사용하지 않는다. 일급 컬렉션, wrapper 객체는 가능하므로 객체를 또 만들도록 한다.
8. 일급 컬렉션을 사용한다.
collection을 wrapping하면서 다른 변수가 없는 클래스의 상태이다. (클래스에 컬렉션(list, set) 하나만 넣는다.)
모든 로직이 컬렉션에서 구현되므로 종속적이고, private final로 불변성이 보장되고, 값과 로직이 함께 ㅈ있어 관리가 쉬워진다.
9. getter/setter/property 삼가한다.
객체에 메시지를 던져서 작업하지 값을 다른데서 다루지 말자.  

#### 인텔리제이 단축키
- 상수 생성: ctrl+alt+c
- 함수 추출: ctrl+alt+m

#### split 함수 공백 처리
- .split(",", -1)하면 마지막 공백처리까지 할 수 있다.

#### string -> int 
- Integer.parseInt(string) 으로 바꾸고, 바꿀 수 없을 경우 NumberFormatException 발생

#### forEach() vs for()
- 성능, 가독성의 면에서 맵핑이나 필터링과 같이 값을 다루는 것이 아닐 경우에는 for를 사용하는 것이 더 좋다.

#### 클래스와 인스턴스
- 클래스는 붕어빵 틀, 상태가 없다. 메서드는 인스턴스를 생성하지 않은 상태에서도 호출할 수 있다. 여러 인스턴스에서 공유하는 정보가 있는 경우에 필드를 생성해 사용한다.
- 인스턴스는 객체, 상태를 가지고 메서드를 통해 상태가 변경된다. 인스턴스의 필드는 상태 정보를 가지고 있는 변수
