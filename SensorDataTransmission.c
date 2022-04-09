#include <stdio.h>
#include <math.h>
#include <string.h>
#include "SensorDataTransmission.h"

#define BMSDATA 20
float Temperature[BMSDATA] = {};
float StateOfCharge[BMSDATA] = {};

int GetDatafromInputFile(char * filename, float *Temperature, float *Voltage)
{  
    FILE *filePointer ;
    filePointer = fopen(filename, "r");    
    return isFileOpenSuccess(filePointer) ? readDataAndSendToConsole(filePointer,Temperature,Voltage) : 0;
}

int isFileOpenSuccess(FILE *filePointer)
{    
    return ( filePointer == NULL ) ? 0 : 1;
}

int readDataAndSendToConsole(FILE *filePointer, float *Temperature, float *Voltage)
{
    float Temp_data = 0,Voltage_data = 0;
    int i;  
    for(i=0; i<BMSDATA; i++)
    {
      fscanf(filePointer, "%f , %f \n", &Temp_data,&Voltage_data);
      Temperature[i] = Temp_data;
      Voltage[i] = Voltage_data;
    }
    fclose(filePointer);    
    return sendDataToConsole(Temperature,Voltage);
}

int sendDataToConsole( float *Temperature, float *Voltage)
{
    for(int i=0;i<BMSDATA;i++)
    {
        printf("Temperature value is %f and StateOfCharge value is %f\n",Temperature[i],Voltage[i]);
    }
}

