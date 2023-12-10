#include <iostream>
#include <map>
#include <vector>
#include <cctype>
#include <climits>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

static long get_ways(long t, long d) {
  long cnt = 0;
  long v = t/2;
  if (t % 2 == 0 && (v * v) > d) {
    cnt++;
    v--;
  }

  while ((v * (t - v)) > d) {
    cnt += 2;
    v--;
  }

  return cnt;
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

  long t, d;
  long prod = 1;
  while (isst >> t) {
    issd >> d;
    prod *= get_ways(t, d);
  }
  
  cout << prod << '\n';
  return 0;
}
