/*
A map is a data structure where you store keys and map values to those keys. All keys must be unique.
Dictionaries in python are also maps. 

Here, we need:
- key-value pair
- keep these key value pairs somewhere
here, we will use a doubly linked list (STL List)

since key has to be unique, every time we try to add a key value pair, we will search for the key.
- if key already in map, we will update its value
- if key not in map, we will add the key-value pair to the very end
*/

#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>
// #include <unordered_map> // the STL version of what we're doing here

using namespace std;

template <typename K, typename V>
class Entry {
private:
    K key;
    V value;
public:
    Entry(const K& k, const V& v) : key(k), value(v) {} // constructor
    // getters
    K getKey() const { return key; }
    V getValue() const { return value; }
    // setters
    void setKey(const K& k) { key = k; }
    void setValue(const V& v) { value = v; }
};

// pre-populated
template <typename K, typename V>
class Iterator {
public:
    typename list<Entry<K, V>>::iterator current; 
    Iterator(typename list<Entry<K, V>>::iterator it) : current(it) {}
    Entry<K, V>& operator*() { return *current; }
    Entry<K, V>* operator->() { return &(*current); }
    Iterator<K, V>& operator++() { ++current; return *this; }
    // "this," in C++, is a pointer to the current object, so we dereference it to return a reference to the current object

    bool operator==(const Iterator<K, V>& other) const { return current == other.current; }
    bool operator!=(const Iterator<K, V>& other) const { return current != other.current; }
};

template <typename K, typename V>
class Map {
// implemented using an unordered list of entries (doubly linked list)
private:
    list<Entry<K, V>> entries; // list of entries
public:
    // constructor
    Map() {}
    // destructor
    ~Map() {}
    // don't need to specify either constructor or destructor, since the STL list will handle memory management for us

    int size() const { return entries.size(); }
    bool empty() const { return entries.empty(); }
    Iterator<K, V> begin() { return Iterator<K, V>(entries.begin()); } 
    Iterator<K, V> end() { return Iterator<K, V>(entries.end()); }

    Iterator<K, V> find(const K& k) {
        for (auto it = entries.begin(); it != entries.end(); ++it) {
            if (it->getKey() == k) {
                return Iterator<K, V>(it); // give us iterator (position) for the entry with key = k
            }
        }
        return end(); // not found, we can add it here 
    } // O(n) - have to look through all n entries in the map

    Iterator<K, V> put(const K& k, const V& v) {
        Iterator<K, V> it = find(k);
        if (it != end()) {
            it->setValue(v); // update, since key found
            return it;
        } else {
            entries.push_back(Entry<K, V>(k, v)); // add entry to the very end of our list of entries
            // end of map
            return Iterator<K, V>(--entries.end()); // returns iterator to the last value (node before end)
        }
    }

    void erase(const K& k) {
        Iterator<K, V> it = find(k);
        if (it != end()) {
            erase(it);
        } else {
            throw out_of_range("Key not found in map!"); // throw an error (key was not found)
        }
    }

    void erase(const Iterator<K, V>& p) {
        // use STL List's erase
        entries.erase(p.current); // get's me the list<Entry<K, V>::iterator related to the Entry we're
        // trying to erase
    }
};

// inefficient
// good for small datasets
// good for lots of puts (like, for the history of calls or something)
// where searches and removals are rare
// O(n) for find, put, and erase (must see if key exists for put)

struct JournalEntry {
    string place;
    vector<string> people;
};

int main() {
    Map<int, JournalEntry> journal;

    // going back to Arendil, suppose he's been keeping a journal of the places he's been and the people he met at those places, or heard of

    JournalEntry entry1;
    entry1.place = "Teavern";
    entry1.people.push_back("Gimm");
    entry1.people.push_back("Forin");
    journal.put(1, entry1);

    JournalEntry entry2;
    entry2.place = "Map";
    entry2.people.push_back("Elarion");
    entry2.people.push_back("Miriel");
    entry2.people.push_back("Thaladir");
    entry2.people.push_back("Thrainor");
    entry2.people.push_back("Galaric");
    entry2.people.push_back("Bramdur");
    entry2.people.push_back("Aldorath");
    entry2.people.push_back("Eldrin");
    entry2.people.push_back("Rohanath");
    journal.put(2, entry2);

    // Test size and empty methods
    cout << "Size: " << journal.size() << endl; // Expected: 2
    cout << "Is empty: " << (journal.empty() ? "Yes" : "No") << endl; // Expected: No

    // Test find method
    auto it = journal.find(3); // Expected: Entry not found
    if (it != journal.end()) {
        cout << "Found entry with value: " << it->getValue().place << endl;
    } else {
        cout << "Entry not found" << endl; 
    }

    JournalEntry entry3;
    entry3.place = "Kahlbohr";
    entry3.people.push_back("Thaladir IV");
    journal.put(3, entry3);

    // Test find method again
    it = journal.find(3); // Expected: Found entry with value: Kahlbohr
    if (it != journal.end()) {
        cout << "Found entry with value: " << it->getValue().place << endl;
    } else {
        cout << "Entry not found" << endl; 
    }

    // Test erase method
    journal.erase(2);
    cout << "Size after erasing entry 2: " << journal.size() << endl; // Expected: 2

    // Test iterator
    cout << "Current entries in the map:" << endl;
    for (auto it = journal.begin(); it != journal.end(); ++it) {
        cout << it->getKey() << ": " << it->getValue().place << endl;
        cout << "People met: ";
        for (const auto& person : journal.find(it->getKey())->getValue().people) { 
            cout << person << ", ";
        }
        cout << endl;
    }

    return 0;
}