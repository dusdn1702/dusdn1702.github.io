---
title: "독서 정리 - 모던 자바 인 액션"
excerpt: "5장"
permalink: /study/22
categories:
  - study
  - java
tags:
  - study
  - java
  
last_modified_at: 2021-03-01
---  
# 모던 자바 인 액션

## [5장] 스트림 활용  
스트림 API는 내부적으로 코드를 병렬로 실행할지, 데이터를 어떻게 처리할지, 내부 반복을 할지 등의 다양한 최적화를 실시한다.  
<br>

### 5.1 필터링  
1. Predicate로 필터링  
filter 메서드는 boolean을 반환하는 Predicate를 인수로 받아 true 요소들을 반환한다.  
```java
List<Integer> ex = new ArrayList<>(1, 2, 11, 12);
ex.stream().filter(i -> i > 10).collect(Collectors.toList());
```  
2. 고유 요소 필터링  
distinct 메서드는 스트림 내에 중복되는 요소를 필터링한다.  
이 때 일치하는 요소는 equals, hashcode로 일치하는 것이다.  
```java
List<Integer> ex = new ArrayList<>(1, 2, 12, 12);
ex.stream().distinct().collect(toList()); //1, 2, 12  
```  
<br>  

### 5.2 스트림 슬라이싱  
1. Predicate로 슬라이싱  
- TAKEWHILE  
일반 스트림은 각 요소에 Predicate를 적용하지만, takewhile 메서드를 사용하여 모든 스트림에 Predicate를 적용한다.  
```java
List<Integer> ex = new ArrayList<>(1, 2, 11, 12);
ex.stream().takewhile(i -> i > 10).collect(toList()); //1, 2
```  
- DROPWHILE  
true가 아닌 false 요소들을 선택하려면 dropwhile을 사용한다.  
```java
List<Integer> ex = new ArrayList<>(1, 2, 11, 12);
ex.stream().dropwhile(i -> i > 10).collect(toList()); //11, 12 
```  
2. 스트림 축소  
limit 메서드를 사용하면 스트림의 갯수를 제한해서 돌려준다.  
정렬되어 있는 스트림이라면 그 순서대로, 정렬되지 않은 스트림도 그 순선대로 잘라서 반환된다.  
```java
List<Integer> ex = new ArrayList<>(1, 2, 11, 12);
ex.stream().limit(2).collect(toList()); // 1, 2
```  
3. 요소 건너뛰기  
skip 메서드는 스트림의 결과를 입력받은 개수만큼 건너뛰고 반환한다.  
```java
List<Integer> ex = new ArrayList<>(1, 2, 11, 12);
ex.stream().takewhile(i -> i > 10).skip(1).collect(toList()); //12
```  
<br>  

