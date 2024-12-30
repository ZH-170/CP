// #include <iostream>
// #include <fstream>
// #include <iomanip>
// #include <algorithm>
// #include <functional>
// #include <numeric>
// #include <cstring>
// #include <string>
// #include <cmath>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <set>
// #include <map>

// using namespace std;
// #define ll long long
// #define lint long long int
// #define ull unsigned long long
// #define fi first
// #define se second
// #define pf push_front
// #define pb push_back
// #define MP make_pair

// #define all(v) v.begin(), v.end()
// #define rall(v) v.rbegin(), v.rend()

// #define max(a, b) ((a > b)? a : b)
// #define min(a, b) ((a < b)? a : b)
// #define max3(a, b, c) max(max(a, b), c)
// #define min3(a, b, c) min(min(a, b), c)

// const int M = 1e9 + 7; 
// const int inf = 0x3f3f3f3f;
// const ll int INF = 1e18;
// const lint MOD = 998244353;

// int cn(char a, char b){
//     if(a == '0' && b == '0'){return 1;}
//     if(a == '0' && b == '1'){return 2;}
//     if(a == '1' && b == '0'){return 3;}
//     if(a == '1' && b == '1'){return 4;}
// }

// int main(){
    
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     // ifstream cin(); 
//     // ofstream cout();
    
//     int n, k;
//     cin >> n >> k;

//     vector<vector<lint>> dp(5, vector<lint>(k+1, 0));
//     dp[1][0] = 1;
//     dp[2][0] = 0;
//     dp[3][0] = 0;
//     dp[4][0] = 1;

//     if(k > 0){
//         for(int i = 1; i <= k; i ++){
//             dp[1][i] = dp[1][i-1] + dp[1][i-1]; dp[1][i] %= MOD;
//             dp[2][i] = dp[2][i-1] + dp[4][i-1]; dp[2][i] %= MOD;
//             dp[3][i] = dp[4][i-1] + dp[3][i-1]; dp[3][i] %= MOD;
//             dp[4][i] = dp[3][i-1] + dp[2][i-1]; dp[4][i] %= MOD;
//             cout << i << endl;
//             cout << dp[1][i] << " " << dp[2][i] << " " << dp[3][i] << " " << dp[4][i] << endl;
//         }
//     }
//     cout << dp[1][k] << " " << dp[2][k] << " " << dp[3][k] << " " << dp[4][k] << endl << endl;

//     // vector<lint> dp(5, 0);
//     // dp[1] = 1;
//     // dp[2] = 0;
//     // dp[3] = 0;
//     // dp[4] = 1;

//     // for(int i = 1; i <= k; i ++){
//     //     lint temp1 = dp[1], temp2 = dp[2], temp3 = dp[3], temp4 = dp[4];
//     //     dp[1] = temp1+temp1; dp[1] %= MOD;
//     //     dp[2] = temp2+temp4; dp[2] %= MOD;
//     //     dp[3] = temp4+temp3; dp[3] %= MOD;
//     //     dp[4] = temp3+temp2; dp[4] %= MOD;
//     // }


    // string s;
    // // cin >> s;
    // for(int i = 0; i < n; i ++){
    //     char c;
    //     cin >> c;
    //     s += c;
    // }

    // lint sum = 0;
    // lint N = 0;
    // int temp;
    // for(int i = 0; i < n/2; i ++){
    //     // cout << i << " " << n-1-( i*(2) ) << endl;
    //     N += (n-1-(2*i));
    //     // cout << N << endl;
    //     // cout << i << " " << i+1 << "||" << n-1-i << " " << n-2-i << endl;
    //     if(i == (n/2)-1 && n%2==0){
    //         lint temp = N*dp[cn(s[n-2-i], s[n-1-i])][k];
    //         temp %= MOD;
    //         sum += temp;
    //         sum %= MOD;
    //     }
    //     else{
    //         lint temp1 = N*dp[cn(s[i], s[i+1])][k];
    //         temp1 %= MOD;
    //         // cout << "TEMP1: " << temp1 << endl;
    //         sum += temp1;
    //         sum %= MOD;
    //         // cout << "SUM1: " << sum << endl;

    //         lint temp2 = N*dp[cn(s[n-2-i], s[n-1-i])][k];
    //         temp2 %= MOD;
    //         // cout << "TEMP2: " << temp2 << endl;
    //         sum += temp2;
    //         sum %= MOD;
    //         // cout << "SUM: " << sum << endl;
    //     }
        
    //     // 6334937
    //     // cout << sum << endl;
    // }
    
    // cout << sum << endl;
