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
        ReadDatafromInput(file,Temperature,Voltage);
        return E_OK;
    }
    else{
        return E_NOT_OK;
    }
}

int CheckFileOpenSuccess(FILE *file)
{    
    return ( file == NULL ) ? 0 : 1;
}

int ReadDatafromInput(FILE *filePointer, float *Temperature, float *Voltage)
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
    return E_OK;
}
