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

const int N = 2e5;
const int M = 1e9 + 7; 
const int inf = 0x3f3f3f3f;
const ll int INF = 1e18;

// find the smallest number that is larger than or equal to x
lint bin1(lint l, lint r, function<bool(lint)> f){
    while(l < r){
        // cout << l << " " << r << endl;
        lint mid = l+(r-l)/2;
        if(f(mid)){
            r = mid;
        }
        else l = mid+1;
    }
    return l;
}

// find the largest number that is smaller than or equal to x
lint bin2(lint l, lint r, function<bool(lint)> f){
    while(l < r){
        lint mid = l + (r-l+1)/2;
        if(f(mid)){
            l = mid;
        }
        else r = mid-1;
    }
    return l;
}



int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // vector<lint> v = {1, 2, 3, 4, 6, 7, 8, 9};
    // lint ans1 = bin1((lint)0, (lint)v.size()-1, [&](lint x){
    //     if(v[x] >= 4){return true;}
    //     else return false;
    // });

    // lint ans2 = bin2((lint)0, (lint)v.size()-1, [&](lint x){
    //     if(v[x] <= 6){return true;}
    //     else return false;
    // });


    // cout << endl << ans2 << " " << v[ans2] << endl;
    
    // ifstream cin();
    // ofstream cout();
    
    lint T;
    cin >> T;
    while(T--){
        lint n, k;
        cin >> n >> k;
        vector<lint> v; // tree position
        // vector<pair<lint, lint>> tree(n+1); // {how mony range this tree in, 第几个tree}
        vector<vector<lint>> treeRange(n+1); // tree[i] = {1, 2} => this tree is in range 1, and 2
        for(lint i = 0; i < n; i ++){
            lint temp;
            cin >> temp;
            v.pb(temp);
            // tree[i].second = i;
        }

        lint max_t = 0;
        sort(v.begin(), v.end());
        // cout << "v: ";
        // for(auto i : v){cout << i << " " ;} cout << endl;

        vector<pair<pair<lint, lint>, lint>> tree_range; // { {l, r}， t }
        vector<lint> extra_tree(k+1); // {第几个range, 多了几个}

        bool full = false;

        for(lint i = 0; i < k; i ++){
            lint l, r, t;
            cin >> l >> r >> t;

            max_t = max(max_t, t);
            tree_range.pb({{l, r}, t});

            lint l1 = bin1((lint)0, (lint)v.size()-1, [&](lint x){
                if(v[x] >= l){return true;}
                else return false;
            });

            lint r1 = bin2((lint)0, (lint)v.size()-1, [&](lint x){
                if(v[x] <= r){return true;}
                else return false;
            });


            // cout << "l1 r1 : ";
            // cout << l1 << " " << r1 << endl;
            
            for(lint temp = l1; temp <= r1; temp ++){
                treeRange[temp].pb(i);
            }

            extra_tree[i] = r1-l1+1-t;
        }

        vector<pair<lint, lint>> tree;
        for(lint i = 0; i < n; i ++){
            tree.pb({i, treeRange[i].size()});
        }

        // cout << "tree: " << endl;
        // for(auto i : tree){
        //     cout << i.first << " " << i.second << endl;
        // }
        // cout << endl;

        // cout << "treeRange: " << endl;
        // for(int i = 0; i < n+1; i ++){
        //     cout << i << ": ";
        //     for(auto j : treeRange[i]){
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;


        sort(tree.begin(), tree.end(), [](pair<lint, lint> a, pair<lint, lint> b){
            return a.second < b.second;
        });

        // cout << "tree: " << endl;
        //     for(auto i : tree){
        //         cout << i.first << " " << i.second << endl;
        //     }
        // cout << endl;

        vector<lint> remove;
        for(lint i = 0; i < n; i ++){
            if(n-remove.size() == max_t){break;}
            bool check = true;
            for(auto j : treeRange[tree[i].first]){
                if(extra_tree[j] == 0){
                    check = false;
                    break;
                }
            }
            if(check){
                remove.pb(i);
                for(auto j : treeRange[tree[i].first]){
                    extra_tree[j]--;
                }
            }
        }

        // cout << "ans: ";
        cout << remove.size() << endl;

        // if(full){cout << 0 << endl;}
        // else{
        //     sort(tree.begin(), tree.end());

        //     cout << "tree" << endl;
        //     for(int i = 0; i < tree.size(); i ++){
        //         cout << tree[i].first << " " << tree[i].second << endl;
        //     }
        //     cout << endl;

        // }


        // sort(tree_range.begin(), tree_range.end(), [](pair<pair<lint, lint>, lint> a, pair<pair<lint, lint>, lint> b){
        //     if(a.first.first == b.first.first){
        //         if(a.first.second == b.first.second){
        //             return a.second > b.second;
        //         }
        //         return a.first.second > b.first.second;
        //     }
        //     return a.first.first < b.first.first;
        // });

        // for(auto i : tree_range){
        //     cout << i.first.first << " " << i.first.second << " " << i.second << endl;
            
        // }

        // vector<lint> deleted;
        // for(lint i = 1; i < tree_range.size(); i++){
        //     if(tree_range[i].first.first <= tree_range[i-1].first.first && tree_range[i].first.second >= tree_range[i-1].first.second && tree_range[i].second >= tree_range[i-1].second){
        //         deleted.pb(i);
        //     }
        // }

        
    }
    
}
// 7 2
// 8 4 10 1 2 6 7
// 2 9 3
// 1 10 4