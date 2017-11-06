/*
* @author Pavel Korzhenko
* @version 0.3 2017/10/31
* @task 02
* @mark
*/

// Visual Studio fix scanf
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
* 1. Реализовать функцию перевода из 10 системы в двоичную используя рекурсию.
*/
void task01(int x, char *result)
{
	if (x)
	{
		task01(x / 2, result);
		strcat(result, (x % 2) ? "1" : "0");
	}
}

/*
* 2. Реализовать функцию возведения числа a в степень b:
a. без рекурсии;
b. рекурсивно;
c. *рекурсивно, используя свойство чётности степени.
*/

float task02(int a, int n, int f)
{
	float retval = 1;

	switch (f) {
		// a
	case 0:
		for (int i = 0; i < n; i++) retval *= a;
		break;
		// b
	case 1:
		if (!n) return retval;
		return a*task02(a, --n, 1);
		break;
		// c
	case 2:
		if (!n) return retval;
		if (n % 2) return a*task02(a, n - 1, 2);
		return task02(a * a, n / 2, 2);
		break;
	}
	return retval;
}

/*
* 3. Исполнитель Калькулятор преобразует целое число, записанное на экране.
* У исполнителя две команды, каждой команде присвоен номер :
*		1. Прибавь 1
*		2. Умножь на 2
* Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза.
* Сколько существует программ, которые число 3 преобразуют в число 20 ?
*		а) с использованием массива;
*		б) с использованием рекурсии.
*/
int task03a(int n, int c)
{
	int *a = calloc((size_t)c, sizeof(int));
	a[n] = 1;
	//printf("\n");
	for (int i = n + 1; i <= c; i++) {
		// == 0 && i/2 >= n
		if (i % 2) {
			//printf("i=%d > %d + %d = %d\n", i, a[i - 1], a[i / 2], a[i - 1] + a[i / 2]);
			a[i] = a[i - 1];
		}
		else {
			//printf("i=%d < %d - 1\n",i, a[i-1]);
			a[i] = (a[i - 1] + a[i / 2]);
		}
		//printf("%d = %d ", i, a[i]);
	}
	/* printf("\n\n");
	for (int i = n; i < c; i++)
	printf("%d = %d ", i, a[i]);
	printf("\n"); */
	//return a[c / 2] + a[c - 1];
	return a[c];
}

int task03b(int n, int k)
{
	if (k == 0) return 0;
	if (n == k) return 1;
	if (k % 2) {
		return task03b(n, k - 1);
	}
	else {
		return task03b(n, k / 2) + task03b(n, k - 1);
	}
}

int main() {
	int b;

	system("chcp 65001");

	// task01
	char res[20] = "b";
	printf("Number to bin: ");
	scanf("%d", &b);
	task01(b, res);
	printf("%d = %s\n", b, res);

	// task02
	int a = 5;
	b = 4;
	// a)
	printf("%d ^ %d: %.0f\n", a, b, task02(a, b, 0));
	// b)
	printf("%d ^ %d: %.0f\n", a, b, task02(a, b, 1));
	// c)
	printf("%d ^ %d: %.0f\n", a, b, task02(a, b, 2));

	// task03
	a = 3;
	b = 20;
	printf("a) Programs %d to %d = %d\n", a, b, task03a(a, b));

	printf("b) Programs %d to %d = %d\n", a, b, task03b(a, b));

	return 0;
}
