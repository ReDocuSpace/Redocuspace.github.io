---
layout: study_language
title:  "프로세싱 움직임"
index : 6
categories: processing
name : "손에 잡히는 프로세싱"
---

### **움직임** 
<hr/>
화면의 애니메이션은 마치 플립 북(flip book)과 같이 하나의 이미지를 그리고, 그 다음 그 이미지를 약간 다른 모습으로 그리고, 또 약간 다른 이미지를 그리는 식으로 만들어진다. 움직임이 부드럽다는 환영은 눈의 잔상 효과 때문에 발생한다. 적절한 속도로 유사한 이미지들을 보여 주면 우리의 뇌는 이 이미지들이 움직인다고 인식한다.

<br/>

#### **1. 프레임 속도 보기**

프로세싱은 부드러운 움직임을 구현하기 위해 draw() 내부의 코드를 초당 60프레임씩 실행한다. 프레임 속도를 확인하려면 아래의 프로그램을 실행하고 콘솔에 출력되는 값을 확인하자. println() 함수의 매개 변수로 frameRate 변수를 사용하면 초당 프로그램이 실행되는 속도를 출력할 수 있다.

```c
void setup(){
    // 기본적으로 프레임은 60 아래와 같이 설정이 가능하다
    frameRate(30);      //  초당 30
    //frameRate(10);    //  초당 10

}

void draw(){
    println(frameRate);
}
```
<br/>

#### **2. 프레임 속도 보기**
```c
int radius = 40;
float x = 110;
float speed = 0.5f;
int direction = 1;

void setup(){
    size(240,120);
    smooth();
    ellipseMode(RADIUS);
}

void draw(){
    background(0);
    x += speed * direction;
    if((x > width - radius) || (x < radius)){
        direction = -direction;
    }
    if(direct == 1){
         arc(x, 60, radius, radius, 0.52, 5.76);
    }else{
         arc(x, 60, radius, radius, 3.67, 8.9);
    }
}
```
<br/>

#### **3. 트위닝(Tweening)**

```c
int startX = 20;
int stopX = 160;
int startY = 30;
int stopY = 80;

float x = startX;
float y = startY;
float step = 0.005f;
float pct = 0.0f;

void setup(){
  size(240,120);
  smooth();
}

void draw(){
  background(0);
  if(pct <1.0){
    x = startX + ((stopX - stopY) * pct);
    y = startY + ((stopY - startY) * pct);
    pct += step;

  }
  ellipse(x,y,20,20);
}
```
<br/>

#### **4. 랜덤한 움직임**

```c
void setup(){
  size(240,120);
  smooth();
}

void draw(){
  background(204);
  for(int x = 20;x < width;x += 20){
    float mx = mouseX/10;
    float offsetA = random(-mx,mx);
    float offsetB = random(-mx,mx);
    line(x + offsetA, 20, x - offsetB, 100);
  }  
}
```
<br/>

#### **5. 도형 움직이기**

```c
float speed = 2.5f;
int diameter = 20;
float x;
float y;

void setup(){
    size(240,120);
    smooth();
    x = width/2;
    y = height/2;
}

void draw(){
    x += random(-speed, speed);
    y += random(-speed, speed);
    x = constrain(x, 0, width);
    y = constrain(y, 0 height);
    ellipse(x,y, diameter, diameter);
}

```
<br/>

#### **6. 타이머**

```c
void draw(){
    int timer = millis();
    println(timer);
}
```
<br/>

#### **7. 예정된 이벤트 시작하기**
```c
int time1 = 2000;
int time2 = 4000;
float x = 0;

void setup(){
    size(480,120);
    smooth();
}

void draw(){
    int currentTime = millis();
    background(204);
    if(currentTime > time2)
    {
      x -= 0.5f;
    } else if(currentTime > time1){
      x += 2;
    }
    ellipse(x,60,90,90);
}
```
<br/>

#### **8. 순환 - 사인파의 값**

```c
float angle = 0.0f;

void draw(){
  float sinval = sin(angle);
  println(sinval);
  float gray = map(sinval, -1, 1, 0, 255);
  background(gray);
  angle += 0.1;
}

```
<br/>

