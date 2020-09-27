---
title: "안드로이드 어플리케이션 만들기"
excerpt: "Android studio with Flutter"
permalink: /study/14
categories:
  - study
  - app
tags:
  - study
  - app
  - android studio
  - flutter

last_modified_at: 2020-09-27
--- 
# Android studio  
안드로이드 스튜디오 플러그인에 flutter와 dart를 설치하면 플러터를 사용할 수 있다.  

# Flutter 란?
플러터는 구글에서 만든 cross-platfrom framework 으로 하나의 코드를 기반으로 android와 ios 앱을 개발할 수 있다. Dart라는 언어를 사용하는데 이 언어는 c언어 기반으로 만들어진 문법이다.

## 설치
flutter sdk를 설치하고, 나는 윈도우 유저니 android studio를 설치한다. 이때 java jdk는 반드시 8이하의 버전이어야 한다. 14 이상이면 오류가 계속 나서 진짜 울고 싶었다.. 그리고 안드로이드 스튜디오 설치할 때, sdk가 유저 이름이 한글이면 안된다. 아직까지 이유는 모르겠는데 이때 맘대로 지정하는 디렉토리를 옮기려고 했는데 실패했다.. 왜였을까..  

### 앱 예제 실행하기  
flutter 다운 받은거 안에 packages가 존재하는데 여기에 많은 예제들이 있다.  

### widget  
플러터는 image, icon, text와 행과 열과 패딩 모두 widget으로 이뤄진다. main.dart에서 runApp에 widget을 전달함으로 앱을 시작한다. 그 아래 child로 text widget을 전달한다.
