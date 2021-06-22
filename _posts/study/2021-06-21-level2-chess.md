---
title: "level2 학습 로그"
excerpt: 체스미션
permalink: /study/45
categories:
  - techcourse
tags:
  - techcourse

last_modified_at: 2021-06-21
---  

# 체스 - Spring 적용하기  
## [Spring] CollectionUtils - 1  
### 내용
- 비어있는 컬렉션인지 확인하고자 할 때 CollectionsUtils.isEmpty(~)를 사용했다.  

## [test] test만을 위한 h2 db 생성 - 2
### 내용
- test를 할 때 프로덕션 코드에 영향을 미치지 않도록 h2 database를 사용하도록 했다.  

## [Exception] 예외처리 - 3
### 내용 
- 모든 예외 처리를 ChessAdvice라는 곳에서 @ControllerAdvice를 사용해 처리하도록 했다.  
- 각 예외 처리를 모두 custom화 하여 예외에 맞는 메시지를 출력하도록 했다.  

## [Spring] mvc - 4
### 내용
- controller, service, repository로 나누어 각 역할에 맡게 일을 수행하고 계층 간 책임을 맡도록 했다.  
- controller<->service 계층에서만 dto를 사용하도록 했다.  

## [Network] rest api - 2
### 내용 
- rest api에 대해 학습하고 적용해 api 호출을 알맞게 하도록 했다.  

## [Test] RestAssured를 사용한 테스트 구현  - 2
### 내용 
- JSON과 HTTP를 기반으로 한 테스트를 진행했다.  

## [Spring] jdbc - 3
### 내용  
- mysql 데이터베이스를 사용하고 spring의 @jdbc 기능을 사용했다.  

## [Spring] core - 3
### 내용
- 빈을 등록하고 @autowired, 생성자 주입을 이용해 주입해서 사용했다.  

## 링크
- [spring mvc](https://dusdn1702.github.io/study/28)  
- [spring jdbc](https://dusdn1702.github.io/study/27)  
- [spring core](https://dusdn1702.github.io/study/29)  
- [리팩토링 내용 정리1](https://dusdn1702.github.io//techcourse/53)  
- [리팩토링 내용 정리2](https://dusdn1702.github.io//techcourse/54)  

# 체스 - 동시게임
## [Spring] @ControllerAdvice, @RestControllerAdvice
### 내용
예외처리는 컨트롤러가 아닌 한 곳에서 처리   
@ExceptionHandler가 하나의 클래스에 대한 처리라면, @ControllerAdvice는 모든 곳에서 발생할 수 있는 예외를 잡아서 처리해준다.    
구현 방식은 따로 클래스를 만들어서 그 안에서 exceptionhandler를 가지도록 한다.   
controllerAdvice는 controller에서 발생한 exception들을 잡아서 처리한다.  
비지니스 로직에 두지 않고 분리함으로써 비즈니스 로직에 더욱 집중할 수 있다.  

## [Spring] dto의 사용 영역  
### 내용  
비슷한 필드를 갖는 DTO여도 각 DTO마다 역할이 다르고 추후 나아갈 방향이 다르기 때문에 존재할 수 있다.  
따라서 requestDto, responseDto가 많이 발생할 수 있다.   
하지만 서비스 레이어에서 Dto를 받거나 Dto를 리턴하게 되면 해당 Dto를 사용하는 특정 Controller 에 종속되게 된다.  
컨트롤러는 특정 뷰에 종속되어 있기 때문에 때에 따라서는 서비스가 뷰에 종속되게 되는 경우가 생길 수 있으므로 service가 dto에 대한 종속성을 가지지 않도록 하자.  

## [Network] REST API  
### 내용 
자원(uri), 행위(http method), 표현을 가진 것이다.  
  **uniform interface**로 uri로 지정한 자원에 대한 조작을 통일되고 한정적인 인터페이스로 수행하도록 한다.  
  **stateless**로 상태를 가지고 있지 않다. 세션 정보나 쿠키를 별도로 가지지 않기 때문에 api는 요청을 수행하기만 하면 된다.  
  **cacheable**로 http가 가진 캐싱 기능을 Last-Modified나 E-Tag를 사용하면 구현할 수 있다.  
  **self-descriptiveness**로 메시지만 보고 알아서 표현할 수 있는 구조이다.  
  **client-server 구조**로 서버는 api 제공, 클라이언트는 사용자 인증, 세션, 로그인 정보 같은 컨텍스트를 직접 관리하도록 한다. 역할이 구분되므로 서로 간의 의존성이 줄어든다.  
  **계층형 구조**로 다중 계층이 될 수 있고 proxy, 게이트웨이 같은 네트워크 기반 중간매체도 사용할 수 있다.  

## [Spring] layered architecture
### 내용 
1. presentation 계층  
사용자와 맞닿아있는 계층으로 사용자가 이용할 수 있는 기능들이 존재하고 요청을 보낼 수 있어야 한다.  
ex) template, js 계층  
2. 제어 계층  
presentation 계층과 비즈니스 로직 계층을 분리하기 위한 controller  
사용자 요청을 검증하고 적절한 응답을 전달  
ex) controller  
3. 비즈니스 로직 계층  
핵심 업무 로직, 데이터 적합성 검증, presentation, persistance 계층을 연결하기 위함  
ex) service  
4. 퍼시스턴스 계층  
데이터 처리 담당 계층, crud db 처리  
ex) repository  
5. 도메인 계층  
실질적인 객체  
ex) dto  

