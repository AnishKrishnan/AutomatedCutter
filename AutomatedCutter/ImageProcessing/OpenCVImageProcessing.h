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
#include "IImageInterface.h"
#include "RectangleContainer.h"
#include <climits>
using namespace cv;
class IMAGEPROCESSING_API OpenCVImageProcessing : public IImageInterface
{
public:

	OpenCVImageProcessing();

	virtual void OpenFile(std::string& pFileName);

	virtual void DisplayImage();

	virtual void FindOutlines();

	virtual void DrawOutlines();

	virtual IImageContainer& GetImage();

	virtual RectangleContainer<int>& GetBoundingBox();

	virtual vector<vector<CustomPoint3d<int>>>& GetLines();


private:

	//static void TrackBarCallback(int, void*);

	void ExtractContours();

	void FindBoundingBox();

	void ConvertContoursToLines();
	
	Mat _image;
	Mat _grayImage;
	Mat _cannyOutput;
	Mat _contourImage;

	vector<vector<Point>> _contours;
	vector<Vec4i> _hierarchy;

	vector<vector<CustomPoint3d<int>>> _lines;

	static const int RECTANGLE_CORNERS = 4;

	
	RectangleContainer<int> _boundingRectangle;
	const char* _imageWindowName;
	const char* _cannyWindowName;

	//canny variables
	int _lowerThresh, _upperThresh, _maxThresh, _apetureSize;

	double _blendImageAlpha, _blendImageGamma;

	bool _showCanny;
};