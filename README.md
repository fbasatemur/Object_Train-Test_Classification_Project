# Object_Train-Test_Classification_Project

Programmig Language: C++
GUI: CLR

------------------------------------------
## Destination:
 - Bir görüntü üzerinde K-Means algoritmasını kullanarak her bir nesnenin belirlenmesi ve belirlenen her nesnenin feature extraction sonucu nesne tespitidir. 
 
## Techniques:
- Input olarak alinan Bitmap goruntusu uzerinde ilk olarak Train islemlerini yaparak daha sonrasinda ise Test islemi ile moment degerleri hesaplanan nesnenin db.txt uzerinden classification islemi yapilir.
- Classification alg olarak Unsupervised Learning algoritmalarindan olan K-Means algoritmasi kullanildi.
- K-Means, Threashold degerlerine olan distance hesaplanmasinda Euclidean veya Mahalonobis distance opsiyonel olarak kullanilabilir. 
- Gurultu azaltmak icin :
    - Mean Filter
    - Morphology -> Opening ( Erosion/Dilation ) uygulandi.
- Component Connectivity Analysis islemi 8 Neighbors -> Structure Element ile yapildi.
- Future space, 7 seviyeli moment hesaplamasindan olusur.

## Steps:
1.	Raw_intensity image üzerine Mean Filter uygula
2.	Histogram matrisini oluştur ve chart ile göster
3.	Distance seçeneği:
    - 3.1.	Euclidean Dist ya da Mahalonobis Dist seç
    - 3.2.	Seçilen Dist türüne göre KMeans algoritmasını kullan 
4.	KMeans sonucunu ekranda göster
5.	KMeans ile elde edilen threshold değerlerine göre 1/0 Binary dönüşümü yap.
6.	Binary image üzerinde arkaplanı 0, nesneleri 1 olarak işaretle
7.	Morphology adımı:
    - 7.1.	Binary image üzerine Erosion uygula
    - 7.2.	Erosion sonucuna Dilation uygula ve Opening uygulanmıştır.
8.	Morphology sonucunu (Opening işlemi) ekranda göster
9.	Opsiyonel olarak Zero Padding uygula ya da uygulama.
10.	Tüm bu sonuçları içeren matrisi sonra kullanmak üzere kopyala (Deep Copy)
11.	8 Komşuluklu CConnectivityAnalysis aşamasında nesne etiketlendirme işlemi yapılır.
12.	CConnectivityAnalysis sonucunu ekranda göster
13.	Etikenlenmiş görüntü üzerinde Bounding Box işlemini yapılır (drawRectangle)
14.	drawRectangle sonucunu ekranda göster
15.	TRAINING Aşaması:
    - 15.1.	Nesne ismini textBox dan al
    - 15.2.	Box içerisine alımış her nesne için (SaveDataBase içerisinde) Feature Extraction işlemini yap (7 Seviyeli Moment hesabı)
    - 15.3.	DataBase’ e kaydet
16.	TEST Aşaması:
    - 16.1.	Görüntü üzerindeki etiket (object) sayısı kadar renk hesaplaması yap
    - 16.2.	DataBase’ den Train edilmiş Moment değerlerini ve object isimleri al
    - 16.3.	Tespit edilen her nesne için:
        - 16.3.1.	Görüntü üzerinden o nesneyi başka bir matrise kes
        - 16.3.2.	Çıkarılan nesne için Feature extraction işlemi yap
        - 16.3.3.	DataBase üzerindeki sonuçlar ile Matching yap
        - 16.3.4.	En benzer olan nesne ismini, kendi rengi ile richTextBox’ a (tespit edilen nesneler listesine) ekle
