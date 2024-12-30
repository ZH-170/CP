#include <bits/stdc++.h>
#include <ctime>
#define lint long long int
#define pb push_back
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        bool check = false;
        int cur = n-1;

        vector<int> v, s;
        cout << 1 << " " << n << endl;
        int f;
        cin >> f;
        v.pb(f);

        while(!check && cur > 1){
            cout << 1 << " " << cur << endl;
            

            int temp;
            cin >> temp;

            if(temp < v.back()){
                s.pb(1);
            }
            else{
                s.pb(0);
            }

            v.pb(temp);

            cur--;
        }

        
        cout << "! ";
        for(auto i : s){cout << i;}
        cout << endl;


    }
}
// 10101