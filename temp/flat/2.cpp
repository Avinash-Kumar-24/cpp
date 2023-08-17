#include<bits/stdc++.h>
using namespace std;

int main() {
  // Read in the string
  string str;
  cin >> str;

  // Check if the string contains only 'a' and 'b' and starts with 'a'
  bool is_valid = true;
  for (char c : str) {
    if (c != 'a' && c != 'b') {
      is_valid = false;
      break;
    }
  }
  if (is_valid && str.front() == 'a') 
  {
    cout << "Accepted" << endl;
  } else 
  {
    cout << "Not accepted" << endl;
  }

  return 0;
}
