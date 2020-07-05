---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 압축"
permalink: /algorithms/31

categoriem:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-07-05
---

압축 - 2018 카카오  
<https://programmers.co.kr/learn/courses/30/lessons/17684>  
flag 사용해서 원하는 것 찾고 반복문 돌리는 것 익숙해지기  
string()써서 string 만드는 것  
다시 해보자  
```cpp
#include <string>
#include <vector>
using namespace std;

vector<int> solution(string msg) {
    vector<string>::iterator it;
    vector<string> dic = {"-"};
    for (int i = 0; i < 26; i++) {
        dic.push_back(string(1, 'A' + i));
    }
    vector<int> answer;
    bool check = true;
    int j = 0;
    for (int i = 0; i < msg.size(); i++) {
        string tmp = "";
        while (check) {
            tmp += msg[i];
            it = find(dic.begin(), dic.end(), tmp);
            if (it != dic.end()) {
                j = it - dic.begin()+1;
                i++;
            } else {
                check = false;
                answer.push_back(j);
                dic.push_back(tmp);
                i--;
            }
        }
    }
    return answer;
}
```
소요시간 ; 1시간