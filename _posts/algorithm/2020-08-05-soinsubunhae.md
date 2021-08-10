---
title: "알고리즘 공부"
excerpt: "백준 ; 소인수분해"
permalink: /algorithms/36


categories:
  - algorithms
tags:
  - programmers
  - algorithms
  - python
last_modified_at: 2020-08-05
---
소인수분해-silver4  
<https://www.acmicpc.net/problem/11653>
숫자 입력 받으면 소인수들을 오름차순으로 출력하기  
i를 2부터 나누어떨어지는 것 차례로 출력  

```python
N = int(input()); i=2
while N>1:
    if(N%i==0):
        N/=i
        print(i)
    else:
         i+=1
```

소요시간 ; 15분