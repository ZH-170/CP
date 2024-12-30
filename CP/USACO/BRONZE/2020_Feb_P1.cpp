#include <bits/stdc++.h>
#define pb push_back
#define lint long long int
using namespace std;

int main() {

    ifstream cin("triangles.in");
    ofstream cout("triangles.out");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> points;
    vector<pair<int, int>> xa(2e4+5, {1e9, 0}), ya(2e5+4, {1e9, 0}); //* (min, max);
    for(int i = 0; i < n; i ++){
        int x, y;
        cin >> x >> y;
        x+=1e4; y+=1e4;
        points.pb({x, y});
        xa[y].first = min(x, xa[y].first);
        xa[y].second = max(x, xa[y].second);
        ya[x].first = min(y, ya[x].first);
        ya[x].second = max(y, ya[x].second);
    }

    // vector<lint> area;
    lint ans = 0;
    for(int i = 0; i < n; i ++){
        lint m_x = max(abs(points[i].first - xa[points[i].second].first), abs(points[i].first - xa[points[i].second].second));
        lint m_y = max(abs(points[i].second - ya[points[i].first].first), abs(points[i].second - ya[points[i].first].second));

        // area.pb(m_x * m_y);
        ans = max(ans, m_x*m_y);
    }

    cout << ans;

    


    return 0;
}