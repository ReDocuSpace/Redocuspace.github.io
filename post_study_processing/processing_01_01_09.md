---
layout: study_booklist
title:  "부록"
index : 10
categories: processing
---

### 확장

Processing은 인터랙티브한 그래픽을 구현하는데 초점을 맞추고 있다. 이 외에도, 기계를 통제하거나, 고해상도 영상을 위한 이미지를 내보내거나, 3D 출력용 모델을 내보낼 수도 있다.

### 3D

프로세싱은 두 가지 방식으로 3D를 그릴 수 있다. 기본적인 프로세싱은 2D 렌더러 (java 2D : P2D)와 OpenGL 방식을 사용한다.

### 조명

```java
import processing.opengl.*

void setup(){
    size(420,220, OPENGL);
    noStroke();
    fill(255);
}

void draw(){
    lights();
    ambientLight(102,102,102);
    directionalLight(255,255,255, -1,0,0);
    pointLight(255,255,255, mouseX, 110, 50);
    spotLight(255,255,255, mouseX, 0, 200, 0, 0, -1, PI, 2);

    rotate(PI/24);
    background(0);
    translate(width/2, height/2, -20);
    int dim = 18;
    for(int i = -height/2;i < height/2;i += dim* 1.4)
    {
        for(int j = -height/2;j < height/2;j += dim* 1.4)
        {
            pushMatrix();
            translate(i, j, -j);
            box(dim, dim, dim);
            popMatrix();
        }
    }
}
```
<br/>

### 카메라

```java
import processing.opengl.*

void setup(){
    size(420,220, OPENGL);
    noStroke();
}

void draw(){
    lights();
    background(0);
    float camZ = (height/2.0) / tan(PI * 60.0 / 360.0);
    camera(mouseX, mouseY, camZ, width/2.0, height/2.0, 0,0,1,0);   // 카메라의 위치, 목표점, 방위
    translate(width/2, height/2, -20);
    int dim = 18;
    for(int i = -height/2;i < height/2; i += dim * 1.4)
    {
        for(int j = -height/2;j < height/2; j += dim* 1.4)
        {
            pushMatrix();
            translate(i,j, -j);
            box(dim,dim,dim);
            popMatrix();
        }
    }
}
```
<br/>

### 이미지 저장하기

```java
float x = 0;

void setup(){
    size(720, 480);
    smooth();
    noFill();
    strokeCap(SQUARE);
    frameRate(30);
}

void draw(){
    background(204);
    translate(x,0);
    for(int y = 40;y < 280;y += 20)
    {
        line(-260,y,0,y+200);
        line(0, y + 200, 260, y);
    }

    if(frameCount < 60){
        saveFrame("Frame/SaveExample-####.tif");
    }else{
        exit();
    }
    x += 2.5;
}

```

### 이징(easing) : 점진적인 변화

마우스의 값들이 조금씩 지연되어 느슨하게 반영되는 기법을 점진적인 변화 (easing)이라고 한다.

### 안티 얼라이어싱 (Anti-aliasing)

이미지를 부드럽게 처리하는 방식

### VLW (Visual Language Workshop)

글자들을 작은 이미지로 저장하는 포맷

### Millis()

경과한 시간