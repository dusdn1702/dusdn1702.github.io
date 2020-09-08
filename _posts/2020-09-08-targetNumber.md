---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 타겟 넘버"
permalink: /algorithms/50

categories:
  - algorithms
tags:
  - programmers
  - algorithms
  - python
last_modified_at: 2020-09-08
---
타겟 넘버  
<https://programmers.co.kr/learn/courses/30/lessons/43165>  
전형적인 dfs 문제로 각각 더하고 빼서 타겟넘버가 될 수 있는 개수가 몇개인지 세는 문제이다.  
처음에 혼자 생각할때는 +와 -를 list로 관리할까 했다. 그 개수가 정해져있지 않아 불가능한 생각이었다.  
dfs를 너무 오랜만에 풀어서 사실상 \*혼자 해결하지 못했다.\*  
재귀함수에서 매개변수는 그 함수에 들어가야하는 것들을 생각해야 한다.  
너무 어렵게 생각하지 않고 단순하게 푸는 연습을 해야할 것 같다.  
```python
answer = 0
def solution(numbers, target):
    global answer
    dfs(0, 0, target, numbers)
    return answer
def dfs(value, idx, target, numbers):
    global answer
    n = len(numbers)
    if (idx == n):
        if (target == value):
            answer+=1
        return
    dfs(value+numbers[idx], idx+1, target, numbers)
    dfs(value-numbers[idx], idx+1, target, numbers)
```  
소요시간 ; 1시간