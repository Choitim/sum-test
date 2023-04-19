#include <stdio.h>
#include <stdint.h>


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("syntax : add-nbo <file1> <file2>\n");
        printf("sample : add-nbo a.bin c.bin\n");
        return -1;
    }

    FILE *fp1, *fp2;
    uint32_t num1, num2;

    fp1 = fopen(argv[1], "rb");
    fp2 = fopen(argv[2], "rb");

    fread(&num1, sizeof(num1), 1, fp1);
    fread(&num2, sizeof(num2), 1, fp2);

    num1 = ntohl(num1);
    num2 = ntohl(num2);

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, num1 + num2, num1 + num2);

    fclose(fp1);
    fclose(fp2);

    return 0;
}
