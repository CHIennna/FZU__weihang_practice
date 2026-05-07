#include <vector>
#include <iomanip>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
constexpr int maxn = 310;
constexpr ll INF = 4e18;
constexpr double eps = 1e-9;
#define MAXN 22

ll f[MAXN][MAXN] = { 0 };
int ctrl[MAXN][MAXN];
int n, m, hx, hy;
int d[9][2] = {
	{0, 0},{1, 2}, {-1, 2}, {1, -2}, {-1, -2},{2, 1}, {2, -1}, {-2, 1}, {-2, -1}
};

signed main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> hx >> hy;
	//处理horse控制点
	for (int i = 0; i < 9; i++) {
		int tmpx = hx + d[i][0];
		int tmpy = hy + d[i][1];
		if (tmpx >= 0 && tmpy >= 0 && tmpx <= n && tmpy <= m)ctrl[tmpx][tmpy] = 1;
	}
	f[0][0] = 1 - ctrl[0][0];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (ctrl[i][j])continue;
			if (i != 0)f[i][j] += f[i - 1][j];
			if (j != 0)f[i][j] += f[i][j - 1];
		}
	}

	cout << f[n][m] << '\n';
	return 0;
}