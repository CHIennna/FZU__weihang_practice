#include <vector>
#include <iomanip>
#include <iostream>
#include <utility>
#include <climits>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
constexpr int maxn = 310;
constexpr ll INF = 4e18;
constexpr double eps = 1e-9;

int n;

signed main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	vector<vector<ll>> a(n+1, vector<ll>(n+1, 0));
	vector<vector<ll>> s(n+1, vector<ll>(n+1, 0));
	//注意vec是0-based 不要开太小越界了
	//原数组  前缀和数组
	//递推式s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	//设左上角的下标为(x1,y1)，右下角的下标为(x2,y2)：
	//s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}

	ll Ans = -LLONG_MAX;
	for (int x1 = 1; x1 <= n; x1++) {
		for (int y1 = 1; y1 <= n; y1++) {
			for (int x2 = 1; x2 <= n; x2++) {
				for (int y2 = 1; y2 <= n; y2++) {
					//需要有这样一行来过滤无效数据喵
					if (x2 < x1 || y2 < y1)continue;
					Ans = max(Ans, s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);
				}
			}
		}
	}

	cout << Ans << '\n';
	return 0;
}