## 6-0 两个有序链表序列的合并 (15 分)
本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。

***函数接口定义：***
``` C
List Merge( List L1, List L2 );
```
其中List结构定义如下：
``` C
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */
```
L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；函数Merge要将L1和L2合并为一个非递减的整数序列。应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。

***裁判测试程序样例：***
``` C
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
```
***输入样例：***

    3
    1 3 5
    5
    2 4 6 8 10

***输出样例：***

    1 2 3 4 5 6 8 10 
    NULL
    NULL

## 6-1 单链表逆转 (20 分)
本题要求实现一个函数，将给定的单链表逆转。

***函数接口定义：***
```C
List Reverse( List L );
```
其中`List`结构定义如下：
```C
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */
```
`L`是给定单链表，函数`Reverse`要返回被逆转后的链表。

***裁判测试程序样例：***
```C
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Reverse( List L );

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
```
***输入样例：***

    5
    1 3 4 5 2

***输出样例：***

    1
    2 5 4 3 1

## 6-2 顺序表操作集 (20 分)
本题要求实现顺序表的操作集。

***函数接口定义：***  
```C
List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );
```
其中List结构定义如下：
```C
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};
```
各个操作函数的定义为：

`List MakeEmpty()`：创建并返回一个空的线性表；  

`Position Find( List L, ElementType X )`：返回线性表中`X`的位置。若找不到则返回`ERROR`；

`bool Insert( List L, ElementType X, Position P )`：将`X`插入在位置`P`并返回`true`。若空间已满，则打印“FULL”并返回`false`；如果参数`P`指向非法位置，则打印“ILLEGAL POSITION”并返回`false`；  

`bool Delete( List L, Position P )`：将位置`P`的元素删除并返回`true`。若参数`P`指向非法位置，则打印“POSITION P EMPTY”（其中`P`是参数值）并返回`false`。

***裁判测试程序样例：***
```C
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}

/* 你的代码将被嵌在这里 */
```
***输入样例：***

    6
    1 2 3 4 5 6
    3
    6 5 1
    2
    -1 6

***输出样例：***

    FULL Insertion Error: 6 is not in.
    Finding Error: 6 is not in.
    5 is at position 0.
    1 is at position 4.
    POSITION -1 EMPTY Deletion Error.
    FULL Insertion Error: 0 is not in.
    POSITION 6 EMPTY Deletion Error.
    FULL Insertion Error: 0 is not in.

## 6-3 求链式表的表长 (10 分)
本题要求实现一个函数，求链式表的表长。

***函数接口定义：***
```C
int Length( List L );
```
其中`List`结构定义如下：
```C
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;
```
`L`是给定单链表，函数`Length`要返回链式表的长度。

***裁判测试程序样例：***
```C
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length( List L );

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}

/* 你的代码将被嵌在这里 */
```
***输入样例：***
    
    1 3 4 5 2 -1

***输出样例：***

    5

## 6-4 链式表的按序号查找 (10 分)
本题要求实现一个函数，找到并返回链式表的第K个元素。

***函数接口定义：***
```C
ElementType FindKth( List L, int K );
```
其中`List`结构定义如下：
```C
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;
```
`L`是给定单链表，函数`FindKth`要返回链式表的第`K`个元素。如果该元素不存在，则返回`ERROR`。

***裁判测试程序样例：***
```C
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth( List L, int K );

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if ( X!= ERROR )
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

/* 你的代码将被嵌在这里 */
```
***输入样例：***

    1 3 4 5 2 -1
    6
    3 6 1 5 4 2

***输出样例：***

    4 NA 1 2 5 3 

## 6-5 链式表操作集 (20 分)
本题要求实现链式表的操作集。

***函数接口定义：***
```C
Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );
```
其中`List`结构定义如下：
```C
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
```
各个操作函数的定义为：

- `Position Find( List L, ElementType X )`：返回线性表中首次出现X的位置。若找不到则返回`ERROR`；

- `List Insert( List L, ElementType X, Position P )`：将`X`插入在位置`P`指向的结点之前，返回链表的表头。如果参数P指向非法位置，则打印“Wrong Position for Insertion”，返回`ERROR`；

- `List Delete( List L, Position P )`：将位置`P`的元素删除并返回链表的表头。若参数`P`指向非法位置，则打印“Wrong Position for Deletion”并返回`ERROR`。

***裁判测试程序样例：***
```C
#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
```
***输入样例：***

    6
    12 2 4 87 10 2
    4
    2 12 87 5

***输出样例：***

    2 is found and deleted.
    12 is found and deleted.
    87 is found and deleted.
    Finding Error: 5 is not in.
    5 is inserted as the last element.
    Wrong Position for Insertion
    Wrong Position for Deletion
    10 4 2 5 

##
## 6-10 二分查找 (20 分)
本题要求实现二分查找算法。

***函数接口定义：***

``` C
Position BinarySearch( List L, ElementType X );
```
其中List结构定义如下：
``` C
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};
```
`L`是用户传入的一个线性表，其中`ElementType`元素可以通过>、==、<进行比较，并且题目保证传入的数据是递增有序的。函数`BinarySearch`要查找`X`在`Data`中的位置，即数组下标（注意：元素从下标1开始存储）。找到则返回下标，否则返回一个特殊的失败标记`NotFound`。

***裁判测试程序样例：***
``` C
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
```
***输入样例1：***

    5
    12 31 55 89 101
    31

***输出样例1：***

    2

***输入样例2：***

    3
    26 78 233
    31

***输出样例2：***

    0


## 6-12 二叉搜索树的操作集 (30 分)
本题要求实现给定二叉搜索树的5种常用操作。

***函数接口定义：***
``` C
BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );
```
其中`BinTree`结构定义如下：
``` C
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};
```
- 函数`Insert`将`X`插入二叉搜索树`BST`并返回结果树的根结点指针；
- 函数`Delete`将`X`从二叉搜索树`BST`中删除，并返回结果树的根结点指针；如果`X`不在树中，则打印一行`Not Found`并返回原树的根结点指针；
- 函数`Find`在二叉搜索树`BST`中找到`X`，返回该结点的指针；如果找不到则返回空指针；
- 函数`FindMin`返回二叉搜索树`BST`中最小元结点的指针；
- 函数`FindMax`返回二叉搜索树`BST`中最大元结点的指针。

***裁判测试程序样例：***
``` C
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */
```
***输入样例：***

    10
    5 8 6 2 4 1 0 10 9 7
    5
    6 3 10 0 5
    5
    5 7 0 10 3

***输出样例：***

    Preorder: 5 2 1 0 4 8 6 7 10 9
    6 is found
    3 is not found
    10 is found
    10 is the largest key
    0 is found
    0 is the smallest key
    5 is found
    Not Found
    Inorder: 1 2 4 6 8 9