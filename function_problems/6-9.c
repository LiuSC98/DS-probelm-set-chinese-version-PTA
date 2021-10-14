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
void InorderTraversal( BinTree BT );
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}
/* 你的代码将被嵌在这里 */

void InorderTraversal( BinTree BT ){
    if(BT){
        if(BT->Left) InorderTraversal(BT->Left);
        printf(" %c",BT->Data);
        if(BT->Right) InorderTraversal(BT->Right);
    }
}

void PreorderTraversal( BinTree BT ){
    if (BT)
    {
        printf(" %c",BT->Data);
        if(BT->Left) PreorderTraversal(BT->Left);
        if(BT->Right) PreorderTraversal(BT->Right);
    }
}

void PostorderTraversal( BinTree BT ){
    if (BT)
    {
        if(BT->Left) PostorderTraversal(BT->Left);
        if(BT->Right) PostorderTraversal(BT->Right);
        printf(" %c",BT->Data);
    }
}


typedef struct queueNode* Ptr2QNode;
struct queueNode{
    BinTree BTNode;
    Ptr2QNode next;
};


void LevelorderTraversal( BinTree BT ){
    Ptr2QNode Qhead=malloc(sizeof(struct queueNode));
    Qhead->BTNode=BT;
    Qhead->next=NULL;
    Ptr2QNode Qtail=Qhead,tempNode;
    while (Qhead)
    {
        if(Qhead->BTNode){
            printf(" %c",Qhead->BTNode->Data);
            if(Qhead->BTNode->Left){
                tempNode=malloc(sizeof(struct queueNode));
                tempNode->BTNode=Qhead->BTNode->Left;
                tempNode->next=NULL;
                Qtail->next=tempNode;
                Qtail=tempNode;
            }
            if(Qhead->BTNode->Right){
                tempNode=malloc(sizeof(struct queueNode));
                tempNode->BTNode=Qhead->BTNode->Right;
                tempNode->next=NULL;
                Qtail->next=tempNode;
                Qtail=tempNode;
            }
        }
        Qhead=Qhead->next;
    }
}