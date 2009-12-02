// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SQUAREREVERSIENGINE_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SQUAREREVERSIENGINE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SQUAREREVERSIENGINE_EXPORTS
#define SQUAREREVERSIENGINE_API __declspec(dllexport)
#else
#define SQUAREREVERSIENGINE_API __declspec(dllimport)
#endif

SQUAREREVERSIENGINE_API int fnSquareReversiEngine(void);