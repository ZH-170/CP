#include <bits/stdc++.h>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;

const int INF=1e9;



int n, q;
vector<int> v(n+1);
vector<int> E;
vector<bool> visited(n+1, false);
vector<int> t_in(n+1), t_out(n+1);
vector<vector<int>> adj(n+1);

int temp = 0;
void dfs(int x){
    // temp++;
    E.pb(x);
    t_in[x] = temp;
    // temp++;
    for(int i : adj[x]){
        if(!visited[i]){
            visited[i] = true;
            temp++;
            // t_in[i] = temp;
            dfs(i);
            // t_out[i] = temp;
            // temp--;
            
        }
        
    }
    // temp++;
    // t_out[x] = temp;
    // temp++;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    v.resize(n+1);
    for(int i = 1; i <= n; i ++){
        cin >> v[i];
    }

    adj.resize(n+1);
    for(int i = 0; i < n-1; i ++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adj[temp1].pb(temp2);
        adj[temp2].pb(temp1);
    }

    visited.resize(n+1, false);
    visited[1] = true;
    dfs(1);

    cout << "E:"; for(auto i : E){ cout << i << " ";} cout << endl;
    for(int i = 1; i <= n; i ++){cout << i << ":" << t_in[i] << " " << t_out[i] << endl;}
    
    for(int i = 0; i < q; i ++){
        int checker;
        cin >> checker;
        if(checker == 1){
            int pos, new_val;
            cin >> pos >> new_val;
        }
        else{
            int pos;
            cin >> pos;
        }
    }

    return 0;
}

// 10 10
// 1 10 3 7 6 4 2 2 5 4
// 10 7
// 5 3
// 8 6
// 7 5
// 1 5
// 6 9
// 8 4
// 2 4
// 3 6
// 1 2 4
// 2 9
// 1 9 5
// 2 10
// 2 1
// 2 10
// 1 10 6
// 2 10
// 2 10
// 2 3