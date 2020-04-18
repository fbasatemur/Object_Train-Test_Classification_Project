
#include "image_Processing.h"
#include <math.h>
#include <ctime>

#define MIN(a,b) ((a < b) ? a : b)
#define MAX(a,b) ((a > b) ? a : b)

int* createHistMatris(BYTE* rawIndensity, int width, int height)
{
	int* hist = new int[256];

	for (int i = 0; i < 256; i++) {
		hist[i] = 0;
	}

	for (int i = 0; i < width * height; i++)
		hist[rawIndensity[i]]++;

	return hist;
}

double standardDeviation(int k, int N)
{
	long total = 0;
	for (int i = 0; i < N; i++)
	{
		total += pow((i - k), 2);
	}

	return sqrt(total / (N - 1));
}

int mahalonobisDist(int k, int x, double standartDevision)
{
	return int(sqrt(pow((double(x - k) / standartDevision), 2)));
}

void tagHistMahalonobis(int* tagArray, int T1, int T2)
{
	double T1StandardD = standardDeviation(T1, 256);
	double T2StandardD = standardDeviation(T2, 256);

	for (int i = 0; i < 256; i++)
	{
		if (mahalonobisDist(T1, i, T1StandardD) < mahalonobisDist(T2, i, T2StandardD))
			tagArray[i] = 0;		// T1 tag value -> 0
		else
			tagArray[i] = 255;		// T2 tag value -> 255
	}
}

void tagHistEuclidean(int* tagArray, int T1, int T2)
{
	for (int i = 0; i < 256; i++)
	{
		if (System::Math::Abs(T1 - i) < System::Math::Abs(T2 - i))
			tagArray[i] = 0;		// T1 tag value -> 0
		else
			tagArray[i] = 255;		// T2 tag value -> 255
	}
}

int* kMeansEuclidean(int* hist, std::vector <int>* vec, int T1, int T2)
{
	if (T1 == 0 && T2 == 0)
	{
		srand(time(NULL));
													// hist matrisinde ki degerlere sahip aralikta tahmin yapsin, boylece threshold degerlerinin 0 a kaymasi engellenir
		T1 = rand() % (histMaxValueIndex(hist, 256) - histMinValueIndex(hist, 256) + 1 ) + histMinValueIndex(hist, 256);							// 0 -> tag value
		T2 = rand() % (histMaxValueIndex(hist, 256) - histMinValueIndex(hist, 256) + 1 ) + histMinValueIndex(hist, 256);							// 255 -> tag value											
	}

	vec->push_back(T1);
	vec->push_back(T2);

	int* tagArray = new int[256];

	while (true)
	{

		tagHistEuclidean(tagArray, T1, T2);

		double meanT1 = 0.0;
		double meanT2 = 0.0;

		long totalMeanT1Upper = 0;		
		long totalMeanT1Down = 0;		
		
		long totalMeanT2Upper = 0;
		long totalMeanT2Down = 0;


		for (int i = 0; i < 256; i++)
		{
			if (tagArray[i] == 0)
			{
				totalMeanT1Upper += i * hist[i];
				totalMeanT1Down += hist[i];
			}
			else {
				totalMeanT2Upper += i * hist[i];
				totalMeanT2Down += hist[i];
			}
		}

		if (totalMeanT1Down == 0) totalMeanT1Down = 1;
		if (totalMeanT2Down == 0) totalMeanT2Down = 1;

		meanT1 = totalMeanT1Upper / totalMeanT1Down;
		meanT2 = totalMeanT2Upper / totalMeanT2Down;

		if ((int)meanT1 == T1 && (int)meanT2 == T2)
		{
			int* TArray = new int[2];

			vec->push_back(T1);
			vec->push_back(T2);
			TArray[0] = T1;
			TArray[1] = T2;
			return TArray;
		}
		else {
			T1 = (int)meanT1;
			T2 = (int)meanT2;

			vec->push_back(T1);
			vec->push_back(T2);
		}
	}
}

