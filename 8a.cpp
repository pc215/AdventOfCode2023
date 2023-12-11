#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

constexpr int LEN_NODE_NAME = 3;
const string START_NODE = "AAA"; 
const string END_NODE = "ZZZ"; 

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  string instrs;
  cin >> instrs;

  unordered_map<string, vector<string>> adj;
  string node, eq, left, right;
  while (cin >> node) {
    cin >> eq >> left >> right;
    adj[node].push_back(left.substr(1, LEN_NODE_NAME));
    adj[node].push_back(right.substr(0, LEN_NODE_NAME));
  }

  auto cur = START_NODE;
  auto instr_pos = 0;
  const auto len = instrs.size();
  while (cur != END_NODE) {
    switch (instrs[instr_pos % len]) {
      case 'L': cur = adj[cur][0]; break;
      case 'R': cur = adj[cur][1]; break;
      default: cout << "GOT " << instrs[instr_pos % len]; exit(1);
    };
    instr_pos++;
  }

  cout << instr_pos << '\n';
  return 0;
}
