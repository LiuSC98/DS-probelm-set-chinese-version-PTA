/*
7-13 统计工龄 (20 分)
给定公司N名员工的工龄，要求按工龄增序输出每个工龄段有多少员工。

输入格式:
输入首先给出正整数N（≤10^5），即员工总人数；随后给出N个整数，即每个员工的工龄，范围在[0, 50]。

输出格式:
按工龄的递增顺序输出每个工龄的员工个数，格式为：“工龄:人数”。每项占一行。如果人数为0则不输出该项。

输入样例:
8
10 2 0 5 7 2 5 2

输出样例:
0:1
2:3
5:2
7:1
10:1

*/


#include <iostream>
#include <algorithm>

using namespace std;

template <typename T>
void insertSort(T arr[],int N){
    if(N<=1) return;
    T temp;
    int j;
    for (int i = 1; i < N; i++)
    {
        temp=arr[i];
        for (j = i; j>0 && arr[j-1]>temp; j--)
        {
            arr[j]=arr[j-1];
        }
        arr[j]=temp;
    }
    
}

template <typename T>
T mid3(T arr[],int left,int right){
    int mid=(left+right)/2;
    if (arr[left]>arr[mid]) swap(arr[left],arr[mid]);
    if (arr[left]>arr[right]) swap(arr[left],arr[right]);  
    if (arr[mid]>arr[right]) swap(arr[right],arr[mid]);
    swap(arr[mid],arr[right-1]);
    return arr[right-1];
}


template <typename T>
void quicksort(T arr[],int left,int right){
    if(left>=right) return;
    else if(right-left>20){
        T pivot = mid3(arr,left,right);
        int low=left,high=right-1;
        while(1){
            while (arr[++low]<pivot);
            while (arr[--high]>pivot);
            if (low<high) swap(arr[low],arr[high]);
            else break;
        }
        swap(arr[low],arr[right-1]);
        quicksort(arr,left,low-1);
        quicksort(arr,low+1,right);
    }
    else{
        insertSort(arr+left,right-left+1);
    }
}

template <typename T>
void Qsort(int N,T arr[]){
    quicksort(arr,0,N-1);
}

int main(){
    int N;
    cin>>N;
    int *arr=new int[N];
    for (int i = 0; i < N; i++)
    {
        cin>>arr[i];
    }
    Qsort(N,arr);
    //sort(arr,arr+N);
    int age=arr[0],cnt=0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i]==age) cnt++;
        else {
            cout<<age<<':'<<cnt<<endl;
            age=arr[i];
            cnt=1;
        }
    }
    cout<<age<<':'<<cnt<<endl;
    delete[] arr;
    return 0;
}