#include<stdio.h>
int main(){
	int width,num;
	scanf("%d%d",&width,&num);
	printf("%*d\n",width,num);
	printf("%1$*2$d\n",width,num);
	return 0;
}
