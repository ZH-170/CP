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

        // cout << N << endl;


        // for(int i = 1; i < N; i ++){
        //     v[i] = i;
        // }
        // cout << v[2];
        SS.clear();
        SS.resize(N);
        findx.clear();
        findx.resize(N);
        // for(auto i : S[0]){cout << i << " ";}
        // cout << N << endl;
        // cout << S[0][0] << " " << S[0][1] << " " << S[0][2] <    < " " << S[0][3] << " " << S[0][4];
        for(int i = 0; i < N-1; i ++){
            // cout << S[0][i];
            SS[i+1] = S[0][i];
            findx[S[0][i]] = i+1;
        }

        // for(auto i : S[0]){cout << i << " ";} cout << endl;
        // for(auto i : findx){cout << i << " ";} cout << endl;

        int ans = 0;

        int temp = 0;
        while(temp < N-1){
            temp++;
            int mAx = FarChild(temp);
            // cout << mAx << endl;
            while(temp != mAx){
                
                temp++;
                mAx = max(mAx, FarChild(temp));
                // cout << temp;
            }
            ans++;
        }


        // for(int i : SS){cout << i << " ";} cout << endl;
        // cout << FarChild(1);


        // cout << endl << ans;
        



        return ans;

    
    }
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int N = 3;
    // int M = 1;
    // vector<int> F = {-1, 0, 0};
    // vector<vector<int>> S = {{2, 1}};

    int N = 12;
    int M = 1;
    vector<int> F = {-1, 0, 0, 2, 2, 1, 5, 1, 2, 0, 9, 4};
    vector<vector<int>> S = {{9, 1, 10, 5, 7, 6, 8, 3, 4, 2, 11}};

    cout << solve(N, M, F, S);
    // solve(N, M, F, S);
}
