#include <queue>
#include <iostream>
using namespace std;
//1746
queue<int> A;
queue<int> N;
A.push(1);
N.push(0);
while (!A.empty()) {
    int now = A.front();
    int num = N.front();
    A.pop();
    N.pop();
    for (int i = 1; i <= ; i) {
        A.push(a[i]);
        N.push(num + 1);
    }
}