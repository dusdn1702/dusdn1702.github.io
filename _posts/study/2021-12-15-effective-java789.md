---
title: "Effective Java - item7-9"
excerpt: 2장 객체 생성과 파괴
permalink: /study/72
categories:
  - java
tags:
  - java 
---  

## [effective java] 2장 객체 생성과 파괴

### item7. 다 쓴 객체 참조를 해제하라

java는 GC가 있어서 메모리 관리에 신경 쓰지 않아도 된다고 생각될 수 있다. 하지만 메모리 누수에 대해 생각해야 한다. 

메모리 누수가 계속되면 디스크 페이징이나 OutOfMemoryError가 발생할 수 있다. 

메모리 누수는 객체가 다시 쓰지 않을 참조를 하고 있을 때 발생할 수 있다. 이럴 때는 null로 처리해 참조를 해제해 해결할 수 있다. 하지만 이것은 예외이고, 변수를 범위 밖으로 보내 누수를 해결할 수도 있다.

- 캐시

  캐시도 메모리 누수의 주범이 될 수 있다.

  WeakHashMap을 이용해 누수를 해결할 수 있다. 이는 엔트리의 유효 기간을 확실히 아는 경우에 유효하다.

  유효 기간을 모를 때는 사용하지 않는 엔트리를 스케줄러로 돌려서 해제하는 방안이 있다.(ex. LinkedHashMap)

- Listener, Callback

  콜백을 등록만 하고 해제하지 않는 경우에 발생할 수 있다. 이때 콜백을 weak reference로 두면 사용하지 않는 콜백을 GC가 수거해갈 수 있다. (ex. WeakHashMap)



### item8. finalizer와 cleaner 사용을 피하라.

객체 소멸자로 finalizer와 cleaner가 존재한다.

- finalizer

  예측할 수 없고, 위험할 수 있어 일반적으로 불필요하다. 사용하지 말아야한다.

- cleaner

  finalizer의 대체재로 사용되지만 여전히 예측할 수 없고 느리고 불필요하다.

이들이 이런 취급을 받는 이유는 제때 실행되어야 하는 작업을 할 수 없기 때문이다. 언제 일을 실행할지, 그게 빠르게인지 느리게인지 알 수 없다. 느리게 실행되면 뜬금없는 OutOfMemoryError를 마주할 수 있고, 수행 여부도 보장되지 않는다.

따라서 DB같이 영구적으로 수정이 되는 작업은 절대 사용하면 안된다.

더군다나 이들은 심각한 성능 문제도 가지고 있으며 보안 문제도 있다. 

이들은 그래서 보통 close 메서드가 호출되지 않은 것에 대한 안전망 역할으로 사용할 수 있다.

또, 네이티브 메서드를 통해 기능을 위임한 네이티브 피어와 연결해 사용할 수 있다. 네이티브 피어는 GC가 알지 못해 회수할 수 없어 이 둘을 사용하기에 효과적이다.

- AutoCloseable 사용

  인스턴스를 다 쓰고 나면 close 메서드를 호출하도록 하면 된다. try-with-resources가 제일 좋다. 자신이 잘 해제되었는지 추적하고 예외를 던지도록 하는 것이다.

  

### item9. Try-finally 보다는 try-with-resources를 사용하라

직접 close 메서드를 호출해 닫아줘야 하는 InputStream, OutputStream, java.sql.Connection 등을 닫을 때 성능 문제를 줄여주기 위해 try-with-resources를 사용하자.

이전에는 try-finally 방식을 사용했지만, 코드가 지저분해지고 close를 실패할 확률이 생겨버린다. 

이럴 때를 위해 AutoCloseable을 구현한 try-with-resources를 사용하는 것이다.

```java
try (InputStraem in = new FileInputStream(src);
    OutputStream out = new FileOutputStream(dst)) {
  //...
}
```

이렇게 되면 읽기도 쉽고 문제를 찾아 해결하기도 쉽다. 