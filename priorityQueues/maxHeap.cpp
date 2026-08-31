#include<iostream>
#include<climits>
#include<vector>

class MaxHeap {
public: 
    std::vector<int> heap;

    MaxHeap() {};

    MaxHeap(std::vector<int>& v) {
        heap = v;

        int n = this->heap.size() / 2;
        for(int i = n; i >= 0; i--) downHeapify(i);
    };

    void insert(int val) {
        this->heap.push_back(val);
        int n = this->heap.size();
        if(n > 1) upHeapify(n-1);
    }

    void pop() {
        int n = this->heap.size();
        if(n <= 0) return;

        std::swap(this->heap[0], this->heap[n-1]);
        this->heap.pop_back();
        downHeapify(0);
    }

    void remove(int idx) {
        int n = this->heap.size();

        if(idx < 0 || idx >= n) return;

        std::swap(this->heap[idx], this->heap[n-1]);

        this->heap.pop_back();
        downHeapify(idx);
        upHeapify(idx);
    }

    void downHeapify(int idx) {
        int n = this->heap.size();
        if(n <= 1) return;
        if(idx < 0 || idx >= n) return;
        
        while(true) {
            int lIdx = (2 * idx) + 1;
            int rIdx = (2 * idx) + 2;
            if(lIdx >= n && rIdx >= n) return;

            int left = (lIdx < n) ? this->heap[lIdx] : INT_MIN;
            int right = (rIdx < n) ? this->heap[rIdx] : INT_MIN;

            if(left > right) {
                if(this->heap[idx] < left) {
                    std::swap(this->heap[idx], this->heap[lIdx]);
                    idx = lIdx;
                }else return;
            }
            else {
                if(this->heap[idx] < right) {
                    std::swap(this->heap[idx], this->heap[rIdx]);
                    idx = rIdx;
                }else return;
            }
        }
    }

    void upHeapify(int idx) {
        if(idx < 0 || idx >= this->heap.size()) return;
        int pIdx = (idx-1) / 2;

        while(heap[pIdx] < heap[idx]) {
            int temp = heap[idx];
            heap[idx] = heap[pIdx];
            heap[pIdx] = temp;

            idx = pIdx;
            pIdx = (idx-1) / 2;
        }
    }

    void display() {
        for(int i = 0; i < this->heap.size(); i+=1) std::cout<<this->heap[i]<<" ";

        std::cout<<std::endl;
    }

    int mx() {
        if(this->heap.size() == 0) {
            std::cout<<"Heap is empty!!"<<std::endl;
            return INT_MIN;
        }
        return this->heap[0];
    }
};

int main() {
    std::vector<int> v = {1,9,6,13,-8,0,22,5,100,-1,3};
    MaxHeap* h = new MaxHeap(v);

    std::cout<<h->mx()<<std::endl;

    h->display();

    h->pop();

    h->display();

    std::cout<<"This is the element to be deleted: "<<h->heap[1]<<std::endl;

    h->remove(1);

    h->display();
}