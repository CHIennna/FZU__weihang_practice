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

bool isPrime(int x) {
    if (x <= 1)return false;
    if (x == 2)return true;
    if (x % 2 == 0)return false;
    for (int i = 3; i * i <= x; i+=2) {
        if (x % i == 0)return false;
    }
    return true;
}
//深搜
void dfs(int start, int count, int sum) {
    //终止条件
    if (count==k) {
        if (isPrime(sum)) {
            ans++;
        }
        return;
    }
    //剪枝

    //继续枚举
    //i是层数
    for (int i = start; i < n; i++) {
        dfs(i + 1, count + 1, sum + arr[i]);
    }
}

signed main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dfs(0,0,0);
    cout << ans << endl;
    return 0;
}

//int a[max];
//int main() {
//    int n, k, ans = 0;
//    cin >> n >> k;
//    int U = 1 << n;
//    for (int i = 0; i < n; i++)cin >> a[i];
//    for (ll S = 0; S < U; S++) {
//        if (__builtin_popcount(S) == k) {
//            int sum = 0;
//            for (int i = 0; i < n; i++) {
//                if (S & (1 << i))sum += a[i];
//            }
//            if (isPrime(sum))ans++;
//        }
//    }
//    cout << ans;
//    return 0;
//}