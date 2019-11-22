#include <iostream>
#include <string>
#include <fstream>
#include "compress.h"

using namespace std;
// to store characters ASCII table
template<class K, class V>
void store_ASCII(HashTable<K, V> &table1)
{
	int i = 0;
	while (i < 256)
	{
		char ch = i;
		string str1(1, ch);
		table1.insertElement(str1, i);
		i++;
	}

}
int main()
{
	HashTable<string, int> table;
	string comfile = "compin.txt";
	string out_comfile = "compout.txt";
	ifstream in;
	ofstream out;

	in.open(comfile.c_str());
	out.open(out_comfile.c_str());
	in.clear();
	in.seekg(0);

	int index = 256;
	char ch;
	string str = "";
	store_ASCII(table);
	//search until end of the file
	while (in.get(ch))
	{
		//read character by character
		string temp_str(1, ch);//convert it to string
		//check sum of previous string and found string is in the hashtable or not
		if (!(table.isKeyExist(str + temp_str)))//if not
		{
			table.insertElement((str + temp_str), index);
			index++;
			out << table.get(str) << " ";
			str = temp_str;
		}
		else if ((table.isKeyExist(str + temp_str)))// if it is
			str = str + temp_str;
	}
	out << table.get(str) << " ";
	in.close();
	out.close();
	return 0;
}