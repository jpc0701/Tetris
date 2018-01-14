#include"map.h"
#include<windows.h>
#include<vector>
#include<iostream>
using namespace std;

void Map::Print(){
    for(auto&point:initmap){
        point.Print();
        Sleep(10);
    }
    SetCursorPosition(14,2);
    SetColor(160);
    cout<< "NEXT";
    SetCursorPosition(14,9);
    cout<< "LEVEL";
    SetCursorPosition(14,12);
    cout<< "SCORE";
    SetColor(7);
}

void Map::PrintGameMap(){
    for(auto&point:gamemap)
        point.Print();
}

void Map::ClearGameMap(){
    for(auto&point:gamemap)
        point.Clear();
}

void Map::AllClear(){
    system("cls");
}

bool Map::IsExist(int x,int y){
    for(auto&point:gamemap){
        if(point.GetX()==x && point.GetY()==y)
            return true;
    }
    return false;
}

void Map::AddTetromino(Tetromino& ctetromino){
    for(auto&point:ctetromino.GetTetromino())
        gamemap.emplace_back(point);
}


bool Map::GameOver(){
    for(auto&point:gamemap){
        if(point.GetY()==0)
            return true;
    }
    return false;
}

void Map::ClearFloor(int floor){
    for(auto&point:gamemap){
        if(point.GetY()<floor){
            point.Clear();
            point.ChangePosition(point.GetX(),point.GetY()+1);
        }
    }
}

int Map::GetScore(){
    int floor[20]={0},count=0;
    vector<Point>::iterator it;
    for(auto&point:gamemap){
        floor[point.GetY()-1]++;
    }
    ClearGameMap();
    for(int i=0;i<20;i++){
        if(floor[i]==10){
            count++;
            int j=0;
            while(1){
                if(j==(int)(gamemap.size()))
                    break;
                if(gamemap.at(j).GetY()==i+1){
                    gamemap.erase(gamemap.begin()+j);
                }
                else
                    j++;
            }
        }
    }
    PrintGameMap();
    Sleep(800);
    ClearGameMap();
    for(int i=0;i<20;i++){
        if(floor[i]==10)
            ClearFloor(i+1);
    }
    PrintGameMap();
    return count;
}
