#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &current) {
  if (current.size() == 0) {
    cout << "[]" << endl;
    return;
  }

  for (int i = 0; i < current.size(); i++) {
    cout << current[i] << " ";
  }
  cout << endl;
}

void printSubSets(vector<int> &arr, int idx, vector<int> &current) {
  if (idx == arr.size()) {
    print(current);
    return;
  }

  print(current);

  for (int i = idx; i < arr.size(); i++) {
    current.push_back(arr[i]);
    printSubSets(arr, i + 1, current);
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

  printSubSets(arr, 0, current);

  return 0;
}