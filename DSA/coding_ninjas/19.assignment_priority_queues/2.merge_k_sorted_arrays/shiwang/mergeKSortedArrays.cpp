#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void getFinalQueue(vector<int>& input, priority_queue<int, vector<int>, greater<int>>& pq) {
	for(int i = 0; i < input.size(); i++) {
		pq.push(input[i]);
	}
}

vector<int> mergeKSortedArray(vector<vector<int>>& input) {

	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> ans;

	for(int i = 0; i < input.size(); i++) {
		getFinalQueue(input[i], pq);
	}

	while(!pq.empty()) {
		ans.push_back(pq.top());
		pq.pop();
	}

	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> input;

	for(int i = 0; i < n; i++) {
		int k;
		cin >> k;

		vector<int> arr;

		for(int j = 0; j < k; j++) {
			int data;
			cin >> data;

			arr.push_back(data);
		}

		input.push_back(arr);
	}

	vector<int> ans = mergeKSortedArray(input);

	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}