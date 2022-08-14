#pragma once
//All postal workers
#include<iostream>
#include<fstream>
#include<string>
#include"PostOffice.h"
#include"Parcel.h"
#include"Mail.h"
using namespace std;

//Base class
class PostalWorker {
protected:
	string worker_Name; //Worker Name
	int worker_ID; //Worker ID
	string worker_Position; //Worker Position
	int worker_Salary; //Worker Salary
	int worker_Designation; ////Worker Designation
public:
	PostalWorker();
	PostalWorker(string wName, int wID, string pos, int sal, int des);
	void inputPostalWorker();
	void set_Worker_Name(string wName);
	void set_Worker_ID();
	void set_Worker_Position(int pos);
	void set_Worker_Salary(int sal);
	void set_Worker_Designation(int des);
	string get_Worker_Name();
	int get_Worker_ID();
	string get_Worker_Position();
	int get_Worker_Salary();
	int get_Worker_Designation();
	virtual void Display() = 0;
};

//Derived classes

//Account Officer
class AccountOfficer :public PostalWorker {
private:
	Invoice invoice;
	Mail mail;
	Parcel parcel;
	//Password function
	int getPassword();
public:
	AccountOfficer();
	AccountOfficer(string wName, int wID, string pos, int sal, int des);
	bool checkPassword(int x);
	void parcelRecord();
	void MailRecord();
	void Display();
};

//Postman
class Postman :public PostalWorker {
private:
	Mail mail; //Mail to deliver
	GPO gpo; //Mail recieved from GPO
public:
	Postman();
	Postman(string wName, int wID, string pos, int sal, int des);
	void RecieveMail();
	void delivered();
	void Display();
};

//Clerk
class Clerk :public PostalWorker {
private:
	float stamp; //Stamp
public:
	Clerk();
	Clerk(string wName, int wID, string pos, int sal, int des, float s = 0);
	float buyStamp(float wKG);
	void Display();
};

//Head of post office
class HeadOfPostOffice :public PostalWorker {
private:
	Invoice invoice;
	Mail mail;
	Parcel parcel;
	//Password function
	int getPassword();
public:
	HeadOfPostOffice();
	HeadOfPostOffice(string wName, int wID, string pos, int sal, int des);
	bool checkPassword(int x);
	void workersMenu();
	void AddPostalWorker();
	void workerRecord();
	void parcelRecord();
	void MailRecord();
	void Display();
};


