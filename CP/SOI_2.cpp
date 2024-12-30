#include <bits/stdc++.h>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> va, vb;
    for(int i = 0; i < n; i ++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        va.pb(temp1);
        vb.pb(temp2);
    }
    vector<pair<int, int>> ans(pow(2, n)+1);
    for(int i = 0; i < ans.size(); i ++){
        ans[i].second = i;
        ans[i].first = 0;
    }
    // for(int i = 1; i < pow(2, n); i ++){

    // }

    vector<lint> ansa(pow(2, n), 0), ansb(pow(2, n), 0);
    vector<pair<lint, lint>> ansc(pow(2, n));
    
    for(lint i = 1; i < pow(2, n); i ++){
        
        lint x = i;
        for(int j = 0; j < n; j ++){
            // cout << n << " " << n%2;
            // cout << x%2 << " ";

            if(x%2 == 1){
                // ans[i].first += (va[j]*va[j] + vb[j]*vb[j]);
                ansa[i]+=va[j];
                ansb[i]+=vb[j];
                
                // cout << va[j] << " " << vb[j] << endl;
            }
            x=x>>1;
        }
        // cout << endl;
    }

    // for(auto i : ans){cout << i.first << " " << i.second << endl;}
    
    

    for(int i = 0; i < ansa.size(); i ++){
        ansc[i].second = i;
        ansc[i].first = (ansa[i]*ansa[i]) + (ansb[i]+ansb[i]);
    }

    sort(ansc.begin(), ansc.end());

    for(auto i : ansc){cout << i.first << " " << i.second << endl;}

    cout << ansc.back().first << " " << ansc.back().second;
}

// 6
// -14 5
// -14 18
// 5 24
// -9 -25
// -10 -10
// -18 -12