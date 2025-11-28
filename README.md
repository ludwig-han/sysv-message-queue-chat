# SysV Message Queue Chat
간단한 **System V 메시지 큐 기반 채팅 프로그램**입니다.  
서로 다른 두 개의 프로세스가 메시지 큐를 통해 텍스트를 주고받습니다.

## 🚀 기능
- System V 메시지 큐 기반 IPC
- 다중 클라이언트 지원
- PID 기반 클라이언트 전용 큐 생성
- 서버 브로드캐스트 기능
- Makefile 기반 빌드
- src / include / build 구조의 모듈화된 프로젝트

## 🏗 System Architecture

### 서버(Server)
- 모든 클라이언트는 서버의 공용 큐(server_in)에 메시지를 보냄
- 서버는 메시지를 받아 각 클라이언트의 PID 기반 큐(client_out_PID)에 전달
- 필요한 경우 브로드캐스트 가능

### 클라이언트(Client)
- 서버 공용 큐로 메시지 송신
- 본인 PID로 생성된 큐에서 메시지 수신

구조도:
```console
(Client A) --
(Client B) ----> [ server_in queue ] ---> (Server)
(Client C) --/

(Server) -- broadcast --> [ client_out_{pid} x N ]
```

## 📁 Directory Structure
```console
project/
│
├─ include/
│ ├─ ipc.h
│ └─ util.h
│
├─ src/
│ ├─ server.c
│ ├─ client.c
│ └─ util.c
│
├─ build/
│ ├─ server
│ └─ client
│
└─ Makefile
```

## 🛠️ 빌드 방법

### 컴파일
```bash
make
```
빌드 후 실행 파일은 `build/` 디렉토리에 생성됩니다.

---

## ▶ Run

### 서버 실행
```bash
./build/server
```

### 클라이언트 실행  
(새 터미널 여러 개 열기)

```bash
./build/client
```

---

## 📡 Used Technology

- System V Message Queue (`msgget`, `msgsnd`, `msgrcv`)
- `ftok` 기반 IPC key 생성
- PID 기반 전용 큐 설계
- Makefile 빌드 자동화
- UNIX 프로그래밍 기본 API 활용

---

## 📌 메시지 구조 예시

```c
struct msg {
    long mtype;
    char text[256];
};
```

## 📝 Example

서버:
```console
[Server] Client(1234) joined.
[Server] Received: hello
[Server] Broadcasting to clients...
```

클라이언트:
```console
Connected as PID=1234
Enter message: hello
[From Server] hello
```

---


## 📝 라이선스
MIT License
```
