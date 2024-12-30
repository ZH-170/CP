#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define lint long long int
using namespace std;

// int main() {

//     // ifstream cin("xxx.in");
//     // ofstream cout("xxx.out");

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;cin>>n;
//     vector<int>v;
//     int first=0,last=0,dif=0;
//     for(int i=0;i<n;i++){
//         int temp;cin>>temp;
//         v.pb(temp);
//         first+=temp;
//     }
//     sort(v.begin(),v.end());
//     last=v[n-1];
//     first-=last;
//     int ind=0;
//     do{
//         dif=abs(first-last);
//         first-=v[ind];
//         last+=v[ind];
//         ind++;
//     }while(abs(first-last)<dif);
//     cout<<dif;
// }

int n;
vector<int>num(101,0);
vector<vector<int>>mem(101,vector<int>(101,0));
void add(int a){
    num[0]+=a;
    int i=0;
    while(num[i]>9){
        num[i+1]+=num[i]/10;
        num[i]%=10;
        i++;
    }
}
void dfs(int i, int j, vector<vector<int>>v){
    // cout<<i<<" "<<j<<endl;
    if(i==n-1 && j==n-1){add(1);return;}
    if(i+v[i][j]<n){
        // if(i+v[i][j]==n-1 && i==n-1) ans+=1;
        // else{
            if(!mem[i+v[i][j]][j]) dfs(i+v[i][j],j,v);
            else add(mem[i+v[i][j]][j]);
            // cout<<mem[i+v[i][j]][j]<<" ";
        // }
    }
    if(j+v[i][j]<n){
        // if(v[i][j]==n-1 && i==n-1) ans+=1;
        // else {
            if(!mem[i][j+v[i][j]]) dfs(i,j+v[i][j],v);
            else add(mem[i][j+v[i][j]]);
            // cout<<mem[i][j+v[i][j]]<<" ";
        // }
    }
}
int main(){
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    
    dfs(0,0,v);
    bool print=0;
    for(int i=100;i>=0;i--){
        if(num[i]>0)print=1;
        if(print)cout<<num[i];
    }
}

// int main(){
//     lint temp=0,sign=1,ans=0;
//     string s;
//     getline(cin,s);
//     for(int i=0;i<s.size();i++){
//         if(!isdigit(s[i]))break;
//         if(i==s.size()-1){cout<<s;return 0;}
//     }
//     for(int i=0;i<s.size();i++){
//         // cout<<s[i];
//         if(s[i]=='-'){
//             sign=-1;
//         }
//         else if(isdigit(s[i])){
//             temp*=10;
//             temp+=(s[i])-48;
//         }
//         else if(!isdigit(s[i])&& isdigit(s[i-1])){
//             ans+=temp*sign;
//             temp=0;
//             sign=1;
//         }
//     }
//     cout<<ans;
// }