#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <sstream>
#include <ctime>

using namespace std;
void clear();

class Text{
    public:
        string name;
        vector <string> next;
        Text(string filename){
            name = filename;
        }
        
        string get_name(){
            return name;
        }
        
        void editor(){
            clear();
            cout << "------------Text Editor------------" << endl;
            int in = 0;
            for(int i = 0; i < next.size(); i++){
                cout << in << ". " << next[i] << endl;
                in++;
            }
            cout << endl;
            stringstream stream;
            string line = "";
            string primary,extra;
            while(line != "--exit--"){
                getline(cin, line);
                
                
                
                
                
                if(line != "--exit--"){
                   cout << in << ". " << line << "\n";
                   cout << "\n";
                   
                   next.push_back(line);
                   
                   in++;
                   
                }
                
                
            }
        }
};

class File{
    public:
        string name;
        File* parent;
        bool deletable;
        vector <Text*> texts;
        vector <File*> next;
        
        File(string text, File* inputParent, bool del) {
            name = text;
            parent = inputParent;
            deletable = del;
        }
        
        void new_file(string name, bool del){
            if(!does_exist(name, true)){
                File *a = new File(name, this, del);
                next.push_back(a);
            }
            else{
                cout << "File already exists" << endl;
            }
        }
        
        void add_text(Text* t){
            texts.push_back(t);
        }
        
        File* get_parent(){
            return parent;
        }
        
        string get_name(){
            return name;
        }
        
        File* get_file(string name){
            for(int i = 0; i < next.size(); i++){
                if(next[i]->get_name() == name){
                       return next[i]; 
                }
            }
            return this;
        }
        
        Text* get_text(string name){
            if(does_exist(name, false)){
                for(int i = 0; i < texts.size(); i++){
                    if(texts[i]->get_name() == name){
                           return texts[i]; 
                    }
                }
            }
        }
        
        bool does_exist(string name, bool file){
            if(file){
                for(int i = 0; i < next.size(); i++){
                    if(next[i]->get_name() == name){
                           return true; 
                    }
                }
                
                false;
            }
            else{
                for(int i = 0; i < texts.size(); i++){
                    if(texts[i]->get_name() == name){
                           return true; 
                    }
                }
                
                false;
            }
        }
        
        int get_index(string name, bool file){
            if(file){
                for(int i = 0; i < next.size(); i++){
                    if(next[i]->get_name() == name){
                           return i; 
                    }
                }
            }
            else{
                for(int i = 0; i < texts.size(); i++){
                    if(texts[i]->get_name() == name){
                           return i; 
                    }
                }
            }
        }
        
        void del_file(string name){
            
            if(does_exist(name, true)){
                int f = get_index(name, true);
            
                next.erase(next.begin()+f); 
            }
            else{
                cout << "File does not exist." << endl;
            }
        }
        
        void del_text(string name){
            if(does_exist(name, false)){
                int f = get_index(name, false);
                
                texts.erase(texts.begin()+f); 
            }
            else{
                cout << "Text does not exist." << endl;
            }
            
        }
        
        void print_files(){
            cout << "----Files----" << endl;
            for(int i = 0; i < next.size(); i++){
                cout << next[i]->get_name() << endl;
            }
            cout << "----Text----" << endl;
            
            for(int i = 0; i < texts.size(); i++){
                cout << texts[i]->get_name() << ".text" << endl;
            }
            
        }

};
File *current;



void show_date() {
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

void clear(){
    for(int i = 0; i<20; i++){
        cout<<"\n";
    }
}

void getCommand(string a, string b) {
    if (a == "ls") {
        current->print_files();
    }
    else if (a == "cd") {
        if(b != ".."){
           current = current->get_file(b); 
        }
        
        else{
            current = current->parent; 
        }
        
    }
    else if (a == "newfile") {
        current->new_file(b, true);
    }
    
    else if (a == "delfile"){
        current->del_file(b);
    }
    
    else if (a == "clear"){
        clear();
    }
    
    else if (a == "newtext"){
        if(!current->does_exist(b, false)){
            Text* t = new Text(b);
            t->editor();
            current->add_text(t);
        }
        else{
            cout << "Text already exists" << endl;
        }
    }
    
    else if(a == "deltext"){
        current->del_text(b);
    }
    
    else if (a == "edit"){
        if(current->does_exist(b, false)){
            Text* t = current->get_text(b);
            t->editor();
        }
        else{
             cout << "Text does not exists" << endl;
        }
    }
    
    else if (a == "exit"){
        
    }
    
    else {
        cout << "-bash: " << a + b << ": command not found" << endl;
    }
}

void workCommand(string command, bool root) {
    string primary, extra;
    stringstream ss;
    ss << command;
    ss >> primary >> extra;
    if(root){
        getCommand(primary, extra);
    }

    primary = "";
    extra = "";
}


string place(){
    File* curr = current;
    string s;
    while (curr){
        s =curr->get_name() + "/" +s;
        
        curr = curr->parent;
    }
    
    return s;
}





int main(){
    show_date();
    current = new File("root", NULL, false);
    current->new_file("Documents", false);
    current->new_file("Downloads", false);
    current->new_file("Pictures", false);
    
    string command = ""; // command stringur fyrir input
    string primary,extra; // primary command er primary, extra er viðbót við það command
    
    //cout << current->next << endl;
    
    while(command != "exit") {
            cout << place() << ": ";
            getline(cin, command);
            workCommand(command, true); // fall sem vinnur með inputtið
            //displayRow(dir); // fall sem prentar út directiory, tekur array sem færibreytu
        }
    
    return 0;
}