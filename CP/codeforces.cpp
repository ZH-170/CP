#include <bits/stdc++.h>
#define lint long long
#define pb push_back
using namespace std;
int MOD = 1e9 + 7;
int INF = 1e9;

int main(){
   
    int n, t, T;
    cin >> n >> t >> T;
   
    vector<int> v(t, 0);
    bool zero = false;

    vector<int> vv;
    for(int i = 0; i < n; i ++){
        int s;
        cin >> s;
        vv.pb(s);
    }

    sort(vv.begin(), vv.end());

    for(int i = 0; i < n; i ++){
       int s = vv[i];

        int temp = s%t;

        if(v[temp] == 0){
            v[temp] = s;
        }
    }


    // for(int i = 0; i < v.size(); i ++){
        // cout << i << " " << v[i] << endl;
    // }


    lint sum = 0;
    for(int i = 0; i < t; i ++){
        sum += (T-v[i]+1+(t-1))/t;
        // cout << T-v[i]+1 << endl;
    }

    cout << sum;
}




