#include <bits/stdc++.h>
#include "cave.h"
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;

// int tryCombination(vector<int> S);

// void answer(vector<int> S, vector<int> D);

void exploreCave(int N){
    vector<int> S;
    for(int i = 1; i < N; i ++){
        S.pb(0);
    }
    S.pb(1);
    
    // vector<pair<int, int>> v;
    vector<int> ans(N);

    for(int i = 0; i < N; i ++){
        ans[N-1-i] = tryCombination(S);
        // v.pb({tryCombination(S), N-1-i});
        S.erase(S.begin());
        S.pb(0);
    }

    S.erase(S.begin());
    S.pb(0);

    answer(S, ans);
}

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

    

//     return 0;
// }