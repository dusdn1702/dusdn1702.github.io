---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 스킬트리"
permalink: /algorithms/43

categories:
  - algorithms
tags:
  - programmers
  - algorithms
  - python
last_modified_at: 2020-08-24
---
스킬트리  
<https://programmers.co.kr/learn/courses/30/lessons/49993>  
처음에는 모든 스킬들이 존재해야한다고 생각하고 풀어서 틀렸다.  
리스트에 각 스킬들이 존재하는 첫번째 위치를 \*skill_tree.find(k번째스킬)\* 로 스킬 개수 만큼돌려서 넣고,  
그 리스트가 오름차순이면 되도록 하였다. 모든 스킬을 배워야 한다면 맞는 구현이었을 거라 생각한다.  
그래서 다시 찾은 방법은 skill에 있는 스킬이면 문자열에 \*+\*하도록 하였다. 한번씩만.  
그래서 \*\*문자열만큼이 skill과 같은 문자열을 갖고 있다면\*\*  
체커가 false로 돌리고 answer++하지 못하도록 하였다.  
<br>  
1차시도 - 첫번째가 없으면 안되지만 2단계까지만 배워도는 되는 부분 미고려  

``` python
def solution(skill, skill_trees):
    answer = 0
    for i in skill_trees:
        skill_list = list(skill)
        haveToAsc = []
        for k in skill_list:
            haveToAsc.append(i.find(k))
        if haveToAsc.count(-1)!=0:
            break
        for j in range(len(skill)):
            if haveToAsc[j]<haveToAsc[j-1]:
                break
        answer+=1
    return answer
```
<br>
2차시도 - 정답  

``` python
def solution(skill, skill_trees):
    answer = 0
    skill_list = list(skill)
    for i in skill_trees:
        tmp = ""
        isOk = True
        for k in i:
            if skill.find(k) != -1:
                tmp += k
        for j in range(len(tmp)):
            if skill_list[j] != tmp[j]:
                isOk = False
                break
        if isOk == True:
            answer+=1
    return answer
```  
소요시간 ; 45분