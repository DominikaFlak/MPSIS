# MPSIS

```
Panel optymalizacyjny stworzony przez nas sluzy do optymalizacji kosztu budowy autostrady na
zadanym terenie (aby nastepnie poprowadzic wzdluz tej drogi swiatlowody). Zakladamy ze teren 
jest znany (znamy wiec tez koszty poszczegolnych dzialek, pokrycie radiowe na nich). Zadaniem
uzytkownika jest jedynie zawezenie terenu na ktorym chce on zbudowac autostrade, okreslenie
wymaganego przez niego pokrycia radiowego, oraz sprecyzowanie na ile maksymalnie odcinkow drogi
moze sobie pozwolic.
```
## Kompilacja programu:
```
g++ main.cpp -o main.cgi -lcgicc

```

## Konfiguracja Apache:
```   
   <Directory /var/www/>    
	Options Indexes FollowSymLinks ExecCGI   
	AllowOverride None    
	Require all granted   
        AddHandler cgi-script .out .cgi .exe   
   </Directory>     
```

## Aktywacja modulow:
```  
  a2enmod cgid
  
```
## Uprawnienia:
```
Program korzysta z plikow tekstowych w ktorych zapisany jest model, a takze tworzy robocze pliki tekstowe
dlatego nalezy pamietac o nadaniu odpowiednich uprawnien do odczytu, zapisu i modyfikacji folderowi, w
ktorym umieszczony zostanie program.
```
