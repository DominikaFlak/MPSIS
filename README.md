# MPSIS


# Kompilacja programu:
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
