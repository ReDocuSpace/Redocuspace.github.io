---
layout: study_booklist
title:  "함수"
index : 8
categories: processing
name : "손에 잡히는 프로세싱"
---

함수는 프로세싱 프로그램을 이루는 기본적인 구성 요소다. 
함수의 장점은 모듈성에 있다. 함수는 독립적인 소프트웨어 단위로, 마치 레고 블록처럼 블록 유형마다 각각 특정한 용도가 있고, 레고로 복잡한 모형을 만들려면 다양한 블록을 결합해야 하듯이, 더 복잡한 프로그램을 만드는 데 사용된다. 함수도 마찬가지로, 이 블록들의 진정한 힘은 동일한 요소들을 가지고 수많은 다양한 형태를 만들어 낼 수 있는 능력에 있다. 

함수는 나무처럼 복잡한 도형을 여러 번 그릴 때 유용하다. 나무의 모양을 그리는 함수는 프로세싱이 내장하고 있는 line() 같은 명령어를 통해 형태를 만들 수 있을 것이다. 일단 나무를 그리는 코드를 작성하고나면 나무의 부분들을 다시 그려야 할 필요가 없다. 간단한게 tree()를 호출하여 도형을 그리면 된다. 함수는 복잡하게 이어지는 구문들을 단순하게 추상화해서 세부적인 구현의 문제보다는 한층 높은 차원의 목표에 집중할 수 있게 해준다.

<br/>

## 함수의 기본

컴퓨터는 프로그램을 한 줄씩 실행한다. 함수가 실행되면 컴퓨터는 함수가 정의된 곳으로 건너뛰어서 그곳의 코드들을 실행한 뒤 다시 원래 실행하고 있떤 코드의 위치로 돌아온다.

<br/>

### 주사위 던지기

```c
void setup(){
    println("ready to roll!");
    rollDice(20);
    rollDice(20);
    rollDice(6);
    println("Finished");
}
void rollDice(int runSides){
    int d = 1 + int(random(runSides));
    println("Rolling..." + d);
}
```
<br/>

### 올빼미 만들기

```c
void setup(){
    size(480,120);
    smooth();
}

void draw(){
    background(204);
    owl(110, 110);
    owl(180, 110);
}

void owl(int x,int y){
    pushMatrix();
    translate(x,y);
    stroke(0);
    strokeWeight(70);
    line(0,-35,0,-65);
    noStroke();
    fill(255);
    ellipse(-17.5,-65,35,35);       // 왼쪽 눈
    ellipse(17.5,-65,35,35);        // 오른쪽 눈
    arc(0, -65, 70, 70, 0, PI);     // 턱
    fill(0);
    ellipse(-14, -65, 8, 8);            // 왼쪽 눈
    ellipse(14, -65, 8, 8);             // 오른쪽 눈
    quad(0, -58, 4, -51, 0, -44, -4, -51);  // 부리
    popMatrix();
}
```
<br/>

### 크기가 각각 다른 올뺴미

```c
void setup(){
    size(480,120);
    smooth();
}

void draw(){
    background(204);
    randomSeed(0);
    for(int i = 35;i < width + 40;i += 40)
    {
        int gray = int(random(0, 102));
        float scalar = random(0.25, 1.0);
        owl(i, 110, gray, scalar);
    }
}

void owl(int x,int y, int gray, float scalar){
    pushMatrix();
    translate(x,y);
    scale(scalar);
    stroke(0);
    strokeWeight(70);
    line(0,-35,0,-65);
    noStroke();
    fill(255 - gray);
    ellipse(-17.5,-65,35,35);       // 왼쪽 눈
    ellipse(17.5,-65,35,35);        // 오른쪽 눈
    arc(0, -65, 70, 70, 0, PI);     // 턱
    fill(gray);
    ellipse(-14, -65, 8, 8);            // 왼쪽 눈
    ellipse(14, -65, 8, 8);             // 오른쪽 눈
    quad(0, -58, 4, -51, 0, -44, -4, -51);  // 부리
    popMatrix();
}

```
<br/>

### 값 반환하기

```c
void setup(){
    float yourWeight = 132;
    float marsWeight = calculateMars(yourWeight);
    println(marsWeight);
}
float calculateMars(float w){
   float newWeight = w * 0.38;
   return newWeight;
}
```