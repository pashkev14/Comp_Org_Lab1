#include <iostream>
#include <iomanip>
#include <locale>

union ftoi {

	double f;
	uint64_t u;

};

int main() {
	std::setlocale(LC_ALL, "RUS");
	std::cout << "��������� ��� ��������� ��������� ������������� �������� ������\n�����: ����� �����, ������ 2309\n\n";
	short com;
	bool exit = false;
	bool** bits = new bool* [64];
	unsigned int pos;
	bool val;
	unsigned int count;
	for (int i = 0; i < 64; ++i) bits[i] = nullptr;
	do {
		std::cout << "��� ������ �������?\n1 - ����� �����\n2 - ������� �����\n0 - ����� �� ���������\n������� ����� ��������������� �������: ";
		std::cin >> com;
		if (std::cin.fail()) {
			std::cout << "������� ������������ �������! ���������� ��� ���!\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}
		switch (com) {
		case 1:
			int a;
			do {
				std::cout << "\n������� ����� ����� � ��������� [" << INT_MIN << "; " << INT_MAX << "]: ";
				std::cin >> a;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			std::cout << "\n�������� �����: " << a << "\n�������� �������������: ";
			std::cout << ((a >> ((sizeof(int) * 8) - 1)) & 1) << " ";
			for (int i = ((sizeof(int) * 8) - 2); i >= 0; --i) {
				std::cout << ((a >> i) & 1);
			}
			std::cout << "\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			unsigned int count;
			do {
				std::cout << "������� �������� ���������� �������� �� ��������� (�� 1 �� 32, ��� 0, ���� �� ����������� ��������� ���� ���): ";
				std::cin >> count;
				if (std::cin.fail() || count > 32) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			}
			while (true);
			if (count == 0) {
				std::cout << "��� � ���������� �������� ��������.";
				std::cout << "\n\n";
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				for (int i = 0; i < 64; ++i) bits[i] = nullptr;
				break;
			}
			for (int i = 0; i < count; ++i) {
				do {
					std::cout << "������� ����� ������� (�� 0 �� 31): ";
					std::cin >> pos;
					if (std::cin.fail() || (pos < 0 || pos > 31)) {
						std::cout << "������� ������������ ������! ���������� ��� ���!\n";
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						continue;
					}
					std::cout << "������� �������� ������� (0 ��� 1): ";
					std::cin >> val;
					if (std::cin.fail()) {
						std::cout << "������� ������������ ������! ���������� ��� ���!\n";
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						continue;
					}
					bits[pos] = new bool(val);
					break;
				} 
				while (true);
			}
			std::cout << "\n�������� �����: " << a;
			std::cout << "\n����:  ";
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
			std::cout << "\n�����: ";
			std::cout << ((a >> ((sizeof(int) * 8) - 1)) & 1) << " ";
			for (int i = ((sizeof(int) * 8) - 2); i >= 0; --i) {
				std::cout << ((a >> i) & 1);
			}
			std::cout << "\n����� �����: " << a;
			std::cout << "\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			for (int i = 0; i < 64; ++i) bits[i] = nullptr;
			break;
		case 2:
			ftoi num;
			do {
				std::cout << "\n������� ������� ����� � ��������e [" << -DBL_MAX << "; " << DBL_MAX << "]: ";
				std::cin >> num.f;
				if (std::cin.fail()) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			std::cout << std::setprecision(17) << std::fixed;
			std::cout << "\n�������� �����: " << num.f << "\n�������� �������������: ";
			for (int i = ((sizeof(double) * 8) - 1); i >= 0; --i) {
				std::cout << ((num.u >> i) & 1);
				if (i == 63 || i == 52) std::cout << " ";
			}
			std::cout << "\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			do {
				std::cout << "������� �������� ���������� �������� �� ��������� (�� 1 �� 64, ��� 0, ���� �� ����������� ��������� ���� ���): ";
				std::cin >> count;
				if (std::cin.fail() || count > 64) {
					std::cout << "������� ������������ ������! ���������� ��� ���!\n\n";
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					continue;
				}
				break;
			} 
			while (true);
			if (count == 0) {
				std::cout << "��� � ���������� �������� ��������.";
				std::cout << "\n\n";
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				for (int i = 0; i < 64; ++i) bits[i] = nullptr;
				break;
			}
			for (int i = 0; i < count; ++i) {
				do {
					std::cout << "������� ����� ������� (�� 0 �� 63): ";
					std::cin >> pos;
					if (std::cin.fail() || (pos < 0 || pos > 63)) {
						std::cout << "������� ������������ ������! ���������� ��� ���!\n";
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						continue;
					}
					std::cout << "������� �������� ������� (0 ��� 1): ";
					std::cin >> val;
					if (std::cin.fail()) {
						std::cout << "������� ������������ ������! ���������� ��� ���!\n";
						std::cin.clear();
						std::cin.ignore(32767, '\n');
						continue;
					}
					bits[pos] = new bool(val);
					break;
				} 
				while (true);
			}
			std::cout << "\n�������� �����: " << num.f;
			std::cout << "\n����:  ";
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
			std::cout << "\n�����: ";
			std::cout << ((num.u >> ((sizeof(double) * 8) - 1)) & 1) << " ";
			for (int i = ((sizeof(double) * 8) - 2); i >= 0; --i) {
				std::cout << ((num.u >> i) & 1);
				if (i == 63 || i == 52) std::cout << " ";
			}
			std::cout << "\n����� �����: " << num.f;
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
			std::cout << "������� ������������ �������! ���������� ��� ���!\n\n";
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			break;
		}
		if (exit) break;
	}
	while (true);
	std::cout << "��������� ��������� ���� ������.";
	return 0;
}