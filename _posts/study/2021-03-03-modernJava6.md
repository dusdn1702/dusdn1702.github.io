---
title: "독서 정리 - 모던 자바 인 액션"
excerpt: "6장"
permalink: /study/23
categories:
  - study
  - java
tags:
  - study
  - java
  
last_modified_at: 2021-03-03
---  
# 모던 자바 인 액션

## [6장] 스트림으로 데이터 수집  
중간 연산은 스트림의 요소를 소비하지 않고 최종 연산은 스트림의 요소를 소비해서 최종 결과를 도출한다.  
<br>

### 6.1 컬렉터란 무엇인가?  
명령형 프로그래밍: 다중 루프와 조건문의 추가로 가독성과 유지보수성이 크게 떨어진다.
함수형 프로그래밍: 원하는 것을 직접 명시할 수 있어서 방법은 중요하지 않다.  
특수한 자료형으로 만들기: `toList, toSet, toCollection`  

1. 컬렉터는 내부적으로 리듀싱 연산이 일어난다.  
Collector 유틸리티 클래스는 자주 사용하는 컬렉터 인스턴스를 손쉽게 생성할 수 있는 정적 팩토리 메서드를 제공한다. Collector 인터페이스의 메서드를 어떻게 구현하느냐에 따라 스트림에 어떤 리듀싱 연산을 수행할지 결정한다.  
2. 미리 정의된 컬렉터  
Collectors에서 제공하는 메서드의 기능은 **스트림 요소를 하나의 값으로 리듀스하고 요약, 요소 그룹화, 요소 분할**이 있다.  
<br>

### 6.2 리듀싱과 요약  
`Collectors.counting()`에서 `count()` 메서드가 더 유리한 메서드인 것처럼 Collectors는 다른 컬렉터와 함께 사용할 때 위력을 발휘한다.  
1. 스트림값에서 최댓값과 최솟값 검색  
`Collectors.maxBy`와 `Collectors.minBy`가 있다.  
이들은 인자로 Comparator`Comoparator.comparingInt(Dish::getCalories)`를 받는다.  
2. 요약 연산  
`Collectors.summingInt`는 객체를 int로 매핑한 컬렉터를 반환한다. 이 메서드는 스트림의 요소들을 탐색하면서 각 칼로리를 더해가면서 총합을 반환한다.  
`summingLong`, `summingDouble`도 있다.  
평균 계산으로 `averagingInt`, `averagingLong`, `averagingDouble`도 존재한다.  
요소 수, 총합, 평균, 최대, 최소를 전부 계산하는 `summarizingInt`, `summarizingLong`, `summarizingDouble`도 있다.  
3. 문자열 연결  
joining 메서드를 잉요해 문자열을 하나로 연결해서 반환할 수 있다.  
`collect(joining())`이나 `collect(joining(","))`와 같이 사용한다.  
4. 범용 리듀싱 요약 연산  
제시된 모든 컬렉터를 reducing으로도 정의할 수 있다.  
세 개의 인수를 가진 경우: 첫 인수는 리듀싱 연산의 시작값이거나 반환갑사, 두번째 인수는 변환 함수, 세번째 인수는 BinaryOperator  
reduce 연산에서는 병렬성이 확보되지 않고 불변형 연산이라는 점에 의미가 퇴색되어 이런 연산은 collect 연산이 장려된다.  
컬렉션을 이용해 같은 연산도 다양한 방법으로 구현할 수 있다.  
- 퀴즈 6-1: 리듀싱으로 문자열 연결 `String shortMenu = menu.stream().reducing("", Dish::getName, (s1, s2) -> s1 + s2))`, `String shortMenu = menu.stream().map(Dish::getName).reducing((s1, s2) -> s1 + s2)).get()`  
<br>

