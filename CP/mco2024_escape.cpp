#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<int>> visited(n+2, vector<int>(m+2, -2));
    
    for(int i = 0; i < n+2; i ++){
        visited[i][0] = -1;
        visited[i][m+1] = -1;
    }

    for(int i = 0; i < m+2; i ++){
        visited[0][i] = -1;
        visited[n+1][i] = -1;
    }

    vector<pair<int, int>> doors, dogs;
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            char temp;
            cin >> temp;
            v[i][j]=temp;
            if(temp == '#'){visited[i+1][j+1] = -1;}
            if(temp == 'e'){doors.pb({i+1, j+1}); q.push({i+1, j+1}); visited[i+1][j+1] = 0;}
            if(temp == 'd'){dogs.pb({i+1, j+1});}
        }
    }

    // for(int i = 0; i < n+2; i ++){
    //     for(int j = 0; j < m+2; j ++){
    //         if(visited[i][j]){cout << 1 << " ";}
    //         else cout << 0 << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;
    
    // for(auto i : doors){cout << i.first << " " << i.second << endl;}

    int ax[4] = {0, 0, 1, -1}, ay[4] = {1, -1, 0, 0};


    
    int ans = 0;

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();




        for(int i = 0; i < 4; i ++){
            if(visited[x+ax[i]][y+ay[i]] == -2){
                // ans++;
                visited[x+ax[i]][y+ay[i]] = visited[x][y] + 1;
                q.push({x+ax[i], y+ay[i]});

                // for(int i = 0; i < n+2; i ++){
                //     for(int j = 0; j < m+2; j ++){
                //         if(visited[i][j]){cout << 1 << " ";}
                //         else cout << 0 << " ";
                //     }
                //     cout << endl;
                // }
                // cout << endl;
                
            }
        }


    }
    // cout << ans;


    // cout << endl;

    for(int i = 0; i < n+2; i ++){
        for(int j = 0; j < m+2; j ++){
            cout << visited[i][j]+1;
        }
        cout << endl;
    }
    vector<int> dogs_speed;
    for(int i = 0; i < dogs.size(); i ++){
        dogs_speed.pb(visited[dogs[i].first][dogs[i].second]);
    }
    sort(dogs_speed.begin(), dogs_speed.end());
    
    for(int i = 0; i < n+2; i ++){
        for(int j = 0; j < m+2; j ++){
            
            if(visited[i][j] >= 0  &&  visited[i][j] < dogs_speed[1]){
                ans++;
            }
        }
        cout << endl;
    }

    cout << ans;
}