---
layout: document
title: "프로세싱 프로그래밍"
root_url : /post/programming_basic/processing_01_01
category: processing01
index : 6
---

### **변수**
<hr/>

변수는 프로그램에서 사용할 수 있도록 메모리에 값을 저장한다. 변수는 프로그램 안에서 여러 번 사용될 수 있으며 프로그램이 실행되는 동안 쉽게 값을 바꿀 수 있다.

변수를 사용하는 가장 근본적인 이유는 같은 코드를 반복해서 작성하는것을 피할 수 있기 때문이다. 만약 여러분이 같은 수를 두 번 이상 타이핑하고 있다면 코드를 더 보편적으로 만들고 업데이트하기 쉽도록 변수로 바꾸는 편이 좋다.

```c
size(400,120);
smooth();

int y = 60;
int d = 80;

ellipse(75,y,d,d);
ellipse(175,y,d,d);
ellipse(275,y,d,d);

noSmooth();
```

<br/>

#### **1. 변수 만들기**

변수를 만들기 위해서는 [변수명],[데이터 유형],[값]을 결정해야 한다. 변수명은 사용자가 변수에 부여하는 이름이다. 변수가 무엇을 저장하는지 알기 쉽도록 변수명을 정하는 것이 좋지만, 일관되게 정하고, 또 너무 장황하지 않도록 한다. 예를 들어, 'radius'라는 변수명이 'r' 이라는 변수명보다 나중에 다시 코드를 봤을 때 더 알아보기 쉬울 것이다.

데이터 유형에 따라 변수에 담을 수 있는 값의 범위가 정의된다. 예를 들어, integer(정수) 데이터 유형에는 소수점이 없는 수(정수)를 저장할 수 있다. 코드에서 integer는 int로 줄여쓴다. 정수, 실수, 문자, 단어, 이미지, 폰트 등은 각각 해당하는 데이터 유형들이 따로 있다.

우선 변수들을 선언해야 하는데, 그러면 컴퓨터의 메모리에 정보를 저장할 수 있는 공간이 마련된다. 변수를 선언할 때는 (int처럼) 데이터 유형도 명시해서 어떤 유형의 정보를 저장할 것인지 표시해야 한다. 데이터 유형의이름을 설정한 뒤에는 변수에 값을 할당할 수 있다.

데이터 유형의 이름은 변수를 선언하는 코드의 행에만 쓴다. 컴퓨터는 변수명 앞에 데이터 유형이 있을 때마다 여러분이 새로운 변수를 선언한다고 판단한다. 프로그램에서는 같은 이름의 변수를 프로그램의 같은 구역에서 두 개 이상 쓸 수 없기 때문에 아래의 경우 에러가 발생한다

```c
int x;          // x를 int 변수로 선언
int x = 12;     // Error! 이 부분에서는 x라는 이름의 변수가 두개나 있을 수 없다
```

<br/>

#### **2. 프로세싱의 변수들**

```c
size(480,120);
smooth();

line(0,0,width,height);     // (0,0)부터 (480,120) 까지 이어지는 선
line(width,0,0,height);     // (480,0) 부터 (0, 120) 까지 이어지는 선
ellipse(width/2, height/2, 60,60);
```

<br/>

#### **3. 간단한 수학**

```c
size(480,120);
int x = 25;
int h = 20;
int y = 25;
rect(x,y,300,h);
x = x + 100;
rect(x,y + h, 300,h);
x = x- 250;
rect(x,y + h*2, 300, h);
```
<br/>

### **반복문**
<hr/>

```c
size(480,120);
smooth();
strokeWeight(8);
for(int i = 20;i < 400;i += 60)
{
    line(i, 40,i + 60, 80);
}
```
<br/>

#### **1. 반복문 1** 

```c
size(480,120);
smooth();
strokeWeight(8);
for(int i = 20;i < 400;i += 20)
{
    line(i, 0,i + i/2, 80);
}
```
<br/>

#### **2. 반복문 2**

```c
size(480,120);
smooth();
strokeWeight(8);
for(int i = 20;i < 400;i += 20)
{
    line(i, 0,i + i/2, 80);
    line(i + i/2, 80, i* 1.2f, 120);
}
```
<br/>

#### **3. 반복문 3** 

```c
size(480,120);
background(0);
smooth();
noStroke();

for(int y= 0;y <= height ; y += 40)
{
    for(int x = 0;x <= width; x += 40)
    {
        fill(255,140);
        ellipse(x,y,40,40);
    }
}
```
<br/>

#### **4. 반복문 3** 

```c
size(480,120);
background(0);
smooth();
noStroke();

for(int y= 0;y <= height + 45 ; y += 40)
{
    fill(255,140);
    ellipse(0,y,40,40);
}
for(int x = 0;x <= width + 45; x += 40)
{
    fill(255,140);
    ellipse(x,0,40,40);
}
```
<br/>

#### **5. 반복문 5** 

```c
size(480,120);
background(0);
smooth();
fill(255);
stroke(102);

for(int y= 20;y <= height - 20 ; y += 10)
{
    for(int x = 20;x <= width - 20; x += 10)
    {
        ellipse(x,y,4,4);
        line(x,y,240,60);
    }
}
```
<br/>

