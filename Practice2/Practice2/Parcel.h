#pragma once
//Parcel orders
#include<iostream>
#include<string>
#include <limits.h>
using namespace std;

//Address Class
class Address {
private:
	string City; //City name
	string Area; //Area inside city
	int StreetNo; //Street number
	int HouseNo; //House number
	int PostalCode; //Postal Code
public:
	Address();
	Address(string city, string area, int street, int house, int postal);
	void setCity(string city);
	void setArea(string area);
	void setStreet(int street);
	void setHouse(int house);
	void setPostal(int postal);
	string getCity();
	string getArea();
	int getStreet();
	int getHouse();
	int getPostal();
	void inputAddress();
	void Display();
};

//Customer class
class Customer {
private:
	string Name; //Name
	Address address; //Address
	long long int PhoneNo; //Phone number
public:
	Customer();
	Customer(string name, Address add, long int phone);
	void setName(string name);
	void setAddress(Address add);
	void setPhone(long long int phone);
	string getName();
	Address getAddress();
	long long int getPhone();
	void inputCustomer();
	void Display();
};

//Date class
class Date {
private:
	int day; //Day
	int month; //Month
	int year; //Year
public:
	Date();
	Date(int d, int m, int y);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	int getDay();
	int getMonth();
	int getYear();
	void Urgent_Date();
	void Normal_Date();
	void inputDate();
	void Display();
};

//Dimension class
class Dimension {
private:
	float length; //Length in cm
	float width; //Width in cm
	float height; //Height in cm
public:
	Dimension();
	Dimension(float l, float w, float h);
	void setLength(float l);
	void setWidth(float w);
	void setHeight(float h);
	float getLength();
	float getWidth();
	float getHeight();
	void inputDimension();
	void Display();
};

//Parcel class
class Parcel {
private:
	int parcel_ID; //Parcel ID
	float parcel_Weight; //Parcel weight in kg
	Dimension parcel_Dimension; //Parcel parcel_Dimensionension
public:
	Parcel();
	Parcel(int id, float w, Dimension d);
	void setID();
	void setWeight(float w);
	void setDimension(Dimension d);
	int getID();
	float getWeight();
	Dimension getDimension();
	void inputParcel();
	void Display();
};

//Charges class
class Charges {
private:
	float s; //Stamp charges
	float charges; //Delivery charges
	Parcel w; //To get weight
public:
	Charges();
	void calculate_charges(float w);
	void stampCharges(float _stamp);
	void Urgent_Parcel_Charges();
	float getCharges();
	void Display();
};

//Invoice class
class Invoice {
private:
	Customer Sender; //Sender information 
	Customer Reciever; //Reciever information 
	Date date; //Delivery date
	Parcel parcel; //Parcel information 
	Charges charges; //Charges information
public:
	Invoice();
	Invoice(Customer s, Customer r, Date d, Parcel p, Charges c);
	void setSender(Customer s);
	void setReciever(Customer r);
	void setDate(Date d);
	void setParcel(Parcel p);
	Customer getSender();
	Customer getReciever();
	Parcel getParcel();
	int getID();
	void Display();
};

