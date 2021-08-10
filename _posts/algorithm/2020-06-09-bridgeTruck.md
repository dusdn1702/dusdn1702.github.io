---
title: "알고리즘 #3"
excerpt: "프로그래머스 ; 다리를 지나는 트럭"
permalink: /algorithms/3
categories:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-09
---
## 다리를 지나는 트럭  
트럭이 1초마다 1씩 지나고 정해진 길이를 모든 트럭이 지나는데에 걸리는 시간을 출력하는 문제 

<첫번째 시도>  
결과는 출력이 되었지만 몇몇 테스트 케이스에서 걸렸다.  
시간초과가 뜨기도 했다.  

<br>
```cpp  
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = bridge_length+1;
    int now = truck_weights[0];        
    q.push(truck_weights[0]);
    for (int j = 0; j < truck_weights.size()-1; j++) {
        now += truck_weights[j + 1];
        if (now <= weight) {
            q.push(truck_weights[j+1]);
            answer-=(bridge_length-1);
        }
        else{
            now -= truck_weights[j+1];
        }
        answer+=bridge_length;
        now -= q.front();
        q.pop();
        q.push(truck_weights[j+1]);
        now+= truck_weights[j+1];
    }
    return answer;
}
```  
<br>
<정답>  
max_size를 갱신해가면서 저장할 필요가 있었다.  
for문이 아닌 while문으로 동작하며 때에 맞는 조건문을 걸어주면 해결할 수 있었다.  
굳이 복잡하게 배열을 사용하지 않아도 된다!!  
<br>
```cpp  
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int max_size = 0;
    int size = 0;
    for(int i=0;i<truck_weights.size();i++){
        size = truck_weights[i];
        while(1){
            if(q.empty()){
                q.push(size);
                max_size+=size;
                answer++;
                break;
            } else if (q.size() == bridge_length){
                max_size-=q.front();
                q.pop();
            } else {
                if(size+max_size > weight){
                    q.push(0);
                    answer++;
                } else{
                    q.push(size);
                    max_size+= size;
                    answer++;
                    break;
                }
            }

        }
    }
    return answer + bridge_length;
}
```