int* kMeansMahalonobis(int* hist, std::vector <int>* vec, int T1, int T2)
{
	if (T1 == 0 && T2 == 0)
	{
		srand(time(NULL));
		// hist matrisinde ki degerlere sahip aralikta tahmin yapsin, boylece threshold degerlerinin 0 a kaymasi engellenir
		T1 = rand() % (histMaxValueIndex(hist, 256) - histMinValueIndex(hist, 256) + 1) + histMinValueIndex(hist, 256);						// 0 -> tag value
		T2 = rand() % (histMaxValueIndex(hist, 256) - histMinValueIndex(hist, 256) + 1) + histMinValueIndex(hist, 256);						// 255 -> tag value											
	}

	vec->push_back(T1);
	vec->push_back(T2);

	int* tagArray = new int[256];

	while (true)
	{

		tagHistMahalonobis(tagArray, T1, T2);

		double meanT1 = 0.0;
		double meanT2 = 0.0;

		long totalMeanT1Upper = 0;
		long totalMeanT1Down = 0;

		long totalMeanT2Upper = 0;
		long totalMeanT2Down = 0;

		for (int i = 0; i < 256; i++)
		{
			if (tagArray[i] == 0)
			{
				totalMeanT1Upper += i * hist[i];
				totalMeanT1Down += hist[i];
			}
			else {
				totalMeanT2Upper += i * hist[i];
				totalMeanT2Down += hist[i];
			}
		}

		if (totalMeanT1Down == 0) totalMeanT1Down = 1;
		if (totalMeanT2Down == 0) totalMeanT2Down = 1;

		meanT1 = totalMeanT1Upper / totalMeanT1Down;
		meanT2 = totalMeanT2Upper / totalMeanT2Down;

		if ((int)meanT1 == T1 && (int)meanT2 == T2)
		{
			int* TArray = new int[2];

			vec->push_back(T1);
			vec->push_back(T2);
			TArray[0] = T1;
			TArray[1] = T2;
			return TArray;
		}
		else {
			T1 = (int)meanT1;
			T2 = (int)meanT2;

			vec->push_back(T1);
			vec->push_back(T2);
		}
	}
}

int* dilationBinary(int* binaryImage, int Width, int Height, int* StructureElement, int StructureElementSize)
{
	int* cnv = new int[Height * Width];

	for (int i = 0; i < Height * Width; i++)
	{
		cnv[i] = 0;
	}

	int locationSet = (StructureElementSize - 1) / 2;

	for (int row = locationSet; row < Height - locationSet; row++)
	{
		for (int col = locationSet; col < Width - locationSet; col++)
		{
			if (binaryImage[row * Width + col] == 1) {

				for (int i = 0; i < StructureElementSize; i++)
				{
					for (int j = 0; j < StructureElementSize; j++)
					{
						cnv[(row - locationSet + i) * Width + col - locationSet + j] = binaryImage[(row - locationSet + i) * Width + col - locationSet + j] || StructureElement[i * StructureElementSize + j];

					}
				}
			}

		}
	}
	return cnv;
}

int* erosionBinary(int* binaryImage, int Width, int Height, int* StructureElement, int StructureElementSize)
{
	int* cnv = new int[Height * Width];

	for (int i = 0; i < Height * Width; i++)
	{
		cnv[i] = 0;
	}

	int locationSet = (StructureElementSize - 1) / 2;

	int counter = 0;
	for (int row = locationSet; row < Height - locationSet; row++)
	{
		for (int col = locationSet; col < Width - locationSet; col++)
		{
			if (binaryImage[row * Width + col] == 1) {

				for (int i = 0; i < StructureElementSize; i++)
				{
					for (int j = 0; j < StructureElementSize; j++)
					{

						if (StructureElement[i * StructureElementSize + j] == (StructureElement[i * StructureElementSize + j] && binaryImage[(row - locationSet + i) * Width + col - locationSet + j]))
						{
							counter++;
						}
					}
				}

				if (counter == StructureElementSize * StructureElementSize)
				{
					cnv[(row * Width) + col] = 1;
				}
				counter = 0;
			}
		}
	}
	return cnv;
}

