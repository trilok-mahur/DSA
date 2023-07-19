#include<bits/stdc++.h>
using namespace std;
//               using recursion
int editDistance(string s1, string s2) {
	if(s1.size() == 0 && s2.size() == 0){
		return 0;
	}
	if(s1.size() == 0 && s2.size() != 0) {
		return s2.size();
	}
	if(s2.size() == 0 && s1.size() != 0) {
		return s1.size();
	}
	if(s1[0] == s2[0]) {
		return editDistance(s1.substr(1) , s2.substr(1));
	}
	else {
		int a = 1 + editDistance(s1.substr(1), s2.substr(1));   // replace in s1
		int b = 1 + editDistance(s1, s2.substr(1));            //  insert in s1
		int c = 1 + editDistance(s1.substr(1), s2);           //   delete in s1
		return min(a, min(b, c));
	}
}

//              suing memoization
int editDistance_mem_helper(string s1, string s2, int **output) {
	int m = s1.size();
	int n = s2.size();
	if(m == 0 || n == 0 ) {
		return max(m, n);
	}
	if(output[m][n] != -1) {
		return output[m][n];
	}
	if(s1[0] == s2[0]) {
		output[m][n] = editDistance_mem_helper(s1.substr(1), s2.substr(1), output);
		return output[m][n];
	}
	else {
		int a = 1 + editDistance_mem_helper(s1.substr(1), s2, output);
		int b = 1 + editDistance_mem_helper(s1, s2.substr(1), output);
		int c = 1 + editDistance_mem_helper(s1.substr(1), s2.substr(1), output);
		output[m][n] = min(a, min(b, c));
		return output[m][n]; 
	}
}
int editDistance_mem(string s1, string s2) {
	int m = s1.size();
	int n = s2.size();
	int **output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
		for(int j = 0; j <= n; j++) {
			output[i][j] = -1;
		}
	}
	return editDistance_mem_helper(s1, s2, output);
}
// 				Edit distance using Dynamic programming ( DP )
int editDistance_DP(string S, string T) {
	int m = S.size();
	int n = T.size();
	int ** output = new int*[m+1];
	for(int i = 0; i <= m; i++) {
		output[i] = new int[n+1];
	}
	for(int i = 0; i <= m; i++) {
		output[i][0] = i;
	}
	for(int j = 0; j <= n; j++) {
		output[0][j] = j;
	} 
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(S[m-i] == T[n-j]) {
				output[i][j] = output[i-1][j-1];
			}
			else{
				int a = 1 + output[i-1][j-1];
				int b = 1 + output[i][j-1];
				int c = 1 + output[i-1][j];
				output[i][j] = min(a, min(b, c));
			}
		}
	}
	cout << "matrix for edit distance DP\n";
	for(int i = 0; i <= m; i++) {
		for(int j = 0 ; j <= n; j++) {
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
	return output[m][n];
}
int main() {
	cout <<"DP = " <<  editDistance_DP("ab12365478963456c", "abcdefghijklmnopqrstuvwxyzxabcd") << endl;
	cout <<"mem = " << editDistance_mem("ab12365478963456c", "abcdefghijklmnopqrstuvwxyzxabcd") << endl;
	cout << "recu = " << editDistance("ab12365478963456c", "abcdefghijklmnopqrstuvwxyzxabcd") << endl;
}