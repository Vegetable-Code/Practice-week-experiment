#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX_NUM 100
// 输入函数 
int intput(int arr[], int len) {
	for(int i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}
}

// 交换函数 
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
} 

// 排序函数 
int *sort1(int a[], int len, char style) {
	int *p = a;
	int i, j, temp;
	// 升序 
	if(style == 'a') {
		for(j = 0; j < len - 1; j++) {
			for(i = 0; i < len - 1; i++) {
				if(p[i] < p[i + 1]) {
					swap(&p[i], &p[i + 1]);
				}
			}
		}	
	}
	// 降序 
	if(style == 'd') {
		for(j = 0; j < len - 1; j++) {
			for(i = 0; i < len - 1; i++) {
				if(p[i] > p[i + 1]) {
					swap(&p[i], &p[i + 1]);
				}
			}
		}
	}
	return p; 
} 

// 通用输出函数 
int *output(int a[], int len, char style, int *(*fun)(int a[], int n, char style)) {
	int *p = NULL;
	p = (*fun)(a, len, style);
	printf("\n%d名同学的成绩为：", len);
	for(int i = 0; i < len; i++) {
		printf("%d ", *(p + i));
	}
	printf("\n\n********************-----输出成功-----********************\n");
	return p;
}

int main() {
	char style;
	int n, a[10], b[MAX_NUM];
	
	printf("请输入10名同学的成绩：");
	intput(a, 10);
	int len = sizeof(a) / sizeof(a[0]); // 获取长度 
	fflush(stdin); // 清空scanf()缓冲区 
	printf("\n请选择你想要的排序方式："); 
	scanf("%c", &style);
	output(a, len, style, sort1);
	
	printf("\n请输入总人数（人数应当小于%d）：", MAX_NUM);
	scanf("%d", &n);
	printf("\n请输入%d名同学的成绩：", n);
	len = n;
	intput(b, len);
	fflush(stdin); // 清空scanf()缓冲区
	printf("\n请选择你想要的排序方式："); 
	scanf("%c", &style);
	output(b, len, style, sort1);
} 
