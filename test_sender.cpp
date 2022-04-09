#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "BMS_Sender/SensorDataTransmission.h"
#include <string.h>

TEST_CASE("Check whether data read success"){
  char *filename = "./BMS_Sender/VoltageTemperatureInput.txt";
  int totalReadingsCaptured;
  float Temperature[20] = {0};
  float Voltage[20] = {0};
  totalReadingsCaptured = GetDatafromInputFile(filename,&Temperature[0],&Voltage[0]);
  REQUIRE(GetDatafromInputFile (filename,&Temperature[0],&Voltage[0]) == E_OK);
  }

TEST_CASE("Check whether data read success Invalid file"){
  char *filename = "./BMS_Sender/Invalid.txt";
  int totalReadingsCaptured;
  float Temperature[20] = {0};
  float Voltage[20] = {0};
  totalReadingsCaptured = GetDatafromInputFile(filename,&Temperature[0],&Voltage[0]);
  REQUIRE(GetDatafromInputFile (filename,&Temperature[0],&Voltage[0]) == E_OK);
  }

TEST_CASE("Check whether print to console is success"){
  int totalReadingsCaptured = 0;
  float Temperature[20] = {0};
  float Voltage[20] = {0};
  char *filename = "./BMS_Sender/VoltageTemperatureInput.txt";
  totalReadingsCaptured = GetDatafromInputFile(filename,&Temperature[0],&Voltage[0]);
  REQUIRE(PrintToConsole (&Temperature[0],&Voltage[0]) == E_OK);
  }
