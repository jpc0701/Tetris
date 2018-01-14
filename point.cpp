#include"point.h"
#include"tools.h"
#include<iostream>

using namespace std;

void Point::Print(){
    SetCursorPosition(x,y);//设置打印坐标
    SetColor(color);//设置颜色
    cout<< "■" ;//打印
    SetColor(7);//将颜色恢复到初始
    SetCursorPosition(0,23);
}

void Point::Clear(){
    SetCursorPosition(x,y);
    SetColor(7);
    cout<< "  " ;
    SetCursorPosition(0,23);
}

void Point::ChangePosition(const int x,const int y){
    this->x=x;
    this->y=y;
}


int Point::GetX(){
    return this->x;
}

int Point::GetY(){
    return this->y;
}

int Point::GetColor(){
    return this->color;
}
