#include <iostream>
using namespace std;
class BinaryHeap{
private:
    int currL=0;
    int *arr;
    int maxSize;
    void percolate(int);
    void build(){
        for(int i=currL/2;i>=1;i--){
            percolate(i);
        }
    }
public:
    explicit BinaryHeap(int cap=100):maxSize(cap),currL(0){
        arr = new int[cap];
    }
    BinaryHeap(const int*data,int size):maxSize(size+100),currL(size) {
        arr = new int [maxSize];
        for(int i=0;i<size;i++)arr[i+1]=data[i];
        build();
    }
    ~BinaryHeap(){delete[]arr;}
    bool empty()const{return currL==0;}
    void push(int x){
        int hole = ++currL;
        for(;hole>1&&x>arr[hole/2];hole/=2)
            swap(arr[hole],arr[hole/2]);
        arr[hole] = x;
    };
    int pop(){
        int minimum = arr[1];
        arr[1] = arr[currL--];
        percolate(1);
        return minimum;
    };
};

void BinaryHeap::percolate(int hole) {
    int child,temp = arr[hole];
    for(;hole*2<=currL;hole=child){
        child = hole*2;
        if(child!=currL&&arr[child]>arr[child+1])child++;
        if(arr[child]>=temp)break;
        else{
            arr[hole] = arr[child];
        }
    }
    arr[hole] = temp;
}
int main() {
    int a[5];
    for(int & i : a)cin>>i;
    BinaryHeap heap(a,5);
    while (!heap.empty()){
        cout<<heap.pop()<<" ";
    }
    return 0;
}
