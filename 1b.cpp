#include <iostream>
#include <cctype>

using namespace std;

static int check_num(string input) {
  switch(input.size()) {
    case 3: {
      if (input == "one") {
        return 1;
      } 
      if (input == "two") {
        return 2;
      } 
      if (input == "six") {
        return 6;
      }
      break;
    }
    case 4: {
      if (input == "four") {
        return 4;
      } 
      if (input == "five") {
        return 5;
      }
      if (input == "nine") {
        return 9;
      }
      break;
    }
    case 5: {
      if (input == "three") {
        return 3;
      }
      if (input == "seven") {
        return 7;
      }
      if (input == "eight") {
        return 8;
      }
      break;
    }
  }
  return 0;
}

static int verify_ans(string input, int i) {
  int val = 0;
  if (isdigit(input[i])) {
    return (input[i] - '0');
  }
  int diff = input.size() - i;
  if (diff >= 3) {
    val = check_num(input.substr(i, 3));
    if (val) return val;
  }
  if (diff >= 4) {
    val = check_num(input.substr(i, 4));
    if (val) return val;
  }
  if (diff >= 5) {
    val = check_num(input.substr(i, 5));
    if (val) return val;
  }
  return val;
}

static int get_last(string input) {
  int val = 0;
  for (int i = input.size() - 1; i >= 0; i--) {
    val = verify_ans(input, i);
    if (val) return val;
  }
  return 0;
}

static int get_first(string input) {
  int val = 0;
  for (unsigned int i = 0; i < input.size(); i++) {
    val = verify_ans(input, i);
    if (val) return val;
  }
  return val;
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


