#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int pairsWithDifferenceK(vector<int>& nums, int k) {

	unordered_map<int, int> freqMap;

	for(int num : nums) {
		freqMap[num]++;
	}

	int count = 0;

	if(k == 0) {
		for(auto p: freqMap) {
			if(p.second > 1) {
				count += (p.second * (p.second - 1))/2;
			}
		}
		return count;
	}

	for(auto p: freqMap) {
		if(freqMap.find(p.first + k) != freqMap.end()) {
			count += freqMap[p.first] * freqMap[p.first + k];
		}
	}

	return count;
}

int main() {
	int n;
	cin >> n;

	vector<int> nums;

	for(int i = 0; i < n; i++) {
		int data;
		cin >> data;

		nums.push_back(data);
	}

	int target;
	cin >> target;

	cout << pairsWithDifferenceK(nums, target);
}