#include<bits/stdc++.h>
using namespace std;
int isDivisible(string s){
	    int ans = 0;
	    int tri = 1;
        for(long i = s.size() - 1; i >= 0; i--) {
            ans += tri*s[i];
            ans = ans % 3;
            tri = 2 * tri;
            tri = tri % 3;
        }
        return ans % 3 == 0;
	}
    int main() {
        cout << "dvd";
    }
    //string of 0 and 1 char only