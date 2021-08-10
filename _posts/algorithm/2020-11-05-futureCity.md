---
title: "알고리즘 공부"
excerpt: "동빈북 ; 미래도시"
permalink: /algorithms/58

categories:
  - algorithms
tags:
  - dongbin
  - algorithms
  - python
last_modified_at: 2020-11-05
---  

#미래도시  
#최단경로 알고리즘  
#전체회사개수N 경로개수M  
#M개 줄에 연결된 두 회사 번호 입력  
#M+2번째 줄에는 X와 K가 공백으로 구분돼 차례대로 1번에서 출발해 K들렸다가 X방문  

```python
INF = int(1e9)
N, M = map(int, input().split())
graph = [[INF]*(N+1) for _ in range(N+1)]
X, K = map(int, input().split())

def Floyd_Warshall(p, q):

    for a in range(1, N+1):
        for b in range(1, N+1):
            if a == b:
                graph[a][b] = 0

    for _ in range(M):
        a, b = map(int, input().split())
        graph[a][b] = 1
        graph[b][a] = 1

    for k in range(1, N+1):
        for a in range(1, N+1):
            for b in range(1, N+1):
                graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b])
    
    if graph[p][q] == INF:
        return -1
    return graph[p][q]

print(Floyd_Warshall(X, K))
```
원래는 k를 무조건 지나가야하므로 거리를 계산해서 return 해야하지만 일단은 알고리즘 보기 편하게 이거로!  
필요한 알고리즘을 잘 쓸수 있도록 많이 플어봐야겠다~!  
소요시간 : 30분