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
        ~node(){}
    };
    node *root;
public:
    //这里的flag都是为了识别空树设置的特殊值
    binaryTree():root(nullptr){}
    binaryTree(T x){root = new node(x);}
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
