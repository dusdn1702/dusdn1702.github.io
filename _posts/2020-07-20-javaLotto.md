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