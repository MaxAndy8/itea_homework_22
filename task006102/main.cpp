#include <iostream>
#include <string>
#include <vector>

class Person {
public:
	Person(const std::string& firstName,
		const std::string& lastName,
		const std::string& birthDate,
		const std::string& phoneNumber)
		: firstName(firstName), lastName(lastName), birthDate(birthDate), phoneNumber(phoneNumber) {}
	virtual ~Person() {}

	friend std::ostream& operator<<(std::ostream& os, const Person& person) {
		os << "�������� ����������:" << std::endl;
		os << "��'�:            " << person.firstName << " " << person.lastName << std::endl;
		os << "���� ����������: " << person.birthDate << std::endl;
		os << "����� ��������:  " << person.phoneNumber;
		return os;
	}

private:
	std::string firstName;
	std::string lastName;
	std::string birthDate;
	std::string phoneNumber;
};

class LastEmployment {
public:
	LastEmployment(const std::string& lastWorkplace,
		const std::string& startDate,
		double hourlyRate)
		: lastWorkplace(lastWorkplace), startDate(startDate), hourlyRate(hourlyRate) {}
	virtual ~LastEmployment() {}

	friend std::ostream& operator<<(std::ostream& os, const LastEmployment& lastEmpl) {
		std::cout << "���������� ��� ����������������:" << std::endl;
		std::cout << "������ ������ ����: " << lastEmpl.lastWorkplace << std::endl;
		std::cout << "���� ������� ������:  " << lastEmpl.startDate << std::endl;
		std::cout << "��������� ������:     " << lastEmpl.hourlyRate << "���." << std::endl;
		return os;
	}

private:
	std::string lastWorkplace;
	std::string startDate;
	double      hourlyRate;
};

class ProfessionalPerson : public Person, public LastEmployment {

public:
	ProfessionalPerson(const std::string& firstName, const std::string& lastName, const std::string& birthDate, const std::string& phoneNumber,
		const std::string& lastWorkplace, const std::string& startDate, double hourlyRate,
		const std::string& profession, const std::vector<std::string>& skills)
		: Person(firstName, lastName, birthDate, phoneNumber),
		LastEmployment(lastWorkplace, startDate, hourlyRate),
		profession(profession), skills(skills) {}
	virtual ~ProfessionalPerson() {}

	friend std::ostream& operator<<(std::ostream& os, const ProfessionalPerson& profPerson) {
		std::cout << "���������� ��� ��������� �����:" << std::endl;
		std::cout << static_cast<const Person&>(profPerson) << std::endl;
		std::cout << static_cast<const LastEmployment&>(profPerson) << std::endl;

		std::cout << "�������: " << profPerson.profession << std::endl;
		std::cout << "�������:  " << std::endl;
		for (const std::string& skill : profPerson.skills) {
			std::cout << "- " << skill << std::endl;
		}
		return os;
	}

private:
	std::string              profession;
	std::vector<std::string> skills;

};


int main() {
	system("chcp 1251>nul");

	std::vector<ProfessionalPerson> employees;

	employees.push_back(ProfessionalPerson("����", "������", "15/01/1985", "+38 063 881 82 83",
		"ABC Inc.", "06/01/2010", 2500.50,
		"���������", { "C++", "Java", "Python" }));

	employees.push_back(ProfessionalPerson("����", "������", "15/01/1985", "+38 063 881 82 83",
		"ABC Inc.", "06/01/2010", 2500.50,
		"���������", { "C++", "Java", "Python" }));

	char continueInput;

	std::cout << "�� ������ ����������� ���� �����? (��� - Y): ";
	std::cin >> continueInput;
	if (continueInput == 'Y' || continueInput == 'y') {
		do {
			std::string firstName, lastName, birthDate, phoneNumber;
			std::string lastWorkplace, startDate, profession;
			double hourlyRate;
			std::vector<std::string> skills;

			std::cout << "������ ��'�: ";
			std::cin >> firstName;
			std::cout << "������ �������: ";
			std::cin >> lastName;
			std::cout << "������ ���� ����������: ";
			std::cin >> birthDate;
			std::cout << "������ ����� ��������: ";
			std::cin >> phoneNumber;

			std::cout << "������ ������ ���� ������: ";
			std::cin >> lastWorkplace;
			std::cout << "������ ���� ������� ������: ";
			std::cin >> startDate;
			std::cout << "������ �������: ";
			std::cin >> profession;
			std::cout << "������ ��������� ������: ";
			std::cin >> hourlyRate;

			int numSkills;
			std::cout << "������ ������� �������: ";
			std::cin >> numSkills;
			skills.reserve(numSkills);

			for (int i = 0; i < numSkills; i++) {
				std::string skill;
				std::cout << "������ ������� " << i + 1 << ": ";
				std::cin >> skill;
				skills.push_back(skill);
			}

			employees.push_back(ProfessionalPerson(firstName, lastName, birthDate, phoneNumber, lastWorkplace, startDate, hourlyRate, profession, skills));

			std::cout << "���������� ��������? (Y/N): ";
			std::cin >> continueInput;
		} while (continueInput == 'Y' || continueInput == 'y');

	}

	std::cout << "������ �����������:" << std::endl;
	int i = 0;
	for (const ProfessionalPerson& employee : employees) {
		i++;
		std::cout << i << " =============================" << std::endl;
		std::cout << employee << std::endl;
	}

	return 0;
}