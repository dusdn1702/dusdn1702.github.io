---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 연습문제"
permalink: /algorithms/23

categoriem:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-26
---
각 소요 시간이 15분 내외로 또 다른 공부할 거리가 없는 연습 문제들을 모아두었다.
<br>
휴대폰번호 가리기  
```cpp
string solution(string phone_number) {
    string answer = "";
    int cnt = 0;
    for (int i = 0; i < answer.size(); i++) {
        if (cnt < answer.size() - 4) {
            answer.push_back((char)9);
        } else {
            answer.push_back(phone_number[i]);
        }
        cnt++;
    }
    return answer;
}
```
<br>
약수의 합 - 연습문제  
```cpp
int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            answer += i;
        }
    }
    return answer;
}
```
<br>
콜라츠 추측 - 연습문제  
num이 1인 경우도 있다. 

```cpp
int solution(int num) {
    int answer = 0;
    int cnt = 0;
    
    if(num==1) return cnt;
    while (cnt++) {
        if (cnt <= 500) {
            if (num % 2 == 0) {
                num /= 2;
            } else if (num % 2 == 1) {
                num *= 3;
                num += 1;
            }
            if(num==1) return cnt;
        } else {
            return -1;
        }
    }
}
```  
<br>
자연수 뒤집어 배열로 만들기 - 연습문제  
10으로 나눌때 나머지 넣고  
그 나머지 빼고  
또 10으로 나누기를 반복  
**string rnum = to_string(n);** 이것도 가능  

```cpp
vector<int> solution(long long n) {
    vector<int> answer;
    while(n>0){
        int tmp = n%10;
        answer.push_back(tmp);
        n-=(tmp);
        n/=10;
    }
    return answer;
}
```