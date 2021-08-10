---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 멀쩡한 사각형"
permalink: /algorithms/41

categories:
  - algorithms
tags:
  - programmers
  - algorithms
  - python
last_modified_at: 2020-08-15
---
멀쩡한 사각형  
<https://programmers.co.kr/learn/courses/30/lessons/62048>  
전에 풀어봤던 것 같은 사각형에서 왼쪽위, 오른쪽아래 꼭짓점 연결해서 지나가는 사각형들 빼는 문제  
결국에 정답은 모든 사각형에서 가로+세로-최대공약수이다.  
최대공약수를 구하는 함수를 구현하고, 본 함수에서 사용해주었다.  
import math 하면 gcd 사용할 수 있다.  
```python
def gcd(a,b):
    if b==0: 
        return a
    return gcd(b, a%b)
def solution(w,h):
    answer = w*h
    if w==h:
        answer -=w
    elif w>h:
        answer-=(w+h-gcd(w,h))
    else:
        answer-=(w+h-gcd(h,w))
    return answer
```
소요시간 ; 15분