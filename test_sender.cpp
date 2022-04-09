#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "SensorDataTransmission.h"
#include <string.h>

TEST_CASE("Read Sensor 1 Data"){
  int totalReadingsCaptured = 0;
  float Temperature[50]={0};
  float ChargeRate[50]={0};
  char *filename = "./VoltageTemperatureInput.txt";
  totalReadingsCaptured = GetDatafromInputFile(filename,&Temperature[0],&Voltage[0]);
  REQUIRE (totalReadingsCaptured == 50);
  }
