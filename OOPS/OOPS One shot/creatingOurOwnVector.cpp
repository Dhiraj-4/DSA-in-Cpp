#include<iostream>
using namespace std;

class vector {
public:
    int size = 0;
    int capacity = 1;
    int* nums;

    // constructor
    vector () {
        nums = new int[1];
    }

    void add(int num) {
        if(size == capacity) {
            capacity *= 2;

            int* nums2 = new int[capacity];
            
            for(int i = 0; i < size; i++) nums2[i] = nums[i];

            int* old = nums;
            nums = nums2;
            delete[] old;            
        }
        nums[size++] = num;
    }

    void print() {
        for(int i = 0; i < size; i++) cout<<nums[i]<<" ";
        cout<<endl;
    }

    void remove() {
        if(size == 0) {
            cout<<("Array is empty");
            return;
        }
        size--;
    }

    int get(int idx) {
        if(idx < 0 || idx >= size) throw runtime_error("Invalid index");

        return nums[idx];
    }

    void set(int idx, int num) {
        if(idx < 0 || idx >= size) throw runtime_error("Invalid index");

        nums[idx] = num;
    }
};

int main() {
    vector nums;
    cout<<"size and capacity: "<<nums.size<<" "<<nums.capacity<<" "<<endl;

    nums.add(10);
    cout<<"nums: "; nums.print();
    cout<<"size and capacity: "<<nums.size<<" "<<nums.capacity<<" "<<endl;

    nums.add(21);
    cout<<"nums: "; nums.print();
    cout<<"size and capacity: "<<nums.size<<" "<<nums.capacity<<" "<<endl;

    nums.add(6);
    cout<<"nums: "; nums.print();
    cout<<"size and capacity: "<<nums.size<<" "<<nums.capacity<<" "<<endl;

    nums.add(2);
    cout<<"nums: "; nums.print();
    cout<<"size and capacity: "<<nums.size<<" "<<nums.capacity<<" "<<endl;

    nums.remove();
    cout<<"nums: "; nums.print();
    cout<<"size and capacity: "<<nums.size<<" "<<nums.capacity<<" "<<endl;
}