// }

// 00: dp(1, k)
// 0 -> 1
// 1 -> 2
// 2 -> 4
// 3 -> 8
// 4 -> 16
// ...
// n -> 2^n

// 01 & 10: dp(2, k) & dp(3, k)
// 0 -> 0
// 1 -> 1 = J1
// 2 -> 1 = J2
// 3 -> 3 = J3
// 4 -> 5 = J4
// 5 -> 11 = J5
// 6 -> 21 = J6
// 7 -> 43 = J7
// ...
// n -> Jn

// 11: dp(4, k)
// 0 -> 1
// 1 -> 0
// 2 -> 2 = 2*J1 = J2+1
// 3 -> 2 = 2*J2 = J3-1
// 4 -> 6 = 2*J3 = J4+1
// 5 -> 10 = 2*J4 = J5-1
// 6 -> 22 = 2*J5 = J6+1
// 7 -> 42 = 2*J6 = J7-1
// ...
// n -> 2*J(n-1) = Jn+(-1)^n



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

const lint N = 1e18;
const lint M = 998244353; 
const int inf = 0x3f3f3f3f;
const ll int INF = 1e18;


int cn(char a, char b){
    if(a == '0' && b == '0'){return 1;}
    if(a == '0' && b == '1'){return 2;}
    if(a == '1' && b == '0'){return 3;}
    if(a == '1' && b == '1'){return 4;}
}


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // ifstream cin();
    // ofstream cout();
    
    vector<lint> v(5, 0);

    //* when k = 1e18
    //* g(00)

    lint exp1 = (N/M) + (N%M);
    // cout << exp1 << endl;
    lint exp2 = (exp1/M) + (exp1%M);
    // cout << exp2 << endl;

    v[1] = 1;
    for(lint i = 0; i < exp2; i ++){
        v[1] *= 2;
        v[1] %= M;
    }

    cout << "v[1] = " << v[1] << endl;

    //* g(01) and g(10)
    //* since Jn = ((2^n) - (-1)^n)/3
    //* then Jn mod M = ((2^n) - (-1)^n) * 3^(-1) mod M
    //* since n = 1e18, hence Jn mod M = ((2^n)-1)*3^(-1) mod M
    //* find modulo inverse of 3 mod M

    lint im3;
    for(int i = 2; i <= M; i ++){
        if(i*3 % M == 1){im3 = i; break;}
    }
    // cout << im3 << endl;

    v[2] = 0;
    for(lint i = 1; i <= v[1]-1; i ++){
        v[2] += im3;
        v[2] %= M;
    }
    v[3] = v[2];

    cout << "v[2] = " << v[2] << "     v[3] = " << v[3] << endl;

    //* g(11)
    //* Jn + (-1)^n
    
    v[4] = v[2] + 1;
    
    cout << "v[4] = " << v[4] << endl;

    //* and now for the rest

    lint n, k;
    cin >> n >> k;
    
    string s;
    cin >> s;
    
    lint sum = 0;
    lint a = 0;
    // lint max_A = 0; //* 5000(5e3) -> 6250000(625e4), 200000(2e5) -> 10000000000 (1e10)
    for(int i = 0; i < n/2; i ++){
        a += (n-1-(2*i));
        a %= M;
        // max_A = max(a, max_A);
        // cout << i << endl;
        if(i == (n/2)-1 && n%2==0){
            lint temp = a*v[cn(s[n-2-i], s[n-1-i])];
            temp %= M;
            sum += temp;
            sum %= M;
        }
        else{
            lint temp1 = a*v[cn(s[i], s[i+1])];
            temp1 %= M;
            // cout << "TEMP1: " << temp1 << endl;
            sum += temp1;
            sum %= M;
            // cout << "SUM1: " << sum << endl;

            lint temp2 = (lint)a*(lint)v[cn(s[n-2-i], s[n-1-i])];
            temp2 %= M;
            // if(temp2 < 0){cout << N << " " << v[cn(s[n-2-i], s[n-1-i])] << endl;}
            // cout << "TEMP2: " << temp2 << endl;
            sum += temp2;
            sum %= M;
            // cout << "SUM: " << sum << endl;
        }

    }
    cout << "ANS = " << sum;
    // cout << max_A << endl;
    // lint temp1 = max_A * v[1], temp2 = max_A * v[2], temp3 = max_A * v[3], temp4 = max_A * v[4];
    // cout << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << endl;
}