---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 뉴스 클러스터링"
permalink: /algorithms/

categoriem:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-07-01
---
뉴스 클러스터링 - 카카오 2018  
<https://programmers.co.kr/learn/courses/30/lessons/17677>  
생각은 단순했는데 새로 배운게 많았던 문제였다.  
- 대소문자를 가리지 않고 비교하므로 tmp[0]=toupper(tmp[0])으로 모두 대문자를 만들어준 부분  
- 소수점을 다루는 부분에서 소수 뒷자리를 버리고 계산할 때 (int)0.1-0.05 하면 앞에꺼만 int가 씌워진다는 부분  
- 계산을 할때는 캐스팅이 꼭 필요한 부분들이 있었다.  
라이브러리를 더 사용하면 더 간단히 풀 수 있었지만 지금 이거를 더 정확하고 빠르게 하는게 중요한 것 같다.  
<br>
```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> group1;
    vector<string> group2;
    string tmp = "";
    for (int i = 0; i < str1.size(); i++) {
        tmp = str1.substr(i, 2);
        tmp[0] = toupper(tmp[0]);
        tmp[1] = toupper(tmp[1]);
        if ((tmp[0] >= 'A' && tmp[0] <= 'Z') && (tmp[1] >= 'A' && tmp[1] <= 'Z')) {
            group1.push_back(tmp);
        }
        tmp.clear();
    }
    for (int i = 0; i < str2.size(); i++) {
        tmp = str2.substr(i, 2);
        tmp[0] = toupper(tmp[0]);
        tmp[1] = toupper(tmp[1]);
        if ((tmp[0] >= 'A' && tmp[0] <= 'Z') && (tmp[1] >= 'A' && tmp[1] <= 'Z')) {
            group2.push_back(tmp);
        }
        tmp.clear();
    }
    int CNTU = 0;
    int CNTN = 0;
    for (int i = 0; i < group1.size(); i++) {
        bool check = false;
        for (int j = 0; j < group2.size(); j++) {
            if (group1[i] == group2[j]) {
                CNTU++;
                CNTN++;
                group2[j]="";
                check = true;
                break;
            }
        }
        if (!check) CNTU++;
    }
    for(int i = 0; i <group2.size();i++){
            if(group2[i]!=""){
                CNTU++;
            }
    }
    float divideNum;
    if(CNTU==0&&CNTN==0) divideNum = 1;
    else{
        divideNum = (float) (CNTN / CNTU);
    }
    answer = (int)(divideNum * 65536);
    return answer;
}
```
<br>
소요시간 ; 1시간+30분