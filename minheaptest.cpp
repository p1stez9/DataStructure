#include <iostream>
#include <algorithm>
using namespace std;

class Minheap {
    public:
        int* heap;
        int capacity;
        int size;

        Minheap(int capacity) {
            this->capacity = capacity;
            heap = new int[capacity];
            size = 0;
        }
        
        int parent(int i) {
            return (i - 1) / 2;
        }

        int leftChild(int i) {
            return 2 * i + 1;
        }

        int rightChild(int i) {
            return 2 * i + 2;
        }

        // ปรับขึ้นเมื่อ insert
        void heapifyUp(int i) {
            while (i > 0 && heap[i] < heap[parent(i)]) {
                swap(heap[i], heap[parent(i)]);
                i = parent(i);
            }
        }

        // ปรับลงเมื่อ deleteMin
        void heapifyDown(int i) {
            int smallest = i;
            int left = leftChild(i);
            int right = rightChild(i);

            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }

            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                heapifyDown(smallest);
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

        void deleteMin() {
            if (size == 0) {
                cout << "Heap is empty\n";
                return;
            }
            cout << "Delete " << heap[0] << endl;
            heap[0] = heap[size - 1];
            size--;
            heapifyDown(0);
        }

        int getMin() {
            if (size == 0) {
                cout << "Empty\n";
                return -1;
            }
            return heap[0];
        }

        void printHeap() {
            cout << "Heap : ";
            for (int i = 0; i < size; i++) {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Minheap h(10);

    h.insert(20);
    h.insert(50);
    h.insert(15);
    h.insert(30);
    h.insert(10);
    h.printHeap();

    cout << "Min = " << h.getMin() << endl;

    h.deleteMin();
    h.printHeap();

    return 0;
}
