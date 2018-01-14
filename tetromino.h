#ifndef TETROMINO_H_INCLUDED
#define TETROMINO_H_INCLUDED

#include"point.h"
#include <stdlib.h>
#include <ctime>
#include<vector>
#include <cmath>
using namespace std;

class Map;
class Tetromino{
public:
    Tetromino(){
        time_t t;
        srand((unsigned) time(&t));
        color=rand()%7+1;//1-蓝色  2-绿色  3-青色  4-红色  5-粉色  6-黄色  7-白色
        type =rand()%7+1;//1-S  2-Z  3-L  4-J  5-O  6-I  7-T
        switch(type){
        case 1:
            x=5;y=-2;
            tetromino.emplace_back(Point(x+1,y,color));
            tetromino.emplace_back(Point(x,y+1,color));
            tetromino.emplace_back(Point(x+1,y+1,color));
            tetromino.emplace_back(Point(x,y+2,color));
            break;
        case 2:
            x=5;y=-2;
            tetromino.emplace_back(Point(x,y,color));
            tetromino.emplace_back(Point(x,y+1,color));
            tetromino.emplace_back(Point(x+1,y+1,color));
            tetromino.emplace_back(Point(x+1,y+2,color));
            break;
        case 3:
            x=5;y=-2;
            tetromino.emplace_back(Point(x,y,color));
            tetromino.emplace_back(Point(x,y+1,color));
            tetromino.emplace_back(Point(x,y+2,color));
            tetromino.emplace_back(Point(x+1,y+2,color));
            break;
        case 4:
            x=5;y=-2;
            tetromino.emplace_back(Point(x+1,y,color));
            tetromino.emplace_back(Point(x+1,y+1,color));
            tetromino.emplace_back(Point(x+1,y+2,color));
            tetromino.emplace_back(Point(x,y+2,color));
            break;
        case 5:
            x=5;y=-1;
            tetromino.emplace_back(Point(x,y,color));
            tetromino.emplace_back(Point(x+1,y,color));
            tetromino.emplace_back(Point(x,y+1,color));
            tetromino.emplace_back(Point(x+1,y+1,color));
            break;
        case 6:
            x=5;y=-3;
            tetromino.emplace_back(Point(x,y,color));
            tetromino.emplace_back(Point(x,y+1,color));
            tetromino.emplace_back(Point(x,y+2,color));
            tetromino.emplace_back(Point(x,y+3,color));
            break;
        case 7:
            x=5;y=-2;
            tetromino.emplace_back(Point(x,y,color));
            tetromino.emplace_back(Point(x+1,y,color));
            tetromino.emplace_back(Point(x+2,y,color));
            tetromino.emplace_back(Point(x+1,y+1,color));
            break;
        }

    }
    Tetromino(int x,int y,int color,int type):x(x),y(y),color(color),type(type){
        switch(type){
        case 1:
            tetromino.emplace_back(Point(x+1,y,color));
            tetromino.emplace_back(Point(x,y+1,color));
            tetromino.emplace_back(Point(x+1,y+1,color));
            tetromino.emplace_back(Point(x,y+2,color));
            break;
        case 2:
            tetromino.emplace_back(Point(x,y,color));
            tetromino.emplace_back(Point(x,y+1,color));
            tetromino.emplace_back(Point(x+1,y+1,color));
            tetromino.emplace_back(Point(x+1,y+2,color));
            break;
        case 3:
            tetromino.emplace_back(Point(x,y,color));
            tetromino.emplace_back(Point(x,y+1,color));
            tetromino.emplace_back(Point(x,y+2,color));
            tetromino.emplace_back(Point(x+1,y+2,color));
            break;
        case 4:
            tetromino.emplace_back(Point(x+1,y,color));
            tetromino.emplace_back(Point(x+1,y+1,color));
            tetromino.emplace_back(Point(x+1,y+2,color));
            tetromino.emplace_back(Point(x,y+2,color));
            break;
        case 5:
            tetromino.emplace_back(Point(x,y,color));
            tetromino.emplace_back(Point(x+1,y,color));
            tetromino.emplace_back(Point(x,y+1,color));
            tetromino.emplace_back(Point(x+1,y+1,color));
            break;
        case 6:
            tetromino.emplace_back(Point(x,y,color));
            tetromino.emplace_back(Point(x,y+1,color));
            tetromino.emplace_back(Point(x,y+2,color));
            tetromino.emplace_back(Point(x,y+3,color));
            break;
        case 7:
            tetromino.emplace_back(Point(x,y,color));
            tetromino.emplace_back(Point(x+1,y,color));
            tetromino.emplace_back(Point(x+2,y,color));
            tetromino.emplace_back(Point(x+1,y+1,color));
            break;
        }

    }
    void Print();//打印出方块
    void Print1();//打印出方块
    void Clear();//清除方块
    bool IsLeftMove(Map& cmap);//是否可以向左移动
    void LeftMove(Map& cmap);//向左移动
    bool IsRightMove(Map& cmap);//是否可以向右移动
    void RightMove(Map& cmap);//向右移动
    bool IsDownMove(Map& cmap);//是否可以向下移动
    bool DownMove(Map& cmap);//向下移动
    void Rotate();//单次逆时针旋转
    void Counterclockwise(Map& cmap);//逆时针旋转
    void Clockwise();//顺时针旋转
    vector<Point> GetTetromino();//返回方块信息
    int GetType(){return type;}
    int GetColor(){return color;}
    friend class Map;
private:
    int x,y,color,type;
    vector<Point> tetromino;
};



#endif // TETROMINO_H_INCLUDED
