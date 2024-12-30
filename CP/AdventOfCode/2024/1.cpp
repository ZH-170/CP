#include <bits/stdc++.h>
#include <ctime>
#define lint long long int
#define pb push_back
using namespace std;


int main() {
    int n = 1000;
    lint sum = 0;
    vector<lint> v1, v2;
    vector<lint> v(100000, 0), c;
    while(n--){
        lint temp1, temp2;
        cin >> temp1 >> temp2;
        v1.pb(temp1);
        v2.pb(temp2);
        v[temp2]++;
        c.pb(temp1);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // for(int i = 0; i < 1000; i ++){
    //     sum += max(v1[i]-v2[i], v2[i]-v1[i]);
    // }
    // cout << sum << endl;
    // cout << v1.back() << " " << v2.back();

    for(int i = 0; i < 1000; i ++){
        sum += c[i] * v[c[i]];
    }
    cout << sum;

}