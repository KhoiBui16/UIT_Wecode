#include <iostream>
#include <unordered_map>
using namespace std;

class HashTable {
private:
    unordered_map<int, bool> table;

public:
    // Insert function
    void insert(int key) {
        table[key] = true;
    }

    // Delete function
    void deleteNode(int key) {
        table.erase(key);
    }

    // Search function
    bool search(int key) {
        return table.find(key) != table.end();
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    HashTable hashTable;
    int a, b;

    while (cin >> a >> b) {
        switch (a) {
            case 1:
                hashTable.insert(b);
                break;
            case 2:
                cout << hashTable.search(b) << '\n';
                break;
            case 3:
                hashTable.deleteNode(b);
                break;
            default:
                break;
        }
    }

    return 0;
}
