/*
7-15 QQ帐户的申请与登陆 (25 分)
实现QQ新帐户申请和老帐户登陆的简化版功能。
最大挑战是：据说现在的QQ号码已经有10位数了。

输入格式:
输入首先给出一个正整数N(≤10^5)，随后给出N行指令。
每行指令的格式为：“命令符（空格）QQ号码（空格）密码”。
其中命令符为“N”（代表New）时表示要新申请一个QQ号，后面是新帐户的号码和密码；
命令符为“L”（代表Login）时表示是老帐户登陆，后面是登陆信息。
QQ号码为一个不超过10位、但大于1000（据说QQ老总的号码是1001）的整数。
密码为不小于6位、不超过16位、且不包含空格的字符串。

输出格式:
针对每条指令，给出相应的信息：

1）若新申请帐户成功，则输出“New: OK”；
2）若新申请的号码已经存在，则输出“ERROR: Exist”；
3）若老帐户登陆成功，则输出“Login: OK”；
4）若老帐户QQ号码不存在，则输出“ERROR: Not Exist”；
5）若老帐户密码错误，则输出“ERROR: Wrong PW”。

输入样例:
5
L 1234567890 myQQ@qq.com
N 1234567890 myQQ@qq.com
N 1234567890 myQQ@qq.com
L 1234567890 myQQ@qq
L 1234567890 myQQ@qq.com

输出样例:
ERROR: Not Exist
New: OK
ERROR: Exist
ERROR: Wrong PW
Login: OK

*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define MaxN 100000

bool isPrime(int n){
    if(n<2)return 0;
    if(n%2==0 && n!=2) return 0;
    for (int i = 3; i < sqrt(n); i++)
    {
        if(n%i==0) return 0;
    }
    return 1;

}
int minPrime(int n){
    if(n==1) return 2;
    if(n%2==0 && n!=2) n++;
    while (!isPrime(n))
    {
        n+=2;
    }
    return n;
}


typedef struct node *Ptr2Node;
struct node{
    string account;
    string PSW;
    Ptr2Node next;
};

struct hashTable{
    int tableSize;
    Ptr2Node *tableHead;
};

int hashing(string S,int size){
    int len=S.length();
    if(len>5){
        return stoi(S.substr(len-6,6))%size;
    }
    return stoi(S.substr(0,len))%size;
}

string insert(string account,string PSW,hashTable HT){
    int hashRes=hashing(account,HT.tableSize);
    Ptr2Node currentNode=HT.tableHead[hashRes];
    while (currentNode)
    {
        if(currentNode->account==account) return "ERROR: Exist";
        currentNode=currentNode->next;
    }
    Ptr2Node newNode=new node;
    newNode->account=account;
    newNode->PSW=PSW;
    newNode->next=HT.tableHead[hashRes];
    HT.tableHead[hashRes]=newNode;
    return "New: OK";
}

string find(string account,string PSW,hashTable HT){
    int hashRes=hashing(account,HT.tableSize);
    Ptr2Node currentNode=HT.tableHead[hashRes];
    while (currentNode)
    {
        if(currentNode->account==account){
            if(currentNode->PSW==PSW) return "Login: OK";
            else return "ERROR: Wrong PW";
        }
        currentNode=currentNode->next;
    }
    return "ERROR: Not Exist";
    
}

int main(){
    int N;
    cin>>N;
    int size=minPrime(N);
    //if(size>10007) size=10007;
    hashTable HT;
    HT.tableSize=size;
    HT.tableHead=new Ptr2Node[size];
    for (int i = 0; i < size; i++)
    {
        HT.tableHead[i]=new node;
        HT.tableHead[i]->next=NULL;
        HT.tableHead[i]->account="";
        HT.tableHead[i]->PSW="";
    }
    
    char C;
    string Qaccount,PSW; 
    for (int i = 0; i < N; i++)
    {
        cin>>C>>Qaccount>>PSW;
        if(C=='N'){
            cout<<insert(Qaccount,PSW,HT)<<endl;
        }
        else if (C=='L')
        {
            cout<<find(Qaccount,PSW,HT)<<endl;
        }
        
    }

    return 0;
}