#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {

    // ifstream cin("xxx.in");
    // ofstream cout("xxx.out");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> num;
    vector<pair<char, int>> vp;
    map<int, char> mp;

    int sum = n;
    for(int i = 0; i < n; i ++){
        char c;
        cin >> c;
        
        int x;
        cin >> x;

        num.pb(x);

        vp.pb({c, x});

        mp[x]=c;
        if(x == 1e9){sum--;}
    }

    sort(num.begin(), num.end());

    int m = 1e9;
    int liar_total = 1e9;
    int liar = 0;
    for(int i = 0; i < n; i ++){
        //* process num[i]

        if(i-1 >= 0){
            if(mp[num[i-1]] == 'L'){

            }
        }

        if(i+1 <= n-1){
            ;
        }
    }

    string s;
    s.replace()
    return 0;
}

