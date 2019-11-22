#ifndef _DECOMPRESS_H_
#define _DECOMPRESS_H_

#include <iostream>
#include <string>

using namespace std;
//created node for V and K values
template<class V, class K>
struct Node
{
	V value;//index
	K key;
	Node()
	{
		value = -1;
	}
};
//create hashtable to store element 
template<class V, class K>
class HashTable
{
private:
	Node<V, K> arry[4096];
	int size;
public:
	HashTable();
	int hashfunction(const K &key);
	void insertElement(K &key, V value);
	K get(V index);
	bool isValueExist(V & value);
};
//constructor
template<class V, class K>
HashTable<V, K>::HashTable()
{
	size = 4096;
	Node<V, K> temp;

	for (int i = 0; i < size; i++)
	{
		arry[i] = temp;
	}
}
//hashed the corresponding element
template<class V, class K>
int HashTable<V, K>::hashfunction(const K&key)
{
	int hashVal = key[0] * 11 + 19;
	if (hashVal < 0)		hashVal = hashVal + size;
	hashVal = hashVal % size;
	return(hashVal);
}
//inserted element
template<class V, class K>
void HashTable<V, K>::insertElement(K & key, V value)
{
	Node<V, K> temp;//new node for element
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
// to get element with given index
template<class V, class K>
K HashTable<V, K>::get(V index)
{
	int x = 0;
	while (x < size-1)
	{
		if (arry[x].value == index)
			return arry[x].key;
		x++;
	}
	return NULL;
}
//to check array has element or not with given index
template<class V, class K>
bool HashTable<V, K>::isValueExist(V& value)
{
	int x = 0;
	while (x < size-1)
	{
		if (arry[x].value == value)
			return true;
		x++;
	}
	return false;
}
#endif


