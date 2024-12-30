#include <bits/stdc++.h>
#include <ctime>
#define lint long long int
#define pb push_back
using namespace std;


bool checking(vector<lint> v){
    bool check1 = true;
    int inc;
    if(v[1] > v[0]){inc = 1;} // increasing
    else inc = 2; // decreasing

    for(int i = 2; i < v.size(); i ++){
        if(v[i] > v[i-1] && inc == 2){check1 = false; break;}
        if(v[i] < v[i-1] && inc == 1){check1 = false; break;}
    }
    if(check1){
        // for(auto i : )
        bool check2 = true;
        for(int i = 1; i < v.size(); i ++){
            int temp = max(v[i]-v[i-1], v[i-1]-v[i]);
            if(temp < 1 || temp > 3){
                check2 = false;
                // cout << 2 << " " << i << endl;
                break;
            }
        }
        if(check2){return true;}
        else return false;
    }
    else return false;
}


int main() {
    int n = 1000;
    int ans = 0;
    while(n--){
        string s;
        getline(cin, s);
        lint cur;
        vector<lint> v;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == ' '){
                v.pb(cur);
                cur = 0;
            }
            else{
                cur *= 10;
                cur += (int(s[i])-48);
            }
        }
        v.pb(cur); cur=0;
        

        // for(auto i : v){cout << i << " ";} cout << endl;
        if(checking(v)){
            ans++;
        }
        else{
            bool check = false;
            for(int i = 0; i < v.size(); i ++){
                vector<lint> v1;
                for(int j = 0; j < v.size(); j ++){
                    if(j != i){v1.pb(v[j]);}
                }
                // for(auto k : v1){cout << k << " ";} cout << endl;
                if(checking(v1)){
                    check = true;
                    break;
                }
            }
            if(check){
                ans++;
            }
        }

        
    }
    cout << ans << endl;

}