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

template <typename T>
class Item {
public:
	T* obj;
	Item<T>* prev;
	Item<T>* next;
	Item(T* object) {
		obj = object;
		cout << "the item " << obj->getname() << " has been created\n\n";
		prev = nullptr;
		next = nullptr;
	}
};


