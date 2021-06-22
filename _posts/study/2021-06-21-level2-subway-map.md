---
title: "level2 학습 로그"
excerpt: 지하철 노선도 미션
permalink: /study/46
categories:
  - techcourse
tags:
  - techcourse

last_modified_at: 2021-06-21
---  

## [Spring] @SpringBootTest의 동작 원리  
### 내용
spring application의 빈 사용,  webEnvironment에서 웹 서버를 시작하는 기능 포함  
@ExtendWith는 junit5에서 제공하는 라이브러리  
- webEnvironment  
mock: mocking된 웹 환경 제공  
RANDOM_PORT: 실제 톰캣을 띄워 환경 구성  
DEFINED_PORT: 지정한 포트에 톰캣을 띄워 환경 구성  
none: 기본적인 applicationContext 로드  
@AutoConfigureMockMvc: Mock 테스트에 필요한 의존성 제공으로 로직상 테스트 진행  

## [Spring] 통합테스트, 단위테스트  
### 내용
- 단위테스트  
독립된 객체, 메서드의 검증  
빠르고 작은 규모를 검증할 수 있다.  
내가 무언가 검증하는데에 필요한 객체가 협력 객체  
ex @WebMvcTest, @DataJpaTest, @RestClientTest, @JsonTest  
- 통합테스트  
독립된 단위가 서로 연결될 때 올바르게 작동하는지 확인하는 테스트  
db와 동작하는지, 서버와 통신하는지 등  
모든 설정과 bean 로드  
오래 걸리고 무겁다. 디버깅이 어렵다.  
ex @SpringBootTest-properties, webEnvironment(Mock, @AutoConfigureMockMvc)  
- End-to-End Test  

## [Spring] Restassured vs MockMVC  
### 내용
- RestAssured  
rest 웹 서비스 검증을 위한 라이브러리로 end to end test인 통합테스트에 사용(@SpringBootTest로 전체 로직 테스트)  
의존성 추가 필요 `testImplementation 'io.rest-assured:rest-assured:3.3.0'`  
등록된 spring bean 전부 로드  
BDD 스타일 구현으로 가독성 좋음  
- MockMVC: 애플리케이션 서버에 배포없이 스프링 mvc의 동작을 재현할 수 있는 라이브러리  
Presentation Layer의 bean 로드해서 빠름  
모두 Mock 객체로 처리해주는 비용 존재  

### 링크
- [5/4](https://dusdn1702.github.io/techcourse/65)  


# 지하철 노선도 관리 - 구간
## [Spring] spring mvc 구조  
### 내용
- client <-> ** presentation layer <-> business <-> persistence ** <-> db  
- layer 별 역할을 명확히 주도록 구현하자.  
- service layer의 정의  
비즈니스 로직을 도메인에 넣을 것인가? 서비스에 넣을 것인가?  
도메인에 비즈니스 로직을 넣어서 객체가 어떠한 일을 하는지 알 수 있도록 하자.  

### 링크
- [5/6](https://dusdn1702.github.io/techcourse/67)  

## [oop] 객체지향으로 구현하라  
### 내용
객체에게 일과 책임을 주어 일을 분담하는 것이 객체지향 프로그래밍의 원칙이다.   
Line, Station, Section이 dto처럼 행동하는 것에 대해 의구심을 갖자.  

## [database] 빈 값의 처리  
### 내용
Hibernate(jpa)나 Mybatis에서는 조회한 데이터가 없는 경우 예외가 아닌 null을 던진다.  
이를 생각해서 조회 시 값이 없는 경우 Optional로 받아서 처리해 확인하고 빈 경우 예외를 발생하도록 하였다.  

## [Spring] java bean validation
### 내용
`@NotBlank`: 공백이면 안된다.  
`@Positive`: 0보다 큰 숫자.  
`@NotNull`: null이면 안된다.  
`@AssertTrue(message = "시작일은 종료일보다 과거로 설정해야 합니다.")`: 커스텀 메시지 처리 가능  
`implementation 'org.springframework.boot:spring-boot-starter-validation'`로 의존성 추가  

#### 링크
- [5/11](https://dusdn1702.github.io/techcourse/72) 
