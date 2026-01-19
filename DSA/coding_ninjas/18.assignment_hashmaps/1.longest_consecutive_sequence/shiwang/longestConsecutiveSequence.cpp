#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

pair<int, int> longestConsecutiveSequence(vector<int> &nums) {
  if (nums.size() == 0)
    return {INT_MIN, INT_MIN};

  unordered_map<int, bool> hasNumMap;

  for (int num : nums) {
    hasNumMap[num] = true;
  }

  int maxLength = 1;
  int start = nums[0];
  int end = nums[0];

  for (int i = 0; i < nums.size(); i++) {
    int currentLength = 1;
    int currentNum = nums[i];

    if (hasNumMap.find(currentNum - 1) != hasNumMap.end()) {
      continue;
    }

    while (hasNumMap.find(++currentNum) != hasNumMap.end()) {
      currentLength++;
    }

    if (currentLength > maxLength) {
      maxLength = currentLength;
      start = nums[i];
      end = currentNum - 1;
    }
  }
  return {start, end};
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

  auto ans = longestConsecutiveSequence(nums);
  cout << ans.first << " " << ans.second << endl;
}