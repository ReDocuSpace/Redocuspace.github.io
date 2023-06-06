---
layout: study_booklist
title:  "변수"
index : 4
categories: processing
name : "손에 잡히는 프로세싱"
---

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

### 변수만들기

변수를 만들기 위해서는 [변수명],[데이터 유형],[값]을 결정해야 한다. 변수명은 사용자가 변수에 부여하는 이름이다. 변수가 무엇을 저장하는지 알기 쉽도록 변수명을 정하는 것이 좋지만, 일관되게 정하고, 또 너무 장황하지 않도록 한다. 예를 들어, 'radius'라는 변수명이 'r' 이라는 변수명보다 나중에 다시 코드를 봤을 때 더 알아보기 쉬울 것이다.

데이터 유형에 따라 변수에 담을 수 있는 값의 범위가 정의된다. 예를 들어, integer(정수) 데이터 유형에는 소수점이 없는 수(정수)를 저장할 수 있다. 코드에서 integer는 int로 줄여쓴다. 정수, 실수, 문자, 단어, 이미지, 폰트 등은 각각 해당하는 데이터 유형들이 따로 있다.

우선 변수들을 선언해야 하는데, 그러면 컴퓨터의 메모리에 정보를 저장할 수 있는 공간이 마련된다. 변수를 선언할 때는 (int처럼) 데이터 유형도 명시해서 어떤 유형의 정보를 저장할 것인지 표시해야 한다. 데이터 유형의이름을 설정한 뒤에는 변수에 값을 할당할 수 있다.

데이터 유형의 이름은 변수를 선언하는 코드의 행에만 쓴다. 컴퓨터는 변수명 앞에 데이터 유형이 있을 때마다 여러분이 새로운 변수를 선언한다고 판단한다. 프로그램에서는 같은 이름의 변수를 프로그램의 같은 구역에서 두 개 이상 쓸 수 없기 때문에 아래의 경우 에러가 발생한다

```c
int x;          // x를 int 변수로 선언
int x = 12;     // Error! 이 부분에서는 x라는 이름의 변수가 두개나 있을 수 없다
```

<br/>

### 프로세싱의 변수들

```c
size(480,120);
smooth();

line(0,0,width,height);     // (0,0)부터 (480,120) 까지 이어지는 선
line(width,0,0,height);     // (480,0) 부터 (0, 120) 까지 이어지는 선
ellipse(width/2, height/2, 60,60);
```
<br/>

### 간단한 수학

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

### 반복

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

### 반복문 1

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

### 반복문 2

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


### 반복문 3

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

### 반복문 4

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

### 반복문 5

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

### 반복문 6

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