// better implementation of map using hash table
// we use a hash function to map keys to indices in an array, and then use separate chaining to handle collisions (we'll dicuss bucketed hash tables, linear probing, quadratic probing, and double hashing)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Entry Class (Stores Key-Value pairs)
template <typename V>
class Entry {
private:
    int key;
    V value;
public:
    Entry(int k = 0, V v = V()) : key(k), value(v) {}
    int getKey() const { return key; }
    V getValue() const { return value; }
    void setValue(const V& v) { value = v; }
    void setKey(int k) { key = k; }
};

// ABSTRACT Base HashMap Class
template <typename V>
class HashMap {
protected:
    int capacity;

    // Hash function: simple modulo operation
    int hashFunction(int key) const {
        return key % capacity;
    }

public:
    HashMap(int cap) : capacity(cap) {}
    virtual ~HashMap() {}

    // Pure virtual functions that every derived collision strategy MUST implement
    virtual void put(int key, V value) = 0;
    virtual V get(int key) const = 0;
    virtual void printMap() const = 0;
};

// Buckets
template <typename V>
class SeparateChainingMap : public HashMap<V> {
private:
    vector<vector<Entry<V>>> buckets; // Array of buckets, each holding a chain of entries

public:
    SeparateChainingMap(int cap) : HashMap<V>(cap) {
        buckets.resize(this->capacity);
    }

    void put(int key, V value) override {
        int index = this->hashFunction(key);

        // Check if key already exists in this chain, update if found
        for (auto& entry : buckets[index]) {
            if (entry.getKey() == key) {
                entry.setValue(value);
                return;
            }
        }
        // Otherwise, add a new entry to the end of the chain
        buckets[index].push_back(Entry<V>(key, value));
    }

    V get(int key) const override {
        int index = this->hashFunction(key);
        for (const auto& entry : buckets[index]) {
            if (entry.getKey() == key) {
                return entry.getValue();
            }
        }
        return V(); // Return default value if not found
    }

    void printMap() const override {
        cout << "\n--- Separate Chaining Map ---\n";
        for (int i = 0; i < this->capacity; ++i) {
            cout << "Bucket " << i << ": ";
            if (buckets[i].empty()) {
                cout << "[Empty]\n";
            } else {
                for (const auto& entry : buckets[i]) {
                    cout << "[Key: " << entry.getKey() << ", Val: " << entry.getValue() << "] -> ";
                }
                cout << "END\n";
            }
        }
    }
};


// Slot structure for probing methods
template <typename V>
struct Slot {
    int key;
    V value;
    bool isOccupied = false;
};

// linear probing
template <typename V>
class LinearProbingMap : public HashMap<V> {
private:
    vector<Slot<V>> table;

public:
    LinearProbingMap(int cap) : HashMap<V>(cap) {
        table.resize(this->capacity);
    }

    void put(int key, V value) override {
        int hash = this->hashFunction(key);

        for (int i = 0; i < this->capacity; ++i) {
            // Linear probing formula: index = (hash + i) % capacity
            int index = (hash + i) % this->capacity;

            if (!table[index].isOccupied || table[index].key == key) {
                table[index] = {key, value, true};
                return;
            }
        }
        cout << "Table is full! Cannot insert Key " << key << "\n";
    }

    V get(int key) const override {
        int hash = this->hashFunction(key);
        for (int i = 0; i < this->capacity; ++i) {
            int index = (hash + i) % this->capacity;
            if (!table[index].isOccupied) return V();
            if (table[index].key == key) return table[index].value;
        }
        return V();
    }

    void printMap() const override {
        cout << "\n--- Linear Probing Map ---\n";
        for (int i = 0; i < this->capacity; ++i) {
            cout << "Slot " << i << ": ";
            if (table[i].isOccupied) {
                cout << "[Key: " << table[i].key << ", Val: " << table[i].value << "]\n";
            } else {
                cout << "[Empty]\n";
            }
        }
    }
};

// quadratic probing
template <typename V>
class QuadraticProbingMap : public HashMap<V> {
private:
    vector<Slot<V>> table;

public:
    QuadraticProbingMap(int cap) : HashMap<V>(cap) {
        table.resize(this->capacity);
    }

