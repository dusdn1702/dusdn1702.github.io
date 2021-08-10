---
title: "알고리즘 공부"
excerpt: "동빈북 ; 큰 수의 법칙"
permalink: /algorithms/54

categories:
  - algorithms
tags:
  - dongbin
  - algorithms
  - python
last_modified_at: 2020-11-04
---  
#greedy  
#큰수의 법칙  
#주어진 수들을 m번 더해 가장 큰 수를 만든다.  
#특정한 인덱스에 해당하는 수가 연속해서 k번을 초과해 더해질 수 없다.  
```python
n, m, k = map(int, input().split())
numbers = list(map(int, input().split()))
result = 0
numbers.sort()

while 1:
  for _ in range(k):
    if m==0:
      break
    result+= numbers[-1]
    m-=1
  if m==0:
    break
  result+=numbers[-2]
  m-=1
print(result)
```
#제일 큰 수와 그 다음 수만 번갈아가며 더해주면 된다는 것을 생각하지 못했고, 이후에도 가장 큰 수를 더해준 다음에 이중으로 반복문을 사용해 두번째를 더해줄 생각을 하지 못했다..  
심지어 숫자가 억 단위로 커질 때의 예외 사항에 대해서 전혀 고려하지 않았다...ㅠㅠ  
소요시간 : 30분  
