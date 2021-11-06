#include <iostream>
#include <vector>
using namespace std;

class minHeap{
    public:
    vector<int> a;

    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }

    int getMin(){
        return a[0];
    }

    void siftUp(int i){
        while(i > 0 && a[parent(i)] > a[i]){
            swap(a[parent(i)],a[i]);
            i = parent(i);
        }
    }
    
    void insert(int k){
        a.push_back(k);
        int i = a.size() - 1;
        siftUp(i);
    }

    void heapify(int i){
        if(left(i) > a.size() - 1){
            return;
        }

        int j = left(i);
        if(right(i) < a.size() && a[left(i)] > a[right(i)]){
            j = right(i);
        }
        if(a[i] > a[j]){
            swap(a[i],a[j]);
            heapify(j);
        }
    }

    int extractMin(){
        int root_value = getMin();
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size() > 0){
            heapify(0);
        }
        return root_value;
    }


    void print(){
        for(int i = 0; i < a.size();i++){
            cout << a[i] << ' ' << endl;
        }
    }

};

int main(){
    int n, x;
    cin >> n;
    minHeap * heap = new minHeap();
    for(int i = 0; i < n; i++){
        cin >> x;
        heap->insert(x);
    }

    for(int i = 0; i < n; i++){
        cout << heap->extractMin() <<' ';
    }

    return 0;
}