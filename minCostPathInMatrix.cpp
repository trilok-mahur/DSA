#include<bits/stdc++.h>
using namespace std;
// Minimum cost path in matrix using recursion
//       method - 1
int minCostPath(int **input, int m, int n, int i, int j) {
	if(i == m -1 && j == n-1) {
		return input[i][j];
	}
	if(i == m || j == n) {
		return INT_MAX;
	}
	int x = minCostPath(input, m, n, i+1,j);
	int y = minCostPath(input, m, n, i, j +1);
	int z = minCostPath(input, m, n, i+1, j +1 );
	return min(x, min(y , z)) + input[i][j];
}
// Minimum cost path in matrix using Memoization
//       method - 2
int minCostPath(int **input, int m, int n, int i, int j, int **output) {
	if(i == m -1 && j == n-1) {
		return input[i][j];
	}
	if(i == m || j == n) {
		return INT_MAX;
	}
	if(output[i][j] != -1) {
		return output[i][j];
	}
	
	int x = minCostPath(input, m, n, i+1,j, output);
	int y = minCostPath(input, m, n, i, j +1, output);
	int z = minCostPath(input, m, n, i+1, j +1, output );
	output[i][j] = min(x, min(y , z)) + input[i][j];
	return output[i][j];


}
int minCostPath(int **input, int m, int n) {
	int **output = new int*[m];
	for(int i = 0; i < m; i++) {
		output[i] = new int[n];
		for(int j = 0; j < n; j++) {
			output[i][j] = -1;
		}
	}
	return minCostPath(input, m ,n, 0, 0,output );
}
// Minimum cost path in matrix using Dynamic Programming
//       method - 3
int minCostPath(int **input, int m, int n) {
	if(m < 2 && n < 2) {
		return input[0][0];
	}
	int **output = new int*[m];
	for(int i = 0; i < m ; i++) {
		output[i] = new int[n];
	}
	output[m-1][n-1] = input[m-1][n-1];
	for(int j = n-2 ; j >= 0; j--) {
		output[m-1][j] = output[m-1][j+1] + input[m-1][j];
	}
	for(int i = m-2; i >= 0; i--) {
		output[i][n-1] = output[i+1][n-1] +input[i][n-1];
	}
	for(int j = n-2; j >= 0; j--) {
		for(int i = m-2; i >= 0; i--) {
			output[i][j] = min(output[i+1][j+1], min(output[i+1][j], output[i][j+1])) + input[i][j];
		}
	}
	return output[0][0];
}