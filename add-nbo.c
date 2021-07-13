#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <netinet/in.h>

void input_err() {
	printf("Usage: add-nbo [FILE1.bin] [FILE2.bin]\n");
	exit(1);
}

uint32_t read_binary(char *file) {
	FILE *fd = fopen(file, "r");
	if (fd == NULL) input_err();
	uint32_t num[1];
	fread(num, 4, 1, fd);
	fclose(fd);
	return ntohl(num[0]);
}

int main(int argc, char *argv[]) {
	if (argc != 3) input_err();
	
	uint32_t num1, num2;
	
	num1 = read_binary(argv[1]);
	num2 = read_binary(argv[2]);

	uint32_t sum = num1 + num2;
	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", num1, num1, num2, num2, sum, sum);

	return 0;
}
