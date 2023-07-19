#include<bits/stdc++.h>
using namespace std;
int highestFrequency(int arr[], int n) {
    unordered_map<int, int> map;
int maxfreq = 0;
    for(int i = 0; i < n; i++) {
        map[arr[i]]++;
        maxfreq = max(maxfreq, map[arr[i]]);
    }
    int result;
    for(int i = 0; i < map.size(); i++) {
        if(maxfreq == map[arr[i]]) {
            result = arr[i];
            break;
        }
    }
    return result;
}