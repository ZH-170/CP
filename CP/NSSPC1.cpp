#include <bits/stdc++.h>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;
lint MOD = 1e9 + 7;
int INF = 1e9;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            cin >> v[i][j];
        }
    }
    // for(int i = 0; i < n; i ++){
    //     for(int j = 0; j < m; j ++){
    //         cout << v[i][j];
    //     }
    //     cout << endl;
    // }

    int x = 0, y = 1;
    int pre_x, pre_y;
    int ans = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[x][y] = true;

    while(x!=n-1 || y!=m-2){
        
        // if(ans == 10){break;}
        
        
        // cout << x << " " << y << endl;
        visited[x][y] = true;
        
        // cout << v[x][y-1] << " " << v[x+1][y] << " " << v[x][y+1] << " " << v[x-1][y] << endl;
        ans++;
        if(v[x][y-1] != '#' && !visited[x][y-1]){pre_x = x; pre_y = y; y-=1;}
        else if(v[x+1][y] != '#' && !visited[x+1][y]){pre_x = x; pre_y = y; x+=1;}
        else if(v[x][y+1] != '#' && !visited[x][y+1]){pre_x = x; pre_y = y; y+=1;}
        else if(v[x-1][y] != '#' && !visited[x-1][y]){pre_x = x; pre_y = y; x-=1;}
        else{x = pre_x; y = pre_y;}
    }
    cout << ans;


    return 0;
}

// 3 20
// 5 10 3 -> +5, 3
// 6 10 1 -> +4, 1
// 4 15 2 -> +11, 2

// 5+6+4 = 15
