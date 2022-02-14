#include<bits/stdc++.h>

using namespace std;

void ingraph(vector<int> graph[], int v, int m) {
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
}

void dfs_util(vector<int> graph[], int s, bool visited[]) {
    if (visited[s]) return;
    cout << s << " ";
    visited[s] = true;
    for (auto i = graph[s].begin(); i != graph[s].end(); i++) {
        dfs_util(graph, *i, visited);
    }
}

void itr_dfs_util(vector<int> graph[], int s, bool visited[]) {
    if (visited[s]) return;

    vector<int> st; st.push_back(s);

    while (!st.empty()) {
        s = st.back();
        st.pop_back();

        if (!visited[s]) cout << s << "\n";
        visited[s] = true;

        for (auto i = graph[s].begin(); i != graph[s].end(); i++) {
            if (!visited[*i]) st.push_back(*i);
        }
    }

}

void dfs(vector<int> graph[], int v) {
    bool visited[v]; for (int i = 0; i < v; i++) visited[i] = false;
    for (int i = 0; i < v; i++) {
        if (!visited[v]) itr_dfs_util(graph, i, visited);
    }
}

void bfs(vector<int> graph[], int s, int v) {
    bool visited[v]; for (int i = 0; i < v; i++) visited[i] = false;

    queue<int> bfsq; bfsq.push(s);
    cout << s << " "; int curr = s;
    visited[curr] = true;

    while (!bfsq.empty()) {
        curr = bfsq.front();
        bfsq.pop();

        vector<int> :: iterator it;
        for (it = graph[curr].begin(); it != graph[curr].end(); it++) {
            if (!visited[*it]) {
                visited[*it] = true;
                bfsq.push(*it);
                cout << *it << " ";
            }
        }
    }
}

vector<int> sortest_path_util(vector<int> graph[], int s, int v) {
    bool visited[v]; for (int i = 0; i < v; i++) visited[i] = false;

    queue<int> bfsq; bfsq.push(s);
    //cout << s << " ";
    int curr = s;
    visited[curr] = true;
    vector<int> parent(v, -1);

    while (!bfsq.empty()) {
        curr = bfsq.front();
        bfsq.pop();

        vector<int> :: iterator it;
        for (it = graph[curr].begin(); it != graph[curr].end(); it++) {
            if (!visited[*it]) {
                parent[*it] = curr;
                visited[*it] = true;
                bfsq.push(*it);
            }
        }
    }
    return parent;
}

void short_path(vector<int> graph[], int v, int a, int b) {
    vector<int> parent = sortest_path_util(graph, a, v);
    list<int> path;
    bool ans = true;
    /*for(int i = 0; i < parent.size(); i++) cout << parent[i] << " ";
    cout << "\n";*/
    for (int i = b; i != a; i = parent[i]) {
        if (i == -1) {
            ans = false;
            break;
        }
        path.push_front(i);
    }
    if (ans) {
        cout << path.size() << "\n";
        for (auto i = path.begin(); i != path.end(); i++) cout << *i << " ";
    }
    else cout << "IMPOSSIBLE/n";
}

int main() {
    int v, m; cin >> v >> m;
    vector<int> graph[v];
    ingraph(graph, v, m);

    dfs(graph, v);
}