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
    void Next();//提示下一个方块
    void Set_Score_Level();//设定
private:
    deque<Tetromino> ctetris;
    int score;
    int speed;
};


#endif // CONTROLLER_H_INCLUDED
