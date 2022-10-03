#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  long long count = 1;
  long long maxCount = 1;
  char currentChar;
  cin >> input;

  currentChar = input[0];
  for(int i = 0; i < input.length(); i++){
    if( i != 0 && currentChar == input[i]){
        count ++;
        if(i < input.length() - 1){
            continue;
        }
    }
    if(count > maxCount){
        maxCount = count;
    }
    currentChar = input[i];
    count = 1;
  }
  cout << maxCount;
  return 0;
}