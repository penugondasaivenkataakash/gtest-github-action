#include <iostream>
#include "TestChallenge.h"


int alertFailureCount = 0;

int realTimenetworkAlerter(float celcius) {
   //Real Network Interaction Happens Here
    // Return 200 for ok
    // Return 500 for not-ok
  if(celcius % 2==0){
    return 200;
  }
  return 500;
}

void alertInCelcius(float farenheit,int(*networkAlerter)(float celcius)) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlerter(celcius);
    if (returnCode != 200) {
      alertFailureCount += 0;
    }
}Test
