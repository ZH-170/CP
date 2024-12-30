#include <bits/stdc++.h>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;

lint n;
vector<vector<lint>> adj(n+1);
vector<lint> t;
vector<lint> T;

void find(lint x, lint a[]){
    // cout << "x=" << x << endl;
    T[x] = a[x];
    for(auto i : adj[x]){
        // if(T[i] == -1){
            find(i, a);
        // }
        T[x] = T[x] ^ T[i];
    }
    
}

// void build(lint a[], lint v, lint tl, lint tr){
//     if(tl == tr){t[v] = a[tl];}
//     else{
//         lint tm = (tl+tr)/2;
//         build(a, v*2, tl, tm);
//         build(a, v*2+1, tm+1, tr);
//         t[v] = t[v*2]^t[v*2+1]^a[v];
//     }
// }

// void update(lint v, lint tl, lint tr, lint pos, lint new_val, lint a[]){
//     if(v == pos){T[v] = new_val; find(1, a);}
//     else{
//         lint tm = (tl+tr)/2;
//         if(pos <= tm){update(v*2, tl, tm, pos, new_val, a);}
//         else{update(v*2+1, tm+1, tr, pos, new_val, a);}
//     }

// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lint q;
    cin >> n >> q;

    adj.resize(n+1);
    T.resize(n+1, -1);

    for(int i = 0; i < n-1; i ++){
        lint a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }

    lint A[n];
    A[0] = -1;
    for(lint i = 1; i <= n; i ++){
        cin >> A[i];
    }

    for(auto i : A){cout << i << " ";} cout << endl;

    t.resize(n*4);

    // build(A, 1, 0, n-1);

    // for(auto i : t){cout << i << " ";} cout << endl;
    find(1, A);
    // for(auto i : T){cout << i << " ";} cout << endl;

    
    // A[1] = 2;
    // find(1, A);



    // // update(1, 1, n, 1, 2, A);
    // for(auto i : T){cout << i << " ";} cout << endl;


    for(lint i = 0; i < q; i ++){
        lint checker;
        cin >> checker;
        if(checker == 1){
            lint pos, new_val;
            cin >> pos >> new_val;
            A[pos] = new_val;
            find(1, A);
        }
        else {
            lint pos;
            cin >> pos;
            cout << T[pos] << endl;
        }
    }


    


    return 0;
}


// 5 10
// 1 2
// 1 3
// 2 4
// 2 5
// 1 2 3 4 5
// 2 1
// 2 2
// 1 2 1
// 2 1
// 2 2
// 1 5 4
// 2 2
// 2 5
// 1 3 7
// 2 1
