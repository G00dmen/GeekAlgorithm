// Алексей Кузнецов <alek-kuzne@yandex.ru>
// "Алгоритмы и структуры данных. Поиск в массиве. Простые сортиовки"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
/*
1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения
    оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают
    количество операций.

2. *Реализовать шейкерную сортировку.

3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
    Функция возвращает индекс найденного элемента или -1, если элемент не найден.

4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью
    алгоритма.
*/

typedef struct {
    int* name;
    int size;
} ArryInt;

void printArry(int*,int);
void swap(int*, int*);
ArryInt arry_from_file(char*);

int linSearch(int*, int, int);
int barrierSearch(int*, int, int);
int binIntSearch(int*, int, int);

void bubbleSort(int*, int);
void upgBubbleSort(int*,int);
void shakerSort(int *, int);

int main()
{
    char f_path[] = "./data.txt";
    ArryInt mass;      
    mass = arry_from_file(f_path);
    printf("N = %d\n", mass.size);
        
    printArry(mass.name,mass.size);

    int value;
	printf("\n\nInput value for search:");
	scanf("%d", &value);

  	linSearch(mass.name, mass.size, value);
    barrierSearch(mass.name, mass.size, value); 
    
    bubbleSort(mass.name, mass.size);  
    mass = arry_from_file(f_path);
    upgBubbleSort(mass.name, mass.size);
    mass = arry_from_file(f_path);
    shakerSort(mass.name, mass.size);
    puts("\nSearch after sorting:");
    binIntSearch(mass.name, mass.size, value);
    linSearch(mass.name, mass.size, value);
    barrierSearch(mass.name, mass.size, value);
    
    
    free(mass.name);
        
    return 0;
}


//***********************************************************************************************
//  Функция линейного поиска в массиве
//***********************************************************************************************

int linSearch(int *arr, int n, int value){
    puts("\nLINEAR SEARCH: ");	
	int i = 0;
	while (i < n && arr[i] != value) i++;
    printf("%d iterations ", i);

	if (i != n){
		printf("Index:%d Value:%d\n", i, arr[i]);
		return i;
	}
	else{
		puts("Value not found\n");
		return -1;
	}
}

//***********************************************************************************************
//  Функция поиска с барьером
//***********************************************************************************************

int barrierSearch(int *arr, int n, int value){
	puts("\nBARRIER SEARCH: ");
    arr[n] = value;
    int i = 0;
    while (arr[i] != value) i++;          // Алгоритм поиска
    printf("%d iterations ", i);
	if (i != n){
		printf("Index:%d Value:%d\n", i, arr[i]);
		return i;
	}
	else{
		puts("Value not found\n");
		return -1;
	}
		
}

//***********************************************************************************************
//  Пузырьковая сортировка
//***********************************************************************************************

void bubbleSort(int *arr, int n){
    puts("\n*ORIGINAL BUBBLE SORT*");
    int swap_count = 0;
    int rounds_counter = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++, rounds_counter++)
            if (arr[j] > arr[j + 1])
            {
                swap(arr+j, arr+j+1);
                swap_count++;
            }
    
    printArry(arr,n);
    printf("\nswaps = %d, rounds = %d\n", swap_count, rounds_counter);
}

//***********************************************************************************************
//  Улучшенная пузырьковая сортировка
//***********************************************************************************************

void upgBubbleSort(int *arr, int n){
    puts("\n*UPGRADED BUBBLE SORT*");
    int swap_count = 0;
    int rounds_counter = 0;
    int nswap;
    for(int i = 0; i < n; i++){
        nswap = 0;
        for(int j = 0; j < (n - 1) - i; j++, rounds_counter++)
            if (arr[j] > arr[j + 1])
            {
                swap(arr+j, arr+j+1);
                nswap++;
                swap_count++;
            }
        if(!nswap) break;
    }     
    
    printArry(arr,n);
    printf("\nswaps = %d, rounds = %d\n", swap_count, rounds_counter);
}

//***********************************************************************************************
//  Шейкерная сортировка сортировка
//***********************************************************************************************

void shakerSort(int *arr, int n){
    puts("\n*SHAKER SORT*");
    int swap_count = 0;
    int rounds_counter = 0;
    int nswap;
    for(int i = 0; i < n; i++){
        int j, k;
        nswap = 0;
        for(j = i; j < (n - 1) - i; j++, rounds_counter++)
            if (arr[j] > arr[j + 1])
            {
                swap(arr+j, arr+j+1);
                nswap++;
                swap_count++;
            }

        if(!nswap) break;
        nswap = 0;

        for(k = j; k > i; k--, rounds_counter++)
            if (arr[k] < arr[k - 1])
            {
                swap(arr+k, arr+k-1);
                nswap++;
                swap_count++;
            }
        if(!nswap) break;
    }     
    
    printArry(arr,n);
    printf("\nswaps = %d, rounds = %d\n", swap_count, rounds_counter);
}
 
//**********************************************************************************************
// Бинарный поиск в отсортированном массиве
//**********************************************************************************************

int binIntSearch(int *arr, int n, int value){
    puts("\nBINARY SEARCH: ");
    int count = 0;
    int L = 0, R = n - 1;
    int m = L + (R - L) / 2;
    while(L <= R && arr[m] != value)
    {
        if (arr[m] < value) 
            L = m + 1;
        else 
            R = m - 1;
        m = L + (R - L) / 2;
        count++;
    }
    printf("%d iterations ", count);
    if (arr[m] == value){
        printf("Index:%d Value:%d\n", m, arr[m]);
        return m;   
    }    
    else{
        puts("Value not found\n");
        return -1;
    }
}

//***********************************************************************************************
//***********************************************************************************************

// Функция вывода массива

void printArry(int *a, int n){
    for(int i=0; i < n; i++)
    printf(" %d:%d ", i, a[i]);
   }

//  Функция swap

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

//  Функция читает данные из файла ./data.txt в массив

ArryInt arry_from_file(char *file_p){
    ArryInt arI;
    arI.size = 0;
    char def_file[]= "./data.txt";  
    
    if (file_p[0] == '0'|| file_p == NULL)
        strncpy(file_p, def_file,256);
    
    FILE *fp;    
    if((fp = fopen(file_p,"r")) == NULL){
        printf("! Invalid file path: %s\n", file_p);
        arI.name = NULL;
        arI.size = 0;
        return arI;
        }
    int s;  
    while (fscanf(fp, "%d",  &s) != EOF){   
        if(!fp) break;
        arI.size++;
        }
    rewind(fp);

    arI.name = (int*) malloc(arI.size * sizeof(int));
     
    for (int i=0; i < arI.size; i++)
        fscanf(fp, "%d", arI.name+i);
        
    fclose(fp);
    return arI;
}