#### 링크
[4/26](https://dusdn1702.github.io/techcourse/58)  
[4/27](https://dusdn1702.github.io/techcourse/59)  
[4/28](https://dusdn1702.github.io/techcourse/60)  
[4/29](https://dusdn1702.github.io/techcourse/61)  
[4/30](https://dusdn1702.github.io/techcourse/62)  

# 체스 - 배포
## [Cloud] public cloud  
### 내용
클라우드 인터넷을 통해 원격으로 접근할 수 있는 모든 것  
- cloud computing  
서버, db, networking과 같은 컴퓨팅 리소스를 인터넷을 통해 관리하는 것  

## [Network] OSI 7 계층   
### 내용
mvc 패턴과 같은 소프트웨어 아키텍쳐 중 하나가 layered architecture  
네트워크 시스템이 대표적인 layered architecture를 따르는 것  
네트워크 시스템의 하나의 커다란 소프트웨어  

## [Network] bastion 서버  
### 내용
터미널 접속을 위한 22번 포트가 장애가 생기면 서비스 자체에 문제가 생긴다.  
그렇다고 모든 서버에 동일 수준의 보안을 설정하는 것은 auto-scaling 확장이 안되고 그래서 bastion server를 만들어 얘가 총알받이가 되도록한다.  
서비스 정상 트래픽과 관리자 트래픽이 구분되어 좋아진다.  

## [Network] 서버 통신 과정  
### 내용
1. 사용자가 웹브라우저 dns를 url 입력한다.  
2. dns를 통해 등록된 실제 주소(ip)를 알아낸다.  
3. ip를 통해 http 요청 메시지를 서버에 보낸다.(TCP/IP)  
4. 서버는 웹브라우저에 응답을 패킷으로 보낸다.  
5. 웹브라우저는 패킷을 조립해 사용자에게 보여준다.  

## [infra] CloudWatch 사용  
### 내용
- aws CloudWatch란  
실시간으로 실행 중인 애플리케이션을 모니터링하는 것으로 리소스 및 애플리케이션에 대해 측정할 수 있는 변수인 지표를 수집하고 추적할 수 있다.  
지표를 감시하다가 임계값을 위반하면 경고를 보낼 수도 있다.  
- AWS Identity and Access Management(IAM)  
리소스에 대한 접근을 안전하게 제어할 수 있는 웹서비스  

## [infra] 각 프로젝트 spring actuator metric 수집  
### 내용
- spring boot actuator란  
애플리케이션 모니터링하고 관리할 수 있는 데이터 제공하는 것  
커스텀 데이터 만드는 과정이 아래에 있다.  

#### 링크
- [5/2](https://dusdn1702.github.io/techcourse/63)  
- [5/3](https://dusdn1702.github.io/techcourse/64)  

## [Network] TCP/IP  
### 내용
- TCP/IP란?  
인터넷과 관련된 다양한 프로토콜의 집합(IEEE, DNS, HTTP, TCP, IP, ICMP ...)으로 일반적인 네트워크를 동작시킨다.  
- application layer  
- transport layer  
- network layer  
- link layer   
