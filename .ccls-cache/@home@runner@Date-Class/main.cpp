#include <iostream>
#include "date.h"

int main() {
  //Test 1 : default date
    Date date1;
  std::cout << "default Date (Format 1): ";
  date1.printFormat1();
  std::cout << std::endl;

  // test 2 : date with parameters
  Date date2(12, 25, 2021);
  std::cout << "Parameterized Date (Format 2): ";
  date2.printFormat2();
  std::cout << std::endl;

  // test 3 : date with parameters
  date2.setDate(5, 10, 2023);
  std::cout << "After setDate() (Format 3): ";
  date2.printFormat3();  // Format 3: 10 May 2023
  std::cout << std::endl;

  //test 4, 5, 6 : invalid dates
  try {
      date2.setDate(13, 45, 2018);
  } catch (const std::invalid_argument&) {
      std::cout << "Invalid date 13/45/2018!" << std::endl;
  }

  try {
    date2.setDate(4, 31, 2000); 
  } catch (const std::invalid_argument&) {
    std::cout << "Invalid date 4/31/2000!" << std::endl;
  }

  try {
    date2.setDate(2, 29, 2009);

  } catch (const std::invalid_argument&) {
      std::cout << "Invalide date 2/29/2009!" << std::endl;
  }

  //test 7 and 8, subtracting dates
  Date date3(4, 10, 2014);
  Date date4(4, 18, 2014);
  std::cout << "Days between 4/10/2014 and 4/18/2014: " << date4 - date3 << " days" << std::endl;

  Date date5(2, 2, 2006);
  Date date6(11, 10, 2003);
  std::cout << "Days between 2/2/2006 and 11/10/2003: " << date5 - date6 << " days" << std::endl;

  //test 9 and 10, pre increment and post increment
  Date date7(2, 29, 2008);
  --date7;
  std::cout << "After Pre-Decrement : ";
  date7.printFormat3();
  std::cout << std::endl;

  ++date7;
  std::cout << "After Pre-Increment : ";
  date7.printFormat3();
  std::cout << std::endl;

  // test 11, 12, 13, 14 - pre increment and post decrement
  Date date8(12, 31, 2024);
  date8--;  // Post-decrement
  std::cout << "After Post-Decrement : ";
  date8.printFormat3();
  std::cout << std::endl;

  date8++;  // Post-increment
  std::cout << "After Post-Increment : ";
  date8.printFormat3();
  std::cout << std::endl;

  // Test 15-16: Input and output using >> and <<
  Date date9;
  std::cout << "Enter a date (month day year): ";
  std::cin >> date9;
  std::cout << "Date entered (Format 2): " << date9 << std::endl;

        return 0;
    }