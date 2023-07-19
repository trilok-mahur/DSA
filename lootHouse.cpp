#include<bits/stdc++.h>
using namespace std;
//    A thief wants to loot houses. He knows the amount of money in
//    each house. He cannot loot two consecutive houses. Find the maximum
//    amount of money he can loot

//          using Memoization
int maxMoneyLooted(int arr[], int n, int *output) {
	if(n <= 0) {
		return 0;
	}
	if(output[n] != -1) {
		return output[n];
	}
	output[n] = max( maxMoneyLooted(arr +1 , n - 1, output), arr[0] + maxMoneyLooted(arr +2, n -2, output) );
	return output[n];
}
int maxMoneyLooted(int *arr, int n){
	if(n <= 0) {
		return 0;
	}
	int *output = new int[n+1];
	for(int i = 0; i <= n; i++) {
		output[i] = -1;
	}
	return maxMoneyLooted(arr, n, output);
	
}
//      using DP comment
int maxMoneyLooted_DP(int *arr, int n) {
	if(n <= 0) {
		return 0;
	}
	int *output = new int[n+1];
	output[0] = 0;
	output[1] = arr[0];
	for(int i = 2; i <= n; i++) {
		output[i] = max(output[i-1], arr[i-1] + output[i-2] );
	}
	return output[n];
}int main() {
    int arr[] = {50, 84, 33, 200, 400};
    cout << "dp = " << maxMoneyLooted_DP(arr, 5) << " mem = " << maxMoneyLooted(arr,5) << endl; 
}
