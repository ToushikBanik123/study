#include<iostream>
#include<vector>
using namespace std;

void downHeapify(vector<int>& nums, int idx, int len) {

	while(true) {
		int left = 2*idx + 1;
		int right = 2*idx + 2;
		int smallest = idx;

		if(left < len && nums[left] < nums[smallest])
			smallest = left;

		if(right < len && nums[right] < nums[smallest])
			smallest = right;

		if(smallest == idx) break;

		swap(nums[idx], nums[smallest]);
		idx = smallest;
	}
}


void heapSort(vector<int>& nums, int n) {

	for(int i = n/2 - 1; i >= 0; i--) {
		downHeapify(nums, i, n);
	}

	int j = n - 1;
	int i = 0;

	while(j > i) {
		swap(nums[i], nums[j]);
		downHeapify(nums, 0, j - 1);
		j--;
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> input;

	for(int i = 0; i < n; i++) {
		int data;
		cin >> data;

		input.push_back(data);
	}

	heapSort(input, n);

	for(int i = 0; i < n; i++) {
		cout << input[i] << " ";
	}

}