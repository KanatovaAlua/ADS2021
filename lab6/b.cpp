#include <iostream>
#include <vector>

using namespace std;

int prefix_function(string s){
    int n = s.size();
    vector<int> p(n,0);
    for(int i = 1; i < n; i++){
        int j = p[i - 1];
        while(j > 0 && s[j] != s[i])
            j = p[j - 1];
        if(s[j] == s[i])
            j++;
        p[i] = j;
    }
    return n - p[s.size() - 1];
}

int main(){
string s;
cin >> s;
int p = prefix_function(s);
if(s.size() % p == 0){
    cout << s.size() / p;
}
else cout << 1;
    return 0;
}