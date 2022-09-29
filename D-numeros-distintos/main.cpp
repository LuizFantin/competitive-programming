#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long length, diffNumbers=0;
  cin >> length;
  long long data[length];

  unordered_map<long long, int> map;
  
  for (int i = 0; i < length; i++) {
    cin >> data[i];
    if(map.find(data[i]) == map.end()){
      map[data[i]] = i;
      diffNumbers++;
    }
  }

  cout << diffNumbers;
  
  return 0;
}
