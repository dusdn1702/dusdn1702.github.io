---
title: "코딩테스트 대비"
excerpt: "python coding test"
permalink: /study/15
categories:
  - study
  - python
tags:
  - study
  - python
  - coding test
  
last_modified_at: 2020-09-28
--- 
# 파이썬 기초 문법
## 자료형
- 정수형  
- 실수형  
무한대 : 1e9  
round(a, b) : a의 b+1번째 자리에서 반올림, 인자 없이 round(a) 하면 소수 첫째 자리에서 반올림  
사칙연산 : + - * / //(몫만)  
- 리스트 자료형  
[-1] : 제일 마지막 원소  
슬라이싱 : a[1:4] 0이 첫번째니까 두번째부터 4-1인 네번째 원소까지  
컴프리헨션 : array = [i for i in range(20) if i % 2 == 1] [i*i for i in range(1, 10)]  
append() : O(1), 원소 하나 삽입  
sort() : O(NlogN), DEFAULT=오름차순  
reverse() : O(N)  
insert(1, 'a') : O(N), 특정한 위치에 원소 삽입  
count() : O(N)  
remove() : O(N)  
[]로 선언   
- 튜플 자료형  
튜플은 한 번 선언된 값을 변경할 수 없다.  
표시는 ()로 한다.  
- 사전 자료형  
key 와 value의 쌍을 데이터로 가지는 자료형  
hash table 사용해 O(1)의 시간, 리스트보다 훨씬 빠르다.  
if 원소 in 사전: 으로 검색 가능  
dict.keys()나 dict.values() 로 키와 밸류 값들을 리스트로 뺄 수 있다.  
data = dict()로 선언, data['a']='b'로 키값 삽입  
- 집합 자료형  
중복이 없고 순서가 없다.  O(1)  
합집합 |, 차집합 -, 교집합 &을 사용할 수 있다.  
add(4)로 원소 추가, update([4, 5])로 여러 개 한꺼번에 추가, remove(4)로 원소 제거  
set([1,2,3]), {}으로 초기화

## 조건문  
if, elif, else: 로 표현, pass로 일단 넘기기도 가능  
비교 연산자 : ==, !=, >, <, >=, <=  
논리 연산자 : and, or, not의 소문자로 표현  
in과 not in 연산자 : 리스트와 문자열에 모두 사용가능  
"success" if a in b else "fail" 로 표현 가능  
"0<a<20"과 "0<x and x<20" 둘다 가능  

## 반복문  
while문 : while i<= 9:  
for문 : for a in list:, for i in range(1, 10): 하면 1부터 9까지!  

## 함수  
def name(parameter):  
        소스코드  
        return 값  
로 함수 정의 가능  
다른 함수에서 함수 내 변수 쓸려면 global로 선언 가능 : global a  
람다 표현식 사용 : (lambda a, b: a+b)(3, 7)  

## 입출력  
map(int, input().split())으로 띄어쓰기로 받은 숫자들 입력 가능  
list(map(int, input().split()))으로 리스트로도 입력 가능  
sys.stdin.readline().rstrip() 으로 한줄 입력 받기 가능  
출력시 str()로 캐스팅해 출력  
print("~~")  

## 라이브러리  
### 내장함수  
input(), print()  
sum() : iterable 객체 모든 원소의 합  
min(), max() : 두 개 이상의 파라미터 들어왔을 때 min/max 반환  
eval("3*7") : 결과 값 반환  
sorted() : 오름차순 정렬  

### itertools  
permutations : n개에서 r개 뽑아 일렬로 나열하는 모든 경우 (순열)  from itertools import permutations  
ex result = list(permutations(data, 3)) (데이터를 세개씩 골라서 리스트로)  
combinations : n개에서 r개 뽑아 순서를 고려하지 않고 나열하는 모든 경우 (조합) from itertools import combinations  
ex list(combinations(data, 3))  
product : n개에서 r개 뽑아 일렬로 나열하는데 중복을 허용하는 모든 경우 (순열) 뽑고자 하는 데이터 수를 repeat 속성값으로 넣어줌  
ex list(product(data, repeat=2)) 2개 뽑는 모든 경우  
combinations_with_replacement : n개에서 r개 뽑아 순서 고려하지 않고 중복을 허용하는 모든 경우 (조합) from itertools import combinations_with_replacement  
ex list(combinations_with_replacement(data, 2))

### heapq  
시간복잡도 O(NlogN)로 PriorityQueue 라이브러리보다 빠름  
h=[]으로 선언하고 heapq.heappush(h, value)의 방식으로 삽입  
import heapq  
삽입 heapq.heappush(), 삭제 heapq.heappop(),  
최대 힙 만드는 법 : 부호 반대로 하기          
```python
        //기본 힙
        for value in iterable:
            heapq.heappush(h, value)
        //최대 힙
        for value in iterable:
            heapq.heappush(h, -value)
```  

### bisect  
이진탐색을 구현, 시간복잡도 O(logN)  
from bisect import bisect_right, bisect_left  
bisect_left(a, x) : 리스트 a에 데이터 x를 삽입할 가장 왼쪽 인덱스를 반환  
bisect_right(a, x) : 리스트 a에 데이터 x를 삽입할 가장 오른쪽 인덱스 반환  
사이에 있는 데이터 개수 세는데 유용  
```python
    def count_by_range(a, left, right):
        right_index = bisect_right(a, right) //리스트 a에 데이터 right를 삽입할 가장 오른쪽 인덱스 나옴
        left_index = bisect_left(a, left) //리스트 a에 데이터 left를 삽입할 가장 왼쪽 인덱스 나옴
        return right_index - left_index
    a = [1, 2, 3, 4, 4, 4, 5, 6]  
    print(count_by_range(a, 4, 4)) //값 4인 데이터 개수 출력  
```  

### collections  
#### deque  
queue 라이브러리가 있지만 우리가 아는 형식은 아니다-> 그냥 list 자료형의 append(), pop()이 뒤에 넣고 뺌
시간복잡도 O(1) from collections import deque로 list보다 빠름
인덱싱, 슬라이싱 안됨  
가장 뒤 원소 삽입 append(), 가장 뒤 원소 삭제 pop(), 가장 앞 원소 추가 appendleft(), 가장 앞 원소 삭제 popleft()  

#### counter  
원소 개수 반환 from collections import Counter  
```python  
    counter = Counter(['1', '2', '3', '4', '4'])
    print(counter['4']) //4 개수 출력
    print(dict(counter))하면 사전 자료형으로 변환
```  

### math  
import math  

#### factorial  
팩토리얼 계산 print(math.factorial(5))  

#### sqrt  
제곱근을 소수점까지 계산해 반환 print(math.sqrt(7))  

#### gcd  
최대 공약수 계산 print(math.gcd(21, 14))  

#### 기타 
파이 print(math.pi)  
e print(math.e)  