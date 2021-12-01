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

class Item {
public:
	object* obj;
	Item* prev;
	Item* next;
	Item(object* O) {
		obj = O;
		cout << "the item " << obj->getname() << " has been created\n\n";
		prev = nullptr;
		next = nullptr;
	}
};

class Storage {
	Item* first;
	Item* current;
	Item* last;
public:
	Storage() {
		first = nullptr;
		current = nullptr;
		last = nullptr;
		cout << "the storage has been created\n\n";
	}
	int count() {
		int res = 0;
		for (firstItem(); !isEoL(); nextItem())res++;
		return res;
	}
	void add(object* obj) {
		Item* item = new Item(obj);
		if (first == nullptr) {
			first = item;
			current = item;
			last = item;
		}
		else {
			last->next = item;
			item->prev = last;
			last = item;
		}
	}
	void firstItem() {
		current = first;
	}
	void lastItem() {
		current = last;
	}
	void prevItem() {
		if (!isEoL()) current = current->prev;
	}
	void nextItem() {
		if (!isEoL()) current = current->next;
	}
	bool isEoL() {
		return current == nullptr;
	}
};
