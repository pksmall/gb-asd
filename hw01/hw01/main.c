/*
* @author Pavel Korzhenko
* @version 0.1
*
*/

// Visual Studio fix scanf
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

/*
* 1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h); где m-масса тела в
*	килограммах, h - рост в метрах.
*/
void task01() {
	int m;
	float h, result;
	printf("Введите массу и рост человекa (ex. 95 1.8):");
	scanf("%d %f", &m, &h);
	result = m / (h * h);
	printf("Индекс массы тела: %.2f\n", result);
}

/*
* 2. Найти максимальное из четырех чисел. Массивы не использовать.
*/
void task02(int numbers) {
	int number, min, max;
	int count = 1;

	while (numbers > 0) {
		number = numbers % 10;
		numbers /= 10;

		if (count == 1) {
			min = number;
			max = number;
		}
		else if (number < min) {
			min = number;
		}
		else if (number > max) {
			max = number;
		}
		count++;
	}
	printf("Min: %d Max: %d\n", min, max);
}

/*
* 3. Написать программу обмена значениями двух целочисленных переменных :
*	a.с использованием третьей переменной;
*	b. *без использования третьей переменной.
*/
void task03(int x, int y) {
	int a;

	printf("Before Swapping: x = %d, y = %d\n", x, y);
	a = x;
	x = y;
	y = a;

	printf("After Swapping: x = %d, y = %d\n", x, y);

	x = x + y;  // x now becomes 15
	y = x - y;  // y becomes 10
	x = x - y;  // x becomes 5

	printf("After Swapping: x = %d, y = %d\n", x, y);

	x = x ^ y;  // x now becomes 15 (1111)
	y = x ^ y;  // y becomes 10 (1010)
	x = x ^ y;  // x becomes 5 (0101)

	printf("After Swapping: x = %d, y = %d\n", x, y);
}

/*
* 4. Написать программу нахождения корней заданного квадратного уравнения.
*/
void task04(int a, int b, int c) {
	long discriminant = b*b - 4 * a*c;

	double x1 = (-b + sqrt(discriminant)) / (2 * a);
	double x2 = (-b - sqrt(discriminant)) / (2 * a);

	if (discriminant > 0) {
		printf("D: %ld; D > 0; 2 корня:\n", discriminant);
		printf("x1 = %.2lf\n", x1);
		printf("x2 = %.2lf\n", x2);
	}
	else if (discriminant == 0) {
		double x = -1.*b / (2 * a);
		printf("D: %ld; D = 0; 1 корень:\n", discriminant);
		printf("x = %.2lf\n", x);
	}
	else if (discriminant < 0) {
		printf("D: %ld; D < 0; нет корней.\n", discriminant);
	}
}

/*
* 5. С клавиатуры вводится номер месяца.Требуется определить, к какому времени года он относится.
*/
void task05() {
	int m;

	printf("Введите месяц:");
	scanf("%d", &m);

	if (m >= 3 && m <= 5)
		printf("весна\n");
	if (m >= 6 && m <= 8)
		printf("лето\n");
	if (m >= 9 && m <= 11)
		printf("осень\n");
	if ((m >= 1 && m <= 2) || m == 12)
		printf("зима\n");
}

/*
*6. Ввести возраст человека(от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет».
*/
void task06() {
	int m;

	printf("Введите возраст человека:");
	scanf("%d", &m);

	if (m >= 11 && m < 21) {
		printf(" %d лет\n", m);
	}
	else if (m % 10 == 1) {
		printf(" %d год\n", m);
	}
	else if ((m > 21) && ((m % 10 == 2) || (m % 10 == 3) || (m % 10 == 4)) || (m > 1 && m < 5)) {
		printf(" %d годa\n", m);
	}
	else {
		printf(" %d лет\n", m);
	}
}

