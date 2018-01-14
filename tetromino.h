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
        color=rand()%7+1;//1-��ɫ  2-��ɫ  3-��ɫ  4-��ɫ  5-��ɫ  6-��ɫ  7-��ɫ
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
    void Print();//��ӡ������
    void Print1();//��ӡ������
    void Clear();//�������
    bool IsLeftMove(Map& cmap);//�Ƿ���������ƶ�
    void LeftMove(Map& cmap);//�����ƶ�
    bool IsRightMove(Map& cmap);//�Ƿ���������ƶ�
    void RightMove(Map& cmap);//�����ƶ�
    bool IsDownMove(Map& cmap);//�Ƿ���������ƶ�
    bool DownMove(Map& cmap);//�����ƶ�
    void Rotate();//������ʱ����ת
    void Counterclockwise(Map& cmap);//��ʱ����ת
    void Clockwise();//˳ʱ����ת
    vector<Point> GetTetromino();//���ط�����Ϣ
    int GetType(){return type;}
    int GetColor(){return color;}
    friend class Map;
private:
    int x,y,color,type;
    vector<Point> tetromino;
};



#endif // TETROMINO_H_INCLUDED
