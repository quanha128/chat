#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, vector<string>> graph;
  int N, Q;
  cin >> N;
  cin >> Q;
  for (int i=0; i<Q; i++) {
    //input
    int t;
    string u, v;
    cin >> t;
    cin >> u;
    cin >> v;

    if (t==0) {
      if (graph.count(u)) {
        graph[u].push_back(v);
      } else {
        vector<string> ve;
        ve.push_back(v);
        graph.insert(pair<string, vector<string>>(u, ve));
      }
    } else {
      // cout << u << "\t";
      // cout << v << "\n";
      for (int i=0; i<graph[u].size(); i++) {
        if (graph[u][i] == v) cout << 1 << "\n";
        else cout << 0 << "\n";
      }
    }
  }
  // map<string, vector<string>>::iterator it;
  // cout << "mymap contains:\n";
  // for (it=graph.begin(); it!=graph.end(); ++it) {
  //   cout << it->first << " => ";
  //   for (int i=0; i<it->second.size(); i++)
  //     cout << it->second[i];
  //   cout << '\n';
  // }

  return 0;
}
