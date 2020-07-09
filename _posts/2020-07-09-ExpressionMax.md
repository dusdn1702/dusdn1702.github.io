---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 수식 최대화"
permalink: /algorithms/34


categoriem:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-07-09
---
수식 최대화 - 2020 카카오  
<https://programmers.co.kr/learn/courses/30/lessons/67257>  
아 잘못 풀었네 ㅋㅋ,,,,,  
위치 바꾸는거 아니고 그대로에서 먼저 계산할 거 찾는거...  
```cpp
#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

long long solution(string expression) {
    long long answer = 0;
    deque<long long> numbers;
    vector<char> operators;
    string tmp = "";
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            numbers.push_back(atoll(tmp.c_str()));
            operators.push_back(expression[i]);
            tmp.clear();
        } else {
            tmp += expression[i];
        }
    }
    numbers.push_back(atoll(tmp.c_str()));
    tmp.clear();

    vector<char> tmpOperators;
    for (int i = 0; i < operators.size(); i++) {
        tmpOperators.push_back(numbers[i]);
    }

    do {
        vector<long long> tmpNumbers;
        for (int i = 0; i < numbers.size(); i++) {
            tmpNumbers.push_back(numbers[i]);
        }
        long long nowAnswer;

        for (int i = 0; i < operators.size(); i++) {
            for (int j = 0; j < tmpOperators.size(); j++) {
                if (tmpOperators[j] == operators[i]) {
                    if (operators[i] == '*') {
                        nowAnswer = tmpNumbers[i] * tmpNumbers[i + 1];
                    } else if (operators[i] == '/') {
                        nowAnswer = tmpNumbers[i] / tmpNumbers[i + 1];
                    } else if (operators[i] == '-') {
                        nowAnswer = tmpNumbers[i] - tmpNumbers[i + 1];
                    } else if (operators[i] == '+') {
                        nowAnswer = tmpNumbers[i] + tmpNumbers[i + 1];
                    }
                    i--;
                    tmpOperators.erase(tmpOperators.begin() + j);
                    tmpNumbers.erase(tmpNumbers.begin() + j, tmpNumbers.begin() + j + 2);
                }
            }
        }
        answer = max((long long)0, abs(nowAnswer));
        tmpOperators.clear();
        tmpNumbers.clear();
    } while (next_permutation(operators.begin(), operators.end()));

    return answer;
}
```
아직 성공 못했다.  
next_permutation 하면서 찾는건 잘 한 것 같은데 tmp들 만들어서 비교하고 계산하는 과정에서 문제가 있는 것 같다.  
아직 진짜 부족한 것 같다. 이런 문제에 두시간이라니 ㅠㅠ  
더 공부하자..  