#ifndef MAP_H
#define MAP_H

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>

#define SIZE_OF_LINE 8
#define SIZE_OF_VERTICAL 8
#define NUM_OF_GEM 4

class Map
{
public:
    Map();
    int map[SIZE_OF_VERTICAL][SIZE_OF_LINE]={0};
    void initMap();
    int* drawLine();//画一行，初始地图通过多次调用生成
    void changeGem();//宝石交换位置
    void eliminateGem();//消除
    void update();//发生更新时处理事件
    void moveDown();//下落
    bool help();//找一个可行的交换，没了就重新生成地图

};

#endif // MAP_H
