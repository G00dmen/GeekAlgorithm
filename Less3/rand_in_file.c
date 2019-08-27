// Записывает массив случайных чисел в файла data.txt
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<time.h>

int main(int argc, char const *argv[])
{
    int* a;
	int N;
    int offset;
    int max_int = 1;
    char f_path[256] = {0};
   // printf("fpath: %s\n", f_path);
    char def_file[]= "./data.txt";                 // Путь файла по умолчанию
   // printf("def_file: %s\n", def_file);
    printf("Enter file name and path (if \"0\", default path \" ./data.txt\"):\n");
    scanf("%s", f_path);
    //printf("scan f_path: %s\n", f_path);
    if (f_path[0] == '0'){
        strncpy(f_path, def_file,256); 
        //printf("copy def_file in f_path: %s\n", f_path);
        }
    FILE *fp;
    if((fp = fopen(f_path,"w")) == NULL)
        printf("! Invalid file path: %s\n", f_path);
	printf("Enter the number of values: ");   // Ввод требуемого числа элементов
	scanf("%i", &N);
    printf("Enter the maximum value for the numbers [1..32767](if \"0\" max = 32767): "); // Масштабирование генерируемых значений
	scanf("%i", &max_int);
        if (max_int == 0)
            max_int = 32767;
    printf("Enter an offset from the minimum value: "); // Ввод смещения генерируемых значений относительно минимального
	scanf("%i", &offset);
    srand(time(NULL));                  
        //fprintf(fp, "%d\n", N);
	a =(int*) malloc(N * sizeof(int)); //Выделение памяти под массив
	int i;
	for (i = 0; i < N; i++)
	{
		a[i] = offset + rand() % max_int;
        printf("%d ", a[i]);
        fprintf(fp,"%d ",a[i]);
	}
        fclose(fp);     // Закрытие файла
        
    return 0;
}

    