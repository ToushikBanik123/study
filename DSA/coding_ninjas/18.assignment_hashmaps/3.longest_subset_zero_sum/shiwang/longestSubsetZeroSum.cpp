#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int longestSubsetWithZeroSum(vector<int> &nums) {
  if (nums.size() == 0)
    return 0;

  int maxLength = 0;
  unordered_map<int, int> sumMap;

  int sum = 0;

  for (int i = 0; i < nums.size(); i++) {

    sum += nums[i];

    if (sum == 0) {
      maxLength = max(maxLength, i + 1);
    }

    if (sumMap.find(sum) != sumMap.end()) {
      maxLength = max(maxLength, i - sumMap[sum]);
    }

    if (sumMap.find(sum) == sumMap.end()) {
      sumMap[sum] = i;
    }
  }
  return maxLength;
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

  cout << longestSubsetWithZeroSum(nums);
}