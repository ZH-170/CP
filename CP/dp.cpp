#include <bits/stdc++.h>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;
int MOD = 1e9 + 7;
int INF = 1e9;

int n, m;
vector<vector<int>> memory(n+1, vector<int>(m+1, -1));

int dp(int x, int y){
    if(x%2==1 && y%2==1) return 0;
    if(x*y == 2) return 1;

    if(memory[x][y] != -1) return memory[x][y];
    cout << x << " " << y << endl;

    for(int i = 1; i <= y/2; i ++){
        memory[x][y] += dp(x, y-i)*dp(x, i);
        cout << dp(x, y-i) << " " << dp(x, i) << endl;
    }
    for(int i = 1; i <= x/2; i ++){
        memory[x][y] += dp(x-i, y)*dp(i, y);
        cout << dp(x-i, y) << " " << dp(i, y) << endl;
    }

    return memory[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cin >> n >> m;

    // cout << dp(n, m);
    int n, m;
    cin >> n >> m;
    vector<int> visited(1003, false);

    queue<int> q;
    q.push(n);
    q.push(m);
    while(!q.empty()){
        int x = q.front();
        q.pop();

        if(x > 1000){continue;}
        visited[x] = true;
        q.push(x+n);
        q.push(x+m);

    }

    for(int i = 0; i < visited.size(); i ++){
        if(visited[i]){cout << i << endl;}
    }


    return 0;
}


// dp[i] = length of longest subsequence till i



// 7 3 5 3 6 2 9 8



// dp, binary search
// dp[i] = till i 


// 4 5 1 3

// 1st 3
// 4 5 1

// 2nd 4
// 5 1

// 1st 3 + 5 = 8
// 1

// 2nd 4 + 1 = 5

// dp[1][j] = max points of first player in the j_th round = max points of first player in j-1_th round + min(second take left, second take right)

// dp[1][1] = max(take_left , take_right)
// dp[2][1] = max(take_left , take_right)
// dp[1][2] = max()



// dp[4][7] = max(dp[4][1] + dp[4][6], dp[4][2] + dp[4][3], )

// y = 7
// x,6 x,1
// x,5 x,2
// x,4 x,3
// -> y <= 7/2

// y = 6
// x,5 x,1
// x,4 x,2
// x,3 x,3
// -> y <= 6/2