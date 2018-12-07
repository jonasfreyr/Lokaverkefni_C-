# Cliff CLI
### Cliff - Command Line Interface
<img src="Images/cliff_clear.png" width="200">


## Keyrsla

Allur kóði er í main.cpp skránni

### þegar forritið er keyrt gæti það skilað meldingu um "ctime" klasann

> Ef slík melding kemur getur þú commentað show_date fallið út eða skipt því út fyrir kóða hér að neðan.

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
	time_t now = time(0);
	tm* localtm = localtime(&now);
	cout << asctime(localtm);
```
___

## Cliff's commands

What things you need to install the software and how to install them

### OS commands
```
cd - change directory 
lf - List Files 
newfile - creates a new file 
delfile - deletes a file 
clear - clears screen
newtext - creates a new text
deltext - deletes a text
edit - edit a text exit - to exit the program
```
### TEXT commands
```
--moveline X-- Moves the editing line to X
--delline X-- Deletes the line X
--moveend-- Moves to the editing line to the end
--print-- Prints the text you have written
--exit-- To exit the TEXT editor
```
## Höfundar

* **Lárus Arnar Sverrisson** - *Initial work*
* **Jónas Freyr Bjarnason** - *Initial work*
