#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

static long get_next_value(string &history) {
  istringstream iss(history);
  vector<long> nums;
  long num;
  while (iss >> num) {
    nums.push_back(num);
    cout << num << ' ';
  }
  cout << '\n';
  
  long ans = 0;
  for (unsigned int i = 0; i < nums.size(); i++) {
    bool done = true;
    unsigned int end = nums.size() - (i + 1);
    for (unsigned int j = 0; j < end; j++) {
      nums[j] = nums[j + 1] - nums[j];
      cout << nums[j] << ' ';
      done &= (nums[j] == 0);
    }
    cout << '\n';
    ans += nums[end];
    if (done) break;
  }
  cout << ans << '\n';
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  string history;
  long ans = 0;
  while (getline(cin, history)) {
    ans += get_next_value(history);
  }

  cout << '\n' << "ANS: " << ans << '\n';
  return 0;
}
