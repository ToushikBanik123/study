#include <iostream>
#include <vector>
using namespace std;

void takeVectorInput(vector<int> &arr, int n){
	int temp;
	cout << "Enter the elements of your vector : ";
	for(int i = 0; i < n; i++){
		cin >> temp;
arr.push_back(temp);
}
}

void printVector(vector<int> &arr){
	for(int x : arr){
		cout << x << " ";
    }
    cout << endl;
}

void checkingSumOnIndex(vector<int> &arr, int j, int sum, int k, vector<int> ans){
	if(sum>k) return;
	if(sum == k){
    printVector(ans);
    return;
    }
    if(arr.size() <= j) return;
	checkingSumOnIndex(arr, j+1, sum, k, ans);
	ans.push_back(arr[j]);
	checkingSumOnIndex(arr, j+1, sum+arr[j], k, ans);
}

void checkingSum(vector<int> &arr, int i, int k){
	if(arr.size() <= i) return;
	vector <int> ans;
	ans.push_back(arr[i]);
    checkingSumOnIndex(arr,i+1,arr[i],k,ans);
    checkingSum(arr,i+1,k);
}


int main(){
	int n;
	int k;
	vector<int> arr;
	cout << "Enter the length of the array (n) : ";
	cin >> n;
	cout << "Enter the element to find in the array (k) : ";
	cin >> k;
	takeVectorInput(arr,n);
	checkingSum(arr,0,k);
	return 0;
}