### 5.3 매핑  
1. 스트림의 각 요소에 함수 적용하기  
map 메서드는 각 요소의 형식을 입력받은 함수에 맞게 변환해주는 역할을 한다.  
```java
List<Integer> ex = new ArrayList<>(1, 2, 12, 12);
ex.stream().map(String::toString).collect(toList()); //"1", "2", 11", "12";
```  
2. 스트림 평면화  
"hello"와 "world"라는 문자열을 가진 리스트를 각 문자로 분리하고, 고유 문자만 뽑아내고자 한다.  
```java
List<String> words = new ArrayList<>("hello", "world");
words.stream().map(w -> w.split("")).distinct().collect(toList());
```  
위 메서드는 hello와 world로 나누어져 각각 분리하기 때문에 중복된 `o`를 걸러내지 못한다.  
```java
words.stream().map(w -> w.split("").map(Arrays::stream).distict().collect(toList()));
```
`Arrays.stream`메서드는 문자열 스트림을 만들었지만, 여전히 hello와 world가 따로 스트림으로 생성된다. 이 때 flatMap을 사용한다.  
```java
words.stream().map(w -> w.split("").flatMap(Arrays::stream).distinct().collect(toList()));
```  
이 때 첫번째 map에서는 각 단어의 개별 문자로 스트림을, flapMap에서는 각 스트림을 하나의 스트림으로 평면화하는 작업이다.  
순서는 함수를 적용해 각 스트림을 만든 다음 각 스트림을 하나의 스트림으로 만드는 것이다.  
- 퀴즈 5-2  
숫자 리스트가 주어졌을 때 제곱근의 리스트로 반환한다.  
```java
List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5);
numbers.stream().map(i -> i * i).collect(toList());
```  
두 개의 숫자 리스트가 있을 때 숫자 쌍의 리스트를 반환한다.  
```java
List<Integer> numbers1 = Arrays.asList(1, 2, 3, 4, 5);
List<Integer> numbers2 = Arrays.asList(6, 7, 8, 9, 10);
List<int[]> pairs = numbers1.stream().map(i -> numbers2.stream().map(j -> new int[]{i, j})).collect(toList());
```  
반환된 숫자 쌍의 리스트에서 합이 3으로 나누어 떨어지는 쌍만 반환한다.  
```java
pairs.stream().filter(i -> (i[0] + i[1]) / 3 == 0).collect(toList());
```  
```java
List<int[]> pairs = numbers1.stream().flatMap(i -> numbers2.stream().filter(j -> (i + j)).map(j -> new int[]{i, j});
```  
<br>  

### 5.4 검색과 매칭  
1. Predicate가 적어도 한 요소라도 일치하면 true  
AnyMatch 메서드를 사용하면 적어도 한 요소가 일치하면 True를 반환한다.  
AnyMatch 메서드는 boolean은 반환하므로 최종 연산이다.  
```java
List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 10);
numbers.stream().anyMatch(i -> i > 5); //true 
```  
2. 모든 요소와 일치하는지 확인  
AllMatch 메서드를 이용해 모든 요소가 일치하면 true를 반환한다.  
```java
List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 10);
numbers.stream().allMatch(i -> i > 0); //true 
```  
noneMatch 메서드는 모든 요소가 일치하지 않으면 true를 반환한다.  
```java
List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 10);
numbers.stream().noneMatch(i -> i < 0); //true 
```  
match 메서드는 스트림 쇼트서킷 기법인 && ||와 같은 연산을 사용한다.  
`쇼트서킷`이란 스트림을 돌다가 적어도 하나가 다르다면 전부 돌지 않고 false를 반환하는 것이다. limit도 그러하다.  
3. 요소 검색  
findAny는 스트림에서 임의의 요소를 반환한다.  
- Optional이란?  
값의 존재나 부재 여부를 표현하는 컨테이너 클래스이다. 예를 들어 null을 반환하더라도 괜찮도록 Optional을 사용하는 것이다.  
    - isPresent() 는 값이 있으면 true
    - ifPresent(Consumer<T> c)는 값이 있으면 consumer 함수를 실행  
    - T get()은 값이 존재하면 값을, 없으면 NoSuchElementException 발생  
    - T orElse()는 값이 있으면 값을, 없으면 기본값을 반환  

4. 첫번째 요소 찾기  
findFirst 메서드는 순서가 정해진 스트림에서 가장 첫번째 값을 반환한다.  
- findAny vs findFirst: 병렬 실행에서는 첫번째 요소를 찾기 힘드므로 요소의 순서가 상관 없다면 병렬 스트림에서는 findAny 사용  
<br>  