### 6.3 그룹화  
Collectors.groupingBy를 이용해 쉽게 메뉴를 그룹화할 수 있다. 분류 함수라고도 부른다. 첫번째 인자에는 요소들이, 두번째 인자에는 기준이 들어간다.  
1. 그룹화된 요소 조작  
`collect(groupingBy(Dish::getType, filtering(dish -> dish.getCalories() > 500, toList())))`와 같이 분류할 수 있다.  
filtering처럼 mapping을 사용할 수 있고, 간단한 추출을 위해 flatMapping도 사용할 수 있다.  
2. 다수준 그룹화  
`Collecteors.groupingBy`로 조합을 할 수 있다. 일반적인 분류 함수와 컬렉터를 인수로 받는다. 인자로 groupingBy를 다시 해주면 두 수준의 맵을 얻을 수 있다.  
3. 서브그룹으로 데이터 수집  
두번째 인자에는 제한이 없기 때문에 원하는 기준으로 원하는 형을 만들어낼 수 있다.  
`Collectors.collectingAndThen`을 이용하면 얻어낸 결과를 원하는 형식으로 바꿀 수 있다.  
```java
Map<Dish.Type, Dish> mostCalories = menu.stream()
        .collect(groupingby(Dish::getType, 
            collectingAndTen(maxBy(comparingInt(Dish::getCalories)), Optional::get)));
```  
<br>  

### 6.4 분할  
분할함수는 boolean을 반환하는 Predicate을 이용해 분할하는 것이다.  
`menu.stream().collect(partitioningBy(Dish::isVegeterian))`에서 `partitioningBy`를 의미한다.  
이를 통해 true인 값과, false인 값으로 나눠서 생성된다.  

1. 분할의 장점  
거짓과 참의 요소들을 모두 얻을 수 있다는 장점이 있다.  
- 퀴즈 6-2: partitioningBy 사용 - partitioningBy의 첫번째 인자는 boolean을 얻을 값, 두번째 인자로는 모을 값이 필요하다.  
2. 숫자를 소수와 비소수로 분할하기  
`isPrime()` 메서드를 구현해 소수와 비소수로 나눌 수 있다.  
```java
public boolean isPrime(int value) {
    return IntStream.range(2, value).noneMatch(i -> value % i == 0);
}
```  
<br>

### 6.5 Collector 인터페이스  
```java
public interface Collector<T, A, R> {
    Supplier<A> supplier();
    BiConsumer<A, T> accumulator();
    Funcion<A, R> finisher();
    BinaryOperator<A> combiner();
    Set<Characteristics> characteristics();
}
```  
T는 수집될 스트림의 제네릭, A는 누적할 객체의 형식, R은 반환할 형식  
1. Collecotr 인터페이스의 메서드 살펴보기  
- supplier: 새로운 결과 컨테이너 만들기(수집)  
- accumulator: 결과 컨테이너에 요소 추가하기(리듀싱 연산 수행 함수 반환)  
- finisher: 최종 변환값을 결과 컨테이너로 적용하기(최종 결과 호출 함수 반환)  
- combiner: 두 결과 컨테이너 병합(리듀싱 연산에서 사용할 함수 반환)  
- Characteristics: UNOREDERED(순서 무관), CONCURRENT(병렬 리듀싱 수행), IDENTITY_FINISH(형변환)  
2. 응용  
- 컬렉터 구현 없이 커스텀 수집 만들기  
`List<Dish> dishes = menuStream.collect(ArrayList::new, List::add, List::addAll);`와 같이 스트림은 발행, 누적, 합침을 인수로 받는 collect를 사용하므로 컬렉터 없이 구현할 수 있다.  
<br>  

### 6.6 커스텀 컬렉터를 구현해서 성능 개선하기  
1. 소수로만 나누기  
    1. Collector 클래스 시그니처 정의  
    2. 리듀싱 연산 구현  
    3. 병렬 실행할 수 있는 컬렉터 만들기  
    4. finisher, characteristics  
2. 성능 비교  
결과적으로 커스텀 클래스의 성능이 더 향상된다.  
Collector 인터페이스를 구현하는 새로운 클래스는 가독성과 재사용성이 떨어지므로 필요 없다.  
