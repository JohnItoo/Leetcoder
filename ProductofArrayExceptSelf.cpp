//Problem name : Product of Array except self
//https://leetcode.com/problems/product-of-array-except-self

#include <bits/stdc++.h>
using namespace std;

//O(N) time and space.
public:
vector<int> productExceptSelfB(vector<int>& nums) {
	int n = nums.size();
	vector<int> left(n, 1);
	vector<int> right(n, 1);

	for (int i = 1; i < n; i++) {
		left[i] = left[i - 1] * arr[i - 1];
	}

	for (int i = n - 2; i >= 0; i--) {
		right[i] = right[i + 1] * arr[i + 1];
	}

	vector<int> solution(n);

	for (int i = 0; i < n; i++) {
		solution[i] = left[i] * right[i];
	}

	return solution;

}

public:
vector<int> productExceptSelf(vector<int>& arr) {
	int n = arr.size();
	vector<int> solution(n, 1);

	for (int i = 1; i < n; i++) {
		solution[i] = solution[i - 1] * arr[i - 1];
	}

	int r = 1;
	for (int i = n - 1; i >= 0; i--) {
		solution[i] *= r;
		r *= arr[i];
	}

	return solution;

}