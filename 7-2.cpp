/*
7-2 一元多项式的乘法与加法运算 (20 分)
设计函数分别求两个一元多项式的乘积与和。

输入格式:
输入分2行，每行分别先给出多项式非零项的个数，
再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。
数字间以空格分隔。

输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。
数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

输入样例:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1

输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0

*/

#include <iostream>

using namespace std;

typedef struct node* Ptr2Node;
struct node{
    int coe,exp;
    Ptr2Node next;
};
typedef Ptr2Node link;


inline link insert(link P,int C,int E){
    link tempNode=new node;
    tempNode->coe=C;
    tempNode->exp=E;
    tempNode->next=NULL;
    P->next=tempNode;
    return P=tempNode;
}


link add(link n1,link n2){
    link res= new node;
    res->next=NULL;
    link p=res;
    link num1=n1->next;
    link num2=n2->next;
    while (num1 && num2)
    {
        if(num1->exp>num2->exp){
            if(num1->coe) p=insert(p,num1->coe,num1->exp);
            num1=num1->next;
        }
        else if(num1->exp<num2->exp){
            if(num2->coe) p=insert(p,num2->coe,num2->exp);
            num2=num2->next;
        }else {
            if(num1->coe+num2->coe) p=insert(p,num1->coe+num2->coe,num2->exp);
            num1=num1->next;
            num2=num2->next;
        }
    }
    while (num1)
    {
        if(num1->coe) p=insert(p,num1->coe,num1->exp);
        num1=num1->next;
    }
    while (num2)
    {
        if(num2->coe) p=insert(p,num2->coe,num2->exp);
        num2=num2->next;
    }
    
    return res; 
}

link multiply(link num1,link num2){
    link res = new node;
    res->next=NULL;
    link n1=num1->next,n2;
    link temp,p;
    while (n1)
    {
        n2=num2->next;
        temp = new node;
        temp->next=NULL;
        p=temp;
        while (n2)
        {
            p=insert(p,n1->coe*n2->coe,n1->exp+n2->exp);
            n2=n2->next;
        }
        res=add(res,temp);
        n1=n1->next;
    }
    
    return res;
}




int main(){
    int N1,N2;

    cin>>N1;
    link poly1=new node;
    poly1->next=NULL;
    link p=poly1;
    int c,e;
    for (int i = 0; i < N1; i++)
    {
        cin>>c>>e;
        if(c)
        p=insert(p,c,e);
    }
    
    cin>>N2;
    link poly2=new node;
    poly2->next=NULL;
    p=poly2;
    for (int i = 0; i < N2; i++)
    {
        cin>>c>>e;
        if(c)
        p=insert(p,c,e);
    }
    
    link mulRes=multiply(poly1,poly2);
    mulRes=mulRes->next;
    if(!mulRes) cout<<"0 0";
    else{
        bool flag=0;
        while (mulRes)
        {
            if(flag)cout<<' ';
            else flag=1;
            cout<<mulRes->coe<<' '<<mulRes->exp;
            mulRes=mulRes->next;
        }
    }
    cout<<endl;
    
    
    link addRes=add(poly1,poly2);
    addRes=addRes->next;
    if(!addRes) cout<<"0 0";
    else{
        bool flag=0;
        while (addRes)
        {
            if(flag)cout<<' ';
            else flag=1;
            cout<<addRes->coe<<' '<<addRes->exp;
            addRes=addRes->next;
        }
    }
    
    
    return 0;
}