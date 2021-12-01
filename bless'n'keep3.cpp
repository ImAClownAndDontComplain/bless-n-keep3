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
	bool isThere(object* O) {
		for (firstItem(); !isEoL(); nextItem())
			if (curItem() == O) return true;
		return false;
	}
	object* curItem() {
		return current->obj;
	}
	object* removeC() {
		if (current == nullptr)	return NULL;
		Item* prev = current->prev;
		Item* next = current->next;
		object* obj = current->obj;
		delete current;
		if (prev == nullptr && next == nullptr) {
			first = nullptr;
			last = nullptr;
		}
		else if (next == nullptr) {
			current = prev;
			last = prev;
			last->next = nullptr;
		}
		else if (prev == nullptr) {
			current = next;
			first->prev = nullptr;
			first = next;
		}
		else {
			current = next;
			prev->next = next;
			next->prev = prev;
		}
		return obj;
	}
	~Storage() {
		if (first == nullptr) return;
		while (!isEoL()) {
			Item* next = current->next;
			delete current;
			current = next;
		}
	}
};

void showstorage(Storage storage) {
	cout << "the storage: ";
	for (storage.firstItem(); !storage.isEoL(); storage.nextItem()) {
		cout << storage.curItem()->getname() << " ";
	}
	cout << "\ntotal amount of items is " << storage.count() << "\n\n";
}
string showpresence(Storage& s, object* o) {
	if (s.isThere(o) == true)return "yes\n\n";
	else return "no\n\n";
}

int main() {
	Storage storage;
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		object* obj = new object((char)(65 + rand() % 26));
		storage.add(obj);
	}
	showstorage(storage);

	storage.firstItem();
	object* F = storage.removeC();
	cout << "removed first item: " << F->getname() << endl;
	delete F;
	showstorage(storage);

	storage.firstItem();
	for (int i = 0; !storage.isEoL() && i < n / 2 - 1; storage.nextItem(), i++);
	object* M = storage.removeC();
	cout << "removed middle item: " << M->getname() << endl;
	delete M;
	showstorage(storage);

	storage.lastItem();
	object* L = storage.curItem();
	L->setname('0');
	cout << "last item is changed to " << L->getname() << endl;
	showstorage(storage);

	cout << "is there item " << L->getname() << " in the storage: " << showpresence(storage, L);
	object* L1 = new object('1');
	cout << "is there item " << L1->getname() << " in the storage: " << showpresence(storage, L1);

	storage.firstItem();
	storage.add(L1);
	cout << "added item: " << L1->getname() << endl;
	showstorage(storage);

	for (storage.firstItem(); !storage.isEoL(); storage.nextItem()) {
		delete storage.curItem();
	}
}
