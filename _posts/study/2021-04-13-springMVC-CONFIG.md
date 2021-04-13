---
title: "Spring MVC Config"
excerpt: 개념 정리
permalink: /study/30
categories:
  - study
  - spring
tags:
  - study
  - spring
  
last_modified_at: 2021-04-13
---  
### Spring MVC Config 학습 테스트 
1. View Controller  
- 사용자가 "/" 요청했을 때 "hello" 응답  
```java
@Configuration
@EnableWebMvc
public class WebMvcConfiguration implements WebMvcConfigurer {
    @Override
    public void addViewControllers(ViewControllerRegistry registry) {
        registry.addViewController("/").setViewName("hello");
    }
}
```  

2. Handler Interceptor  
- 사용자가 "/admin/**" 요청했을 때 LoginInterceptor를 통해 인증  
- 비인가 사용자가 회원 목록 조회했을 때 권한 없음(인증 과정 거쳐야 함)  
```java
@Override
public void addInterceptors(InterceptorRegistry registry) {
    registry.addInterceptor(new LoginInterceptor())
        .addPathPatterns("/admin/**");
}
```  

3. Handler Method Argument Resolver  
- loginMember 파라미터에 값 셋팅할 수 있게 AuthenticationPrincipalArgumentResolver 활용  
```java
@Override
public void addArgumentResolvers(List<HandlerMethodArgumentResolver> resolvers) {
    resolvers.add(new AuthenticationPrincipalArgumentResolver());
}
```  