BYTE* meanFilter(BYTE* colorImage, int& Width, int& Height, int* StructureElement, int StructureElementSize)
{
	int locationSet = (StructureElementSize - 1) / 2;

	int cWidth = (Width - (locationSet * 2));
	int cHeight = (Height - (locationSet * 2));

	BYTE* cnv = new BYTE[cWidth * cHeight];

	for (long i = 0; i < cHeight * cWidth; i++)
	{
		cnv[i] = 0;
	}

	long temp = 0;
	for (int row = locationSet; row < Height - locationSet; row++)
	{
		for (int col = locationSet; col < Width - locationSet; col++)
		{
			for (int i = 0; i < StructureElementSize; i++)
			{
				for (int j = 0; j < StructureElementSize; j++)
				{
					temp += (colorImage[(row - locationSet + i) * Width + col - locationSet + j] * StructureElement[i * StructureElementSize + j]);
				}
			}
			cnv[(row - locationSet) * cWidth + col - locationSet] = (int)(temp / (StructureElementSize * StructureElementSize));
			temp = 0;

		}
	}

	Width = cWidth;
	Height = cHeight;

	return cnv;
}

void backgroundControl(int* binaryImage, int Width, int Height)
{
	long counterZero = 0;
	long counterOne = 0;

	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{
			(binaryImage[row * Width + col] == 0) ? counterZero++ : counterOne++;		// zemin olarak en fazla bulunan binary value say
		}
	}

	// Background degeri 0 ise zeminden ayrilan elemanlar 1'dir.
	// Background degeri 1 ise zeminden ayrilan elemanlar 0'dir. Tam tersine bacground -> 0 , nesne -> 1 yap
	if (counterZero < counterOne)
	{
		for (int i = 0; i < Width * Height; i++)										
		{
			binaryImage[i] = (binaryImage[i] == 0) ? 1 : 0;
		}
	}
}

void displayBitmap(BYTE* intensityMat, int Width, int Height, int* T2Points, System::Drawing::Bitmap^ bitmap)
{
	System::Drawing::Color color;
	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{

			if (System::Math::Abs(T2Points[0] - intensityMat[row * Width + col]) < System::Math::Abs(T2Points[1] - intensityMat[row * Width + col]))
				color = System::Drawing::Color::FromArgb(0, 0, 0);
			else
				color = System::Drawing::Color::FromArgb(255, 255, 255);

			// setpixel ise col row ve color bilgilerini ilgili bitmap matrise atar 
			bitmap->SetPixel(col, row, color);
		}
	}
}

void displayBitmap(int* intensityMat, int Width, int Height, System::Drawing::Bitmap^ bitmap)
{
	System::Drawing::Color color;
	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{

			if (intensityMat[row * Width + col] == 1)
				color = System::Drawing::Color::FromArgb(0, 0, 0);
			else
				color = System::Drawing::Color::FromArgb(255, 255, 255);

			// setpixel ise col row ve color bilgilerini ilgili bitmap matrise atar 
			bitmap->SetPixel(col, row, color);
		}
	}
}

void calculateTagColors(std::vector <int> tagVector, std::vector <int>& tagColorVector)
{
	int retVecSize = tagVector.size();
	retVecSize = retVecSize == 0 ? 1 : retVecSize;
	int colorK = 255 / retVecSize;

	for (int i = 0; i < retVecSize; i++)
	{
		tagColorVector.push_back(i * colorK);
	}
}

void displayCConnectivityAnalysis(int* zeroPadingSurface, int Width, int Height, System::Drawing::Bitmap^ bitmapSurface, std::vector <int> tagVector)
{
	std::vector <int> tagColorVector;
	calculateTagColors(tagVector, tagColorVector);

	System::Drawing::Color color;

	int colorValue = 0;
	int previousValue = 0;
	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{

			if (zeroPadingSurface[row * Width + col] == 0)
				color = System::Drawing::Color::FromArgb(255, 255, 255);

			else if (valueSearch(tagVector, zeroPadingSurface[row * Width + col]))
			{
				colorValue = tagColorVector[vecValueIndex(tagVector, zeroPadingSurface[row * Width + col])] % 255;
				color = System::Drawing::Color::FromArgb(colorValue, (colorValue * colorValue) % 255, (colorValue * colorValue * colorValue) % 255);
				/*color = System::Drawing::Color::FromArgb((colorValue * zeroPadingSurface[row * Width + col]) % 255, (colorValue * colorValue) % 255, (colorValue * colorValue * colorValue) % 255);*/

			}

			// setpixel ise col row ve color bilgilerini ilgili bitmap matrise atar 
			bitmapSurface->SetPixel(col, row, color);
		}
	}
}

