#ifndef Def_BG
#define Def_BG

#include <time.h>
#include <iostream>
#include "SDL2.hpp"
#include "Item.hpp"

#define MAX_MAP_TYPE 16

#define Block_PixelSize 48

//X方向のブロック数(15) + 端(2)
#define MAP_X_SideLength 17
//Y方向のブロック数(9) + 端(2)
#define MAP_Y_SideLength 11

#define Block_Count (MAP_X_SideLength * MAP_Y_SideLength)

class Map
{
    // ----- 定数、定義 ----- //
    private:
    int DefaultMap[Block_Count]={
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
        2,3,3,1,1,1,1,1,1,1,1,1,1,1,3,3,2,
        2,3,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,
        2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,
        2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
        2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,
        2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
        2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,
        2,3,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,
        2,3,3,1,1,1,1,1,1,1,1,1,1,1,3,3,2,
        2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    };
    struct BlockPercentage
    {
        const int All=8;
        const int Bleackable=5;
        const int Air=1;
        const int InItem=2;
    }blockPercentage;

    struct Block {
        BlockType blockType;
        Item item;
        // 座標
        SDL_Rect Pos;
    }block[Block_Count];
    
    public:

    // ----- 変数 ----- //
    private:

    public:
    int MapNum;

    // ----- 関数 ----- //
    private:
    inline void initRand() { srand((unsigned int) time(NULL)); }
    inline int RandBlock() { return rand() % blockPercentage.All + 1; }
        
    public:
    // ブロックの描画
    void DrawBlocks();
    // 侵入不可判定
    bool Invasive(SDL_Rect rect){

    }
    Map(){};
    ~Map();
    void SetBlockData(int mapData[]);
    void RenderBlocks(SDL_Renderer* renderer){
        for (int i = 0; i < Block_Count; i++)
        {
            switch (block[i].blockType)
            {
            case Bleakable: case InItem:
                /* code */
                break;
            case UnBreakable:
                break;
            case Air:
                break;
            default:
                break;
            }
        }
    }
};

enum BlockType{
    // 破壊可能(アイテムなし)
    Bleakable,
    // 破壊可能(アイテムあり)
    InItem,
    // 破壊不可能
    UnBreakable,
    // 空気
    Air,
};

#endif