#pragma once
//Mail Service
#include<iostream>
#include"Parcel.h"
using namespace std;

//Mail Service class
class MailService {
protected:
	float _charges; //Mail charges
	int NoOfDays; //Number of days delivery will take
	float _stamp; //Stamp charges
	float _weigh; //Mail weight
public:
	MailService();
	MailService(float c, int n, float s, float w);
	virtual void Calculate_Charges(float w);
	virtual void setDays();
	void set_Weight(float w);
	virtual void Display();
};

//Urgent Mail Service class
class Urgent :public MailService {
private:
	float urgent; //Urgent service charges
public:
	Urgent();
	void _setWeight(float w);
	void Calculate_Charges(float w);
	void stampCharges(float s);
	void SetDays();
	void Display();
};

//Regular Mail Service class
class Regular :public MailService {
public:
	void Calculate_Charges(float w);
	void stampCharges(float s);
	void SetDays();
	void Display();
};

//Mail class
class Mail {
protected:
	int ID; //Unique id
	MailService mail_Service; //To get information about mail service
	Customer _sender; //To get sender's information
	Customer _receiver; ////To get reciever's information
public:
	Mail();
	Mail(MailService ms, Customer sen, Customer rec);
	void setID();
	void setMail_Service(MailService ms);
	void set_Sender(Customer sen);
	void set_Receiver(Customer rec);
	int getID();
	MailService getMail_Service();
	Customer get_Sender();
	Customer get_Receiver();
	void Display();
};

//Returned mail class
class ReturnedMail : public Mail {
private:
	Mail mail;
public:
	void setReturned(Mail m);
	Mail Returned();
};

//Bounced mail class
class BouncedMail :public Mail {
private:
	Mail mail;
public:
	void setBounced(Mail m);
	Mail Bounced();
};


