//	cuber_test_suites.cpp
//	followers.cpp
//	Laura Lundell & Khan Howe
//	For CS 311 Fall 2018
//	Started: 11/29/18
//	Updated: 12/4/18
//	Source for cuber_test_suites.cpp
//	Tests for class Cuber: test suites
//	Exercise B: Writing a Test Suite
//	Uses the "Catch" unit-testing framework, version 2
//	Requires cuber_test_main.cpp, catch.hpp, cuber.h
/*	Sources used:
*			Dr. Chappell's slides on Project 8 thoughts and his skeleton file
*
*/

// Includes for code to be tested
#include "cuber.h"         // For class Cuber
#include "cuber.h"         // Double inclusion test

#define CATCH_CONFIG_FAST_COMPILE
                             // Disable some features for faster compile
#include "catch.hpp"         // For the "Catch" unit-testing framework

// Additional includes for this test program


// *********************************************************************
// Test Cases
// *********************************************************************


TEST_CASE("TEST LARGE RANGE OF VALUES")
{
    Cuber cc;
    {
        INFO("-5 cubed is -125");
        REQUIRE(cc(-5) == -125);
    }
    {
        INFO("0 cubed is 0");
        REQUIRE(cc(0)==0);
    }
    {
        INFO("1 cubed is 1");
        REQUIRE(cc(1)==1);
    }
    {
        INFO("5 cubed is 125");
        REQUIRE(cc(5)==125);
    }
    {
        INFO("1000 cubed is 1 Billion");
        REQUIRE(cc(1000)==1000000000);
    }
    {
        INFO("-1000 cubed is -1 Billion");
        REQUIRE(cc(-1000)== -1000000000);
    }
    {
        INFO("pi cubed is 30.959144000000002");
        REQUIRE(cc(3.14)==30.959144000000002);
    }

}

TEST_CASE("Test negative ints")
{
	Cuber cc;
	{
		INFO("-5 cubed is -125");
		REQUIRE(cc(-5)==-125);
	}
	{
		INFO("-1 cubed is -1");
		REQUIRE(cc(-1)==-1);
	}
}

TEST_CASE("Test doubles")
{
	Cuber cc;
	{
		INFO("1.1 cubed is 1.331");
		REQUIRE(cc(1.1)== Approx(1.331));
	}
	{
		INFO("2.3 cubed is 12.167");
		REQUIRE(cc(2.3)== Approx(12.167));
	}

}
