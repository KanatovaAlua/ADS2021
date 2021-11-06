#include <iostream>
#include <vector>
#define ll long long
using namespace std;

class MaxHeap {
    public:
    vector<ll> a;

    ll parent(ll i) {
        return (i - 1) / 2;
    }

    ll left(ll i) {
        return 2 * i + 1;
    }

    ll right(ll i) {
        return 2 * i + 2;
    }

    int getMax(){
        return a[0];
    }
 
    void insert(ll k,int n) {
        if(a.size() == n){
            cout << "-1" << endl;
            return;
        }
        a.push_back(k);
        ll i = a.size() - 1;
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        cout << i + 1 << endl;
    }

    void siftUp(){
        ll i = a.size() - 1;
        while (i >= 0){
            if (a[parent(i)] < a[i])
                swap(a[parent(i)], a[i]);
            i--;
        }
    }

    int siftDown(ll i) { 
        if(left(i) > a.size() - 1){
            return i;
        }
        int j = left(i);
        if(right(i) < a.size() && a[right(i)] > a[j])
            j = right(i);
        if(a[i] < a[j]) {
            swap(a[i], a[j]);
            return siftDown(j);
        }
            return i;
    }

    void extractMax(){
        if(a.size() == 0){
            cout << "-1" << endl;
            return;
        }
        if(a.size() == 1){
            cout << "0" << " " << getMax() << endl;
            a.pop_back();
            return;
        }
        int root_value = getMax();
        swap(a[0],a[a.size()-1]);
        a.pop_back();
        if(a.size() > 0){
            cout << siftDown(0) + 1 << " ";
        }
        cout << root_value << endl;
    }


    void print() {
        int nn = a.size();
        for (int i = 0; i < nn; i++) 
            cout << a[i] << " ";
        
        cout << endl;
    }
};

int main(){
    ll n,m;
    cin >> n >> m;
    MaxHeap *heap = new MaxHeap();

    for(ll i = 0; i < m; i++){
        int q;
        cin >> q;
        if(q == 1){
            heap->extractMax();
        }
        if(q == 2){
            int add;
            cin >> add;
            heap->insert(add,n);
        }
        
    }

    heap->print();
    return 0;
}