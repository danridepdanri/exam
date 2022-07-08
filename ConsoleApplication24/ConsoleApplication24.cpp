#include <iostream>
#include <nlohmann/json.hpp>
#include <ctime>
#include <fstream>

using namespace std;
using namespace nlohmann;
class Plan
{
public:
	string type;
	string content;
	string time;


};
bool add() {
	string type, content, time;
	cout << "Выберите тип операции:\n1) Запустить приложение\n2) Включить напоминаниe\n3) Включить звуковое оповещение\n4)Остановить программу" << endl;
	cout << "Ваш выбор: ";
	int key = 0;
	cin >> key;
	if (key == 1) {
		type = "load";
		cout << "Введите полный путь к исполняемому файлу: ";
		cin >> content;
		cout << "Введите дату в формате [20.07.2015 18:30:25]:";
		cin >> time;
	}
	else if(key == 2){
		type = "message";
		cout << "Введите текст уведомления: ";
		cin >> content;
		cout << "Введите дату в формате [20.07.2015 18:30:25]:";
		cin >> time;
	}
	else if (key == 3) {
		type = "sound";
		cout << "Введите количество уведомлений: ";
		cin >> content;
		cout << "Введите дату в формате [20.07.2015 18:30:25]:";
		cin >> time;
	}
	else if (key == 4) {
		type = "close";
		cout << "Введите количество уведомлений: ";
		cin >> content;
		cout << "Введите дату в формате [20.07.2015 18:30:25]:";
		cin >> time;
	}
	
	Plan plan;
	plan.type = type;
	plan.content = content;
	plan.time = time;
	json object;
	
	object["type"] = plan.type;
	object["content"] = plan.content;
	object["time"] = plan.time;
	
	string j = object.dump();
	cout << j << endl;
	ofstream o("output.json", ios::app);
	o << j << endl;
	o.close();
	return true;
}
bool see() {
	return true;
}
bool deleted() {
	vector<string> vec;
	int dell;
	cout << "Введите номер строки для удаления : ";
	cin >> dell;
	ifstream file("output.json");
	if (file.is_open())
	{
		string str;
		while (getline(file, str))
			vec.push_back(str);
		file.close();
		if (vec.size() < dell)
			return false;
		vec.erase(vec.begin() + dell);
		ofstream outfile("output.json");
		if (outfile.is_open())
		{
			copy(vec.begin(), vec.end(),
				ostream_iterator<string>(outfile, "\n"));
			outfile.close();
			return true;
		}
		return false;
	}
	return false;
}

bool settings() {
	cout << "Вы вошли в настройки. Доступные настройки:\n1) Посмотреть все поставленные задачи\n2) Удалить задачу" << endl;
	int x;
	int y;
	cin >> x;
	if (x == 1) {
		see();
		cout << "Для возвращения в настройки нажмите 1: ";
		cin >> y;
		if (y == 1) {
			settings();

		}
	}
	else if (x == 2) {
		deleted();
		cout << "Для возвращения в настройки нажмите 1: ";
		cin >> y;
		if (y == 1) {
			settings();
		
		}
	}
	

	return true;
}
bool menu() {
	cout << "Добро пожаловать в круто код 2017. Cписок доступных операций: \n1) Добавление задачи\n2) Настройки текущих задач" << endl;
	int x;
	int y;
	cin >> x;
	if (x == 1) {
		add();
		cout << "Для возвращения в меню нажмите 1: ";
		cin >> y;
		if (y == 1) {
			menu();

		}
	}
	else if (x == 2) {
		settings();
		cout << "Для возвращения в меню нажмите 1: ";
		cin >> y;
		if (y == 1) {
			menu();

		}
	}
	

	return true;
}
int main() {
	setlocale(LC_ALL, "Russian_Russia.1251");
	menu();
	/*add();*/
	/*see();*/
	/*deleted();*/
}
