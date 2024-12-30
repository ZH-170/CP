#include <bits/stdc++.h>
#define lint long long int
#define pb push_back
using namespace std;

int main(){
    lint n, x;
    cin >> n >> x;
    
    vector<pair<lint, lint>> v;
    for(lint i = 0; i < n; i ++){
        lint temp;
        cin >> temp;
        v.pb({temp, i});
    }
    sort(v.begin(), v.end());

    lint l = 0, r = v.size()-1;

    bool check = true;
    while(l < r){
        if(v[l].first + v[r].first < x){
            l++;
        }
        else if(v[l].first + v[r].first > x){
            r--;
        }
        else if(v[l].first + v[r].first == x){
            cout << v[l].second+1 << " " << v[r].second+1 << endl;
            check = false;
            break;
        }
    }
    if(check){cout << "IMPOSSIBLE" << endl;}
}