#include <bits/stdc++.h>
using namespace std;

using lint = long long;

using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int, int>;
#define f first
#define s second
#define mp make_pair

void setIO(string name = "") {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vector<vector<pair<int, int>>> adj(1e5+1);
vector<bool> visited(1e5+1, false);
vi d(1e5+1, 0);

void dfs(int p, int dis, int target){
	// cout << p << ": "; for(int i = 0; i < 4; i ++){cout << visited[i] << " ";} cout << endl;
	if(p == target){d[p] = max(d[p], dis); return;}
	for(auto i : adj[p]){
		// cout << i.first << endl;
		
		if(!visited[i.first]){
			visited[i.first] = true;
			int k = dis;
			if(dis == 0){dis = i.second;}
			else{dis = min(dis, i.second);}
			dfs(i.first, min(dis,  i.second), target);
			visited[i.first] = false;
			dis = k;
		}
	}
}

int main(){
	setIO;

	ifstream cin("wormsort.in");
	ofstream cout("wormsort.out");

	int n, m;
	cin >> n >> m;
	
	vector<int> p(n+1);
	vi where_is(n+1);
	for(int i = 1; i <= n; i ++){
		cin >> p[i];
		where_is[p[i]] = i;
	}

	for(int i = 0; i < m; i ++){
		int a, b, m;
		cin >> a >> b >> m;
		adj[a].pb({b, m});
		adj[b].pb({a, m});
	}

	// queue<pair<int, int>> q;
	// q.push({5, 0});

	for(int i = 1; i <= n; i ++){
		if(p[i] != i){
			visited.clear();
			visited.resize(1e5+1, false);

			visited[p[i]] = true;
			dfs(p[i], 0, i);

			swap(p[where_is[i]], p[i]);

			// for(int i = 1; i <= n; i ++){cout << p[i] << " ";} cout << endl;
			
		}
	}

	// visited[3] = true;
	// dfs(3, 0, 1);
	
	// for(int i = 0; i <= n; i ++){
	// 	cout << d[i] << " ";
	// }
	// cout << endl;

	sort(all(d));


	// cout << "ans:";

	if(d.back() == 0){cout << -1;}
	else cout << d.back();
	

}

// 6 6
// 1 2 3 4 6 5
// 1 2 11
// 2 3 12
// 3 4 13
// 4 5 14
// 5 6 7
// 1 6 10

// 3 3
// 3 1 2
// 1 2 5
// 2 3 6
// 3 1 7

// 4 4
// 3 2 1 4
// 1 2 9
// 1 3 7
// 2 3 10
// 2 4 3