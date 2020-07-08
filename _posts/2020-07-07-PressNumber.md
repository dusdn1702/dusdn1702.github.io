---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 키패드 누르기"
permalink: /algorithms/33


categoriem:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-07-07
---
키패드 누르기 - 2020 카카오 인턴  
<https://programmers.co.kr/learn/courses/30/lessons/67256>  
인턴 코테에서 봤던 문제  
한시간 걸렸던 것 같은데 함수 잘 나누고 명명도 이쁘게 한 것 같다.  
이렇게 풀도록 하자. 좀 더 빠르게.  

<br>
```cpp
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

string answer = "";
queue<char> lefthand;
queue<char> righthand;

int map[4][3]={{1,2,3},{4,5,6},{7,8,9},{11,0,12}}; //번호판

pair<int,int> findmap(int wanttoknow){
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            if(wanttoknow==map[i][j]){
                return make_pair(i,j);
            }
        }
    }
}
void left(int P){
    lefthand.push(P);
    answer.append("L");
   // cout<<"좌";
}
void right(int P){
    righthand.push(P);
    answer.append("R");
  //  cout<<"우";
}
void findhand(char L, char R, int P, string H){
    pair<int, int> whereisL = findmap(L);
    pair<int, int> whereisR = findmap(R);
    pair<int,int> moveto = findmap(P);
    int LtoP = abs(moveto.first-whereisL.first)+abs(moveto.second-whereisL.second);
    int RtoP = abs(moveto.first-whereisR.first)+abs(moveto.second-whereisR.second);
    if(LtoP<RtoP){
        left(P);
    }
    else if(LtoP>RtoP){
        right(P);
    }
    else{
        if(H=="right"){
            right(P);
        }
        else if(H=="left"){
            left(P);
        }
    }
}
string solution(vector<int> numbers, string hand) {
    lefthand.push(11);
    righthand.push(12);
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]==1 || numbers[i]==4 || numbers[i]== 7){
            left(numbers[i]);
        }
        else if(numbers[i]==3 || numbers[i]==6 || numbers[i]== 9){
            right(numbers[i]);
        }
        else if(numbers[i]==2 || numbers[i]==5 || numbers[i]== 8 || numbers[i]==0){
            findhand(lefthand.back(), righthand.back(), numbers[i], hand);
        }
    }
    return answer;
}
```
소요시간 ; 1시간 