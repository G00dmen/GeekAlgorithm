#include<stdio.h>
#include<math.h>
/*
	Кузнецов Алексей <alek-kuzne@yandex.ru>

1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
*/

int decToBin(int n){
	if (n==0)
		return 0;
	else
	{
		decToBin(n/2);
		printf("%d", n%2);
	}
}

/*
2. Реализовать функцию возведения числа a в степень b:
	a. без рекурсии;
	b. рекурсивно;
	c. *рекурсивно, используя свойство чётности степени.
*/
// Функция расчёта целой степени b числа a
// a)

float masPow(float a, int b){
	
float res = 1;
	if (b < 0){
		b = -b;
		a = 1/a;
	}
	while (b > 0){
		res *= a;
		b--;
	}
		return res;
}
// b)

float masRecPow(float a, int b){
			
	if (b == 0)
		return 1;
		
	else if (b > 0)
	{
		return (masRecPow(a,b-1) * a);
	}
	else 
	{
		b = -b;
		a = 1/a;
		return masRecPow(a,b);	
	}
	
}
/*
3. Исполнитель Калькулятор преобразует целое число, записанное на экране. У исполнителя две команды, каждой команде присвоен номер:

    1. Прибавь 1
	2. Умножь на 2
		Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза.
		Сколько существует программ, которые число 3 преобразуют в число 20?
		а) с использованием массива; б) с использованием рекурсии.
*********************************************************************************************************
		 Откровенно говоря, суть этого задания я не понял!
		 Возможны различные варианты программ, как с использованием циклов, так и рекурсии, так и совместно циклов с рекурсиями.
		 Что нужно сделать? Реализовать эту программу-калькулятор? Либо нужно попытаться выделить все возможные алгоритмы
		 реализации этой программы?
*********************************************************************************************************
*/

int main(){
// Ввод и вызов функции задания №1
	int num, a, b;
	
	printf("Enter number: ");
	scanf("%d", &num);
	printf("Number in bin = 0b");
	decToBin(num);
	printf("\n");

// Ввод и вызов функции задания №2 
// a)
	printf("Enter number a: ");
	scanf("%d", &a);
	printf("Enter number b: ");
	scanf("%d", &b);
	printf("a ^ b = %f", masPow(a,b));
	printf("\n");
// b)
	printf("Enter number a: ");
	scanf("%d", &a);
	printf("Enter number b: ");
	scanf("%d", &b);
	printf("a ^ b = %f", masRecPow(a,b));
	printf("\n");
	return 0;
}