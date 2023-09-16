#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n; cin >> n;
    long long a[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    long long dp[n + 1][n + 1];

    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (j == 1) {
                dp[i][j] = a[i][j];
            }
            else if (i == 1) {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j - 1]) + a[i][j];
            }
            else if (i == n) {
                dp[i][j] = max(dp[i - 1][j - 1], dp[i][j - 1]) + a[i][j];
            }
            else {
                dp[i][j] = max({ dp[i - 1][j - 1],dp[i][j - 1],dp[i + 1][j - 1] }) + a[i][j];
            }

        }
    }
    long long k = -99;
    for (int i = 1; i <= n; i++) {
        k = max(k, dp[i][n]);
    }
    cout << k;
    return 0;
}


