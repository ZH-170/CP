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
    
    // ifstream cin();
    // ofstream cout();
    
    int T;
    cin >> T;
    while(T--){
        int n, X1;
        cin >> n >> X1;
        vector<vector<pair<int, int>>> target(n);
        int max_y=-1e9-1, max_yx, min_y=1e9+1, min_yx;
        for(int i = 0; i < n; i ++){
            int y1, y2, x2;
            target[i].pb({X1, y1}); //* left down
            target[i].pb({X1, y2});
            target[i].pb({x2, y1});
            target[i].pb({x2, y2}); //* right up

            if(y2 > max_y){
                max_y = y2;
                max_yx = x2;
            }
            else if(y2 == max_y){
                max_yx = min(max_yx, x2);
            }


            if(y1 < min_y){
                min_y = y1;
                min_yx = X1;
            }
        }

        vector<int> s;
        int pos=0, neg=0;
        int pos_m=0, neg_m=0;
        for(int i = 0; i < 4*n; i ++){
            int temp;
            cin >> temp;
            s.pb(temp);
            if(temp > 0){pos++; pos_m = min(pos_m, temp);}
            else{neg++; neg_m = max(neg_m, temp);}
        }

        if(pos < n || neg < n){cout << -1 << endl;}
        else{
            ;
        }




    }
    
}


larger s
(positive)
-> upper y, inner x
(negative)
-> lower y, inner x

smaller s
(positive)
-> lower y, outer x
(negative)
-> upper y, outer x


SORT AND SEARCHING !!!

sort positive, negative s

sort 