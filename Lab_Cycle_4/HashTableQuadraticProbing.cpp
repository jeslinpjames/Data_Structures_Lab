// Implement a hash table with quadratic probing using array with the following operations
// :INSERT(key), DELETE(key), SEARCH(key)
#include<iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashMap {
private:
    int* table;
    int size;

public:
    HashMap() {
        table = new int[TABLE_SIZE];
        size = 0;
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = -1;
        }
    }

    ~HashMap() {
        delete[] table;
    }

    int hash(int key,int attempt) {
        return (key + attempt*attempt) % TABLE_SIZE;
    }

    void insert(int key) {
        int index = hash(key,0);
        int attempt = 0;
        while (table[index] != -1) {
            attempt++;
            index = hash(key, attempt);
        }
        table[index] = key;
        size++;
    }

    void remove(int key) {
        int index = hash(key,0);
        int attempt = 0;
        while (table[index] != key && table[index] != -1) {
            attempt++;
            index = hash(key, attempt);
        }
        if (table[index] == key) {
            table[index] = -1;
            size--;
        } else {
            cout << "Key not found: " << key << endl;
        }
    }

    bool search(int key) {
        int index = hash(key,0);
        int attempt = 0;
        while (table[index] != key && table[index] != -1) {
            attempt++;
            index = hash(key, attempt);
        }
        return table[index] == key;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != -1)
                cout << table[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    HashMap hashTable;

    hashTable.insert(5);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(35);

    cout << "HashTable contents:" << endl;
    hashTable.display();

    cout << "Searching for key 15: " << (hashTable.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for key 20: " << (hashTable.search(20) ? "Found" : "Not Found") << endl;

    hashTable.remove(15);
    hashTable.remove(20); // This key is not in the table

    cout << "HashTable contents after removal:" << endl;
    hashTable.display();

    return 0;
}
