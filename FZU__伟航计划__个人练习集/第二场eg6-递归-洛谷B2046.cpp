#include <queue>
#include <iostream>
using namespace std;

int fibi(int x) {
    if (x <= 2) {
        return 1;
    }
    return fibi(x - 1) + fibi(x - 2);
}

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cout << fibi(x) << endl;
    }
	return 0;
}