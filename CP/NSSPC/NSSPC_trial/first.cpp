#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define lint long long int
#define fi first
#define se second
using namespace std;

// int main(){
//     lint n;
//     cin>>n;
//     vector<int> a(n);
//     lint sum=0;
//     for(int i=0;i<n;i++){
//         cin>>a[i]; sum+=a[i];
//     }
//     sort(a.begin(),a.end());
//     lint suml=a[0];
//     lint sumr=sum-a[0];
//     lint dif=abs(sumr-suml);
//     for(int i=1;i<n;i++){
//         suml+=a[i];
//         sumr-=a[i];
//         dif=min(dif,abs(suml-sumr));
//     }
//     cout<<dif<<endl;
// }

// int n,m,k;
// int xx[8]={-1,-1,-1,0,0,1,1,1};
// int yy[8]={-1,0,1,-1,1,-1,0,1};

// bool check(int x,int y,vector<pair<int,int>> &sit){
//     int sum=0;
//     for(int j=0;j<k;j++){
//     for(int i=0;i<8;i++){
//         if(x+xx[i]<0 || x+xx[i]>=n) continue;
//         else if(y+yy[i]<0 || y+yy[i]>=m) continue;
//         if(x+xx[i]==sit[j].fi && y+yy[i]==sit[j].se) sum++;
//         if(sum>=3) return true;
//     }
//     }
//     return false;
// }

// int main(){
//     cin>>n>>m>>k;
//     vector<pair<int,int>> sit(k);
//     for(int i=0;i<k;i++){
//         cin>>sit[i].fi>>sit[i].se;
//         sit[i].fi--;
//         sit[i].se--;
//     }
//     int ans=0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             if(check(i,j,sit)) {ans++;}
//         }
//     }
//     cout<<ans;
// }

// int main() {
//     // ifstream cin("xxx.in");
//     // ofstream cout("xxx.out");
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int sum=0;
//     string str;
//     cin>>str;
//     while(str.find(')')!=string::npos){
//         auto it=str.find(')');
//         int re=0;
//         char n;
//         for(int i=it;i>=0;i--){
//             if(str[i]=='('){
//                 if(n=='+') sum+=re;
//                 else if(n=='-') sum-=re;
//                 str.erase(it-i,it);
//                 cout<<str<<endl;
//             }
//             else if(isdigit(str[i])) re+=str[i];
//             else if(str[i]=='+') n='+';
//             else if(str[i]=='-') n='-';
//         }
//     }
//     cout<<sum;
//     return 0;
// }

int main(){
    int n;
    cin>>n;
    if(isdigit(' '))cout<<"YES";
}