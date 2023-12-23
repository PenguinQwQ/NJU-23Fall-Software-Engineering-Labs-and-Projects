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
        str = "-294832";
        EXPECT_EQ(-294832, strToNum(str));
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
    // Module 3: Overall Testing
    
}

