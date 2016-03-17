#include <stdio.h>
typedef struct Node{
	int flag;
	char data;
	int next;
} Node;

int main(){
	Node nodes[100000];
	int first,second,lines;
	int addr,next,i,start;
	char data;
	for (i=0;i<100000;i++){
		nodes[i].flag = 0;
		nodes[i].next = 0;
	}
	scanf("%d %d %d",&first,&second,&lines);
	for (i=0;i<lines;i++) {
		scanf("%d %c %d", &addr, &data, &next);
		nodes[addr].data = data;
		nodes[addr].next = next;
	}
	for (i=first; i != -1;){
		nodes[i].flag = 1;
		i = nodes[i].next;
	}
	for (i=second; i != -1;){
		if (nodes[i].flag == 0) {
			i = nodes[i].next;
		}
		else {
			start = i;
			break;
		}
	}
	if (i == -1)
		start = -1;
	printf("%d\n",start);
	return 0;
}
