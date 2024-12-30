#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {

    ifstream cin("lifeguards.in");
    ofstream cout("lifeguards.out");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(1001, 0);
    vector<pair<int, int>> shift;

    for(int i = 0; i < n; i ++){
        int a, b;
        cin >> a >> b;
        for(int j = a; j < b; j ++){
            v[j]++;
        }
        shift.pb({a, b});
    }

    int ans = 0;

    for(int i = 0; i < n; i ++){
        for(int j = shift[i].first; j < shift[i].second; j ++){
            v[j]--;
        }
        int temp = 0;
        for(int j = 0; j < 1000; j ++){
            if(v[j] > 0){temp++;}
        }
        ans = max(ans, temp);
        for(int j = shift[i].first; j < shift[i].second; j ++){
            v[j]++;
        }
    }

    cout << ans;

    

    return 0;
}