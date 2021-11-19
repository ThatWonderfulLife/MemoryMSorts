#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca_elementos(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void printaLista(int aList[], int listSize) {
	for (int idx = 0; idx < listSize; idx++) {
		printf("%d ", aList[idx]);
	}
		printf("\n");
}

/* Primeira Exigência: BUBBLE SORT (método da bolha) */
void bubble_Sort(int a[], int n){
	int i, j;
	for (i = 0; i < n ; i++)
		for (j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				troca_elementos(&a[j], &a[j + 1]);
}
/* FIM Primeira Exigência: BUBBLE SORT*/

/* Segunda Exigência: QuickSort (método da troca e partição)*/
int partition(int array[], int low, int high) {
	int pivot = array[high];
	int i = (low - 1);

	for (int j = low; j < high; j++) {
		if (array[j] <= pivot) {
			i++;
			troca_elementos(&array[i], &array[j]);
		}}
	troca_elementos(&array[i + 1], &array[high]);
	return (i + 1);
}

void quickSort(int array[], int low, int high) {
	if (low < high) {
		int pi = partition(array, low, high);
		quickSort(array, low, pi - 1);
		quickSort(array, pi + 1, high);
	}}
/* Fim da Segunda Exigência: QuickSort (método da troca e partição)*/

/* Terceira Exigência: InsertionSort (método da inserção direta) */
void insertionSort(int array[], int size) {
	for (int step = 1; step < size; step++) {
		int key = array[step];
		int j = step - 1;
		while (key < array[j] && j >= 0) {
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}}
 /* Fim da Terceira Exigência: InsertionSort (método da inserção direta)*/

/* Quarta Exigência: BinaryInsertionSort (método da inserção direta binária)*/
 int binarySearch(int a[], int item, int low, int high){
    if (high <= low)
        return (item > a[low])?  (low + 1): low;
    int mid = (low + high)/2;
    if(item == a[mid])
        return mid+1;
    if(item > a[mid])
        return binarySearch(a, item, mid+1, high);
    return binarySearch(a, item, low, mid-1);
}
 
void insertionSortBinary(int a[], int n){
    int i, loc, j, k, selected;

    for (i = 1; i < n; ++i)
    {
        j = i - 1;
        selected = a[i];
        loc = binarySearch(a, selected, 0, j);
        while (j >= loc){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }}
 /* Fim da Quarta Exigência: BinaryInsertionSort (método da inserção direta binária)*/

/* Quinta Exigência: SelectionSort (método da seleção direta) */
void selectionSort(int arr[], int n){
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++){
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		troca_elementos(&arr[min_idx], &arr[i]);
	}}
 /* Fim da Quinta Exigência: SelectionSort (método da seleção direta)*/

/* Sexta Exigência: HeapSort (método da seleção em árvore)*/
void heapify(int arr[], int n, int i) {
	int max = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;

	if (leftChild < n && arr[leftChild] > arr[max])
		max = leftChild;

	if (rightChild < n && arr[rightChild] > arr[max])
		max = rightChild;

	if (max != i) {
		troca_elementos(&arr[i], &arr[max]);
		heapify(arr, n, max);
	}}
void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		troca_elementos(&arr[0], &arr[i]);

		heapify(arr, i, 0);
	}}
 /* Fim da Sexta Exigência: HeapSort (método da seleção em árvore)*/

/* Sétima Exigência: MergeSort (método da intercalação)*/
 
void merge_sort(int i, int j, int a[], int aux[]) {
	if (j <= i) {
		return;
	}
	int mid = (i + j) / 2;

	merge_sort(i, mid, a, aux);
	merge_sort(mid + 1, j, a, aux);

	int pointer_left = i;
	int pointer_right = mid + 1;
	int k;

	for (k = i; k <= j; k++) {
		if (pointer_left == mid + 1) { 
			aux[k] = a[pointer_right];
			pointer_right++;
		}
		else if (pointer_right == j + 1) { 
			aux[k] = a[pointer_left];
			pointer_left++;
		}
		else if (a[pointer_left] < a[pointer_right]) {
			aux[k] = a[pointer_left];
			pointer_left++;
		}
		else {
			aux[k] = a[pointer_right];
			pointer_right++;
		}}

	for (k = i; k <= j; k++) {
		a[k] = aux[k];
	}}
/* Fim da Sétima Exigência: MergeSort (método da intercalação) */

/* Oitava Exigência: BucketSort (método da distribuição de chave) */
struct bucket{
    int count;
    int* value;
};
 
int compareIntegers(const void* first, const void* second){
    int x = *((int*)first), y =  *((int*)second);
    if (x == y){
        return 0;
    }
    else if (x < y){
        return -1;
    }
    else{
        return 1;
    }}
 
