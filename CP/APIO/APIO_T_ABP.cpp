#include <bits/stdc++.h>
#include <cmath>
#define lint long long
#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
int MOD = 1e9 + 7;
int INF = 1e9;




unsigned long long Alice(const vector<int> P){
    unsigned long long k = 0;
    for(int i = 0; i < P.size(); i ++){
        k=k+(P[i]*pow(10, i));
        if(P[i] <= 2 && P[i] > 0){k++;}

    }
    return k;
}

vector<int> Bob(const unsigned long long x){
    vector<int> ans;
    int temp=1;

    while(x != 0){
        ans.pb(x % (unsigned long long)(pow(10, temp)));
        temp++;
        x -= ((unsigned long long)x % (unsigned long long)(pow(10, temp)))*(unsigned long long)(pow(10, temp));
    }
    
    return ans;
}

int main(){
    vector<int> P = {3, 5, 2, 4, 1};
    cout << Alice(P) << endl;
    vector<int> v = Bob(Alice(P));
    for(auto i : v){cout << i << " ";}
    
}