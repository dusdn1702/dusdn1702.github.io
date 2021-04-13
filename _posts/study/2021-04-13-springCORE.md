---
title: "Spring CORE"
excerpt: 개념 정리
permalink: /study/29
categories:
  - study
  - spring
tags:
  - study
  - spring
  
last_modified_at: 2021-04-13
---  
### Spring CORE 학습 테스트  
1. scan  
- @Component  
DAO에 선언함으로써 LineDao가 스프링 빈으로 등록됨  
- @Service  
Service에 선언함으로써 LineService가 스프링 빈으로 등록됨  

2. di  
의존성 주입은 생성자 혹은 팩토리 메서드에 의해 주입된다.  
컨테이너는 빈을 생성할 때 이러한 의존성을 주입한다.  
- construnctor injection  
```java
@Service
public class StationConstructorService {
    private StationRepository stationRepository;
    public StationConstructorService(StationRepository stationRepository) {
        this.stationRepository = stationRepository;
    }
    public String sayHi() {
        return stationRepository.sayHi();
    }
}
```  

- setter injection  
```java
@Service
public class StationSetterService {
    private StationRepository stationRepository;
    @Autowired
    public void setStationRepository(StationRepository stationRepository) {
        this.stationRepository = stationRepository;
    }
    public String sayHi() {
        return stationRepository.sayHi();
    }
}
```  

- field injection  
@Autowired를 생성자에 붙여서 초기화하여 주입  
```java
@Service
public class StationFieldService {
    @Autowired
    private StationRepository stationRepository;

    public String sayHi() {
        return stationRepository.sayHi();
    }
}
```  
