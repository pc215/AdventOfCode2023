#include <iostream>
#include <cctype>
#include <sstream>

using namespace std;

#define RED_MAX 12
#define GREEN_MAX 13
#define BLUE_MAX 14

bool is_valid(string game) {
  string token;
  int value = 0;
  int r = 0, g = 0, b = 0;
  char end = ' ';
  istringstream iss(game);
  while (iss >> value) {
    iss >> token;
    if (!isalpha(token.back())) {
      end = token.back();
      token.pop_back();
    }

    if (token == "red") {
      r += value;
      if (r > RED_MAX) {
        return false;
      }
    } else if (token == "green") {
      g += value;
      if (g > GREEN_MAX) {
        return false;
      }
    } else if (token == "blue") {
      b += value;
      if (b > BLUE_MAX) {
        return false;
      }
    } else {
      cout << "Invalid Token!";
      exit(1);
    }

    if (end == ';') {
      r = g = b = 0;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  string game;
  int game_no = 0;
  int ans = 0;

  while (cin >> game >> game_no) {
    cin >> game;
    getline(cin, game);
    if (is_valid(game)) {
      ans += game_no;
    }
  }
  
  cout << ans << '\n';
  return 0;
}
