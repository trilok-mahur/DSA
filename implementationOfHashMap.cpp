#include<bits/stdc++.h>
using namespace std;
template <typename V>
class mapNode{
    public :
    string key;
    V value;
    mapNode* next;
    mapNode(string key, V value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    ~mapNode() {
        delete next;
    }
};
template <typename V>
class ourMap{
    private :
    mapNode<V> ** buckets;
    int count;
    int numBuckets;
    public: 
    ourMap() {
        count = 0;
        numBuckets = 5;
        buckets = new mapNode<V>*[numBuckets];
        for(int i = 0; i < numBuckets; i++) {
            buckets[i] = NULL;
        }
    }
    ~ourMap() {
        for(int i = 0; i < numBuckets; i++) {
            delete buckets[i];
            delete [] buckets;
        }
    }
    int size() {
        return count;
    }
    private : 
    int getBucketIndex(string key) {
        int hashCode = 0;
        int currentCoeff = 1;
        for(int i = key.length() - 1; i >= 0; i--) {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;
            currentCoeff *= 7;
            currentCoeff = currentCoeff % numBuckets; 
        }
        return hashCode % numBuckets;
    }
    private:
    void rehash() {
        mapNode<V>** temp = buckets;
        buckets = new mapNode<V>*[2 * numBuckets];
        for(int i = 0; i < 2 * numBuckets; i++) {
            buckets[i] = NULL;
        }
        int oldNumBuckets = numBuckets;
        numBuckets *= 2;
        count = 0;
        for(int i = 0; i < oldNumBuckets; i++) {
            mapNode<V>* head = temp[i];
            while(head != NULL) {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for(int i = 0; i < oldNumBuckets; i++) {
            mapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
    }
    public :
    void insert(string key, V value) {
        int bucketIndex = getBucketIndex(key); 
        mapNode<V>* head = buckets[bucketIndex];
        while(head != NULL) {
            if(head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        mapNode<V>* Node = new mapNode<V>(key,value);
        Node->next = head;
        buckets[bucketIndex] = Node;
        count++;
        double loadfactor = (1.0 * count)/ numBuckets;
        if(loadfactor > 0.7) {
            rehash();
        }
    }
    V remove(string key) {
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        mapNode<V>* prev = NULL;

        while( head != NULL){
            if(head->key == key ) {
                if(prev == NULL) {
                    buckets[bucketIndex] = head->next;
                }
                else {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next; 
        }
        cout << "\nGiven Key is not exist in this map\n";
        return 0;
    }
    V getValu(string key) {
        int bucketIndex = getBucketIndex(key);
        mapNode<V>* head = buckets[bucketIndex];
        while(head != NULL) {
            if(head->key == key) {
                return head->value;
            }
            head = head->next;
        }
        cout << "\nGiven Key is not present in this map\n";
        return 0;

    }
    void printmap() {
        for(int i = 0; i < numBuckets; i++) {
            mapNode<V>* head = buckets[i];
            while(head != NULL) {
                cout << "| KEY : " << head->key << " & Value : " << head->value << " |   ";
                head = head->next;
            }
            cout << endl;
        }
    }
    double loadFactor() {
        return (1.0 * count)/numBuckets;
    }
    int bucketsize() {
        return numBuckets;
    }
};
int main() {
    ourMap<int> m;
    for(int i = 0; i < 20; i++) {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = 100 + i;
        m.insert(key,value);
        cout << "\nLoadfactor = " << m.loadFactor() << endl;
        cout <<" size = " << m.size() << endl;
        cout << "Bucket size = " << m.bucketsize() << endl;
    }
    m.insert("ggh",23);
    m.insert("ggha",523);
    m.insert("ggsh",243);
    m.insert("ggah",236);
    m.insert("ggash",2334);
    m.insert("ggash",23363);
    m.insert("gagh",2386);
    m.insert("asggh",235);
    m.insert("ggthh",2367);
    m.insert("ggh54tr",23);
    m.insert("ggrtrtgdch",23);
    m.insert("ggrfthh",23);
    m.insert("ggrh",23);
    m.insert("ggth",23);
    m.insert("ggmh",23);
    m.printmap();
    cout <<"\nLoad factor = " << m.loadFactor() << endl;
    cout << "Buckets size = " << m.bucketsize() << endl; 
    cout << "size = " << m.size() << endl;
}