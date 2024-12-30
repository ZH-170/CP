#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {
    lint sum = 0;

    while(true){
        string s;
        getline(cin, s);
        // cout << s.size();
        if(s.empty()){
            // cout << "Hello" << endl;
            break;
        }
        else{
            // cout << "World " << s.size() << endl;

            lint ind = 0;
            string temp = "mul(,)";
            lint temp_ind = 0;
            vector<int> v;
            bool is_enable = true;
            while(ind < s.size()){
                // cout << ind << endl;

                if(ind < s.size()-3){
                    if(s[ind] == 'd' && s[ind+1] == 'o' && s[ind+2] == '(' && s[ind+3] == ')'){
                        is_enable = true;
                        cout << "ENABLE!" << endl;

                    }
                }

                if(ind < s.size()-6){
                    if(s[ind] == 'd' && s[ind+1] == 'o' && s[ind+2] == 'n' && s[ind+3] == '\'' && s[ind+4] == 't' && s[ind+5] == '(' && s[ind+6] == ')'){
                        is_enable = false;
                        cout << "DISABLE!" << endl;
                    }
                }


                // if(is_enable){
                    if(temp_ind == 4 && int(s[ind]) <= 57 && int(s[ind]) >= 48){
                        ind++;
                    }
                    else if(s[ind] == temp[temp_ind]){
                       temp_ind ++;
                        ind++;
                    }
                    else{
                        ind++;
                        temp_ind = 0;
                    }
                    if(temp_ind == temp.size()-1){
                        if(is_enable){v.pb(ind);}
                        temp_ind = 0;
                        // cout << is_enable << endl;
                    }
                // }
                // else{ind++;}
            }
                

            // for(auto i : v){cout << i << " " << s[i] << endl;}

            vector<string> ans;
            for(int i = 0; i < v.size(); i ++){
                if(v[i]+1 < s.size()){
                    if(s[v[i]+1] == ')'){
                        string temptemp;
                        for(int j = v[i]+1; j >= 0; j --){
                            temptemp+=s[j];
                            if(s[j] == 'm'){
                                reverse(temptemp.begin(), temptemp.end());
                                ans.pb(temptemp);
                                break;
                            }
                        }
                    }
                    else if(s[v[i]+2] == ')'){
                        string temptemp;
                        for(int j = v[i]+2; j >= 0; j --){
                            temptemp+=s[j];
                            if(s[j] == 'm'){
                                reverse(temptemp.begin(), temptemp.end());
                                ans.pb(temptemp);
                                break;
                            }
                        }
                    }
                    else if(s[v[i]+3] == ')'){
                        string temptemp;
                        for(int j = v[i]+3; j >= 0; j --){
                            temptemp+=s[j];
                            if(s[j] == 'm'){
                                reverse(temptemp.begin(), temptemp.end());
                                ans.pb(temptemp);
                                break;
                            }
                        }
                    }
                }
            }
            cout << "ans.size(): " << ans.size() << endl;
            for(auto i : ans){
                for(auto j : i){cout << j;}
                cout << endl;
            }


            lint total = 0;
            for(int i = 0; i < ans.size(); i ++){
                int temp1=0, temp2=0;
                bool cur = false;
                for(int j = 0; j < ans[i].size(); j ++){
                    
                    if(int(ans[i][j])>=48 && int(ans[i][j])<=57 && !cur){
                        temp1 *= 10;
                        temp1 += (int(ans[i][j])-48);
                    }
                    if(int(ans[i][j]) == 44){
                        cur = true;
                    }
                    if(int(ans[i][j])>=48 && int(ans[i][j])<=57 && cur){
                        temp2 *= 10;
                        temp2 += (int(ans[i][j])-48);
                    }
                }
                cout << temp1 << " " << temp2 << " " << (lint)(temp1*temp2) << endl;
                total += (lint)(temp1*temp2);
            }
            cout << total << endl;
            sum += total;
        
        
        }
    }
    cout << sum << endl;

}
// 102785526

// 10217702
// 10576232
// 28257801
// 11242653
// 22217562
// 20273576
// 499 826
// 125 420
// 125 420
// 645 560
// 13 127
// 439 817
// 224 797
// 464 432
// 35 360
// .
// .
// .
// 551 872
// 221 320
// 402 345
// 698 4
// 
// 281 880
// 362 818
// 610 930