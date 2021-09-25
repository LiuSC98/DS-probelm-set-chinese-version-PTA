/*
7-14 电话聊天狂人 (25 分)
给定大量手机用户通话记录，找出其中通话次数最多的聊天狂人。

输入格式:
输入首先给出正整数N（≤10^5），为通话记录条数。随后N行，每行给出一条通话记录。
简单起见，这里只列出拨出方和接收方的11位数字构成的手机号码，其中以空格分隔。

输出格式:
在一行中给出聊天狂人的手机号码及其通话次数，其间以空格分隔。
如果这样的人不唯一，则输出狂人中最小的号码及其通话次数，并且附加给出并列狂人的人数。

输入样例:
4
13005711862 13588625832
13505711862 13088625832
13588625832 18087925832
15005713862 13588625832

输出样例:
13588625832 3

*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;


typedef struct hashNode *Ptr2node;
struct hashNode{
    string phoneNum;
    int cnt;
    Ptr2node next;
};

int getHash(string s,int d=13){
    int x=stoi(s.substr(6,5));
    return x%d;
}

bool isPrime(int N){
    if(N<2) return 0;
    if(N%2==0 && N!=2) return 0;
    for (int i = 3; i < sqrt(N); i++)
    {
        if(N%i==0) return 0;
    }
    return 1;
}
int minPrime(int N){
    while (!isPrime(N)) N++;
    return N;
}

void insertHashTable(Ptr2node *hashTable,string s,int index){
    Ptr2node currentNode=hashTable[index]->next;
    Ptr2node tempNode;
    if(!hashTable[index]->next){
        tempNode=new (struct hashNode);  
        tempNode->cnt=1;
        tempNode->next=NULL;
        tempNode->phoneNum=s;
        hashTable[index]->next=tempNode;
        return;
    }else{
        while (currentNode)
        {
            if(currentNode->phoneNum==s){
                currentNode->cnt++;
                return;
            }
            currentNode=currentNode->next;
        }
        tempNode=new (struct hashNode);  
        tempNode->cnt=1;
        tempNode->next=hashTable[index]->next;
        tempNode->phoneNum=s;
        hashTable[index]->next=tempNode;
        return;
    }
}

int find(Ptr2node *hashTable,string s,int p){
    Ptr2node currentNode;
    for (int i = 0; i < p; i++)
    {
        currentNode=hashTable[i];
        while (currentNode)
        {
            if(currentNode->phoneNum==s) return currentNode->cnt;
            currentNode=currentNode->next;
        }
    }
    return -1;
}

void findMax(Ptr2node *hashTable,int p){
    Ptr2node currentNode;
    int max=0,numMax=0;
    string maxS="";
    for (int i = 0; i < p; i++)
    {
        currentNode=hashTable[i];
        while (currentNode)
        {
            if(currentNode->cnt>max){
                max=currentNode->cnt;
                numMax=1;
                maxS=currentNode->phoneNum;
            }
            else if(currentNode->cnt==max){
                numMax++;
                if(maxS>currentNode->phoneNum){
                    maxS=currentNode->phoneNum;
                }
            }
            currentNode=currentNode->next;
        }
    }
    cout<<maxS<<' '<<max;
    if(numMax>1) cout<<' '<<numMax;
}

int main(){
    int N,hash_res;
    cin>>N;
    int p=minPrime(2*N);
   
    Ptr2node *hashTable=new Ptr2node[p];
    for (int i = 0; i < p; i++)
    {
        hashTable[i]=new (struct hashNode);
        hashTable[i]->cnt=0;
        hashTable[i]->phoneNum="";
        hashTable[i]->next=NULL;
    }
    
    string s1,s2;
    for (int i = 0; i < N; i++)
    {
        cin>>s1>>s2;
        
        hash_res=getHash(s1,p);
        
        insertHashTable(hashTable,s1,hash_res);
        hash_res=getHash(s2,p);
        insertHashTable(hashTable,s2,hash_res);
    }
    findMax(hashTable,p);
    delete[] hashTable;
    return 0;
}