#include <stdio.h>
#include <stdlib.h>
 
// 输入函数 
void input(int a[], int length) {
	int i;
	for(i = 0; i < length; i++) {
		scanf("%d", &a[i]);
	} 
}

// 交换函数
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
} 

// 两个排序函数 
void sort_high(int a[], int length) {
	int i, j, item = 0, temp = 0;
	// 选择排序 
	for(i = 0; i < length - 1; i++){
		item = i;
		for(j = i + 1; j < length; j++) {
			if(a[j] > a[item]) {
				item = j;
			}
		}
		swap(&a[i], &a[item]);
	} 	
} 

void sort_low(int a[], int length) {
	int i, j, item = 0, temp = 0;
	// 选择排序 
	for(i = 0; i < length - 1; i++){
		item = i;
		for(j = i + 1; j < length; j++) {
			if(a[j] < a[item]) {
				item = j;
			}
		}
		swap(&a[i], &a[item]);
	} 	
}

// 输出函数 
void output(int a[], int length) {
	int k;
	for(k = 0; k < length; k++) {
		printf("%d ", a[k]);
	}	
} 

int main() {
	// 功能一 
	int  a[11];
	int i, j, k;
	int item = 0, temp = 0, length = 10, add = 0;
	// 功能二 
	printf("请输入10名学生的成绩：");
	input(a, length);
	// 功能三 
	sort_high(a, length);
	printf("%d名学生的成绩：", length);
	output(a, length);
	// 功能四 
	printf("\n输入另一位同学的成绩：");
	scanf("%d", &add);
	length += 1; // 长度加 1  
	a[length - 1] = add; 
	sort_high(a, length);
	printf("%d名学生的成绩：", length);
	output(a, length);
	printf("\n");	
	// 功能五 
	sort_low(a, length);
	printf("%d名学生的成绩：", length);
	output(a, length);
	printf("\n");
}

/* 示例 
9 8 7 6 5 4 3 1 2 0
10
*/
