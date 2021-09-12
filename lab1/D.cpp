#include <iostream>
#include <queue>
using namespace std;

int main(){

    queue <string> a, b, c;

    int n; 
    string s;

    while(cin >> n) {
        cin >> s;
        if(n == 9) 
        a.push(s);
        else if (n == 10) 
        b.push(s);
        else 
        c.push(s);
    }
    while(!a.empty()) {
        cout << "9 " << a.front() << endl;
        a.pop();
    }
    while(!b.empty()) {
        cout << "10 " << b.front() << endl;
        b.pop();
    }
    while(!c.empty()) {
        cout << "11 " << c.front() << endl;
        c.pop();
    }
}