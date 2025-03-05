#include "Header.h"

void delCurData(char***& data, int& countNow, int& cur) {
	if (!countNow) return;
	char*** newData = new char** [countNow - 1];
	for (int i = 0; i < countNow - 1; i++)
	{
		newData[i] = new char* [2];
		newData[i][0] = nullptr;   // Имя
		newData[i][1] = nullptr;   // Телефон
	}
	for (int i = 0, j = 0; i < countNow; i++)
	{
		if (i == cur) continue;
		newData[j][0] = data[i][0];
		newData[j][1] = data[i][1];
		j++;
	}
	delete[] data[cur][0];
	delete[] data[cur][1];
	delete[] data[cur];


	cur = 0;
	data = newData;
	countNow--;
}
void addUser(char***& data, int& countNow, char* name, char* phone) {
	char*** newData = new char** [countNow + 1];
	for (int i = 0; i < countNow + 1; i++)
	{
		newData[i] = new char* [2];
		newData[i][0] = nullptr;   // Имя
		newData[i][1] = nullptr;   // Телефон
	}
	int i = 0; //Элемент заполняемого списка
	if (countNow)
		for (; i < countNow; i++)
		{
			newData[i][0] = new char[strlen(data[i][0]) + 1];
			strcpy_s(newData[i][0], strlen(data[i][0]) + 1, data[i][0]);
			newData[i][1] = new char[strlen(data[i][1]) + 1];
			strcpy_s(newData[i][1], strlen(data[i][1]) + 1, data[i][1]);
		}

	newData[i][0] = new char[strlen(name) + 1];
	strcpy_s(newData[i][0], strlen(name) + 1, name);
	newData[i][1] = new char[strlen(phone) + 1];
	strcpy_s(newData[i][1], strlen(phone) + 1, phone);
	if (data) {
		for (int i = 0; i < countNow; i++) {
			delete[] data[i][0];
			delete[] data[i][1];
			delete[] data[i];
		}
		delete[] data;
	}

	data = newData;
	countNow++;
}
void addUser(char***& data, int& countNow, const char* cName, const char* cPhone) {
	char* name = new char[strlen(cName) + 1];
	strcpy_s(name, strlen(cName) + 1, cName);

	char* phone = new char[strlen(cPhone) + 1];
	strcpy_s(phone, strlen(cPhone) + 1, cPhone);

	addUser(data, countNow, name, phone);
	delete[] name;
	delete[] phone;
}

void showData(char*** data, int countNow, int cur, TaskStructure& m) {
	setCursorPosition(m.startPos);
	for (int i = 0; i < countNow; i++) {
		std::cout << ((cur != i) ? "" : "-> ") << "Имя: " << data[i][0] << ", Телефон: " << data[i][1];
		nextLine(m.startPos);
	}
}
char toLowerRus(char ABC) {
	if ((ABC >= 'A' && ABC <= 'Z') || (ABC >= 'А' && ABC <= 'Я'))
		return ABC + 32;
	return ABC;
}
bool textMatch(const char* text1, const char* text2) {
	for (int i = 0; i < strlen(text1); i++)
		if (toLowerRus(text1[i]) != toLowerRus(text2[i])) return false;
	return true;
}
int searchData(char*** data, int countNow, char* what) {
	for (int i = 0; i < countNow; i++)
	{
		char* item = data[i][0];
		if (textMatch(what, data[i][0])) return i;
		if (textMatch(what, data[i][1])) return i;
	}
	return -1;
}

void changeData(char***& data, int& countNow, int cur, char* name, char* phone) {
	if (!countNow) addUser(data, countNow, name, phone);
	if (name) {
		char* newName = new char[strlen(name) + 1];
		strcpy_s(newName, strlen(name) + 1, name);
		delete[] data[cur][0];
		data[cur][0] = newName;
	}

	if (phone)
	{
		char* newPhone = new char[strlen(phone) + 1];
		strcpy_s(newPhone, strlen(phone) + 1, phone);
		delete[] data[cur][1];
		data[cur][1] = newPhone;
	}
}