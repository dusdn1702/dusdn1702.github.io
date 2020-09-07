---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 더맵게"
permalink: /algorithms/49

categories:
  - algorithms
tags:
  - programmers
  - algorithms
  - python
last_modified_at: 2020-09-07
---
더맵게  
<https://programmers.co.kr/learn/courses/30/lessons/42626>  

처음부터 문제를 30분동안 잘못 이해하고 있었다.  
모든 지수가 k이상이 되어야 하는건데 1과 2*2 가 k만 넘으면 된다고 생각했다.  
문제를 제대로 보고 풀자!!  
그래서 정렬과 deque을 사용했는데 어디선지 자꾸 틀리고 시간 초과가 됐다.  
아래가 그 코드다. 아마도 정렬이 안되어있으니 앞에 두개만 보고 비교해 틀렸을 것이다.  
```python
#1 - 연습문제만 통과
from collections import deque
def solution(scoville, K):
    answer = 0
    scoville.sort()
    while 1:
        if scoville[0]<K:
            scoville.sort()
            tmp = scoville[0]
            del scoville[0]
            tmp += (scoville[0]*2)    
            scoville.insert(0,tmp)
            answer+=1
        else:
            return answer
    return -1
```  
<br>
그래서 찾아보니 파이썬에서 heap을 다룰 때 쓰는 heapq가 있어서 사용하여 통과됐다.  
여기서도 더해나가다가 하나밖에 안남은 경우에 -1을 return 하려했는데  
애초에 두개밖에 없을 경우를 고려하지 못했다.  
조금 더 생각하며 풀자.  

```python
#2 - 통과
import heapq
def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while 1:
        if scoville[0]<K:
            min1 = heapq.heappop(scoville)
            min2 = heapq.heappop(scoville)
            heapq.heappush(scoville, min1 + (min2*2))
            answer+=1
            if len(scoville)==1 and scoville[0]<K: #두개만 있을 때도 고려!!
                return -1
        elif scoville[0]>=K:
            return answer
```  
소요시간 ; 45분