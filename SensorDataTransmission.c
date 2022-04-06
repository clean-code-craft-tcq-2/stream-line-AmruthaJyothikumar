#include <stdio.h>
#include <math.h>
#include <string.h>
#include "SensorDataTransmission.h"

float converttophysicalvalue(float resolution, int sensorvalue)
{
  float physicalvalue;
  physicalvalue = (sensorvalue*resolution);
  return physicalvalue;
}

void interpretParameterValues(float resolution, int sensorValues[], int* interpretedParameterValues, size_t numberOfSamples)
{	
	int maxIntValue, totalMeasurementRange, roundedOffValue;
	float resolution, scalingFactor, interpretedValue;

	for (size_t i=0; i<numberOfSamples; i++){
		interpretedValue = converttophysicalvalue(resolution, sensorValues[i]);
		ConvertedPhysicalValue[i] = interpretedValue;
	}
}

void GetSensorValues(int tempsensorValues[], float tempresolution, int voltagesensorValues[], float voltresolution)
{
  	int interpretedTempValues[numberOfSamples];
	  int interpretedVoltValues[numberOfSamples];
  
  	interpretParameterValues(tempresolution, tempSensorValues, interpretedTempValues, numberOfSamples);
	  interpretParameterValues(voltresolution, voltageSensorValues, interpretedVoltValues, numberOfSamples);
	  printtoconsoleTemp(interpretedTempValues, interpretedVoltValues,numberOfSamples);
    printtoconsoleVoltage(interpretedTempValues, interpretedVoltValues,numberOfSamples);
}

void printtoconsoleTemp(float Temperature[],numberOfSamples)
{
    for(int i=0;i<numberOfSamples;i++)
    {
        printf("Temperature value is %f\n",Temperature[i]);
    }
}

void printtoconsoleVoltage(float Voltage[],numberOfSamples)
{
    for(int i=0;i<numberOfSamples;i++)
    {
        printf("Temperature value is %f\n",Voltage[i]);
    }
}
