#include <iostream>
#include <iomanip>
#include <locale>

union ftoi {

	double f;
	uint64_t u;

};

int main() {
	std::setlocale(LC_ALL, "RUS");
	std::cout << "Программа для обработки двоичного представления числовых данных\nАвтор: Савин Павел, группа 2309\n\n";
	short com;
	bool exit = false;
	bool** bits = new bool* [64];
	unsigned int pos;
	bool val;
	unsigned int count;
	for (int i = 0; i < 64; ++i) bits[i] = nullptr;
	do {
		std::cout << "Что хотите сделать?\n1 - Целое число\n2 - Дробное число\n0 - Выйти из программы\nВведите номер соответствующей команды: ";
		std::cin >> com;
		if (std::cin.fail()) {
			std::cout << "Введена некорректная команда! Попробуйте еще раз!\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}
		switch (com) {
		case 1:
			int a;
			do {
				std::cout << "\nВведите целое число в диапазоне [" << INT_MIN << "; " << INT_MAX << "]: ";
				std::cin >> a;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			std::cout << "\nИсходное число: " << a << "\nДвоичное представление: ";
			std::cout << ((a >> ((sizeof(int) * 8) - 1)) & 1) << " ";
			for (int i = ((sizeof(int) * 8) - 2); i >= 0; --i) {
				std::cout << ((a >> i) & 1);
			}
			std::cout << "\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			unsigned int count;
			do {
				std::cout << "Введите желаемое количество разрядов на изменение (от 1 до 32, или 0, если не собираетесь выполнять этот шаг): ";
				std::cin >> count;
				if (std::cin.fail() || count > 32) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			}
			while (true);
			if (count == 0) {
				std::cout << "Шаг с изменением разрядов пропущен.";
				std::cout << "\n\n";
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				for (int i = 0; i < 64; ++i) bits[i] = nullptr;
				break;
			}
			for (int i = 0; i < count; ++i) {
				do {
					std::cout << "Введите номер разряда (от 0 до 31): ";
					std::cin >> pos;
					if (std::cin.fail() || (pos < 0 || pos > 31)) {
						std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						continue;
					}
					std::cout << "Введите значение разряда (0 или 1): ";
					std::cin >> val;
					if (std::cin.fail()) {
						std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						continue;
					}
					bits[pos] = new bool(val);
					break;
				} 
				while (true);
			}
			std::cout << "\nИсходное число: " << a;
			std::cout << "\nБыло:  ";
			std::cout << ((a >> ((sizeof(int) * 8) - 1)) & 1) << " ";
			for (int i = ((sizeof(int) * 8) - 2); i >= 0; --i) {
				std::cout << ((a >> i) & 1);
			}
			for (int i = 0; i < 32; ++i) {
				if (bits[i] != nullptr) {
					if (*(bits[i]) == false) {
						a = a & (~(1 << i));
					}
					else {
						a = a | (1 << i);
					}
				}
			}
			std::cout << "\nСтало: ";
			std::cout << ((a >> ((sizeof(int) * 8) - 1)) & 1) << " ";
			for (int i = ((sizeof(int) * 8) - 2); i >= 0; --i) {
				std::cout << ((a >> i) & 1);
			}
			std::cout << "\nНовое число: " << a;
			std::cout << "\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			for (int i = 0; i < 64; ++i) bits[i] = nullptr;
			break;
		case 2:
			ftoi num;
			do {
				std::cout << "\nВведите дробное число в диапазонe [" << -DBL_MAX << "; " << DBL_MAX << "]: ";
				std::cin >> num.f;
				if (std::cin.fail()) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			std::cout << std::setprecision(17) << std::fixed;
			std::cout << "\nИсходное число: " << num.f << "\nДвоичное представление: ";
			for (int i = ((sizeof(double) * 8) - 1); i >= 0; --i) {
				std::cout << ((num.u >> i) & 1);
				if (i == 63 || i == 52) std::cout << " ";
			}
			std::cout << "\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			do {
				std::cout << "Введите желаемое количество разрядов на изменение (от 1 до 64, или 0, если не собираетесь выполнять этот шаг): ";
				std::cin >> count;
				if (std::cin.fail() || count > 64) {
					std::cout << "Введены некорректные данные! Попробуйте еще раз!\n\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			if (count == 0) {
				std::cout << "Шаг с изменением разрядов пропущен.";
				std::cout << "\n\n";
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				for (int i = 0; i < 64; ++i) bits[i] = nullptr;
				break;
			}
			for (int i = 0; i < count; ++i) {
				do {
					std::cout << "Введите номер разряда (от 0 до 63): ";
					std::cin >> pos;
					if (std::cin.fail() || (pos < 0 || pos > 63)) {
						std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						continue;
					}
					std::cout << "Введите значение разряда (0 или 1): ";
					std::cin >> val;
					if (std::cin.fail()) {
						std::cout << "Введены некорректные данные! Попробуйте еще раз!\n";
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						continue;
					}
					bits[pos] = new bool(val);
					break;
				} 
				while (true);
			}
			std::cout << "\nИсходное число: " << num.f;
			std::cout << "\nБыло:  ";
			std::cout << ((num.u >> ((sizeof(double) * 8) - 1)) & 1) << " ";
			for (int i = ((sizeof(double) * 8) - 2); i >= 0; --i) {
				std::cout << ((num.u >> i) & 1);
				if (i == 63 || i == 52) std::cout << " ";
			}
			for (int i = 0; i < 64; ++i) {
				if (bits[i] != nullptr) {
					if (*(bits[i]) == false) {
						num.u = num.u & (~(1ULL << i));
					}
					else {
						num.u = num.u | (1ULL << i);
					}
				}
			}
			std::cout << "\nСтало: ";
			std::cout << ((num.u >> ((sizeof(double) * 8) - 1)) & 1) << " ";
			for (int i = ((sizeof(double) * 8) - 2); i >= 0; --i) {
				std::cout << ((num.u >> i) & 1);
				if (i == 63 || i == 52) std::cout << " ";
			}
			std::cout << "\nНовое число: " << num.f;
			std::cout << "\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			for (int i = 0; i < 64; ++i) bits[i] = nullptr;
			std::cout << std::setprecision(-1) << std::defaultfloat;
			break;
		case 0:
			exit = true;
			break;
		default:
			std::cout << "Введена некорректная команда! Попробуйте еще раз!\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			break;
		}
		if (exit) break;
	}
	while (true);
	std::cout << "Программа завершила свою работу.";
	return 0;
}