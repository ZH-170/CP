#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;
#define ll long long
#define lint long long int
#define ull unsigned long long
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define MP make_pair

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define max(a, b) ((a > b)? a : b)
#define min(a, b) ((a < b)? a : b)
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)

// const int N = 1e5;
const int M = 1e9 + 7; 
const int inf = 0x3f3f3f3f;
const ll int INF = 1e18;


// find the largest number smaller than or equal to x
int low_bin(int l, int r, function<bool(int)> f){
    while(l < r){
        int mid = l+ (r-l+1)/2;
        if(f(mid)){
            l = mid;
        }
        else{
            r = mid-1;
        }

    }
    return l;
}

// find the smallest number larger than x
int hi_bin(int l, int r, function<bool(int)> f){
    while(l < r){
        int mid = l + (r-l)/2;
        if(f(mid)){
            r = mid;
        }
        else l = mid+1;
    }
    return l;
}


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // ifstream cin();
    // ofstream cout();
    
    // find nearest x, y -> double binary search
    // then check that one, then the other one
    // but time complexity = O(log n * log n * N * G)
    // if lucky then pass

    // but very complicated so first try the brute force one

    lint G, N;
    cin >> G >> N;
    
    vector<pair<pair<lint, lint>, lint>> g; // => {{x, y}, t}
    vector<pair<int, int>> gxy, gt;
    for(lint i = 0; i < G; i ++){
        lint temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        g.pb({{temp1, temp2}, temp3});
        gxy.pb({temp1, temp2});
        gt.pb({temp3, i});
    }

    vector<pair<pair<lint, lint>, lint>> v;

    sort(gt.begin(), gt.end());
    
    lint ans = 0;
    // if one of the g the cow can't make it => it is innocent
    
    for(lint i = 0; i < N; i ++){
        lint x, y, t;
        cin >> x >> y >> t;

        for(lint j = 0; j < G; j ++){
            pair<lint, lint> pos1 = {x, y}, pos2 = g[j].first;
            lint t1 = t, t2 = g[j].second;
            // cout << endl << "i " << i << " j " << j << endl;
            // cout << "pos1: " << pos1.first << " " << pos1.second << endl;
            // cout << "pos2: " << pos2.first << " " << pos2.second << endl;
            // cout << "t1: " << t1 << " t2: " << t2 << endl; 
            if( (pos1.first - pos2.first)*(pos1.first - pos2.first) + (pos1.second - pos2.second)*(pos1.second - pos2.second) > (t1-t2)*(t1-t2)){
                ans++;
                break;
            }

            // if(j == G-1){cout << i << endl; ans++;}
        }
    }
    
    cout << ans << endl;
}