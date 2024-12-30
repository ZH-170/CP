#include <iostream>
#include <vector>
#include <algorithm>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;
lint MOD = 1e9 + 7;
int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, t;
    cin >> n >> m >> t;
    string s;
    cin >> s;

    vector<int> xi, yj;
    vector<int> cc;
    int isum=0, jsum=0;
    int nt=0, et=0, st=0, wt=0;

    int l=0, r=0;
    int lt=0, rt=0;
    for(auto i : s){
        // if(i == 'N'){
        //     // xi.pb(-1); yj.pb(0);
        //     cc.pb(-10);
        //     isum-=1;
        //     nt++;
        // }
        // if(i == 'S'){
        //     // xi.pb(+1); yj.pb(0);
        //     cc.pb(10);
        //     isum+=1;
        //     st++;
        // }
        if(i == 'E'){
            // xi.pb(0); yj.pb(+1);
            cc.pb(1);
            // jsum+=1;
            et++;
            
            l++;

            r--;
            if(r < 0){rt++; r=0;}

        }
        if(i == 'W'){
            // xi.pb(0); yj.pb(-1);
            cc.pb(-1);
            // jsum-=1;
            wt++;


            l--;
            if(l < 0){lt++; l=0;}
        }
    }

    // for(auto i : cc){cout << i << " ";}
    // cout << endl;

    // for(auto i : xi){cout << i << " "+_

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            // cout << i << j << " ";

            int x = i, y = j;
            // int xy = x*10 + y;
            


            // FOR SUBTASK 1
            // for(int k = 0; k < cc.size(); k ++){
            //     // x += xi[k]; y+=yj[k];
            //     // if(x<1){x++;}
            //     // if(y<1){y++;}
            //     // if(x>n){x--;}
            //     // if(y>m){y--;}
            //     xy += cc[k];
            //     if(xy%10 < 1){xy++;}
            //     if(xy%10 > m){xy--;}
            //     // cout << xy << endl;
                
            // }
            // cout << endl << endl << endl;
            // cout << xy << " ";
            // cout << (((xy/10)-1)*m) + (xy%10) -1 << " ";
            // cout << endl;
            // cout << xy << " ";
            // cout << x << " " << y << " " << m << endl;

            // FOR SUBTASK 3
            // x+=isum; y+=jsum;
            // if(nt>(i-1)){x+=(nt-(i-1));}
            // if(st>(j-1)){y+=(st-(j-1));}
            // if(wt>(n-i)){x+=(wt-(n-i));}
            // if(et>(m-j)){y-=(et-(m-j));}

            
            // else{

            // }


            


            // cout << m*(x-1) + (y-1) << " ";
            // cout << x << y << " ";



        }
        // FOR SUBTASK 2

        cout << lt << " " << rt << endl;
        if(lt+rt <= m){
            for(int i = 0; i <= lt; i ++){cout << 0 << " ";}
            for(int i = 0; i < m-(lt+1+rt+1); i ++){cout << i+1 << " ";}
            for(int i = 0; i <= rt; i ++){cout << m << " ";}
        }
        else{
            
        }

        cout << endl;
    }

    return 0;
}