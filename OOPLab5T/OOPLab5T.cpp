// OOPLab5T.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <cstring>
#include <iostream>
using namespace std;
#include "Lab5Exmaple.h"
//Example1
class Tail {
private:
	int length;
public:
	Tail(int len) : length(len) {}
	int getLength() const { return length; }
};

class Dog {
private:
	char* color;
	int age;
	Tail tail;
public:
	Dog(const char* c, int a, int t_len) : age(a), tail(t_len) {
		color = new char[strlen(c) + 1];
		copy(c, c + strlen(c) + 1, color);
	}
	Dog(const Dog& d) : age(d.age), tail(d.tail.getLength()) {
		color = new char[strlen(d.color) + 1];
		copy(d.color, d.color + strlen(d.color) + 1, color);
	}
	virtual ~Dog() {
		delete[] color;
	}
	const char* getColor() const { return color; }
	int getAge() const { return age; }
	int getTailLength() const { return tail.getLength(); }
};

class NamedDog : public Dog {
private:
	char* name;
public:
	NamedDog(const char* n, const char* c, int a, int t_len) : Dog(c, a, t_len) {
		name = new char[strlen(n) + 1];
		copy(n, n + strlen(n) + 1, name);
	}
	NamedDog(const NamedDog& nd) : Dog(nd), name(new char[strlen(nd.name) + 1]) {
		copy(nd.name, nd.name + strlen(nd.name) + 1, name);
	}
	~NamedDog() {
		delete[] name;
	}
	const char* getName() const { return name; }
	void print() const {
		cout << "Name: " << name << ", Color: " << getColor() << ", Age: " << getAge() << ", Tail Length: " << getTailLength() << endl;
	}
}

//example 2
class Animal {
private:
	string classification; // класифікація тварини
	int limbs; // число кінцівок
	int offspring; // число нащадків

public:
	Animal() : classification(""), limbs(0), offspring(0) {} // конструктор за замовчуванням
	Animal(string c, int l, int o) : classification(c), limbs(l), offspring(o) {} // конструктор із параметрами
	virtual ~Animal() {} // віртуальний деструктор

	virtual void print() { // функція друку
		cout << "Classification: " << classification << endl;
		cout << "Limbs: " << limbs << endl;
		cout << "Offspring: " << offspring << endl;
	}

	void setOffspring(int o) { offspring = o; } // функція перепризначення числа нащадків
};

class DomesticAnimal : public Animal {
private:
	string name; // кличка

public:
	DomesticAnimal() : name("") {} // конструктор за замовчуванням
	DomesticAnimal(string c, int l, int o, string n) : Animal(c, l, o), name(n) {} // конструктор із параметрами
	~DomesticAnimal() {} // деструктор

	void print() { // функція друку
		Animal::print(); // виклик функції друку батьківського класу
		cout << "Name: " << name << endl;
	}

	void setName(string n) { name = n; } // функція перепризначення клички
};

//Example3
class Education {
public:
	Education();
	Education(string institutionName, string degree, int year);
	Education(const Education& other);
	Education& operator=(const Education& other);
	virtual ~Education();
	virtual void print(ostream& os) const;
	virtual void read(istream& is);

protected:
	string institutionName_;
	string degree_;
	int year_;
};

class HigherEducation : public Education {
public:
	HigherEducation();
	HigherEducation(string institutionName, string degree, int year, string thesisTitle);
	HigherEducation(const HigherEducation& other);
	HigherEducation& operator=(const HigherEducation& other);
	virtual ~HigherEducation();
	virtual void print(ostream& os) const override;
	virtual void read(istream& is) override;

private:
	string thesisTitle_;
};

Education::Education() : institutionName_(""), degree_(""), year_(0) {}

Education::Education(string institutionName, string degree, int year)
	: institutionName_(institutionName), degree_(degree), year_(year) {}

Education::Education(const Education& other)
	: institutionName_(other.institutionName_), degree_(other.degree_), year_(other.year_) {}

Education& Education::operator=(const Education& other) {
	institutionName_ = other.institutionName_;
	degree_ = other.degree_;
	year_ = other.year_;
	return *this;
}

Education::~Education() {}

void Education::print(ostream& os) const {
	os << "Institution name: " << institutionName_ << endl;
	os << "Degree: " << degree_ << endl;
	os << "Year: " << year_ << endl;
}

void Education::read(istream& is) {
	cout << "Enter institution name: ";
	getline(is, institutionName_);
	cout << "Enter degree: ";
	getline(is, degree_);
	cout << "Enter year: ";
	is >> year_;
	is.ignore();
}

HigherEducation::HigherEducation() : Education(), thesisTitle_("") {}

HigherEducation::HigherEducation(string institutionName, string degree, int year, string thesisTitle)
	: Education(institutionName, degree, year), thesisTitle_(thesisTitle) {}

HigherEducation::HigherEducation(const HigherEducation& other)
	: Education(other), thesisTitle_(other.thesisTitle_) {}

HigherEducation& HigherEducation::operator=(const HigherEducation& other) {
	Education::operator=(other);
	thesisTitle_ = other.thesisTitle_;
	return *this;
}

HigherEducation::~HigherEducation() {}

void HigherEducation::print(ostream& os) const {
	Education::print(os);
	os << "Thesis title: " << thesisTitle_ << endl;
}

void HigherEducation::read(istream& is) {
	Education::read(is);
	cout << "Enter thesis title: ";
	getline(is, thesisTitle_);
}

int main()
{
    std::cout << " Lab #5  !\n";
    //Example1
 NamedDog myDog("Rufus", "brown", 3, 10);
	myDog.print();
	return 0;
    
    //example2
    Animal a1;
	a1.print(); // виведе значення за замовчуванням

	Animal a2("Mammal", 4, 2);
	a2.print(); // виведе задані значення

	DomesticAnimal d1;
	d1.print(); // виведе значення за замовчуванням

	DomesticAnimal d2("Dog", 4, 3, "Rex");
	d2.print(); // виведе задані значення

	d2.setOffspring(5); // перепризначення числа нащадків
	d2.print(); // виведе змінені значення

	d2.setName("Max"); // перепризначення клички
	d2.print(); // виведе змінені значення

	return 0;
    
    
    //example3
    Education e("University", "Bachelor", 2010);
	e.print(cout);

	cout << endl;

	HigherEducation he("University", "Master", 2012, "Thesis title");
	he.print(cout);

	cout << endl;

	Education eCopy = e;
	eCopy.print(cout);

	cout << endl;

	HigherEducation heCopy = he;
	heCopy.print(cout);

	cout << endl;

	Education eCopy2;
	eCopy2.read(cin);
	e.print(cout);

	cout << endl;

	HigherEducation heCopy2;
	heCopy2.read(cin);
	heCopy2.print(cout);

	cout << endl;

	return 0;

    int chain = 1;
    if (chain == 1) chain = mainExample1();
    if (chain == 2) chain = mainExample2();
    if (chain == 3) chain = mainExample3();
    if (chain == 4) chain = mainExample4();
    if (chain == 5) chain = mainExample5();

}
