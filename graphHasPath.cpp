#include <bits/stdc++.h>
using namespace std;
bool hasPath(int ** edges, bool * visited, int n, int v1, int v2) {
    if(v1 == v2 ) {
        return true;
    }
    queue<int> q;
    q.push(v1);
    visited[v1] = true;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        for(int i = 0; i < n; i++) {
            if(i == current) {
                continue;
            }
            if(visited[i]) {
                continue;
            }
            if(!visited[i] && edges[current][i]) {
                if(i == v2) {
                    return true;
                }
                else{
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    return false;
    
}

int main() {

    int n , e;
    cout << "Enter number of Vertices = ";
    cin >> n;
    cout << "\nEnter number of edges = ";
    cin >> e ;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++) {
        edges[i]  = new int[n];
        for(int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }
    cout << "\nEnter first vertex ans second vertex\n";
    for(int i = 0; i < e; i++) {
        int f , s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool * visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    cout << "\nEnter V1 & V2 for find the path between V1 & V2\n";
    int v1, v2;
    cin >> v1 >> v2;
    bool ans = hasPath(edges, visited, n, v1, v2);
    if(ans) {
        cout << "There is path betwenn " << v1 <<" & " << v2;
    }
    else {
        cout << "There is no path between " << v1 << " & " << v2;
    }
    return 0;


}