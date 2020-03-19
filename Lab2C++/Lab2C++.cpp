// Lab2C++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <Windows.h>
#define garbage_collector() cin.ignore(cin.rdbuf()->in_avail())
using namespace std;
struct Address {
    int PostIndex;
    char Country[30];
    char Region[30];
    char District[30];
    char Town[30];
    char Street[30];
    int House;
    int Flat;
};

struct CarOwner {
    char FirstName[25];
    char SecondName[25];
    char LastName[25];
	char Sex[7];
	int Age;
    int telephone;
    Address adress;
    char mark[30];
    int NumberCar;
    int NumberPassport;

};

CarOwner InitCarOwner();
CarOwner* InitArray(int Dimension);
void DisplayArray(CarOwner *MassiveStruct,int Dimension);
void DisplayCarOwner(CarOwner);
void SortFirstName(CarOwner*, int);

int main(int argc, char* argv)
{
   
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "");

    int Dimension;
	bool begin = true;
	char SexTag[7];
	int LowAge, UpperAge;

tryagain:
	CarOwner* MassiveStruct = nullptr;
	do
	{	
		cout << "\nEnter the number of car owners:  ";
		do {
			cin >> Dimension;
			if (cin.fail())
			{
				cout << "try again - incorrect input " << endl;
				cin.clear();
				cin.ignore(32222, '\n');
			}
			else
				break;
		} while (true);
		MassiveStruct = InitArray(Dimension);
		if (MassiveStruct == nullptr)
		{
			cout << "\nDynamic array don't exist!\n";

			do {
				cout << "Input '+' to try again ,'-' to exit... ";
				char symbol;
				symbol = getchar();
				(symbol == '+') ? begin == true : begin == false;
				if (symbol == '+')
					goto tryagain;
				exit(777);

			} while (!begin);
		}


	} while (begin != true);
	cout << "\nВся информация: " << endl;
	DisplayArray(MassiveStruct, Dimension);

	cout << "\nУточните пол: ";
	do {
		cin >> SexTag;
	} while (isdigit((char)SexTag[1]));
	cout << "\nВведите границу возраста: ";
	do
	{
		cin >> LowAge >> UpperAge;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32222, '\n');
		}
		else
			break;
	} while (true);


	cout << "\nThe sorting list of persons: ";
	SortFirstName(MassiveStruct, Dimension);
	DisplayArray(MassiveStruct, Dimension);

	delete MassiveStruct;

}
CarOwner InitCarOwner()
{
	CarOwner carOwner;

	cout << "\nInput first name: ";
	garbage_collector();
	cin.getline(carOwner.FirstName, 255);

	cout << "Input second name: ";
	garbage_collector();
	cin.getline(carOwner.SecondName, 255);

	cout << "Input last name: ";
	garbage_collector();
	cin.getline(carOwner.LastName, 255);

	cout << "Input sex: ";
	garbage_collector();
	cin.getline(carOwner.Sex, 255);

	cout << "Input age: ";
	garbage_collector();
	cin >> carOwner.Age;

	cout << "Input the mark: ";
	garbage_collector();
	cin.getline(carOwner.mark, 255);

	cout << "Input telephone: ";
	garbage_collector();
	cin >> carOwner.telephone;

	cout << "Input number car: ";
	garbage_collector();
	cin >> carOwner.NumberCar;

	cout << "Input number passport: ";
	garbage_collector();
	cin >> carOwner.NumberPassport;

	cout << "Input post index: ";
	garbage_collector();
	cin >> carOwner.adress.PostIndex;

	cout << "Input country: ";
	garbage_collector();
	cin.getline(carOwner.adress.Country, 255);

	cout << "Input region: ";
	garbage_collector();
	cin.getline(carOwner.adress.Region, 255);

	cout << "Input the district: ";
	garbage_collector();
	cin.getline(carOwner.adress.District, 255);

	cout << "Input town: ";
	garbage_collector();
	cin.getline(carOwner.adress.Town, 255);

	cout << "Input street: ";
	garbage_collector();
	cin.getline(carOwner.adress.Street, 255);

	cout << "Input house: ";
	garbage_collector();
	cin >> carOwner.adress.House;

	cout << "Input flat: ";
	garbage_collector();
	cin >> carOwner.adress.Flat;
	
	return carOwner;
}

CarOwner* InitArray(int Dimension) {
	CarOwner* Mas = new CarOwner[Dimension];
	if (Mas == nullptr)
		return nullptr;
	for (size_t i = 0; i < Dimension; i++)
	{
		printf("\nEnter the information about %d person ", i + 1);
		Mas[i] = InitCarOwner();
	}
	return Mas;
}

void DisplayArray(CarOwner* Massive, int Dimension)
{
	for (size_t i = 0; i < Dimension; i++) { 
		DisplayCarOwner(Massive[i]); 
	}
}

void DisplayChoise(CarOwner* Massive, int Dimension, char* SexTag, int LowAge, int UpperAge)
{
	for (size_t i = 0; i < Dimension; i++)
	{
		if (
			strcmp(Massive[i].Sex, SexTag) == 0 &&
			Massive[i].Age <= UpperAge &&
			Massive[i].Age >= LowAge
			)
		{
			DisplayCarOwner(Massive[i]);
		}
	}
}

void DisplayCarOwner(CarOwner carOwner)
{

	cout << "FIO: " << carOwner.FirstName << " " << carOwner.SecondName << " " << carOwner.LastName << endl;
	cout << "Sex: " << carOwner.Sex << endl;
	cout << "Telephone: " << carOwner.telephone << endl;
	cout << "PostIndex: " << carOwner.adress.PostIndex << endl;
	cout << "Country: " << carOwner.adress.Country << endl;
	cout << "Region: " << carOwner.adress.Region << endl;
	cout << "District: " << carOwner.adress.District << endl;
	cout << "Town: " << carOwner.adress.Town << endl;
	cout << "Street: " << carOwner.adress.Street << endl;
	cout << "House: " << carOwner.adress.House << endl;
	cout << "Flat: " << carOwner.adress.Flat << endl;
	cout << "Mark: " << carOwner.mark << endl;
	cout << "NumberCar: " << carOwner.NumberCar << endl;
	cout << "NumberCar: " << carOwner.NumberPassport << endl;
}

void SortFirstName(CarOwner* Mas, int Dimension)
{
	CarOwner carOwner;
	for (size_t i = 0; i <= Dimension; i++)
	{
		for (size_t j = Dimension - 1; j > i; j--)
		{
			if (strcmp(Mas[j].FirstName, Mas[j - 1].FirstName) < 0)

				carOwner = Mas[j];
				Mas[j] = Mas[j - 1];
				Mas[j - 1] = carOwner;

		}
	}
}

int& CheckCorectDigitValue(int& value)
{
	bool flag = false;
	do {
		if (flag) {
			cout << "[!]Попробуйте еще раз";
		}flag = false;
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32222, '\n');
		}
		else
		{
			return value;
		}
	} while (true);
}
