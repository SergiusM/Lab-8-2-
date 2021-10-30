//2.	Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). 
//Упорядочить последовательность по неубыванию первой цифры числа,
//числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию произведения цифр числа,
//числа с одинаковыми первыми цифрами и одинаковыми произведениями цифр дополнительно упорядочить по неубыванию самого числа.
#include <iostream>

#define N 100
int main()
{
	//int mas[N], perv[N], pr[N];
	int* mas = new int[N];
	int* perv = new int[N];
	int* pr = new int[N];
	int n;
	std::cin >> n;
	std::cout << "After" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cin >> mas[i];
		pr[i] = 1;
		int a = mas[i];
		do
		{
			pr[i] = pr[i] * (a % 10);
			a /= 10;
		} while (a > 0);
		a = mas[i];
		while (a > 9)
		{
			a /= 10;
		}
		perv[i] = a;
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (perv[i] > perv[j] || perv[i] == perv[j] && pr[i] > pr[j] ||
				perv[i] == perv[j] && pr[i] == pr[j] && mas[i] > mas[j])
			{
				std::swap(mas[i], mas[j]);
				std::swap(perv[i], perv[j]);
				std::swap(pr[i], pr[j]);
			}
		}
	std::cout << "Before" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << mas[i] << std::endl;
	}
	delete[] mas;
	delete[] perv;
	delete[] pr;
}