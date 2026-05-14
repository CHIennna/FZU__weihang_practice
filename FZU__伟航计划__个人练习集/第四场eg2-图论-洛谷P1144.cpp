#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

vector<int> e[MAXN];
int cnt[MAXN];
int dis[MAXN];
int vis[MAXN];

int main() {
	queue<int> q;
	q.push(1);
	vis[1] = 1, dis[1] = 0, cnt[1] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : e[x]) {
			if (!vis[y]) {
				dis[y] = dis[x] + 1;
				cnt[y] = cnt[x];
				vis[y] = 1;
				q.push(y);
			}
			else if (dis[y] == dis[x] + 1) {
				cnt[y] = (cnt[y] + cnt[x]) % 100003;
			}
		}
	}
}