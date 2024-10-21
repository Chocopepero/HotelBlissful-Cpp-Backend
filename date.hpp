#pragma once

#include <string>
#include <sstream>

class Date {
public:
  Date(int month = 1, int day = 1, int year = 1970)
      : _month{month}, _day{day}, _year{year} {}

  Date(const std::string &date) {
    int year, month, day;
    std::stringstream ss(date);
    char delimiter;
    ss >> year >> delimiter >> month >> delimiter >> day;

    _year = year;
    _month = month;
    _day = day;
  }

  int get_Month() const { return _month; }
  int get_Day() const { return _day; }
  int get_Year() const { return _year; }

    bool operator<(const Date &rhs) const noexcept {
        if (_year != rhs._year) {
            return _year < rhs._year;  // Compare years first
        }
        if (_month != rhs._month) {
            return _month < rhs._month; // If years are equal, compare months
        }
        return _day < rhs._day; // If months are equal, compare days
    }


  bool operator==(const Date &rhs) const noexcept {
    return (_month == rhs._month && _day == rhs._day && _year == rhs._year);
  }

private:
  int _month;
  int _day;
  int _year;
};
