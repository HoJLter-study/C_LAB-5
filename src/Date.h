#pragma once
#include <iostream>

class Date {
private:
	uint8_t day;
	uint8_t month;
	uint16_t year;

public:
	Date();
	Date(uint8_t, uint8_t, uint16_t);

	bool operator>(const Date&);
	bool operator<(const Date&);
	bool operator<=(const Date&);
	bool operator>=(const Date&);
	bool operator==(const Date&);
	bool operator!=(const Date&);

	int getDay();
	int getMonth();
	int getYear();

	void setDay(uint8_t);
	void setMonth(uint8_t);
	void setYear(uint16_t);

	bool isStudyTime();
};


uint8_t daysInMonth(uint8_t, uint16_t);


std::ostream& operator<< (std::ostream&, Date);
std::istream& operator>> (std::istream&, Date&);

