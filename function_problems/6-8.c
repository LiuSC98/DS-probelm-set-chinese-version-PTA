#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}
/* 你的代码将被嵌在这里 */

int max(int a,int b){
    return a>b?a:b;
}
int GetHeight( BinTree BT ){
    if(!BT) return 0;
    if(BT) 
        return 1+max(GetHeight(BT->Left),GetHeight(BT->Right));
}