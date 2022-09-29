#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

char fillRectangle (long long value) {
  long long aux, count = 0;

  for (aux = 2; aux <= sqrt(value); aux++) {
    if(value%aux == 0)
      count++;
  }

  return count == 0 ? 'N' : 'S';
}

int main() {
  long long selos;
  char result;
  cin >> selos;

  if (selos < 4)
    result = 'N';

  else if(selos & 1)
    result = fillRectangle(selos);

  else 
    result = 'S';
  cout << result;
  
  return 0;
}
