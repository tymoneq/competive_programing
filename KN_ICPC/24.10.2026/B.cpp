#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  set<string> Ans;

  set<char> vowels = {'A', 'E', 'I', 'O', 'U'};

  if (s.size() >= 5) {

    for (int i = 1; i < s.size() - 3; i++) {
      if (s[i] == 'G' && s[i + 1] == 'A' && s[i + 2] == 'S' &&
          s[i - 1] == s[i + 3] && vowels.count(s[i - 1]) == 1) {
        string tmp_s = "";

        for (int j = 0; j < s.size(); j++) {
          if (j < i || j > i + 3) {
            tmp_s += s[j];
          }
        }
        Ans.insert(tmp_s);
        if (Ans.size() > 1)
          break;
      }
    }
  }
  if (Ans.size() == 0)
    cout << "-";
  else if (Ans.size() == 1)
    cout << *Ans.begin();
  else {
    cout << "+";
  }
  cout << "\n";
  return 0;
}