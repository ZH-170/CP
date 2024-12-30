#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {

    // ifstream cin("cownomics.in");
    // ofstream cout("cownomics.out");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i ++){
        int temp;
        cin >> temp;
        v.pb(temp);
    }

    // vector<int> petals(1001, 0);
    lint ans = 0;

    for(int dx = 1; dx <= n; dx ++){
        
        int l = 0, r = dx-1;
        while(r < n){
            
            // cout << l << " " << r << " " << ans << endl;
            int sum = 0;
            for(int i = l; i <= r; i ++){
                sum +=v[i];
            }

            if(sum%dx == 0){
                for(int i = l; i <= r; i ++){
                    if(v[i] == (sum/dx)){ans++; break;}
                }
            }
            l++; r++;
        }

    }



    cout << ans;

    return 0;
}