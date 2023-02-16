
#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class Data_Item {
public:
	string key;
	string val;

	Data_Item() {
		key = "";
		val = "";
	}

	Data_Item(string k, string v) {
		key = k;
		val = v;
	}

};

class HashTable {

private:
	static const int size = 10;
	list<Data_Item> table[size];

public:
	int getHash(string key);
	void insert(string key, string val);
	void remove(string key);
	bool isKeyExist(string key);
	string search(string key);
	void print();

};

int HashTable::getHash(string key)
{
	int sum = 0;
	for (int i = 0; i < key.length(); i++) {
		sum = sum + key[i];
	}
	return sum % size;
}

void HashTable::insert(string key, string val)
{
	int index = getHash(key);
	//cout << index << endl;
	Data_Item di(key, val);
	//check key exists - get the list of that key and check whether the key is there in the list
	if (!isKeyExist(key))
		table[index].push_back(di);
	else
		cout << "The key already exist" << endl;
}

void HashTable::remove(string key)
{
	if (!isKeyExist(key))
		cout << "Key does not exist" << endl;
	else {
		int index = getHash(key);
		list<Data_Item> this_list = table[index];
		list<Data_Item>::iterator itr = this_list.begin();
		while (itr != this_list.end()) {
			if (itr->key == key) {
				//once the item is deleted, the iterator jumps to the next item 
				//(so it should not be inremented in this step)
				itr = this_list.erase(itr); 
			}
			else {
				itr++;
			}
		}
		table[index] = this_list;
	}
}



bool HashTable::isKeyExist(string key)
{
	int index = getHash(key);
	for (Data_Item d : table[index]) {
		if (d.key == key)
			return true;
	}
	return false;
}

string HashTable::search(string key)
{
	int index = getHash(key);
	for (Data_Item d : table[index]) {
		if (d.key == key)
			return d.val;
	}
	return "Value could not be found";
}

void HashTable::print()
{
	for (int i = 0; i < size; i++) {
		cout << "Index " << i << " : ";
		for (Data_Item d : table[i]) {
			cout << d.key << " - " << d.val << " | ";
		}
		cout << endl;
	}
}


int main() {
	HashTable ht;
	ht.insert("peter", "0713458759");
	ht.insert("peter", "0713458755");
	ht.insert("shawn", "0713457755");
	ht.insert("ali", "0711265789");
	ht.print();

	string tel = ht.search("shawn");
	cout << "Telephone number of Shawn is " << tel << endl;
	
	ht.remove("shawn");
	ht.print();

	return 0;
}