#include<bits/stdc++.h>
using namespace std;
void printGraphDFS(int **edges, bool *visited, int sv, int n) {
    cout << sv << endl;
    visited[sv] = true;
    for(int i = 0; i < n; i++) {
        if( i == sv) {
            continue;
        }
        if(edges[sv][i] == 1) {
            if(visited[i]) {
                continue;
            }
        printGraphDFS(edges, visited, i, n);
        }
    }

}
void DFS(int ** edges, int n)  {
    bool * visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    } 
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            printGraphDFS(edges, visited, i, n);
        }
    }
}
void  printGraphBFS(int** edges, bool *visited, int sv, int n) {
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty()) {
        int current = pendingVertices.front();
        pendingVertices.pop();
        cout << current << endl;
        for(int i = 0 ; i < n; i++) {
            if(i == current) {
                continue;
            }
            if(edges[current][i] == 1 && !visited[i]) {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }

}
void BFS(int ** edges, int n) {
    bool * visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    } 
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            printGraphBFS(edges, visited, i, n);
        }
    }    
} 

int main() {
    int n; 
    int e;
    cout << "Enter the number of Node = ";
    cin >> n;
    cout << "\nEnter the number of edges = ";
    cin >> e;
    int ** edges = new int*[n];
    for(int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }
    cout << "\nEnter edges\n";
    for(int i = 0; i < e; i++) {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    cout << "BFS\n";
    BFS(edges, n);
    cout << "\nDFS\n";
    DFS(edges, n);




}