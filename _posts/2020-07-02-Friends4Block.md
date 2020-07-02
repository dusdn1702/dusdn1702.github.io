---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 프렌즈4블럭"
permalink: /algorithms/29

categoriem:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-07-02
---
프렌즈4블록 - 카카오 2018  
<https://programmers.co.kr/learn/courses/30/lessons/17679>  
2*2로 같은 거 뭉쳐있으면 터뜨리고 아래로 내리는 것  
vector<string>으로 주어졌을 때  
vector<vector<bool>>로 선언할 수 있고, (m,vector<bool>(n))으로 크기 조정 가능  
다 돌아도 없으면 while문 끝내는 finish 필요  
한 텀에 한세트씩 터뜨림  
<br>
```cpp
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool finish = true;
    while (finish) {
        vector<vector<bool>> check(m, vector<bool>(n));
        finish = false;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (board[i][j] == -1) continue;
                    if ((board[i][j] == board[i + 1][j]) && (board[i + 1][j] == board[i + 1][j + 1]) && (board[i + 1][j + 1] == board[i][j + 1])) {
                        check[i][j] = true;
                        check[i][j + 1] = true;
                        check[i + 1][j] = true;
                        check[i + 1][j + 1] = true;
                        finish = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (check[i][j]) {
                    answer++;
                    for (int k = i - 1; k >= 0; k--) {
                        board[k + 1][j] = board[k][j];
                        board[k][j] = -1;
                    }
                }
            }
        }
    }
    return answer;
}
```
소요시간 ; 1시간
혼자 다시 풀기!!