#include"tetromino.h"
#include"map.h"

#include <stdlib.h>
#include <ctime>
#include<vector>
#include <cmath>
using namespace std;


void Tetromino::Print(){
    for(auto&point:tetromino){
        if(!(point.GetX()<1 || point.GetX()>10 || point.GetY()<1 || point.GetY()>20))
            point.Print();
    }
}

void Tetromino::Print1(){
    for(auto&point:tetromino){
        point.Print();
    }
}

void Tetromino::Clear(){
    for(auto&point:tetromino)
        if(!(point.GetX()<1 || point.GetX()>10 || point.GetY()<1 || point.GetY()>20))
            point.Clear();
}

bool Tetromino::IsLeftMove(Map& cmap){
    for(auto&point:tetromino){
        if(point.GetX()==1 || cmap.IsExist(point.GetX()-1,point.GetY()))
            return false;
    }
    return true;
}

void Tetromino::LeftMove(Map& cmap){
    if(IsLeftMove(cmap)){
        Clear();
        for(auto&point:tetromino)
            point.ChangePosition(point.GetX()-1,point.GetY());
        Print();
    }
}

bool Tetromino::IsRightMove(Map& cmap){
    for(auto&point:tetromino){
        if(point.GetX()==10 || cmap.IsExist(point.GetX()+1,point.GetY()))
            return false;
    }
    return true;
}

void Tetromino::RightMove(Map& cmap){
    if(IsRightMove(cmap)){
        Clear();
        for(auto&point:tetromino)
            point.ChangePosition(point.GetX()+1,point.GetY());
        Print();
    }
}

bool Tetromino::IsDownMove(Map& cmap){
    for(auto&point:tetromino){
        if(point.GetY()==20 || cmap.IsExist(point.GetX(),point.GetY()+1))
            return false;
    }
    return true;
}

bool Tetromino::DownMove(Map& cmap){
    if(IsDownMove(cmap)){
        Clear();
        for(auto&point:tetromino)
            point.ChangePosition(point.GetX(),point.GetY()+1);
        Print();
        return true;
    }else
        return false;
}

void Tetromino::Rotate(){
    if(type!=5){
        for(auto&point:tetromino){
            point.ChangePosition(tetromino[1].GetY()-point.GetY()+tetromino[1].GetX(),point.GetX()-tetromino[1].GetX()+tetromino[1].GetY());
        }
    }
}

void Tetromino::Counterclockwise(Map& cmap){
    bool flag=false;
    int displacemen[5]={1,-2,3,-4,2},i=0;
    Rotate();
    while(1){
        for(auto&point:tetromino){
            if(cmap.IsExist(point.GetX(),point.GetY()) || point.GetX()==0 || point.GetX()==11 || point.GetY()==21){
                flag=true;
                break;
            }
        }
        if(flag){
            for(auto&point:tetromino)
                point.ChangePosition(point.GetX()+displacemen[i],point.GetY());
            if(i==4){
                Rotate();Rotate();Rotate();
                break;
            }
            i++;
            flag=false;
        }else
            break;
    }
}

vector<Point> Tetromino::GetTetromino(){
    return tetromino;
}

