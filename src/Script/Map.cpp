#include "../Header/Map.hpp"
#include <stdio.h>

Map::Map(){
    BlockPercentage BPer;
    
    switch (0)
    {
    case 0: //通常 4P
        SetBlockData(DefaultMap);
        break;
    
    default:
        break;
    }
}

void Map::SetBlockData(int mapData[]) {
    for (int i = 0; i < Block_Count; i++)
    {
        //BlockTypeの設定
        switch (mapData[i])
        {
        case 0:
                break;
        case 1: // ランダム
            switch (RandBlock())
            {
            case 1:case 2: case 3: case 4: case 5:
                block[i].blockType = Bleakable;
                break;
            case 6:
                block[i].blockType = Air;
                break;
            case 7: case 8:
                block[i].blockType = InItem;
                break;
            default:
                break;
            }
            break;
        case 2: // 破壊不可能
                block[i].blockType = UnBreakable;
                break;
        case 3: // 空気
                block[i].blockType = Air;
                break;
        default:
                break;
        }
        //Posの設定
        block[i].Pos = {i/MAP_X_SideLength ,i%MAP_X_SideLength ,Block_PixelSize ,Block_PixelSize};
    }
};