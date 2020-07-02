---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 하샤드 수"
permalink: /algorithms/15

categoriem:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-21
---

하샤드 수 - 연습문제  
<https://programmers.co.kr/learn/courses/30/lessons/12947>  
int로 주어진 값을 각 자리로 나눠서 다 더해서 나눠지면 하샤드 수  
to_string 사용하는 방법  
이때 string에는 char로 들어갔으므로 -'0' 필요함!!  
x를 10의 제곱수로 나눠서 다 더하는 방법  
이때 나눠진 x를 기록해줄 tmp 필요함!!  
<br>
```cpp
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//2차 to_string 사용
bool solution(int x) {
    bool answer = true;
    string s = to_string(x);
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        sum += s[i] - '0';
    }
    cout << sum;
    if (x % sum != 0) answer = false;
    return answer;
}
```
<br>
```cpp
1차 제곱수로 나누기 사용
틀린 이유 ; x 값을 바꿔가며 계산하지 않아서
bool solution(int x) {
    bool answer = true;
    vector<char> tmp;
    for (int i = 0; i <= 5; i++) {
        if (x >= pow(10, i)) {
            cout << x / pow(10, i);
            tmp.push_back(x / pow(10, i));
        } else
            break;
    }
    int sum = 0;
    for (int i = tmp.size() - 1; i >= 0; i--) {
        sum += tmp[i];
    }
    if (x % sum != 0) answer = false;
    return answer;
}
```
<br>
```cpp
//1차 정답
bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int tmp = x;
    while (tmp != 0) {
        sum += tmp % 10;
        tmp = tmp / 10;
    }
    if (x % sum != 0) answer = false;
    return answer;
}
```
<br>
소요시간 ; 15분
