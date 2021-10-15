/*
7-6 列出连通集 (25 分)
给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N−1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

输入格式:
输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。

输出格式:
按照"{ v1 v2... vk}"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

输入样例:
8 6
0 7
0 1
2 0
4 1
2 4
3 5

输出样例:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }

*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Node* Ptr2Node;
struct Node{
    int val;
    Ptr2Node next;
};
typedef Ptr2Node Queue,Stack;

void BFS(bool *M, int N){
    if(N<1) return;
    bool *visited=new bool[N];
    for (int i = 0; i < N; i++) visited[i]=0;
    
    Queue Qhead=NULL,Qend=NULL,Qtemp=NULL;
    for (int i = 0; i < N; i++)
    {
        if(!visited[i]){
            visited[i]=1;
            Qhead=new Node;
            Qhead->val=i; Qhead->next=NULL; Qend=Qhead;
            cout<<'{';
            while (Qhead)
            {
                cout<<' '<<Qhead->val;
                for (int j = 0; j < N; j++)
                {
                    if(!visited[j] && M[Qhead->val*N+j]){
                        visited[j]=1;
                        Qend->next=new Node;
                        Qend=Qend->next;
                        Qend->val=j; Qend->next=NULL;
                    }
                }
                Qtemp=Qhead;
                Qhead=Qhead->next;
                delete Qtemp;
            }
            Qtemp=Qend=Qhead=NULL;
            cout<<" }"<<endl;
        }
    }
}

void DFS(bool *M, int N){
    if(N<1) return;
    bool *visited=new bool[N];
    bool *printed=new bool[N];
    for (int i = 0; i < N; i++) printed[i]=visited[i]=0;
    
    Stack StackTop=NULL,StackTemp=NULL;
    for (int i = 0; i < N; i++)
    {
        if(!visited[i]){
            visited[i]=1;
            StackTop=new Node;
            StackTop->val=i; StackTop->next=NULL;
            cout<<'{';
            while (StackTop)
            {
                int val=StackTop->val;
                if(!printed[val]){
                    cout<<' '<<val;
                    printed[val]=1;
                }
                int j=0;
                for (j = 0; j < N; j++)
                {
                    if(!visited[j] && M[val*N+j]){
                        visited[j]=1;
                        StackTemp=new Node;
                        StackTemp->val=j;
                        StackTemp->next=StackTop;
                        StackTop=StackTemp;
                        break;
                    }
                }
                if(j==N){
                    StackTemp=StackTop;
                    StackTop=StackTop->next;
                    delete StackTemp;
                }
            }
            StackTemp=StackTop=NULL;
            cout<<" }"<<endl;
        }
    }
    
}

int main(){
    int N,E;
    cin>>N>>E;
    bool* M=new bool[N*N];
    for (int i = 0; i < N; i++)
    {
        M[i*N+i]=0;
        for (int j = i+1; j < N; j++)
        {
            M[i*N+j]=M[j*N+i]=0;
        }
    }
    
    int v1,v2;

    for (int i = 0; i < E; i++)
    {
        cin>>v1>>v2;
        M[v1*N+v2]=M[v2*N+v1]=1;
    }
    DFS(M,N);
    BFS(M,N);
    

    return 0;
}

