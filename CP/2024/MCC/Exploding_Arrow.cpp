//* very very first thought: binary search
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;
#define ll long long
#define lint long long int
#define ull unsigned long long
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define MP make_pair

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define max(a, b) ((a > b)? a : b)
#define min(a, b) ((a < b)? a : b)
#define max3(a, b, c) max(max(a, b), c)
#define min3(a, b, c) min(min(a, b), c)

const int N = 1e5;
const int M = 1e9 + 7; 
const int inf = 0x3f3f3f3f;
const ll int INF = 1e18;


lint n, m, k;
vector<lint> v;

bool check(lint x){
    // vector<lint> a = v;
    // // cout << "x: " << x << endl << "a.size():  " << a.size() << endl;
    // int cur_front = 0;
    // // cout << m*x << endl;
    // for(int i = 0; i < k; i ++){
    //     if(cur_front == n){break;}
        
    //     for(int j = cur_front; j < n; j ++){
    //         if(( (lint)(m*x) - (lint)((cur_front-j)*(cur_front-j) )) > a[j]){
    //             a[j]=0;
    //             continue;
    //         }
    //         a[j] -= max((lint)0, ( (lint)(m*x) - (lint)((cur_front-j)*(cur_front-j) )));
    //     }
    //     while(a[cur_front] <= 0 && cur_front < n){
    //         cur_front++;
    //         // cout << cur_front << endl;
    //     }

    //     // for(auto li : a){cout << li << " ";}
    //     // cout << endl << "cf: " << cur_front << " " << a[cur_front] << endl;

    // }
    // // cout << cur_front << endl << endl;

    // if(cur_front == n){return true;}
    // else return false;

    vector<lint> a(v.size(), 0);

    int cur_front = 0;
    for(int i = 0; i < k; i ++){
        if(cur_front == n){break;}

        for(int j = cur_front; j < n; j ++){
            a[j] += ((lint)max(0, ( ((lint)m*(lint)x) - ( ((lint)cur_front-(lint)j)*((lint)cur_front-(lint)j) ) )));
        }
        while(a[cur_front] >= v[cur_front] && cur_front < n){
            cur_front++;
        }
    }

    if(cur_front == n){return true;}
    else return false;
}

lint bin(lint l, lint r, function<bool(lint)> f){
    while(l < r){
        lint mid = l + (r-l+1)/2;
        cout << l << " " << r << " " << mid << " " << check(mid) << endl;
        if(f(mid)){r = mid;}
        else{l = mid+1;}
    }
    return l;
}



int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // ifstream cin();
    // ofstream cout();
    
    
    cin >> n >> m >> k;

    for(int i = 0; i < n; i ++){
        lint temp;
        cin >> temp;
        v.pb(temp);
    }

    // lint ans = bin(179999, 180003, [&](lint x){
    //     return check(x);
    // });

    // cout << ans << endl;

    // cout << v[199999] << endl;


    for(int i = 180002; i <= 180003; i ++){
        cout << i << " " << check(i) << endl;
    }

}

// 1 1000000000 500000001 1
// 1 500000001 250000001 1
// 1 250000001 125000001 1
// 1 125000001 62500001 1
// 1 62500001 31250001 1
// 1 31250001 15625001 1
// 1 15625001 7812501 1
// 1 7812501 3906251 1
// 1 3906251 1953126 1
// 1 1953126 976564 1
// 1 976564 488283 1
// 1 488283 244142 1
// 1 244142 122072 0
// 122073 244142 183108 1
// 122073 183108 152591 0
// 152592 183108 167850 0
// 167851 183108 175480 0
// 175481 183108 179295 0
// 179296 183108 181202 1
// 179296 181202 180249 1
// 179296 180249 179773 0
// 179774 180249 180012 1
// 179774 180012 179893 0
// 179894 180012 179953 0
// 179954 180012 179983 0
// 179984 180012 179998 0
// 179999 180012 180006 1
// 179999 180006 180003 1
// 180002 or 180003






// 1 1000000000 500000000 1
// 1 500000000 250000000 1
// 1 250000000 125000000 1
// 1 125000000 62500000 1
// 1 62500000 31250000 1
// 1 31250000 15625000 1
// 1 15625000 7812500 1
// 1 7812500 3906250 1
// 1 3906250 1953125 1
// 1 1953125 976563 1
// 1 976563 488282 1
// 1 488282 244141 1
// 1 244141 122071 1
// 1 122071 61036 0
// 61037 122071 91554 1
// 61037 122071 91554 1
// 61037 91554 76295 1
// 61037 76295 68666 1
// 61037 68666 64851 0
// 64852 68666 66759 0
// 66760 68666 67713 0
// 67714 68666 68190 1
// 67714 68190 67952 1
// 67714 67952 67833 0
// 67834 67952 67893 0
// 67894 67952 67923 0
// 67924 67952 67938 0
// 67939 67952 67945 0
// 67946 67952 67949 0
// 67950 67952 67951 1
// 67950 67951 67950 1
// 67950




// //* very very first thought: binary search
// #include <iostream>
// #include <fstream>
// #include <iomanip>
// #include <algorithm>
// #include <functional>
// #include <numeric>
// #include <cstring>
// #include <string>
// #include <cmath>
// #include <vector>
// #include <queue>
// #include <stack>
// #include <set>
// #include <map>

// using namespace std;
// #define ll long long
// #define lint long long int
// #define ull unsigned long long
// #define fi first
// #define se second
// #define pf push_front
// #define pb push_back
// #define MP make_pair

// #define all(v) v.begin(), v.end()
// #define rall(v) v.rbegin(), v.rend()

// #define max(a, b) ((a > b)? a : b)
// #define min(a, b) ((a < b)? a : b)
// #define max3(a, b, c) max(max(a, b), c)
// #define min3(a, b, c) min(min(a, b), c)

// const int N = 1e5;
// const int M = 1e9 + 7; 
// const int inf = 0x3f3f3f3f;
// const ll int INF = 1e18;


// int bin(int l, int r, function<bool(int)> f){
//     while(l<r){
//         int mid = l + (r-l+1)/2;
//         if(f(mid)){
//             r = mid;
//         }
//         else{
//             l = mid+1;
//         }
//     }
//     return l;
// }


// int main(){
    
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
    
//     // ifstream cin();
//     // ofstream cout();
    
//     int n;
//     cin >> n;
//     vector<int> v;
//     for(int i = 0; i < n ; i ++){
//         int temp;
//         cin >> temp;
//         v.pb(temp);
//     }
//     sort(v.begin(), v.end());
//     for(auto i : v){cout << i << " " ;} cout << endl;

//     int ans = bin(0, n, [&](int x){
//         return v[x] > 5;
//     });

//     cout << ans << " " << v[ans];
// }