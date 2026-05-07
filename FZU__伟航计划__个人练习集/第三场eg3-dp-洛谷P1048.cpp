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

int t, m;
int tim[1005], value[1005];
int dp[105][1005];
//int dp[1005];

signed main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> t >> m;
	for (int i = 1; i <= m; i++) {
		cin >> tim[i] >> value[i];
	}
	//二维：数据范围小
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= t; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j >= tim[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - tim[i]] + value[i]);
			}
		}
	}
	//一维：空间小
	/*for (int i = 1; i <= m; i++) {
		for (int j = t; j >= tim[i];j--) {
			dp[j] = max(dp[j], dp[j - tim[i]] + value[i]);
		}
	}*/
	cout << dp[m][t];
}