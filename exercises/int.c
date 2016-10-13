#include <stdio.h>
#include <stdint.h>

int main()
{
	
	printf("Size 8: %d\nSize16: %d\nSize32: %d\nSize64: %d\n ", (sizeof(int8_t)*8), (sizeof(int16_t)*8), (sizeof(int32_t)*8), (sizeof(int64_t)*8));

	return 0;
}
