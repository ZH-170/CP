#include <bits/stdc++.h>
#define lint long long int
#define pb push_back
using namespace std;

const int INF = 1e9;
const int MOD = 1E9+7;

int draw_territory(int N, int A, int B, vector<int> D, vector<int> L){
    lint length = L[0];
    lint sum = 0, times = 0;
    for(lint i = 0; i <= length; i ++){
        sum += ((i*(i+1))%MOD);
        sum %= MOD;
        times += i+1;
    }
    sum *= B;
    sum %= MOD;
    sum += ((times*A)%MOD);
    return sum;

    vector<vector<bool>> visited(4001, vector<bool>(4000, false));
    int x = 2000, y = 2000;
    visited[x][y] = true;
    int dx[7] = {0, 0, 1, 1, 0, -1, -1}, dy[7] = {0, 1, 1, 0, -1, -1, 0};
    for(int i = 0; i < N; i ++){
        for(int j = 0; j < L[i]; j ++){
            x += dx[D[i]]; y+=dy[D[i]];
            visited[x][y] = true;
        }
    }

    vector<vector<int>> d(4001, vector<int>(4001));
    queue<pair<int, int>> q;

    q.push({0, 0});

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();

        if(!visited[x][y]){
            for(int i = 1; i <= 6; i ++){
                x += ax[i]; y += ay[i];
                if(x >= 0  &&  y >= 0  &&  x <= 4001  &&  y <= 4001){
                    q.push({x, y});
                    visited[x][y] = true;
                    d[x][y] = -1;
                }
                x -= ax[i]; y -= ay[i];
            }
        }
    }

    
}

//? 1: (X, Y+1)
//? 2: (X+1, Y+1)
//? 3: (X+1, Y)
//? 4: (X, Y-1)
//? 5: (X-1, Y-1)
//? 6: (X-1, Y)
    
int main(){
    
    vector<int> D = {2, 4, 6};
    vector<int> L = {3, 3, 3};
    cout << draw_territory(3, 1, 0, D, L);
}

//! A+dB

// (X, Y)

//? 1: (X, Y+1)
//? 2: (X+1, Y+1)
//? 3: (X+1, Y)
//? 4: (X, Y-1)
//? 5: (X-1, Y-1)
//? 6: (X-1, Y)

// 0 0 0 0 0
// 0 0 1 1 0
// 0 1 0 1 0
// 0 1 1 2 0
// 0 0 2 0 0

// for(int i = 0;)

// make a graph, 

// 0 0 0 ... 2000 ... 0 0 0 | 0 0 0 ... 2000 ... 0 0 0
// 0
// 0
// 0
// .
// .
// .
// 0
// 0
// 0
// 0 0 0 ... 2000 ... 0 0 0 | 0 0 0 ... 2000 ... 0 0 0
// 0
// 0
// 0
// .
// .
// .
// 0
// 0
// 0
// 0 0 0 ... 2000 ... 0 0 0 | 0 0 0 ... 2000 ... 0 0 0

// set the initial point to be (2000, 2000)
