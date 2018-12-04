//
//  main.cpp
//  Lokaverkefni_C++_Larus
//
//  Created by Lárus A. on 27/11/2018.
//  Copyright © 2018 Lárus A. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

void showDate() {
    time_t now = time(0);
    // Convert now to tm struct for local timezone
    tm* localtm = localtime(&now);
    cout << asctime(localtm);
}


void displayRow(string listi[10]) {
    for (int i = 0; i<10; i++) {
        cout << listi[i] << "  ";
    }
    cout << "\n";
}

void getCommand(string a, string b) {
    if (a == "ls") {
        //current.list_files();
    }
    else if (a == "cd") {
        // gera eh
    }
    else if (a == "") {
        // idk
    }
    
    else {
        cout << "-bash: " << a + b << ": command not found" << endl;
    }
}

void workCommand(string command) {
    string primary, extra;
    stringstream ss;
    ss << command;
    ss >> primary >> extra;
    getCommand(primary, extra);
    primary = "";
    extra = "";
}


int main() {
    showDate();
    string command = ""; // command stringur fyrir input
    string primary,extra; // primary command er primary, extra er viðbót við það command
    
    string dir[10] = {
        "Mappa1","Mappa2","Mappa3","Mappa4","Mappa5", // demo mappa fyrir display row fallið
        "Mappa6","Mappa7","Mappa8","Mappa9","Mappa10"
    };

    while(command != "exit") {
        cout << "LinuxUser:~$ ";
        getline(cin, command);
        workCommand(command); // fall sem vinnur með inputtið
        //displayRow(dir); // fall sem prentar út directiory, tekur array sem færibreytu
    }
    return 0;
}
