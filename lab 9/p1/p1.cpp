#include <iostream>
#include <cstdio>

template <typename K, typename V>
class Map {
private:
    struct MapNode {
        K key;
        V value;
        int index;
    };

    MapNode* data;
    int capacity;
    int size;

    void resize() {
        capacity *= 2;
        MapNode* newData = new MapNode[capacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Map() {
        capacity = 10;
        size = 0;
        data = new MapNode[capacity];
    }

    ~Map() {
        delete[] data;
    }

    V& operator[](const K& key) {
        for (int i = 0; i < size; ++i) {
            if (data[i].key == key) {
                return data[i].value;
            }
        }
        if (size == capacity) {
            resize();
        }
        data[size].key = key;
        data[size].index = size;
        return data[size++].value;
    }

    void Set(const K& key, const V& value) {
        (*this)[key] = value;
    }

    bool Get(const K& key, V& value) const {
        for (int i = 0; i < size; ++i) {
            if (data[i].key == key) {
                value = data[i].value;
                return true;
            }
        }
        return false;
    }

    int Count() const {
        return size;
    }

    void Clear() {
        size = 0;
    }

    bool Delete(const K& key) {
        for (int i = 0; i < size; ++i) {
            if (data[i].key == key) {
                for (int j = i; j < size - 1; ++j) {
                    data[j] = data[j + 1];
                    data[j].index = j;
                }
                size--;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& other) const {
        for (int i = 0; i < other.size; ++i) {
            bool found = false;
            for (int j = 0; j < this->size; ++j) {
                if (this->data[j].key == other.data[i].key) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }

    MapNode* begin() const {
        return data;
    }

    MapNode* end() const {
        return data + size;
    }
};

int main() {
    Map<int, const char*> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}