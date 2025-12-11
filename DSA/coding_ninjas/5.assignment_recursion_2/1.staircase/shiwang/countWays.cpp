#include <bits/stdc++.h>
using namespace std;

int countWays(int n) {
  if (n == 0)
    return 1;
  if (n < 0)
    return 0;

  return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
}

int main() {
  int n;
  cin >> n;

  cout << countWays(n);

  // Tabulation Approach

  vector<int> dp(n + 1, 0);
  dp[0] = 1;

  for (int i = 0; i < dp.size(); i++) {
    if (i + 1 < dp.size()) {
      dp[i + 1] += dp[i];
    }
    if (i + 2 < dp.size()) {
      dp[i + 2] += dp[i];
    }
    if (i + 3 < dp.size()) {
      dp[i + 3] += dp[i];
    }
  }
    cout << endl << "Tabulation Approach " << dp[n];
  return 0;
}