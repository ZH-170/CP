#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main() {

    ifstream cin("cownomics.in");
    ofstream cout("cownomics.out");

    int n, m;
    cin >> n >> m;

    vector<vector<char>> s(n), p(n);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            char temp;
            cin >> temp;
            s[i].pb(temp);
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            char temp;
            cin >> temp;
            p[i].pb(temp);
        }
    }

    int ans = 0;

    for(int i = 0; i < m; i ++){
        int A1=0, C1=0, G1=0, T1=0;
        for(int j = 0; j < n; j ++){
            if(s[j][i] == 'A'){A1++;}
            else if(s[j][i] == 'C'){C1++;}
            else if(s[j][i] == 'G'){G1++;}
            else if(s[j][i] == 'T'){T1++;}
        }
        
        bool repeat = false;

        for(int j = 0; j < n; j ++){
            if(p[j][i] == 'A'){
                if(A1 != 0){repeat = true; break;}
            }
            else if(p[j][i] == 'C'){
                if(C1 != 0){repeat = true; break;}
            }
            else if(p[j][i] == 'G'){
                if(G1 != 0){repeat = true; break;}
            }
            else if(p[j][i] == 'T'){
                if(T1 != 0){repeat = true; break;}
            }
        }

        if(!repeat){ans++;}
    }

    cout << ans;
}