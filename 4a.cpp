#include <iostream>
#include <unordered_set>
#include <cctype>
#include <cmath>
#include <sstream>

using namespace std;

static long get_score(string line) {
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
  return (matches == 0) ? 0 : pow(2, matches - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  long sum = 0;
  string line;
  while (cin >> line) {
    cin >> line;
    getline(cin, line);
    sum += get_score(line);
  }

  cout << sum << '\n';
  return 0;
}
