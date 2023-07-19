#include<bits/stdc++.h>

using namespace std;

class MinHeap{

    vector<int> q;
    
    public: 
    MinHeap() {

    }
    bool isEmpty() {
        return q.size() == 0;
    }

    int size() {
        return q.size();
    }

    void push(int data) {
        q.push_back(data);
        int child = q.size() - 1;
        while( child > 0 && q[child] < q[(child -1)/2] ) {
            int temp = q[child];
            q[child] = q[(child - 1)/2];
            q[(child -1)/2] = temp;
            child = (child - 1) / 2;
        }
    }
    int top() {
        return q[0];
    }

    int pop() {

        // pop
        // heapify

    }

    void printHeap() {
        cout << endl;
        for(auto it: q) {
            cout << it << " ";
        }
        cout << endl;
    }
    int heapify() {
        if(isEmpty()) {
            return INT_MIN;
        }
        int temp = q[0];
        int n = q.size() - 1;
        q[0] = q[n];
        q.pop_back();
        int parent = 0; 
        int leftChild = 2 * parent + 1;
        while(leftChild < n && (q[parent] > q[leftChild] || q[parent] > q[leftChild + 1 ] )) {
            bool flag = false;
            if(q[leftChild] < q[leftChild + 1]) {
                flag = true;
            }
            if(flag) {
                int temp2 = q[parent];
                q[parent] = q[leftChild];
                q[leftChild] = temp2;
                parent = leftChild;
            }
            else {
                int temp2 = q[parent];
                q[parent] = q[leftChild + 1];
                q[leftChild + 1] = temp2;
                parent = leftChild + 1;
            
            }
            leftChild = 2 * parent + 1;
            
        }
        return temp;
    }
};
int main() {
    MinHeap heap;
    heap.push(10);
    heap.push(20);
    heap.push(15);
    heap.push(5);
    heap.push(2);
    heap.push(4);
    cout << "size = " <<  heap.size() << endl;
    // while(!heap.isEmpty()) {
    //     cout << heap.top() << " ";
    //     heap.heapify();
    // }/

    heap.printHeap();
    cout << heap.heapify() << endl;
    cout << heap.heapify() << endl;
    cout << heap.heapify() << endl;
    cout << heap.heapify() << endl;
    cout << heap.heapify() << endl;
    cout << heap.heapify() << endl;
    cout << heap.heapify() << endl;
    cout << heap.heapify() << endl;
    cout << heap.heapify() << endl;
    cout << heap.heapify() << endl;
}