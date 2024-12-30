#include <bits/stdc++.h>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;

// lint ans = 0;
lint n;
vector<lint> parent(n+1, -1), parent_2(n+1, -1);
vector<vector<lint>> adj1(n+1), adj2(n+1);

void dfs(lint x, lint v){
    if(x == v) return;
    for(auto i : adj1[x]){
        if(parent[i] == -1){
            parent[i] = x;
            dfs(i, v);
        }
    }
}

void dfs_2(lint x, lint v){
    if(x == v) return;
    for(auto i : adj2[x]){
        if(parent_2[i] == -1){
            parent_2[i] = x;
            dfs_2(i, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    lint q;
    cin >> n >> q;

    vector<lint> a;
    a.pb(0);
    for(lint i = 0; i < n; i ++){
        lint temp;
        cin >> temp;
        a.pb(temp);
    }

    adj1.resize(n+1);
    adj2.resize(n+1);
    

    for(lint i = 0; i < n-1; i ++){
        lint temp1, temp2;
        cin >> temp1 >> temp2;
        adj1[temp1].pb(temp2);
        adj1[temp2].pb(temp1);
    }
    for(lint i = 0; i < n-1; i ++){
        lint temp1, temp2;
        cin >> temp1 >> temp2;
        adj2[temp1].pb(temp2);
        adj2[temp2].pb(temp1);
    }

    for(lint i = 0; i < q; i ++){
        parent.resize(n+1, -1);
        lint x, y;
        cin >> x >> y;
        parent[x] = -2;
        dfs(x, y);

        // for(auto j : parent){cout << j << " ";} cout << endl;

        lint temp = y;
        vector<lint> first_w;
        while(temp != x){
            first_w.pb(temp);
            temp = parent[temp];
        }
        first_w.pb(x);
        // cout << first_w[0] << endl;

        // for(auto j : first_w){cout << j;} cout << endl;

        lint ans = 0;

        for(int j = 0; j < first_w.size(); j ++){ //TODO later change away j<1 to first_w.size()
            
            parent_2.resize(n+1, -1);

            parent_2[x] = -2;
            dfs_2(x, first_w[j]);
            // for(auto l : parent_2){cout << l << " ";} cout << endl;
            lint temp_2 = first_w[j];
            lint bit_and = a[x];
            vector<lint> haha;
            while(temp_2 != x){

                haha.pb(temp_2);
                // cout << bit_and << " " << temp_2 << " " << 
                bit_and = a[temp_2]&bit_and;
                // cout << bit
                temp_2 = parent_2[temp_2];
            }
            
            ans += bit_and;
            // haha.pb(x);
            // for(auto k : haha){cout << k;} cout << endl; cout << bit_and << endl;
        }
        cout << "ans=";
        cout << ans;
    } 

    
    return 0;
}


//! remember to take queries -> finish the input part

//* int h = 3, i = 5;
//* int j = h&i;
//* cout << j;
//! kenot "cout << h&i"

//? STEP 1: find w1=u, w2, w3, ...., wr=v4
//? .......HOW? 
//? .......tree traversal -> tree algorithm find the path of the tree?
//? .......dfs from u until reach v?
//? .......then use parent[] to record the distance

//? STEP 2: find dis(u, w1) + dis(u, w2) + dis(u, w3)...
//? .......HOW? segment tree?
//? .......dis(w1, wr) = Aw1 & Aw2 & Aw3 ... Awr
//? .......maybe need segment tree => HOW?
//? .......for dis(u, wx) => need to find the route from u to wx
//? in the second tree... dfs again?
//? then?


// 5 1
// 7 3 7 7 7
// 1 4
// 4 2
// 3 1
// 3 5
// 3 5
// 2 1
// 4 5
// 2 4
// 2 3



// 5 5
// 7 3 7 7 7
// 1 4
// 4 2
// 3 1
// 3 5
// 3 5
// 2 1
// 4 5
// 2 4
// 1 1
// 4 2
// 4 4
// 1 3
// 2 3