---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 체육복"
permalink: /algorithms/50

categories:
  - algorithms
tags:
  - programmers
  - algorithms
  - python
last_modified_at: 2020-09-07
---
체육복  
<https://programmers.co.kr/learn/courses/30/lessons/42862>  
생각을 잘못했다.  
해놓고 왜 안되지 라고 계속 생각했는데 잃어버렸는데 여분이 있는 학생도 있었다.  
이게 그 코드   
```python
def solution(n, lost, reserve):
    answer = (n-len(lost))
    for i in lost:
        for j in reserve:
            if i-1==j or i+1==j:
                lost.remove(i)
                reserve.remove(j)
                answer+=1
                
    return answer
```  
그러고 나서는 그렇게 겹치는 애들을 어떻게 처리해줄지 몰라서 한참 헤맸다.  
그러다가 포기한게 이 코드  
여기서는 set으로 중복을 제거할라했는데 생각해보니까 set 하면 중복 빼고 하나씩 남아있었다..  
그래서 실패..  
++ 검색해보니 이렇게 하면 됐다.  
```python
    lostN = list(set(lost) - set(reserve))
    reserveN = list(set(reserve) - set(lost))
```  

```python
def solution(n, lost, reserve):
    answer = (n-len(lost))

    total = set(lost + reserve)
    lost.sort()
    reserve.sort()
    answer += (len(lost)+len(reserve)-len(total))
    for i in range(len(lost)):
        if lost[i] in total:
            for j in range(len(reserve)):
                if reserve[j] in total:
                    if lost[i]-1==reserve[j] or lost[i]+1==reserve[j]:
                        lost[i]=-1
                        reserve[j]=-1
                        answer+=1
        print(lost, reserve)
    return answer
```
마지막으로 이게 멋쟁이 코드..  
저렇게 문장형으로 파이썬처럼 쓰는 것 좀 배우자!!  
```python
def solution(n, lost, reserve):
    realReserve = [i for i in reserve if i not in lost]
    realLost = [j for j in lost if j not in reserve]
    
    for r in realReserve:
        if r-1 in realLost:
            realLost.remove(r-1)
        elif r+1 in realLost:
            realLost.remove(r+1)
    return n-len(realLost)
```  
소요시간 ; 1시간 30분  
차분하고 침착하게 더 생각하면서 예외 생각도 하고 케이스도 찾아내면서 공부하자 ㅠㅠ