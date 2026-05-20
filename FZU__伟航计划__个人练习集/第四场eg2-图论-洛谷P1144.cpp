#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int FUCK = 100003;

vector<int> e[MAXN];
int cnt[MAXN];//1到i的最短路条数
int dis[MAXN];//1到i的最短距离
int vis[MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x); // 无向图，双向建边
	}
	queue<int> q;
	q.push(1);
	vis[1] = 1, dis[1] = 0, cnt[1] = 1;
	while (!q.empty()) {
		int x = q.front(); 
		q.pop();
		for (int y : e[x]) {
			if (!vis[y]) {
				dis[y] = dis[x] + 1;
				cnt[y] = cnt[x];
				vis[y] = 1;
				q.push(y);
			}else if (dis[y] == dis[x] + 1) {
				cnt[y] = (cnt[y] + cnt[x]) % FUCK;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << cnt[i] % FUCK << '\n';
	}
	return 0;
}