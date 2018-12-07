#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <sstream>
#include <ctime>
#include <regex>

using namespace std;
void clear();
bool does_exist();

class Text {
public:
	string name;
	vector<string> next;
	Text(string filename) { name = filename; }
	bool deleteable;

	string get_name() { return name; }

	int get_length() { return int(name.length()); }

	void editor() {
		clear();
		cout << string(14, ' ') << "TEXTeditor" << endl;
		cout << string(11, ' ') << "version 8.0.1283" << endl;

		int in = 0;
		for (int i = 0; i < next.size(); i++) {
			cout << in << ". " << next[i] << endl;
			in++;
		}
		cout << endl;
		string line = "";
		bool command;
		int inser = in;
		while (true) {
			cout << in << "~";
			command = false;
			getline(cin, line);
			string com, num;
			stringstream ss;
			ss << line;
			ss >> com >> num;

			//cout << com << "----" << num << endl;

			if (com == "--moveline"){
				command = true;
				int numb = stoi(num);
				inser = numb;
				in = numb;
			}

			cout << "\n";
			if (line == "--exit--") {
				break;
			}
			if (command == false){
				next.insert(next.begin() + inser, line);
				inser++;
				in++;
			}
		}
	}
};

class File {
public:
	string name;
	File* parent;
	vector<Text*> texts;
	vector<File*> next;
	bool deletable;

	File(string text, File* inputParent, bool del) {
		name = text;
		parent = inputParent;
		deletable = del;
		//cout << del << endl;
	}

	void new_file(string name, bool del) {
		if (!does_exist(name, true)) {
			File* a = new File(name, this, del);
			next.push_back(a);
		}
		else {
			cout << "File " << "'" << name << "'" << " already exists" << endl;
		}
	}

	int get_length() { return int(name.length()); }

	void add_text(Text* t) { texts.push_back(t); }

	File* get_parent() { return parent; }

	string get_name() { return name; }

	File* get_file(string name, File* curr) {
		if (does_exist(name, true)) {
			for (int i = 0; i < next.size(); i++) {
				if (next[i]->get_name() == name) {
					return next[i];
				}
			}
		}
		return curr;
	}

	Text* get_text(string name) {
		if (does_exist(name, false)) {
			for (int i = 0; i < texts.size(); i++) {
				if (texts[i]->get_name() == name) {
					return texts[i];
				}
			}
		}
		return nullptr;
	}

	bool does_exist(string name, bool file) {
		if (file) {
			for (int i = 0; i < next.size(); i++) {
				if (next[i]->get_name() == name) {
					return true;
				}
			}
			return false;
		}
		else {
			for (int i = 0; i < texts.size(); i++) {
				if (texts[i]->get_name() == name) {
					return true;
				}
			}

			return false;
		}
	}

	int get_index(string name, bool file) {
		if (file) {
			for (int i = 0; i < next.size(); i++) {
				if (next[i]->get_name() == name) {
					return i;
				}
			}
		}
		else {
			for (int i = 0; i < texts.size(); i++) {
				if (texts[i]->get_name() == name) {
					return i;
				}
			}
		}
		return 0;
	}
	bool is_del(string name){
		File* f = get_file(name, this);
		
		if (f->deletable){
			return true;
		}

		else{
			return false;
		}

	}
	void del_file(string name) {
		if (does_exist(name, true)) {
			if (is_del(name)){
				int f = get_index(name, true);
				next.erase(next.begin() + f);
			}
			else{
				cout << "File " << "'" << name << "'" << " is not deletable" << endl;
			}
		}
		else {
			cout << "File does not exist." << endl;
		}
	}

	void del_text(string name) {
		if (does_exist(name, false)) {
			int f = get_index(name, false);

			texts.erase(texts.begin() + f);
		}
		else {
			cout << "Text does not exist." << endl;
		}
	}

