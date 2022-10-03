#include <iostream>
#include <string>
using namespace std;

int main() {
  long long length, sumLength=0, sumMissingNumber=0;
  cin >> length;
  long long data[length-1];
  
  for (int i = 0; i < length-1; i++) {
    cin >> data[i];
    sumMissingNumber += data[i];
  }

  sumLength = (length*(1 + length))/2;
  

  cout << sumLength - sumMissingNumber;
  
  return 0;
}
