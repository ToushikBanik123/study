#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void stockSpan(vector<int> &stockPrice, vector<int> &result) {
  stack<int> s1;
  int count = 0;
  int maxCount = 0;
  int currMaxPrice = stockPrice[0];
  int maxPrice = stockPrice[0];

  for (int i = 0; i < stockPrice.size(); i++) {
    if (!s1.empty() && stockPrice[i] <= s1.top()) {
      while (!s1.empty()) {
        s1.pop();
        count++;
        maxCount++;
      }
      maxPrice = max(maxPrice, currMaxPrice);
      currMaxPrice = stockPrice[i];
    }
    s1.push(stockPrice[i]);
    if (maxPrice < stockPrice[i]) {
      result.push_back(maxCount + s1.size());
    } else if (currMaxPrice < stockPrice[i]) {
      currMaxPrice = stockPrice[i];
      result.push_back(count + s1.size());
    } else {
      result.push_back(s1.size());
    }
    count = 0;
  }
}

int main() {

  int n;
  cin >> n;
  vector<int> stockPrice;
  vector<int> result;

  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;

    stockPrice.push_back(data);
  }

  stockSpan(stockPrice, result);

  for (auto item : result) {
    cout << item << " ";
  }
}