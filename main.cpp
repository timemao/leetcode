#include <iostream>
#include "func.h"

//#define my_abs(a,b) a>=b?(a-b):(b-a)
long long my_abs( long long a,  long long b) {
	 long long abs_v = 0;
	if (a >= b) {
		abs_v = a - b;
	}
	else {
		abs_v = b - a;
	}
	return abs_v;
}
int test_programmer_climbing()
{
	long long max_T = 10;
	long long max_mm = 100000;
	long long max_height = 1000000000;

	long long n0;
	std::cin >> n0;
	long long* n = new long long[10];

	long long* hv = new long long[max_mm];
	long long* diff = new long long[max_mm];

	long long wid0 = 0;
	for (long long k = 0; k < n0; k++)
	{
		long long tmp_n;
		std::cin >> tmp_n;
		n[k] = tmp_n;

		if (tmp_n >= 2 && tmp_n <= max_mm)
		{
			for (long long i = 0; i < tmp_n; i++)
			{
				long long tmp_hv;
				std::cin >> tmp_hv;
				if (tmp_hv >= 1 && tmp_hv <= max_height) {
					hv[i+wid0] = tmp_hv;
				}
			}
		}
		wid0 = wid0 + tmp_n;
	}

	long long wid = 0;
	for(long long k=0;k<n0;k++){
		
		long long min_v = max_height;
		
		long long diff_num = 0;
		for (long long i = 0; i < n[k]; i++) {
			for (long long j = 0; j < i; j++) {
				long long tmp_diff = my_abs(hv[i + wid], hv[j + wid]);
				//std::cout << tmp_diff << " ";
				diff[diff_num] = tmp_diff;
				diff_num += 1;
				if (tmp_diff <= min_v)
					min_v = tmp_diff;
			}
		}
		long long min_mum = 0;
		for (long long i = 0; i < diff_num; i++) {
			//std::cout << diff[i]<<" ";
			if (min_v == diff[i])
				min_mum += 1;
		}
		std::cout << min_v << " " << min_mum << std::endl;
		wid = wid + n[k];
	}
	delete[] n;
	delete[] hv;
	delete[] diff;
	return 0;
}

int main()
{
	//least_road_sum();
	Minimum_Spanning_Tree_main();
	return 0;
}