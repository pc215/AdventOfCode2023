#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

static void add_galaxies(string &row, vector<pair<int, int>> &coords, 
                         vector<bool> &empty_c, vector<bool> &empty_r) {
  istringstream iss(row);
  char galaxy;
  bool is_empty_row = true;
  int m = empty_r.size();
  int n = empty_c.size();
  for (int i = 0; i < n; i++) {
    iss >> galaxy;
    bool empty_galaxy = (galaxy == '.');

    empty_c[i] = (empty_c[i] && empty_galaxy);
    is_empty_row &= empty_galaxy;

    if (!empty_galaxy) {
      coords.push_back({m, i});
    }
  }
  empty_r.push_back(is_empty_row);
}

static void add_offsets(map<int, int> &off, vector<bool> &empty) {
  int extra = 0;
  for (unsigned int i = 0; i < empty.size(); i++) {
    if (empty[i]) {
      off[i] = ++extra;
    }
  }
}

static long get_dist(int ci, int cj, map<int, int> &off) {
  long ans = abs(ci - cj);
  auto it_i = off.upper_bound(ci);
  auto it_j = off.upper_bound(cj);
  auto off_i =  (it_i == off.begin()) ? 0 : (*--it_i).second;
  auto off_j =  (it_j == off.begin()) ? 0 : (*--it_j).second;
  ans += abs(off_i - off_j);
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  vector<pair<int, int>> coords;
  /* Offsets based on row number/column number */
  map<int, int> off_r, off_c;

  string row;
  getline(cin, row);
  vector<bool> empty_c(row.size(), true), empty_r;

  
  do {
    add_galaxies(row, coords, empty_c, empty_r);
  } while (getline(cin, row));

  add_offsets(off_c, empty_c);
  add_offsets(off_r, empty_r);

  long ans = 0;
  for (unsigned int i = 0; i < coords.size(); i++) {
    auto [xi, yi] = coords[i];
    for (unsigned int j = (i + 1); j < coords.size(); j++) {
      auto [xj, yj] = coords[j];
      auto dist = get_dist(xi, xj, off_r) + get_dist(yi, yj, off_c);
      ans += dist;
      cout << "(" << xi << ", " << yi << ")" << ' ';
      cout << "(" << xj << ", " << yj << ")" << ' ';
      cout << dist << '\n';
    }
  }

  cout << ans << '\n';
  return 0;
}
