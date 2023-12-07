# UDP-Nodemcu
Crypto Communicate using UDP protocol between computer and nodemcu


Merhabalar, basit bir proje istedi bi arkadasim, hem ona yardim hem de kafa dagitmak icin gelistirdigim bir proje, yazma aliskanligi olsun diye bunu paylasiyorum.

Kisaca projeyi analatacak olursak, masaustu bir yazilimla kontrol edilebilen ve robot uzerindeki sensorlerden elde edilen veriyi masaustu yazilimda gostermeyi amaclamaktadir. Projedeki asil espiri veri transferi yapilirken bir sifreleme yapma ve gecikmeyi en aza indirmek. Burada haberlesme icin UDP protokolu kullanildi gecikmeyi aza indirmek icin, ancak bu protokol guvenli degil. Guvenli degil den kasit, verinin istenen yere ulasip ulasmadigini kontrol eden bir mekanizma yok, bu sebepten kritik yapilarda kullanilmasi pek tavsiye edilmez. Uygulamanin masaustu kisminin gorselligi ve for uygulamasinin yazilimi pek onemli olmadigi icin oralar pek profesyonel degil, yani fazla vakit harcamaya degmezdi. Neyse bu kadar gunah cikardigimiz yeter, baslayalim.

Azicik detay asagidaki linkte 
https://medium.com/@cantek41/nodemcu-udp-kriptolu-iletisim-28acba31660d
