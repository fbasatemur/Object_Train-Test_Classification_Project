# Unsupervised Learning Classification

Programmig Language: C++/CLR

## Destination:
Determination of each object using the K-Means algorithm on an image and the result of the feature extraction of each determined object is the object detection. 
First, an entrance image is taken and **Trained**. After that, "db.txt" is used for the **Test** process and the classification process is done.
 
## Techniques:
- K-Means algorithm was used for Unsupervised Learning Classification.
- Euclidean or Mahalanobis distance calculation methods can be used for the K-means algorithm.
- For noise reduction :
    - Mean Filter
    - Morphology -> Opening ( Erosion/Dilation )
- Component Connectivity Analysis process is done with 8 Neighbors (Structure Element).
- Feature extraction, 7-level moment is calculated.

## Steps:
1.	Apply Mean Filter to input image
2.	KMeans algorithm apply
3.	The background of the result image is set to 0; make foreground 1 (It's now binary image)
4.	Morphology steps:
    - 4.1.	Apply Erosion on Binary image
    - 4.2.	Apply Dilation and Opening process completed.
5.	Object labeling is done with the Component Connectivity Analysis process.
6.	Bounding boxes are apply to labelled images (drawRectangle)
7.	TRAINING Steps:
    - 7.1.	Get object name from ** TextBox **
    - 7.2.	Perform Feature Extraction for each object enclosed in Bounding boxes. (7-level moment)
    - 7.3.	Save in "db.txt"
8.	TEST Steps:
    - 8.2.	Get moment values and object names in "db.txt"
    - 8.3.	For each detected object:
        - 8.3.1.	Apply Feature extraction process
        - 8.3.2.	Match the values in "db.txt"
        - 8.3.3.	Add the most similar objects to "RichTextBox" with their own color
  
# Sample Screenshots
Sample 1 is lentil test

   ![alt text](https://github.com/fbasatemur/Object_Train-Test_Classification_Project/blob/add-license-1/screenshots/lentil_test.jpg "Lentil Test")
  
Sample 2 is lentil train 

   ![alt text](https://github.com/fbasatemur/Object_Train-Test_Classification_Project/blob/add-license-1/screenshots/lentil_train.jpg "Lentil Train")
  
Sample 3 is many objects detection with Euclidean Distance

   ![alt text](https://github.com/fbasatemur/Object_Train-Test_Classification_Project/blob/add-license-1/screenshots/many_objects_test_euclidean.jpg "Many objects detection with Euclidean Distance")
  
Sample 4 is many objects detection with Mahalonobis Distance

   ![alt text](https://github.com/fbasatemur/Object_Train-Test_Classification_Project/blob/add-license-1/screenshots/many_objects_test_mahalonobis.jpg "Many objects detection with Mahalonobis Distance")
