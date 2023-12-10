#include <iostream>
#include <map>
#include <vector>
#include <cctype>
#include <climits>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

static long get_ways(double t, double d) {
  double desc = sqrt(pow(t, 2) - (4 * d));
  long low = ceil((t - desc)/2);
  long high = floor((t + desc)/2);
  return high - low + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  
  string time;
  getline(cin, time);

  string dist;
  getline(cin, dist);

  istringstream isst(time), issd(dist);
  string title;
  isst >> title;
  issd >> title;

  string t, buf_t, d, buf_d;
  while (isst >> buf_t) {
    t += buf_t;
    issd >> buf_d;
    d += buf_d;
  }

  long ans = get_ways(stod(t), stod(d));
  
  cout << ans << '\n';
  return 0;
}
