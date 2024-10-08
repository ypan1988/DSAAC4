#include <cctype>  // toupper()
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Generic findMax, with a function object, C++ style.
// Precondition: a.size( ) > 0.
template <typename Object, typename Comparator>
const Object &findMax(const vector<Object> &arr, Comparator isLessThan) {
  int maxIndex = 0;

  for (int i = 1; i < arr.size(); ++i)
    if (isLessThan(arr[maxIndex], arr[i])) maxIndex = i;

  return arr[maxIndex];
}

// Generic findMax, using default ordering.
#include <functional>
template <typename Object>
const Object &findMax(const vector<Object> &arr) {
  return findMax(arr, less<Object>{});
}

class CaseInsensitiveCompare {
 public:
  bool operator()(const string &lhs, const string &rhs) const {
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
  cout << findMax(arr) << endl;

  return 0;
}