#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize );
bool Push( Stack S, ElementType X, int Tag );
ElementType Pop( Stack S, int Tag );

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Tag ); /* details omitted */

int main()
{
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while ( !done ) {
        switch( GetOp() ) {
        case push: 
            scanf("%d %d", &Tag, &X);
            if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
            break;
        case pop:
            scanf("%d", &Tag);
            X = Pop(S, Tag);
            if ( X==ERROR ) printf("Stack %d is Empty!\n", Tag);
            break;
        case end:
            PrintStack(S, 1);
            PrintStack(S, 2);
            done = 1;
            break;
        }
    }
    return 0;
}

/* 你的代码将被嵌在这里 */
bool isEmpty(Stack S,int Tag){
    if(Tag==1){
        if(S->Top1==-1) return true;
        return false;
    }
    else if(Tag==2){
        if(S->Top2==S->MaxSize) return true;
        return false;
    }
    return true;
}

bool isFull(Stack S){
    if((S->Top1+1)==S->Top2) return true;
    return false;
}


Stack CreateStack( int MaxSize ){
    Stack S=(Stack)malloc(sizeof(struct SNode));
    S->MaxSize=MaxSize;
    S->Top1=-1;
    S->Top2=MaxSize;
    S->Data=(ElementType *)malloc(sizeof(ElementType)*MaxSize);
    for (int i = 0; i < MaxSize; i++) 
        S->Data[i]=ERROR;
    return S;
}

bool Push( Stack S, ElementType X, int Tag ){
    if(isFull(S)){
        printf("Stack Full\n");
        return false;
    }
    if (Tag==1) S->Data[++S->Top1]=X;
    else if(Tag==2) S->Data[--S->Top2]=X;
    return true;
}

ElementType Pop( Stack S, int Tag ){
    if(isEmpty(S,Tag)){
        printf("Stack %d Empty\n",Tag);
        return ERROR;
    }

    if(Tag==1){
        return S->Data[S->Top1--];
    }
    else if(Tag==2){
        return S->Data[S->Top2++];
    }
}