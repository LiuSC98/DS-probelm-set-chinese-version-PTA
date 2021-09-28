/*
7-3 树的同构 (25 分)
给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。
例如图1给出的两棵树就是同构的，因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。
而图2就不是同构的。

现给定两棵树，请你判断它们是否是同构的。

输入格式:
输入给出2棵二叉树树的信息。
对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N−1编号）；
随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。
如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。注意：题目保证每个结点中存储的字母是不同的。

输出格式:
如果两棵树是同构的，输出“Yes”，否则输出“No”。

输入样例1（对应图1）：
8
A 1 2
B 3 4
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8
G - 4
B 7 6
F - -
A 5 1
H - -
C 0 -
D - -
E 2 -

输出样例1:
Yes

输入样例2（对应图2）：
8
B 5 7
F - -
A 0 3
C 6 -
H - -
D - -
G 4 -
E 1 -
8
D 6 -
B 5 -
E - -
H - -
C 0 2
G - 3
F - -
A 1 4

输出样例2:
No

*/

#include <iostream>
using namespace std;

struct listNode{
    char C,L,R;
};
int main(){
    int res1[26];//,res2[26];
    for (int i = 0; i < 26; i++)
    {
        res1[i]=-2;
        //res2[i]=-1;
    }
    int lSon,rSon;
    int N1,N2;
    cin>>N1;
    listNode *list1=new listNode[N1];
    for (int i = 0; i < N1; i++)
    {
        cin>>list1[i].C>>list1[i].L>>list1[i].R;
        list1[i].C=list1[i].C-'A';
        if(list1[i].L=='-')list1[i].L=-1;
        else list1[i].L=list1[i].L-'0';
        if(list1[i].R=='-')list1[i].R=-1;
        else list1[i].R=list1[i].R-'0';
    }
    for (int i = 0; i < N1; i++)
    {
        if(res1[list1[i].C]==-2) res1[list1[i].C]=-1;
        if(list1[i].L!=-1){
            res1[list1[list1[i].L].C]=list1[i].C;
        }
        if(list1[i].R!=-1){
            res1[list1[list1[i].R].C]=list1[i].C;
        }
    }

    cin>>N2;
    if(N1!=N2) {
        cout<<"No";
        return 0;
    }
    listNode *list2=new listNode[N2];
    for (int i = 0; i < N2; i++)
    {
        cin>>list2[i].C>>list2[i].L>>list2[i].R;
        list2[i].C=list2[i].C-'A';
        if(list2[i].L=='-')list2[i].L=-1;
        else list2[i].L=list2[i].L-'0';
        if(list2[i].R=='-')list2[i].R=-1;
        else list2[i].R=list2[i].R-'0';
    }
    
    for (int i = 0; i < N1; i++)
    {
        if(res1[list2[i].C]==-2){
            cout<<"No";
            return 0;
        }
        if(list2[i].L!=-1){
            if(res1[list2[list2[i].L].C]!=list2[i].C){
                cout<<"No";
                return 0;
            }
        }
        if(list2[i].R!=-1){
            if(res1[list2[list2[i].R].C]!=list2[i].C){
                cout<<"No";
                return 0;
            }
        }
    }
    // for (int i = 0; i < N1; i++)
    // {
    //     if(res2[list2[i].C]==-2) res2[list2[i].C]=-1;
    //     if(list2[i].L!=-1){
    //         res2[list2[list2[i].L].C]=list2[i].C);
    //     }
    //     if(list2[i].R!=-1){
    //         res2[list2[list2[i].R].C]=list2[i].C;
    //     }
    // }
    // for(int i=0;i<26;i++){
    //     if(res2[i]!=res1[i]){
    //         cout<<"No";
    //         return 0;
    //     }
    // }
    cout<<"Yes";
    return 0;
}