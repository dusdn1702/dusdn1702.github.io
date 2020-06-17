---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 올바른 괄호"

categories:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-17
---
올바른 괄호 - 연습문제  
<https://programmers.co.kr/learn/courses/30/lessons/12909>  
괄호의 개수가 같지 않으면 false  
닫는 괄호가 여는 괄호보다 많으면 거기서 false로 진행  

<br>
```cpp
#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int openCount = 0;
    int closeCount = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(') openCount++;
        else if(s[i]==')') closeCount++;
        if(closeCount>openCount) return false;
    }
    if(closeCount!=openCount) return false;
    return answer;
}
```
<br>
소요 시간 : 15분
