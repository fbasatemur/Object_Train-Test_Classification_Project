#pragma once
#include <windows.h>
#include <vector>
#include <atlstr.h>	


int* createHistMatris(BYTE*, int, int);

double standardDeviation(int k, int N);

int mahalonobisDist(int k, int x, double standartDevision);

void tagHistMahalonobis(int* tagArray, int T1, int T2);

void tagHistEuclidean(int* tagArray, int T1, int T2);

int* kMeansEuclidean(int* hist, std::vector <int>* vec, int T1 = 0, int T2 = 0);

int* kMeansMahalonobis(int* hist, std::vector <int>* vec, int T1 = 0, int T2 = 0);

int* dilationBinary(int* p, int W, int H, int* M, int K);

int* erosionBinary(int* p, int W, int H, int* M, int K);

BYTE* meanFilter(BYTE*, int&, int&, int*, int);

void backgroundControl(int* binaryImage, int Width, int Height);

void displayBitmap(BYTE* intensityMat, int Width, int Height, int* T2Points, System::Drawing::Bitmap^ bitmap);

void displayBitmap(int* intensityMat, int Width, int Height, System::Drawing::Bitmap^ bitmap);

void calculateTagColors(std::vector <int> tagVector, std::vector <int>& tagColorVector);

void displayCConnectivityAnalysis(int* zeroPadingSurface, int Width, int Height, System::Drawing::Bitmap^ bitmapSurface, std::vector <int> vecTags);

void displayRectangle(int* classificationImage, int Width, int Height, System::Drawing::Bitmap^ bitmapSurface, std::vector <int>& tagVector);

int* intensity2Binary(BYTE* intensity, int Width, int Height, int* T2Points);

int* addZeroPadding(int* cnv, int& Width, int& Height, int structureElementSize);

int vecValueIndex(std::vector <int>& vec, int value);

int vecValueIndexDouble(std::vector <double>& vec, double value);

int vecMinValue(std::vector <int>& vec);

double vecMinValueDouble(std::vector <double>& vec);

int histMinValueIndex(int* arry, int arry_size);

int histMaxValueIndex(int* arry, int arry_size);

bool doubleValueSearch(std::vector <int>& vec, int value1, int value2);

bool valueSearch(std::vector <int>& vec, int value);

int vecClear(std::vector <int>&, std::vector <int>&);

void CConnectivityAnalysis8N(int* binaryImage, int Width, int Height, std::vector <int>&);

void draw(int* classificationImage, int& Width, int& startRow, int& startCol, int& stopRow, int& stopCol);

void drawRectangle(int* classificationImage, int Width, int Height, std::vector <int>& tagVector, std::vector <int>& tagCoordVector);

double calculateMPQ(int* binaryImage, int Width, int Height, int p, int q);

double calculateMPQ(int* binaryImage, int Width, int Height, int p, int q, double medianRow, double medianCol);

double calculateNPQ(int* binaryImage, int Width, int Height, int p, int q);

void  calculateQ(int* binaryImage, int Width, int Height, std::vector <double>& QVector);

int* binaryImageCut(int* binaryImage, int Width, int startCol, int startRow, int stopCol, int stopRow, int& newWidth, int& newHeight);

void deepCopyArray(int* array1, int Width, int Height, int* array2);
