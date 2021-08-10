---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 완주하지 못한 선수"
permalink: /algorithms/46

categories:
  - algorithms
tags:
  - programmers
  - algorithms
  - python
last_modified_at: 2020-09-01
---
완주하지 못한 선수  
<https://programmers.co.kr/learn/courses/30/lessons/42576>

우선 처음에는 참가자에서 하나씩 제거해 하나 남은 참가자를 리턴하려고 하였다.  
코드는 아래,  
```python
def solution(participant, completion):
    answer = ''
    for runner in completion:
        participant.remove(runner)
        answer+=str(participant[0])
        return answer
```
성공했지만, 효율성 테스트에서 걸려 각 배열을 sort하고, 다른게 있으면 그게 정답, 아니면 가장 뒤에 있는것을 return 하도록 하여 효율성을 통과했다.  
```python
def solution(participant, completion):
    answer = ''
    participant.sort()
    completion.sort()
    
    for part, com in zip(participant, completion):
        if part!=com:
            return part
    return participant[-1]
```

<br><br>

추가적으로 배운 다른 사람 코드는 다음과 같다.  
collections.Counter를 사용한 방법으로 participant에서 completion을 뺀 하나가 답이 된다. 이는 ['자료이름':개수]로 이루어 진다.   
```python
import collections

def solution(participant, completion):
    answer = collections.Counter(participant) - collections.Counter(completion)
    return list(answer.keys())[0]
```  
<br>
굉장히 간단한 level 1인 문제였는데 효율성 테스트는 하나도 통과 못하고 오랜 시간이 걸린데에 충격받았다.  
혼자 구현하고 끊임없이 더 나은 방법을 생각해야겠다.  

소요시간 ; 1시간