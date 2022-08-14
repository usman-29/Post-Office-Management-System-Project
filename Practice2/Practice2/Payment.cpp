#include "Payment.h"

//Expiry Date CLass Functions
//Default constructor
ExpiryDate::ExpiryDate() {
	month = 0;
	year = 0;
}

//Parameterised constructor
ExpiryDate::ExpiryDate(int m, int y) :month(m), year(y) {

}

//SET & GET Functions
void ExpiryDate::setMonth(int m) {
	month = m;
}
void ExpiryDate::setYear(int y) {
	year = y;
}

//Card Class Functions
//Default constructor
Card::Card() {
	CardHolder = "";
	CardNo = 0;
}

//SET functions
void Card::setHolder(string holder) {
	CardHolder = holder;
}
void Card::setCard(long long int card) {
	CardNo = card;
}
void Card::setExpiry(int m, int y) {
	expiry_date.setMonth(m);
	expiry_date.setYear(y);
}

//Function to input PIN code
void Card::inputPIN() {
	for (int i = 0; i < 4; i++)
	{
		PinCode[i] = _getch();
		cout << "*";
	}
}

//Payment Class Functions
//Default constructor
Payment::Payment() {
	Done = 0;
}

//Parameterised constructor
Payment::Payment(int d) :Done(d) {

}

//Function to input card details
void Payment::Input_Card_Details() {
	string holder; //Card holder name
	long long int card; //card number
	int m, y; //month & year for expiry date
	cout << "Card holder name: ";
	cin.ignore();
	getline(cin, holder);
	cardDetails.setHolder(holder);
	cout << "Card number: ";
	cin >> card;
	cardDetails.setCard(card);
	cout << "Expiry date(mm/yy): ";
	cin >> m >> y;
	cardDetails.setExpiry(m, y);
	cout << "PIN: ";
	cardDetails.inputPIN();
	Done++;
}

//Function to confirm payment done or not
bool Payment::isPayment_Done() {
	if (Done > 0) {
		return true;
	}
	else {
		return false;
	}
}