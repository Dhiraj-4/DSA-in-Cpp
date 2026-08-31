#include<iostream>
#include<queue>
#include<vector>

int main() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // minHeap
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap; // maxHeap, this is default
    std::priority_queue<int> mxHeap; // this is also maxHeap, other two parameters are default for maxHeap

    std::vector<int> v = {2,1,3,4,5,65};
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeapVector(v.begin(), v.end()); // also allowed

    minHeap.push(2);
    minHeap.push(26);
    minHeap.push(29);
    minHeap.push(22);
    minHeap.push(65);
    minHeap.push(1);
    minHeap.push(-56);
    minHeap.push(29);

    std::cout<<minHeap.top()<<std::endl;
}