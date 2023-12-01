#include <iostream>
#include <cctype>

using namespace std;

static int get_last(string input) {
  for (auto c = input.rbegin(); c < input.rend(); c++) {
    if (isdigit(*c)) {
      return atoi(&(*c));
    }
  }
  return 0;
}

static int get_first(string input) {
  for (auto c : input) {
    if (isdigit(c)) {
      return atoi(&c);
    }
  }
  return 0;
}
static int get_value(string input) {
  int ans = get_first(input) * 10 + get_last(input);
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  string input;
  long ans = 0;
  while (cin >> input) {
    ans += get_value(input);
  }
  cout << ans << '\n';
  return 0;
}