	void print_files() {
		if (next.size() == 0 && texts.size() == 0) {
			cout << "this folder is empty" << endl;
		}
		int four_row_counter = 0;
		for (int i = 0; i < next.size(); i++) {
			cout << next[i]->get_name()
				<< string(16 - next[i]->get_length(),
				' ');  // formula to calculate space between words
			four_row_counter++;
			if (four_row_counter == 4) {
				four_row_counter = 0;
				cout << "\n";
			}
		}
		int four_row_counter2 = 0;
		for (int i = 0; i < texts.size(); i++) {
			cout << texts[i]->get_name()
				<< string(16 - next[i]->get_length(),
				' ');  // formula to calculate space between words
			if (four_row_counter2 == 4) {
				four_row_counter2 = 0;
				cout << "\n";
			}
		}
		cout << "\n";
	}
};

File* current;

void show_date() {
	/* 
	Fyrir xcode
	time_t now = time(0);
	tm* localtm = localtime(&now);
	cout << asctime(localtm);
	*/

	// Fyrir Visual Studio
	time_t rawtime;
	time(&rawtime);
	struct tm timeinfo;
	localtime_s(&timeinfo, &rawtime);
	char str[26];
	asctime_s(str, sizeof str, &timeinfo);
	cout << str;
}

void helpPage(){
	vector<string> commands = { "cd", "" };
}

void clear() {
	for (int i = 0; i < 20; i++) {
		cout << "\n";
	}
}

void getCommand(string a, string b) {
	if (a == "ls") {
		current->print_files();
	}
	else if (a == "cd") {
		if (b != "..") {
			current = current->get_file(b, current);
		}

		else {
			if (current->parent != nullptr){
				current = current->parent;
			}
		}

	}
	else if (a == "newfile") {
		if (!current->does_exist(b, true)){
			if (b.find_first_not_of(' ') != std::string::npos) {
				current->new_file(b, true);
			}
			else{
				cout << "file names cannot be blank" << endl;
			}
		}
		else{
			cout << "File already exists" << endl;
		}
	}

	else if (a == "delfile") {
		current->del_file(b);
	}

	else if (a == "clear") {
		clear();
	}

	else if (a == "newtext") {
		if (!current->does_exist(b, false)) {
			if (b.find_first_not_of(' ') != std::string::npos) {
				Text* t =
					new Text(b + ".text");  // makes '.text' a part of the file name
				t->editor();
				current->add_text(t);
			}
			else {
				cout << "file names cannot be blank" << endl;
			}
		}
		else {
			cout << "Text already exists" << endl;
		}
	}

	else if (a == "deltext") {
		current->del_text(b);
	}

	else if (a == "edit") {
		if (current->does_exist(b, false)) {
			Text* t = current->get_text(b);
			t->editor();
		}
		else {
			cout << "Text does not exists" << endl;
		}
	}

	else if (a == "exit") {
	}

	else if (a == "help") {
		cout << "help page" << endl;
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
	if (root) {
		getCommand(primary, extra);
	}
	primary = "";
	extra = "";
}

string place() {
	File* curr = current;
	string s;
	while (curr) {
		s = curr->get_name() + "/" + s;
		curr = curr->parent;
	}
	return s;
}

int main() {
	show_date();
	current = new File("root", nullptr, false);
	current->new_file("Downloads", false);
	current->new_file("Pictures", false);
	current->new_file("Documents", false);
	current->new_file("Dodfgloads", true);
	current->new_file("Pdfgdfgtures", true);
	current->new_file("Dodfgnts", true);
	current->new_file("Dodfgads", true);
	current->new_file("dfgdfgctures", true);
	current->new_file("Dfdgents", true);
	current->new_file("Doads", true);
	current->new_file("Pic", true);


	string command = "";  // command stringur fyrir input
	string primary,
		extra;  // primary command er primary, extra er viðbót við það command

	// cout << current->next << endl;

	while (command != "exit") {
		cout << place() << ": ";
		getline(cin, command);
		workCommand(command, true);  // fall sem vinnur með inputtið
		// displayRow(dir); // fall sem prentar út directiory, tekur array sem
		// færibreytu
	}

	return 0;
}