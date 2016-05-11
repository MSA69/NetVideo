/*
  Customer_t.cpp

  Test program for class Customer
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <string>

#include "Customer.hpp"

int main() {

    // no rental
    {
        Customer customer("Fred");

        assert(customer.getName() == "Fred");

        // test using literal string
        assert(customer.statement() == "Rental Record for Fred\nAmount owed is: 0\n");
    }

    // no rental
    {
        Customer customer("Fred");

        assert(customer.getName() == "Fred");

        // test using external file
        std::ifstream finput("Customer_t.norental.txt");
        std::ostringstream out;
        out << finput.rdbuf();

        assert(customer.statement() == out.str());
    }

    // one rental
    {
        Customer customer("Fred");

        assert(customer.getName() == "Fred");

        // one rental
        customer.addRental(Rental(Video("A", Video::REGULAR), 1));

        // test using external file
        std::ifstream finput("Customer_t.onerental.txt");
        std::ostringstream out;
        out << finput.rdbuf();

        assert(customer.statement() == out.str());
    }

    // two rentals
    {
        Customer customer("Fred");

        // Create movies
        Video lotr("Lord of the Rings", Video::REGULAR);
        Video hp("Harry Potter", Video::CHILDRENS);

        // Create rentals of these movies
        Rental r1(lotr, 10);
        Rental r2(hp, 5);

        // add two rentals
        customer.addRental(r1);
        customer.addRental(r2);

        // test using external file
        std::ifstream finput("Customer_t.tworental.txt");
        std::ostringstream out;
        out << finput.rdbuf();
        assert(customer.statement() == out.str());
    }

    return 0;
}
