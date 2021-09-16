/*
7-10 公路村村通 (30 分)
现有村落间道路的统计数据表中，列出了有可能建设成标准公路的若干条道路的成本，
求使每个村落都有公路连通所需要的最低成本。

输入格式:
输入数据包括城镇数目正整数N（≤1000）和候选道路数目M（≤3N）；
随后的M行对应M条道路，每行给出3个正整数，分别是该条道路直接连通的两个城镇的编号以及该道路改建的预算成本。
为简单起见，城镇从1到N编号。

输出格式:
输出村村通需要的最低成本。如果输入数据不足以保证畅通，则输出−1，表示需要建设更多公路。

输入样例:
6 15
1 2 5
1 3 3
1 4 7
1 5 4
1 6 2
2 3 4
2 4 6
2 5 2
2 6 6
3 4 6
3 5 1
3 6 1
4 5 10
4 6 8
5 6 3

输出样例:
12
*/

#include <stdio.h>
#define maxN 1000
#define infinite 65535

int roadCost[maxN][maxN],cost2s[maxN],parent[maxN],MST[maxN];

int findMinIndex(int N){
    int minValue=infinite;
    int minIndex=-1;
    for(int i=0;i<N;i++){
        if(!MST[i]&&cost2s[i]<minValue){
            minValue=cost2s[i];
            minIndex=i;
        }
    }
    return minIndex;
}

int minSpanTr(int N){
    int v;
    while(1){
        v=findMinIndex(N);
        if(v==-1) break;
        MST[v]=1;
        cost2s[v]=0;
        for(int w=0;w<N;w++){
            if(roadCost[v][w]<cost2s[w]){
                cost2s[w]=roadCost[v][w];
                parent[w]=v;
            }
        }
    }
    int costSum=0;
    for(int i=0;i<N;i++){
        if (!MST[i]) return -1;
        costSum+=roadCost[i][parent[i]];
    }
    return costSum;
    
}


int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    for (int i = 0; i < N; i++)
    {
        MST[i]=0;
        cost2s[i]=infinite;
        parent[i]=i;
        roadCost[i][i]=0;
        for(int j=i+1;j<N;j++)
        {
            roadCost[i][j]=roadCost[j][i]=infinite;
        }
    }
    cost2s[0]=0;
    int v1,v2,cost;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d",&v1,&v2,&cost);
        roadCost[v1-1][v2-1]=roadCost[v2-1][v1-1]=cost;
    }
    printf("%d",minSpanTr(N));
    return 0;
}