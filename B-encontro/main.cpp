#include <iostream>
#include <string>
using namespace std;


int checkIfMeetOccured(long long initialAliceX, long long initialAliceY, long long initialBobX, long long initialBobY, long long stepAliceX, long long stepAliceY, long long stepBobX, long long stepBobY){
  long long time = 0;
  long long currentAliceX = initialAliceX;
  long long currentAliceY = initialAliceY;
  long long currentBobX = initialBobX;
  long long currentBobY = initialBobY;

  while(currentAliceX < currentBobX && currentAliceY < currentBobY){
    if(currentAliceX == currentBobX && currentAliceY == currentBobY){
      return time;
    }

    currentAliceX += stepAliceX;
    currentAliceY += stepAliceY;
    currentBobX -= stepBobX;
    currentBobY -= stepBobY;
    time += 1;
  }

  return -1;
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
