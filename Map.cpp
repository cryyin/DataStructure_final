#include "Map.h"

Map::Map()
{
    srand((int)time(NULL));
}

int * Map::drawLine()
{
    int line[SIZE_OF_LINE];

    for(int i = 0; i < SIZE_OF_LINE; i++)
    {
        line[i] = rand() % (NUM_OF_GEM);
    }
    int *a=line;
    return a;
}

void Map::initMap()
{
    for(int i=0;i<SIZE_OF_VERTICAL;i++){
        for(int j=0;j<SIZE_OF_LINE;j++){
            int *line=drawLine();
            map[i][j]=*(line+j);
        }
    }
}
