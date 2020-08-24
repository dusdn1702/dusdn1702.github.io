---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 크레인 인형뽑기 게임"
permalink: /algorithms/32


categories:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-07-06
---
크레인 인형뽑기 게임 - 카카오 2019  
<https://programmers.co.kr/learn/courses/30/lessons/64061>
상당히 쉬운 문제였는데 지우는 데에서 한참 고생했다.  
erase는 (dolls.end())를 가리키면 안된다....(dolls.begin()+i)를 해야한다...  
그냥 pop_back()했으면 좋았을 것을...  
또 for문 내에서 일들이 벌어졌어야 하는데 바보같이 설계했다..  
바빴다고 하지만 그럴수록 집중해서 풀자!  
<br>
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> dolls;
    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][moves[i] - 1] != 0) {
                int tmpdoll = board[j][moves[i] - 1];
                if (!dolls.empty()) {
                    if (dolls.back() == tmpdoll) {
                        dolls.pop_back();
                        //dolls.erase(dolls.begin()+dolls.size()-1);
                        answer += 2;
                    } else {
                        dolls.push_back(tmpdoll);
                    }
                } else {
                    dolls.push_back(tmpdoll);
                }
                board[j][moves[i]-1] = 0;
                break;
            }
        }
    }
    return answer;
}
```
<br>
소요시간 ; 1시간
**시간 줄이자!!**