// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the COMMS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// COMMS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef COMMS_EXPORTS
#define COMMS_API __declspec(dllexport)
#else
#define COMMS_API __declspec(dllimport)
#endif

// This class is exported from the Comms.dll
class COMMS_API CComms {
public:
	CComms(void);
	// TODO: add your methods here.
};

extern COMMS_API int nComms;

COMMS_API int fnComms(void);
