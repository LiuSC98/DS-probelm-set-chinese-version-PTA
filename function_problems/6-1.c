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


List Reverse( List L ){
    if(!L || !L->Next) return L;
    List L1=L->Next;
    L->Next=NULL;
    List L2=L1->Next;

    while (L2)
    {
        L1->Next=L;
        L=L1;
        L1=L2;
        L2=L2->Next;        
    }
    L1->Next=L;
    L=L1;
    return L;
}