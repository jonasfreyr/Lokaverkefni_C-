# Cliff CLI
### Cliff - Command Line Interface
<img src="Images/Cliff_logo.png" width="250">


## Keyrsla

Allur kóði er í  [main.cpp](https://github.com/jonasfreyr/Lokaverkefni_C-/blob/master/main.cpp) skránni

### þegar forritið er keyrt gæti það skilað meldingu um "ctime" klasann

> Ef slík melding kemur getur þú commentað `show_date()` fallið út eða skipt því út fyrir kóða hér að neðan.

Fyrir visual studio
```cpp
void show_date() {
	time_t rawtime;
	time(&rawtime);
	struct tm timeinfo;
	localtime_s(&timeinfo, &rawtime);
	char str[26];
	asctime_s(str, sizeof str, &timeinfo);
	cout << str;
}
```
Fyrir Linux
```cpp
void show_date() {
	time_t now = time(0);
	tm* localtm = localtime(&now);
	cout << asctime(localtm);
}
```
___

## Cliff skipanir

### OS skipanir

| skipun        | skýring        
| ------------- |:-------------:|
|	cd      | change directory 	|
| ```lf```		| List Files      	|
| ```newfile``` 	| creates a new file    |
| ```delfile```      	| deletes a file	|
| ```clear```      	| clears screen      	|
| ```newtext``` 	| creates a new text    |
| ```deltext```      	| deletes a text 	|
| ```edit```      	| edit a text      	|
| ```exit```		| to exit the program   |

### TEXTedit skipanir
| skipun        | skýring        
| ------------- |:-------------:|
| ```--moveline X--```| Moves the editing line to X    |
| ```--delline X--``` | Deletes the line X    |
| ```--moveend--```   | Moves to the editing line to the end	|
| ```--print--```     | Prints the text you have written     	|
| ```--exit--```      | To exit the TEXT editor    |
## Höfundar

* **Lárus Arnar Sverrisson** - *Initial work*
* **Jónas Freyr Bjarnason** - *Initial work*
