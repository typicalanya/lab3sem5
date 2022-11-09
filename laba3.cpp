#include "Head.h"

using namespace std;

void insertionSort(int arr[], int length_array) { // сортировка вставками
	int counter = 0;
	for (int i = 1; i < length_array; i++) {
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			counter++;
			int tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
		}
	}
	cout << "Отсортированный массив: " ;
	for (int i = 0; i < length_array; i++) cout << arr[i] << " "; //вывод массива
}


void choicesSort(int arr[], int length_array) // сортировка выбором
    {
        for (int repeat_counter = 0; repeat_counter < length_array; repeat_counter++)
        {
            int temp = arr[0]; // временная переменная для хранения значения перестановки
            for (int element_counter = repeat_counter + 1; element_counter < length_array; element_counter++)
            {
                if (arr[repeat_counter] > arr[element_counter])
                {
                    temp = arr[repeat_counter];
                    arr[repeat_counter] = arr[element_counter];
                    arr[element_counter] = temp;
                }
            }
        }
		cout << "Отсортированный массив: " ;
		for (int i = 0; i < length_array; i++) cout << arr[i] << " "; //вывод массива
    }

void bubbleSort(int arr[], int length_array) // пузырьковая сортировка
{
	for (int i = 0; i < length_array; i++) {
		for (int j = 0; j < (length_array - 1); j++) {
			if (arr[j] > arr[j + 1]) {
				int b = arr[j]; // создали дополнительную переменную
				arr[j] = arr[j + 1]; // меняем местами
				arr[j + 1] = b; // значения элементов
			}
		}
	}
	cout << "Отсортированный массив: ";
	for (int i = 0; i < length_array; i++) cout << arr[i] << " "; //вывод массива
}

int i, j,  d, schet;
void ShellSort(int arr[], int length_array) //сортировка Шелла
{
	d = length_array;
	d = d / 2;
	while (d > 0)
	{
		for ( i = 0; i < length_array - d; i++)
		{
			 j = i;
			while (j >= 0 && arr[j] > arr[j + d])
			{
				 schet = arr[j];
				arr[j] = arr[j + d];
				arr[j + d] = schet;
				j--;
			}
		}
		d = d / 2;
	}
	cout << "Отсортированный массив: ";
	for ( int i = 0; i < length_array; i++) cout << arr[i] << " "; //вывод массива
}

void quickSort(int arr[], int length_array) { // быстрая сортировка
	//Указатели в начало и в конец массива
	int i = 0;
	int j = length_array - 1;

	//Центральный элемент массива
	int mid = arr[length_array / 2];

	//Делим массив
	do {
		//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
		//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
		while (arr[i] < mid) {
			i++;
		}
		//В правой части пропускаем элементы, которые больше центрального
		while (arr[j] > mid) {
			j--;
		}

		//Меняем элементы местами
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	//Рекурсивные вызовы, если осталось, что сортировать
	if (j > 0) {
		//"Левый кусок"
		quickSort(arr, j + 1);
	}
	if (i < length_array) {
		//"Прaвый кусок"
		quickSort(&arr[i], length_array - i);
	}
	cout << "Отсортированный массив: ";
	for (int i = 0; i < length_array; i++) cout << arr[i] << " "; //вывод массива
}

int main() {
	setlocale(LC_ALL, "Russian");

	const int n=20;
	int Arr[n] = {10,1,56,7,8, 64, 89, 20, 3, 5, 46, 34, 23, 87, 90, 17,81,52,39,80};
	
	int Numb = 0;
	cout << "-----------------------" << endl;
	cout << "Доступные команды: " << endl;
	cout << "0 - Выйти из программы;" << endl;
	cout << "1 - Сортировка вставками;" << endl;
	cout << "2 - Сортировка выбором;" << endl;
	cout << "3 - Пузырьковая сортировка;" << endl;
	cout << "4 - Сортировка Шелла;" << endl;
	cout << "5 - Быстрая сортировка;" << endl;
	cout << "-----------------------" << endl;
	cout << "Введите номер команады, чтобы ее выполнить : ";
	cin >> Numb;

	while (Numb != 0)
	{
		switch (Numb)
		{
		case 0: {
			cout << "Спасибо, что воспользовались нашей программой" << endl;
			break;
		}
		case 1: { //сортировка вставками
			cout <<endl<< "Исходный массив: ";
			for (i = 0; i < n; i++) {
				cout << Arr[i] << " ";
			}
			cout << endl;
			clock_t start = clock();
			insertionSort(&Arr[0], n);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl;
			printf("The time: %f seconds\n", seconds);
			Numb = 0;
			break;
		}
		case 2: {// сортировка выбором
			cout <<endl<< "Исходный массив: " ;
			for (i = 0; i < n; i++) {
				cout << Arr[i] << " ";
			}
			cout << endl;
			clock_t start = clock();
			choicesSort(&Arr[0], n);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl;
			printf("The time: %f seconds\n", seconds);
			Numb = 0;
			break;
		}
		case 3: {// пузырьковая сортировка
			cout <<endl<< "Исходный массив: " ;
			for (i = 0; i < n; i++) {
				cout << Arr[i] << " ";
			}
			cout << endl;
			clock_t start = clock();
			bubbleSort(&Arr[0], n);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl;
			printf("The time: %f seconds\n", seconds);
			Numb = 0;
			break;
		}
		case 4: {// сортировка Шелла
			cout <<endl<< "Исходный массив: ";
			for (i = 0; i < n; i++) {
				cout << Arr[i] << " ";
			}
			cout << endl;
			clock_t start = clock();
			ShellSort(&Arr[0], n);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl;
			printf("The time: %f seconds\n", seconds);
			Numb = 0;
			break;
		}
		case 5: {// быстрая сортировка
			cout <<endl << "Исходный массив: " ;
			for (i = 0; i < n; i++) {
				cout << Arr[i] << " ";
			}
			cout << endl;
			clock_t start = clock();
			quickSort(&Arr[0], n);
			clock_t end = clock();
			double seconds = (double)(end - start) / CLOCKS_PER_SEC;
			cout << endl;
			printf("The time: %f seconds\n", seconds);
			Numb = 0;
			break;
		}
		}
	}
}
