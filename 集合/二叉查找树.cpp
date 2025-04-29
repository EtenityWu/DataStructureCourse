#include<iostream>
using namespace std;
/// to do:二叉查找树
class binarySearchTree{
    struct node{
        int data;
        node* left,*right;
        explicit node(int x,node *l = nullptr,node *r = nullptr):data(x),left(l),right(r){}
    };
    node *root;
public:
    binarySearchTree(){root = nullptr;}
    ~binarySearchTree(){release(root);}
    void push(int x){push(x,root);}
    node* find(int x){return find(x,root);}
    void remove(int x){remove(x,root);}
    void print(){print(root);}
    void inOrder(int *arr,int &index){inOrder(root,arr,index);}
private:
    void inOrder(node *r,int *arr,int &index){
        if(!r)return;
        inOrder(r->left,arr,index);
        arr[index++] = r->data;
        inOrder(r->right,arr,index);
    }
    void push(int x,node *&r){///这里改变了树的结构，所以一定要用&类型！！！
        if(!r)r = new node(x);
        else if(x<r->data) push(x,r->left);
        else if(x>r->data) push(x,r->right);
    }
    node* find(int x,node *r){
        if(!r)return r;
        if(x==r->data)return r;
        else if(x<r->data)return find(x,r->left);
        else return find(x,r->right);
    }
    void remove(int x,node *&r){///这里改变了树的结构，所以一定要用&类型！！！
        if(!r)return;
        else if(x<r->data)remove(x,r->left);
        else if(x>r->data)remove(x,r->right);
        else if(r->left&&r->right){
            node *temp=r->right;
            while(temp->left){temp = temp->left;}
            r->data = temp->data;
            remove(temp->data,r->right);
        } else{
            node *temp = r;
            r = (r->left)?r->left:r->right;
            delete temp;
        }
    }
    void release(node *r){
        if(!r)return;
        release(r->left);
        release(r->right);
        delete r;
    }
    void print(node *r){
        if(!r)return;
        print(r->left);
        cout<<r->data<<" ";
        print(r->right);
    }
};
void sort(int *a,int len){
    binarySearchTree searchTree;
    for(int i=0;i<len;i++){
        searchTree.push(a[i]);
    }
    int index=0;
    searchTree.inOrder(a,index);
}
int main(){
    int n;
    cin>>n;
    int *arr;
    arr = new int [n+1];
    binarySearchTree Sort;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[i] = a;
        Sort.push(a);
    }
    Sort.print();
    cout<<endl;
    sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    delete[]arr;
    return 0;
}
