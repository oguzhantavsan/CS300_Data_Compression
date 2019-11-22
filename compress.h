#ifndef _COMPRESS_H_
#define _COMPRESS_H_

#include <iostream>
#include <string>

using namespace std;

template<class K, class V>
//created node for K and V values
struct Node
{
	V value;//index
	K key;//element
	Node()
	{
		value = -1;//first set index -1
	}
};
template<class K, class V>
//create hashtable to store element 
class HashTable
{
private:
	Node<K, V> arry[4096];
	int size;
public:
	HashTable();
	int hashfunction(const K &key);
	void insertElement(K &key, V value);
	int get(const K & key);
	bool isKeyExist(const K & k);
};
//constructor
template<class K, class V>
HashTable<K, V>::HashTable()
{
	size = 4096;
	Node<K, V> temp;

	for (int i = 0; i < size; i++)
	{
		arry[i] = temp;
	}
}
//hashed the corresponding element
template<class K, class V>
int HashTable<K, V>::hashfunction(const K&key)
{	int hashVal = key[0]*11 + 19;
	if (hashVal < 0)		hashVal = hashVal + size;	
	hashVal = hashVal % size;
	return(hashVal);
}
//inserted element
template<class K, class V>
void HashTable<K, V>::insertElement(K & key, V value)
{
	Node<K, V> temp;//new node for element
	int hashindex = hashfunction(key);
	temp.key = key;
	temp.value = value;
	//enter while loop until index < size, element in corresponding index is not equal to key, and index in the array with corresponding index is not equal -1
	while (hashindex < size && arry[hashindex].key != key && arry[hashindex].value != -1)
	{
		hashindex++;
	}
	arry[hashindex] = temp;
}
// to get index with given element
template<class K, class V>
int HashTable<K, V>::get(const K & k)
{
	int x = hashfunction(k);
	while (x < (size - 1) && arry[x].key != k)
		x++;
	return arry[x].value;
}
//to check element is in array or not
template<class K, class V>
bool HashTable<K, V>::isKeyExist(const K& key)
{
	int x = 0;
	while (x < size)
	{
		if (arry[x].key == key)
			return true;
		x++;
	}
	return false;
}
#endif


