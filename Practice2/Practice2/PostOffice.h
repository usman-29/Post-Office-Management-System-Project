#pragma once
//Post office
#include<iostream>
#include<fstream>
#include"Mail.h"
#include"Parcel.h"
using namespace std;

//Post office class
class PostOffice {
private:
	Invoice parcel; //Parcel invoice
	Mail mail; //Mail invoice
	ReturnedMail r; //Returned mail
	BouncedMail b; //Bounced mail
public:
	PostOffice();
	PostOffice(Invoice p, Mail m);
	void setParcel(Invoice p);
	void setMail(Mail m);
	Invoice getParcel();
	Mail getMail();
	void returnedMail(ReturnedMail m);
	void bouncedMail(BouncedMail m);
	void ParcelFile();
	void trackParcel();
	void MailFile();
	void trackMail();
};

//Shipment class
class Shipment {
private:
	PostOffice post;
	Invoice p;
public:
	void setParcel();
	void shipped();
};


//GPO class
class GPO {
private:
	PostOffice post;
	Mail m;
public:
	void setMail();
	Mail getMail();
};


