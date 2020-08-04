---
title: "로또"
excerpt: "java 공부"
permalink: /study/4

categoriem:
  - study
tags:
  - study

last_modified_at: 2020-07-20
---

# 로또 

<br>

# 7/20
- 일급 컬렉션이란
        다른 멤버 변수가 없는 상태  
        final은 재할당만 금지, 불변은 아님  
- exception 처리
        여러개를 throw하는 경우 쉼표로 구분  
        exception을 활용해 무언가 한다면 checked exception, 안한다면 unchecked exception  
        void send() throw Exception{} 의 구현도 가능하다  
        try는 exception 잡고, catch는 발생하면 할 일, finally는 무조건 할 일  
        예외 발생 원인 찾기 위해 stack trace 하는 것도 가능  
        catch된 예외 처리하고 다시 throw하는 것도 가능   
- enum의 사용
        클래스와 같은 구현으로, 클래스를 상수처럼 사용하는 것  
        관련 있는 상수 값들을 enum으로 구현하면 유용하다  

# 7/21
- Random stream의 사용
        Random().ints(3, 0, 11)할 경우 1부터 10까지 3개의 랜덤 함수 생성  
        중복을 방지하기 위해 .distinct() 사용  
        distinct 사용할 경우 .limit(3)으로 갯수 제한 필요  
        .boxed()를 이용해 상태 cast 가능  
        .collect(toList())를 사용해 list로 만들기  
        한개씩 랜덤넘버 만들 경우 nextInt(upper) 사용  
- null 예외처리
        Objects.requireNonNull(inputNumbers, "숫자가 null입니다.");  
        로 하면 inputNumbers 안에 있는 null이 예외처리됨  
- ArrayList <-> List
        List<> 만들으려면 Arrays.asList() 사용  
        List -> ArrayList 는 arrayList.addAll(List)  
        ArrayList -> Array 는 arrayList.toArray(arr)  
        ArrayList는 클래스, List는 인터페이스 (int, Integer)  
        ArrayList는 동적으로 조절 가능  

# 7/23
- valueOf의 사용
        입력한 인자를 Number 객체 형으로 변환해서 반환하는 것  
        enum에서 valueOf를 사용했다면 그 클래스 형식으로 변환해서 반환해준다  
        Integer, String, Float 등등 사용 가능  
- BigInteger란 
        long보다 큰 수를 다뤄야할 때 BigInteger 사용  

# 7/25
- interface의 사용
        객체의 기능을 구현하는 함수  
        인터페이스 속 기능들을 객체가 갖도록 하겠다. <public class LEDTV implements TV> 로 사용  
        참조변수의 타입으로 인터페이스도 사용할 수 있다.  
        동일한 인터페이스를 사용하는건 클래스의 사용법이 같다는 것을 의미  

# 7/27
- map
        new linkedHashMap 사용하면 key와 value에 관계없이 입력 그대로 출력 가능  
        각각 value, key에 따라 오름차순/내림차순 정렬도 가능  
        TreeMap<>(comparator) 는 애초에 넣을 때 정렬됨  
        List를 이용하는 경우 한쪽만 정렬이 필요하면 정렬할 수 있다  
        Stream을 이용해서도 정렬 가능  
- ArrayList와 LinkedList
        추가/삭제가 빈번하면 Linked, 인덱스 조회가 빈번하면 Array  
- getter의 사용을 지양하자  
        getter는 객체를 노출시킨다. 객체에게 메시지를 보내서 직접 판단하도록 하자  