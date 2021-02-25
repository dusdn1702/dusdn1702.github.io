---
title: "독서 정리 - 모던 자바 인 액션"
excerpt: "4장"
permalink: /study/21
categories:
  - study
  - java
tags:
  - study
  - java
  
last_modified_at: 2021-02-25
--- 
# 모던 자바 인 액션
<br> 

## [4장] 스트림 소개  
수많은 요소들을 포함하는 컬렉션들을 멀티스레드를 사용하지 않고 병렬로 처리할 수 있도록 한다.  
<br>

### 4.1 스트림이란?  
선언형으로 컬렉션 데이터를 처리하는 것으로 더 **간결하고 가독성이 좋아진다**  
stream()을 parallelStream()으로 바꾸면 코드를 멀티코어 아키텍쳐에서 병렬로 실행한다. 이렇게 되면 스레드와 락에 대한 걱정이 없어져 **성능이 좋아진다.**  
filter로 거른 요소들을 map으로 연결하고, 이들을 collect로 모은다. 이렇게 자유롭게 조립하며 **유연성이 좋아진다.**  
<br> 

### 4.2 스트림 시작하기  
스트림의 정의: **데이터 처리 연산**을 지원하도록 **소스**에서 추출된 **연속된 요소**  
    - 연속된 요소: stream은 특정 요소 형식으로 이뤄진 연속된 값 집합의 인터페이스, collection이 데이터라면, stream은 계산이 목적이다.  
    - 소스: stream은 데이터를 제공받아 생성되므로 형식과 순서도 유지된다.  
    - 데이터 처리 연산: DB와 유사한 연산을 지원한다.  
- 파이프라이닝: 스트림 연산끼리 연결해 커다란 파이프라인을 구성하도록 한다.  
- 내부 반복  
```java
List<Integer> hi = new ArrayList<>(1,2,3,4,5,6,10);
List<String> hello = hi.stream()
    .filter(i -> i < 10).map(String::toString)
    .limit(2)
    .collect(toList());
System.out.println(hello); //[1, 2]
```  
+ limit: 스트림 크기 제한  
<br> 

### 4.3 스트림과 컬렉션  
- 컬렉션  
자료구조가 포함하는 모든 값을 메모리에 저장하는 자료구조다.  
컬렉션에 추가하기 전에 계산되어야 한다.  
이미 다 만들어 놓는 착실한 친구  
**외부 반복**: 사용자가 직접 for-each를 사용해서 반복해야한다. 외부 반복은 병렬성을 포기하든지 synchronized 하든지 한다.  
- 스트림  
사용자가 요청할 때만 계산해서 넘겨주는 고정된 자료구조다.  
한번 생성된 스트림에 요소를 추가하거나 삭제할 수 없다.  
요청할 때만 나오는 게으른 친구
**내부 반복**: 함수만 전해주면 알아서 각 요소에 적용한다. 하드웨어를 활용한 병렬성을 자동으로 선택한다.  
<br>

### 4.4 스트림 연산  
`menu.stream().filer(i -> i < 10).map(Dish::getName).limit(2).collect(toList());`에서 stream을 형성하고 collect는 최종, 이전은 중간 연산이다.  
1. 중간 연산  
스트림은 시킬 때까지 실행하지 않는다.  
따라서 limit한 2개만 얻어내는 **쇼트서킷**과 filter와 map이 서로 다르지만 하나로 병합되는 **루프 퓨전**으로 엄청난 최적화의 효과를 얻을 수 있다.  
- filter: Predicate<T>  
- map: Function<T, R>  
- limit: 갯수 제한  
- sorted: Comparator<T>  
- distinct: 중복 제거
2. 최종 연산  
List, Integer, void 등과 같은 결과가 반환되는 것이다.  
- forEach: void 각 요소에 람다 적용  
- count: long 스트림 개수 반환  
- collect  
이렇게 stream은 다룰 `데이터 소스`, 파이프라인을 생성할 `중간 연산`과 완성할 `최종 연산`으로 이루어진다.  