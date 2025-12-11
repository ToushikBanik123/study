#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  unordered_map<string, vector<vector<int>>> memo;

  vector<vector<int>> subSetSumToK(vector<int> &arr, int idx, int target) {
    string key = to_string(idx) + "|" + to_string(target);

    if (target == 0) {
      return {{}};
    }

    if (idx >= arr.size() || target < 0) {
      return {};
    }
    
    if (memo.find(key) != memo.end()) {
      return memo[key];
    }

    vector<vector<int>> take = subSetSumToK(arr, idx + 1, target - arr[idx]);

    for (auto &subset : take) {
      subset.insert(subset.begin(), arr[idx]);
    }

    vector<vector<int>> skip = subSetSumToK(arr, idx + 1, target);
    take.insert(take.end(), skip.begin(), skip.end());
    memo[key] = take;
    return take;
  }
};

int main() {
  int n, x;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    arr[i] = k;
  }
  cin >> x;

  Solution s1;

  vector<vector<int>> result = s1.subSetSumToK(arr, 0, x);

  for (auto &subset : result) {
    for (auto &num : subset) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}