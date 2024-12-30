#include <bits/stdc++.h>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    fo


    return 0;
}

// abc
// 3
// 1 2 2 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1





// int bin1(int l, int r, function<bool(int)> f){ // smallest number that is larger than x
//     while(l < r){
//         int mid = l + (r-l)/2;
//         if(f(mid)){
//             r=mid;
//         }
//         else{
//             l=mid+1;
//         }
//     }
//     return l;
// }

// int bin2(int l, int r, function<bool(int)> f){ // largest number that is smaller than x
// 	while(l < r){
// 		int mid = l + (r-l+1)/2;
// 		if(f(mid)){
// 			l=mid;
// 		}
// 		else{
// 			r=mid-1;
// 		}
// 	}
// 	return l;
// }


// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     // vector<int> v = {1, 3, 4, 5, 7, 8, 9, 10, 11, 13};

//     // int k = bin1(0, 9, [&](int x){
//     //     return (v[x] >= 9);
//     // });

// 	// int m = bin2(0, 9, [&](int x){
// 	// 	return (v[x] <= 9);
// 	// });


//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<vector<int>> seats(n, vector<int>(m));
//     for(int i = 0; i < n; i ++){
//         iota(seats[i].begin(), seats[i].end(), 1);
//     }

//     while(k--){
//         for(int i = 0; i < n; i ++){
//             for(auto j : seats[i]){
//                 cout << j << " ";
//             }
//             cout << endl;
//         }
//         int x, y;
//         cin >> x >> y;
//         vector<pair<int, int>> s;
//         for(int i = 0; i < n; i ++){
//             int x1 = bin1(0, seats[i].size(), [&](int x){
//                 return seats[i][x] >= y;
//             });
//             int y1 = bin2(0, seats[i].size(), [&](int x){
//                 return seats[i][x] <= y;
//             });
//             s.pb({y1, x1});
//         }
//         for(auto i : s){cout << i.first << " " << i.second << endl;}
//         break;

        

//     }

//     // 3 4 6
//     // 1 1
//     // 1 1
//     // 1 1
//     // 1 2
//     // 1 3
//     // 1 3

//     // 1 1
//     // 1 2
//     // 2 1
//     // 1 3
//     // 1 4
//     // 2 3

//     // x, y = > 5, 4
//     // 1: 1, 2, 3, 5, 6, 7, 9
//     // 1. get the xy, then binary search on all rows
//     // => there are n rows, hence, we need to binary search n rows, each row have m seats 
//     // => O(2nlogm)
//     // vector<vector<int>> seats(n, vector<int>(m)) => n*m 
//     // for(vector<int> x : v){
//     //     binary search x
//     // }

//     // 2. then we get atmost 2n pair of coordinates, compare the distances
//     // => O(2n)

//     // 3. update, lets say the coordinate is x1, y1
//     // then v[x1].erase(y1)
//     // => O(m)

//     // So, total time complexity
//     // = O(nlogm + 2n + m)
//     // ~ O(nlogm + n + m)
//     // ~ O(n + n + m)
//     // = O(n+m)
//     // = O(1E3)

//     // int n, m;
//     // cin >> n >> m;

//     // // all concentrated
//     // lint sum1 = ((n-m)*(n-m+1))/2;
    
//     // // all evenly divided
//     // lint sum2 = 0;
//     // int n_g1=0, n_g2=0;
//     // int s_g1=0, s_g2=0;
//     // n_g1 = n/m;
//     // n_g2 = n_g1+1;
//     // s_g2 = n%m;
//     // s_g1 = m-s_g2;
//     // lint sum2_1 = ((n_g1)*(n_g1-1))/2, sum2_2 = ((n_g2-1)*(n_g2))/2;

//     // sum2 = (sum2_1*s_g1) + (sum2_2*s_g2);
//     // // cout << n_g1 << " " << n_g2 << " " << s_g1 << " " << s_g2 << " " << sum2_1 << " " << sum2_2 << endl;
//     // cout << sum2 << " " << sum1;
    
// }


// // vector<vector<int>> v(3);
// // {

// // {2}
// // {}
// // {}

// // }


// // v[2][1] = 1

// // vector<int> s = {2, 3, 4}
// // v.pb(s);

// // v[0].pb(2); => v[0][0] = 2;


// // 1 2 3 4 5 6 7 8 9
// // 1e18
// // n numbers 
// // O(n)
// // the smallest number that is greater than 8

// // O(log n)


// // 1 2 3 4 || 5 6 7 8 9