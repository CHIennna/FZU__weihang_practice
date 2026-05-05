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
//only 55 counts qwq
int n,m,k;

int main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	ll cnt = 0;
	vector<vector<int>> num(n + 2, vector<int>(m + 2));
	if (k == 1) {
		cout << n * (n + 1) / 2 * m * (m + 1) / 2 << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> num[i][j];
		}
	}
	vector<vector<int>> prev(n + 2, vector<int>(m + 2));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			prev[i][j] = prev[i-1][j] + prev[i][j-1] + num[i][j] - prev[i-1][j-1];
		}
	}

	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= m; y1++) {
			for (int x2 = x1; x2 <= n; x2++) {
				int sum = 0;
				for (int y2 = y1; y2 <= m; y2++) {
					sum = prev[x2][y2] - prev[x1 - 1][y2] - prev[x2][y1 - 1] + prev[x1 - 1][y1 - 1];
					if (sum % k == 0) {
						cnt++;
					}
				}
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}