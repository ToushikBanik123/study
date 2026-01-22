#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int pairSumTo0(vector<int> &numsArr1) {
  if (numsArr1.size() == 0)
    return 0;

  unordered_map<int, int> freqMap;

  int count = 0;

  for (int num : numsArr1) {
    if (freqMap.find(-num) != freqMap.end()) {
      count += freqMap[-num];
    }
    freqMap[num]++;
  }

  return count;
}

int main() {
  int n1;
  cin >> n1;

  vector<int> numsArr1;

  for (int i = 0; i < n1; i++) {
    int data;
    cin >> data;

    numsArr1.push_back(data);
  }

  cout << pairSumTo0(numsArr1);
}