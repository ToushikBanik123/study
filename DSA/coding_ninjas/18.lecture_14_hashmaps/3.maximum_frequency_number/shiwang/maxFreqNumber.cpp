#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int maxFrequencyNumber(vector<int> &nums) {
  if (nums.size() == 0)
    return INT_MIN;

  int maxFreqNum = nums[0];
  int maxFreq = 1;

  unordered_map<int, pair<int, int>> freqMap;
  for (int i = 0; i < nums.size(); i++) {
    if (freqMap.find(nums[i]) == freqMap.end()) {
      freqMap[nums[i]] = {i, 1};
    } else {
      freqMap[nums[i]].second++;
    }
  }

  int minIdx = nums.size();

  for (auto freq : freqMap) {
    int value = freq.first;
    int idx = freq.second.first;
    int occur = freq.second.second;

    if (occur > maxFreq || (occur == maxFreq && idx < minIdx)) {
      maxFreqNum = value;
      minIdx = idx;
      maxFreq = occur;
    }
  }

  return maxFreqNum;
}

int main() {
  int n;
  cin >> n;

  vector<int> nums;

  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;

    nums.push_back(data);
  }

  cout << maxFrequencyNumber(nums);
}