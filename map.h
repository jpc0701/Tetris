#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include"point.h"
#include"tools.h"
#include"tetromino.h"
#include<windows.h>
#include<vector>

using namespace std;

//class Tetromino;

class Map{
public:
    Map(){
        int color=14;
        initmap.emplace_back(Point(0,0,color));
        initmap.emplace_back(Point(1,0,color));
        initmap.emplace_back(Point(2,0,color));
        initmap.emplace_back(Point(3,0,color));
        initmap.emplace_back(Point(4,0,color));
        initmap.emplace_back(Point(5,0,color));
        initmap.emplace_back(Point(6,0,color));
        initmap.emplace_back(Point(7,0,color));
        initmap.emplace_back(Point(8,0,color));
        initmap.emplace_back(Point(9,0,color));
        initmap.emplace_back(Point(10,0,color));
        initmap.emplace_back(Point(11,0,color));
        initmap.emplace_back(Point(11,1,color));
        initmap.emplace_back(Point(11,2,color));
        initmap.emplace_back(Point(11,3,color));
        initmap.emplace_back(Point(11,4,color));
        initmap.emplace_back(Point(11,5,color));
        initmap.emplace_back(Point(11,6,color));
        initmap.emplace_back(Point(11,7,color));
        initmap.emplace_back(Point(11,8,color));
        initmap.emplace_back(Point(11,9,color));
        initmap.emplace_back(Point(11,10,color));
        initmap.emplace_back(Point(11,11,color));
        initmap.emplace_back(Point(11,12,color));
        initmap.emplace_back(Point(11,13,color));
        initmap.emplace_back(Point(11,14,color));
        initmap.emplace_back(Point(11,15,color));
        initmap.emplace_back(Point(11,16,color));
        initmap.emplace_back(Point(11,17,color));
        initmap.emplace_back(Point(11,18,color));
        initmap.emplace_back(Point(11,19,color));
        initmap.emplace_back(Point(11,20,color));
        initmap.emplace_back(Point(11,21,color));
        initmap.emplace_back(Point(10,21,color));
        initmap.emplace_back(Point(9,21,color));
        initmap.emplace_back(Point(8,21,color));
        initmap.emplace_back(Point(7,21,color));
        initmap.emplace_back(Point(6,21,color));
        initmap.emplace_back(Point(5,21,color));
        initmap.emplace_back(Point(4,21,color));
        initmap.emplace_back(Point(3,21,color));
        initmap.emplace_back(Point(2,21,color));
        initmap.emplace_back(Point(1,21,color));
        initmap.emplace_back(Point(0,21,color));
        initmap.emplace_back(Point(0,20,color));
        initmap.emplace_back(Point(0,19,color));
        initmap.emplace_back(Point(0,18,color));
        initmap.emplace_back(Point(0,17,color));
        initmap.emplace_back(Point(0,16,color));
        initmap.emplace_back(Point(0,15,color));
        initmap.emplace_back(Point(0,14,color));
        initmap.emplace_back(Point(0,13,color));
        initmap.emplace_back(Point(0,12,color));
        initmap.emplace_back(Point(0,11,color));
        initmap.emplace_back(Point(0,10,color));
        initmap.emplace_back(Point(0,9,color));
        initmap.emplace_back(Point(0,8,color));
        initmap.emplace_back(Point(0,7,color));
        initmap.emplace_back(Point(0,6,color));
        initmap.emplace_back(Point(0,5,color));
        initmap.emplace_back(Point(0,4,color));
        initmap.emplace_back(Point(0,3,color));
        initmap.emplace_back(Point(0,2,color));
        initmap.emplace_back(Point(0,1,color));

        initmap.emplace_back(Point(12,0,color));
        initmap.emplace_back(Point(13,0,color));
        initmap.emplace_back(Point(14,0,color));
        initmap.emplace_back(Point(15,0,color));
        initmap.emplace_back(Point(16,0,color));
        initmap.emplace_back(Point(17,0,color));
        initmap.emplace_back(Point(18,0,color));
        initmap.emplace_back(Point(18,1,color));
        initmap.emplace_back(Point(18,2,color));
        initmap.emplace_back(Point(18,3,color));
        initmap.emplace_back(Point(18,4,color));
        initmap.emplace_back(Point(18,5,color));
        initmap.emplace_back(Point(18,6,color));
        initmap.emplace_back(Point(18,7,color));
        initmap.emplace_back(Point(18,8,color));
        initmap.emplace_back(Point(18,9,color));
        initmap.emplace_back(Point(18,10,color));
        initmap.emplace_back(Point(18,11,color));
        initmap.emplace_back(Point(18,12,color));
        initmap.emplace_back(Point(18,13,color));
        initmap.emplace_back(Point(18,14,color));
        initmap.emplace_back(Point(18,15,color));
        initmap.emplace_back(Point(18,16,color));
        initmap.emplace_back(Point(18,17,color));
        initmap.emplace_back(Point(18,18,color));
        initmap.emplace_back(Point(18,19,color));
        initmap.emplace_back(Point(18,20,color));
        initmap.emplace_back(Point(18,21,color));
        initmap.emplace_back(Point(17,21,color));
        initmap.emplace_back(Point(16,21,color));
        initmap.emplace_back(Point(15,21,color));
        initmap.emplace_back(Point(14,21,color));
        initmap.emplace_back(Point(13,21,color));
        initmap.emplace_back(Point(12,21,color));
    }
    void Print();
    void PrintGameMap();//打印游戏地图
    void ClearGameMap();//清除游戏地图
    void AllClear();//全清除
    bool IsExist(int,int);//坐标(x,y)是否存在方块
    void AddTetromino(Tetromino& ctetromino);//向游戏地图中添加方块
    bool GameOver();//游戏是否结束
    void ClearFloor(int floor);//清除层
    int GetScore();//得分
    friend class Tetromino;
private:
    vector<Point> initmap;
    vector<Point> gamemap;
};

#endif // MAP_H_INCLUDED
