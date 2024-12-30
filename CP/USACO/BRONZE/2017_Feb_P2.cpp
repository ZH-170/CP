#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {

    ifstream cin("circlecross.in");
    ofstream cout("circlecross.out");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string s;
    cin >> s;
    
    vector<pair<int, int>> v(26);
    vector<bool> check(26, false);
    
    for(int i = 0; i < s.size(); i ++){
        if(check[int(s[i])-65]){
            v[int(s[i])-65].second = i;
        }
        else{
            v[int(s[i])-65].first = i;
            check[int(s[i]-65)] = true;
        }
    }

    // for(auto i : v){cout << i.first << " " << i.second << endl;} cout << endl;

    int ans = 0;

    for(int i = 0; i < 26-1; i ++){
        for(int j = i+1; j < 26; j ++){
            // cout << i << " " << j << endl;
            
            // cout << i << " " << j << endl; 
            // cout << v[i].first << " " << v[i].second << "   ";
            // cout << v[j].first << " " << v[j].second << endl;

            if(v[i].first < v[j].first && v[i].second > v[j].second){
                // cout << "ha\n";
                ans++;
            }
            else if(v[i].first > v[j].first && v[i].second < v[j].second){
                // cout << i << " " << j << endl; 
                // cout << v[i].first << " " << v[i].second << endl;
                // cout << v[j].first << " " << v[j].second << endl;
                // cout << "he\n";
                ans++;
            }
            else if(v[i].second < v[j].first){
                // cout << "hi\n";
                ans++;
            }
            else if(v[j].second < v[i].first){
                // cout << "ho\n";
                ans++;
            }
            // cout << endl;
        }
    }


    cout << 325-ans;
    
    return 0;
}