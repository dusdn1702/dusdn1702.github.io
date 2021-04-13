---
title: "Spring Auth"
excerpt: 개념 정리
permalink: /study/31
categories:
  - study
  - spring
tags:
  - study
  - spring
  
last_modified_at: 2021-04-13
---  
### Spring Auth 학습 테스트  
1. HttpSession  
session 주입  
```java
@RequestMapping(..)
public void fooMethod(HttpSession session) {
    session.setAttribute(Constants.FOO, new Foo());
    //...
    Foo foo = (Foo) session.getAttribute(Constants.FOO);
}
```  

session 얻기  
```java
ServletRequestAttributes attr = (ServletRequestAttributes) 
    RequestContextHolder.currentRequestAttributes();
HttpSession session= attr.getRequest().getSession(true); // true == allow create
```  

- session에 인증 정보 저장, 로그인 정보 추출  
```java
@PostMapping("/login/session")
public ResponseEntity sessionLogin(HttpServletRequest request, HttpSession session) {
    Map<String, String[]> paramMap = request.getParameterMap();
    String email = paramMap.get(USERNAME_FIELD)[0];
    String password = paramMap.get(PASSWORD_FIELD)[0];
    if (authService.checkInvalidLogin(email, password)) {
        throw new AuthorizationException();
    }
    session.setAttribute(SESSION_KEY, email);
    return ResponseEntity.ok().build();
}
```  
- session을 통해 인증 정보 조회  
```java
@GetMapping("/members/me")
public ResponseEntity findMyInfo(HttpSession session) {
    String email = (String) session.getAttribute(SESSION_KEY);
    MemberResponse member = authService.findMember(email);
    return ResponseEntity.ok().body(member);
}
```  
2. @RequestParam / HttpServletRequest  
- tokenRequest 값을 메서드 파라미터로 받아오기  
```java
@PostMapping("/login/token")
public ResponseEntity tokenLogin(@RequestBody TokenRequest tokenRequest) {
    TokenResponse tokenResponse = authService.createToken(tokenRequest);
    return ResponseEntity.ok().body(tokenResponse);
}
```  
- authorization 헤더의 bearer 값 추출  
```java
@GetMapping("/members/you")
public ResponseEntity findYourInfo(HttpServletRequest request) {
    String token = AuthorizationExtractor.extract(request);
    MemberResponse member = authService.findMemberByToken(token);
    return ResponseEntity.ok().body(member);
}
```
