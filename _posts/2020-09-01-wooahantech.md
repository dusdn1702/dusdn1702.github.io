---
title: "우아한 테크러닝"
excerpt: "Typescipt & React"
permalink: /study/8

categories:
  - study
tags:
  - study
  - Frontend

last_modified_at: 2020-09-01
---
우아한 테크러닝 - Typescript&react  
네트워킹 ; 코드품질->아키텍처->적정기술  
<br>

(상태 State)	  
환경 (Env)		실행 환경에 대한 환경, runtime, 개발 환경까지도  
제품 Prod;		실제 서비스 제품  
목표 (Mission))		베스트 practice 에 대한  
코드 (Quality)  
상대적{E=mc2}  
<br> 

<https://www.typescriptlang.org/play>
<https://codesandbox.io/index2>
<https://reactjs.org/>
<https://redux.js.org/>
<https://mobx.js.org/README.html>
<https://redux-saga.js.org/>
<https://blueprintjs.com/>
<https://testing-library.com/>

## TypeScript  
```ts
type Age = number;      //number의 타입을 Age로 정해줌
//이런 타입 명시는 컴파일 타임에만 작동되는 문법 요소
//런타임까지 가는 요소는 TRANSFILING 되어서 JS로 변형되는것
//TYPESCRIPT의 이점은 컴파일 타임에 적용되는 것이 많음

type Foo = {    //객체 타입 생성
    age: Age;
    name: string;
}

interface Bar{  //인터페이스
    age: Age;
    name: string;
}

const foo: Foo = {  //변수 만들고 변수 뒤 타입
    age: 10,
    name: 'Ki',
}

const bar: Bar = {  
    age: 10,
    name: 'Ki',
}

//변수 만들기 let foo = 10;은파이썬처럼 이미 type이 정해졌으므로 foo=false와 같은거 하면 오류
let fii: number = 10;   //타입을 명시한 경우; docs에서 type 익히기
let age: Age = 10;
function func(){
    arguments   //가변인자
    return 0;
}
```  
<br>

## React
Yarn create react-app my-app --template typescript / npx create-react-app my-app  
Index.tsx -> serviceWorker 삭제  
<https://babeljs.io/>  
```ts
import React from 'react';	//변환된 다음에 사용하므로 반드시 포함

interface AppProps{ //외부와 소통하는 interface
  title: String;
  color: String;
}

function App(props: AppProps){  //함수 인자의 객체로 전달, 순수 함수 컴포넌트
  return(
    <h1>{props.title}</h1>  //자바스크립트에서 쓸 때 {} dksdp tkdyd
  )
}

ReactDOM.render(  //production 작동 x, 컨테이너 관리, 단일트리의 virtual dom이므로 최상위에서 한번만 호출

  <React.StrictMode>
    <App title="Tech HELLO!" color="red"/>
  </React.StrictMode>,  //첫번째 인자
  document.getElementById('root') //html 컨테이너
);
```
js로 변형되면>>
```js
"use strict";

function App() {
  return /*#__PURE__*/React.createElement("h1", null, "Hello Tech");	//type, property, child요소의data
}
```  

상태관리 -> redux(간단함) => MobX  
변하는 상태가 있을 때 어떻게 할 것인가  
전역에 상태를 어떻게 관리할 것인가..  
Compile 상태에서 관리하기  
유연성 측면에서 각 기능 잘 생각하기…  
<br>
다음 시간 : sample들 만들어보며 하나하나    