void displayRectangle(int* classificationImage, int Width, int Height, System::Drawing::Bitmap^ bitmapSurface, std::vector <int>& tagVector)
{
	std::vector <int> tagColorVector;
	calculateTagColors(tagVector, tagColorVector);

	System::Drawing::Color color;

	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{

			if (classificationImage[row * Width + col] == 0)
				color = System::Drawing::Color::FromArgb(255, 255, 255);

			else if (classificationImage[row * Width + col] == 1)
				color = System::Drawing::Color::FromArgb(0, 255, 0);

			else if (valueSearch(tagVector, classificationImage[row * Width + col]))
			{
				int colorValue = tagColorVector[vecValueIndex(tagVector, classificationImage[row * Width + col])] % 255;
				color = System::Drawing::Color::FromArgb(colorValue, (colorValue * colorValue) % 255, (colorValue * colorValue * colorValue) % 255);
				/*color = System::Drawing::Color::FromArgb((colorValue * classificationImage[row * Width + col]) % 255, (colorValue * colorValue) % 255, (colorValue * colorValue * colorValue) % 255);*/
			}

			// setpixel ise col row ve color bilgilerini ilgili bitmap matrise atar 
			bitmapSurface->SetPixel(col, row, color);
		}
	}
}

int* intensity2Binary(BYTE* intensity, int Width, int Height, int* T2Points)
{
	int* bImage = new int[Height * Width];

	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{
			if (System::Math::Abs(T2Points[0] - intensity[row * Width + col]) < System::Math::Abs(T2Points[1] - intensity[row * Width + col]))
				bImage[row * Width + col] = 1;
			else
				bImage[row * Width + col] = 0;
		}
	}
	return bImage;
}

int* addZeroPading(int* cnv, int& Width, int& Height, int structureElementSize)
{
	int fillSize = (structureElementSize - 1) / 2;
	int cnvZeroWidth = (Width + (fillSize * 2));

	int cnvZeroHeight = (Height + (fillSize * 2));

	int* cnvZeroPading = new int[cnvZeroWidth * cnvZeroHeight];

	for (int row = 0; row < cnvZeroHeight; row++)
	{
		for (int col = 0; col < cnvZeroWidth; col++)
		{
			if (col < fillSize || col >= (cnvZeroWidth - fillSize) || row < fillSize || row >= (cnvZeroHeight - fillSize))
				cnvZeroPading[row * cnvZeroWidth + col] = 0;
			else
				cnvZeroPading[row * cnvZeroWidth + col] = cnv[(row - fillSize) * Width + (col - fillSize)];
		}
	}

	Width = cnvZeroWidth;
	Height = cnvZeroHeight;

	return cnvZeroPading;
}

int vecValueIndex(std::vector <int>& vec, int value)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int vecValueIndexDouble(std::vector <double>& vec, double value)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == value)
		{
			return i;
		}
	}
	return -1;
}

int vecMinValue(std::vector <int>& vec)
{
	int min = vec[0];
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] < min)
		{
			min = vec[i];
		}
	}

	return min;
}

double vecMinValueDouble(std::vector <double>& vec)
{
	double min = vec[0];
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] < min)
		{
			min = vec[i];
		}
	}

	return min;
}

int histMinValueIndex(int* arry, int arry_size)
{
	for (int index = 0; index < arry_size; index++)
	{
		if (arry[index] > 0)
		{
			return index;
		}
	}
}

int histMaxValueIndex(int* arry, int arry_size)
{
	for (int index = arry_size - 1; index >= 0; index--)
	{
		if (arry[index] > 0)
		{
			return index;
		}
	}
}

bool doubleValueSearch(std::vector <int>& vec, int value1, int value2)
{
	for (int index = 0; index < vec.size(); index += 2)
	{
		if (vec[index] == value1 && vec[index + 1] == value2)
			return true;
	}
	return false;
}

bool valueSearch(std::vector <int>& vec, int value)
{
	for (int index = 0; index < vec.size(); index++)
	{
		if (vec[index] == value)
			return true;
	}
	return false;
}

