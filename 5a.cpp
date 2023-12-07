#include <iostream>
#include <map>
#include <vector>
#include <cctype>
#include <climits>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

const int NUM_MAPS = 7;

static void
process_seeds(vector<long> &seeds, string &input) {
  istringstream iss(input);
  string title;
  /* seeds: */
  iss >> title;
  assert(title == "seeds:");

  long seed;
  while (iss >> seed) {
    seeds.push_back(seed);
  }
}

static void
process_maps(map<long, long> *maps) {
  string title;
  int map_no = 0;

  cin >> title;
  while (cin >> title) {
    string sdrs;
    long drs, srs, rl;
    while (cin >> sdrs) {
      if (!isdigit(sdrs[0])) break;
      drs = stol(sdrs);
      cin >> srs >> rl;
      
      if (!maps[map_no][srs-1])
        maps[map_no][srs - 1] = srs - 1;

      maps[map_no][srs - 1 + rl] = drs - 1 + rl; 
    }    
    map_no++;
  }
}

static long
find_location(long seed, map<long, long> *maps) {
  for (int i = 0; i < NUM_MAPS; i++) {
    auto it = maps[i].lower_bound(seed);
    if (it == maps[i].end()) continue;
    long diff = (*it).first - seed;
    seed = (*it).second - diff;
  }
  return seed;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  string input;
  vector<long> seeds;
  map<long, long> maps[NUM_MAPS];

  getline(cin, input);
  process_seeds(seeds, input);
  process_maps(maps);

  long ans = LONG_MAX;
  for (auto seed : seeds) {
    ans = min(ans, find_location(seed, maps));
  }

  cout << ans << '\n';
  return 0;
}
