#include <iostream>
#include <nlohmann/json.hpp>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#pragma warning(disable:4996)
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


using namespace std;
using namespace nlohmann;
class Plan
{
public:
	string type;
	string content;
	string time;


};
bool Data() {
	time_t     now;
	struct tm* ts;
	char       buf[80];


	time(&now);


	ts = localtime(&now);
	int year, month, day, hour, minute, sec;

	cout << "Введите год: ";
	cin >> year;
	if (year < (ts->tm_year + 1900)) {
		cout << "Этот год уже прошел" << endl;
		Data();
	}
	else {
		cout << "Введите месяц: ";
		cin >> month;
		if (year == (ts->tm_year + 1900) && month < (ts->tm_mon)) {
			cout << "Этот месяц уже прошел" << endl;
			Data();

		}
		else if (year >= (ts->tm_year + 1900)) {
			cout << "Введите день: ";
			cin >> day;
			if (day > 31 || day < 0) {
				cout << "Не правильный день" << endl;
				Data();

			}
			else {
				cout << "Введите часы: ";
				cin >> hour;
				if (hour > 24 || hour < 0) {
					cout << "Не правильное время" << endl;
					Data();

				}
				else {
					cout << "Введите минуты: ";
					cin >> minute;
					if (minute < 0 || minute > 59) {
						cout << "Не правильное время" << endl;
						Data();

					}
					else {
						cout << "Введите секунды:";
						cin >> sec;
						if (sec < 0 || sec > 59) {
							cout << "Не правильное время" << endl;
							Data();

						}
						else {
							cout << "Вы закончили вводить время" << endl;
						}
					}

				}
			}
		}
		else if (year == (ts->tm_year + 1900) && month == (ts->tm_mon) && month > 0 && month <= 12) {
			cout << "Введите день: ";
			cin >> day;
			if (day < ts->tm_mday) {
				cout << "Не правильный день" << endl;
				Data();
			}
			else if (day >= ts->tm_mday && day <= 31) {
				cout << "Введите часы: ";
				cin >> hour;
				if (hour < ts->tm_hour) {
					cout << "Не правильный час" << endl;
					Data();
				}
				else if (hour >= ts->tm_hour && hour <= 23) {
					cout << "Введите минуты: ";
					cin >> minute;
					if (minute < ts->tm_min) {
						cout << "Не правильная минута" << endl;
						Data();
					}
					else if (minute > ts->tm_min && minute <= 59) {
						cout << "Введите секунды: ";
						cin >> sec;
						if (sec < 0 || sec >= 59) {
							cout << "Не правильные секунды" << endl;
							Data();
						}
					}

				}

			}
		}
		else if (year == (ts->tm_year + 1900) && month > (ts->tm_mon) && month > 0 && month <= 12) {
			cout << "Введите день: ";
			cin >> day;
			if (day < 0 || day > 31) {
				cout << "Не правильный день" << endl;
				Data();
			}
			else {
				cout << "Введите часы: ";
				cin >> hour;
				if (hour < 0 || hour > 23) {
					cout << "Не правильный час" << endl;
					Data();

				}
				else {
					cout << "Введите минуты: ";
					cin >> minute;
					if (minute < 0 || minute > 59) {
						cout << "Не правильная минута" << endl;
						Data();
					}
					else {
						cout << "Введите секунды: ";
						cin >> sec;
						if (sec < 0 || sec > 59) {
							cout << "Не правильная cекунда" << endl;
							Data();
						}
					}
				}

			}

		}

	}
	if (month < 10) { // месяц
		std::ofstream out;         
		out.open("temp.txt"); 
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << day << " " << hour << ":" << minute << ":" << sec << endl;
		}
	}
	if (hour < 10) { // Часы
		std::ofstream out;         
		out.open("temp.txt"); 
		if (out.is_open())
		{
			out << year << "-" << month << "-" << day << " " << "0" << hour << ":" << minute << ":" << sec << endl;
		}
	}
	if (minute < 10) { // Минуты
		std::ofstream out;         
		out.open("temp.txt"); 
		if (out.is_open())
		{
			out << year << "-" << month << "-" << day << " " << hour << ":" << "0" << minute << ":" << sec << endl;
		}
	}
	if (sec < 10) { // Секунды
		std::ofstream out;         
		out.open("temp.txt"); 
		if (out.is_open())
		{
			out << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << "0" << sec << endl;
		}
	}
	if (day < 10) { // Дни
		std::ofstream out;          
		out.open("temp.txt"); 
		if (out.is_open())
		{
			out << year << "-" << month << "-" << "0" << day << " " << hour << ":" << minute << ":" << sec << endl;
		}
	}
	if (month < 10 and day < 10) { // Месяц дни
		std::ofstream out;         
		out.open("temp.txt"); 
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << "0" << day << " " << hour << ":" << minute << ":" << sec << endl;
		}
	}
	if (month < 10 and hour < 10) { // Месяц часы
		std::ofstream out;          
		out.open("temp.txt"); 
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << day << " " << "0" << hour << ":" << minute << ":" << sec << endl;
		}
	}
	if (month < 10 && minute < 10) { // месяц минуты
		std::ofstream out;        
		out.open("temp.txt"); 
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << day << " " << hour << ":" << "0" << minute << ":" << sec << endl;
		}
	}
	if (month < 10 and sec < 10) { // Месяц секунды
		std::ofstream out;         
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << day << " " << hour << ":" << minute << ":" << "0" << sec << endl;
		}
	}
	if (day < 10 and hour < 10) { // день часы 
		std::ofstream out;          
		out.open("temp.txt"); 
		if (out.is_open())
		{
			out << year << "-"  << month << "-" << "0" << day << " " << "0" << hour << ":" << minute << ":" << sec << endl;
		}
	}
	if (day < 10 and minute < 10) { // день минуты 
		std::ofstream out;         
		out.open("temp.txt"); 
		if (out.is_open())
		{
			out << year << "-" << month << "-" << "0" << day << " " << hour << ":" << "0" << minute << ":" << sec << endl;
		}
	}
	if (day < 10 and sec < 10) { // день секунды
		std::ofstream out;          
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << "0" << day << " " << hour << ":" <<  minute << ":" << "0" << sec << endl;
		}
	}
	if (hour < 10 and  minute < 10) { // Часы минуты
		std::ofstream out;         
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-"  << day << " " << "0" << hour << ":" << "0" << minute << ":"  << sec << endl;
		}
	}
	if (hour < 10 and sec < 10) { // Часы секунды
	std::ofstream out;         
	out.open("temp.txt");
	if (out.is_open())
	{
		out << year << "-" << month << "-" << day << " " << "0" << hour << ":"  << minute << ":" << "0" << sec << endl;
	}
	}
	 if (minute < 10 and sec < 10) { // Минуты секунды
	std::ofstream out;         
	out.open("temp.txt");
	if (out.is_open())
	{
		out << year << "-" << month << "-" << day << " "  << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
	}
	}
	if (month < 10 and day < 10 and hour < 10) { // месяц день часы 
	std::ofstream out;          
	out.open("temp.txt"); 
	if (out.is_open())
	{
		out << year << "-" << "0" << month << "-" << "0" << day << " " << "0" << hour << ":"  << minute << ":"  << sec << endl;
	}
	}
	if (month < 10 and day < 10 and minute < 10) { // месяц день минуты 
	std::ofstream out;         
	out.open("temp.txt"); 
	if (out.is_open())
	{
		out << year << "-" << "0" << month << "-" << "0" << day << " "  << hour << ":" << "0" << minute << ":" << sec << endl;
	}
	}
	if (month < 10 && day < 10 and sec < 10) { // месяц день секунды
	std::ofstream out;         
	out.open("temp.txt"); 
	if (out.is_open())
	{
		out << year << "-" << "0" << month << "-" << "0" << day << " " << hour << ":"  << minute << ":" << "0" << sec << endl;
	}
	}
	if (month < 10 && hour < 10 and minute < 10) { // месяц часы минуты
	std::ofstream out;        
	out.open("temp.txt"); 
	if (out.is_open())
	{
		out << year << "-" << "0" << month << "-" << day << " " << "0" << hour << ":" << "0" << minute << ":"  << sec << endl;
	}
	}
	if (month < 10 && hour < 10 and sec < 10) { // месяц часы секунды 
	std::ofstream out;          
	out.open("temp.txt"); 
	if (out.is_open())
	{
		out << year << "-" << "0" << month << "-" << day << " " << "0" << hour << ":" << minute << ":" << "0" << sec << endl;
	}
	}
	if (month < 10 && minute < 10 and sec < 10) { // месяц минуты секунды
	std::ofstream out;         
	out.open("temp.txt");
	if (out.is_open())
	{
		out << year << "-" << "0" << month << "-" << day << " "  << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
	}
	}
	 if (day < 10 && hour < 10 and minute < 10) { // день часы минуты
	std::ofstream out;         
	out.open("temp.txt");
	if (out.is_open())
	{
		out << year << "-" << month << "-" << "0" << day << " " << "0" << hour << ":" << "0" << minute << ":"  << sec << endl;
	}
	}
	if (day < 10 && hour < 10 and sec < 10) { // день часы секкунды
	std::ofstream out;        
	out.open("temp.txt");
	if (out.is_open())
	{
		out << year << "-" << month << "-" << "0" << day << " " << "0" << hour << ":"  << minute << ":" << "0" << sec << endl;
	}
	}
	if (day < 10 && minute < 10 and sec < 10) { // день минуты секунды
	std::ofstream out;         
	out.open("temp.txt"); 
	if (out.is_open())
	{
		out << year << "-" << month << "-" << "0" << day << " "  << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
	}
	}
	if (day < 10 && minute < 10 and sec < 10) { // часы минуты секунды
	std::ofstream out;        
	out.open("temp.txt"); 
	if (out.is_open())
	{
		out << year << "-" << month << "-" << day << " " << "0" << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
	}
	}
	if (day < 10 && minute < 10 and hour < 10 && minute < 10) { // месяц день часы минуты
	std::ofstream out;        
	out.open("temp.txt");
	if (out.is_open())
	{
		out << year << "-" << "0" << month << "-" << "0" << day << " " << "0" << hour << ":" << "0" << minute << ":"  << sec << endl;
	}
	}
	if (day < 10 && minute < 10 and hour < 10 && minute < 10) { // месяц день часы секунды
	std::ofstream out;         
	out.open("temp.txt");
	if (out.is_open())
	{
		out << year << "-" << "0" << month << "-" << "0" << day << " " << "0" << hour << ":" << minute << ":" << "0" << sec << endl;
	}
	}
	if (day < 10 && minute < 10 and hour < 10 && minute < 10) { // месяц день минуты секунды
	std::ofstream out;          
	out.open("temp.txt");
	if (out.is_open())
	{
		out << year << "-" << "0" << month << "-" << "0" << day << " "  << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
	}
	}
	if (day < 10 && minute < 10 and hour < 10 && minute < 10) { // месяц часы минуты секунды
	std::ofstream out;          
	out.open("temp.txt");
	if (out.is_open())
	{
		out << year << "-" << "0" << month << "-"  << day << " " << "0" << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
	}
	}
	if (day < 10 && minute < 10 and hour < 10 && minute < 10) { // день часы минуты секунды
	std::ofstream out;         
	out.open("temp.txt");
	if (out.is_open())
	{
		out << year << "-"  << month << "-" << "0" << day << " " << "0" << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
	}
	}
	if (day < 10 && month < 10 and hour < 10 && minute < 10 && sec < 10) { // день часы минуты секунды месяца
	std::ofstream out;         
	out.open("temp.txt"); 
	if (out.is_open())
	{
		out << year << "-" << "0" << month << "-" << "0" << day << " " << "0" << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
	}
	}
	if(day >= 10 && month >= 10 and hour >= 10 && minute >= 10 && sec >= 10) {
	std::ofstream out;         
	out.open("temp.txt"); 
	if (out.is_open())
	{
		out << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << sec << endl;
	}
}


		
	
	
	
	
	return true;
}
bool add() {
	string type, content, time;
	
	cout << "Выберите тип операции:\n1) Запустить приложение\n2) Включить напоминаниe\n4)Остановить программу" << endl;
	cout << "Ваш выбор: ";
	int key = 0;
	cin >> key;
	if (key == 1) {
		type = "Load";
		cout << "Введите полный путь к исполняемому файлу: ";
		cin >> content;
		cout << "Введите дату в формате [2022-07-08 18:30:25]:";
		cout << endl;
		Data();
		
	}
	else if(key == 2){
		type = "Message";
		cout << "Введите текст уведомления: ";
		cin >> content;
		cout << "Введите дату в формате [2022-07-08 18:30:25]:";
		cout << endl;
		Data();
	}
	else if (key == 4) {
		exit;
	}
	else {
		system("cls");
		add();
	}
	std::string line;
	string line2;
	std::ifstream in("temp.txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		while (getline(in, line))
		{
			std::cout << line << std::endl;
			line2 = line;
		}
	}
	
	Plan plan;
	plan.type = type;
	plan.content = content;
	plan.time = line2;
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
	ifstream file("output.json"); // файл из которого читаем (для линукс путь будет выглядеть по другому)
	string jsonString;
	int i = 0;
	while (getline(file, jsonString)) { // пока не достигнут конец файла класть очередную строку в переменную (s)
		json object = json::parse(jsonString);
		string type = object["type"].get<string>();
		string content = object["content"].get<string>();
		string time = object["time"].get<string>();
		i++;
		cout << "Задача " << i << ":" << "Тип: " << type << " Содержимое: " << content << " Время выполнения: " << time << ";" << endl;
		
	}

	file.close();
	return true;
}
bool deleted() {
	see();
	vector<string> vec;
	int dell;
	cout << "Введите номер строки для удаления : ";
	cin >> dell;
	dell = dell - 1;
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
	cout << "Вы вошли в настройки. Доступные настройки:\n1) Посмотреть все поставленные задачи\n2) Удалить задачу\n3) Добавить задачу\n0)Закрыть" << endl;
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
		system("cls");
		deleted();
		
		cout << "Для возвращения в настройки нажмите 1: ";
		cin >> y;
		if (y == 1) {
			system("cls");
			settings();
		
		}
	}
	else if (x == 3) {
		system("cls");
		add();

		cout << "Для возвращения в настройки нажмите 1: ";
		cin >> y;
		if (y == 1) {
			settings();

		}
	
	}
	else if (x == 0) {
		exit;
	}
	else {
		system("cls");
		settings();
	}
	

	return true;
}
bool menu() {
	cout << "Добро пожаловать в круто код 2017. Cписок доступных операций: \n1) Добавление задачи\n2) Настройки текущих задач\n3) Закрыть приложение" << endl;
	int x;
	int y;
	cin >> x;
	if (x == 1) {
		system("cls");
		add();
		
		cout << "Для возвращения в меню нажмите 1: ";
		int x;
		cin >> x;
		if (x == 1) {
			system("cls");
			menu();

		}
	}
	else if (x == 2) {
		system("cls");
		settings();
		
		cout << "Для возвращения в меню нажмите 1: ";
		cin >> y;
		if (y == 1) {
			system("cls");
			menu();

		}
	}
	else if (x == 3) {
		exit;
		
	}
	else {
		system("cls");
		menu();
	}
	

	return true;
}
int main() {
	setlocale(LC_ALL, "Russian_Russia.1251");
	menu();
}
