#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define bts(jimin) cerr << #jimin << " -> "; loveYourself(jimin); cerr << endl;
void loveYourself(int jimin)    { cerr << jimin; }
template <class T> void loveYourself(vector <T> v) { 
    cerr << "[ ";
    for (T suga : v) {
        loveYourself(suga);
        cerr << " ";
    }
    cerr << "]";
}


int vertices, edges;
vector<vector<int>> graph(10);
vector<int> visited(10);
vector<int> Parent(10);
vector<int> bfs;
vector<int> dfs;


vector<int> shortestDistance(int current) {
    vector<int> distance(10, 0);
    queue<int> bfsQueue;
    bfsQueue.emplace(current);
    bfs.emplace_back(current);
    visited[current] = 1;
    Parent[current] = -1;

    while (!bfsQueue.empty()) {
        int parent = bfsQueue.front();
        bfsQueue.pop();
        for (auto child : graph[parent]) {
            if (!visited[child]) {
                visited[child] = 1;
                distance[child] = distance[parent] + 1;
                Parent[child] = parent;
                bfs.emplace_back(child);
                bfsQueue.emplace(child);
            }
        }
    }
    return distance;
}



int main() {

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    freopen("../error.txt", "w", stderr);
   
    cin >> vertices >> edges;
    
    for (int i = 0; i < edges; i++) {
        int x, y; cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }
     
    vector<int> shortestPath = shortestDistance(0);
    bts(shortestPath);
    bts(bfs);
    bts(Parent);

}