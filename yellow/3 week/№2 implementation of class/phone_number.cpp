#include "phone_number.h"

PhoneNumber::PhoneNumber(const string& international_number)
{
	istringstream is(international_number);

	char sign = is.get();
	getline(is, country_code_, '-');
	getline(is, city_code_, '-');
	getline(is, local_number_);

	if (sign != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty()) {
		throw invalid_argument("Phone number must begin with '+' symbol and contain 3 parts separated by '-' symbol: "
			+ international_number);
	}

	/*bool error = true;
	if (!international_number.empty()&&international_number.at(0) == '+')
	{
		size_t pos1 = international_number.find('-');
		if (pos1 != string::npos)
		{
			size_t pos2 = international_number.find('-', pos1 + 1);
			if (pos2 != string::npos && pos2 - pos1 > 1 && pos2 != international_number.length() - 1)
			{
				error = false;

				country_code_ = international_number.substr(1, pos1 - 1);
				city_code_ = international_number.substr(pos1 + 1, pos2 - pos1 - 1);
				local_number_ = international_number.substr(pos2 + 1, international_number.length() - pos2);
			}
		}
	}

	if (error)
		throw invalid_argument("Invalid argument");*/
}

string PhoneNumber::GetCountryCode() const { return country_code_; }

string PhoneNumber::GetCityCode() const { return city_code_; }

string PhoneNumber::GetLocalNumber() const { return local_number_; }

string PhoneNumber::GetInternationalNumber() const { return '+' + country_code_ + "-" + city_code_ + "-" + local_number_; }