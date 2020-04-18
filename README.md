# Object_Train-Test_Classification_Project

Programmig Language: C++
GUI: CLR
------------------------------------------
- Input olarak alinan Bitmap goruntusu uzerinde ilk olarak Train islemlerini yaparak daha sonrasinda ise Test islemi ile moment degerleri hesaplanan nesnenin db.txt uzerinden classification islemi yapilir.
- Classification alg olarak Unsupervised Learning algoritmalarindan olan K-Means algoritmasi kullanildi.
- K-Means, Threashold degerlerine olan dist hesaplanmasinda Euclidean veya Mahalonobis Dist opsiyonel olarak kullanilabilir. 
- Gurultu azaltmak icin :
    - Mean Filter
    - Morphology -> Opening ( Erosion/Dilation ) uygulandi.
- Component Connectivity Analysis islemi 8 Neighbors -> Structure Element ile yapildi.
- Future space, 7 seviyeli moment hesaplamasindan olusur.

