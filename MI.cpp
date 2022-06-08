#include<iostream>
using namespace std;

class Person
{
private:
	char* firstname;
	char* lastname;

protected:
	int age;

public:

	Person(char* fname, char* lname, int ag)
	{
		firstname = fname;
		lastname = lname;
		age = ag;
		cout << "Person() called" << endl;
	}
	char* getfirstname()
	{
		return firstname;
	}
	char* getlastname()
	{
		return lastname;
	}
	int getage()
	{
		return age;
	}
	void printInformation()
	{
		cout << firstname << " " << lastname << " is " << age << " years old";
		
	}
	~Person()
	{
		delete firstname;
		delete lastname;
		cout << "~Person called" << endl;
	}
};

class Student :virtual public Person
{
protected:
	float cgpa;

public:
	Student(char* fname, char* lname, int ag, float CGPA) : Person(fname, lname, ag)
	{
		cgpa = CGPA;
		cout << "Student() called" << endl;
	}
	void printInformation()
	{
		
		cout << getfirstname() << " " << getlastname() << " is a " << getage() << " years old and his CGPA is " << cgpa << endl;
	}
	float getcgpa()
	{
		return cgpa;
	}

	~Student()
	{
		cout << "~Student called" << endl;
	}
};

class Undergraduate :public Student
{
private:
	char* fypname;

public:
	Undergraduate(char* fname, char* lname, int ag, float CGPA, char* FYP) :Student(fname, lname, ag, CGPA), Person(fname, lname, ag)
	{
		fypname = FYP;
		cout << "Undergraduate() called " << endl;
	}
	void printInformation()
	{
		cout << getfirstname() << " " << getlastname() << " is a undergraduate student, his cpga is " << getcgpa() << " and his final year project is titled " << fypname << endl;
	}
	~Undergraduate()
	{
		delete fypname;
		cout << "~Undergraduate called" << endl;
	}
};

class Graduate : public Student
{
private:
	char* thesistopic;

public:
	Graduate(char* fname, char* lname, int ag, float CGPA, char* TT) :Student(fname, lname, ag, CGPA), Person(fname, lname, ag)
	{
		thesistopic = TT;
		cout << "Graduate() called " << endl;
	}
	void printInformation()
	{
		cout << getfirstname() << " " << getlastname() << " is a Graduate student, his cpga is " << getcgpa() << " and his his thesis topic is " << thesistopic << endl;
	}
	~Graduate()
	{
		delete thesistopic;
		cout << "~Graduate called" << endl;
	}
};

class Faculty :virtual public Person
{
private:
	int coursecount;
	int teleexe;

public:

	Faculty(char* fname, char* lname, int ag, int CC, int TE) : Person(fname, lname, ag)
	{
		coursecount = CC;
		teleexe = TE;
		cout << "Faculty() called" << endl;
	}
	void printInformation()
	{
		cout << "Faculty member name: " << getfirstname() << " " << getlastname() << " Age: " << age << " Number of courses " << coursecount << " Ext. " << teleexe << endl;

	}
	int getcoursecount()
	{
		return coursecount;
	}
	~Faculty()
	{
		cout << "~Faculty called" << endl;
	}
};

class TA :public Student, public Faculty
{
public:
	TA(char* fname, char* lname, int ag, float CGPA, int CC, int TE) : Student(fname, lname, ag, CGPA), Faculty(fname, lname, ag, CC, TE), Person(fname, lname, ag)
	{
		cout << "TA() called" << endl;
	}
	void printInformation()
	{
		cout << getfirstname() << " " << getlastname() << " is a student his cpga is " << getcgpa() << " and he is TA of " << getcoursecount() << " course" << endl;
	}
	~TA()
	{
		cout << "~TA called" << endl;
	}
};


void main()
{
	Undergraduate ug1("ted", "thompson", 22, 3.91, "oop lab");
	Faculty f1("richard", "karp", 45, 2, 420);
	   
	    /*output for exercise 3:
	    person() called
		student() called
		undergraduate() called
		person() called
		faculty() called*/

	Student s("Ted", "Thompson", 22, 3.91);
	Faculty f("Richard", "Karp", 45, 2, 420);
	//here the number of courses is 2
	//and the extension number is 420
	s.printInformation();
	f.printInformation();
	Undergraduate u("Ted", "Thompson", 22, 3.91, "The Event Locator");
	Graduate      g("Arnold", "Gates", 25, 3.01, "Distributed Algorithms");
	u.printInformation();
	g.printInformation();
	TA ta("Ted", "Thompson", 25, 3.91, 3, 420);
		ta.printInformation();

	system("pause");
}

//OUTPUT
//Person() called
//Student() called
//Person() called
//Faculty() called
//Ted Thompson is a 22 years old and his CGPA is 3.91
//Faculty member name : Richard Karp Age : 45 Number of courses 2 Ext. 420
//Person() called
//Student() called
//Undergraduate() called
//Person() called
//Student() called
//Graduate() called
//Ted Thompson is a undergraduate student, his cpga is 3.91 and his final year project is titled The Event Locator
//Arnold Gates is a Graduate student, his cpga is 3.01 and his his thesis topic is Distributed Algorithms
//Person() called
//Student() called
//Faculty() called
//TA() called
//Ted Thompson is a student his cpga is 3.91 and he is TA of 3 course