#### **9. 순환 - 사인파와 움직임**

```c
float angle = 0.0f;
float offset = 60;
float scalar = 40;
float speed = 0.05f;

void setup(){
  size(240,120);
  smooth();
}

void draw(){
  background(0);
  float y1 = offset + sin(angle) * scalar;
  float y2 = offset + sin(angle + 0.4f) * scalar;
  float y3 = offset + sin(angle + 0.8f) * scalar;

  ellipse(80,y1,40,40);
  ellipse(120,y1,40,40);
  ellipse(160,y1,40,40);

  angle += speed;
}
```
<br/>

#### **10. 순환 - 원운동**

```c
float angle = 0.0f;
float offset = 60;
float scalar = 30;
float speed = 0.05f;

void setup(){
  size(120,120);
  smooth();
}
void draw(){
  float x = offset + cos
}
```
<br/>

#### **11. 순환 - 나선형**

```c
float angle = 0.0f;
float offset = 60;
float scalar = 2;
float speed = 0.05f;

void setup(){
  size(120,120);
  fill(0);
  smooth();
}

void draw(){
  float x=  offset + cos(angle) * scalar;
  float y = offset + sin(angle) * scalar;
  ellipse(x,y,2,2);
  
  angle += speed;
  scalar += speed;
}
```
<br/>

### **도형, 회전, 비례**
<hr/>

도형의 기준점의 좌표를 수정하여 움직임을 만들어낼 수도 있지만, 화면의 기준점 좌표를 이동해도 움직임을 만들어 낼 수 있다.
<br/>

#### **1. 위치 변환**

```c
void setup(){
  size(120,120);
}

void draw(){
  translate(mouseX, mouseY);    // gotoxy(x,y);
  rect(0,0,30,30);
}
```
<br/>

#### **2. 다중이동**

```c
void setup(){
  size(120,120);
}

void draw(){
  translate(mouseX, mouseY);    // gotoxy(x,y);
  rect(0,0,30,30);
  translate(35, 10);
  rect(0,0,15,15);
}
```
<br/>

#### **3. 변환에서 제외하기**

```c
void setup(){
  size(120,120);
}

void draw(){
  pushMatrix();
  translate(mouseX, mouseY);    // gotoxy(x,y);
  rect(0,0,30,30);
  popMatrix();
  translate(35, 10);
  rect(0,0,15,15);
}
```
<br/>

#### **4. 회전**

```c
float angle = 0.0f;

void setup(){
  size(120,120);
  smooth();
}

void draw(){
  translate(mouseX, mouseY);    // gotoxy(x,y);
  rotate(angle);
  rect(-15,-15, 30,30);
  angle += 0.1;
}
```
<br/>

#### **5. 비례 변환 (Scaling)**

```c
float angle = 0.0f;

void setup(){
  size(120,120);
  smooth();
}

void draw(){
  translate(mouseX, mouseY);    // gotoxy(x,y);
  scale(sin(angle) + 2);
  rect(-15,-15, 30,30);
  angle += 0.1;
}
```
<br/>

#### **6. 테두리 두께 유지하기**

```c
float angle = 0.0f;

void setup(){
  size(120,120);
  smooth();
}

void draw(){
  translate(mouseX,mouseY);
  float scalar = sin(angle) + 2;
  scale(scalar);
  strokeWeight(1.0/scalar);
  rect(-15,-15,30,30);
  angle += 0.1;
}

```
<br/>

#### **7. 팔의 관절**

```c
float angle = 0.0f;
float angleDirection = 1;
float speed = 0.005f;

void setup(){
  size(120,120);
  smooth();
}

void draw(){
  background(204);
  translate(20,25);
  rotate(angle);
  strokeWeight(12);
  line(0,0,40,0);
  translate(40,0);
  rotate(angle * 2.0f);
  strokeWeight(6);
  line(0,0,30,0);
  translate(30,0);
  rotate(angle * 2.5f);
  strokeWeight(3);
  line(0,0,20,0);

  angle += speed * angleDirection;
  if((angle > QUARTER_PI) || (angle < 0)){
    angleDirection += -1;
  }
}
```
<br/>