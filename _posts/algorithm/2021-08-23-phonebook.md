---
title: "알고리즘 풀이"
excerpt: "프로그래머스 전하번호 목록"
permalink: /algorithms/64

categories:
  - algorithms
tags:
  - algorithms
  - python

---
## 문제 설명
다른 전화번호를 포함하고 있는 전화번호가 있으면 false, 있으면 true를 반환하라.

## 1차
정확성 일부, 시간초과 발생,
해시 문제니까 해시를 사용해보자.
```py
def solution(phone_book):
    for i in range(0, len(phone_book) - 1):
        for j in range(i+1, len(phone_book)):
            if phone_book[i] in phone_book[j] or phone_book[j] in phone_book[i]:
                return False
    return True
```

## 2차
해시 사용법을 도저히 모르겠다.  
정렬하면 적어도 접두어에 포함하고 있는 것들끼리 붙어있을거고, i부터 돌면서 가장 작은 걸로(i 길이로) i+1을 슬라이싱해서 접두어 같은지 확인했다.  

```py
def solution(phone_book):
    phone_book.sort()
    for i in range(0, len(phone_book) - 1):
        if phone_book[i] in phone_book[i+1][0:len(phone_book[i])]:
            return False
    return True
```