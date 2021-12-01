#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int n = 10;

class object {
private:
	char name;
public:
	object(char s) {
		name = s;
		cout << "the object " << name << " has been created\n";
	}
	void setname(char s) {
		name = s;
		cout << "the name " << name << " has been setted\n";
	}
	char getname() {
		return name;
	}
	~object() {
		cout << "the object " << name << " has been deleted\n";
	}
};
