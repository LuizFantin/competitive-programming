#include <iostream>
#include <string>
using namespace std;


int checkIfMeetOccured(long long initialAliceX, long long initialAliceY, long long initialBobX, long long initialBobY, long long stepAliceX, long long stepAliceY, long long stepBobX, long long stepBobY){
  long long i = 0;

  while(1){
    if(initialAliceX + stepAliceX*i > initialBobX - stepBobX*i && initialAliceY + stepAliceY*i > initialBobY - stepBobY*i)
      return -1;
    if(initialAliceX + stepAliceX*i == initialBobX - stepBobX*i && initialAliceY + stepAliceY*i == initialBobY - stepBobY*i)
      return i;
    i++;
  }
}

int main() {
  long long initialAliceX = 0, initialAliceY = 0, initialBobX, initialBobY, stepAliceX, stepAliceY, stepBobX, stepBobY, timeOfMeet;
  cin >> initialBobX;
  cin >> initialBobY;
  cin >> stepAliceX;
  cin >> stepAliceY;
  cin >> stepBobX;
  cin >> stepBobY;

  timeOfMeet = checkIfMeetOccured(initialAliceX, initialAliceY, initialBobX, initialBobY, stepAliceX, stepAliceY, stepBobX, stepBobY);

  cout << timeOfMeet;

  
  return 0;
}
