#include<bits/stdc++.h>
using namespace std;
//          Knapsack problem using recursion
int knapsack(int *weights, int *values, int n, int maxWeight){
	if(n == 0 || maxWeight == 0) {
		return 0;
	}
	if(maxWeight < weights[0] ) {
		return knapsack(weights+1, values +1, n-1, maxWeight);
	}
	int a = values[0] + knapsack(weights+1, values +1, n-1, maxWeight -weights[0] );
	int b = knapsack(weights+1, values +1, n-1, maxWeight);
	return max(a, b);
}
//      Knapsack problem using Memoization
int knapsack(int* weights, int* values, int n, int maxWeight, int **output) {
	if(n == 0 || maxWeight == 0) {
		return 0;
	}
	if(output[n][maxWeight] != -1) {
		return output[n][maxWeight];
	}
	if(maxWeight < weights[0] ) {
		output[n][maxWeight] =  knapsack(weights+1, values +1, n-1, maxWeight, output);
		return output[n][maxWeight];
	}
	int a = values[0] + knapsack(weights+1, values +1, n-1, maxWeight -weights[0], output );
	int b = knapsack(weights+1, values +1, n-1, maxWeight, output);
	output[n][maxWeight] =  max(a, b);
	return output[n][maxWeight];

}
int knapsack_mem(int* weights, int* values, int n, int maxWeight) {
	int **output = new int*[n+1];
	for(int i = 0; i <= n; i++) {
		output[i] = new int[maxWeight + 1];
		for(int j = 0; j <= maxWeight; j++) {
			output[i][j] = -1;
		}
	}
	return knapsack(weights, values, n, maxWeight, output);
}

// Knapsack problem using DP
int knapsack_DP(int* weights, int* values, int n, int maxWeight) {
	if(n == 0 || maxWeight == 0) {
		return 0;
	}
	int ** output = new int*[n+1];
	for(int i = 0; i <= n; i++) {
		output[i] = new int[maxWeight +1];
	}
	for(int i = 0; i <= n; i++) {
		output[i][0] = 0;
	}
	for(int j = 0; j <= maxWeight; j++) {
		output[0][j] = 0;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= maxWeight; j++) {
			if(weights[i-1] > j ) {
				output[i][j] = output[i-1][j];
			}
			else {
				int a = output[i-1][j];
				int b = values[i-1] + output[i-1][j-weights[i-1]];
				output[i][j] = max (a, b);
			}
		}
	}
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= maxWeight; j++) {
            cout << output[i][j] << "  ";
        }
        cout << endl;
    }

	return output[n][maxWeight];
}


int main() {
    int n;
    int maxWeight;
    cout << "Enter the size = ";
    cin >> n;
    int *val = new int[n];
    int *weight = new int[n];
    cout << "\nEnter the values \n";
    for(int i = 0; i < n; i++) {
        cout << " ";
        cin >> val[i]; 
    }
    cout << "\nEnter the weights\n";
    for(int i = 0; i < n; i++) {
        cout << " ";
        cin >> weight[i]; 
    }
    cout << "\nEnter the max weight = ";
    cin >> maxWeight;
    cout << endl;
    cout << "knapsack = " << knapsack_DP(weight, val, n, maxWeight) << endl;
    cout << "knapsack = " << knapsack_mem(weight, val, n, maxWeight) << endl;
}