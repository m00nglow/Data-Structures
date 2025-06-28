#include <bits/stdc++.h>

using namespace std;

template <typename K, typename V>

class HashNode {
public:
    V value;
    K key;

    HashNode(K key, V value) {
        this->key = key;
        this->value = value;
    }
};

class HashMap {
    HashNode<K, V>** arr;
    int capacity;
    int size;
    HashNode<K, V>* dummy;
public:
    HashMap() {
        capacity = 7;
        size = 0;
        arr = new HashNode<K, V>*[capacity];

        for (int i =0; i < capacity; i++)
            arr[i] = nullptr;

        dummy = new HashNode<K, V>(-1, 1);
    }

    int hashCode(K key) {
        return key % capacity;
    }

    void insertNode(K key, V value) {
        HashNode<K, V>* temp = new HashNode<K, V>(key, value);

        int hashIndex = hashCode(key);

        while (arr[hashIndex] != nullptr && arr[hashIndex]->key != key && arr[hashIndex]->key != -1) {
            hashIndex++;
            hashIndex %= capacity;
        }

        if (arr[hashIndex] == nullptr || arr[hashIndex]->key == -1)
            size++;

        arr[hashIndex] = temp;
    }

    V deleteNode(int key) {
        int hashIndex = hashCode(key);

        while (arr[hashIndex] != nullptr) {
            if (arr[hashIndex]->key == key) {
                HashNode<K, V>* temp = arr[hashIndex];
                arr[hashIndex] = dummy;

                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= capacity;
        }
        return nulltpr;
    }
};