#include <queue>
#include <numeric>
#include <iomanip>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
constexpr int MAX = 100005;

bool isprime_arr[MAX];
int n;
//一种预处理 目的是“多次查询”范围很大能不超时
//bool isPrime(int x) {
//    if (x <= 1)return false;
//    if (x == 2)return true;
//    if (x % 2 == 0)return false;
//    for (int i = 3; i * i <= x; i+=2) {
//        if (x % i == 0)return false;
//    }
//    return true;
//}

void sieve() {
    for (int i = 2; i < MAX; i++)isprime_arr[i] = true;
    for (int i = 2; i * i < MAX; i++) {
        if (isprime_arr[i]) {
            for (int j = i * i; j < MAX; j+=i) {
                isprime_arr[j] = false;
            }
        }
    }
}

signed main() {
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    sieve();
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (isprime_arr[x]) {
            cout << x << " ";
        }
    }
    cout << '\n';
    return 0;
}