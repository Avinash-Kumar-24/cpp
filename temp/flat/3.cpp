#include<bits/stdc++.h>
using namespace std;

int main() {
  // Read in the string
  string str;
  cin >> str;

  bool is_valid = true;
  for(char c : str)
  {
    if(c != 'a' && c != 'b')
    {
        is_valid = false;
        break;
    }
  }
  // Count the number of 'a's in the string
  int count = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'a') {
      count++;
    }
  }

  // Check if the string satisfies the condition
  if (is_valid && count >= 2) {
    cout << "accepted" << endl;
  } else {
    cout << "not accepted" << endl;
  }

  return 0;
}
