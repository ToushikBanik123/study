#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int> &stockPrices) {
  stack<int> stockPriceIdxs;
  vector<int> result;

  for (int i = 0; i < stockPrices.size(); i++) {
    int count = 1;

    if (stockPriceIdxs.empty() ||
        stockPrices[i] <= stockPrices[stockPriceIdxs.top()]) {
      result.push_back(1);
    } else {
      while (!stockPriceIdxs.empty() &&
             stockPrices[i] > stockPrices[stockPriceIdxs.top()]) {
        count += result[stockPriceIdxs.top()];
        stockPriceIdxs.pop();
      }
      result.push_back(count);
    }
    stockPriceIdxs.push(i);
  }

  return result;
}

int main() {

  vector<int> stockPrices;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;
    stockPrices.push_back(data);
  }

  vector<int> result = stockSpan(stockPrices);

  for (int i = 0; i < n; i++) {
    cout << result[i] << " ";
  }
}