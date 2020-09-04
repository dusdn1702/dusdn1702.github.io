---
title: "파이썬 알고리즘 공부"
excerpt: "python 공부"
permalink: /study/6

categories:
  - study
tags:
  - study

last_modified_at: 2020-09-01
---
## 20/08/04
- 리스트에서 -1은 제일 뒷 요소를 가리킨다.  
- range(2, -1, -1)이라면 2부터 -1(마지막)까지 -1씩 거꾸로 가는 경우이다.  

## 20/08/05
- for _ in range(int) : int 만큼 돈다  
- for i in range(len(list)) : list 길이만큼 하나씩  
- else if의 표기는 elif  
- {}사이에 글자 출력, %숫자 하면 숫자 출력 두개씩 해야 각자 기호 출력 가능
- for i in str: 하면 문자열 하나하나 차례로 돌아간다  
- python의 모든 정수는 크기 상관 없이 int  
- list.sort()는 오름차순 1,2,3,4
- list.sort(reverse=True)는 내림차순 4,3,2,1
- list.reverser()는 list를 거꾸로
- list.sort(key=len)은 길이순으로 정렬

## 20/08/06
- %s 문자열, %c 문자1개, %d 정수, %f 부동소수, %o 8진수, %x 16진수

## 20/08/07
- set 자료형의 특징을 사용하면 list의 중복을 제거할 수 있다.
  1. 중복을 허용하지 않는다.
  2. 순서가 없다.
- 형변환은 abc = set(wasList)
- max(a,b,c)면 a,b,c 중 최대
- list.count(요소) 하면 요소의 개수 나옴
- list의 생성은 [a,b,c]

## 20/08/09
- 딕셔너리 자료형 ; LIST = {'HI':11, 'HELLO':10} 등의 Key, Value으로 map 생성
- 문자열[::-1] 하면 그 문자열 거꾸로 

## 20/08/11
- 문자열 포맷팅 여러개 한 경우 괄호로 묶어서 전달 print("one is %d\n two is %d", %(1,2))
- ' + '.join(map(str, numbers)) 하면 numbers 요소 사이사이에 +가 쪼인된다
- lambda 인자 : 표현식 ex lambda x:x[1] 하면 x가 1번째 요소가 됨
- sorted(list, key = lambda x:x[1])의미는 list의 1번째 요소로 오름차순 sort
- print(list[-1][0])은 제일 큰거의 0번째 요소 출력

## 20/08/14
- 제곱: x**y 하면 x의 y제곱

## 20/08/15
- import math 하면 쓸 수 있는 함수
    math.ceil(수): 올림  
    math.fabs(수): 절댓값  
    math.factorial(수): 팩토리얼 함수  
    math.floor(수): 내림(-3.14면 -4)
    math.trunc(수): 내림(-3.14면 -3)  
    math.gcd(1, 4): 최대공약수  
    math.modf(수): 정수와 소수 분리해 반환  
    math.pow(3,2): 3^2  
    \*math.sqrt(수): 제곱근 반환\*
    math.각삼각함수

## 20/08/27
- True/False임..  
- 집합은 set인데 a=set()하거나 set([1,2,3])과 같이 list 선언하고 들어가야 한다! 집합에는 중복x  
- {}는 사전형! 사전형은 map이당  
- []가 리스트!  
    list(map(''.join, permutations(list(numbers), j)) number를 list로 보고 각 숫자 j개를 순열해서 list로 넣는 것  
    이미 list인 경우는 list(map(''.join, permutations(list, j))이고, 개수 전부 하고 싶으면 permutations(list) 해도 된다.  
    순열은 순서 상관 있는거고 combination 쓰면 list(map(''.join, combination(list j)) 순서 상관 없는 조합도 나타낼 수 있다.  
    import itertools 해주어야 한다.  
- map은 map(int, input().split())처럼 나누고 할당한다고 생각하면 된다.  
- join은 리스트에서 문자열로  
- slice는 [1:10] 1은 포함, 10은 비포함  
- step은 [1:5:2] 1에서 4까지 2씩 띄워서 list로

## 20/08/30
- 딕셔너리 자료형 {}, key:value 로 구성  
- 딕셔너리 등록 a = {1:'a', 'b':'c', 'name'=[1,2,3,hi]}로 가능  
- dictionary.keys() 하면 key들이 리스트로  
- 입력 요소가 []안에 들어있을 때는 안에 있는 걸 리스트로 보고 element[0], element[1] 등으로 사용하면 된다.  

## 20/09/01
- \*\*enumerate\*\* 인덱스 번호와 항목 연결 for p in enumerate([1,2,3,4]): 하면 (0,1)(1,2)(2,3)(3,4)가 됨  
- \*\*zip\*\* 동일한 개수의 두 자료형을 묶어줌  
list로 만들 경우 ; numbername=list(zip(number,name))  
dictionary로 만들 경우 ; for number, name in zip(number, name): dic[number]=name  
- defaultdict(list)로 할 경우 기본값 list로 정의되어 비어있어도 에러 안남
- lambda식 사용법 ; lambda a, b: a+b 로 매개변수 a,b: 표현식a+b
- 리스트 확장 alist.extend(blist) 하면 alist에 blist를 더하도록
- insert는 (자리, 넣을 값)
- append는 요소 추가
- pop은 마지막 요소 삭제
- del a[1]은 a의 1번째 요소 삭제
- \*\*collections.Counter()\*\* dictionary 같은 hash형 자료들의 값 개수 셀 때 사용!! 객체들간 연산도 가능 => import collections 필요  

## 20/09/04
- deque() 사용 - pop(), popleft() 추가할 땐 append(2)
- stack() 사용 - pop(), appen(1)
- for문의 range(a,b) 하면 a 포함 b 미포함