# ZADANIA Z SYSTEMÓW OPERACYJNYCH - TELEINFORMATYKA ZUT 2021/2022

## ZAD1 (lab1) - HELLO SO
### Napisać program w języku C wypisujący w konsoli tekst "Hello SO" wraz ze znakiem nowej linii, a następnie kończący pracę.

## ZAD2 (lab1) – DOSTĘP/WYSZUKIWANIE PID PROCESU
### Napisać program w języku C wypisujący w konsoli swój PID (process identifier), a następnie blokujący zamknięcie programu (np. poprzez pętlę nieskończoną, lub oczekiwanie na wprowadzenie znaku z klawiatury). Odnaleźć proces z poziomu konsoli na różne sposoby (poprzez PIDoraz nazwę procesu). Do wyszukiwania procesu można użyć poleceń takich jak: ps, top, etc.

## ZAD3 (lab2) – PRZECHWYTYWANIE I OBSŁUGA SYGNAŁU#1
### Napisać program w języku C który:
#### •rejestruje obsługę dla sygnału SIGINT
#### •wchodzi w nieskończoną pętlę
#### •podczas nadejścia sygnału SIGINT, wypisuje w konsoli (w nowej linii) numer albumu studenta, a następnie kończy program.
### Wykonać program, a następnie zakończyć poprzez naciśnięcie Ctrl+C.

## ZAD4 (lab2) – PRZECHWYTYWANIE I OBSŁUGA SYGNAŁU#2
### Napisać program w języku C który:
#### •rejestruje obsługę dla sygnału SIGTERM
#### •wypisuje w konsoli swój PID
#### •wchodzi w nieskończoną pętlę
#### •podczas nadejścia sygnału SIGTERM, wypisuje w konsoli (w nowej linii) numer albumu studenta, a następnie kończy program.
### Wykonać program w jednej konsoli, a w drugiej za pomocą polecenia kill wysłać sygnał SIGTERM do naszego procesu.

## ZAD5 (lab3) – WYSYŁANIE SYGNAŁU Z JEDNEGO PROCESU DO DRUGIEGO
### 1. Napisać w języku C, skompilować i uruchomić aplikację, która:
#### •rejestruje obsługę dla sygnału SIGTERM. Obsługa będzie miała za zadanie w przypadku nadejścia sygnału wypisać w konsoli numer albumu studenta i zamknąć program
#### •wyświetla swój PID w konsoli
#### •wchodzi w nieskończoną i uśpioną pętlę

### 2. Napisać w języku C, skompilować i uruchomić aplikację, która:
#### •pobiera PID procesu z punktu 1 -może być poprzez argument przekazany z linii poleceń lub wpisany z konsoli po starcie
#### •używa programowej funkcji kill aby wysłać sygnał SIGTERM do drugiego procesu (zdefiniowanego w punkcie pierwszym)

#### Wykonać program pierwszy, a następnie drugi, który zakończy pierwszy.

## ZAD6 (lab3) – PRZEŁĄCZANIE FLAGI PRZEZ NADCHODZĄCY SYGNAŁ
### Napisać program w języku C który:
#### •rejestruje obsługę dla sygnału SIGUSR1. Obsługa będzie miała za zadanie ustawiać flagę (i tylko tyle)
#### •wyświetla swój PID w konsoli
#### •wchodzi w nieskończoną i uśpioną pętlę, która będzie dodatkowo w każdej iteracji sprawdzać,czy flaga jest ustawiona i jeżeli tak, to wypisywać w konsoli numer albumu, a następnie czyścić flagę i przejść do kolejnej iteracji.

#### Za pomocą polecenia kill z konsoli wysłać sygnał SIGUSR1 do naszej aplikacji. Każde wysłanie tego sygnału powinno spowodować wypisanie w konsoli nowej linii z numerem albumu. Po paru próbach można zamknąć aplikację za pomocą Ctrl+C

## ZAD7 (lab4) – OBSŁUGA SYGNAŁU ALARM
### Napisać w języku C, skompilować i uruchomić program, który:
#### •rejestruje obsługę dla sygnału alarmu. Obsługa będzie miała za zadanie w przypadku nadejścia sygnału wypisać w konsoli numer albumu studenta.
#### •ustawia alarm na wywołanie za X sekund (wartość dowolna, ale lepiej nie za duża, żeby za długo nie czekać)
#### •wchodzi w nieskończoną i uśpioną pętlę

## ZAD8 (lab4) – STRUMIENIE
### 1. Napisać w języku C, skompilować i uruchomić aplikację, która:
#### •przekierowuje standardowe wyjście do pliku (zapis)
#### •wchodzi w nieskończoną i uśpioną pętlę, która będzie dodatkowo w każdej iteracji wysyłać do standardowego wyjścia linie tekstu zakończone znakiem nowej linii. W linii zawarty ma być numer iteracji oraz numer albumu

### 2. Napisać w języku C, skompilować i uruchomić aplikację, która:
#### •przekierowuje standardowe wejście z pliku (odczyt)
#### •wchodzi w nieskończoną i uśpioną pętlę, która będzie dodatkowo w każdej iteracji czekać,aż pojawi się nowa linia tekstu na standardowym wejściu i ją wyświetlać (fgets) -proszę nie używać scanf bo się do tego nie nadaje.

## ZAD9 (lab5) –POTOKI: JEDNOKIERUNKOWE FIFO
### 1. Napisać w języku C program pełniący rolę serwera,który:
#### •tworzy jednokierunkowe FIFO (mknod), nazwane numerem albumu
#### •otwiera utworzone FIFO do odczytu
#### •w nieskończonej pętli czeka na wiadomości od klienta
#### •po nadejściu wiadomości:
##### •wyświetla treść wiadomości, gdy wiadomość nie jest numerem albumu
##### •gdy wiadomość równa jest numerowi albumu, zamyka FIFO i kończy program

### 2. Napisać w języku C program pełniący rolę klienta,który:
#### •otwiera FIFO tylko do zapisu
#### •w nieskończonej pętli czeka na input od użytkownika
#### •wysyła wiadomość do serwera poprzez otwarte FIFO
#### •dodatkowo, jeżeli wiadomością był numer albumu, to zamyka FIFO i kończy działanie programu.