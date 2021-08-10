---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 소수찾기"
permalink: /algorithms/44

categories:
  - algorithms
tags:
  - programmers
  - algorithms
  - python
last_modified_at: 2020-08-27
---
소수 찾기
<https://programmers.co.kr/learn/courses/30/lessons/42839>
처음에 소수를 찾을 범위를 구하는데에서 애를 먹었다.  
int(number/2)로 할 경우 뒤에 소수를 짤라버려서 돌아야 할 수를 하나 덜 도므로 +1을 해주어야 하고,  
최적화된 것은 number의 제곱근에 +1 하는 경우이다.  
permutation 사용법과 join의 사용법을 더 익히자!  
list와 set을 자유자재로 왔다갔다 하고, 각 자료형을 왜 쓰는지, 어떻게 쓰는지도 알아야 할 것 같다.  
<br>

``` python
from itertools import permutations
import math

def prime(number):
    if number < 2:
        return False
    k = math.sqrt(number)
    for i in range(2, int(k)+1):
        if number%i==0:
            return False
    return True
def solution(numbers):
    answer = []
    for j in range(1, len(numbers)+1):
        numberList = list(map(''.join, permutations(list(numbers), j)))
        for k in list(set(numberList)):
            if int(k)==1:
                break
            if prime(int(k)):
                answer.append(int(k))
    return len(set(answer))
```
소요시간 ; 1시간