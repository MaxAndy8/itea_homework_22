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
		os << "Особиста інформація:" << std::endl;
		os << "Ім'я:            " << person.firstName << " " << person.lastName << std::endl;
		os << "Дата народження: " << person.birthDate << std::endl;
		os << "Номер телефону:  " << person.phoneNumber;
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
		std::cout << "Інформація про працевлаштування:" << std::endl;
		std::cout << "Останнє робоче місце: " << lastEmpl.lastWorkplace << std::endl;
		std::cout << "Дата початку роботи:  " << lastEmpl.startDate << std::endl;
		std::cout << "Погодинна ставка:     " << lastEmpl.hourlyRate << "грн." << std::endl;
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
		std::cout << "Інформація про професійну особу:" << std::endl;
		std::cout << static_cast<const Person&>(profPerson) << std::endl;
		std::cout << static_cast<const LastEmployment&>(profPerson) << std::endl;

		std::cout << "Професія: " << profPerson.profession << std::endl;
		std::cout << "Навички:  " << std::endl;
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

	employees.push_back(ProfessionalPerson("Іван", "Петров", "15/01/1985", "+38 063 881 82 83",
		"ABC Inc.", "06/01/2010", 2500.50,
		"Програміст", { "C++", "Java", "Python" }));

	employees.push_back(ProfessionalPerson("Іван", "Петров", "15/01/1985", "+38 063 881 82 83",
		"ABC Inc.", "06/01/2010", 2500.50,
		"Програміст", { "C++", "Java", "Python" }));

	char continueInput;

	std::cout << "Ви хочете дозаповнити базу кадрів? (Так - Y): ";
	std::cin >> continueInput;
	if (continueInput == 'Y' || continueInput == 'y') {
		do {
			std::string firstName, lastName, birthDate, phoneNumber;
			std::string lastWorkplace, startDate, profession;
			double hourlyRate;
			std::vector<std::string> skills;

			std::cout << "Введіть ім'я: ";
			std::cin >> firstName;
			std::cout << "Введіть прізвище: ";
			std::cin >> lastName;
			std::cout << "Введіть дату народження: ";
			std::cin >> birthDate;
			std::cout << "Введіть номер телефону: ";
			std::cin >> phoneNumber;

			std::cout << "Введіть останнє місце роботи: ";
			std::cin >> lastWorkplace;
			std::cout << "Введіть дату початку роботи: ";
			std::cin >> startDate;
			std::cout << "Введіть професію: ";
			std::cin >> profession;
			std::cout << "Введіть погодинну ставку: ";
			std::cin >> hourlyRate;

			int numSkills;
			std::cout << "Введіть кількість навичок: ";
			std::cin >> numSkills;
			skills.reserve(numSkills);

			for (int i = 0; i < numSkills; i++) {
				std::string skill;
				std::cout << "Введіть навичку " << i + 1 << ": ";
				std::cin >> skill;
				skills.push_back(skill);
			}

			employees.push_back(ProfessionalPerson(firstName, lastName, birthDate, phoneNumber, lastWorkplace, startDate, hourlyRate, profession, skills));

			std::cout << "Продовжити введення? (Y/N): ";
			std::cin >> continueInput;
		} while (continueInput == 'Y' || continueInput == 'y');

	}

	std::cout << "Список співробітників:" << std::endl;
	int i = 0;
	for (const ProfessionalPerson& employee : employees) {
		i++;
		std::cout << i << " =============================" << std::endl;
		std::cout << employee << std::endl;
	}

	return 0;
}