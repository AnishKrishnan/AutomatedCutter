// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the IMAGEPROCESSING_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// IMAGEPROCESSING_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#pragma once
#ifdef IMAGEPROCESSING_EXPORTS
#define IMAGEPROCESSING_API __declspec(dllexport)
#else
#define IMAGEPROCESSING_API __declspec(dllimport)
#endif
#include <opencv2/core/core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include "IImageContainer.h"
class IMAGEPROCESSING_API OpenCVImage :	public IImageContainer
{
public:
	OpenCVImage(cv::Mat& pImage);
	~OpenCVImage(void);

	virtual int GetWidth();

	virtual int GetHeight();

	virtual int* GetData();

	virtual int GetStep();

private:
	cv::Mat& _image;
};

