#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Вывод файла
bool printFile(string path) {
	ifstream in;
	in.open(path);

	if (in.is_open()){
		char sym;
		while (in.get(sym))
			cout << sym;
		in.close();
		return true;
	}
	in.close();
	return false;
}
// Задание
bool fileInput(string path, int pos, string str) {
	string newFile;

	ifstream copy;
	copy.open(path);
	if (!copy.is_open()) {
		copy.close();
		return false;
	}

	char sym;
	while (copy.get(sym))
		newFile += sym;
	copy.close();

	newFile.insert(pos, str);
	ofstream out;
	out.open(path);

	if (!out.is_open()) {
		out.close();
		return false;
	}

	out << newFile;
	out.close();
	return true;
}
// Задача 1
string subfile(string path, int pos) {
	ifstream in;
	in.open(path);
	if (in.is_open()) {
		string res;
		char sym;
		in.seekg(pos, ios::beg);
		while (in.get(sym))
			res += sym;
		in.close();
		return res;
	}
	in.close();
	return "";
}
// Задача 3
void path_to_file(string path, bool n) {
	if (n)
	{
		ofstream out;
		out.open(path,ios ::in | ios::app);
		if (out.is_open())
		{
			cout << "Введите строку:\n";
			string str;
			getline(cin, str);
			out << str << "\n";
			out.close();
		}
		else
			cout << "Error\n";
		out.close();
	}
	else
	{
		ifstream in;
		in.open(path);
		char sym;
		while (in.get(sym))
		cout << sym;
		in.close();
			
	}

}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	string path = "file.txt";

	/*fstream fs;
	fs.open(path, ios::in | ios::app);

	if (fs.is_open()) {
		cout << "Файл открыт.\n";
		string str;
		//Запись файла
		cout << "Введиьте строку:\n";
		getline(cin, str);
		fs << str + "\n";
		cout << "Запись добавлена в файл.\n";
		// Счиывание из файлa
		fs.seekg(0, ios::beg);
		char sym;
		cout << "Содержимоное файла:\n";
		while (fs.get(sym))
			cout << sym;
	}
	else
		cout << "Ошибка открытия файла.\n";

	fs.close();*/

	// Задание
	cout << "Задача 1.\nВведите строку:\n";
	string str;
	getline(cin, str);
	if (fileInput(path, 15, str))
		cout << "Запись помещена в файл.\n";
	else
		cout << "Ошибка выполнения функции.\n";
	cout << "\nСодержимое файла:\n";

	printFile(path);

	// Задача 1
	cout << "Задача 1.\nВведите позицию: ";
	cin >> n;
	cin.ignore();
	cout << "Содержимоле файла с позиции " << n << ":\n";
	cout << subfile(path, n) << endl;

	// Задача 2
	cout << "Задача 2.\n";

	int day = 0, month = 0, year = 0;

	ifstream in; 
	in.open("date.txt");

	if (in.is_open())
	{
		string date;
		in >> date;

		day = stoi(date);
		cout << "День = " << day << "\n\n";

		month = stoi(date.substr(date.find(".") +1));
		cout << "Месяц = " << month << "\n\n";

		year = stoi(date.substr(date.rfind(".") +1));
		cout << "Год = " << year << "\n\n";
	}
	else
		cout << "Ошыбка открытия файла\n";

	// Задача 2
	cout << "Задача 3.\n";
	path_to_file(path, false);
	return 0;
}

// seekg - seek get pointer. Метод который перемещает курсор считывания в новую позицию файла
// seekз - seek put pointer. Метод который перемещает курсор записи в новую позицию файла