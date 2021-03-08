---
title: "독서 정리 - 모던 자바 인 액션"
excerpt: "8장"
permalink: /study/25
categories:
  - study
  - java
tags:
  - study
  - java
  
last_modified_at: 2021-03-08
---  
# 모던 자바 인 액션

## [8장] 컬렉션 API 개선  

### 8.1 컬렉션 팩토리  
```java
List<String> friends = Arrays.asList("1", "2", "3");
```  
위와 같은 코드에서 add를 고정된 크기의 배열이라 실행하면 **UnsupportedOperationException** 발생  
리스트를 인수로 받는 `Hashset` 생성자로 해결    
stream API 사용  
1. 리스트 팩토리  
`List.of("a", "b", "c");`이거를 List의 팩토리 메서드라고 부른다.  
- List.of()에는 가변 인수를 받는 오버로딩은 존재하지 않다. 그 이유는 가변 인수는 추가 배열을 할당해서 리스트로 감싸는데 그 말은 즉슨 그 배열을 처리하는 비용까지 있는 것이다.  
2. 집합 팩토리  
`Set.of("a", "b", "c");` 집합의 팩토리 메서드다.  
중복된 요소 입력시 IllegalArgumentException 발생  
3. 맵 팩토리  
`Map.of("a", 1, "b", 2, "c", 3);` 맵의 팩토리 메서드다. 키와 값을 번갈아 제공한다.  
열 개 이상의 맵을 생성하는 경우에는 `Map.Entry<K, V>` 객체를 인수로 받으며 가변 인수로 구현된 `Map.ofEntries(entry("a", 1), entry("b", 2), entry("c", 3));`과 같은 방법을 이용하는 것이 좋다.  
위와 같은 팩토리로 생성된 컬렉션은 바꿀 수 없다!! *set, add 등 메서드 사용 불가*  
<br>  

### 8.2 리스트와 집합 처리
기존 컬렉션을 바꾸는 것은 에러를 유발하고 복잡해진다. 그래서 아래와 같은 메서드가 나왔다.  
1. removeIf 메서드  
```java
for(Transaction transaction : transactions) {
    if(Character.isDigit(transaction.getReferenceConde().charAt(0))) {
        transactions.remove(transaction);
    }
}
```  
위 코드는 `ConcurrentModificationException`이 발생한다.  
for-each에서는 Iterator 객체가 사용되는데 이 객체가 hasNext()로 Collection 객체 자체에게 묻고 있어서 상호간에 동기화가 되지 않는다.  
이때 **removeIf** 메서드를 사용하면 좋다.  
```java
transactions.removeIf(transaction -> Character.isDigit(transaction.getReferenceCode().charAt(0)));
```  

2. replaceAll 메서드  
요소를 제거하는게 아니라 바꿔야할 때 사용하면 좋다.  
stream을 사용하면 할 수 있지만, 새 컬렉션이 만들어진다는 점이 문제이다.  
ListIterator 객체를 이용하면 set 메서드를 이용해 기존의 컬렉션을 바꿀 수 있다.  
하지만 또 iterator.next()로 확인하며 set해나가기에는 복잡하고 문제가 일어날 수 있어 자바 8에서는 `replaceAll` 메서드를 제공한다.  
```java
examples.replaceAll(ex -> Character.toUpperCase(code.charAt(0))) + code.substring(1));  
```
<br>

### 8.3 맵 처리  
1. forEach 메서드  
```java
for(Map.Entry<String, Integer> entry: examples.entrySet())
```  
위와 같이 하던 맵 순회를 아래와 같이 `BiConsumer`를 이용해 할 수 있다.  
```java
examples.forEach((name, age) -> ~~)
```  
2. 정렬 메서드  
Entry.comparingByValue, Entry.comparingByKey를 이용해 값 또는 키를 정렬할 수 있다.  
`examples.entrySet().stream().sorted(Entry.comparingByKey()).collect(Collectors.toMap())`와 같이 사용한다.  
HashMap은 키로 생성한 해시코드로 접근할 수 있는 버켓에 저장하는 방법이 사용된다. 버킷이 커지면 정렬된 트리를 이용해 동적 치환한다.  
3. getOrDefault 메서드  
찾으려는 값이 존재하지 않으면 NPE 방지를 위해 null이 아닌 다른 값을 반환하도록 도와주는 메서드이다.  
`examples.getOrDefault("a", 0)`과 같이 사용할 수 있다.  
4. 계산 패턴  
- computeIfAbsent: 값이 없으면 새로 추가하고 계산한다. (이미 처리한 데이터 다시 계산안해도 될 때 유리)  
- computeIfPresent: 값이 있으면 새 값을 계산하여 넣는다. null이 반환되면 맵에서 제거한다.   
- compute: 새 값을 계산하고 저장  
5. 삭제 패턴  
`examples.remove("a", 1);`를 사용하면 제거된다.  
6. 교체 패턴  
- replaceAll: BiFunction을 이용해 모든 키의 값을 교체한다.  
- replace: 키가 존재하면 값을 바꾼다.  
7. 합침  
```java
Map<String, Integer> f = Map.ofEntries(entry("a", 1), entry("b", 2));
Map<String, Integer> p = Map.ofEntries(entry("c", 3), entry("d", 4));
Map<String, Integer> sum = new HashMap<>(f);
sum.putAll(p);
```  
중복 값이 없을 때 위와 같이 합칠 수 있다.  
중복 키가 다른 값으로 있으면 `merge`메서드를 사용할 수 있다.  
```java
f.forEach((k, v) -> sum.merge(k, v, (age1, age2) -> age1 + "&" + age2));
```  
이는 지정된 키와 연관 없거나 값이 null이면 null이 아닌 값과 연결하고, 결과가 null이면 항목을 제거한다.  
<br>  

### 8.4 개선된 ConcurrentHashMap  
동시성 친화적인 HashMap이다. 동시 추가, 갱신을 허용한다. **스레드 안전**한 맵!  
1. 리듀스와 검색
- forEach: 각 요소에 함수 실행  
- reduce: 모든 값을 제공된 함수로 결과 생성  
- search: null이 아닌 값일때까지 각 요소에 함수 적용  
이는 상태를 잠그지 않고 수행하므로 변경될 수 있는 객체, 값, 순서 등에 의존하지 않아야 한다.   
기본 값에는 특화된 메서드가 제공되므로 박싱 작업이 필요 없도록 적극 활용한다.  
- 키, 값으로 연산
- 키로 연산  
- 값으로 연산  
- Map.Entry 객체로 연산  
위 네가지 연산 형태가 지원된다.  
2. 개수  
`mappingCount` 메서드가 제공된다. size보다 사용하기가 장려된다.  
3. 집합뷰  
맵을 집합 뷰로 반환하는 `keySet`이라는 메서드를 제공한다.  
