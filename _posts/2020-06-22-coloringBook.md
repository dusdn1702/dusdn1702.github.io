---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 카카오프렌즈 컬러링북"
permalink: /algorithms/

categoriem:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-22
---
카카오프렌즈 컬러링북 - 2017 카카오코드 예선  
<https://programmers.co.kr/learn/courses/30/lessons/1829>  
같은 색깔(숫자)을 bfs로 찾는 것  
함수 내에서 전역변수 초기화하라고 했으면 해야한다!!  
m,n을 solution에서 받아왔으니 받아온거 그대로 bfs에 넘겨줘야한다!!  
vector<int> v(size)l; ---> size에 벡터 크기 넣어용  
<br>
```cpp
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define maxx 100
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
bool visit[maxx][maxx];

int BFS(int m, int n, int a, int b, vector<vector<int>> map) {
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    visit[a][b] = true;
    int cnt = 1;
    int nowColor = map[a][b];

    while (!q.empty()) {
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
                if (map[nextX][nextY] == nowColor && !visit[nextX][nextY]) {
                    visit[nextX][nextY] = true;
                    q.push(make_pair(nextX, nextY));
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visit[i][j]=false;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0 && !visit[i][j]) {
                int thisColorCnt = BFS(m, n, i, j, picture);
                max_size_of_one_area = max(max_size_of_one_area, thisColorCnt);
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
```
소요시간 ; 45분
