#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point{
public:
    Point(const int x,const int y,const int color):x(x),y(y){
        int temp1=color << 4;
        this->color=temp1+color+8;
    }
    void Print();//打印出点
    void Clear();//清理点
    void ChangePosition(const int x,const int y);//改变点的位置
    int GetX();//获取x坐标
    int GetY();//获取y坐标
    int GetColor();//获取颜色
private:
    int x,y,color;//坐标和颜色
};

#endif // POINT_H_INCLUDED
