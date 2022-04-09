#include <stdio.h>
#include <string.h>
#include "SensorDataTransmission.h"

float Temperature[BMSDATA] = {};
float Voltage[BMSDATA] = {};

int GetDatafromInputFile(char * filename, float *Temperature, float *Voltage)
{  
    FILE *file ;
    file = fopen(filename, "r");   
    if (CheckFileOpenSuccess(file)){
        ReadDatafromInputText(file,Temperature,Voltage);
        return E_OK;
    }
    else
    {
        return E_NOT_OK;
    }
}

int CheckFileOpenSuccess(FILE *file)
{    
    return ( file == NULL ) ? 0 : 1;
}

int ReadDatafromInputText(FILE *file, float *Temperature, float *Voltage)
{
    float temperatureread = 0;
    float voltageread = 0;
    int i;  
    for(i=0; i<BMSDATA; i++)
    {
      fscanf(file, "%f , %f \n", &temperatureread,&voltageread);
      Temperature[i] = temperatureread;
      Voltage[i] = voltageread;
    }
    fclose(file);    
    return PrintToConsole(Temperature,Voltage);
}

int PrintToConsole( float *Temperature, float *Voltage)
{
    for(int i=0;i<BMSDATA;i++)
    {
        printf("Temperature value is %f and StateOfCharge value is %f\n",Temperature[i],Voltage[i]);
    }
    return E_OK;
}
