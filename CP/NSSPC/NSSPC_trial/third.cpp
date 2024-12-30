#include <bits/stdc++.h>
#define lint long long int
#define pb push_back
using namespace std;

vector<int> parent;
int find_parent(int x){
    cout << x << endl;
    if(parent[x] == x){return x;}
    else{
        parent[x] = find_parent(x);
        return parent[x];
    }

}

int main(){
    int n;
    cin >> n;
    parent = vector<int>(n);
    for(int i = 0; i < n; i ++){
        parent[i] = i;
    }

    for(int i = 0; i < n-1; i ++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        parent[x] = y;
    }
    
    int q;
    cin >> q;
    for(int i = 0; i < q; i ++){
        int x;
        cin >> x;
        x--;
        cout << find_parent(x) << endl;
    }
}