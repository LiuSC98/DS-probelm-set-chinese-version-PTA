/*
7-11 关键活动 (30 分)
假定一个工程项目由一组子任务构成，子任务之间有的可以并行执行，有的必须在完成了其它一些子任务后才能执行。
“任务调度”包括一组子任务、以及每个子任务可以执行所依赖的子任务集。

比如完成一个专业的所有课程学习和毕业设计可以看成一个本科生要完成的一项工程，各门课程可以看成是子任务。
有些课程可以同时开设，比如英语和C程序设计，它们没有必须先修哪门的约束；
有些课程则不可以同时开设，因为它们有先后的依赖关系，比如C程序设计和数据结构两门课，必须先学习前者。

但是需要注意的是，对一组子任务，并不是任意的任务调度都是一个可行的方案。
比如方案中存在“子任务A依赖于子任务B，子任务B依赖于子任务C，子任务C又依赖于子任务A”，那么这三个任务哪个都不能先执行，这就是一个不可行的方案。

任务调度问题中，如果还给出了完成每个子任务需要的时间，则我们可以算出完成整个工程需要的最短时间。
在这些子任务中，有些任务即使推迟几天完成，也不会影响全局的工期；但是有些任务必须准时完成，否则整个项目的工期就要因此延误，这种任务就叫“关键活动”。

请编写程序判定一个给定的工程项目的任务调度是否可行；如果该调度方案可行，则计算完成整个工程项目需要的最短时间，并输出所有的关键活动。

输入格式:
输入第1行给出两个正整数N(≤100)和M，其中N是任务交接点（即衔接相互依赖的两个子任务的节点，
例如：若任务2要在任务1完成后才开始，则两任务之间必有一个交接点）的数量。交接点按1~N编号，M是子任务的数量，依次编号为1~M。
随后M行，每行给出了3个正整数，分别是该任务开始和完成涉及的交接点编号以及该任务所需的时间，整数间用空格分隔。

输出格式:
如果任务调度不可行，则输出0；否则第1行输出完成整个工程项目需要的时间，
第2行开始输出所有关键活动，每个关键活动占一行，按格式“V->W”输出，其中V和W为该任务开始和完成涉及的交接点编号。
关键活动输出的顺序规则是：任务开始的交接点编号小者优先，起点编号相同时，与输入时任务的顺序相反。

输入样例:
7 8
1 2 4
1 3 3
2 4 5
3 4 3
4 5 1
4 6 6
5 7 5
6 7 2

输出样例:
17
1->2
2->4
4->6
6->7

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxN 100
#define infinite 65535


typedef struct Node* Ptr2Node;
struct Node{
    int val;
    Ptr2Node next;
};

typedef struct Qnode *Queue;
struct Qnode{
    Ptr2Node head,tail;
};


Queue EnQ(int x,Queue Q){
    Ptr2Node tempNode=(Ptr2Node)malloc(sizeof(struct Node));
    tempNode->val=x;
    tempNode->next=NULL;

    if (!Q->head)
    {
        Q->head=Q->tail=tempNode;
    }else{
        Q->tail->next=tempNode;
        Q->tail=tempNode;
    }
    return Q;
}

int DeQ( Queue Q ){
    if(!Q->head) return -1;
    int v=Q->head->val;
    Ptr2Node tempNode=Q->head;
    Q->head=Q->head->next;
    free(tempNode);
    return v;
}


int topologicalSort(int costMatrix[][maxN],int inDegree[],int outDegree[],int N,Ptr2Node stack[]){
    Queue Q=(Queue)malloc(sizeof(struct Qnode));
    Q->head=Q->tail=NULL;
    int cnt=0,v,earliest[maxN]={0,},latest[maxN];
    bool collected[maxN]={0,};

    for(int i=0;i<N;i++){
        latest[i]=infinite;
        if(inDegree[i]==0) EnQ(i,Q);
    }

    while (Q->head)
    {
        v=DeQ(Q);
        cnt++;
        for (int i = 0; i < N; i++)
        {
            if (costMatrix[v][i]<infinite)
            {
                if (earliest[v]+costMatrix[v][i]>earliest[i]) earliest[i]=earliest[v]+costMatrix[v][i]; 
                if(--inDegree[i]==0) EnQ(i,Q);
            }
        }
    }
    if(cnt!=N){
        printf("0");
        return -1;
    }

    int maxCost=0;
    for (int i = 0; i < N; i++)
    {
        if(outDegree[i]==0){
            //latest[i]=earliest[i];
            EnQ(i,Q);
            if(maxCost<earliest[i]) maxCost=earliest[i];
        }
    }
    printf("%d\n",maxCost);

    for (int i = 0; i < N; i++)
    {
        if(outDegree[i]==0){
            latest[i]=maxCost;
        }
    }
    
   
    
    while (Q->head)
    {
        v=DeQ(Q);
        for (int i = 0; i < N; i++)
        {
            if(costMatrix[i][v]<infinite){
                if (latest[v]-costMatrix[i][v]<latest[i]) latest[i]=latest[v]-costMatrix[i][v]; 
                if(--outDegree[i]==0) EnQ(i,Q);
            }
        }
        
    }

    Ptr2Node tempNode;
    int tempV;

    for(int i=0;i<N;i++){
        if (earliest[i]==latest[i])
        {
            tempNode=stack[i];
            while (tempNode)
            {
                tempV=tempNode->val;
                if(earliest[tempV]==latest[tempV] && earliest[i]+costMatrix[i][tempV]==earliest[tempV]){
                    printf("%d->%d\n",i+1,tempV+1);
                }
                tempNode=tempNode->next;
            }
        }
    }
    return 1;
}


int main(){
    int N,M,inDegree[maxN],outDegree[maxN],costMatrix[maxN][maxN];

    Ptr2Node stack[maxN],tempNode;
    scanf("%d %d",&N,&M);

    for (int i = 0; i < N; i++)
    {
        stack[i]=NULL;
        inDegree[i]=0;
        outDegree[i]=0;
        for (int j = i; j < N; j++)
        {
            costMatrix[i][j]=costMatrix[j][i]=infinite;
        }
    }
    
    int m1,m2,t;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d",&m1,&m2,&t);
        costMatrix[m1-1][m2-1]=t;
        outDegree[m1-1]++;
        inDegree[m2-1]++;
        tempNode = (Ptr2Node)malloc(sizeof(struct Node));
        tempNode->val=m2-1;
        if(!stack[m1-1]){
            stack[m1-1]=tempNode;
            stack[m1-1]->next=NULL;
        }else{
            tempNode->next=stack[m1-1];
            stack[m1-1]=tempNode;
        }
        
    }

    topologicalSort(costMatrix,inDegree,outDegree,N,stack);
    
    return 0;
}