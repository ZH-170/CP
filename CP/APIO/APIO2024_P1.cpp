#include <bits/stdc++.h>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;

// int farthestChild(int x){
//     int m = ;
//     for(auto i : adj[x]){
        
//     }
// }

int N;
vector<vector<int>> child(N);
vector<int> SS;
int FarChild(int x){
    int m = x;
    for(int i : child[SS[x]]){
        m = max(m, FarChild(i));
    }
    return m;
}

int solve(int n, int M, vector<int> F, vector<vector<int>> S){
    if(M == 1){
        N = n;
        vector<int> v(N);

        child.clear();
        child.resize(N);
        for(int i = 1; i < N; i ++){
            child[F[i]].pb(i);
        }
        
        for(int i = 1; i < N; i ++){
            v[i] = i;
        }
        // vector<int> S[0]
        SS.clear();
        SS.pb(0);
        for(auto i : S[0]){
            SS.pb(i);
        }

        int ans = 0;

        int temp = 1;
        while(temp != N-1){
            int mAx = FarChild(SS[temp]);
            // int temp = 1;
            while(temp != mAx){
                temp++;
                mAx = max(mAx, FarChild(SS[temp]));
            }
            temp++;
            ans++;
        }
        cout << ans;
        



        return ans;

    } else{

        vector<pair<int, int>> v(N, {1e9, 0});
        //* v[i].first = the first time i appears
        //* v[i].second = the last time i appears
        //* then we know v[i].first til v[i].second will be a day (if overlap)
        //TODO: find a way to connect these days

        for(int i = 0; i < M; i ++){ //* loop for M times: 0, 1, 2, 3, ..., M-1
            for(int j = 0; j < N-1; j ++){ //* loop for N-1 times: 0, 1, 2, 3, ..., N-2
                v[S[i][j]].first = min(v[S[i][j]].first, j);
                v[S[i][j]].second = max(v[S[i][j]].second, j);
            }
        }

        return 0;



        // for(int i = 1; i < N; i ++){cout << i << ": " << v[i].first << " " << v[i].second << endl;}
        
        vector<vector<int>> adj;
        for(int i = 0; i < N; i ++){
            for(int j = 0; j < N-1; j ++){
                ;
            }
        }


        


    }
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 3;
    int M = 1;
    vector<int> F = {-1, 0, 0};
    vector<vector<int>> S = {{1, 2}};

    cout << solve(N, M, F, S);
    // solve(N, M, F, S);
}
