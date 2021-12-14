---
title: "Effective Java - item4 ~ 6"
excerpt: 2장 객체 생성과 파괴
permalink: /study/71
categories:
  - java
tags:
  - java 
---  

## [effective java] 2장 객체 생성과 파괴

#### item4. 인스턴스화를 막으려거든 private 생성자를 사용하라

생성자를 명시하지 않으면 컴파일러가 자동으로 기본 생성자를 만들어준다. 이 기본 생성자를 통해서 인스턴스화가 될 수 있다.

추상 클래스로 만들면 하위 클래스가 인스턴스화해서 사용할 수 있으므로 private 생성자를 추가하도록 한다.

더 보수적으로 작성하려면 생성자가 호출되면 예외가 던져지도록 하면 된다.

#### item5. 자원을 직접 명시하지 말고 의존 객체 주입을 사용하라

- 자원을 직접 명시한 예

  싱글턴이나 정적 유틸 클래스를 의미한다.

  ```java
  public class Dictionary {
    private static final Alphabet alphabet = new Alphabet();
    
    private Dictionary() {}
    
    public static String findWord(String word) {
      //..
    }
  }
  ```

  유연하지 않고 테스트가 어려워진다.

  멀티스레드 환경에서 사용할 수 없다.

  자원에 따라 동작이 달라지는 경우에 사용할 수 없다.

- 의존 객체 주입한 예

  인스턴스를 생성할 때 생성자에서 알맞는 자원으로 만들어주는 것을 의미한다.

  ```java
  public class Dictionary {
    private final Alphabet alphabet;
    
    private Dictionary(Alphabet alphabet) {
      this.alphabet = alphabet;
    }
    
    public static String findWord(String word) {
      //..
    }
  }
  ```

  클래스의 유연성, 재사용성, 테스트 용이성을 개선해준다.

  불변을 보장한다. 여러 클라이언트가 의존 객체들을 안심하고 공유할 수 있다.

  생성자, 정적 팩터리, 빌더에 모두 사용할 수 있다.

  - 팩터리 메서드 패턴

    생성자에 자원 팩터리를 넘겨주는 방식.

    Supplier 인터페이스를 사용하는 방식으로 클라이언트는 자신이 명시한 타입의 하위 타입이면 무엇이든 생성할 수 있는 팩터리를 넘기게 되는 것을 사용할 수 있다. 이 때, 한정적 와일드카드를 두어서 매개변수 제한을 해야한다.

#### item6. 불필요한 객체 생성을 피하라.

똑같은 기능의 객체를 사용하기 보다 불변 객체를 생성해 재사용하는 것이 빠르고 생성 비용도 줄일 수 있으며 메모리도 효율적이다.

```java
//1
String s = new String("hi");

//2
String s = "hi";
```

1은 선언할 때마다 인스턴스를 새로 생성하여 비효율적이다.

2는 jvm heap 영역 안에서 같은 문자열이 생성되면 그걸 재활용한다.

이 외에도 생성자 대신 정적 팩터리 메서드를 사용해 불필요한 객체 생성을 막을 수 있다.

그 예시로 `Boolean(String)` 대신 사용할 수 있는 `Boolean.valueOf(String)` 이 있다.

- String.matches 이야기

  정규표현식 `String.matches(String)` 은 내부에서 Pattern 인스턴스를 생성하는데 이것이 한 번 쓰고 버려져 gc 대상이 될 뿐만 아니라 Pattern 객체 자체가 정규표현식에 해당하는 final state machine을 만드므로 생성 비용이 비싸 사용하지 않는 것이 좋다. 

  사용하고 싶다면 불변 Pattern 인스턴스를 초기화 과정에서 직접 생성해 캐싱해두고 호출 될 때마다 재사용하는 것이 좋다.

  하지만 해당 메서드를 한 번도 호출하지 않으면 불필요한 생성이 또 된 것이므로 호출 될 때 생성하는 `lazy initialization` 을 사용할 수 있지만 코드가 복잡해지고 성능은 크게 개선되지 않아 추천되지 않는다.

- Adapter(View) 이야기

  이 adapter들은 하나만 생성되고 실제 작업이 이뤄지는 뒷단 객체에 연결만 되면 된다.

  Map 인터페이스의 keySet 메서드는 Map 객체 안의 키 전부를 담은 Set 뷰를 반환해 keySet 메서드가 호출될 때마다 새로운 Set을 만들 필요가 없다.

- Auto boxing 이야기

  기본 타입과 박싱된 타입을 구분되지 않게 해주지만 객체 타입을 사용하면 지 혼자 오토박싱을 해서 인스턴스를 생성하고 버리고를 반복하니 느려진다.

  따라서 필요할 때만 객체 타입을 사용하도록 하고 primitive을 사용해 불필요한 오토박싱을 없애도록 하자.

요즘 jvm에서 객체 생성은 비싸지 않다. 프로그램의 명확성, 간결성, 기능을 위해 작은 객체를 생성하는 것은 좋다. 하지만 DB Connection 같이 비싼 객체는 재사용하도록 하자. 방어적 복사와 불필요한 객체 사용 시의 trade off를 잘 생각해야 한다.