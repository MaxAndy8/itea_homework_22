#include <iostream>

class Device
{
public:
	virtual int returnVoltage() = 0;
	Device() = default;
	virtual ~Device() {}
};

class Scanner : virtual public Device
{
private:
	int voltage = 0;
public:
	virtual int returnVoltage() { return voltage; }
	Scanner(int vol = 215) : voltage(vol) { }
	virtual ~Scanner() {}
};

class Printer : virtual public Device
{
private:
	int voltage = 0;
public:
	virtual int returnVoltage() { return voltage; }
	Printer(int vol = 225) : voltage(vol) { }
	virtual ~Printer() {}
};

class Multi : public Printer, public Scanner
{
public:
	virtual int returnVoltage()
	{
		int printerVoltage = Printer::returnVoltage();
		int scannerVoltage = Scanner::returnVoltage();

		if (printerVoltage > scannerVoltage) {
			return printerVoltage + 1;
		}
		else {
			return scannerVoltage + 1;
		}
	}
	Multi(int volPrin = 225, int volScan = 215)
		: Device(), Printer(volPrin), Scanner(volScan)
	{}
	virtual ~Multi() {}
};

int main()
{
	system("chcp 1251>nul");

	std::cout << " - - - - - - - - - - - 1 - - - - - - - - - - -" << std::endl;
	{
		Printer printer;
		Scanner scanner;
		Multi   MF237w;

		// �������� ������� � ������� ��������    
		std::cout << "Printer voltage: " << printer.returnVoltage() << std::endl;
		std::cout << "Scanner voltage: " << scanner.returnVoltage() << std::endl;
		std::cout << "Multi voltage:   " << MF237w.returnVoltage()  << std::endl;
	}

	std::cout << " - - - - - - - - - - - 2 - - - - - - - - - - -" << std::endl;
	{
		Multi MF237w;

		// ������������ ������ returnVoltage() ��� ��������� �������
		int multiVoltage = MF237w.returnVoltage();
		std::cout << "������� Multi: " << multiVoltage << std::endl;

		// ����������: ������������ ���������� ������ ����� ��������� �� ���������
		Device*  devicePtr  = &MF237w;
		Scanner* scannerPtr = &MF237w;
		Printer* printerPtr = &MF237w;

		std::cout << "������� ����� �������� �� Device:  " << devicePtr->returnVoltage()  << std::endl;
		std::cout << "������� ����� �������� �� Scanner: " << scannerPtr->returnVoltage() << std::endl;
		std::cout << "������� ����� �������� �� Printer: " << printerPtr->returnVoltage() << std::endl;
	}


	return 0;
}
