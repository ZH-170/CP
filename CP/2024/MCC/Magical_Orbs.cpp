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
    
    // int T;
    // cin >> T;
    // while(T--){
    //     int n;
    //     cin >> n;
    //     vector<lint> v;
    //     for(int i = 0; i < n; i ++){
    //         lint temp;
    //         cin >> temp;
    //         v.pb(temp);
    //     }
    //     sort(v.begin(), v.end());
    //     for(auto i : v){cout << i << " ";} cout << endl << endl;

    //     for(int i = 0; i < n; i ++){
    //         v[i] %= M;
    //     }

    //     while(v.size()!=1){
    //         int mid = ((v.size() + 1)/2)-1; //! check for extreme case
            
    //         vector<lint> v1;
    //         for(int i = 0; i < v.size()/2; i ++){
    //             cout << i << " " << mid-i << " " << v.size()-1-i << endl;
    //             v1.pb(v[mid-i] + v[v.size()-1-i] + v[v.size()-1-i]);
    //         }
    //         if(v.size()%2==1){
    //             v1.pb(v[0]);
    //         }
            
    //         reverse(v1.begin(), v1.end());
    //         v = v1;
    //         for(auto i : v){cout << i << " ";} cout << endl << endl;
            
    //     }

    //     cout << v[0] << endl;

        //* a bit lazy to type down the code
        //* but typically is just first sort the vector then take the middle and the back then add x+2y like this lah
        //* maybe not middle + 2* back, maybe is (back-1)+2*back or smtg else
        //! but now I think is middle + 2*back lah

        //? ok conseptional wrong
        //? should 堆雪球 越滚越大
        //? so if it is in this case then just use the back two 
        // a b c d e
        // d+e+e
        // c+2(d+e+e)
        // b+2(c+2(d+e+e))

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<lint> v;
        for(int i = 0; i < n; i ++){
            lint temp;
            cin >> temp;
            v.pb(temp);
        }
        sort(v.begin(), v.end(), greater<lint>());
        // for(auto i : v){cout << i << " ";} cout << endl;

        for(int i = 0; i < n; i ++){
            v[i] %= M;
        }

        lint sum = v[0];
        sum %= M;
        // cout << sum << endl;
        for(int i = 1; i < n; i ++){
            sum *= 2;
            sum %= M;
            
            sum += v[i];
            sum %= M;
            
            // cout << sum << endl;
        }

        cout << sum << endl;
    }
    // }
    
}
// 2
// 3
// 1 2 1
// 4
// 1 2 3 2

// 11
// 37