#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// ����� �����
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
// �������
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
// ������ 1
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
// ������ 3
void path_to_file(string path, bool n) {
	if (n)
	{
		ofstream out;
		out.open(path,ios ::in | ios::app);
		if (out.is_open())
		{
			cout << "������� ������:\n";
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
		cout << "���� ������.\n";
		string str;
		//������ �����
		cout << "�������� ������:\n";
		getline(cin, str);
		fs << str + "\n";
		cout << "������ ��������� � ����.\n";
		// ��������� �� ����a
		fs.seekg(0, ios::beg);
		char sym;
		cout << "������������ �����:\n";
		while (fs.get(sym))
			cout << sym;
	}
	else
		cout << "������ �������� �����.\n";

	fs.close();*/

	// �������
	cout << "������ 1.\n������� ������:\n";
	string str;
	getline(cin, str);
	if (fileInput(path, 15, str))
		cout << "������ �������� � ����.\n";
	else
		cout << "������ ���������� �������.\n";
	cout << "\n���������� �����:\n";

	printFile(path);

	// ������ 1
	cout << "������ 1.\n������� �������: ";
	cin >> n;
	cin.ignore();
	cout << "����������� ����� � ������� " << n << ":\n";
	cout << subfile(path, n) << endl;

	// ������ 2
	cout << "������ 2.\n";

	int day = 0, month = 0, year = 0;

	ifstream in; 
	in.open("date.txt");

	if (in.is_open())
	{
		string date;
		in >> date;

		day = stoi(date);
		cout << "���� = " << day << "\n\n";

		month = stoi(date.substr(date.find(".") +1));
		cout << "����� = " << month << "\n\n";

		year = stoi(date.substr(date.rfind(".") +1));
		cout << "��� = " << year << "\n\n";
	}
	else
		cout << "������ �������� �����\n";

	// ������ 2
	cout << "������ 3.\n";
	path_to_file(path, false);
	return 0;
}

// seekg - seek get pointer. ����� ������� ���������� ������ ���������� � ����� ������� �����
// seek� - seek put pointer. ����� ������� ���������� ������ ������ � ����� ������� �����