---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 같은 숫자는 싫어"
permalink: /algorithms/20

categories:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-22
---
같은 숫자는 싫어 - 연습문제  
<https://programmers.co.kr/learn/courses/30/lessons/12906>  
모든 데에서 같은 숫자 있으면 한개만 출력하는 줄 알았다.  
문제를 잘 읽자..  
<br>
```cpp
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    answer.push_back(arr[0]);
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i]!=arr[i+1]){
            answer.push_back(arr[i+1]);
        }
    }
    return answer;
}
```
<br>
소요시간 ; 20분