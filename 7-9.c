/*
7-9 旅游规划 (25 分)
有了一张自驾旅游路线图，你会知道城市间的高速公路长度、以及该公路要收取的过路费。
现在需要你写一个程序，帮助前来咨询的游客找一条出发地和目的地之间的最短路径。
如果有若干条路径都是最短的，那么需要输出最便宜的一条路径。

输入格式:
输入说明：输入数据的第1行给出4个正整数N、M、S、D，其中N（2≤N≤500）是城市的个数，
顺便假设城市的编号为0~(N−1)；M是高速公路的条数；S是出发地的城市编号；D是目的地的城市编号。
随后的M行中，每行给出一条高速公路的信息，
分别是：城市1、城市2、高速公路长度、收费额，中间用空格分开，数字均为整数且不超过500。
输入保证解的存在。

输出格式:
在一行里输出路径的长度和收费总额，数字间以空格分隔，输出结尾不能有多余空格。

Input Sample:
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20

Output Sample:
3 40

*/

#include<stdio.h>
#include<stdlib.h>

#define infinite 65535

struct DisPrice{
    int distance,price;
}cities[500][500];

void Dijkstra(int N,int start,int treminal){
    int collected[N],path[N],dist[N],cost[N];
    for(int i=0; i<N;i++){
        collected[i]=0;
        dist[i]=cities[start][i].distance;
        cost[i]=cities[start][i].price;
        if(dist[i]>0 && dist[i]<infinite) path[i]=start;
        else path[i]=-1;
    }
    collected[start]=1;
    int s=start,v;
    while (1)
    {
        int min=infinite;
        for(int i=0;i<N;i++){
            if(!collected[i] && dist[i]<min){
                min=dist[i];
                v=i;
            }
        }
        if(min==infinite) break;
        collected[v]=1;
        for (size_t i = 0; i < N; i++)
        {
            if(!collected[i]){
                if(dist[v]+cities[v][i].distance<dist[i]){
                    dist[i]=dist[v]+cities[v][i].distance;
                    cost[i]=cost[v]+cities[v][i].price;
                    path[i]=path[v];
                }
                else if(dist[v]+cities[v][i].distance==dist[i] && cost[i]>cost[v]+cities[v][i].price)
                {
                    cost[i]=cost[v]+cities[v][i].price;
                    path[i]=path[v];
                }
            }
            
        }
        
    }
    printf("%d %d",dist[treminal],cost[treminal]);
}

int main(){
    int N,M,S,D;
    scanf("%d %d %d %d",&N,&M,&S,&D);
    int city1,city2,Dis,Pri;
    for (int i = 0; i < N; i++)
    {
        cities[i][i].distance=cities[i][i].price=0;
        for(int j=i+1; j<N;j++){
            cities[i][j].distance=cities[j][i].distance=infinite;
            cities[i][j].price=cities[j][i].price=infinite;
        }
    }

    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d %d",&city1,&city2,&Dis,&Pri);
        cities[city1][city2].distance=cities[city2][city1].distance=Dis;
        cities[city1][city2].price=cities[city2][city1].price=Pri;
    }
    Dijkstra(N,S,D);

    return 0;
}