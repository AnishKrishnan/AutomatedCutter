// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PROCESSOR_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PROCESSOR_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PROCESSOR_EXPORTS
#define PROCESSOR_API __declspec(dllexport)
#else
#define PROCESSOR_API __declspec(dllimport)
#endif

// This class is exported from the Processor.dll
class PROCESSOR_API CProcessor {
public:
	CProcessor(void);
	// TODO: add your methods here.
};

extern PROCESSOR_API int nProcessor;

PROCESSOR_API int fnProcessor(void);
