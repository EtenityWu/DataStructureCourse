#include<iostream>
using namespace std;
class BinaryHeap{
private:
    struct node{
        node *parent;
        int key;
        int degree;
        node *child;
        node *sibling;
        node(){
            parent = child = sibling = nullptr;
        }
    };
    node *head;
public:
    BinaryHeap(){head = new node;}
    int minimum(BinaryHeap *a){
        node *x=a->head;
        int min = x->key;
        x=x->sibling;
        while(x){
            if(x->key<min)min=x->key;
            x=x->sibling;
        }
        return min;
    }
    void link(node *y,node*z){
        y->parent=z;
        y->sibling=z->child;
        z->child=y;
        z->degree+=1;
    }
    node *linkRoot(BinaryHeap *&h1,BinaryHeap *&h2){
        node *first= nullptr;
        node *p1=h1->head;
        node *p2=h2->head;
        if(!p1)return p2;
        if(!p2)return p1;
        if(p1->degree<p2->degree){
            first = p1;
            p1 = p1->sibling;
        } else{
            first = p2;
            p2 = p2->sibling;
        }
        node *p = first;
        while(p1&&p2){
            if(p1->degree<p2->degree){
                p->sibling = p1;
                p = p1;
                p1 = p1->sibling;
            } else{
                p->sibling = p2;
                p = p2;
                p2 = p2->sibling;
            }
        }
        if(!p1)p->sibling = p2;
        if(!p2)p->sibling = p1;
        return first;
    }
    BinaryHeap *merge(BinaryHeap*& h1, BinaryHeap*& h2) {
        BinaryHeap *result = new BinaryHeap();
        result->head = linkRoot(h1, h2);
        if (!head) return nullptr;
        node* prev = nullptr;
        node* curr = head;
        node* next = curr->sibling;
        while (next) {
            if ((curr->degree != next->degree) ||
                (next->sibling && next->sibling->degree == curr->degree)) {
                prev = curr;
                curr = next;
            } else {
                if (curr->key <= next->key) {
                    curr->sibling = next->sibling;
                    link(next, curr);
                } else {
                    if (prev) prev->sibling = next;
                    else head = next;
                    link(curr, next);
                    curr = next;
                }
            }
            next=curr->sibling;
        }
        return result;
    }
};

int main(){

}
