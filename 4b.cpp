#include <iostream>
#include <unordered_set>
#include <vector>
#include <cctype>
#include <cmath>
#include <sstream>

using namespace std;

static void update_cnt(string line, vector<int> &cnt, int i) {
  int matches = 0;
  istringstream iss(line);
  unordered_set<string> nums;
  string num = "";
  while (num != "|") {
    iss >> num;
    nums.insert(num);
  }

  while (iss >> num) {
    auto it = nums.find(num);
    if (it != nums.end()) {
      matches++;
      nums.erase(it);
    }
  }

  for (int j = 1; j <= matches; j++) {
    cnt[i + j] += cnt[i];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  const int mxN = 300;
  vector<int> cnt(mxN, 1);

  long sum = 0;
  string line;
  int i = 0;
  while (cin >> line) {
    cin >> line;
    getline(cin, line);
    sum += cnt[i];
    update_cnt(line, cnt, i++);
  }

  cout << sum << '\n';
  return 0;
}
