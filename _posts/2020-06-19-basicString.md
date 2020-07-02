---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 문자열 다루기 기본"
permalink: /algorithms/9
categories:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-19
---

문자열 다루기 기본 - 연습문제  
<https://programmers.co.kr/learn/courses/30/lessons/12918>  
프로그래머스 1단계 기본 문제라 너무 쉬웠다.  
그럼에도 불구하고 ascii code 찾아서 했다.  
'0'~'9' 썼으면 안찾아도 됐다.  
<br>
```cpp
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size()==4 || s.size()==6){
    for(int i=0;i<s.size();i++){
        if(s[i]>=48 && s[i]<=57) answer = true;
        else return false;
    }
    }else return false;
    return answer;
}
```
<br>
소요시간 ; 5분
