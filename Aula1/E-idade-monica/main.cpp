#include <iostream>
#include <string>
using namespace std;

int main() {
  long long firstChildAge, secondChildAge, monicaAge, thirdChildAge, maxAge;
  cin >> monicaAge;
  cin >> firstChildAge;
  cin >> secondChildAge;

  thirdChildAge = monicaAge - firstChildAge - secondChildAge;

  if(firstChildAge > secondChildAge && firstChildAge > thirdChildAge)
    maxAge = firstChildAge;
  else if(secondChildAge > thirdChildAge && secondChildAge > firstChildAge)
    maxAge = secondChildAge;
  else
    maxAge = thirdChildAge;

  cout << maxAge;

  
  return 0;
}
