#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int maxn = 1000011;
constexpr ll INF = 4e18;

ll a[maxn];
ll n, m;
bool isValid(int h) {
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > h) {
			sum += a[i] - h;
		}
	}
	return sum >= m;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int l = 0, r = 1e9, mid, ans;
	while (l <= r) {//×ó±ÕÓÒ±Õ
		mid = l + (r - l) / 2;
		if (isValid(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}