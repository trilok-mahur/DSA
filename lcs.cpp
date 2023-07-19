#include<bits/stdc++.h>
using namespace std;

//  LCS using recursion
int lcs(string S, string T) {
    if(S.length() == 0 || T.length() == 0) {
        return 0;
    }
    if(S[0] == T[0]) {
        return 1 + lcs(S.substr(1), T.substr(1));
    }
    else {
        return max(lcs(S.substr(1), T), lcs(S, T.substr(1)));
    }
}
// using Memoization
int LCS_mem_helper(string S, string T, int ** output) {
    int m = S.size();
    int n = T.size();
    if(n == 0 || m == 0) {
        return 0;
    }
    if(output[m][n] != -1) {
        return output[m][n];
    }
    int ans;
    if(S[0] == T[0]) {
        ans = 1 + LCS_mem_helper(S.substr(1), T.substr(1), output);
    }
    else {
        int a = LCS_mem_helper(S.substr(1), T, output);
        int b = LCS_mem_helper(S, T.substr(1), output);
        ans = max(a, b);
    }
    output[m][n] = ans;
    return output[m][n];
}
int LCS_mem(string S, string T) {
    int m = S.size();
    int n = T.size();
    int ** output = new int*[m+1];
    for(int i = 0 ; i < m + 1; i++) {
        output[i] = new int[n+1];
        for(int j = 0; j< n + 1; j++) {
            output[i][j] = -1;
        }
    }
    int ans = LCS_mem_helper(S, T, output);
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++){
            cout << output[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
    return ans;
}
int LCS_DP(string S, string T) {
    int m = S.size();
    int n = T.size();
    int ** output = new int*[m+1];
    for(int i = 0; i <= m; i++) {
        output[i] = new int[n+1];
    }
    for(int i = 0; i <= m; i++) {
        output[i][0] = 0;
    }
    for(int j = 1; j <= n; j++) {
        output[0][j] = 0;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(S[m-i] == T[n-j]) {
                output[i][j] = 1 + output[i-1][j-1];
            }
            else {
                int a = output[i-1][j];
                int b = output[i][j-1];
                int c= output[i-1][j-1];
                output[i][j] = max(a, max(b, c));
            }
        }
    }
    cout << endl;
    cout << "Output matrix is given by\n";
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++) {
            cout<< output[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
    return output[m][n];
}

int main() {
    cout << LCS_DP("abc", "cba") << endl;
    cout << LCS_mem("abc", "cba") << endl;
}