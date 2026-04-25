#include <queue>
#include <numeric>
#include <iomanip>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int x1, y1, x2, y2;
char map[1005][1005];
bool used[1006][1006];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs() {
	queue<pii> q;
	queue<int> step;
	q.push({ x1,y1 });
	step.push(0);
	used[x1][y1] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		int s = step.front();
		q.pop();
		step.pop();
		if (x == x2 && y == y2) {
			return s;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];//next x
			int ny = y + dy[i];//next y
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
			if (map[nx][ny] == '1')continue;
			if (used[nx][ny])continue;
			used[nx][ny] = true;
			q.push({ nx,ny });
			step.push(s + 1);
		}
	}
	return -1;//一般用不到 因为确保有解了
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < n; j++) {
			map[i][j] = line[j]; 
		}
	}
	cin >> x1 >> y1 >> x2 >> y2;
	x1--;
	x2--;
	y1--;
	y2--;
	cout << bfs() << '\n';
	return 0;
}