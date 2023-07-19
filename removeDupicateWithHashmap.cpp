#include<bits/stdc++.h>
using namespace std;
vector<int> removeDupicates(int arr[], int size) {
    vector<int> output;
    unordered_map<int, bool> seen;
    for(int i = 0; i < size; i++) {
        if(seen.count(arr[i]) > 0) {
            continue;
        }
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    } 
    return output;
}
int main() {
    int arr[] = {1,2,3,2,3,4,7,5,0,0,6,6,0,7,6,5,3,2,1};
    vector<int> output = removeDupicates(arr,19);
    for(auto it : output) {
        cout << it << " ";
    }
    cout << endl;
    
}