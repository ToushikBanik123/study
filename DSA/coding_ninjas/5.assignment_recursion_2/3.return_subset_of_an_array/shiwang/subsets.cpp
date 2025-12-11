#include <bits/stdc++.h>
using namespace std;

void subsets(vector<int> &arr, int idx, vector<int> &current,
             vector<vector<int>> &result) {
  if (idx == arr.size()) {
    result.push_back(current);
    return;
  }

  result.push_back(current);

  for (int i = idx; i < arr.size(); i++) {
    current.push_back(arr[i]);
    subsets(arr, i + 1, current, result);
    current.pop_back();
  }
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    arr[i] = k;
  }
  vector<int> current;
  vector<vector<int>> result;
  subsets(arr, 0, current, result);

    for (auto &subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
        cout << subset[i];
        if (i != subset.size() - 1) {
            cout << " ";
        }
        }
        cout << "]" << endl;
    }
  return 0;
}