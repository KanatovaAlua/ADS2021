#include <iostream>
#include <vector>
using namespace std;

class maxHeap{
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

    void siftUp(int i){
        while(i > 0 && a[parent(i)] < a[i]){
            swap(a[parent(i)],a[i]);
            i = parent(i);
        }
        cout << i+1 << endl;
    }
    
    void insert(int k){
        a.push_back(k);
        int i = a.size() - 1;
    }

    void increaseKey(int i, int new_value){
        a[i] = new_value + a[i];
        siftUp(i);
    }

    void print(){
        for(int i = 0; i < a.size();i++){
            cout << a[i] << ' ';
        }
    }

};

int main(){
    int n, b;
    cin >> n;
    maxHeap * heap = new maxHeap();
    for(int i = 0; i < n; i++){
        cin >> b;
        heap->insert(b);
    }
    int m,add,k;
    cin >> m;
    for(; m > 0; --m)
    {
        cin >> k;
        cin >> add;
        heap->increaseKey(k-1,add);
    }
    heap->print();
    return 0;
}