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

int n,m;

signed main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	vector<vector<int>> arr(n + 2, vector<int>(n+2));
	vector<vector<int>> diff(n + 2, vector<int>(n + 2));
	ll tot = 0;
	for (int i = 1; i <= m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		diff[x1][y1]++;
		diff[x2 + 1][y1]--;
		diff[x1][y2 + 1]--;
		diff[x2 + 1][y2 + 1]++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + diff[i][j];
			tot += (i + j) ^ arr[i][j];
		}
	}
	cout << tot << '\n';
	return 0;
}