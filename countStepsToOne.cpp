#include<bits/stdc++.h>
using namespace std;
int countStepsToOne(int n)
{
	if( n < 2) {
		return 0;
	}
	int x;
	int *arr = new int[n+1];
	arr[0] = 0;
	arr[1] = 0;
	
	for(int i = 2; i <= n; i++) {
		int y = INT_MAX;
		int z = INT_MAX;
		x = arr[i-1];
		if(i % 2 ==0) {
			y = arr[i/2];
		}
		if( i % 3 == 0) {
			z = arr[i/3];
		}
		arr[i] = 1 + min( x, min( z, y));
	}
	return arr[n];
}