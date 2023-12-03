#include <iostream>
#include <vector>
#include <cctype>
#include <sstream>

using namespace std;

static bool is_valid(int i, int j, int m, int n) {
  return i < m && j < n &&
         i >=0 && j >= 0;
}

static bool is_symbol(char c) {
  return !isdigit(c) && (c != '.');
}

static bool has_symbol(int start, int end, 
                       int row, vector<string> &input) {
  int m = (int) input.size();
  int n = (int) input[0].size();

  if (is_valid(row, start - 1, m, n) && is_symbol(input[row][start-1])) {
    return true;
  }
  if (is_valid(row, end, m, n) && is_symbol(input[row][end])) {
    return true;
  }
  for (int i = start-1; i <= end; i++) {
    if (is_valid(row - 1, i, m, n) && is_symbol(input[row - 1][i])) {
      return true;
    }
    if (is_valid(row + 1, i, m, n) && is_symbol(input[row + 1][i])) {
      return true;
    }
  }

  return false;
}

/* i should be moved to one after the number */
static long get_num(int *i, string &input) {
  string num = "";
  while (*i < ((int) input.size()) && isdigit(input[*i])) {
    num += input[*i];
    (*i)++;
  }
  return stoi(num);
}

static long process(int row, vector<string> &input) {
  long sum = 0;
  for (int i = 0; i < (int) input[0].size(); i++) {
    if (!isdigit(input[row][i])) continue;

    int j = i;
    int num = get_num(&i, input[row]);
    if (has_symbol(j, i, row, input)) {
      sum += num;
    }
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  vector<string> input;
  string line;
  while (cin >> line) {
    input.push_back(line);
  }

  long sum = 0;
  for (unsigned int i = 0; i < input.size(); i++) {
    sum += process(i, input);
  }

  cout << sum << '\n';
  return 0;
}
