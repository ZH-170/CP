#include <bits/stdc++.h>
#define lint long long
#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int MOD = 1e9 + 7;
int INF = 1e9;

vector<int> compute(int N, vector<int> F){

    vector<int> dgr(N+1, 0);
    vector<vector<int>> adj(N+1);

    for(int i = 1; i < N; i ++){
        dgr[i] ++;
        dgr[F[i]] ++;
        adj[i].pb(F[i]);
        adj[F[i]].pb(i);
    }

    priority_queue<int> pq;
    for(int i = 0; i < N; i ++){
        if(dgr[i] == 1){pq.push(i);}
    }
    vector<int> ans;
    while(!pq.empty()){
        int x = pq.top();
        pq.pop();
        if(x ==  0){continue;}
        dgr[x] = 0;
        for(auto i : adj[x]){
            dgr[i]--;
            if(dgr[i] == 1){pq.push(i);}
        }
        // cout << x;
        ans.pb(x);
    }

    // vector<int> ans;
    // for(int z = 1; z < N; z ++){
    //     for(int i = N-1; i >= 0; i --){
    //         if(dgr[i] == 1){
    //             ans.pb(i);
    //             for(auto k : adj[i]){
    //                 dgr[k]--;
    //             }
    //             dgr[i] = 0;
    //             break;
    //         }
    //     }
    // }

    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    // int N;
    // cin >> N;
    // vector<int> F;
    // for(int i = 0; i < N-1; i ++){
    //     int temp;
    //     cin >> temp;
    //     F.pb(temp);
    // }

    vector<int> v = compute(8, {-1, 2, 4, 0, 3, 0, 7, 2});

    for(auto i : v){cout << i << " ";} cout << endl;
    
    

    

    // for(auto i : ans){cout << i << " ";} cout << endl;
    
    
    return 0;
}