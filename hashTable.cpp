#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

template<class T, class T2>
class HashItem {
  private:
    T key;
    T2 value;
  public:
    HashItem(T key, T2 value) {
      this->key = key;
      this->value = value;
    }

    T GetKey() {
      return this->key;
    }

    T2 GetValue() {
      return this->Value;
    }
};

template<class T, class T2>
class HashTable {
  private:
    const int hashSize = 128;
    vector<HashItem<T,T2>*> hashContainer[128];
    int (*hashFunction)(T);

  public:
    HashTable(int (*hashFunction)(T)) {
      this->hashFunction = hashFunction;
    }

    void InsertItem (HashItem<T,T2>* newItem) {
      int keyIndex = this->hashFunction(newItem.GetKey());
      hashContainer[keyIndex].push_back(newItem);
    }

    T2 GetItemValue (T key) {
      int keyIndex = this->hashFunction(key);
      for(auto item : hashContainer[keyIndex]) {
        if(key == item.GetKey()) {
          return item.GetValue();
        }
      }
      return NULL;
    }
};

//We are more interested in Hash class itself than having a working hash table
int modularHash (int key) {
  return key%128;
}

int main() {
  HashTable<int, int> *table = new HashTable<int,int>(&modularHash);
  HashItem<int, int> *item1 = new HashItem<int,int>(1,2);
  HashItem<int, int> *item2 = new HashItem<int,int>(2,3);

  delete(table);
  delete(item1);
  delete(item2);
  return 0;
}
