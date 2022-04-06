void interpretTemperatureAndVoltageValuesFromSensors(parameterInfo tempInfo, parameterInfo voltInfo, int tempSensorValues[],
	int VoltageSensorValues[], char* tempAndVoltValuesInCSV[], size_t numberOfSamples);

float converttophysicalvalue(float resolution, int sensorvalue);
void printtoconsoleTemp(float Temperature[], size_t numberOfSamples);
void printtoconsoleVoltage((float Temperature[], size_t numberOfSamples);
void interpretParameterValues(float resolution, int sensorValues[], int* interpretedParameterValues, size_t numberOfSamples);
void GetSensorValues((int tempsensorValues[], float tempresolution, int voltagesensorValues[], float voltresolution);
                     
