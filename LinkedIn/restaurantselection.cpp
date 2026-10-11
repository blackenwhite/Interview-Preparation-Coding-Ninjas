#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <set>

using namespace std;

// Instant runoff / ranked choice.
//
// Contract the tests below assume:
// - Count each ballot's current first remaining restaurant.
// - Winner needs strictly more than half of ALL ballots: votes > n / 2.
// - Otherwise eliminate every restaurant with the minimum first-choice count
//   (including 0). Repeat.
// - A ballot with no remaining restaurant is exhausted and votes for nobody.
// - If only one restaurant remains, it wins even without a majority.
// - If every remaining restaurant has the same count, there is no unique
//   winner: return "".
// - Empty restaurants or empty ballots: return "".

string electRestaurant(const vector<string>& restaurants, const vector<vector<string>>& ballots) {
    int n = ballots.size();
    vector<queue<string>> vectorQ(n);
    for(int i=0;i<n;i++) {
        for(string s: ballots[i]) {
            vectorQ[i].push(s);
        }
    }

    unordered_set<string> excluded;

    while(true){
        set<pair<int, string>> st;
        map<string,int> freq;
        for(int i=0;i<n;i++) {
            queue<string>& q = vectorQ[i];
            while(!q.empty() && excluded.count(q.front())) {
                q.pop();
            }
            if(q.empty()) {
                continue;
            }
            auto it = q.front();
            freq[it]++;
        }
        for(string r:restaurants) {
            if(!excluded.count(r)) {
                st.insert({freq[r], r});
            }
        }

        if(st.size()==0) {
            return "";
        }

        // check even split

        // get the highest wala and check
        auto &[maxCount, mx] = (*st.rbegin());
        // cout<<maxCount<<" = maxCount, and mx = "<<mx<<"\n";
        

        // else remove the lowest votes wala
        auto &[minCount, mn] = *st.begin();
        if(st.size()>1 && maxCount == minCount) {
            return "";
        }

        if(maxCount>n/2) {
            return mx;
        }

        excluded.insert(mn);
        // cout<<"Minn = "<<mn<<"\n";
        if(excluded.size()==restaurants.size()) {
            return ""; // no winner
        }
    }
    return "";
}

namespace {

int g_passed = 0;
int g_failed = 0;

void check(const string& name, const vector<string>& restaurants,
           const vector<vector<string>>& ballots, const string& expected) {
    const string got = electRestaurant(restaurants, ballots);
    if (got == expected) {
        ++g_passed;
        cout << "PASS  " << name << "\n";
    } else {
        ++g_failed;
        cout << "FAIL  " << name << "\n"
             << "      expected: \"" << expected << "\"\n"
             << "      got:      \"" << got << "\"\n";
    }
}

}  // namespace

int main() {
    // 1) Hello Interview sample: C is last, transfers to A, A gets 3/5.
    check("sample_hello_interview", {"A", "B", "C"},
          {
              {"A", "B", "C"},
              {"A", "B", "C"},
              {"B", "C", "A"},
              {"B", "A", "C"},
              {"C", "A", "B"},
          },
          "A");

    // 2) Already a majority on first-choice votes. No elimination.
    check("immediate_majority", {"A", "B", "C"},
          {
              {"A", "B", "C"},
              {"A", "C", "B"},
              {"A", "B", "C"},
          },
          "A");

    // 3) Single ballot: 1 > 0, first preference wins.
    check("single_ballot", {"A", "B", "C"}, {{"B", "A", "C"}}, "B");

    // 4) Only one restaurant exists.
    check("single_restaurant", {"Pizza"}, {{"Pizza"}, {"Pizza"}, {"Pizza"}}, "Pizza");

    // 5) D has 0 first-choice votes, but A already has 3/5.
    //    Check majority before eliminating; A should win in round 1.
    check("majority_before_eliminating_zero", {"A", "B", "C", "D"},
          {
              {"A", "B", "C", "D"},
              {"A", "B", "C", "D"},
              {"A", "C", "B", "D"},
              {"B", "A", "C", "D"},
              {"C", "A", "B", "D"},
          },
          "A");

    // 6) Classic IRV transfer: A leads round 1 but does not have a majority.
    //    C is eliminated, C's ballots move to B, B wins 5/9.
    check("leader_loses_after_transfer", {"A", "B", "C"},
          {
              {"A", "B", "C"},
              {"A", "B", "C"},
              {"A", "B", "C"},
              {"A", "B", "C"},
              {"B", "C", "A"},
              {"B", "C", "A"},
              {"B", "C", "A"},
              {"C", "B", "A"},
              {"C", "B", "A"},
          },
          "B");

    // 7) Two rounds with a unique loser each time.
    //    Round 1: A2 B2 C1 D0 -> drop D.
    //    Round 2: A2 B2 C1    -> drop C.
    //    Round 3: A2 B3       -> B has 3/5.
    check("multiple_rounds", {"A", "B", "C", "D"},
          {
              {"A", "B", "C", "D"},
              {"A", "B", "C", "D"},
              {"B", "A", "C", "D"},
              {"B", "C", "A", "D"},
              {"C", "B", "A", "D"},
          },
          "B");

    // 8) Last-place tie: B and C both have 1. Eliminate both.
    //    A is the only restaurant left, so A wins even though 2 is not > 2.
    check("eliminate_all_last_place_ties", {"A", "B", "C"},
          {
              {"A", "B", "C"},
              {"A", "C", "B"},
              {"B", "A", "C"},
              {"C", "A", "B"},
          },
          "A");

    // 9) 50/50 is not a majority (2 is not > 2). Remaining restaurants tied.
    check("even_split_no_majority", {"A", "B"},
          {
              {"A", "B"},
              {"A", "B"},
              {"B", "A"},
              {"B", "A"},
          },
          "");

    // 10) Full first-round tie among every restaurant.
    check("complete_three_way_tie", {"A", "B", "C"},
          {
              {"A", "B", "C"},
              {"B", "C", "A"},
              {"C", "A", "B"},
          },
          "");

    // 11) C is eliminated; that ballot lists only C, so it becomes exhausted.
    //     Remaining A vs B is 2-2. No unique winner.
    check("exhausted_ballot_then_tie", {"A", "B", "C"},
          {
              {"A", "B"},
              {"A", "B"},
              {"B", "A"},
              {"B", "A"},
              {"C"},
          },
          "");

    // 12) Incomplete rankings. After C is dropped, C's next choice B
    //     gives B 3/5.
    check("incomplete_rankings", {"A", "B", "C"},
          {
              {"A"},
              {"A"},
              {"B", "C"},
              {"B"},
              {"C", "B"},
          },
          "B");

    // 13) n = 2: need 2 votes. First round A1 B1 is a tie.
    check("two_ballots_split", {"A", "B"}, {{"A", "B"}, {"B", "A"}}, "");

    // 14) n = 1 edge already covered; empty inputs.
    check("empty_restaurants", {}, {{"A"}}, "");
    check("empty_ballots", {"A", "B"}, {}, "");

    // 15) Winner is nobody's unique first choice in a later sense:
    //     A is eliminated (1 vote), then C's second choices elect B 3/5.
    check("eliminate_then_majority", {"A", "B", "C"},
          {
              {"A", "B", "C"},
              {"B", "A", "C"},
              {"B", "C", "A"},
              {"C", "B", "A"},
              {"C", "B", "A"},
          },
          "B");

    cout << "\n" << g_passed << " passed, " << g_failed << " failed\n";
    return g_failed == 0 ? 0 : 1;
}
