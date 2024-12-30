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

const int N = 2e5;
const int M = 1e9 + 7; 
const int inf = 0x3f3f3f3f;
const ll int INF = 1e18;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    ifstream cin("pairup.in");
    ofstream cout("pairup.out");
    
    
    int n;
    cin >> n;
    vector<pair<lint, lint>> v;
    for(int i = 0; i < n; i ++){
        lint temp1, temp2;
        cin >> temp1 >> temp2;
        v.pb({temp2, temp1});
    }
    sort(v.begin(), v.end());
    
    lint l = 0, r = v.size()-1;
    lint max_time = 0;
    while(l < r){
        if(v[l].second < v[r].second){
            v[r].second -= v[l].second;
            l++;
            max_time = max(max_time, v[r].first+v[l].first);
        }
        else if(v[l].second > v[r].second){
            v[l].second -= v[r].second;
            r--;
            max_time = max(max_time, v[r].first+v[l].first);
        }
        else if(v[l].second == v[r].second){
            l++;
            r--;
            max_time = max(max_time, v[r].first+v[l].first);
        }
    }

    cout << max_time << endl;
    
}