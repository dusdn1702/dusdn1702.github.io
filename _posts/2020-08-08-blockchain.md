---
title: "블록체인 멘토링"
excerpt: "블록체인 - 하이퍼레져패브릭"
permalink: /study/6

categories:
  - study
tags:
  - study
  - blockchain

last_modified_at: 2020-08-04
---
하이퍼레져 자격증...

** 하이퍼레저 패브릭으로 배우는 블록체인 **

## fabric 이란
- hyperledger project의 framework 
- 프라이버시, 기밀성 제공
- 채널 제공으로 피어만 기밀성 갖고 사용 가능

## fabric 아키텍쳐
- identity, membership service(신원과 역할에 대한 보증과 관리)
- ledger, transactions(체인코드 제출, 업데이트, api 호출), 
- consensus service: distribute ledger(블록체인 관리;hash), ordering service(트랜잭션 발생 순서 정렬), network protocol(피어 생존 여부 체크), endorsement validation(사용자 검증)
- chaincode(업무용 백엔드 느낌): secure container, secure registry services

## fabric 구성요소
- identity: PKI 기반 디지털 인증서, CA가 약함
- membership: MSP(peer, orderer, CA, Admin 역할, 소속, 권한 정의)
- peer: channels, chaincode, events, ledger(blockchain, worldstate(최신 데이터 소유))
    + endorsing peer(트랜잭션에 대한 보증,시뮬레이션 피어), committing peer(원장 가진 모든 피어)
    * leader peer(orderer가 leader한테만 block 제공; 부하 분산, leader가 팀원에게 전달, static/dynamic 선출 방식 선택 가능), anchor peer(자신의 org의 구성 정보를 알려주며 다른 org와 통신하며 정보 동기화, leader까지도 알려줌)
- sdk: 소프트웨어 개발 도구
    + data read 1. 트랜잭션 생성 요청 2. sdk 받음 3. peer와 연결 4. 체인코드 실행 요청 5. peer가 내 chaincode container 실행, 없으면 이때 실행 6. 결과값 반환 :: 요청 받은 피어만 수행
    + data write 1. 트랜잭션 생성 요청 2. sdk 받아서 3. peer 연결 4. 체인코드 실행 요청 4.5 peer의 체인코드 실행 5. endorser peer들이 검증 진행(무분별한 order 거절) 검증되면 인증서 제공 6. 보증 허가된 트랜잭션 전달 7. sdk 받아서 8. 보증 허가된 트랜잭션을 orderer는 그 순서에 따라 트랜잭션 정렬해서 규정에 맞게 블록 생성해 9. 최신 블록에 트랜잭션 포함해 leader peer에게 전달 10. leader 피어가 각 피어에 최신 블록 전달 ; 이 로직을 성공하면 성공했다고 알림 주어 검증
- chaincode: 성능은 golang(level db), 편리함은 node.js
    + QSCC, ESCC(endorsing peer에서 실행), VSCC(Committing peer에서, 검증할 때 사용), CSCC
- ledger: 모든 트랜잭션 기록되는 db의 유형
    + world state(원장의 현재 값, 새로운 거를 계속 put 하는 것); leveDB(key-value, 고성능), couchDB(json 포맷)
    + blockchain(모든 거래 기록 저장); header, data(transaction있는데 보증이 뭔지 등등..)
- ordering service: 모든 것에 대한 순서 관리
    + kafka: pub-sub 구조, 카프카가 메시지 갖고 있고 zookeeper가 관리한다. 분산이 안됨. 백엔드에 많이 씀
- channel: 서로 다른 채널 간 프라이버스 제공, 원장별로 생성, 각 피어 별로 원하는 채널 이용

## 합의알고리즘(Consensus Algorithm) = 보증 + 오더링 + 검증 

### 참고
peer랑 orderer chaincod log 띄워두고 진행할 것
** 한 것에 대한 검증할 줄 알 것 **
전체 transaction flow 다시
!(transaction_flow.png)(C:\Users\조연우\Desktop\project_BC)

CLI container 한번에 보내주는 역할 ; 없어도 됨
peer의 default를 yaml에서 변경
~~ 체인코드 인스턴스화, 