### 5.5 리듀싱  
모든 스트림 연산을 처리해서 값으로 도출하는 것을 `리듀싱 연산`이라고 한다.  
1. 요소의 합  
reduce 메서드는 반복된 패턴을 추상화해서 모든 요소를 더할 수 있다.  
reduce는 초깃값과 두 요소를 조합해서 새로운 값을 만드는 BinaryOperator를 받는다.  
초깃값을 입력하지 않으면 오버라이딩된 함수를 이용해서 입력된 함수만 실행한다. 하지만 초기값이 없으면 값을 더하지 못한다.  
```java
List<Integer> numbers = Arrays.asList(1, 2, 3);
numbers.stream().reduce(0, (a, b) -> a + b); //6
numbers.stream().reduce(0, Integer::sum); //6
```  
2. 최댓값과 최솟값  
초깃값을 주지 않는 reduce 메서드는 다음과 같이 활용한다.  
```java
numbers.stream().reduce(Integer::max); //3
```  
- reduce 연산은 내부 반복이 추상화되어 병렬화가 어렵다. 병렬로 실행하려면 변수값이 변하지 않고 연산의 최종값이 일정해야 한다.  
- stream은 각 연산의 내부적인 상태를 고려해야 한다. map, filter는 내부 상태를 갖지 않는 연산이지만, reduce, max, sum과 같은 연산은 내부 상태가 필요하다. 이 값은 한정되어 **모든 요소가 버퍼에 추가되어 있어야 한다**  
<br>

### 5.6 실전 연습  
- 알파벳 순 정렬  
`.sorted().reduce("", (n1, n2) -> n1 + n2);` 문자열로 만들기  
<br>

### 5.7 숫자형 스트림 
박싱 비용을 줄이기 위해 숫자 스트림을 효율적으로 처리할 수 있는 **기본형 특화 스트림**이 있다.  
1. 기본형 특화 스트림  
숫자 스트림 매핑: IntStream, DoubleStream, LongStream  
객체 스트림 복원: `boxed` 메서드 사용  
기본값: OptionalInt, OptionalDouble, OptionalLong을 사용해 최댓값이 없을 때 기본값을 명시적으로 정의할 수 있다.  
```java
OptionalInt hi = Arrays.asList("1", "2", "3").stream().mapToInt(Integer::parseInt).max();
int max = hi.orElse(2);
```  
2. 숫자 범위  
IntStream과 LongStream에서는 range, rangeClosed로 숫자스트림을 만들 수 있다.  
```java
IntStream i = IntStream.rangeClosed(1, 100); // 1부터 100  
```  
3. 피타고라스  
<br>

### 5.8 스트림 만들기  
1. 값으로 스트림 만들기  
```java
Stream.of(~~);
Stream.empty(); //스트림 비우기  
```  
2. null이 될 수 있는 객체로 스트림 만들기  
```java
Stream.ofNullable(~~);
```  
3. 배열로 스트림 만들기  
```java
Arrays.stream(~~).sum();
```  
4. 파일로 스트림 만들기  
```java
long unique = 1;
 try(Stream<String> lines = Files.lines(Paths.get("data.txt"), Charset.defaultCharset())) {
     unique = lines.flatMap(line -> Arrays.stream(line.split(" "))).distinct().count();
 } catch(IOException e){

 }
```  
5. 함수로 무한 스트림 만들기  
크기가 고정되지 않은 스트림을 만들어 요청할 때마다 무제한으로 값을 계산하도록 한다. 무제한이지 않도록 limit으로 제한을 준다.  
- limit 메서드  
```java
Stream.iterate(0, n -> n + 2)
    .limit(10)  //이거 없으면 언바운드 스트림 생성
    .forEach(System.out::println);
```  
- 퀴즈 5-4 피보나치 수열  
```java
Stream.iterate(new int[]{0, 1}, t -> new int[]{t[1], t[0] + t[1]})
    .limit(20)
    .forEach(t -> System.out.println(t[0] + t[1]));
```  
- generate 메서드  
```java
Stream.generate(Math::random)
    .limit(5)
    .forEach(System.out::println);
```  
병렬 코드에서는 발행자에 상태가 있으면 안전하지 않다.  
iterate를 사용할 때는 상태가 바뀌지 않는 순수한 불변 상태가 유지되어야 한다.  