/*
* 7. С клавиатуры вводятся числовые координаты двух полей шахматной доски(x1, y1, x2, y2).Требуется определить, относятся
*	ли к поля к одному цвету или нет.
*/
void task07() {
	int x1, y1, x2, y2;

	printf("Введите чесловые координаты двух полей шахматной доски (ex x1 y1 x2 y2):");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	if ((x1 + y1) % 2 == (x2 + y2) % 2) {
		printf("Поля одного цвета.\n");
	}
	else {
		printf("Поля разных цветов.\n");
	}
}

/*
* 8. Ввести a и b и вывести квадраты и кубы чисел от a до b.
*/
void task08() {
	int a, b;
	int s, q;

	printf("Введите два целых числа (ex. a b, but a < b):");
	scanf("%d %d", &a, &b);
	for (int i = a; i <= b; i++) {
		s = i * i;
		q = i * i * i;
		printf("%d в квадрате %d\n", i, s);
		printf("%d в кубе %d\n", i, q);
	}

}
/*
* 9. Даны целые положительные числа N и K.Используя только операции сложения и вычитания, найти частное от деления
*  нацело N на K, а также остаток от этого деления.
*/
void task09() {
	int a, b;
	int s = 0, q; //s - частное q - остаток

	printf("Введите два целых числа (ex. a b but a > b):");
	scanf("%d %d", &a, &b);
	if (a > 0 && b > 0) {
		while (a >= b) {
			s += 1;
			a -= b;
		}
		q = a;
	}
	printf("Частное: %d остаток: %d", s, q);

}

/*
* 10. Дано целое число N(> 0).С помощью операций деления нацело и взятия остатка от деления определить, имеются ли в
*	   записи числа N нечетные цифры.Если имеются, то вывести True, если нет — вывести False.
*/
void task10() {
	int a;
	bool b = false;

	printf("Введите число (ex. a but a > 0):");
	scanf("%d", &a);
	while (a != 0 && !b) {
		if (!((a % 10) % 2)) {
			a = a / 10;
		}
		else {
			b = true;
		}
	}
	printf("A = %s\n", b ? "true" : "false");
}

/*
* 11. С клавиатуры вводятся числа, пока не будет введен 0. Подсчитать среднее арифметическое всех положительных четных
*	   чисел, оканчивающихся на 8.
*/
void task11() {
	int a, sum = 0;

	do {
		printf("Введите число или 0 для выхода: ");
		scanf("%d", &a);
		if (a > 0 && (a % 2) == 0 && (a % 10) == 8) {
			sum += a;
		}
	} while (a != 0);

	printf("Sum = %d\n", sum);
}

/*
* 12. Написать функцию нахождения максимального из трех чисел.
*/
void task12() {
	int a, b, c, max;

	printf("Введите 3 числa (ex. a b c): ");
	scanf("%d %d %d", &a, &b, &c);
	if (a > b) {
		max = a;
	}
	else {
		max = b;
	}
	if (c > max) {
		max = c;
	}
	printf("Max is %d\n", max);
}

/*
* 13. * Написать функцию, генерирующую случайное число от 1 до 100.
*	 с использованием стандартной функции rand()
*   без использования стандартной функции rand()
*/
void task13() {
	srand(time(NULL));
	int r = (rand() % 100) + 1;
	printf("Rand : %d\n", r);
	r = ((r * 7621) + 1) % 100;
	if (r == 0) { r = 1; }
	printf("MyRand : %d\n", r);
}

/*
* TODO:
* 14. * Автоморфные числа.Натуральное число называется автоморфным, если оно равно последним цифрам своего квадрата.
*   Например, 25 \ :sup: 2 = 625. Напишите программу, которая вводит натуральное число N и выводит на экран все
*   автоморфные числа, не превосходящие N.
*/
int main() {
	system("chcp 65001");

	//task01();
	//task02(5328);
	//task03(5, 10);
	//task04(2, 6, 1);
	//task05();
	//task06();
	//task07();
	//task08();
	//task09();
	//task10();
	//task11();
	//task12();
	task13();

	return 0;
}
