#include <vector>
#include <string>

using namespace std;

class MinWindowSubstringSolution {
public:
    string min_window_naive(string s, string t);
    string min_window_two_indexes(string s, string t);
    string min_window_optimized(string s, string t);
    string minWindow(string s, string t);
};
