---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 큰수만들기"

categories:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-16
---
<https://programmers.co.kr/learn/courses/30/lessons/42586>

```cpp//큰 수 만들기 - greedy
//1차
//순서 상관 없이 큰 수 만든다고 생각해서 틀림
#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
deque<int> deq;


string solution(string number, int k) {
    string answer = "";
    int first = 0;
    pair<int, int> firstnumi;
    for (int i = 0; i <= number.size() - k; i++) {
        if (first < number[i]) {
            first = number[i];
        }
    }
    firstnumi.first = first;
    for (int i = 0; i < k; i++) {
        if (number[i] == first) {
            firstnumi.second = i;
            break;
        }
    }
    deq.push_back(first);
    int canremove = k - firstnumi.second;
    for (int i = firstnumi.second + 1; i < number.size(); i++) {
        deq.push_back(number[i]);
        while (canremove--) {
            if (number[i - 1] < number[i]) {
                deq.pop_back();
            }
        }
    }
    for (int i = 0; i < number.size() - k; i++) {
        answer.push_back(deq[i]);
    }
    return answer;
}

//2차
//이중포문 돌려가며 진행
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;
deque<int> deq;
string solution(string number, int k) {
    string answer = "";
    
    int makeNumber = number.size() - k;
    int checkNumIndex = 0;
    int maxNumIndex = 0;
    char maxNum;
    
    for(int i=0;i<makeNumber;i++){
        maxNum = number[checkNumIndex];
        maxNumIndex = checkNumIndex;
        for(int j=checkNumIndex;j<=k+i;j++){
            if(maxNum < number[j]){
                maxNum = number[j];
                maxNumIndex = j;
            }
        }
        checkNumIndex = maxNumIndex + 1;
        answer += maxNum;
    }
    return answer;
}
```
<br>
<br>
처음에는 아예 접근을 잘못 했고,  
이중포문을 생각한 뒤로는 쉽게 풀었다.  
<br>
스택으로도 풀 수 있을 것 같은데 도전해봐야겠다.

