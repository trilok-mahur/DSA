#include<bits/stdc++.h>
using namespace std;
#include "student.cpp"
    int main() {
        // Node * head1 = NULL;
        // Node * head2 = NULL;
        // cout << "Take input for head1 \n";
        // head1 = takeInput(head1);
        // cout << "Take input for head2 \n";
        // head2 = takeInput(head2);
        // cout << " ans common = " << intersectPoint(head1, head2) << endl;
        int n;
        cout << "enter n = ";
        cin >> n;
        vector<vector<int>> vec( n , vector<int> (n, 0));
        cout << endl;
        cout << "Vector elements are\n";
        vec[0][2] = 9;
                vec[1][2] = 9;
                        vec[2][2] = 9;
                                vec[3][2] = 9;
        for(int i = 0; i < n; i++) {
            for(int j =0; j < n; j++) {
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }
    }