#include <iostream>
#include <algorithm>
using namespace std;

class Maxheap {
    public:
        int* heap;
        int capacity;
        int size;

        Maxheap(int capacity) {
            this->capacity = capacity;
            heap = new int[capacity];
            size = 0;
        }
        
        int parent(int i) {
            return (i - 1) / 2;
        }

        int leftChild(int i) {
            return 2 * i  + 1;
        }

        int rightChild(int i) {
            return 2 * i + 2;
        }

        void heapifyUp(int i) {
            while(i > 0 && heap[i] > heap[parent(i)]) {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        void heapifyDown(int i) {
            int largest = i;
            int left = leftChild(i);
            int right = rightChild(i);

            if(left < size && heap[left] > heap[largest]) {
                largest = left;
            }

            if(right < size && heap[right] > heap[largest]) {
                largest = right;
            }

            if(largest != i) {
                swap(heap[i], heap[largest]);
                heapifyDown(largest); // recursive ไปเรื่อยๆ
            }
        }

        void insert(int value) {
            if (size == capacity) {
                cout << "Heap Full\n";
                return;
            }
            heap[size] = value;
            heapifyUp(size);
            size++;
        }

        void deleteMax() {
            if (size == 0) {
                cout << "Heap is empty\n";
                return;
            }
            cout << "Delete " << heap[0] << endl;
            heap[0] = heap[size - 1];
            size--;
            heapifyDown(0);
        }

        int getMax() {
            if (size == 0) {
                cout << "Empty\n";
                return -1;
            }
            return heap[0];
        }

        void printHeap() {
            cout << "Heap : ";
            for(int i = 0 ; i < size ; i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        }

};

int main() {
    Maxheap h(10);

    h.insert(20);
    h.insert(50);
    h.insert(15);
    h.insert(30);
    h.insert(10);
    h.printHeap();
    return 0;
}