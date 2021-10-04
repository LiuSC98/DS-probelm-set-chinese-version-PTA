/*
7-4 是否同一棵二叉搜索树 (25 分)
给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:
输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。随后L行，每行给出N个插入的元素，属于L个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

输出格式:
对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

输入样例:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0

输出样例:
Yes
No
No

*/

#include <iostream>
using namespace std;

typedef struct node* Ptr2Node;
struct node{
    int key;
    Ptr2Node left,right;
};
typedef Ptr2Node BiTree;

BiTree insert(BiTree root,int x){
    if(!root){
        root=new node;
        root->key=x;
        root->right=root->left=NULL;
    }
    else{
        if(x<root->key)
            root->left=insert(root->left,x);
        else
            root->right=insert(root->right,x);
    }
    return root;
}

bool isSameTree(BiTree tree1,BiTree tree2){
   if(!tree1&&!tree2) return 1;
   else if(!tree1 || !tree2) return 0;
   else if(tree1->key!=tree2->key) return 0;
   else return isSameTree(tree1->left,tree2->left)&&isSameTree(tree1->right,tree2->right); 
}

void deleteTree(BiTree root){
    if(root){
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}


int main(){
    int N,L;
    do{
        cin>>N;
        if(N){
            cin>>L;
            BiTree tree0=NULL;
            int input;
            for (int i = 0; i < N; i++)
            {
                cin>>input;
                tree0=insert(tree0,input);
            }
            while(L--){
                BiTree tree1=NULL;
                for (int i = 0; i < N; i++)
                {
                    cin>>input;
                    tree1=insert(tree1,input);
                }
                if(isSameTree(tree0,tree1)) cout<<"Yes";
                else cout<<"No";
                cout<<endl;
                deleteTree(tree1);
            }
        }
    }while (N);
    
    return 0;
}