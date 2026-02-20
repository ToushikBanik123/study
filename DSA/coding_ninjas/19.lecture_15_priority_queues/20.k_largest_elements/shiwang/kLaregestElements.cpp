#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> kSmallestElements(vector<int> &input, int k, int n) {
  if (k == 0)
    return {};
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < n; i++) {
    if (pq.size() == k && pq.top() < input[i]) {
      pq.pop();
    }
    if (pq.size() < k)
      pq.push(input[i]);
  }

  vector<int> ans;
  while (!pq.empty()) {
    ans.push_back(pq.top());
    pq.pop();
  }
  return ans;
}

int main() {
  int n;
  cin >> n;

  vector<int> input;

  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;

    input.push_back(data);
  }

  int k;
  cin >> k;

  vector<int> ans = kSmallestElements(input, k, n);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}