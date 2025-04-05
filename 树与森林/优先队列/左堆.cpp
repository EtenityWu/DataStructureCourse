#include<iostream>
using namespace std;
struct leftistHeap {
    int data;
    leftistHeap* left;
    leftistHeap* right;
    int npl;
    explicit leftistHeap(int val): data(val), npl(0), left(nullptr), right(nullptr) {}
};
int getNpl(leftistHeap* node) {
    return node ? node->npl : -1;
}
leftistHeap* merge(leftistHeap* a, leftistHeap* b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data>b->data)swap(a, b);
    a->right = merge(a->right, b);
    if (getNpl(a->right)>getNpl(a->left))swap(a->left, a->right);
    a->npl = getNpl(a->right) + 1;
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


//这个时间复杂度最大会达到n*log(n),下面给出gpt提示出来的用队列实现的
leftistHeap* build(int *a,int n){
    leftistHeap* root = new leftistHeap(a[0]);
    for(int i=1;i<n;i++){
        leftistHeap *t = new leftistHeap(a[i]);
        root = merge(root,t);
    }
    return root;
}
#include <queue>
leftistHeap* buildHeap(int* a, int n) {
    queue<leftistHeap*> q;
    for(int i = 0; i < n; ++i) {
        q.push(new leftistHeap(a[i]));
    }
    while(q.size() > 1) {
        leftistHeap* h1 = q.front(); q.pop();
        leftistHeap* h2 = q.front(); q.pop();
        q.push(merge(h1, h2));
    }
    return q.empty() ? nullptr : q.front(); // 返回最终堆顶
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
