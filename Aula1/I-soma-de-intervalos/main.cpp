#include <iostream>
#include <string>
using namespace std;

int main() {
  long long length, numberOfQueries;
  cin >> length;
  cin >> numberOfQueries;

  long long data[length], queries[numberOfQueries*2], sum[length+1];
  sum[0] = 0;
  
  for (int i = 0; i < length; i++) {
    cin >> data[i];
  }

  for(int j = 0; j < numberOfQueries*2; j+=2) {
    cin >> queries[j];
    cin >> queries[j + 1]; 
  }

  for(int k = 1; k < length+1; k++) {
    sum[k] = sum[k-1] + data[k-1];
  }

  for(int j = 0; j < numberOfQueries*2; j+=2) {
    cout << sum[queries[j+1]+1] - sum[queries[j]] << "\n";
  }
  
  return 0;
}
