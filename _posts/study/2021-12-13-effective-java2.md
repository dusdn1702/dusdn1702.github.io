---
title: "Effective Java - item1"
excerpt: 2장 객체 생성과 파괴
permalink: /study/69
categories:
  - java
tags:
  - java 
---  

## [effective java] 2장 객체 생성과 파괴

### item2. 생성자에 매개변수가 많다면 빌더를 고려하라.

- 점층적 생성자 패턴

  필수 매개변수, 필수 매개변수 + 선택 매개변수 1개, 필수 매개변수 + 선택 매개변수 2개, ...

  매개변수 개수가 많아지면 클라이언트 코드를 작성하거나 읽기 어렵다. 

  각 값이 뭔지, 개수는 몇개인지, 올바른 데에 잘 넣었는지 확인하지 않으면 동작이 올바르게 실행되지 않는다.

- 자바빈즈 패턴(JavaBeans pattern) 

  매개변수가 없는 생성자로 객체를 만들고 setter로 매개변수의 값을 설정하는 방식

  점층적 생성자 패턴보다 읽기 쉽고 인스턴스 생성에 용이해졌다.

  하지만 객체 하나를 만들기 위해 수많은 메서드를 호출해야하고, 객체를 온전히 생성할 때까지 일관성이 없게 된다. 디버깅도 쉽지 않고 불변객체도 만들 수 없어 스레드 안정성을 얻을 수 없다.

  문제 해결을 위해 freeze 메서드를 사용하고 있지만 런타임 오류에는 여전히 문제가 존재한다.

- **빌더패턴(Builder pattern)**

  필수 매개변수만으로 생성자를 호출해 빌더 객체를 얻고 빌더 객체가 제공하는 setter 메서드로 선택 매개변수를 설정한다. 최종적으로 build 메서드를 호출해 필요한 객체를 얻는다. 

  메서드 체이닝을 이용해 각 setter 메서드가 빌더를 반환하도록 하여 매개변수 값을 설정하는 것을 연쇄적으로 호출할 수 있다. 

  불변식(프로그램 실행 동안 반드시 만족해야하는 조건, 주어진 조건 안에서만 변경을 허용)으로 값 검증도 가능하다.

  ```java
  public class Pizza {
    private final String size;
    private final String ham;
    private final String cheese;
    private final String dough;
    
    private Pizza(Builder builder) {
      this.size = builder.size;
      this.ham = builder.ham;
      this.cheese = builder.cheese;
      this.dough = builder.dough;
    }
    
    public static class Builder {
  	  private final String size;
      
      public Builder(String size) {
        this.size = size;
      }
      
      public Builder ham(String ham) {
        this.ham = ham;
        return this;
      }
      public Builder cheese(String cheese) {
        this.cheese = cheese;
        return this;
      }
      public Builder dough(String dough) {
        this.dough = dough;
        return this;
      }
      
      public Pizza build() {
        return new Pizza(this);
      }
    }
  }
  ```

  추상 클래스는 추상 빌더, 구현 클래스는 구현 빌더를 갖도록 하여 계층적으로 설계된 클래스에 사용하기 좋다. 

  - 장점

    이해하기 쉽고 헷갈리지 않는다. 

    안전하다.

    가변인수 매개변수를 여러 개 사용할 수 있다.

    유연하게 매개변수에 따라 다른 객체를 만들 수 있다.

  - 단점

    빌더 생성 비용 발생

    매개변수 4개 이상은 되어야 값어치를 한다. 하지만 api는 시간이 갈수록 매개변수가 늘어나기 마련이므로 생성자와 정적 패터리를 썼다가 빌더 쓰는 것보다 빌더로 애초에 만드는게 낫다.

  