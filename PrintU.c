#include <stdio.h>
#include <string.h>
#define N 81
int main() {
	int n1, n2, n3, len;
	int i, j;
	char str[N];
	gets(str);
	len = strlen(str);
	n1 = n2 = n3 = (len + 2)/3;
	if (n1 + n2 + n3 + 1 == len + 2) {
		n2 += 1;
	}
	else if (n1 + n2 + n3 + 2 == len + 2){
		n2 += 2;
	}

	for (i = 0; i < n1 - 1; i ++) {
		putchar(str[i]);
		for (j = 0; j < n2 - 2;j++)
			putchar(' ');
		putchar(str[len-i-1]);
		putchar('\n');
	}
	for (i = n1 - 1; i < n1 + n2 - 1; i ++)
		putchar(str[i]);
	putchar('\n');
	return 0;
}
