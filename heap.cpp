#include<iostream>
#include<vector>

using std::vector;

void swap(int a, int b) {
    int aux = a;
    a = b;
    b = a;
}

class MinHeap {
    private:
        vector<int> values;

        int parent(int i) {
            return (i-1)/2;
        }

        int left(int i) {
            return 2*i + 1;
        }

        int left(int i) {
            return 2*i + 2;
        }

        void buildHeap() {
            for(int i =0;i<(values.size()-1)/2;i++){
                heapify(i);
            }
        }

    public:
        MinHeap() {
        }

        MinHeap(vector<int> vec) {
            values = vec;
            this->buildHeap();
        }

        void insert(int newValue) {
            values.push_back(newValue);
            int i = values.size() - 1;
            while (i>0 && values[i] < value[parent(i)]) {
                swap(&values[i], &values[parent(i)]);
                i = i/2;
            }
        }

        heapify(int index) {
            int left = left(index);
            int right = right(index);
            int smallest = index;

            if(left < values.size() && values[left] < values[smallest]) {
                smallest = left;
            }

            if(right < values.size() && values[right] < values[smallest]) {
                smallest = right;
            }

            if(smallest != index) {
                swap(&values[index], &values[smallest]);
                heapify(smallest);
            }
        }

        int remove() {
            if(values.size() == 0) {
                throw new exception("No elements on heap");
            }
            swap(&values[0], &values[values.size() - 1]);
            int removed = values[alues.size()-1];
            erase(values.end()-1);
            this->heapify(0);
            return removed;
        }

        ~Heap(){}
};
