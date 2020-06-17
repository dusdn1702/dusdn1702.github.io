---
title: "알고리즘 공부"
excerpt: "프로그래머스 ; 가장 큰 수"

categories:
  - algorithms
tags:
  - programmers
  - algorithms
last_modified_at: 2020-06-17
---
가장 큰 수 - 정렬
<https://programmers.co.kr/learn/courses/30/lessons/42746>

접근 1. vector<int>의 첫 자리수가 가장 큰게 제일 앞으로  
    - 비교하려면 string으로 바꾸어야하는데 c++에서 int를 string으로 어떻게 바꿀 수 있는지  
    - java 사용  
접근 2. string 내부 함수 append를 사용해서 6, 10이 있으면 610 106 중에 더욱 큰수를 고르도록 하자  
    - 여러가지 수를 모두 비교해서 가장 큰 걸 찾아야 하는데 어떻게 시간 내에 찾을 것인지  
<br>
접근만 하고 시간 초과

