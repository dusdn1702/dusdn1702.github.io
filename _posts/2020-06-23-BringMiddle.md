---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 가운데 글자 가져오기"
permalink: /algorithms/21

categoriem:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-23
---
가운데 글자 가져오기 - 연습문제  
<https://programmers.co.kr/learn/courses/30/lessons/12903>  
문자열의 가운데 글자 가져오는 문제  
짝수면 가운데 두개  
<br>
```cpp
#include <string>
#include <vector>

using namespace std;

//직접 찾아서 push_back 하는 방법
string solution(string s) {
    string answer = "";
    if(s.size()%2==1){
        answer.push_back(s[s.size()/2]);
    } else{
        answer.push_back(s[s.size()/2-1]);
        answer.push_back(s[s.size()/2]);
    }
    return answer;
}
```
<br>
```cpp
//substring 사용하는 방법
string solution(string s) {
    string answer = "";
    if(s.size()%2==1){
        return s.substr(s.size()/2,1);
    } else{
        return s.substr(s.size()/2-1,2);
    }
    return answer;
}
```
<br>
소요시간; 5분
