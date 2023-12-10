#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <cassert>
#include <sstream>

using namespace std;

constexpr int NUM_CATEGORIES = 7;
constexpr int LEN_HAND = 5;

enum Category {
  HIGH_CARD,
  ONE_PAIR,
  TWO_PAIR,
  THREE_OF_A_KIND,
  FULL_HOUSE,
  FOUR_OF_A_KIND,
  FIVE_OF_A_KIND
};

unordered_map<char, int> strength = {
  {'J', 0},
  {'2', 1},
  {'3', 2},
  {'4', 3},
  {'5', 4},
  {'6', 5},
  {'7', 6},
  {'8', 7},
  {'9', 8},
  {'T', 9},
  {'J', 10},
  {'Q', 11},
  {'K', 12},
  {'A', 13},
};

struct hand_comparator {
  bool operator()(const pair<string, long> &a, 
                  const pair<string, long> &b) const {
    auto first_hand = a.first;
    auto second_hand = b.first;
    for (int i = 0; i < LEN_HAND; i++) {
      if (first_hand[i] == second_hand[i]) continue;
      return strength[first_hand[i]] < strength[second_hand[i]];
    }
    return true;
  }
};

static int get_category(string hand) {
  unordered_map<char, int> cnt;
  vector<int> cnt_num(LEN_HAND + 1, 0);

  for (auto card : hand) {
    cnt[card]++;
  }

  auto highest = 'J';
  auto max_num = 0;
  for (auto &[card, num] : cnt) {
    if (card == 'J') continue;
    if (num > max_num) {
      highest = card;
      max_num = num;
    }
  }

  assert(highest != ' ');

  /* In case all five cards are jokers */
  auto num_jokers = cnt['J'];
  cnt[highest] += cnt['J'];
  cnt['J'] -= num_jokers;

  for (auto &[_, num] : cnt) {
    cnt_num[num]++;
  }

  if (cnt_num[LEN_HAND]) return FIVE_OF_A_KIND;
  if (cnt_num[LEN_HAND - 1]) return FOUR_OF_A_KIND;
  if (cnt_num[LEN_HAND - 2]) {
    if (cnt_num[2]) return FULL_HOUSE;
    else return THREE_OF_A_KIND;
  }
  if (cnt_num[LEN_HAND - 3] == 2) {
    return TWO_PAIR;
  }

  if (cnt_num[LEN_HAND - 3] == 1) {
    return ONE_PAIR;
  }

  return HIGH_CARD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input.txt", "r", stdin);

  set<pair<string, long>, hand_comparator> categories[NUM_CATEGORIES];

  string hand;
  long bid;
  while (cin >> hand) {
    cin >> bid;
    categories[get_category(hand)].insert({hand, bid});
  }

  long ans = 0;
  long rank = 1;
  /* categories are ordered from lower to higher rank */
  for (int i = 0; i < NUM_CATEGORIES; i++) {
    for (const auto& [_, bid] : categories[i]) {
      ans += (rank * bid);
      rank++;
    }
  }

  cout << ans << '\n';
  return 0;
}
