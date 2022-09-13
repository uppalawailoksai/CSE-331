#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
vector<int> b;
vector<vector<int>> graph;
vector<bool> is_visited;
vector<bool> is_special;
vector<int> parent_graph;
vector<pair<int, int>> node_heights;
int n;
long int possible_paths;
int mod = 1000000007;

void makeParentGraph(int node, int parent) {
    parent_graph[node] = parent;
    for (int i = 0; i < graph[node].size(); i++) {
        if (parent_graph[graph[node][i]] == -2)
            makeParentGraph(graph[node][i], node);
    }
}

int initializeNodeHeight(int node) {
    is_visited[node] = true;
    int height = -1;
    for (int i = 0; i < graph[node].size(); i++)
        if (!is_visited[graph[node][i]])
            height = max(height, initializeNodeHeight(graph[node][i]));
    node_heights.push_back(make_pair(height + 1, node));
    return height + 1;
}

bool makeVirticalPaths(int node) {
    is_visited[node] = true;
    map<int, int> values;
    vector<int> values_to_find;
    int top_node = node;
    values[a[node]]++;
    values_to_find.push_back(b[node]);
    for (int i = 0; i < values_to_find.size(); i++) {
        if (values[values_to_find[i]] == 0) {
            do {
                int parent = parent_graph[top_node];
                if (parent == -1 || is_visited[parent])
                    return false;
                values[a[parent]]++;
                values_to_find.push_back(b[parent]);
                is_visited[parent] = true;
                top_node = parent;
            } while (values_to_find[i] != a[top_node]);
        }
        values[values_to_find[i]]--;
    }
    is_special[top_node] = true;
    return true;
}

bool isPossibleVirticalPartitions() {
    parent_graph.clear();
    parent_graph.resize(n, -2);
    node_heights.clear();
    makeParentGraph(0, -1);
    initializeNodeHeight(0);
    sort(node_heights.begin(), node_heights.end());
    is_visited.clear();
    is_visited.resize(n);
    for (int i = 0; i < n; i++) {
        if (!is_visited[node_heights[i].second]) {
            if (!makeVirticalPaths(node_heights[i].second))
                return false;
        }
    }
    return true;
}

void calcPossiblePaths(int node) {
    is_visited[node] = true;
    if (graph[node].size() == 1 && is_visited[graph[node][0]])
        return;
    int flag = true;
    for (int i = 0; i < graph[node].size(); i++) {
        if(!is_visited[graph[node][i]]) {
            calcPossiblePaths(graph[node][i]);
            if(!is_special[graph[node][i]])
                flag = false;
        }
    }
    if (flag)
        possible_paths = (possible_paths * (graph[node].size() + (node == 0 ? 1 : 0))) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int s;
        cin >> n >> s;
        a.clear();
        b.clear();
        is_special.clear();
        is_visited.clear();
        graph.clear();

        a.resize(n);
        b.resize(n);
        is_visited.resize(n);
        is_special.resize(n);
        graph.resize(n, vector<int>());
        possible_paths = 1;

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        bool is_possible = isPossibleVirticalPartitions();
       
        if (s == 1) {
            if (!is_possible)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        } else if (!is_possible) {
            cout << 0 << endl;
        } else {
            is_visited.clear();
            is_visited.resize(n);
            calcPossiblePaths(0);
            cout << possible_paths << endl;
        }
    }
}