    void put(int key, V value) override {
        int hash = this->hashFunction(key);

        for (int i = 0; i < this->capacity; ++i) {
            // Quadratic probing formula: index = (hash + i^2) % capacity
            int index = (hash + (i * i)) % this->capacity;

            if (!table[index].isOccupied || table[index].key == key) {
                table[index] = {key, value, true};
                return;
            }
        }
        cout << "Table is full! Cannot insert Key " << key << "\n";
    }

    V get(int key) const override {
        int hash = this->hashFunction(key);
        for (int i = 0; i < this->capacity; ++i) {
            int index = (hash + (i * i)) % this->capacity;
            if (!table[index].isOccupied) return V();
            if (table[index].key == key) return table[index].value;
        }
        return V();
    }

    void printMap() const override {
        cout << "\n--- Quadratic Probing Map ---\n";
        for (int i = 0; i < this->capacity; ++i) {
            cout << "Slot " << i << ": ";
            if (table[i].isOccupied) {
                cout << "[Key: " << table[i].key << ", Val: " << table[i].value << "]\n";
            } else {
                cout << "[Empty]\n";
            }
        }
    }
};

// double hashing
template <typename V>
class DoubleHashingMap : public HashMap<V> {
private:
    vector<Slot<V>> table;

    // Secondary hash function: must never return 0 to avoid infinite loops
    int hash2(int key) const {
        return 7 - (key % 7);
    }

public:
    DoubleHashingMap(int cap) : HashMap<V>(cap) {
        table.resize(this->capacity);
    }

    void put(int key, V value) override {
        int h1 = this->hashFunction(key);
        int h2 = hash2(key);

        for (int i = 0; i < this->capacity; ++i) {
            // Double hashing formula: index = (h1 + i * h2) % capacity
            int index = (h1 + i * h2) % this->capacity;

            if (!table[index].isOccupied || table[index].key == key) {
                table[index] = {key, value, true};
                return;
            }
        }
        cout << "Table is full! Cannot insert Key " << key << "\n";
    }

    V get(int key) const override {
        int h1 = this->hashFunction(key);
        int h2 = hash2(key);

        for (int i = 0; i < this->capacity; ++i) {
            int index = (h1 + i * h2) % this->capacity;
            if (!table[index].isOccupied) return V();
            if (table[index].key == key) return table[index].value;
        }
        return V();
    }

    void printMap() const override {
        cout << "\n--- Double Hashing Map ---\n";
        for (int i = 0; i < this->capacity; ++i) {
            cout << "Slot " << i << ": ";
            if (table[i].isOccupied) {
                cout << "[Key: " << table[i].key << ", Val: " << table[i].value << "]\n";
            } else {
                cout << "[Empty]\n";
            }
        }
    }
};

int main() {
    // 1. Test Separate Chaining (Buckets)
    SeparateChainingMap<string> chainingMap(5);
    chainingMap.put(101, "Apple");  // h1 = 1
    chainingMap.put(106, "Banana"); // Collides with 101 (both % 5 == 1)
    chainingMap.put(201, "Cherry"); // Collides with 101 & 106
    chainingMap.printMap();

    // 2. Test Linear Probing
    LinearProbingMap<string> linearMap(5);
    linearMap.put(101, "Dog");   // h1 = 1
    linearMap.put(106, "Cat");   // Slides down to next available slot
    linearMap.put(111, "Mouse"); // Slides further down
    linearMap.printMap();

    // 3. Test Quadratic Probing
    QuadraticProbingMap<string> quadMap(5);
    quadMap.put(101, "Sun");   // h1 = 1
    quadMap.put(106, "Moon");  // Jumps by 1^2 = slot 2
    quadMap.put(111, "Star");  // Jumps by 2^2 = slot 5
    quadMap.printMap();

    // 4. Test Double Hashing
    DoubleHashingMap<string> doubleMap(5);
    doubleMap.put(101, "Red");   // h1 = 1
    doubleMap.put(106, "Blue");  // Uses secondary hash to compute step size
    doubleMap.put(111, "Green");
    doubleMap.printMap();

    return 0;
}