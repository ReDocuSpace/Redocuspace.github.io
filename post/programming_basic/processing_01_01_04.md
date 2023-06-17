---
layout: document
title: "프로세싱 상호작용"
root_url : /post/programming_basic/processing_01_01
category: processing01
index : 6
---

### **상호작용**
<hr/>

마우스나 키보드, 혹은 다른 장치에 반응해야 하는 코드는 프로그램이 종료되기 전까지 지속적으로 실행되어야 한다. 
이렇게 하기 위해서는, 업데이트되는 행들을 프로세싱의 draw() 함수 블록 안에 넣어 줘야 한다.

##### **setup() 함수**

```c
void setup(){
    println("I'm starting");
}
```
<br/>

##### **darw() 함수**

```c
void draw(){
    println("I'm drawing");
    println(frameCount);
}
```
<br/>

#### **1. 마우스 추적하기**
```c
void setup(){
    size(480,120);
    fill(0,102);
    smooth();
    noStroke();
}

void draw(){
    ellipse(mouseX, mouseY, 9,9);
}
```
<br/>

#### **2. 자신을 따라다니는 점**
```c
void setup(){
    size(480,120);
    fill(0,102);
    smooth();
    noStroke();
}

void draw(){
    backgorund(204);
    ellipse(mouseX, mouseY, 9,9);
}
```
<br/>

#### **3. 마우스 추적하기**

```c
void setup(){
    size(480,120);
    strokeWeight(4);
    smooth();
    stroke(0,102);
}

void draw(){
    line(mouseX, mouseY, pmouseX,pmouseY);
}
```

<br/>

#### **4. 마우스의 속도로 선의 두께 설정하기**

```c
void setup(){
    size(480,120);

    smooth();
    stroke(0,102);
}

void draw(){
    float weight = dist(mouseX, mouseY, pmouseX,pmouseY);
    strokeWeight(weight);
    line(mouseX, mouseY, pmouseX,pmouseY);
}

```
<br/>

#### **5. 이징 - 점진적인 변화**

마우스의 값들이 조금씩 지연되어 느슨하게 반영되는 기법을 점진적인 변화 (easing)이라고 한다.

```c
float x;
float easing = 0.01f;
float diameter = 12;

void setup(){
    size(220,120);
    smooth();
}

void draw(){
    float targetX = mouseX;
    x += (targetX - x) * easing;
    ellipse(x,40,12,12);
    println(targetX + " : " + x);
}
```
<br/>

#### **6. 이징을 이용해서 그린 부드러운 선들**

```c
float x;
float y;
float px;
float py;
float easing = 0.05f;

void setup(){
    size(480,120);
    smooth();
    stroke(0,102);
}

void draw(){
    float targetX = mouseX;
    x += (targetX - x) * easing;

    float targetY = mouseY;
    y += (targetY - y) * easing;

    float weight = dist(x,y,px,py);
    strokeWeight(weight);
    line(x,y,px,py);
    py = y;
    px = x;
}
```

<br/>

#### **7. 특정한 범위로 수치를 연결시키기**

```c
void setup(){
    size(240,120);
    strokeWeight(12);
    smooth();
}

void draw(){
    background(204);
    stroke(255);
    line(120 ,60 ,mouseX, mouseY);  // 흰 선
    stroke(0);
    float mx = mouseX/2 + 60;
    line(120 ,60 ,mx ,mouseY);      // 검은선
}
```

<br/>

#### **8. map() 함수로 수치들 연결시키기**

```c
void setup(){
    size(240,120);
    strokeWeight(12);
    smooth();
}

void draw(){
    background(204);
    stroke(255);
    line(120 ,60 ,mouseX, mouseY);  // 흰 선
    stroke(0);
    float mx = map(mouseX, 0, width, 60, 180);
    line(120 ,60 ,mx ,mouseY);      // 검은선
}
```

<br/>

#### **9. 마우스 클릭하기**

```c
void setup(){
    size(240,120);
    strokeWeight(12);
    smooth();
}

void draw(){
    background(204);
    stroke(255);
    line(40,0,70,height);
    if(mousePressed == true){
        stroke(0);
    }
    line(0, 70, width, 50);
}
```

<br/>

#### **10. 클릭하지 않았을 때를 검출하기**

```c
void setup(){
    size(240,120);
    strokeWeight(12);
    smooth();
}

void draw(){
    background(204);
    stroke(255);
    line(40,0,70,height);
    if(mousePressed == true){
        stroke(0);
    }else{
        stroke(255);
    }
    line(0, 70, width, 50);
}
```

<br/>


#### **11. 마우스의 여러 버튼 [ LEFT , CENTER, RIGHT]**

```c
void setup(){
    size(240,120);
    strokeWeight(12);
    smooth();
}

void draw(){
    background(204);
    stroke(255);
    line(40,0,70,height);
    if(mouseButton == LEFT){
        stroke(0);
    }else{
        stroke(255);
    }
    line(0, 70, width, 50);
}
```
<br/>


#### **12. 원의 범위**

```c
int x = 120;
int y = 60;
int radius = 12;

void setup(){
    size(240,120);
    smooth();
    ellipseMode(RADIUS);
}

void draw(){
    background(204);
    float d = dist(mouseX, mouseY, x,y);
    if( d < radius){
        radius++;
        fill(0);
    }else{
        fill(255);
    }
    ellipse(x,y,radius,radius);
}
```
<br/>

#### **13. 직사각형의 범위**

```c
int x = 80;
int y = 30;
int w = 80;
int h = 60;

void draw(){
    background(204);
    if((mouseX > x) && (mouseX < x + w) && (mouseY > y) && mouseY < (y + h)){
        fill(0);
    }else{
        fill(255);
    }
    rect(x,y,w,h);
}
```

<br/>

#### **14. 키보드 입력**

```c
void setup(){
    size(240,120);
    smooth();
}

void draw(){
    background(204);
    line(20,20,220,100);

    if(keyPressed){
        line(220, 20, 20, 100);
    }
}
```

<br/>


#### **15. 글자 그리기**

```c
void setup(){
    size(120,120);
    textSize(64);
    textAlign(CENTER);      // 중앙에 위치
}

void draw(){
    if(keyPressed){
        background(0);
        text(key,60,80);
    }
}
```

<br/>

#### **16. 특정한 키를 검사하기**

```c
void setup(){
    size(120,120);
    textSize(64);
    textAlign(CENTER);      // 중앙에 위치
}

void draw(){
    background(204);
    if(keyPressed){
        if((key == 'h' || (key == 'H'))){
            line(30,60,90,60);
        }
        if((key == 'n') || (key == 'N')){
            line(30,20,90,100);
        }
    }
    line(30,20,30,100);
    line(90,20,90,100);
}
```

<br/>

#### **17. 화살표 키로 움직이기**

```c
int x = 215;

void setup(){
    size(480,120);
}

void draw(){
    if(keyPressed && (key == CODED)){
        if(keyCode == LEFT){
            x--;
        } else if (keyCode == RIGHT){
            x++;
        }
    } 
    rect(x,45,50,50);
}
```

<br/>
