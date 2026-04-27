#include <queue>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
constexpr int MAX = 5000005;
constexpr int maxn = 30;
constexpr ll INF = 4e18;
constexpr double eps = 1e-9;

int n, k;
int ans;
int arr[maxn];

signed main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << ans << endl;
    return 0;
}