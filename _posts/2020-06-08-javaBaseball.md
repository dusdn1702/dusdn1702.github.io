---
title: "숫자야구 콘솔 게임 만들기"
excerpt: "java 공부"
permalink: /study/
categories:
  - study
tags:
  - study
last_modified_at: 2020-06-25
---

처음으로 자바 배워서 제작해봤다.  

재밌다. 열심히 기록하면서 배우자.  

컨벤션 지켜서 명명하는 방법, 객체 나눠서 사용하는 방법.

## int 자료형을 char로 바꾸는 방법  
- char character = (char) (int integer+'0');  
- Character.forDigit(a,10);  
  10은 십진수를 의미한다.  
- Integer.toString(number).charAt  
  매번 String 호출한다는 단점  
- Character.toChars(number)
  매번 Chars 호출하는 단점

## 1부터 9까지 랜덤 고를때
0부터 9까지 고른 랜덤에서 무조건 1을 더하고 연산한다.  
이러면 굳이 0일 경우를 안골라내도 된다.  

## public static final char  
char도 상수화 가능하다.  