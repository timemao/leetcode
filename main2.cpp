#include <iostream>

int main()
{
	//unsigned char img[] = {
	//	110,12,134,44,
	//	32,113,32,35
	//};
	unsigned char img[] = {
	154,153,153,62,
	205,204,204,62
	};
	//float val = (float)(img[0+4]);
	float *tmp = (float*)(img);
	printf("%f,%f\n",tmp[0], tmp[1]);
	//float val = *(float*)(img+1);

	//float img_float[] = { 0.333,0.4 };
	float img_float[] = { 0.0,0.0 };
	unsigned char* tmp_byte = (unsigned char*)img_float;
	for (int i = 0; i < 8; i++)
	{
		printf("i=%d,%d\n", i, tmp_byte[i]);
	}
	return 0;
}