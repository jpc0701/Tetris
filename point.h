#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point{
public:
    Point(const int x,const int y,const int color):x(x),y(y){
        int temp1=color << 4;
        this->color=temp1+color+8;
    }
    void Print();//��ӡ����
    void Clear();//�����
    void ChangePosition(const int x,const int y);//�ı���λ��
    int GetX();//��ȡx����
    int GetY();//��ȡy����
    int GetColor();//��ȡ��ɫ
private:
    int x,y,color;//�������ɫ
};

#endif // POINT_H_INCLUDED
