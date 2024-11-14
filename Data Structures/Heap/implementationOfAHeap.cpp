#include<iostream>
using namespace std;

class heap {

    public :
        int arr[100];
        int size;

        heap() {
            arr[0] = -1;
            size = 0;
        }

        void insert(int value) {

            size = size + 1;
            int index = size;
            arr[index] = value;

            while(index > 1) {
                int parent = index / 2;

                if(arr[parent] < arr[index]) {
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else {
                    return;
                }
            }
        }

        void deleteFromHeap() {
            
            if(size == 0) {
                cout << "Nothing to Delete" << endl;
            }

            arr[1] = arr[size];

            size--;

            int i = 1;
            while(i < size) {

                int leftChild = 2*i;
                int rightChild = 2*i+1;

                if(leftChild <= size && arr[leftChild] > arr[i] && arr[leftChild] > arr[rightChild]) {
                    swap(arr[i],arr[leftChild]);
                    i = leftChild;
                }
                else if(rightChild <= size && arr[rightChild] > arr[i] && arr[rightChild] > arr[leftChild]) {
                    swap(arr[i],arr[rightChild]);
                    i = rightChild;
                }
                else {
                    return;
                }
            }

        }

        void print() {
            for(int i=1 ;i<=size;i++) {
                cout << arr[i] << " ";
            }cout << endl;
        }
};

void heapify(int arr[], int &n, int elementIndex_i) { // 1-based indexing and Max Heap

    int largest = elementIndex_i;
    int leftChild = 2*elementIndex_i;
    int rightChild = 2*elementIndex_i+1;

    if(leftChild <= n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    if(rightChild <= n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    if(largest != elementIndex_i) {
        swap(arr[largest],arr[elementIndex_i]);
        heapify(arr,n,largest);
    }
}

void heapify_min_heap(int arr[],int &n,int elementIndex_i) { // 0 - based indexing

    int smallest = elementIndex_i;
    int leftChild = 2*elementIndex_i + 1;
    int rightChild = 2*elementIndex_i + 2;

    if(leftChild < n && arr[leftChild] < arr[smallest]) {
        smallest = leftChild;
    }
    if(rightChild < n && arr[rightChild] < arr[smallest]) {
        smallest = rightChild;
    }

    if(smallest != elementIndex_i) {
        swap(arr[elementIndex_i],arr[smallest]);
        heapify_min_heap(arr,n,smallest);
    }
}

void heapSort(int arr[] , int n) {

    int size = n;

    while(size>1) {
        //step : 1
        swap(arr[1],arr[size]);
        size--;

        //step : 2
        heapify(arr,size,1);
    }
}

int main() {

    // heap h;

    // h.insert(50);
    // h.insert(52);
    // h.insert(53);
    // h.insert(54);
    // h.insert(55);
    // h.insert(70);

    // h.print();

    // h.deleteFromHeap();
    // cout << "After Deletion : " << endl;
    // h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    for(int i = (n/2)  ; i>0 ; i--) {
        heapify(arr,n,i);
    }

    cout << "Printing Array after Hepify " << endl;
    for(int i = 1  ; i<=n ; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    // for(int i = (n/2)-1 ; i>=0 ; i--) {
    //     heapify_min_heap(arr,n,i);
    // }

    heapSort(arr,n);

    cout << "Printing Array after Heap Sort : " << endl;
    for(int i = 1  ; i<=n ; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}