void bucketSort(int array[],int n){
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++){
        buckets[i].count = 0;
        buckets[i].value = (int*)malloc(sizeof(int) * n);
    }
    
    for (i = 0; i < n; i++){
        if (array[i] < 0){
            buckets[0].value[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10) {
            buckets[2].value[buckets[2].count++] = array[i];
        }
        else {
			buckets[1].value[buckets[1].count++] = array[i];
		}}
    for (k = 0, i = 0; i < 3; i++){
        qsort(buckets[i].value, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++){
            array[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
        free(buckets[i].value);
    }}
 /* Fim da Oitava Exigência: BucketSort (método da distribuição de chave) */

int main(){
	while (1){
		int tamanhoLista;
		printf("Qual o tamanho do Array para testar?\n");
		srand ( time(NULL) );
		scanf("%d", &tamanhoLista);
		int arrayOriginal[tamanhoLista], aux[tamanhoLista], listaTeste[tamanhoLista];
		
		for(int i = 0; i < tamanhoLista; i++){
			arrayOriginal[i] = rand()%1001;
		}
		
		printf("Array gerado: ");
		printaLista(arrayOriginal, tamanhoLista);
		
		int algoritmoRodar;
		clock_t t;
		
		while(1){
			memcpy(listaTeste, arrayOriginal, sizeof(arrayOriginal)+1);
			printf("Qual o algoritmo que você deseja testar?\n0 - Sair\n");
			printf("1 - Bubble Sort\n");
			printf("2 - Quick Sort\n3 - Insertion Sort\n4 - Binary Insertion Sort\n");
			printf("5 - Selection Sort\n6 - Heap Sort\n7 - Merge Sort\n8 - Bucket Sort\n");
			printf("9 - Gerar outro Array\n");
			scanf("%d", &algoritmoRodar);
			switch (algoritmoRodar){
				case 0:
					exit(0);
				
				case 1:
					printf("Lista sem alteração: \n");
					printaLista(listaTeste, tamanhoLista);
					t = clock();
					bubble_Sort(listaTeste, tamanhoLista);
					t = clock() - t;
					printf("Lista alterada pelo Bubble Sort: \n");
					printaLista(listaTeste, tamanhoLista);
					printf("Tempo de execucao: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
					break;

				case 2:
					printf("Lista sem alteração: \n");
					printaLista(listaTeste, tamanhoLista);
					t = clock();
					quickSort(listaTeste, 0, tamanhoLista);
					t = clock() - t;
					printf("Lista alterada pelo Quick sort: \n");
					printaLista(listaTeste, tamanhoLista);
					printf("Tempo de execucao: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
					break;

				case 3:
					printf("Lista sem alteração: \n");
					printaLista(listaTeste, tamanhoLista);
					t = clock();
					insertionSort(listaTeste, tamanhoLista);
					t = clock() - t;
					printf("Lista alterada pelo Insertion sort: \n");
					printaLista(listaTeste, tamanhoLista);
					printf("Tempo de execucao: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
					break;
				
				case 4:
					printf("Lista sem alteração: \n");
					printaLista(listaTeste, tamanhoLista);
					t = clock();
					insertionSort(listaTeste, tamanhoLista);
					t = clock() - t;
					printf("Lista alterada pelo BinaryInsertionSort: \n");
					printaLista(listaTeste, tamanhoLista);
					printf("Tempo de execucao: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
					break;
				
				case 5:
					printf("Lista sem alteração: \n");
					printaLista(listaTeste, tamanhoLista);
					t = clock();
					selectionSort(listaTeste, tamanhoLista);
					t = clock() - t;
					printf("Lista alterada pelo Selection sort: \n");
					printaLista(listaTeste, tamanhoLista);
					printf("Tempo de execucao: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
					break;
				
				case 6:
					printf("Lista sem alteração: \n");
					printaLista(listaTeste, tamanhoLista);
					t = clock();
					heapSort(listaTeste, tamanhoLista);
					t = clock() - t;
					printf("Lista alterada pelo Heap Sort: \n");
					printaLista(listaTeste, tamanhoLista);
					printf("Tempo de execucao: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
					break;
				
				case 7:
					printf("Lista sem alteração: \n");
					printaLista(listaTeste, tamanhoLista);
					t = clock();
					merge_sort(0, tamanhoLista, listaTeste, aux);
					t = clock() - t;
					printf("Lista alterada pelo Merge Sort: \n");
					printaLista(listaTeste, tamanhoLista);
					printf("Tempo de execucao: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
					break;
				
				case 8:
					printf("Lista sem alteração: \n");
					printaLista(listaTeste, tamanhoLista);
					t = clock();
					bucketSort(listaTeste,tamanhoLista);
					t = clock() - t;
					printf("Lista alterada pelo Bucket Sort: \n");
					printaLista(listaTeste, tamanhoLista);
					printf("Tempo de execucao: %lf milissegundos\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
					break;				
				case 9:
					main();}}}
	return 0;
}