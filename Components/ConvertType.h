#ifndef CONVERTYPE_H
#define CONVERTYPE_H

#include "Components.h"

/*			Convert enum to string function			*/
string weekday_to_string(const Weekday& weekday);

Weekday string_to_weekday(const string& str);

string session_to_string(const Session& session);

Session string_to_session(const string& str);

string gender_to_string(const Gender& gender);

Gender string_to_gender(const string& str);

Date string_to_date(const string& str);

#endif // !CONVERTYPE_H
