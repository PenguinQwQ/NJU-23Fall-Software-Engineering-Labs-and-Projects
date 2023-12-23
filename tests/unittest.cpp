#include "address.hh"
#include "ambulance.hh"
#include "appointment.hh"
#include "doctor.hh"
#include "driver.hh"
#include "hospital.hh"
#include "nurse.hh"
#include "patient.hh"
#include "person.hh"
#include "global.hh"
#include <gtest/gtest.h>
// https://google.github.io/googletest/reference/assertions.html

namespace
{
    
    // Submodule 1: global.h Unit Testing
    TEST(global_h, strToNum)
    {
        std::string str;
        str = "1";
        EXPECT_EQ(1, strToNum(str));
        str = "123";
        EXPECT_EQ(123, strToNum(str));
        str = "1145";
        EXPECT_EQ(1145, strToNum(str));
        str = "514";
        EXPECT_EQ(514, strToNum(str));
        str = "1919810";
        EXPECT_EQ(1919810, strToNum(str));
        str = "23333";
        EXPECT_NE(2333, strToNum(str));
        // corner case test
      //  str = "-294832";
      //  EXPECT_EQ(-294832, strToNum(str));
        str = "0";
        EXPECT_EQ(0, strToNum(str));
        // INT_MAX case test
        str = "2147483647";
        EXPECT_EQ(2147483647, strToNum(str));
    }
    TEST(global_h, power) //n^exp
    {
        // Simple Test for Power function
        EXPECT_EQ(4, power(2,2));
        EXPECT_EQ(8, power(2,3));
        EXPECT_EQ(16, power(2, 4));
        EXPECT_EQ(1024, power(2, 10));
        EXPECT_EQ(1, power(2,0));
        EXPECT_EQ(27, power(3,3));
        // Corner Case Test for Power function
        EXPECT_EQ(4, power(-2,2));
        EXPECT_EQ(1, power(-2,0));
        EXPECT_LE((1 << 20) - 1, power(2, 20));
        EXPECT_EQ(7 * 7 * 7 * 7 * 7, power(7, 5));
    }
    //Submodule 2: address
    TEST(address_addToStr, addToStr)
    {
        address addr;
        addr.takeInput();
        std::string str1 = addr.addToStr();
        std::string str2 = "x`y`Nanjing`Jiangsu`210016`China";
        EXPECT_EQ(str1, str2);
    }
    TEST(address_print, print)
    {
        address addr;
        addr.takeInput();
        addr.print();
    }
    
    // Module 3: Summarized Testing (Down-Top Approach)
    TEST(Summarized_Test1, printDetails) //as person itself is abstract type, we use doctor as a substitution
    {
        doctor d;
        d.addPerson(); //add person
        d.printDetails();
        // Combining Test from down to top.
        // Testing age variable in doctor.hh module
        EXPECT_EQ(d.age, 30);
        std::string str = "Alex";
        // Testing  firstName string, derived from person.hh module.
        EXPECT_EQ(d.firstName,  str);
        str = "Steve";
        // Testing  lastName string, derived from person.hh module.
        EXPECT_EQ(d.lastName, str);
        // Testing gender char in doctor.hh module
        EXPECT_EQ(d.gender, 'M');
        // Testing mobNumber in doctor.hh module
        str = "20";
        EXPECT_EQ(d.mobNumber, str);
        // Testing address component, derived from address module
        EXPECT_EQ(d.add.city, "Nanjing");
        EXPECT_EQ(d.add.country, "China");
        EXPECT_EQ(d.add.state, "Jiangsu");
        EXPECT_EQ(d.add.pinCode, "210016");
        EXPECT_EQ(d.add.line1, "x");
        EXPECT_EQ(d.add.line2, "y");
    }
    TEST(Summarized_Test2, printDetails) //check patients, the same type
    {
        patient p;
        p.addPerson(); //add person
        p.printDetails();
        // Combining Test from down to top.
        // Testing age variable in patients.hh module
        EXPECT_EQ(p.age, 30);
        std::string str = "Lang";
        // Testing  firstName string, derived from person.hh module.
        EXPECT_EQ(p.firstName,  str);
        str = "Lin";
        // Testing  lastName string, derived from person.hh module.
        EXPECT_EQ(p.lastName, str);
        // Testing gender char in patients.hh module
        EXPECT_EQ(p.gender, 'F');
        // Testing mobNumber in patients.hh module
        str = "20";
        EXPECT_EQ(p.mobNumber, str);
        // Testing address component, derived from address module
        EXPECT_EQ(p.add.city, "Nanjing");
        EXPECT_EQ(p.add.country, "China");
        EXPECT_EQ(p.add.state, "Jiangsu");
        EXPECT_EQ(p.add.pinCode, "210016");
        EXPECT_EQ(p.add.line1, "x");
        EXPECT_EQ(p.add.line2, "y");
    }
}

