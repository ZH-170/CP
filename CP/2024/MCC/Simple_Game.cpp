//* first thought is that to think like two of them have a1+a2+...+an and b1+b2+...+bn
//* then the "card picking section" can be act as "dun let ur opponent have the card"
//* then we can try to think from here and find the first n/2 largests cards in both hands
//* then think which card should be "deleted" at first...
//* since Evirir goes first, then Rhae's card will be first "deleted";
//* that's being said, we should delete the largest card of b first and keep the other card for a
//* but this comes to a problem: is it keeping the largest cards of us is more worth it, or deleting the largest cards of others is more worth it

//* second thought is that maybe a1-b1 brings a special meaning into this game?


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

const int N = 1e4;
const int M = 1e9 + 7; 
const int inf = 0x3f3f3f3f;
const ll int INF = 1e18;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // ifstream cin();
    // ofstream cout();
    
    // int n;
    // cin >> n;
    // vector<pair<lint, lint>> v;
    // lint A=0, B=0;
    // for(int i = 0; i < n; i ++){
    //     lint temp1, temp2;
    //     cin >> temp1 >> temp2;
    //     v.pb({temp1, temp2});
    //     A+=temp1; B+=temp2;
    // }
    // vector<pair<lint, lint>> va=v, vb=v;

    // sort(va.begin(), va.end(), [](pair<lint, lint> a, pair<lint, lint> b){
    //     if(a.first == b.first){return a.second < b.second;}
    //     else return a.first > b.first;
    // });

    // sort(vb.begin(), vb.end(), [](pair<lint, lint> a, pair<lint, lint> b){
    //     if(a.second == b.second){return a.first < b.first;}
    //     else return a.second > b.second;
    // });


    
    // //* this idea is dun let the other person take the largest card
    // //* seems not correct
    // //* maybe make use of a-b
    // if a-b large, then meens (a > b) a lot
    // if a-b small, then means (a < b) a lot


    // int n;
    // cin >> n;
    // vector<pair<pair<lint, lint>, int>> va, vb;
    // for(int i = 0; i < n; i ++){
    //     lint temp1, temp2;
    //     cin >> temp1 >> temp2;
    //     va.pb({{temp1, temp2}, i});
    //     vb.pb({{temp1, temp2}, i});
    // }

    // sort(va.begin(), va.end(), [](pair<pair<lint, lint>, int> a, pair<pair<lint, lint>, int> b){
    //     if(a.first.first == b.first.first){
    //         return a.first.second > b.first.second;
    //     }
    //     else return a.first.first > b.first.first;
    // });
    
    // sort(vb.begin(), vb.end(), [](pair<pair<lint, lint>, int> a, pair<pair<lint, lint>, int> b){
    //     if(a.first.second == b.first.second){
    //         return a.first.first > b.first.first;
    //     }
    //     else return a.first.second > b.first.second;
    // });

    // vector<bool> take(n, false);
    // lint A=0, B=0;
    // int acur=0, bcur=0;
    // for(int i = 0; i < n; i ++){
    //     if(i % 2 == 0){
    //         while(take[va[acur].second] == true){
    //             acur++;
    //         }
    //         A += va[acur].first.first;
    //         take[va[acur].second] = true;
    //         // cout << va[acur].first.first << endl;
    //     }
    //     else if(i % 2 == 1){
    //         while(take[vb[bcur].second] == true){
    //             bcur++;
    //         }
    //         B += vb[bcur].first.second;
    //         take[vb[bcur].second] = true;
    //         // cout << vb[bcur].first.second << endl;
    //     }
    // }
    // cout << A-B << endl;

    int n;
    cin >> n;
    vector<tuple<lint, lint, int>> va, vb;
    for(int i = 0; i < n; i ++){
        lint temp1, temp2;
        cin >> temp1 >> temp2;
        va.pb(make_tuple(temp1+temp2, temp1, i));
        vb.pb(make_tuple(temp1+temp2, temp2, i));
    }

    sort(va.begin(), va.end(), [](tuple<lint, lint, int> a, tuple<lint, lint, int> b){
        if(get<0>(a) == get<0>(b)){return get<1>(a) > get<1>(b);}
        else return get<0>(a) > get<0>(b);
    });

    sort(vb.begin(), vb.end(), [](tuple<lint, lint, int> a, tuple<lint, lint, int> b){
        if(get<0>(a) == get<0>(b)){return get<1>(a) > get<1>(b);}
        else return get<0>(a) > get<0>(b);
    });

    vector<bool> taken(n, false);
    lint A=0, B=0;
    int acur=0, bcur=0;
    for(int i = 0; i < n; i ++){
        if(i%2 == 0){
            while(taken[get<2>(va[acur])]){
                acur ++;
            }
            A += get<1>(va[acur]);
            taken[get<2>(va[acur])] = true;
        }
        else if(i%2 == 1){
            while(taken[get<2>(vb[bcur])]){
                bcur ++;
            }
            B +=get<1>(vb[bcur]);
            taken[get<2>(vb[bcur])] = true;
        }
    }

    cout << A-B << endl;


}
// A:
// 8 8-
// 6 3-
// 4 7-
// 3 -3-
// -1 7-
// -9 0

// B:
// 8 8-
// 4 7-
// -1 7-
// 6 3-
// -9 0
// 3 -3


// A: 8+6+3
// B: 7+7+0

// A:
// (8, 8) 16
// (6, 3) 9
// (3, -3) 0

// B:
// (4, 7) 11
// (-1, 7) 6
// (-9, 0) -9

// 10
// 46 54 100 -
// 42 58 100 -
// 42 58 100 -
// 41 59 100 -
// 41 59 100 -
// 49 49 98 -
// 48 48 96 -
// 47 47 94 -
// 46 46 92 -
// 41 41 82 -


// A:
// (46, 54), (42, 58), (42, 58), (48, 48), (46, 46) = 224

// B:
// (41, 59), (41, 59), (49, 49), (47, 47), (41, 41) = 255

// A: 8 7 -1
// B: 3 -3 0

// 6
// -1 7 -8
// 6 3 3
// 3 -3 6
// 4 7 -3
// 8 8 0
// -9 0 -9

// A: 6, 3, 0 => 3+6+8
// B: -8, -3, -9 => 7+7+0

// A:
// 3, -3
// 6, 3
// 8, 8

