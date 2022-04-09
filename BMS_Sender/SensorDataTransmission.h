typedef enum
{
	E_NOT_OK,
	E_OK
}DATASTATUS;

extern int GetDatafromInputFile(char * filename, float *Temperature, float *Voltage);
extern int isFileOpenSuccess(FILE *filePointer);
extern int readDataAndSendToConsole(FILE *filePointer, float *Temperature, float *Voltage);
extern int sendDataToConsole( float *Temperature, float *Voltage);
