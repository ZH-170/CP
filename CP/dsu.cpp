#include <bits/stdc++.h>
#define lint long long
#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int MOD = 1e9 + 7;
int INF = 1e9;




int main() {

    // IOS
    // ios_base::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("mootube.in");
    ofstream cout("mootube.out");

    int n, q;

    cin >> n >> q;
    vector<vector<pair<int, int>>> adj(n+1);
    vector<vector<int>> dis(n+1, vector<int>(n+1, INF));
    vector<bool> visited(n+1, false);
    

    for(int i = 1; i < n; i ++){
        int a, b, w;
        cin >> a >> b >> w;

        visited[a] = true;
        visited[b] = true;

        adj[a].pb({b, w});
        adj[b].pb({a, w});

        dis[a][b] = w;
        dis[b][a] = w;

        if(a>b){swap(a, b);}

        for(int i = 1; i <= b; i ++){
            if(i != a  &&  visited[i]){
                dis[i][b] = min(dis[i][a], dis[a][b]);
                dis[b][i] = dis[i][b];
            }
        }

        
    }

    for(int i = 0; i <= n; i ++){
        dis[i][i] = 0;
    }

    // for(int i = 1; i <= n; i ++){
    //     for(int j = 1; j <= n ; j ++){
    //         cout << dis[i][j] << " ";
    //     }
     
    //     cout << endl;
    // }

    for(int i = 0; i < q; i ++){
        int v, k;
        cin >> k >> v;
        int ans = 0;
        for(int j = 1; j <= n; j ++){
            if(dis[j][v] >= k){ans++;}
        }
        cout << ans << endl;
    }



    return 0;
}

// 4 3
// 1 2 3
// 2 3 2
// 2 4 4
// 1 2
// 4 1
// 3 1

// how to find the lowest num in the path?

// dfs or what?

// can dsu make it?