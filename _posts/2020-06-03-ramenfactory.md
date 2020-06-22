---
title: "알고리즘 #2"
excerpt: "프로그래머스 ; 라면공장"
permalink: /algorithms/
categories:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-03
---
```cpp
#include <string>  
#include <vector>  
#include <queue>  
  
using namespace std;  
  
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {  
			int answer = 0;  
  			int d = 0;  
  			priority_queue<int, vector<int>, less<int>> pq;  
			      
    			for(int i=0;i<k;i++){  
        			if(dates[d]==i){  
            				pq.push(supplies[d]);  
            				d++;  
        			}  
        			if(stock==0){  
            				stock = pq.top();  
            				pq.pop();  
            				answer++;  
        			}  
        			stock--;    
    			}  
    			return answer;  
		} 
```
	처음에는 priority queue 생각 못하고 막 풀려다가 실패했다..  
	그냥 queue에 넣어도 필요 없이 공급받는 경우가 생기기 때문에 주의해야 한다.  
	문제를 마구잡이로 풀지 말고 생각하고 풀자!
