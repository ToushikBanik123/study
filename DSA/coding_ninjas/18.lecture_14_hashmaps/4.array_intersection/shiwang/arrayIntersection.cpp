#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void arrIntersection(vector<int> &numsArr1, vector<int> &numsArr2) {
  if (numsArr1.size() == 0 || numsArr2.size() == 0)
    return;

  sort(numsArr1.begin(), numsArr1.end());

  unordered_map<int, int> seen;

  for (int num : numsArr2) {
    seen[num]++;
  }

  for (int num : numsArr1) {

    if (seen[num] > 0) {
      cout << num << " ";
      seen[num]--;
    }
  }
}

int main() {
  int n1;
  cin >> n1;

  vector<int> numsArr1;
  vector<int> numsArr2;

  for (int i = 0; i < n1; i++) {
    int data;
    cin >> data;

    numsArr1.push_back(data);
  }

  int n2;
  cin >> n2;

  for (int i = 0; i < n2; i++) {
    int data;
    cin >> data;

    numsArr2.push_back(data);
  }

  arrIntersection(numsArr1, numsArr2);
}