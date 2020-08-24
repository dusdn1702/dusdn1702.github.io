---
title: "파이썬 알고리즘 공부"
excerpt: "python 공부"
permalink: /study/5

categories:
  - study
tags:
  - study

last_modified_at: 2020-08-04
---
## 20/08/04
- 리스트에서 -1은 제일 뒷 요소를 가리킨다.  
- range(2, -1, -1)이라면 2부터 -1(마지막)까지 -1씩 거꾸로 가는 경우이다.  

## 20/08/05
- for _ in range(int) : int 만큼 돈다  
- for i in range(len(list)) : list 길이만큼 하나씩  
- else if의 표기는 elif  
- {}사이에 글자 출력, %숫자 하면 숫자 출력 두개씩 해야 각자 기호 출력 가능
- for i in str: 하면 문자열 하나하나 차례로 돌아간다  
- python의 모든 정수는 크기 상관 없이 int  
- list.sort()는 오름차순 1,2,3,4
- list.sort(reverse=True)는 내림차순 4,3,2,1
- list.reverser()는 list를 거꾸로
- list.sort(key=len)은 길이순으로 정렬

## 20/08/06
- %s 문자열, %c 문자1개, %d 정수, %f 부동소수, %o 8진수, %x 16진수

## 20/08/07
- set 자료형의 특징을 사용하면 list의 중복을 제거할 수 있다.
  1. 중복을 허용하지 않는다.
  2. 순서가 없다.
- 형변환은 abc = set(wasList)
- max(a,b,c)면 a,b,c 중 최대
- list.count(요소) 하면 요소의 개수 나옴
- list의 생성은 [a,b,c]

## 20/08/09
- 딕셔너리 자료형 ; LIST = {'HI':11, 'HELLO':10} 등의 Key, Value으로 map 생성
- 문자열[::-1] 하면 그 문자열 거꾸로 

## 20/08/11
- 문자열 포맷팅 여러개 한 경우 괄호로 묶어서 전달 print("one is %d\n two is %d", %(1,2))
- ' + '.join(map(str, numbers)) 하면 numbers 요소 사이사이에 +가 쪼인된다
- lambda 인자 : 표현식 ex) lambda x:x[1] 하면 x가 1번째 요소가 됨
- sorted(list, key = lambda x:x[1])의미는 list의 1번째 요소로 오름차순 sort
- print(list[-1][0])은 제일 큰거의 0번째 요소 출력

## 20/08/14
- 제곱: x**y 하면 x의 y제곱

## 20/08/15
- import math 하면 쓸 수 있는 함수
    math.ceil(수): 올림  
    math.fabs(수): 절댓값  
    math.factorial(수): 팩토리얼 함수  
    math.floor(수): 내림(-3.14면 -4)
    math.trunc(수): 내림(-3.14면 -3)  
    math.gcd(1, 4): 최대공약수  
    math.modf(수): 정수와 소수 분리해 반환  
    math.pow(3,2): 3^2  
    math.sqrt(수): 제곱근 반환
    math.각삼각함수