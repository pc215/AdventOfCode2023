#include <iostream>
#include <cctype>
#include <sstream>

using namespace std;

long get_power(string game) {
  string token;
  long value = 0;
  long r = 0, g = 0, b = 0;
  istringstream iss(game);
  while (iss >> value) {
    iss >> token;
    if (!isalpha(token.back())) {
      token.pop_back();
    }

    if (token == "red") {
      r = max(r, value);
    } else if (token == "green") {
      g = max(g, value);
    } else if (token == "blue") {
      b = max(b, value);
    } else {
      cout << "Invalid Token!";
      exit(1);
    }
  }
  return (r * g * b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  string game;
  int game_no = 0;
  long ans = 0;

  while (cin >> game >> game_no) {
    cin >> game;
    getline(cin, game);
    ans += get_power(game);
  }
  
  cout << ans << '\n';
  return 0;
}
