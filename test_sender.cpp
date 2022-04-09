#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BMS_Sender/SensorDataTransmission.h"
#include <string.h>

TEST_CASE("Read Sensor 1 Data"){
  int totalReadingsCaptured = 0;
  float Temperature[20]={0};
  float Voltage[20]={0};
  char *filename = "./BMS_Sender/VoltageTemperatureInput.txt";
  totalReadingsCaptured = GetDatafromInputFile(filename,&Temperature[0],&Voltage[0]);
  REQUIRE (totalReadingsCaptured == 50);
  }
