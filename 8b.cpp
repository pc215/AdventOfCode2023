#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

#define ll unsigned long long 

constexpr int LEN_NODE_NAME = 3;

static ll gcd(ll a, ll b) {
  if (a == 0) {
    return b;
  }
  return gcd(b % a, a);
}

static ll lcm(ll a, ll b) {
  return (a * b) / gcd(a, b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  string instrs;
  cin >> instrs;

  unordered_map<string, vector<string>> adj;
  unordered_map<string, string> node_pos;
  unordered_map<string, ll> end_nodes;
  string node, eq, left, right;
  while (cin >> node) {
    if (node[LEN_NODE_NAME - 1] == 'A') {
      node_pos[node] = node;
    } else if (node[LEN_NODE_NAME - 1] == 'Z') {
      end_nodes[node] = 0;
    }

    cin >> eq >> left >> right;
    adj[node].push_back(left.substr(1, LEN_NODE_NAME));
    adj[node].push_back(right.substr(0, LEN_NODE_NAME));
  }

  ll instr_pos = 0;
  const auto len = instrs.size();
  ll ans = 1;
  while (!node_pos.empty()) {
    for (auto it = node_pos.begin(); it != node_pos.end(); it++) {
      switch (instrs[instr_pos % len]) {
        case 'L': (*it).second = adj[(*it).second][0]; break;
        case 'R': (*it).second = adj[(*it).second][1]; break;
        default: cout << "GOT " << instrs[instr_pos % len]; exit(1);
      };

      auto end_node = (*it).second;
      if (end_node[LEN_NODE_NAME - 1] == 'Z') {
        auto it1 = end_nodes.find(end_node);
        assert(it1 != end_nodes.end());
        auto val = (*it1).second;

        if (val == 0) {
          cout << "Reached " << (*it).second << " at " << instr_pos << '\n';
          (*it1).second = instr_pos;
        } else {
          cout << "Reached again " << (*it).second << " at " << instr_pos << '\n';
          cout << "DIFF: " << instr_pos - (*it1).second << '\n';
          ll bans = ans;
          cout << "Prev ans " << bans << '\n';
          ans = lcm(ans, instr_pos);
          cout << "New LCM " << ans << '\n';
          cout << "Completed " << (*it).first << '\n';
          end_nodes.erase(it1);
          node_pos.erase(it);
        }
      }
    }
    instr_pos++;
  }

  assert(end_nodes.empty());
  cout << ans << '\n';
  return 0;
}
