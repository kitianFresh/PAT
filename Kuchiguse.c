#include <stdio.h>
#include <string.h>

void reverse(char *str);

int main(){
	int i, j, n;
	size_t len;
	char arr[100][256], ch;
	ch = '\0';
	scanf("%d\n", &n);
	for (i = 0; i < n; i++){
		scanf("%c", &ch);
		for (j = 0; ch != '\n';j++){
			arr[i][j] = ch;
			scanf("%c", &ch);
		}
		arr[i][j] = '\0';
	}

	for (i = 0; i < n; i++)
		reverse(arr[i]);

	for (i = 0; arr[0][i] != '\0'; i++)
		for(j = 1; arr[j][i] != '\0'; j++){
			if (arr[j][i] == arr[0][i]) continue;
			else {
				arr[0][i] = '\0';
				i--;/* break out of outside for loop */
				break;
			}
		}
	if (i == 0)
		printf("nai\n");
	else{
		reverse(arr[0]);
		printf("%s\n", arr[0]);
	}
	return 0;
}

void reverse(char *str) {
	char *end, temp;
	end = str;
	while (*end != '\0') {
		end ++;
	}
	end --;
	while (str < end) {
		temp = *str;
		*str = *end;
		*end = temp;
		str ++;
		end --;
	}
}
