#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include<deque>
#include"Tetromino.h"
using namespace std;

class Controller{
public:
    Controller():score(0),speed(20){

    }
    void Start();
    void Game();
    void Next();//��ʾ��һ������
    void Set_Score_Level();//�趨
private:
    deque<Tetromino> ctetris;
    int score;
    int speed;
};


#endif // CONTROLLER_H_INCLUDED
