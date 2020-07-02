---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 정수 제곱급 판별하기"
permalink: /algorithms/16
categories:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-21
---

정수의 제곱근 판별 - 연습문제  
그냥 while문 돌리면서 풀기 || 함수 사용하기  
<https://programmers.co.kr/learn/courses/30/lessons/12934?language=cpp>  
sqrt(n)은 루트 씌우는 함수  
pow(n,2)는 n의 제곱 만드는 함수  
<br>
```cpp
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long t=sqrt(n);
    if ((pow(t,2)==n) && (t != 1)) {
        answer = pow(t + 1, 2);
    }
    else if(n == 1){
        answer=4;
    }
    else
        answer=-1;
    return answer;
}
```
```cpp
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    while(1){
        if(answer*answer == n){
            return (answer+1)*(answer+1);
        }
        if(answer>n){
            return -1;
        }
        answer +=1;
    }
    return answer;
}
```
<br>
소요시간 ; 10
