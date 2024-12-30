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

lint n, q;
vector<vector<char>> grid(1e3, vector<char>(1e3, '?'));
vector<vector<bool>> checkGrid(1e3, vector<bool>(1e3, true));

void make_black(lint x, lint y){
    if(x-1 >= 0 && grid[x-1][y] == 'D' && checkGrid[x-1][y]){checkGrid[x-1][y] = false; make_black(x-1, y);}
    if(x+1 < n && grid[x+1][y] == 'U' && checkGrid[x+1][y]){checkGrid[x+1][y] = false; make_black(x+1, y);}
    if(y-1 >= 0 && grid[x][y-1] == 'R' && checkGrid[x][y-1]){checkGrid[x][y-1] = false; make_black(x, y-1);}
    if(y+1 < n && grid[x][y+1] == 'L' && checkGrid[x][y+1]){checkGrid[x][y+1] = false; make_black(x, y+1);}
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // ifstream cin();
    // ofstream cout();
    
    
    cin >> n >> q;
    


    lint cnt = 0;
    
    for(lint z = 0; z < q; z ++){
        lint a, b;
        cin >> a >> b;
        char c;
        cin >> c;
        grid[a-1][b-1] = c;

        // cout << z << endl;

        if(c == 'R'){
            if(b != n){
                if(!checkGrid[a-1][b]){
                    checkGrid[a-1][b-1] = false;
                    make_black(a-1, b-1);
                    cnt ++;
                }
                else if(grid[a-1][b] == 'L'){
                    checkGrid[a-1][b] = false;
                    checkGrid[a-1][b-1] = false;
                    make_black(a-1, b-1);
                    make_black(a-1, b);
                    cnt += 2;
                }
            }
        }

        // cout << z << endl;

        if(c == 'L'){
            if(b != 1){
                if(!checkGrid[a-1][b-2]){
                    checkGrid[a-1][b-1] = false;
                    make_black(a-1, b-1);
                    cnt ++;
                }
                else if(grid[a-1][b-2] == 'R'){
                    checkGrid[a-1][b-2] = false;
                    checkGrid[a-1][b-1] = false;
                    make_black(a-1, b-1);
                    make_black(a-1, b-2);
                    cnt += 2;
                }
            }
        }
        // cout << z << endl;

        if(c == 'U'){
            if(a != 1){
                if(!checkGrid[a-2][b-1]){
                    checkGrid[a-1][b-1] = false;
                    make_black(a-1, b-1);
                    cnt ++;
                }
                else if(grid[a-2][b-1] == 'D'){
                    checkGrid[a-2][b-1] = false;
                    checkGrid[a-1][b-1] = false;
                    make_black(a-1, b-1);
                    make_black(a-2, b-1);
                    cnt += 2;
                }
            }
        }

        // cout << z << endl;

        if(c == 'D'){
            if(a != n){
                if(!checkGrid[a][b-1]){
                    checkGrid[a-1][b-1] = false;
                    make_black(a-1, b-1);
                    cnt ++;
                }
                else if(grid[a][b-1] == 'U'){
                    checkGrid[a][b-1] = false;
                    checkGrid[a-1][b-1] = false;
                    make_black(a-1, b-1);
                    make_black(a, b-1);
                    cnt += 2;
                }
            }
        }

        // cout << z << endl;




        //flood fill

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        lint ax[4]={0, 0, 1, -1}, ay[4]={1, -1, 0, 0};
        
        lint usable = 0;
        for(lint I = 0; I < n; I ++){
            lint i, j;
            i = I;
            j = 0;
            if(!visited[i][j] && checkGrid[i][j]){
                queue<pair<lint, lint>> qq;
                qq.push({i, j});
                usable++;
                visited[i][j] = true;
                while(!qq.empty()){
                    pair<lint, lint> cur = qq.front();
                    qq.pop();

                    for(int k = 0; k < 4; k ++){
                        lint x = cur.first+ax[k], y = cur.second+ay[k];

                        if(x >= 0 && x < n && y >= 0 && y < n){
                            if(!visited[x][y] && checkGrid[x][y]){
                                visited[x][y] = true;
                                qq.push({x, y});
                                usable++;
                            }
                        }
                    }

                    
                }
            }

            i = I;
            j = n-1;
            if(!visited[i][j] && checkGrid[i][j]){
                queue<pair<lint, lint>> qq;
                qq.push({i, j});
                usable++;
                visited[i][j] = true;
                while(!qq.empty()){
                    pair<lint, lint> cur = qq.front();
                    qq.pop();

                    for(int k = 0; k < 4; k ++){
                        lint x = cur.first+ax[k], y = cur.second+ay[k];

                        if(x >= 0 && x < n && y >= 0 && y < n){
                            if(!visited[x][y] && checkGrid[x][y]){
                                visited[x][y] = true;
                                qq.push({x, y});
                                usable++;
                            }
                        }
                    }

                    
                }
            }

            j = I;
            i = 0;
            if(!visited[i][j] && checkGrid[i][j]){
                queue<pair<lint, lint>> qq;
                qq.push({i, j});
                usable++;
                visited[i][j] = true;
                while(!qq.empty()){
                    pair<lint, lint> cur = qq.front();
                    qq.pop();

                    for(int k = 0; k < 4; k ++){
                        lint x = cur.first+ax[k], y = cur.second+ay[k];

                        if(x >= 0 && x < n && y >= 0 && y < n){
                            if(!visited[x][y] && checkGrid[x][y]){
                                visited[x][y] = true;
                                qq.push({x, y});
                                usable++;
                            }
                        }
                    }

                    
                }
            }

            j = I;
            i = n-1;
            if(!visited[i][j] && checkGrid[i][j]){
                queue<pair<lint, lint>> qq;
                qq.push({i, j});
                usable++;
                visited[i][j] = true;
                while(!qq.empty()){
                    pair<lint, lint> cur = qq.front();
                    qq.pop();

                    for(int k = 0; k < 4; k ++){
                        lint x = cur.first+ax[k], y = cur.second+ay[k];

                        if(x >= 0 && x < n && y >= 0 && y < n){
                            if(!visited[x][y] && checkGrid[x][y]){
                                visited[x][y] = true;
                                qq.push({x, y});
                                usable++;
                            }
                        }
                    }

                    
                }
            }

        //     cout << "visited:" << endl;
        //     for(int i = 0; i < n; i ++){
        //         for(auto j : visited[i]){
        //             cout << j;
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
            
        }

        // cout << usable << endl;
        cout << (n*n) - usable << endl;

        // cout << "grid:   checkGrid:" << endl;
        // for(int i = 0; i < n; i ++){
        //     for(int j = 0; j < n; j ++){
        //         cout << grid[i][j];
        //     }
        //     cout << "       ";
        //     for(int j = 0; j < n; j ++){
        //         cout << checkGrid[i][j];
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        

    }

    
    
}

// 3 5
// 1 1 R
// 3 3 L
// 3 2 D
// 1 2 L
// 2 1 U


// flood fill ?
// every time flood fill from the outest part of the 
