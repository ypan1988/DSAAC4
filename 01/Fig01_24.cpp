#include <cctype>  // toupper()
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Generic findMax, with a function object, Version #1.
// Precondition: a.size( ) > 0.
template <typename Object, typename Comparator>
const Object &findMax(const vector<Object> &arr, Comparator cmp) {
  int maxIndex = 0;

  for (int i = 1; i < arr.size(); ++i)
    if (cmp.isLessThan(arr[maxIndex], arr[i])) maxIndex = i;

  return arr[maxIndex];
}

class CaseInsensitiveCompare {
 public:
  bool isLessThan(const string &lhs, const string &rhs) const {
    return strcmp(toUpper(lhs).c_str(), toUpper(rhs).c_str()) < 0;
  }
  string toUpper(const string &str) const {
    string res = str;
    for (auto &c : res) {
      c = toupper(c);
    }
    return res;
  }
};

int main() {
  vector<string> arr = {"ZEBRA", "alligator", "crocodile"};
  cout << findMax(arr, CaseInsensitiveCompare{}) << endl;

  return 0;
}