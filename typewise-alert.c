#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {
  int lowerLimit[COOLING_TYPES] = {0, 0, 0};
  int upperLimit[COOLING_TYPES] = {35, 45, 40};

  return inferBreach(temperatureInC, lowerLimit[coolingType], upperLimit[coolingType]);
}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  switch(alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  char breachTypeTexts[BREACH_TYPES][] = {"", "low", "high"};
  if(breachType != NORMAL) {
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too %s\n", breachTypeTexts[breachType]);
  }
}