int vecClear(std::vector <int>& collisionTags, std::vector <int>& temp)
{
	for (int i = 0; i < collisionTags.size(); i += 2)
	{
		if (i == 0)
		{
			temp.push_back(collisionTags[i]);
			temp.push_back(collisionTags[i + 1]);
		}
		else
		{
			if (!valueSearch(temp, collisionTags[i]) && valueSearch(temp, collisionTags[i + 1]))
			{
				temp.push_back(collisionTags[i]);
				int tempSize = 0;
				do
				{
					tempSize = temp.size();

					for (int j = 0; j < i; j += 2)
					{
						if (!valueSearch(temp, collisionTags[j]) && valueSearch(temp, collisionTags[j + 1]))
							temp.push_back(collisionTags[j]);

						else if (valueSearch(temp, collisionTags[j]) && !valueSearch(temp, collisionTags[j + 1]))
							temp.push_back(collisionTags[j + 1]);

					}

				} while (temp.size() != tempSize);

			}
			else if (valueSearch(temp, collisionTags[i]) && !valueSearch(temp, collisionTags[i + 1]))
			{
				temp.push_back(collisionTags[i + 1]);
				int tempSize = 0;
				do
				{
					tempSize = temp.size();

					for (int j = 0; j < i; j += 2)
					{
						if (!valueSearch(temp, collisionTags[j]) && valueSearch(temp, collisionTags[j + 1]))
							temp.push_back(collisionTags[j]);

						else if (valueSearch(temp, collisionTags[j]) && !valueSearch(temp, collisionTags[j + 1]))
							temp.push_back(collisionTags[j + 1]);

					}

				} while (temp.size() != tempSize);

			}
		}
	}
	for (int i = 0; i < temp.size(); i++)
	{
		while (valueSearch(collisionTags, temp[i]))
		{
			collisionTags.erase(collisionTags.begin() + vecValueIndex(collisionTags, temp[i]));
		}
	}

	return vecMinValue(temp);
}

void CConnectivityAnalysis8N(int* binaryImage, int Width, int Height, std::vector <int>& tagCounterVec)
{
	int StructureElementSize = 3;
	int locationSet = (StructureElementSize - 1) / 2;

	int tagCounter = 1;
	int counter = 0;
	std::vector <int> tagVector;

	std::vector <int> collisionTags;


	for (int row = locationSet; row < Height - locationSet; row++)
	{
		for (int col = locationSet; col < Width - locationSet; col++)
		{
			if (binaryImage[row * Width + col] == 1)
			{
				for (int i = 0; i < StructureElementSize; i++)
				{
					for (int j = 0; j < StructureElementSize; j++)
					{
						if (binaryImage[(row - locationSet + i) * Width + col - locationSet + j] != 0 && binaryImage[(row - locationSet + i) * Width + col - locationSet + j] != 1)
						{
							if (!valueSearch(tagVector, binaryImage[(row - locationSet + i) * Width + col - locationSet + j]))
							{
								counter++;
								tagVector.push_back(binaryImage[(row - locationSet + i) * Width + col - locationSet + j]);
								if (counter == 2)
									break;
							}
						}
					}
					if (counter == 2)
						break;
				}

				switch (counter)
				{
				case 0:
					tagCounter++;
					tagCounterVec.push_back(tagCounter);
					binaryImage[row * Width + col] = tagCounter;
					break;

				case 1:
					binaryImage[row * Width + col] = tagVector[0];
					break;

				case 2:
					binaryImage[row * Width + col] = tagVector[1];

					if (!doubleValueSearch(collisionTags, tagVector[0], tagVector[1]) && !doubleValueSearch(collisionTags, tagVector[1], tagVector[0]))
					{
						collisionTags.push_back(tagVector[0]);
						collisionTags.push_back(tagVector[1]);
					}
					break;

				default:
					break;
				}
				tagVector.clear();
				counter = 0;
			}
		}
	}

	std::vector <int> temp;

	while (collisionTags.size() > 0)
	{
		int minValue = vecClear(collisionTags, temp);

		temp.erase(temp.begin() + vecValueIndex(temp, minValue));

		for (int i = 0; i < temp.size(); i++)
		{
			if (valueSearch(tagCounterVec, temp[i]))
			{
				tagCounterVec.erase(tagCounterVec.begin() + vecValueIndex(tagCounterVec, temp[i]));
			}
			for (int row = locationSet; row < Height - locationSet; row++)
			{
				for (int col = locationSet; col < Width - locationSet; col++)
				{
					if (binaryImage[row * Width + col] == temp[i])
					{
						binaryImage[row * Width + col] = minValue;
					}
				}
			}
		}
		temp.clear();
	}
}

