#include <stdio.h>
#include <iostream>
#include <string>

#define MAX_STRING 100

using namespace std;

//-------------------- build table ------------------//
char upper_[11] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[' };
char middle_[10] = { 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';' };
char below_[9] = { 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',' };


int find_index_char(char *char_arr, char tmp, int n_arr)
{
	int local = -1;
	for (int j = 0; j < n_arr; j++)
	{
		if (char_arr[j] == tmp)
		{
			local = j;
			return local;
		}
	}
	return local;
}

struct key_local
{
	int x;
	int y;
};

void find_index(string str, key_local *str_local)
{
	int n_length = str.length();
	char out_char[100] = {};

	for (int i = 0; i < n_length; i++)
	{
		char tmp_ = str.substr(i, 1).c_str()[0];

		int local ;
		local=find_index_char(upper_, tmp_, 11);
		if (local>-1)
		{
			str_local[i].x = 1;
			str_local[i].y = local;
			out_char[i] = upper_[local - 1];
			continue;
		}

		local = find_index_char(middle_, tmp_, 10);
		if (local>-1)
		{
			str_local[i].x = 2;
			str_local[i].y = local;
			out_char[i] = middle_[local - 1];
			continue;
		}

		local = find_index_char(below_, tmp_, 9);
		if (local>-1)
		{
			str_local[i].x = 2;
			str_local[i].y = local;
			out_char[i] = below_[local - 1];
			continue;
		}
		//printf("x,y=%d,%d\n", str_local[i].x, str_local[i].y);
	}
	string out_str = out_char;
	//printf("out_str=%s\n", out_str.c_str());
	printf("%s\n",out_str.c_str());
}

int main()
{

	//-------------------- input lookup ------------------//
	int n_string;
	//printf("input n_string: \n");
	cin >> n_string;

	//string *in_strings = new string[n_string];
	key_local str_local[100];

	for (int i = 0; i < n_string; i++)
	{
		string tmp_str;
		//printf("input str:\n");
		cin >> tmp_str;

		//printf("idx=%d, tmp_str=%s\n", i,tmp_str.c_str());

		find_index(tmp_str, str_local);

	}
	getchar();
	//delete(in_strings);
	return 0;
}