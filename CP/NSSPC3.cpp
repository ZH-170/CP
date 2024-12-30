#include <bits/stdc++.h>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;
lint MOD = 1e9 + 7;
int INF = 1e9;

vector<int> multi(vector<int> x ,vector<int> y){
    
    int m = x.size();
    int n = y.size();
    vector<int> ans(m+n-1, 0);
    for(int i = 0; i <= m+n-2; i ++){
        
        for(int j = 0; j <= i; j ++){
            if(j < m && i-j < n) ans[i] += (x[j]*y[i-j]);
        }
    }
    return ans;
}

int main() {
    

    // vector<int> a = {0, 0, 0, -1, 1, -1}, b = {1, -1, 1, -1, 1};
    // for(auto i : v(a, b)){
    //     cout << i << " ";
    // }
    // cout << endl;

    int n;
    cin >> n;
    int s1;
    cin >> s1;
    vector<int> v;
    for(int i = 0; i < s1; i ++){
        int temp;
        cin >> temp;
        v.pb(temp);
    }

    for(int i = 0; i < n-1; i ++){
        int s;
        cin >> s;
        vector<int> b;
        for(int j = 0; j < s; j ++){
            int temp;
            cin >> temp;
            b.pb(temp);
        }
        v = multi(v, b);
        // v.clear();
        // v = v1;
        // for(auto i : v){cout << i << " ";} cout << endl;
    }
    
    for(auto i : v) cout << i << " ";
    // int n;
    // cin >> n;
    // vector<vector<int>> v(10);
    // int sum_ex = 0;
    // for(int i = 0; i < n; i ++){
        
    //     int s;
    //     cin >> s;
    //     sum_ex += s;
    //     for(int j = 0; j < s; j ++){
    //         int temp;
    //         cin >> temp;
    //         v[i].pb(temp);
    //     }
    // }

    // vector<int> a = {1, -1, 1}, b = {0, 0, 0, -1};
    // for(auto i : v(a, b)){
    //     cout << i << " ";
    // }
    // cout << endl;

    // vector<int> a = {0, 0, 0, -1, 1, -1}, b = {1, -1, 1, -1, 1};
    // for(auto i : v(a, b)){
    //     cout << i << " ";
    // }
    // cout << endl;

    return 0;
}

// 2
// 3 1 1 1
// 4 1 0 0 1
// 1 1 1 1 1 1

// 3
// 3 1 -1 1
// 4 0 0 0 -1
// 5 1 -1 1 -1 1
// 0 0 0 -1 2 -3 3 -3 2 -1