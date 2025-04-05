#include<iostream>
using namespace std;

///✅ 如何将左式堆改为斜堆？
///只需要修改合并操作中的 左右子树交换规则，不再依赖 npl，而是直接交换左右

struct leftistHeap {
    int data;
    leftistHeap* left;
    leftistHeap* right;
    explicit leftistHeap(int val): data(val), npl(0), left(nullptr), right(nullptr) {}
};
leftistHeap* merge(leftistHeap* a, leftistHeap* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data>b->data)swap(a, b);
    a->right = merge(a->right, b);
    swap(a->left, a->right);
    return a;
}
leftistHeap* push(leftistHeap* root,int x){
    leftistHeap* n = new leftistHeap(x);
    return merge(root,n);
}
leftistHeap* pop(leftistHeap* root){
    if(!root)return nullptr;
    leftistHeap* leftistHeap_left = root->left;
    leftistHeap* leftistHeap_right = root->right;
    delete root;
    return merge(leftistHeap_left,leftistHeap_right);
}


leftistHeap* build(int *a,int n){
    leftistHeap* root = new leftistHeap(a[0]);
    for(int i=1;i<n;i++){
        leftistHeap *t = new leftistHeap(a[i]);
        root = merge(root,t);
    }
    return root;
}
void printPre(leftistHeap *root){
    if(!root)return;
    cout<<root->data<<" ";
    printPre(root->left);
    printPre(root->right);
}
/*void printMid(leftistHeap *root){
    if(!root)return;
    printMid(root->left);
    cout<<root->data<<" ";
    printMid(root->right);
}*/
int main(){
    int a[5];
    for(int &i:a)cin>>i;
    leftistHeap* root = build(a,5);
    printPre(root);
//    cout<<endl;
//    printMid(root);
    return 0;
}
