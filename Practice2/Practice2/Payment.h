#pragma once
//Payment Method
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

//Expiry date class
class ExpiryDate {
private:
	int month; //Month
	int year; //Year
public:
	ExpiryDate();
	ExpiryDate(int m, int y);
	void setMonth(int m);
	void setYear(int y);
};

//Card class
class Card {
private:
	string CardHolder; //Card holder name
	long long int CardNo; //Card number
	ExpiryDate expiry_date; //Expiry date of card
	char PinCode[4]; //PIN code
public:
	Card();
	void setHolder(string holder);
	void setCard(long long int card);
	void setExpiry(int m, int y);
	void inputPIN();
};

//Payment class
class Payment {
private:
	int Done; //To confirm payment
	Card cardDetails; //Card details
public:
	Payment();
	Payment(int d);
	void Input_Card_Details();
	bool isPayment_Done();
};


