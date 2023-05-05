#include "ConvertType.h"
#include "Date.h"

/*			Convert enum to string function			*/
string weekday_to_string(const Weekday& weekday) {
	switch (weekday)
	{
	case MON:
		return "MON";
	case TUE:
		return "TUE";
	case WED:
		return "WED";
	case THU:
		return "THU";
	case FRI:
		return "FRI";
	case SAT:
		return "SAT";
	case SUN:
		return "SUN";
	}
	return "\n";
}

Weekday string_to_weekday(const string& str) {
	if (str == "MON")
		return MON;
	else if (str == "TUE")
		return TUE;
	else if (str == "WED")
		return WED;
	else if (str == "THU")
		return THU;
	else if (str == "FRI")
		return FRI;
	else if (str == "SAT")
		return SAT;
	else
		return SUN;
}

string session_to_string(const Session& session) {
	switch (session) {
	case S1:
		return "7:30";
	case S2:
		return "9:30";
	case S3:
		return "13:30";
	case S4:
		return "15:30";
	}
	return "\n";
}

Session string_to_session(const string& str) {
	if (str == "7:30")
		return S1;
	else if (str == "9:30")
		return S2;
	else if (str == "13:30")
		return S3;
	return S4;
}

string gender_to_string(const Gender& gender) {
	if (gender == male)
		return "Male";
	else if (gender == female)
		return "Female";
	return "\n";
}

Gender string_to_gender(const string& str) {
	if (str == "Male")
		return male;
	return female;
}

Date string_to_date(const string& str) {
	string dayStr, monthStr, yearStr;
	std::stringstream ss(str);
	getline(ss, dayStr, '/');
	getline(ss, monthStr, '/');
	getline(ss, yearStr);

	unsigned short day = static_cast<unsigned short>(std::stoi(dayStr));
	unsigned short month = static_cast<unsigned short>(std::stoi(monthStr));
	unsigned int year = static_cast<unsigned int>(std::stoul(yearStr));
	Date date(day, month, year);
	return date;
}