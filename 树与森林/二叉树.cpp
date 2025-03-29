#include <iostream>
#include <queue>
using namespace std;

template <class T>
class binaryTree{
    friend void print(const binaryTree& t,T flag);
private:
    struct node{
        node *left,*right;
        T data;
        node():left(nullptr),right(nullptr){}
        explicit node(T t,node *l= nullptr,node *r = nullptr):data(t),left(l),right(r){}
        ~node()= default;
    };
    node *root;
public:
    //这里的flag都是为了识别空树设置的特殊值
    binaryTree():root(nullptr){}
    explicit binaryTree(T x){root = new node(x);}
    ~binaryTree(){clear(root);};
    void clear(){clear(root);};
    bool isEmpty()const{return root== nullptr;};
    T Root(T flag)const;
    T lChild(T x,T flag)const;
    T rChild(T x,T flag)const;
    void preOrder()const{preOrder(root);};//前序遍历
    void midOrder()const{midOrder(root);};//中序遍历
    void postOrder()const{postOrder(root);};//后续遍历
    void levelOrder()const;//层次序遍历
    void creatTree(T flag);
    T parent(T x,T flag)const{return flag;}
private:
    node *find(T x,node *t)const;
    void clear(node*&t);
    void preOrder(node *t)const;
    void midOrder(node *t)const;
    void postOrder(node *t)const;
};

template<class T>
void print(const binaryTree<T> &t, T flag) {
    queue<T> que;
    que.push(t.root->data);
    cout<<endl;
    while (!que.empty()){
        char p,l,r;
        p = que.pop();
        l = t.lChild(p,flag);
        r = t.rChild(p,flag);
        cout<<p<<" "<<l<<" "<<r<<endl;
        if(l!=flag)que.push(l);
        if(r!=flag)que.push(r);
    }

}

template<class T>
void binaryTree<T>::creatTree(T flag) {
    queue<node*>que;
    node *temp;
    T x,ldata,rdata;
    cout<<"root data:"<<endl;
    cin>>x;
    root = new node(x);
    que.push(x);
    while (!que.empty()){
        temp = que.pop();
        cout<<"left and right:"<<endl;
        cin>>ldata>>rdata;
        if(ldata!=flag)que.push(temp->left=new node(ldata));
        if(rdata!=flag)que.push(temp->left=new node(rdata));
    }
}

template<class T>
T binaryTree<T>::rChild(T x, T flag) const {
    node *tmp = find(x,root);
    if(tmp== nullptr||tmp->right== nullptr)return flag;
    return tmp->right->data;
}

template<class T>
T binaryTree<T>::lChild(T x, T flag) const {
    node *temp =find(x,root);
    if(temp==nullptr||temp->left==nullptr)return flag;
    return temp->left->data;
}

template<class T>
binaryTree<T>::node *binaryTree<T>::find(T x, binaryTree::node *t) const {
    node *temp;
    if(t== nullptr)return nullptr;
    if(t->data==x)return t;
    if((temp= find(x,t->left)))return temp;
    return find(x,t->right);
}

template<class T>
void binaryTree<T>::levelOrder() const {
    queue<node*>q;
    node *temp;
    q.push(root);
    while(!q.empty()){
        temp = q.pop();
        cout<<temp->data<<" ";
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }
}

template<class T>
void binaryTree<T>::preOrder(binaryTree::node *t) const {
    if(t==nullptr)return;
    cout<<t->data<<" ";
    preOrder(t->left);
    preOrder(t->right);
}

template<class T>
void binaryTree<T>::midOrder(binaryTree::node *t) const {
    if(t==nullptr)return;
    preOrder(t->left);
    cout<<t->data<<" ";
    preOrder(t->right);
}

template<class T>
void binaryTree<T>::postOrder(binaryTree::node *t) const {
    if(t==nullptr)return;
    preOrder(t->left);
    preOrder(t->right);
    cout<<t->data<<" ";
}

template<class T>
void binaryTree<T>::clear(binaryTree::node *&t) {
    if(t== nullptr)return;
    if(t->left!=nullptr)clear(t->left);
    if(t->right!= nullptr)clear(t->right);
    delete t;
    t = nullptr;
}

template<class T>
T binaryTree<T>::Root(T flag) const {
    if(root)return root->data;
    else return flag;
}


int main(){

    return 0;
}
