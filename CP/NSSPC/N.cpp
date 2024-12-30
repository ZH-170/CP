#include <bits/stdc++.h>
#define lint long long
#define pb push_back
using namespace std;
int MOD = 1e9 + 7;
int INF = 1e9;




int main(){
    int a1, a2, a3, a4, a5;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    int b1, b2, b3, b4, b5;
    cin >> b1 >> b2 >> b3 >> b4 >> b5;
    int n;
    cin >> n;


    int p;
    cin >> p;
    bool is_single;
    if(p == 1){is_single = true;}
    else is_single = false;


    int score_m = 0, score_p = 0;


    while(n--){
        // cout << score_m << " " << score_p << endl;


        int x, y;
        cin >> x >> y;


        int s;
        cin >> s;
        bool is_serve;
        if(s == 1){is_serve = true;}
        else{is_serve = false;}


        string t;
        cin >> t;

        if(t == "mango"){
            //* the ball lands outside the rectangle formed by:
            //* the horizontal line
            //* singles back boundary line
            //* doubles side boundary lines
            if(y < b3 || y > b5 || x < a1 || x > a5){
                cout << "peach" << endl;
                score_p++;
                continue;
            }
           
            //* the match is single
            //* the ball lands outside the two singles side boundary lines
            if(is_single){
                if(x > a4 || x < a2){
                    cout << "peach" << endl;
                    score_p++;
                    continue;
                }
            }


            //* the match is double
            //* the shot was a serve
            //* the ball lands outside the doubles back boundary line
            if(!is_single && is_serve){
                if(y > b4){
                    cout << "peach" << endl;
                    score_p++;
                    continue;
                }
            }
        }
    }
}
