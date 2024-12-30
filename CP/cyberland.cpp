#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;
lint MOD = 1e9 + 7;
int INF = 1e9;

double solve(int N, int M, int K, int H, vector<int> x, vector<int> y, vector<int> c, vector<int> arr){
    vector<vector<int>> v(3, vector<int>(3, 0));
    v[0][0] = 0;
    v[1][1] = 0;
    v[2][2] = 0;

    for(int i = 0; i < M; i ++){
        v[x[i]][y[i]] = c[i];
        v[y[i]][x[i]] = c[i];
    }
    
    int sum1 = 0; // v[0][H]
    if(arr[H] == 0){sum1 = 0;}
    if(arr[H] == 1){sum1 += v[0][H];}
    if(arr[H] == 2){sum1 += v[0][H]/2;}

    int sum2 = 0; // v[0][3-H]+v[3-H][H]
    if(arr[3-H] == 0){sum2 = 0;}
    if(arr[3-H] == 1){sum2 += v[0][3-H];}
    if(arr[3-H] == 2){sum2 += v[0][3-H]/2;}

    if(arr[H] == 0){sum2 = 0;}
    if(arr[H] == 1){sum2 += v[3-H][H];}
    if(arr[H] == 2){sum2 += v[3-H][H]; sum2 /= 2;}

    if(v[0][H] == 0) return sum2;
    else if(v[0][3-H] == 0 || v[3-H][H] == 0){return sum1;}
    else return min(sum1, sum2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solve(3, 2, 30, 2, {1, 2}, {2, 0}, {12, 4}, {1, 2, 1});

    return 0;
}

// normal comment
//! comment important

// 0 3-h h
// 0 h
// if no 0 h then go 0 3-h 1
// else if no 0 3-h or 3-h h then go 0 h
// else 

//    0  1  2
// 0  0
// 1     0
// 2        0

