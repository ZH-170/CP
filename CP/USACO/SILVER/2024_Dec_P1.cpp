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
    
    lint T;
    cin >> T;
    for(lint z = 0; z < T; z++){
        lint n;
        cin >> n;
        vector<lint> v;
        lint sum = 0;
        lint tempsum = 0;
        for(lint i = 0; i < n; i ++){
            lint temp;
            cin >> temp;
            v.pb(temp);
            sum += (lint)temp;
            if(i < (n/2)-1){
                // cout << i << " ";
                tempsum += (lint)temp;
            }
        }

        // cout << endl << endl;
        // if(T == 2 && n == 4){
            if(n == 2){
                cout << v[0]+v[1] << " " << 0 << endl;
            }
            else{
                lint m_s = tempsum;
                for(lint i = (n/2)-2; i >= 0; i --){
                    tempsum -= v[i];
                    tempsum += v[n-1- ((n/2)-2 - i)];
                    // cout << i << " " << n-1- ((n/2)-2 - i) << endl;
                    
                    m_s = max(tempsum, m_s);
                }

                cout << sum - m_s << " " << m_s << endl;

            }
        // }
        // else{
        //     cout << ((n/2)+1)*v[0] << " " << ((n/2)-1)*v[0] << endl;
        // }


    }
    
}
