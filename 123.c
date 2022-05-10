#include<stdio.h>
#include<stdbool.h>
#define MaxSize 50
typedef struct{
	int data[MaxSize];
	int length;
}SqList;
void ListInit(SqList *L){
	L->length = 0;
	for (int i = 0; i < MaxSize; i++)
		L->data[i] = 0;

}
bool ListInsert(SqList* L, int i, int e) {
	if (i<1 || i>L->length + 1)
	{

		return false;
	}
	if (L->length >= MaxSize)
		return false;
	for (int j = L->length; j >= i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}
void Delete_X(SqList *L,int x) {
	int k = 0;
	for (int i = 0; i < L->length; i++) {
		if (L->data[i] != x) {
			L->data[k] = L->data[i];
			k++;
		}
	}
	L->length = k;
}
void List_Printf(SqList* L) {
	for (int i = 0; i < L->length; i++)
		printf("%d  ", L->data[i]);
	printf("\n顺序表的长度为%d\n\n\n", L->length);
}
int main()
{
	SqList list;
	SqList *L=&list;
	ListInit(L);
	ListInsert(L, 1, 5);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 2);
	ListInsert(L, 4, 10);
	int value=0;
	int* a = &value;
	Delete_X(L,2);
	List_Printf(L);
	system("pause");
	return 0;
}
