#define BMSDATA 20
#define E_OK 1
#define E_NOT_OK 0

extern int GetDatafromInputFile(char * filename, float *Temperature, float *Voltage);
extern int CheckFileOpenSuccess(FILE *filePointer);
extern int ReadDatafromInputText(FILE *filePointer, float *Temperature, float *Voltage);
extern int PrintToConsole( float *Temperature, float *Voltage);
