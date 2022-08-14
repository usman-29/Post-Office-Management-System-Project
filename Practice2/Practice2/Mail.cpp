#include "Mail.h"

//MailService Class Functions
//Default constructor
MailService::MailService() {
	_charges = 0;
	NoOfDays = 0;
	_stamp = 0;
	_weigh = 0;
}

//Parameterised constructor
MailService::MailService(float c, int n, float s, float w) :_charges(c), NoOfDays(n), _stamp(s), _weigh(w) {

}

//Function to calculate charges for mail
void MailService::Calculate_Charges(float w) {}

//Function to calculate number of days for delivery of mail
void MailService::setDays() {}

//Function to set weight
void MailService::set_Weight(float w) {
	_weigh = w;
}

//Display function
void MailService::Display() {
	cout << "Mail weight: " << _weigh << endl;
	cout << "Registration charges: Rs.30" << endl;
	cout << "Stamp charges: " << _stamp << endl;
	cout << "Total Charges: " << _charges << endl;
	cout << "No of days to deliver this mail : " << NoOfDays << endl;
}

//Urgent Class Functions
//Default constructor
Urgent::Urgent() {
	urgent = 0;
}

//Function to set Weight
void Urgent::_setWeight(float w) {
	set_Weight(w);
}

//Function to calculate charges for Urgent mail service
void Urgent::Calculate_Charges(float w) {
	//Charges depending upon mail weight (gm)
	if (w <= 250) {
		_charges = 50;
	}
	else if (w <= 500) {
		_charges = 80;
	}
	else {
		_charges = 100;
	}
	_charges += 30; //Registration charges
	urgent = _charges * 20 / 100; //20% extra
	_charges = _charges + urgent; //Total charges
}

//Function to get stamp charges
void Urgent::stampCharges(float s) {
	_stamp = s; //to get stamp charges
	_charges += _stamp;
}

//Function to set number of days for urgent mail service
void Urgent::SetDays() {
	NoOfDays = 1;
}

//Display function
void Urgent::Display() {
	cout << "Mail Service: Urgent" << endl;
	cout << "Urgent mail charges: " << urgent << endl;
	MailService::Display();
}

//Function to calculate charges for regular mail service
void Regular::Calculate_Charges(float w)
{
	//Charges depending upon mail weight (gm)
	if (w <= 250) {
		_charges = 50;
	}
	else if (w <= 500) {
		_charges = 80;
	}
	else {
		_charges = 100;
	}
	_charges += 30; //Registration charges
}

//Function to get stamp charges
void Regular::stampCharges(float s) {
	_stamp = s; //to get stamp charges
	_charges += _stamp;
}

//Function to set number of days for regular mail service
void Regular::SetDays() {
	srand((unsigned int)time(NULL));
	NoOfDays = 1 + rand() % 7;
}

//Display function
void Regular::Display() {
	cout << "Mail Service: Regular" << endl;
	MailService::Display();
}

//Mail Class Functions
//Default constructor
Mail::Mail() {
	ID = 0;
}

//Parameterised constructor
Mail::Mail(MailService ms, Customer sen, Customer rec) : mail_Service(ms), _sender(sen), _receiver(rec) {
	ID = 0;
}

//SET & GET Functions
void Mail::setID() {
	srand(time(0));
	int stack[100];
	for (int i = 0; i < 100; i++) {
		stack[i] = ((rand() * rand()) % 5000) + 100;
		if (stack[i] < 0) {
			stack[i] *= (-1);
		}
	}
	int x = rand() % 100;
	ID = stack[x];
}
void Mail::setMail_Service(MailService ms) {
	mail_Service = ms;
}
void Mail::set_Sender(Customer sen) {
	_sender = sen;
}
void Mail::set_Receiver(Customer rec) {
	_receiver = rec;
}
int Mail::getID() {
	return ID;
}
MailService Mail::getMail_Service() {
	return mail_Service;
}
Customer Mail::get_Sender() {
	return _sender;
}
Customer Mail::get_Receiver() {
	return _receiver;
}

//Display function
void Mail::Display() {
	cout << "Sender information: " << endl;
	_sender.Display();
	cout << endl;
	cout << "Reciever information: " << endl;
	_receiver.Display();
	cout << endl;
	cout << "Mail service information: " << endl;
	cout << "ID: " << getID() << endl;
	mail_Service.Display();
}

//Returned Mail Class Functions
//SET Function
void ReturnedMail::setReturned(Mail m) {
	mail = m;
}

//Mail returned to post office
Mail ReturnedMail::Returned() {
	return mail;
}

//Bounced Mail Class Functions
//SET Function
void BouncedMail::setBounced(Mail m) {
	mail = m;
}

//Mail sent to post office
Mail BouncedMail::Bounced() {
	return mail;
}
