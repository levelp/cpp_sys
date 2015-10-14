#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > edges;

int main() {
  int n = 3, m = 2;
  //edges.reserve(n, );
  for(int i = 0; i < n; i++)
    edges.push_back(vector<int>());
  edges[0].push_back(1);
  edges[1].push_back(2);
  edges[2].push_back(3);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < edges[i].size(); j++)
      cout << edges[i][j] << endl;

  return 0;
}
