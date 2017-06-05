// Arc_proj.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"

#include <iostream>
#include "Sector.h"
#include <string>

using namespace std;

void Print(double smt) {
	cout << "Value: ";
	cout << smt << endl;
}

bool Choose(int s, Sector &sec) {

	double a = 0, b = 0;
	switch (s)
	{
	case 1:
		cout << "Radius change: ";
		cin >> a;
		cout << "Angle change: ";
		cin >> b;
		sec.ChangeSize(a, b);
		cout << "Changed radius and angle!" << endl;
		Print(sec.radius);
		Print(sec.angle);
		break;
	case 2:
		cout << "Area: ";
		Print(sec.Area());
		break;
	case 3:
		cout << "Arc Length:  ";
		Print(sec.ArcLen());
		break;
	case 4:
		cout << "Circle Length: ";
		Print(sec.CircleLen());
		break;
	case 5:
		cout << "Circle d: ";
		Print(sec.CircleD());
		break;
	default:
		return false;
		break;
	}
	cout << " " << endl;
	return true;
}

void ChooseWay(Sector* sector) {
	int value;
	int arnum;
	bool s = true;
	while (s) {
		cout << "1 - Change size,  2 - Area, 3 - Arc Length, 4 - Circle Length, 5 - d ";
		cin >> value;
		cout << "Choose number in array: ";
		cin >> arnum;

		s = Choose(value, sector[arnum - 1]);
	}
}


int main()
{/*
#pragma region  
	cout << "Input n: ";
	int n;
	cin >> n;
	Sector* sec = new Sector[n];

	double rad = 0;

	for (int i = 0; i < n; i++) {
		cout << "Radius:";
		cin >> sec[i].radius;
		while (sec[i].radius < 0) {
			cout << "Try again radius: ";
			cin >> sec[i].radius;
		}
		cout << "Angle:";
		cin >> sec[i].angle;

		while (sec[i].angle < 0 || sec[i].angle > 360) {
			cout << "Try again angle: ";
			cin >> sec[i].angle;
		}

	}
	ChooseWay(sec);
	int a = 0;
	cin >> a;
#pragma endregion */
	char *RemoteAddr = getenv("REMOTE_ADDR");
	char *ContentLength = getenv("CONTENT_LENGTH");
	char *QueryString = getenv("QUERY_STRING"); // GET-запрос 

	int NumBytes = atoi(ContentLength); // вычисляем длину данных — переводим строку в число 
	char *Data = (char *)malloc(NumBytes + 1); // выделяем в свободной памяти буфер нужного размера 
	fread(Data, 1, NumBytes, stdin); // читаем POST-данные из стандартного потока ввода 
	Data[NumBytes] = 0; // добавляем нулевой код в конец строки (конец строки в C) 

	printf("Content-type: text/html\n\n"); // выводим заголовок 

										   // выводим документ 
	printf("<html><body>");
	printf("<h1>Здравствуйте. Мы знаем о вас все!</h1>");
	printf("Ваш IP-адрес: %s<br>", RemoteAddr);
	printf("Количество байтов данных: %d<br>", NumBytes);
	printf("Вот параметры, которые Вы указали: %s<br>", Data);
	printf("А вот то, что мы получили через URL: %s", QueryString);
	printf("</body></html>");
	//cout << "Content-type: text/html\n\nHello World!"; 
	return 0;
}

