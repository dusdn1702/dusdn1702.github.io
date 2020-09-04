---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 주식가격"
permalink: /algorithms/47

categories:
  - algorithms
tags:
  - programmers
  - algorithms
  - python
last_modified_at: 2020-09-04
---
주식가격 - 스택/큐
<https://programmers.co.kr/learn/courses/30/lessons/42584>
리스트에 있는 가격이 하나씩 뒤로 가며 떨어질 때까지 초를 하나씩 추가해서 세는 문제였다.  
이중 포문을 사용해서 풀었다.  
근데 deque도 사용할 수 있고, stack도 사용할 수 있다!!  
```python
def solution(prices):
    answer = []
    prices_list = list(prices)
    for i in range(len(prices_list)):
        cnt = int(0)
        for j in range(i+1, len(prices_list)):
            cnt +=1
            if prices_list[i] > prices_list[j]:
                break
        answer.append(cnt)
    return answer
```
소요시간 ; 20분