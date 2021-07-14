#include <bits/stdc++.h>
using namespace std;

int N, M, tmp, tmp2, sol;
vector < vector <int> > vicini;

// Main code
int main()
{
  // Cncomment the following lines if you want to read/write from files
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  // Input
  cin >> N >> M;
  sol = 0;
  vicini.resize(M);

  for(size_t i = 0; i < N; ++i) {
    cin >> tmp >> tmp2;
    vicini[tmp - 1].push_back(tmp2 - 1);
    vicini[tmp2 - 1].push_back(tmp - 1);
  }

  for(size_t i = 0; i < M; ++i) {
    vector <int> o;
    for (auto a : vicini[i]) {
      if (find(o.begin(), o.end(), a) == o.end()) {
        for (auto b: vicini[a]) {
          o.push_back(b);
          if (find(vicini[b].begin(), vicini[b].end(), i) != vicini[b].end()){
            sol ++;
            //cout << i << "\t" << a << "\t" << b << endl;
          }
        }
      }
      
    }
  }

  // Output
  cout << sol/3 << endl;

  // End
  return 0;
}
