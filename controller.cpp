#include<iostream>
#include<conio.h>
#include<windows.h>
#include<deque>
#include"controller.h"
#include"tools.h"
#include"map.h"

using namespace std;

void Controller::Start(){

    SetWindowSize(19,24);
    SetCursorPosition(5,10);
    cout << "按任意键开始游戏";
    while(1){
        if(kbhit()){
            SetCursorPosition(5,10);
            cout <<"                       ";
            break;
        }
    }
}

void Controller::Game(){
    int keyboard,i=0,speed_t=5;
    bool flag=true,restart=true,game=true;
    while(1){
        restart=true;
        Map cmap;
        cmap.AllClear();
        cmap.Print();
        Set_Score_Level();
        ctetris.clear();
        ctetris.push_back(Tetromino());
        ctetris.push_back(Tetromino());
        Next();
        while(1){
            game=true;
            while(kbhit()){
                keyboard=getch();
                switch(keyboard){
                    case 224:
                        keyboard=getch();
                        switch(keyboard){
                            case 75:
                                ctetris.front().Clear();
                                ctetris.front().LeftMove(cmap);
                                ctetris.front().Print();
                                break;
                            case 77:
                                ctetris.front().Clear();
                                ctetris.front().RightMove(cmap);
                                ctetris.front().Print();
                                break;
                        }
                        break;
                    case 32:
                        ctetris.front().Clear();
                        ctetris.front().Counterclockwise(cmap);
                        ctetris.front().Print();
                        break;
                    case 27:
                        SetCursorPosition(13,15);
                        SetColor(BACKGROUND_INTENSITY|BACKGROUND_GREEN);
                        cout << "继续游戏";
                        SetColor(7);
                        SetCursorPosition(13,17);
                        cout << "重新游戏";
                        SetCursorPosition(13,19);
                        cout << "退出游戏";
                        int key=1;
                        while(1){
                            keyboard=getch();
                            if(keyboard==224){
                                keyboard=getch();
                                switch(keyboard){
                                    case 80:
                                        key=key<3?key+1:1;
                                        break;
                                    case 72:
                                        key=key>1?key-1:3;
                                        break;
                                }
                                switch(key){
                                    case 1:
                                        SetCursorPosition(13,15);
                                        SetColor(BACKGROUND_INTENSITY|BACKGROUND_GREEN);
                                        cout << "继续游戏";
                                        SetColor(7);
                                        SetCursorPosition(13,17);
                                        cout << "重新游戏";
                                        SetCursorPosition(13,19);
                                        cout << "退出游戏";
                                        break;
                                    case 2:
                                        SetCursorPosition(13,15);
                                        cout << "继续游戏";
                                        SetCursorPosition(13,17);
                                        SetColor(BACKGROUND_INTENSITY|BACKGROUND_GREEN);
                                        cout << "重新游戏";
                                        SetColor(7);
                                        SetCursorPosition(13,19);
                                        cout << "退出游戏";
                                        break;
                                    case 3:
                                        SetCursorPosition(13,15);
                                        cout << "继续游戏";
                                        SetCursorPosition(13,17);
                                        cout << "重新游戏";
                                        SetCursorPosition(13,19);
                                        SetColor(BACKGROUND_INTENSITY|BACKGROUND_GREEN);
                                        cout << "退出游戏";
                                        SetColor(7);
                                        break;
                                }
                            }else if(keyboard==27){
                                SetCursorPosition(13,15);
                                SetColor(7);
                                cout << "        ";
                                SetCursorPosition(13,17);
                                cout << "        ";
                                SetCursorPosition(13,19);
                                cout << "        ";
                                SetColor(7);
                                break;
                            } else if(keyboard==13){
                                SetCursorPosition(13,15);
                                SetColor(7);
                                cout << "        ";
                                SetCursorPosition(13,17);
                                cout << "        ";
                                SetCursorPosition(13,19);
                                cout << "        ";
                                SetColor(7);
                                if(key==1){
                                    break;
                                }else if(key==2){
                                    game=false;
                                    break;
                                }else if(key==3){
                                    restart=false;
                                    game=false;
                                    break;
                                }
                            }
                        }

                        break;
                }
            }
            if(game==false){
                break;
            }
            if(i>=speed){
                ctetris.front().Clear();
                flag= ctetris.front().DownMove(cmap);
                ctetris.front().Print();
                i=0;
            }


            Sleep(speed_t);
            i++;
            if(!flag){
                flag=true;
                cmap.AddTetromino(ctetris.front());
                score+=cmap.GetScore();
                ctetris.pop_front();
                ctetris.push_back(Tetromino());
                Next();
                Set_Score_Level();
                if(cmap.GameOver()){
                    game=false;
                    break;

                }

            }
        }
        if(restart==false){
            exit(0);
        }
    }
}

void Controller::Next(){
    for(int i=0;i<4;i++){
        SetCursorPosition(14,4+i);
        cout << "        ";
    }
    Tetromino temp(14,4,ctetris.back().GetColor(),ctetris.back().GetType());
    temp.Print1();
}

void Controller::Set_Score_Level(){
    SetCursorPosition(14,13);
    cout << score;
    SetCursorPosition(14,10);
    cout << score/10;
    speed=40-(score/10)*1;
}