#### **6. 반복문 6** 

```c
size(480,120);
background(0);
smooth();

for(int y= 32;y <= height ; y += 8)
{
    for(int x = 12;x <= width ; x += 15)
    {
        ellipse(x + y , y , 16 - y/10.0f , 16 - y/10.0f);
    }
}
```
<br/>

### **함수**
<hr/>

함수는 프로세싱 프로그램을 이루는 기본적인 구성 요소다. 
함수의 장점은 모듈성에 있다. 함수는 독립적인 소프트웨어 단위로, 마치 레고 블록처럼 블록 유형마다 각각 특정한 용도가 있고, 레고로 복잡한 모형을 만들려면 다양한 블록을 결합해야 하듯이, 더 복잡한 프로그램을 만드는 데 사용된다. 함수도 마찬가지로, 이 블록들의 진정한 힘은 동일한 요소들을 가지고 수많은 다양한 형태를 만들어 낼 수 있는 능력에 있다. 

함수는 나무처럼 복잡한 도형을 여러 번 그릴 때 유용하다. 나무의 모양을 그리는 함수는 프로세싱이 내장하고 있는 line() 같은 명령어를 통해 형태를 만들 수 있을 것이다. 일단 나무를 그리는 코드를 작성하고나면 나무의 부분들을 다시 그려야 할 필요가 없다. 간단한게 tree()를 호출하여 도형을 그리면 된다. 함수는 복잡하게 이어지는 구문들을 단순하게 추상화해서 세부적인 구현의 문제보다는 한층 높은 차원의 목표에 집중할 수 있게 해준다.

<br/>

#### **함수의 기본**

컴퓨터는 프로그램을 한 줄씩 실행한다. 함수가 실행되면 컴퓨터는 함수가 정의된 곳으로 건너뛰어서 그곳의 코드들을 실행한 뒤 다시 원래 실행하고 있떤 코드의 위치로 돌아온다.

<br/>


#### **1. 주사위 던지기**

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

#### **2. 올빼미 만들기**

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

#### **3. 크기가 각각 다른 올뺴미**

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

#### **4. 값 반환하기**

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
<br/>


### **클래스**
<hr/>

객체지향 프로그래밍은 프로그램에 대한 또 다른 관점을 제공한다. <br/>


boolean, int, float와 같이 하나의 값만 담을 수 있는 기본 데이터 유형들과는 달리 객체는 여러 값을 담을 수 있는 변수이다. 뿐만 아니라 객체는 변수들과 련련 함수들을 그룹으로 묶을 수 있는 방법이기도 하다. 객체는 여러분이 이미 다루어 본 변수들과 함수들을 더 이해하기 쉬운 패키지로 결합해둔다. [PImage, PFont, String, PShape] <br/>

객체는 아이디어를 보다 작은 구성 요소로 나눠줄 수 있기 때문에 중요하다. 이는 자연 세계와 유사하다. 예를 들어, 신체 기관은 조직들로 이루어져 있고, 조직들은 세포로 이루어져 있는 것과 같다. 마찬가지로, 코드가 더욱 복잡해질수록 작은 구조들로 환산해서 더 복잡한 구조들에 대응해야 한다. 모든 것을 홀로 처리하는 거대한 코드 덩어리를 작성하기보다 서로 연동되어 작동하는 작고 이해하기 쉬운 코드 조각들이 작성하기도 쉽고 관리하기도 용의하다.<br/>

소프트웨어 객체는 관련이 있는 변수들고 ㅏ함수들의 집합체다. 객체에서는 변수를 필드 혹슨 인스턴스 변수라고 하고, 함수는 메서드라고 부른다. 필드와 메서드는 앞 장들의 변수들 및 함수들과 같은 방식으로 작동하는데, 이들이 객체의 일부임을 강조하기 위해 새로운 용어를 쓰기로 하자. 즉, 다시 말하면 객체는 관련된 데이터(필드)를 관련된 액션 및 비헤이비어(메서드)와 결합한다.

#### **클래스의 형태**
```c
class 라디오 // 클래스
{
    // 필드
    볼륨
    주파수
    대역
    전원
    // 메서드
    불륨설정하기
    주파수 설정하기
    대역 설정하기
}
```
<br/>

### **배열**
<hr/>

배열은 같은 이름을 사용하는 변수들의 목록이다. 배열은 매번 새로운 이름의 변수를 생성하지 않고도 많은 변수를 다루는 작업을 할 수 있기 때문에 유용하다.

#### **마우스 움직임을 추적하는 배열**

```c
int num = 60;
int x[] = new int[num];
int y[] = new int[num];

void setup(){
    size(240,120);
    smooth();
    noStroke();
}

void draw(){
    background(0);
    for(int i = x.length - 1;i > 0;i--){
        x[i] = x[i - 1];
        y[i] = y[i - 1];
    }

    x[0] = mouseX;
    y[0] = mouseY;

    for(int i = 0;i < x.length;i++)
    {   
        fill(i * 4);
        ellipse(x[i],y[i], 40,40);
    }
}

```