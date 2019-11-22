#include <iostream>
#include <string>
#include <fstream>
#include "decompress.h"

using namespace std;
// to store characters ASCII table
template<class V, class K>
void store_ASCII(HashTable<V, K> &table1)
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
	HashTable<int, string> table;
	string comfile = "compout.txt";
	string out_comfile = "decompout.txt";
	ifstream in;
	ofstream out;

	in.open(comfile.c_str());
	out.open(out_comfile.c_str());
	in.clear();
	in.seekg(0);

	int index = 256;
	int bin;
	int tmp;
	string str = "";
	string line = "";
	store_ASCII(table);

	in >> bin;
	tmp = bin;
	//search until end of the file
	while (in >> bin)
	{
		//read integer by integer
		line = table.get(tmp);
		if (!(table.isValueExist(bin)))//if not
		{
			char fc = table.get(tmp).at(0);//first char of string of last number
			table.insertElement(line + fc, index);
		}
		else if((table.isValueExist(bin)))//if it is
		{
			char fc = table.get(bin).at(0);//first char of string of corresponding number
			table.insertElement(line + fc, index);
		}
		index++;
		tmp = bin;
	}
	in.clear();
	in.seekg(0);
	int x;
	while (in>>x)//out all table
	{
		out << table.get(x);
	}

	in.close();
	out.close();
	return 0;
}