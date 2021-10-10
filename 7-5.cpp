/*
7-5 堆中的路径 (25 分)
将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。

输入格式:
每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、以及需要打印的路径条数。下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。最后一行给出M个下标。

输出格式:
对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。

输入样例:
5 3
46 23 26 24 10
5 4 3

输出样例:
24 23 10
46 23 10
26 10

*/

#include <iostream>
#include <algorithm>
using namespace std;


void up(int start,int heap[]){
    int now=heap[start];
    while(start>0){
        if(now<heap[(start-1)/2]){
            heap[start]=heap[(start-1)/2];
            start=(start-1)/2;
        }
        else break;
    }
    heap[start]=now;
}

void print2Root(int start,int heap[]){
    bool flag=0;
    while(start>0){
        if (flag) cout<<' ';
        else flag=1;
        cout<<heap[start];
        start=(start-1)/2;
    }
    if (flag) cout<<' ';
    cout<<heap[0]<<endl;
}

int main(){
    int N,M;
    cin>>N>>M;
    int *minHeap=new int[N];

    for (int i = 0; i < N; i++)
    {
        cin>>minHeap[i];
        up(i,minHeap);
    }
    
   
    int index;
    for (int i = 0; i < M; i++)
    {
        cin>>index;
        if(index<1||index>N) continue;
        print2Root(--index,minHeap);
    }
    
    delete[] minHeap;
    return 0;
}