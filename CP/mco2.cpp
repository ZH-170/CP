#include <iostream>
#include <vector>
#include <algorithm>
#define lint long long
#define pb push_back
#define mp make_pair
using namespace std;
lint MOD = 1e9 + 7;
int INF = 1e9;



int N0, N1, M;
vector<vector<int>> A(2);


bool binarySearch1(int i, int x){// check if A[i] contains x;
    int l = 0, r = A[i].size()-1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if(A[i][m] == x)
            return true;
        else if(A[i][m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}

bool binarySearch2(int i, int x){// check if A[1-i] contains M-x;
    i = 1-i;
    x = M-x;
    int l = 0, r = A[i].size()-1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if(A[i][m] == x)
            return true;
        else if(A[i][m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    cin >> N0 >> N1 >> M;
    for(int i = 0; i < N0; i++){
        int temp;
        cin >> temp;
        A[0].pb(temp);
    }
    for(int i = 0; i < N1; i ++){
        int temp;
        cin >> temp;
        A[1].pb(temp);
    }
    
    sort(A[1].begin(), A[1].end());
    sort(A[0].begin(), A[0].end());

    int q;
    cin >> q;
    for(int i = 0; i < q; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 3){
            if(binarySearch1(b, c) || binarySearch2(b, c)) cout << "YES";
            else cout << "NO";
        }
        if(a == 1){
            A[b].pb(c);
            sort(A[b].begin(), A[b].end());
        }
        // if(a == 2)

    }



    return 0;
}