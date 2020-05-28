#ifndef MAP_H
#define MAP_H


class map
{
public:
    map();
    void drawLine();//画一行，初始地图通过多次调用生成
    void changeGem();//宝石交换位置
    void eliminateGem();//消除
    void update();//发生更新时处理事件
    void moveDown();//下落
    bool help();//找一个可行的交换，没了就重新生成地图

};

#endif // MAP_H
