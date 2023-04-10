#ifndef CONVERTYPE_H
#define CONVERTYPE_H

#include "Components.h"

/*			Convert enum to string function			*/
std::string weekday_to_string(const Weekday& weekday);

Weekday string_to_weekday(const std::string& str);

std::string session_to_string(const Session& session);

Session string_to_session(const std::string& str);

std::string gender_to_string(const Gender& gender);

Gender string_to_gender(const std::string& str);

#endif // !CONVERTYPE_H
