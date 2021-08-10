---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 오픈채팅방"
permalink: /algorithms/17
categories:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-21
---
오픈채팅방 - 2019 카카오  
<https://programmers.co.kr/learn/courses/30/lessons/42888>
name에 USERID와 NICKNAME 넣어서 필요한 닉네임을 빼내도록 하였다.  
공백 분리하는 거 -> [i]에서[j]번째가 공백이면 thisString에 넣고  
아니면 tmp뒤에 붙이고  
result에는 Enter와 id 넣고  
answer에는 결과 string 넣고  
**map에는 insert 꼭 안해도 key값으로 넣고 비교해낼수 있다  
**ex) name[thisString[1]] = thisString[2];  
<br>
```cpp
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> name;
    vector<pair<string, string>> result;

    for (int i = 0; i < record.size(); i++) {
        string tmp;
        vector<string> thisString;
        for (int j = 0; j < record[i].size(); j++) {
            if (record[i][j] == ' ') {
                thisString.push_back(tmp);
                tmp.clear();
            } else
                tmp.push_back(record[i][j]);
        }
        thisString.push_back(tmp);
        if (thisString[0] == "Enter") {
            name[thisString[1]] = thisString[2];
            result.push_back(make_pair(thisString[0], thisString[1]));
        } else if (thisString[0] == "Change") {
            name[thisString[1]] = thisString[2];
        } else if (thisString[0] == "Leave") {
            result.push_back(make_pair(thisString[0], thisString[1]));
        }
    }

    for (int i = 0; i < result.size(); i++) {
        if (result[i].first == "Enter") {
            answer.push_back(name[result[i].second] + "님이 들어왔습니다.");
        } else if (result[i].first == "Leave") {
            answer.push_back(name[result[i].second] + "님이 나갔습니다.");
        }
    }
    return answer;
}
```
<br>
소요시간 ; 1시간 30분
