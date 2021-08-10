---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 방금 그곡"
permalink: /algorithms/30

categories:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-07-05
---
방금 그곡 - 2018 카카오  
<https://programmers.co.kr/learn/courses/30/lessons/17683>  
아 어떻게 풀지는 알겠는데 인간적으로 너무 길다..  
진짜 심심할때 다시 할게요..  
나누는 부분과 시간계산 부분을 좀 더 효율적인 방법으로 해보자  
음계 #들어가는 것도 구분해야한다.

```cpp
#include <string>
#include <vector>
#define TIME 5
using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<string> tmpMusic;
    vector<pair<int, pair<string, string>>> Musics;
    for (int i = 0; i < musicinfos.size(); i++) {
        string tmp = "";
        for (int j = 0; j < musicinfos[i].size(); j++) {
            if (musicinfos[i][j] != ',') {
                tmp += musicinfos[i][j];
            } else {
                tmpMusic.push_back(tmp);
                tmp.clear();
            }
        }
    }
    pair<int, int> start;
    pair<int, int> end;
    string tmpnum = "";
    tmpnum = tmpMusic[0][0] + tmpMusic[0][1];
    int startHour = atoi(tmp.c_str());
    start.first = startHour;
    tmpnum.clear();
    tmpnum = tmpMusic[0][3] + tmpMusic[0][4];
    int startMinute = atoi(tmp.c_str());
    start.second = startMinute;
    tmpnum.clear();

    tmpnum = tmpMusic[1][0] + tmpMusic[1][1];
    int endHour = atoi(tmp.c_str());
    start.first = endHour;
    tmpnum.clear();
    tmpnum = tmpMusic[1][3] + tmpMusic[1][4];
    int endMin = atoi(tmp.c_str());
    start.second = endMin;
    tmpnum.clear();

    if (end.second < start.second) {
        end.first--;
        end.second += 60;
    }
    int times = (end.second - start.second) + (end.first - start.first) * 60;
    Musics.push_back(make_pair(times, make_pair(tmpMusic[2], tmpMusic[3])));

    for(int i =0;i<Musics.size();i++){
        if(Musics[i].second.second)
    }
    return answer;
}
```
소요시간; 1시간?