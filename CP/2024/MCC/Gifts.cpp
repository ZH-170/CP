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

const int N = 1e5;
const int M = 1e9 + 7; 
const int inf = 0x3f3f3f3f;
const ll int INF = 1e18;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // ifstream cin();
    // ofstream cout();
    
    int n, m;
    cin >> n >> m;

    vector<int> t;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i ++){
        int temp;
        cin >> temp;
        v.pb({temp, i});
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b){
        if(a.first == b.first){return a.second < b.second;}
        else return a.first < b.first;
    });

    vector<bool> check(n, false);
    for(int i = 0; i < m; i ++){
        check[v[i].second] = true;
    }
    for(auto i : check){cout << i << " ";} cout << endl;
    
}