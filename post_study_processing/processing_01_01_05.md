---
layout: study_booklist
title:  "미디어"
index : 6
categories: processing
name : "손에 잡히는 프로세싱"
---

프로세싱으로 단순한 선이나 도형만 그릴 수 있는 것은 아니다. 이제 레스터 이미지(rester image), 벡터 파일(vector file), 폰트 등을 프로그램에 로드해서 사진, 복잡한 도형, 그리고 다양한 서체에 이르기까지 시각적 가능성을 확장해 보자.

프로세싱은 data 폴더에 이러한 파일들을 저장하기 때문에 데스크톱, 웹, 또는 모바일 기기에서 실행되는 스케치를 만들더라도 파일들의 위치를 걱정할 필요가 없다.

## 이미지

프로세싱에서는 다음 3단계를 통해 이미지를 그린다.

1. 스케치의 data 폴더에 이미지를 추가한다.
2. 이미지를 저장할 수 있도록 PImage 유형의 변수를 생성한다.
3. loadImage() 함수로 이미지를 변수에 로드한다.

<br/>

### 이미지 로드하고 관리하기

```c
PImage img1;
PImage img2;

void setup(){
    size(480,120);
    img1 = loadImage("이미지파일명.jpg");
    img2 = loadImage("이미지파일명.jpg");
}
void draw(){
    background(0);
    image(img1, 0, 0, mouseX * 2, mouseY * 2);   // 크기
    image(img2, 0, mouseY * -1);                 // 투명도
}
```
<br/>

## 폰트

프로세싱은 기본 폰트 외에도 다양한 폰트로 텍스트를 표시할 수 있다.
텍스트를 다른 서체로 표시하기 전에 프로세싱 메뉴에서 컴퓨터에 있는 폰트를 VLW 포맷으로 변환해야 한다. VLW 포맷은 글자들을 작은 이미지로 저장한다. Tool 메뉴에서 Create Font를 선택하면 컴퓨터의 폰트를 VLW 포맷으로 변환해 주는 툴이 실행된다. 이 대화 창에서 변환하고자 하는 폰트와 크기 그리고 안티 얼라이어싱을 선택한다.

1. 스케치의 data 폴더에 폰트를 추가한다.
2. 폰트를 담을 수 있또록 PFont 유형의 변수를 생성한다.
3. loadFont() 함수로 변수에 폰트를 로드한다.
4. textFont() 명령으로 현재의 폰트를 설정한다.

<br/>

### 폰트를 설정한 텍스트 작성
```c

PFont font;

void setup(){
    size(480,120);
    smooth();
    font = loadFont("특정폰트.vlw");
    textFont(font);
}
void draw(){
    background(102);
    textSize(36);
    text("문자",25,60);     // x,y 좌표
    textSize(18);
    text("문자",27,90);     // x,y 좌표
    
    // 박스안에 글자 쓰기
    text("문자", 26,30,240,100);
}
```
<br/>

## 도형

잉크스케이프나 일러스트레이터 같은 프로그램에서 만든 벡터 도형들도 프로세싱에서 바로 로드할 수 있다. 이렇게 하면 프로세싱에서 함수를 사용하여 그리지 않을 다양한 도형들을 사용할 수 있다. 벡터 도형도 이미지와 마찬가지로 로드하기 전에 스케치에 추가해야 한다.

1. SVG 파일을 data폴더에 추가한다.
2. 벡터 파일을 저장할 PShape 유형의 변수를 생성한다.
3. loadShape() 명령어로 변수에 벡터 파일을 로드한다.

<br/>

### 도형 크기 관리하기

```c
PShape network;

void setup(){
    size(480,120);
    smooth();
    shapeMode(CENTER);
    network = loadShape("파일명.svg");
}

void draw(){
    background(0);
    shape(network, 30, 10);
    shape(network, 180, 10, 280, 280);

    float diameter = map(mouseX, 0, width, 10, 800);
    shape(network, 120, 60, diameter, diameter);
}
```