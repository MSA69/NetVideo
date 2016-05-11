/*
  Customer.cpp

  Definition file for Customer class
*/

#include "Customer.hpp"
#include "Video.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// constructor
Customer::Customer(const std::string& name)
    : name(name)
{ }

// customer name
std::string Customer::getName() const {

    return name;
}

// add a rental to this customer
void Customer::addRental(const Rental& rental) {

    rentals.push_back(rental);
}

double Customer::rentalPrice(const Rental& r)
{
	
        switch(r.tVideo().getCode()) 
		{
            case Video::REGULAR:
            if (r.tDaysRented() > 2)
			{
				return (2+ (r.tDaysRented() - 2) * 1.5);
			}
			return 2;
            break;

            case Video::NEW_RELEASE:
			return (r.tDaysRented() * 3);
            break;

            case Video::CHILDRENS:
            if (r.tDaysRented() > 3)
			{
				return(1.5 + (r.tDaysRented() - 3) * 1.5);
			}
			return 1.5;
            break;
        }
}

// customer rental statement
std::string Customer::statement() const {

    // customer name
    std::string result("Rental Record for ");
    result += getName();
    result += "\n";

    // rentals
    double totalAmount = 0;

    for (std::vector<Rental>::const_iterator it = rentals.begin(); it != rentals.end(); ++it) 
	{


        // title of rental
        result += "\t";
        result += it->getVideo().getTitle();
        result += "\t";

        double videoCost = rentalPrice(it);

        // amount of rental
        std::ostringstream out_str_stream;
        out_str_stream << videoCost;
        result += out_str_stream.str();
        result += "\n";

        totalAmount += videoCost;
    }

    // total amount owed
    result += "Amount owed is: ";
    std::ostringstream out_str_stream;
    out_str_stream << totalAmount;
    result += out_str_stream.str();
    result += "\n";



    return result;
}