void draw(int* classificationImage, int& Width, int& startRow, int& startCol, int& stopRow, int& stopCol)
{
	for (int row = startRow; row <= stopRow; row++)
	{
		for (int col = startCol; col <= stopCol; col++)
		{
			classificationImage[row * Width + col] = 1;
		}
	}
}

void drawRectangle(int* classificationImage, int Width, int Height, std::vector <int>& tagVector, std::vector <int>& tagCoordVec)
{
	for (int i = 0; i < tagVector.size(); i++)
	{
		int minRow = Height;
		int minCol = Width;
		int maxRow = 0;
		int maxCol = 0;
		for (int row = 0; row < Height; row++)
		{
			for (int col = 0; col < Width; col++)
			{
				if (tagVector[i] == classificationImage[row * Width + col])
				{
					minRow = MIN(minRow, row);
					minCol = MIN(minCol, col);
					maxRow = MAX(maxRow, row);
					maxCol = MAX(maxCol, col);
				}
			}
		}
		draw(classificationImage, Width, minRow, minCol, minRow, maxCol);
		draw(classificationImage, Width, maxRow, minCol, maxRow, maxCol);
		draw(classificationImage, Width, minRow, minCol, maxRow, minCol);
		draw(classificationImage, Width, minRow, maxCol, maxRow, maxCol);
		tagCoordVec.push_back(minCol);	// minX
		tagCoordVec.push_back(minRow);	// minY
		tagCoordVec.push_back(maxCol);	// maxX
		tagCoordVec.push_back(maxRow);	// maxY

	}
}

double calculateMPQ(int* binaryImage, int Width, int Height, int p, int q)
{
	double temp = 0;
	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{
			temp += System::Math::Pow(row, p) * System::Math::Pow(col, q) * binaryImage[row * Width + col];
		}
	}
	return temp;
}

double calculateMPQ(int* binaryImage, int Width, int Height, int p, int q, double medianRow, double medianCol)
{
	double temp = 0;
	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{
			temp += System::Math::Pow((row - medianRow), p) * System::Math::Pow((col - medianCol), q) * binaryImage[row * Width + col];
		}
	}
	return temp;
}

double calculateNPQ(int* binaryImage, int Width, int Height, int p, int q)
{
	double y = ((p + q) / 2) + 1;

	double medianRow = calculateMPQ(binaryImage, Width, Height, 1, 0) / calculateMPQ(binaryImage, Width, Height, 0, 0);
	double medianCol = calculateMPQ(binaryImage, Width, Height, 0, 1) / calculateMPQ(binaryImage, Width, Height, 0, 0);

	return calculateMPQ(binaryImage, Width, Height, p, q, medianRow, medianCol) / System::Math::Pow(calculateMPQ(binaryImage, Width, Height, 0, 0, medianRow, medianCol), y);
}

