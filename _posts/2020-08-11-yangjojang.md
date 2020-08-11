---
title: "알고리즘 공부"
excerpt: "백준 ; yangjojang of the year"
permalink: /algorithms/38

categoriem:
  - algorithms
tags:
  - baekjoon
  - algorithms
  - python
last_modified_at: 2020-08-11
---
술 많이 먹는 대학 찾기  
<https://www.acmicpc.net/problem/11557>  
딕셔너리 자료형을 사용하려다 실패했다.  
딕셔너리 자료형은 value로 key를 추출할 수 없으므로 경우에 맞지 않다.  
이 경우 list 속 list로 사용해 lambda식으로 sort하고,  
마지막요소의 0번째 요소인 대학을 출력하도록 한다.  

```python
T = int(input())

for _ in range(T):
    N=int(input())
    drink = []
    for _ in range(N):
        S,L= map(str, input().split())
        drink.append([S, int(L)])
    drink = sorted(drink, key = lambda x:x[1])
    print(drink[-1][0])
```
소요시간 ; 30분