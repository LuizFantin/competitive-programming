#include <iostream>
#include <string>
using namespace std;

int main() {
  long long length, subarrayLength, count = 0, maxCount;
  cin >> length;
  cin >> subarrayLength;

  long long data[length];
  
  for (int i = 0; i < length; i++) {
    cin >> data[i];
  }

  for(int i = 0; i < length-subarrayLength+1; i++){
    if(i == 0){
      for(int j = 0; j < subarrayLength; j++){
        count = count + data[j];
      }
      maxCount = count;
      continue;
    }

    count = count - data[i-1] + data[i+subarrayLength-1];
    
    if (count > maxCount) maxCount = count;

  }

  cout << maxCount;

  return 0;
}
