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

| command        | action        
| ------------- |:-------------:|
| ```cd```      	| change directory 	|
| ```lf```		| List Files      	|
| ```newfile``` 	| creates a new file    |
| ```delfile```      	| deletes a file	|
| ```clear```      	| clears screen      	|
| ```newtext``` 	| creates a new .text document    |
| ```deltext```      	| deletes a .text document 	|
| ```edit```      	| edit a .text document      	|
| ```exit```		| to exit the program   |

### TEXTedit skipanir
| command        | action        
| ------------- |:-------------:|
| ```--moveline X--```| moves the editing line to X    |
| ```--delline X--``` | deletes the line X    |
| ```--moveend--```   | moves to the editing line at the end	|
| ```--print--```     | prints the text you have written     	|
| ```--exit--```      | to exit the TEXT editor    |
## Höfundar

* **Lárus Arnar Sverrisson** - *Initial work*
* **Jónas Freyr Bjarnason** - *Initial work*