void calculateQ(int* binaryImage, int Width, int Height, std::vector<double>& QVector)
{
	QVector.push_back(calculateNPQ(binaryImage, Width, Height, 2, 0) + calculateNPQ(binaryImage, Width, Height, 0, 2));

	QVector.push_back(System::Math::Pow((calculateNPQ(binaryImage, Width, Height, 2, 0) - calculateNPQ(binaryImage, Width, Height, 0, 2)), 2) + 4 * System::Math::Pow(calculateNPQ(binaryImage, Width, Height, 1, 1), 2));

	QVector.push_back(System::Math::Pow((calculateNPQ(binaryImage, Width, Height, 3, 0) - 3 * calculateNPQ(binaryImage, Width, Height, 1, 2)), 2) + System::Math::Pow((3 * calculateNPQ(binaryImage, Width, Height, 2, 1) - calculateNPQ(binaryImage, Width, Height, 0, 3)), 2));

	QVector.push_back(System::Math::Pow((calculateNPQ(binaryImage, Width, Height, 3, 0) + calculateNPQ(binaryImage, Width, Height, 1, 2)), 2) + System::Math::Pow((calculateNPQ(binaryImage, Width, Height, 2, 1) + calculateNPQ(binaryImage, Width, Height, 0, 3)), 2));

	QVector.push_back((calculateNPQ(binaryImage, Width, Height, 3, 0) - 3 * calculateNPQ(binaryImage, Width, Height, 1, 2)) * (calculateNPQ(binaryImage, Width, Height, 3, 0) + calculateNPQ(binaryImage, Width, Height, 1, 2)) * ((System::Math::Pow(calculateNPQ(binaryImage, Width, Height, 3, 0) + calculateNPQ(binaryImage, Width, Height, 1, 2), 2)) - 3 * (System::Math::Pow(calculateNPQ(binaryImage, Width, Height, 2, 1) + calculateNPQ(binaryImage, Width, Height, 0, 3), 2))) + (3 * calculateNPQ(binaryImage, Width, Height, 2, 1) - calculateNPQ(binaryImage, Width, Height, 0, 3)) * (calculateNPQ(binaryImage, Width, Height, 2, 1) + calculateNPQ(binaryImage, Width, Height, 0, 3)) * (3 * (System::Math::Pow((calculateNPQ(binaryImage, Width, Height, 3, 0) + calculateNPQ(binaryImage, Width, Height, 1, 2)), 2)) - (System::Math::Pow((calculateNPQ(binaryImage, Width, Height, 2, 1) + calculateNPQ(binaryImage, Width, Height, 0, 3)), 2))));

	QVector.push_back((calculateNPQ(binaryImage, Width, Height, 2, 0) - calculateNPQ(binaryImage, Width, Height, 0, 2)) * (System::Math::Pow(calculateNPQ(binaryImage, Width, Height, 3, 0) + calculateNPQ(binaryImage, Width, Height, 1, 2), 2) - (System::Math::Pow(calculateNPQ(binaryImage, Width, Height, 2, 1) + calculateNPQ(binaryImage, Width, Height, 0, 3), 2))) + 4 * calculateNPQ(binaryImage, Width, Height, 1, 1) * (calculateNPQ(binaryImage, Width, Height, 3, 0) + calculateNPQ(binaryImage, Width, Height, 1, 2)) * (calculateNPQ(binaryImage, Width, Height, 2, 1) + calculateNPQ(binaryImage, Width, Height, 0, 3)));

	QVector.push_back((3 * calculateNPQ(binaryImage, Width, Height, 2, 1) - calculateNPQ(binaryImage, Width, Height, 0, 3)) * (calculateNPQ(binaryImage, Width, Height, 3, 0) + calculateNPQ(binaryImage, Width, Height, 1, 2)) * ((System::Math::Pow(calculateNPQ(binaryImage, Width, Height, 3, 0) + calculateNPQ(binaryImage, Width, Height, 1, 2), 2)) - 3 * (System::Math::Pow(calculateNPQ(binaryImage, Width, Height, 2, 1) + calculateNPQ(binaryImage, Width, Height, 0, 3), 2))) - (calculateNPQ(binaryImage, Width, Height, 3, 0) - 3 * calculateNPQ(binaryImage, Width, Height, 1, 2)) * (calculateNPQ(binaryImage, Width, Height, 2, 1) + calculateNPQ(binaryImage, Width, Height, 0, 3)) * (3 * (System::Math::Pow((calculateNPQ(binaryImage, Width, Height, 3, 0) + calculateNPQ(binaryImage, Width, Height, 1, 2)), 2)) - (System::Math::Pow((calculateNPQ(binaryImage, Width, Height, 2, 1) + calculateNPQ(binaryImage, Width, Height, 0, 3)), 2))));

}

int* binaryImageCut(int* binaryImage, int Width, int startCol, int startRow, int stopCol, int stopRow, int& newWidth, int& newHeight)
{
	newWidth = System::Math::Abs(stopCol - startCol + 1);
	newHeight = System::Math::Abs(stopRow - startRow + 1);
	int* cutImage = new int[newWidth * newHeight];

	for (int row = startRow; row <= stopRow; row++)
	{
		for (int col = startCol; col <= stopCol; col++)
		{
			cutImage[(row - startRow) * newWidth + (col - startCol)] = binaryImage[row * Width + col];
		}
	}

	return cutImage;
}

void deepCopyArray(int* array1, int Width, int Height, int* array2)
{
	for (int row = 0; row < Height; row++)
	{
		for (int col = 0; col < Width; col++)
		{
			array2[row * Width + col] = array1[row * Width + col];
		}
	}
}

