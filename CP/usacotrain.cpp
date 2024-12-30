// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <cmath>
// #include <fstream>
// #define lint long long
// #define pb push_back
// #define mp make_pair
// using namespace std;
// lint MOD = 1e9 + 7;
// lint INF = 1e9;

// int n;
// vector<int> dis(n, 0);
// vector<bool> visited(n, false);
// vector<vector<int>> adj(n+1);

// void dfs(int v, int u){
//     visited[v] = true;
//     dis[u]++;
//     for(auto i : adj[v]){
//         if(!visited[i]){
//             dfs(i, u);
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     ifstream cin("moocast.in");
//     ofstream cout("moocast.out");

//     cin >> n;
//     vector<pair<int, int>> pos;
//     vector<int> power;

//     adj.resize(n+1);
//     dis.resize(n, 0);

//     for(int i = 0; i < n; i ++){
//         int x, y, z;
//         cin >> x >> y >> z;
//         pos.pb({x, y});
//         power.pb(z);
//     }
//     for(int i = 0; i < n-1; i ++){
//         for(int j = i+1; j < n; j ++){
//             int x1=pos[i].first, y1=pos[i].second;
//             int x2=pos[j].first, y2=pos[j].second;
//             // cout << i << " " << j << " ";
//             // cout << sqrt( (y1-y2)*(y1-y2) + (x1-x2)*(x1-x2) ) << endl;
//             if( (y1-y2)*(y1-y2) + (x1-x2)*(x1-x2)  <=  power[i]*power[i]){
//                 adj[i].pb(j);
//             }
//             if( (y1-y2)*(y1-y2) + (x1-x2)*(x1-x2)  <=  power[j]*power[j]){
//                 adj[j].pb(i);
//             }
//         }
//     }

//     for(int i = 0; i < n; i ++){
//         visited.resize(n, false);
        
//         visited[i] = true;
//         dfs(i, i);
//     }

//     int m = 0;
//     for(auto i : dis){m = max(m, i);}
//     cout << m;

//     // for(lint i = 0; i < n+1; i ++){
//     //     cout << i << " : ";
//     //     for(auto j : adj[i]){cout << j << " ";}
//     //     cout << endl;
//     // }

//     return 0;
// }


// // 4
// // 1 3 5
// // 5 4 3
// // 7 2 1
// // 6 1 1


// //! now what?

// //? find from every cow what is the longest distance they can reach?
// //? dfs ?




//* codeforces

// #include <bits/stdc++.h>
// #define lint long long int
// #define pb push_back
// using namespace std;

// lint n, m;
// vector<vector<lint>> adj(n+1);
// vector<bool> visited(n+1);

// void check(lint x){
//     for(auto i : adj[x]){
//         visited[i] = true;
//     }
// }

// int main() {

    // int T;
    // cin >> T; 
    // while(T--){
    //     adj.clear();
    //     visited.clear();
    //     cin >> n >> m;    
    //     adj.resize(n+1);
    //     visited.assign(n+1, false);
        
    //     for(lint i = 0; i < m; i ++){
    //         lint a, b;
    //         cin >> a >> b;
    //         adj[a].pb(b);
    //         adj[b].pb(a);
    //     }

    //     vector<lint> ans;

    //     for(int i = 1; i < n+1; i ++){
    //         if(!visited[i]){
    //             ans.pb(i);
    //             check(i);
    //         }
            
    //     }

    //     cout << ans.size() << endl;
    //     for(auto i : ans){cout << i << " ";} cout << endl;
    // }
// }




#include <bits/stdc++.h>
#define lint long long int
#define pb push_back
using namespace std;

lint n;
vector<vector<lint>> adj(n+1);
vector<bool> visited(n+1, false);
vector<lint> ans;

void find(lint x){
    visited[x] = true;
    for(auto i : adj[x]){
        visited[i] = true;
    }
}

int main() {

    lint T;
    cin >> T;
    while(T--){
        lint m;
        cin >> n >> m;

        ans.clear();
        adj.clear();
        visited.clear();
        
        
        visited.assign(n+1, false);
        adj.resize(n+1);

        for(lint i = 0; i < m; i ++){
            lint temp1, temp2;
            cin >> temp1 >> temp2;
            adj[temp1].pb(temp2);
            adj[temp2].pb(temp1);
        }

        lint max_v = -1, max_i = -1;
        for(lint i = 1; i <= n; i ++){
            if(adj[i].size() > max_v){
                max_v = adj[i].size();
                max_i = i;
            }
        }
        ans.pb(max_v);
        visited[max_v] = true;
        for(auto i : adj[max_i]){
            visited[i] = true;
        }
        for(lint i = 1; i <= n; i ++){
            if(!visited[i]){
                ans.pb(i);
                find(i);
            }
        }

        cout << ans.size() << endl;
        for(auto i : ans){cout << i << " ";}
        cout << endl;

    }

    return 0;
}

//! maybe at any point it took more than floor(n/2) vertices -> take the vertex with most neighbours first.
//? many of them? take one