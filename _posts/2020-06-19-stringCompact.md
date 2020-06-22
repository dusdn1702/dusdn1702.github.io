---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 문자열 압축"
permalink: /algorithms/
categories:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-19
---
문자열 압축 - 카카오 공채 기출  
<https://programmers.co.kr/learn/courses/30/lessons/60057>  
계속 개수를 같은지 그 개수만큼 맨끝까지 돌리는 부분에서 헷갈렸다.  
꼼꼼히 tc 생각하는 습관!  
<br>
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    if (answer == 1) return 1;

    for (int i = 1; i <= s.length() / 2; i++) {
        string result = "";
        int cnt = 1;
        string tmp1 = s.substr(0, i);

        for (int j = i; j < s.length(); j += i) {
            string tmp2 = s.substr(j, i);

            if (tmp1 == tmp2) {
                cnt++;
            } else {
                if (cnt == 1) {
                    result += tmp1;
                    tmp1 = tmp2;
                } else {
                    result = result + to_string(cnt) + tmp1;
                    tmp1 = tmp2;
                    cnt = 1;
                }
            }
            if (i + j >= s.length()) {
                if (cnt == 1) {
                    result += s.substr(j);
                    break;
                } else {
                    result = result + to_string(cnt) + tmp1;
                    break;
                }
            }
        }
        if (result.length() < answer) {
            answer = result.length();
        }
    }
    return answer;
}
```
<br>
소요시간 : 1시간
