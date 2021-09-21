/*
7-12 排序 (25 分)
给定N个（长整型范围内的）整数，要求输出从小到大排序后的结果。

本题旨在测试各种不同的排序算法在各种数据情况下的表现。各组测试数据特点如下：
数据1：只有1个元素；
数据2：11个不相同的整数，测试基本正确性；
数据3：103个随机整数；
数据4：104个随机整数；
数据5：105个随机整数；
数据6：105个顺序整数；
数据7：105个逆序整数；
数据8：105个基本有序的整数；
数据9：105个随机正整数，每个数字不超过1000。

输入格式:
输入第一行给出正整数N（≤105），随后一行给出N个（长整型范围内的）整数，其间以空格分隔。

输出格式:
在一行中输出从小到大排序后的结果，数字间以1个空格分隔，行末不得有多余空格。

输入样例:
11
4 981 10 -17 0 -20 29 50 8 43 -5

输出样例:
-20 -17 -5 0 4 8 10 29 43 50 981

*/
#include <iostream>
#include <iomanip>
using namespace std;
#define MAXSIZE 100000

void bubbleSort(long arr[],int N){
    long swaptemp;
    bool flag=0;
    for (int i = 0; i < N-1; i++)
    {
        flag=0;
        for(int j = N-1; j> i; j--){
            if(arr[j]<arr[j-1])
            {
                swaptemp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=swaptemp;
                flag=1;
            }
        }
        if (!flag) break;
    }

    for (int i = 0; i < N; i++)
    {
        if (i) cout<<' ';
        cout<< arr[i];
    }
    cout<<endl;
}

void selectSort(long arr[],int N){
    int minIndex;
    long swapTemp;
    
    for (int i = 0; i < N-1; i++)
    {
        minIndex = i;
        for (int j = i; j < N; j++)
        {
            if(arr[j]<arr[minIndex]) minIndex=j;
        }
        swapTemp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = swapTemp;
    }
    for (int i = 0; i < N; i++)
    {
        if (i) cout<<' ';
        cout<< arr[i];
    }
    cout<<endl;
}

void insertSort(long arr[],int N){
    long temp;
    
    for (int i = 1; i < N; i++)
    {
        temp= arr[i];
        int j;
        for (j = i; j>0 && arr[j-1]>temp; j--)
        {
            arr[j]=arr[j-1];
        }
        arr[j]=temp;
    }

    for (int i = 0; i < N; i++)
    {
        if (i) cout<<' ';
        cout<< arr[i];
    }
    cout<<endl;
}


void ShellSort(long arr[],int N){ 
    const int sedgewick[]={260609,64769,16001,3905,929,505,209,109,41,19,5,1,0}; //sedgewick serial:  4^n-3*2^n+1
    int si=0;
    while (si>=N) si++;
    int gap,temp;

    for(gap=sedgewick[si];gap>0;gap=sedgewick[++si])
    {
        for (int i = gap; i < N; i++)
        {
            int j;
            temp=arr[i];
            for (j = i; j >=gap && arr[j-gap]>temp ; j-=gap)
            {
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i) cout<<' ';
        cout<< arr[i];
    }
    cout<<endl;

}

void heapSort(int arr[],int N){
    typedef struct Node *Ptr2Node;
    struct Node{
        int val;
        Ptr2Node left,right;
    };
}




int main(){
    int N;
    cin >> N;
    long arr0[MAXSIZE],arr1[MAXSIZE],arr2[MAXSIZE],arr3[MAXSIZE];
    for (int i = 0; i < N; i++)
    {
        cin >> arr0[i];
        arr1[i]=arr2[i]=arr3[i]=arr0[i];
    }
    
    //selectSort(arr0,N);
    //insertSort(arr1,N);
    //bubbleSort(arr2,N);
    ShellSort(arr3,N);
    return 0;
}