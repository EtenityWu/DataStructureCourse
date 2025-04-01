 class stack{
private:
    char *a;
    int curL=0;
public:
    explicit stack(int n){a = new char [n+1];}
    ~stack(){delete []a;}
    bool empty()const {return curL==0;}
    void push(char s){curL++;a[curL-1] = s;}
    char top(){return a[curL-1];}
    void pop(){curL--;}
};
class queue {
private:
    int *val;
    int cap;
    int curl = 0;
    int head = 0, tail = 0;
public:
    explicit queue(int n){cap=n+1;val =new int[cap];}
    ~queue(){delete[] val;}
    bool empty(){ return curl == 0; }
    int front(){ return val[head]; }
    int back(){ return val[(tail-1+cap)%cap];}
    void push(int i){
        val[tail] = i;
        tail = (tail + 1) % cap;
        curl++;
    }
    void pop_front(){head=(head+1)%cap;curl--;}
    void pop_back(){tail=(tail-1+cap)% cap;curl--;}
};
struct heap {
    int *element;
    int maxSize;
    int cur;
    explicit heap(int n) : maxSize(n + 1), cur(n) {
        element = new int[maxSize];
    }
    ~heap() { delete[] element; }
};
void heapify(heap &h, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= h.cur && h.element[left] > h.element[largest])
        largest = left;
    if (right <= h.cur && h.element[right] > h.element[largest])
        largest = right;
    if (largest != i) {
        swap(h.element[i], h.element[largest]);
        heapify(h, largest);
    }
}
void buildMaxHeap(heap &h) {
    for (int i = h.cur / 2; i >= 1; i--) {
        heapify(h, i);
    }
}
void heapSort(heap &h) {
    buildMaxHeap(h);  // 先建堆
    for (int i = h.cur; i > 1; i--) {
        swap(h.element[1], h.element[i]); // 将最大值放到末尾
        h.cur--; // 让堆的有效长度减少
        heapify(h, 1); // 重新调整堆
    }
}
