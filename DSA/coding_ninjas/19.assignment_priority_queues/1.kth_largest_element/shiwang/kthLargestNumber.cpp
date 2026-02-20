#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int kthLargestNumber(vector<int> &input, int n, int k) {
  if (n <= 0)
    return INT_MIN;

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < input.size(); i++) {
    if (pq.size() == k && pq.top() < input[i]) {
      pq.pop();
    }

    if (pq.size() < k) {
      pq.push(input[i]);
    }
  }

  return pq.top();
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

  int ans = kthLargestNumber(input, n, k);
  cout << ans;
}