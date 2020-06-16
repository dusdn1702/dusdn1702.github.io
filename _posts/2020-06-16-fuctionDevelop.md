---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 기능개발"

categories:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-16
---
<https://programmers.co.kr/learn/courses/30/lessons/42586>

```cpp  
//기능 개발 - 스택/큐
//걸리는 날짜를 계산해 큐에 넣고 얼마 걸리는지는 딱히 필요 없으므로
//더 적게 걸릴 경우 pop을 같이 cnt++하며 해주고
//많이 걸릴 경우 그거부터 또 찾는 방식으로 진행
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    for(int i=0;i<progresses.size();i++){
        int remains = 100 - progresses[i];
        if(remains % speeds[i] == 0) remains = remains / speeds[i];
        else remains = remains / speeds[i] + 1;
        q.push(remains);
    }
    int cnt = 1;
    int tmp = q.front();
    q.pop();
    while(!q.empty()){
        if(tmp>=q.front()){
            q.pop();
            cnt++;
        } else{
            answer.push_back(cnt);
            cnt = 1;
            tmp = q.front();
            q.pop();
        }
    }
    answer.push_back(cnt);
    return answer;
}
```
<br>
<br>
처음 pop과 front를 비교하는 위치가 헷갈려 금방 풀걸 오래 걸렸다.  
차분하게 생각하여 시간 낭비를 줄여야 겠다.
