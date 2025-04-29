#include<iostream>
using namespace std;
/// to do:AVL平衡树
class AVLTree{
    struct node{
        int data;
        node *left,*right;
        int height;
        explicit node(const int x,node *l = nullptr,node *r = nullptr,int h=1):data(x),left(l),right(r),height(h){}
    };
    node *root;
private:
    bool adjust(node *&t,int type){
        if(type){///右子树上删除让右子树变短
            if(height(t->left) - height(t->right) == 1 ) return true;
            if(height(t->right) == height(t->left)) { --t->height; return false;}
            if(height(t->left->right) > height(t->left->left)){
                LR(t);
                return false;
            }
            LL(t);
            if (height(t->right) == height(t->left)) return false; else return true;
        } else{
            if (height(t->right) - height(t->left) == 1 ) return true;
            if (height(t->right) == height(t->left)) { --t->height; return false;}
            if (height(t->right->left) > height(t->right->right))               
            { RL(t);	return false;  }
            RR(t);
            if (height(t->right) == height(t->left)) return false; else return true;

        }
    }
    bool remove(int x, node*&r){
        if(!r)return true;
        if(x==r->data){
            if(!r->left||!r->right){
                node *temp = r;
                r = r->left?r->left:r->right;
                delete temp;
                return false;
            }
            else{
                node *temp = r->right;
                while(temp->left)temp=temp->left;
                r->data = temp->data;
                if(remove(temp->data,r->right))return true;
                return adjust(r,1);
            }
        }
        if(x<r->data){
            if(remove(x,r->left))return true;
            return adjust(r,0);
        } else{
            if(remove(x,r->right))return true;
            return adjust(r,1);
        }
    }
    void LL(node *&t){
        node *temp = t->left;
        t->left = temp->right;
        temp->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        temp->height = max(height(temp->left), height(t))+1;
        t = temp;///这一步应该是来链接当前节点与父节点，
                ///可以这样理解：t一直都要做当前小区域的根节点，所以得换回来
    }
    void RR(node *&t){
        node *temp = t->right;
        t->right = temp->left;
        temp->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        temp->height = max(height(temp->right), height(t))+1;
        t = temp;
    }
    void LR(node *&t){
        RR(t->left);
        LL(t);
    }
    void RL(node *&t){
        LL(t->right);
        RR(t);
    }
    void push(int x,node *r){
        if(!r)r = new node(x);
        else if(x<r->data){
            push(x,r->left);
            if(height(r->left)- height(r->right)==2){
                if(x<r->left->data)LL(r);
                else LR(r);
            }
        } else if(x>r->data){
            push(x,r->right);
            if(height(r->right)- height((r->left))==2){
                if(x>r->right->data)RR(r);
                else RL(r);
            }
        }
        r->height = max(height(r->left), height(r->right))+1;
    }
    node *find(int x){
        node *r = root;
        while(r&&r->data!=x){
            if(x<r->data)r=r->left;
            else r = r->right;
        }
        return r;
    }
    static int height(node *r){return r?r->height:0;}
};
int main(){

}
