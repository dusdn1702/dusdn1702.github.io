---
title: "level2 학습 로그"
excerpt: 지하철 경로 미션
permalink: /study/47
categories:
  - techcourse
tags:
  - techcourse

last_modified_at: 2021-06-21
---  

# 지하철 경로 - 회원
## [Spring] spring 동작 원리
### 내용
- resolver, interceptor에 대해 학습하며 전체적인 스프링의 동작원리에 대해 알게 되었다.  
- CLIENT -> DISPATCHER SERVLET -> INTECEPTOR -> HANDLER  
- DispatcherServlet  
req, res를 받아서 원하는 컨트롤러의 메서드로 매핑해주고, 그 처리가 끝나고 view와 같은 결과가 나오면 적당한 결과를 매핑해 반환해주는 아이.  
즉 우리가 비즈니스로직만 만들면 되도록 연결해주는 아이  
servlet WebApplicationContext(controllers, viewResolver, handlerMapping) <--상속-- root WebApplicationContext(Services, Repositories)  
- HandlerMapping  
컨트롤러를 찾아주는 기능, 인터페이스로 매핑될 곳을 가지고 있다.  
- HandlerAdapter  
핸들러매핑을 통해 찾은 컨트롤러를 실행하는 기능, 인터페이스를 구현해서 생성  
boolean supports(지원 여부) -> ModelAndView handle(동작 구현)  
- HandlerEnterceptor  
DispatcherServlet의 호출 전후로 요청, 응답 가공하는 필터  
prehandle은 컨트롤러 호출 전 실행, posthandle은 호출 후 실행(ModelAndView 제공됨), afterCompletion은 모든 작업 완료 후 실행      
- ViewResolver  
이름에 따른 뷰를 찾아서 반환  

## [infra] 인증과 인가  
### 내용
인증: 이 사람 맞는지 입증(웹에서 로그인의 과정)  
인가: 서비스에 등록된 유저의 신원 입증(웹에서 글을 쓸 수 있는 권한)  
- 세션을 통한 인가  
사용자 ---- 로그인 ----> 서버 <---> db + session storage    
        <--- session id ----  
사용자 ---- 데이터 요청 + 쿠키 ----> 서버  
        <--- 요청 데이터 ---  

- 토큰을 통한 인가  
사용자 ---- 로그인 ----> 서버 <---> db  
        <--- token ----  
사용자 ---- 데이터 요청 + token ----> 서버     
        <--- 요청 데이터 ---  

## [Spring] 세션과 쿠키  
### 내용
- 쿠키  
총 300개 저장 가능, 한 도메인에 20개 쿠키 저장 가능, 하나의 쿠키 4kb  
이름, 값(text), 만료일, 경로 저장  
클라이언트 요청  
-> 서버에서 쿠키 생성  
-> 생성한 쿠키에 정보를 담아 http 화면 돌려줄 때 같은 클라이언트에 돌려줌  
-> 받은 쿠키를 클라이언트가 가지고 있다가 다시 요청할 때 쿠키와 함께 전송  
-> 같은 사이트 방문 시 해당 쿠키가 있으면 요청 페이지와 함께 쿠키 전송  
속도는 세션보다 빠르지만 보안이 안좋다.  
ex 오늘 팝업 안보기, 아이디 비번 자동 입력  

- 세션  
서버가 허용하는 한 제한 없다.  
클라이언트 요청  
-> 서버는 쿠키(request-header)를 확인해 session-id 확인  
-> session-id 없으면 서버는 생성해서 클라이언트에게 줌  
-> 클라이언트로 돌려준 session-id를 쿠키로 서버에 저장  
-> 재접속 시 쿠키로 id 전달  
쿠키보다 느리고 소모되는 자원이 크지만 보안이 좋다.  
ex 로그인  

## [Spring] token  
### 내용
클라이언트의 로그인 요청 -> 서버의 토큰 발행(response body)  
클라이언트의 토큰 저장(쿠키/authorization)  
인가 필요한 요청마다 토큰 전송  

## [web] CORS
### 내용
교차 출처 리소스 공유, 추가 http 헤더를 사용해 하나의 출처에서 실행 중인 웹 애플리케이션이 다른 출처의 선택한 자원에 접근할 수 있는 권한을 부여하도록 알려주는 것  
브라우저는 보안 상의 이유로 교차 출처 http 요청을 제한.  XMLHttpRequest와 fetch는 동일 출처 정책을 적용, 웹 애플리케이션은 자신과 같은 출처만 불러올 수 있다.  

## [web] cookie vs local storage vs session storage  
### 내용
- cookie  
웹 요청은 매번 쿠키정보를 포함해 서버로 전송된다.  
최대 4kb  
만료기간 존재  
도메인 단위 접근 제한  
- web storage(local/session)  
저장된 데이터가 클라이언트에 존재하지만 서버로 전송되지는 않는다.  
용량의 제한이 없다 (5mb)  
영원히 저장할 수 있다.  

## [Spring] Spring Security  
### 내용
- 비밀번호 암호화를 위해 적용했다.  

# 지하철 경로 - 최단거리 조회  

### [java] 템플릿 메서드 패턴 적용    
지하철 최단 경로를 찾는 것에 대한 인터페이스를 분리하였는데 더 다양한 알고리즘들이 사용할 수 있게 하기 위해 추상화를 진행하였다.  
그래프를 만드는 것에 대해서 중복이 발생할 수 있으니 이를 두 단계 추상화하여 진행하였다.  
ShortestPath(interface) -> ShortestPathGraph(abstract) -> ShortestPathWithDijkstra  
Path가 하는 일이 줄어든 것 같아 고민이다.  
```java  
public class Path {
    private final ShortestPath shortestPath;

    public Path(ShortestPath shortestPath) {
        this.shortestPath = shortestPath;
    }

    public List<Station> getStations() {
        return shortestPath.getStations();
    }

    public int getDistance() {
        return shortestPath.getDistance();
    }
}
```  
```java 
public interface ShortestPath {
    List<Station> getStations();

    int getDistance();
}
```  
```java 
public abstract class ShortestPathGraph implements ShortestPath {
    protected final WeightedMultigraph<Station, DefaultWeightedEdge> graph;

    public ShortestPathGraph(
        WeightedMultigraph<Station, DefaultWeightedEdge> graph, List<Section> sections) {
        this.graph = graph;
        for (
            Section section : sections) {
            graph.addVertex(section.getUpStation());
            graph.addVertex(section.getDownStation());
            graph.setEdgeWeight(graph.addEdge(section.getUpStation(), section.getDownStation()), section.getDistance());
        }
    }
}
```  
```java  
public class ShortestPathWithDijkstra extends ShortestPathGraph {
    private final GraphPath dijkstraShortestPath;

    public ShortestPathWithDijkstra(List<Section> sections, Station source, Station target) {
        super(new WeightedMultigraph<>(DefaultWeightedEdge.class), sections);
        this.dijkstraShortestPath = new DijkstraShortestPath(graph).getPath(source, target);
    }

    @Override
    public List<Station> getStations() {
        return Objects.requireNonNull(dijkstraShortestPath.getVertexList());
    }

    @Override
    public int getDistance() {
        return (int) dijkstraShortestPath.getWeight();
    }
}
```  