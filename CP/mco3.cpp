#include <iostream>
#include <vector>
#include <algorithm>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;
lint MOD = 1e9 + 7;
int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t;
    cin >> n >> m >> t;
    string s;
    cin >> s;

    int l=1, r=m; // l = place of L, r = place of R
    int ll=2, rr=m-1;
    vector<int> L, R;
    L.pb(1);
    R.pb(m);
    bool merge = false;

    for(int i = 0; i < t; i ++){
        if(s[i] == 'W'){
            if(merge){if(l>0)l--;}
            else {
                r--;
                if(r==1){// L R merge -> only move l
                    merge = true;
                }
                else if(l==1){
                    L.pb(ll);
                    ll++;
                    
                }
                else {
                    l--;
                }
            }
        }
        if(s[i] == 'E'){
            if(merge){if(l<m)l++;}
            else{
                l++;
                if(l==m){// L R merge -> only move l
                merge = true;
                }

                if(r==m){
                    R.pb(rr);
                    rr--;
                }
                else {
                    r++;
                }
            }
        }
    }

    // cout << l << " "<< r;
    // cout << endl;
    // for(auto i : L){cout << i << " ";} cout << endl;
    // for(auto i : R){cout << i << " ";} cout << endl;

    if(!merge){
        for(int i = 0; i < L.size(); i ++){
            cout << l-1-1 << " ";
        }
        for(int i = 1; i < m-R.size()+1-L.size(); i ++){
            cout << l+i-1-1 << " ";
        }
        for(int i = 0; i < R.size(); i ++){
            cout << r-1-1 << " ";
        }
    }
    else{
        for(int i = 0; i < m; i ++){
            cout << l-1 << " ";
        }
    }


        cout << endl;
    

    return 0;
}