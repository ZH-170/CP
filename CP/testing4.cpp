#include <bits/stdc++.h>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;



int N;
vector<vector<int>> child(N);
vector<int> SS(N+1);
vector<int> findx(N);
vector<int> mem(N+1, -1);
int FarChild(int x){
    if(mem[x] == -1){
        int m = x;
        for(int i : child[SS[x]]){
            m = max(m, FarChild(findx[i]));
        }
        mem[x] = m;
    }
    return mem[x];
}

int solve(int n, int M, vector<int> F, vector<vector<int>> S){
    if(M == 1){
        N = n;
        vector<int> v(N);
        mem.clear();
        mem.resize(N+1, -1);

        child.clear();
        child.resize(N);
        for(int i = 1; i < N; i ++){
            child[F[i]].pb(i);
        }

        SS.clear();
        SS.resize(N);
        findx.clear();
        findx.resize(N);
        for(int i = 0; i < N-1; i ++){
            // cout << S[0][i];
            SS[i+1] = S[0][i];
            findx[S[0][i]] = i+1;
        }
        int ans = 0;

        int temp = 0;
        while(temp < N-1){
            temp++;
            int mAx = FarChild(temp);
            while(temp != mAx){
                
                temp++;
                mAx = max(mAx, FarChild(temp));
            }
            ans++;
        }
        return ans;

    }
    else{


        //? parent = F


        //? step 1: find the partition of each node first

        vector<pair<int, int>> v(n, {1e9, 0});
        v.clear();
        v.resize(n, {1e9, 0});

        for(int i = 0; i < M; i ++){ //* loop for M times: 0, 1, 2, 3, ..., M-1
            for(int j = 0; j < n-1; j ++){ //* loop for N-1 times: 0, 1, 2, 3, ..., N-2
                v[S[i][j]].first = min(v[S[i][j]].first, j);
                v[S[i][j]].second = max(v[S[i][j]].second, j);
            }
        }
        // for(auto i : v){cout << i.first << " " << i.second << endl;} cout << endl;
        sort(v.begin(), v.end());
        // for(auto i : v){cout << i.first << " " << i.second << endl;} cout << endl;

        
        //? step 2: merge the partition
        vector<pair<int, int>> partition;
        partition.clear();
        
        int timer = 1, nop = 1;
        // partition[1].first = v[0].first; partition[1].second = v[0].second;
        partition.pb({0, 0});
        partition.pb(v[0]);
        while(timer < n-1){


            if(v[timer].first <= partition[nop].second  &&  v[timer].second >= partition[nop].first){
                partition[nop].first = min(partition[nop].first, v[timer].first);
                partition[nop].second = max(partition[nop].second, v[timer].second);
            }
            else{
                nop++;
                // partition[nop] = v[timer];
                partition.pb(v[timer]);
            }

            timer++;
            
        }


        // partition = 1, 2, 3, 4

        //? step3: deal with the partition

        vector<int> P(n);
        P.clear();
        P.resize(n);
        // for(int i = 0; i < n-1; i ++){
            // cout << S[0][i] << " ";
        // } cout << endl;
        for(int i = 1; i <= nop; i ++){
            // cout << partition[i].first << " " << partition[i].second << endl;
            for(int j = partition[i].first; j <= partition[i].second; j ++){
                P[S[0][j]] = i;
            }
        }

        // for(int i = 1; i < n; i ++){
            // cout << i << ": " << P[i] << endl;
        // }
        // cout << endl << endl;

        int minus = 0;

        for(int i = 1; i <= nop; i ++){
            for(int j = partition[i].first; j <= partition[i].second; j ++){

                if(F[S[0][j]] != 0  &&  P[F[S[0][j]]] < P[S[0][j]]){
                    // cout << F[S[0][j]] << " " << S[0][j] << endl;
                    // cout << P[F[S[0][j]]] << " " << P[S[0][j]] << endl << endl;
                    minus++;
                }
            }
        }

        // cout << nop-minus;
        return nop-minus;










    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    // int N = 3;
    // int M = 1;
    // vector<int> F = {-1, 0, 0};
    // vector<vector<int>> S = {{2, 1}};

    // int N = 12;
    // int M = 2;
    // vector<int> F = {-1, 0, 0, 8, 2, 1, 5, 1, 2, 0, 9, 4};
    // vector<vector<int>> S = {{9, 1, 10, 5, 7, 6, 8, 3, 4, 2, 11}, {7, 10, 5, 9, 1, 6, 3, 8, 11, 2, 4}};

    int N = 12;
    int M = 1;
    vector<int> F = {-1, 0, 0, 2, 2, 1, 5, 1, 2, 0, 9, 4};
    vector<vector<int>> S = {{9, 1, 10, 5, 7, 6, 8, 3, 4, 2, 11}};

    // int N = 5;
    // int M = 2;
    // vector<int> F = {-1, 0, 0, 1, 1};
    // vector<vector<int>> S = {{1, 2, 3, 4}, {4, 1, 2, 3}};

    cout << solve(N, M, F, S);
    // solve(N, M, F, S);

    //! REMEMBER TO CHANGE THE "VOID" TO "INT" AND CHANGE THE "COUT" TO "RETURN" !!!!!
}
