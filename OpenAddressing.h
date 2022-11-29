#ifndef HASHING_OPENADDRESSING_H
#define HASHING_OPENADDRESSING_H

#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <vector>
#include <fstream>

using std::cout, std::endl, std::function, std::nullopt, std::optional, std::string, std::vector, std::ofstream;

template<typename Keyable>
class DoubleHash {
private:
    enum state {EMPTY, FILLED, REMOVED};
    struct hashable {
        Keyable item;
        state status;
    };
    vector<hashable> table;
    unsigned long tableSize;
    function<string(Keyable)> getKey;
    unsigned long numItems;

    ofstream outfile;

    unsigned long hornerHash(string key) const {
        unsigned long hashVal = 0;
        for (char letter : key) {
            hashVal = hashVal * 37 + letter;
        }
        return hashVal % tableSize;
    }

    unsigned long cameronHash(string key) const{
        unsigned long hashVal = 0;
        for(char letter : key){
            hashVal = hashVal*44 + letter - 7;
        }
        return hashVal % tableSize;
    }

    // Find the next prime number
    int nextPrime(int n) {
        if (n % 2 == 0) {
            ++n;
        }
        bool prime = false;
        while (!prime) {
            prime = true;
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    prime = false;
                }
            }
            n += 2;
        }
        return (n-2);
    }

    void rehash(const int& reads) {
        int& read = const_cast<int&> (reads);
        // Store a copy of the hash table
        vector<hashable> oldTable = table;
        tableSize = nextPrime(tableSize * 2);
        // Empty the table
        table.clear();
        numItems = 0;

        table.resize(tableSize);

        // Reinsert all FILLED items
        for (int i = 0; i < oldTable.size(); ++i) {
            if (oldTable[i].status == FILLED) {
                insert(oldTable[i].item, read);
            }
        }

    }

public:
    // Constructor
    DoubleHash(unsigned long tableSize, function<string(Keyable)> getKey) {
        // This will fill the table with default Keyables and EMPTY statuses
        this->tableSize = nextPrime(tableSize);
        table.resize(this->tableSize);
        this->getKey = getKey;
        numItems = 0;
    }

    // Insert
    void insert(Keyable item, int& reads) {
        int& read= const_cast<int&>(reads);
        // Get the key from the item
        string key = getKey(item);
        if (!find(key, read)) {
            // Hash the key to get an index
            unsigned long index = hornerHash(key)+ cameronHash(key);
            if(index >=tableSize)
                index=index-tableSize;
            // Probe until we find a non-filled index
            while (table[index].status == FILLED) {
                // Add one to the index for linear probing
                index += 1;
                index %= tableSize;
            }
            table[index].item = item;
            if (table[index].status == EMPTY) {
                ++numItems;
                table[index].status = FILLED;
                // Rehash when more than half the table is filled
                if (numItems > tableSize/2) {
                    rehash(read);
                }
            } else {
                table[index].status = FILLED;
            }
        }
        outfile<<read<<",\t";
    }

    // Find
    optional<Keyable> find(string key, const int& reads) const {
        int& read = const_cast<int&>(reads);
        // Hash the key to get an index
        unsigned long index = hornerHash(key) + cameronHash(key);
        if(index >=tableSize)
            index=index-tableSize;
        read++;
        while (table[index].status != EMPTY) {
            // Check the index to see if the key matches
            read++;
            if (table[index].status == FILLED && getKey(table[index].item) == key) {
                // We found the item
                read++;
                return table[index].item;
            }
            // Add one to the index for linear probing
            index += 1;
            index %= tableSize;
        }
        // We didn't find the item
        return nullopt;
    }

    // Remove
    bool remove(string key) {
        // Hash the key to get an index
        unsigned long index = hornerHash(key) + cameronHash(key);
        if(index >=tableSize)
            index=index-tableSize;
        while (table[index].status != EMPTY) {
            // Check the index to see if the key matches
            if (table[index].status == FILLED && getKey(table[index].item) == key) {
                // We found the item
                // Remove it
                table[index].status = REMOVED;
                table[index].item = Keyable();
                return true;
            }
            // Add one to the index for linear probing
            index += 1;
            index %= tableSize;
        }
        // We didn't find the item
        return false;
    }

    // Print the table
    void printTable() const {
        cout << "Beginning of table" << endl;
        for (unsigned long i = 0; i < tableSize; ++i) {
            cout << i << ": ";
            if (table[i].status == FILLED) {
                cout << table[i].item;
            } else if (table[i].status == REMOVED) {
                cout << "X";
            }
            cout << endl;
        }
        cout << "End of table" << endl;
    }
};


#endif
