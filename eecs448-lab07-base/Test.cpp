#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "LinkedListOfInts.h"
#include <iostream>

TEST_CASE( "isEmpty() can determine if the linked list is empty", "[isEmpty]" )
{
  LinkedListOfInts testlist;
  SECTION( "empty list returns true" )
  {
    REQUIRE( testlist.isEmpty() == true );
    if ( testlist.isEmpty() == true )
    {
      std::cout << "passed: empty list returns true" << '\n';
    }
  }
  SECTION( "after addBack returns false" )
  {
    testlist.addBack(1);
    REQUIRE( testlist.isEmpty() == false );
    if ( testlist.isEmpty() == false )
    {
      std::cout << "passed: after addBack returns false" << '\n';
    }
  }
  SECTION( "after addFront returns false" )
  {
    testlist.addFront(1);
    REQUIRE( testlist.isEmpty() == false );
    if ( testlist.isEmpty() == false )
    {
      std::cout << "passed: after addFront returns false" << '\n';
    }
  }
  SECTION( "after removeBack of single node list returns true" )
  {
    testlist.addBack(2);
    testlist.removeBack();
    REQUIRE( testlist.isEmpty() == true );
    if ( testlist.isEmpty() == true )
    {
      std::cout << "passed: after removeBack of single node list returns true" << '\n';
    }
  }
  SECTION( "after removeFront of single node list returns true" )
  {
    testlist.addFront(2);
    testlist.removeFront();
    REQUIRE( testlist.isEmpty() == true );
    if ( testlist.isEmpty() == true )
    {
      std::cout << "passed: after removeFront of single node list returns true" << '\n';
    }
  }
  SECTION( "after removeBack of multi-node list returns false" )
  {
    testlist.addBack(2);
    testlist.addBack(3);
    testlist.removeBack();
    REQUIRE( testlist.isEmpty() == false );
    if ( testlist.isEmpty() == false )
    {
      std::cout << "passed: after removeBack of multi-node list returns false" << '\n';
    }
  }
  SECTION( "after removeBack of multi-node list returns false" )
  {
    testlist.addFront(2);
    testlist.addFront(3);
    testlist.removeBack();
    REQUIRE( testlist.isEmpty() == false );
    if ( testlist.isEmpty() == false )
    {
      std::cout << "passed: after removeBack of multi-node list returns false" << '\n';
    }
  }
}

TEST_CASE( "can determine size of linked list", "[size]" )
{
  LinkedListOfInts testlist;
  SECTION( "size of empty list is zero" )
  {
    REQUIRE( testlist.size() == 0 );
    if ( testlist.size() == 0 )
    {
      std::cout << "passed: size of empty list is zero" << '\n';
    }
  }
  SECTION( "addBack to empty list, size is 1" )
  {
    testlist.addBack(3);
    REQUIRE( testlist.size() == 1 );
    if ( testlist.size() == 1 )
    {
      std::cout << "passed: addBack to empty list, size is 1" << '\n';
    }
  }
  SECTION( "repeatedly called addBack, size = (size + # times called)" )
  {
    testlist.addBack(3);
    testlist.addBack(4);
    testlist.addBack(5);
    REQUIRE( testlist.size() == 3 );
    if ( testlist.size() == 3 )
    {
      std::cout << "passed: repeatedly called addBack, size = (size + # times called)" << '\n';
    }
  }
  SECTION( "addFront to empty list, size is 1" )
  {
    testlist.addFront(3);
    REQUIRE( testlist.size() == 1 );
    if ( testlist.size() == 1 )
    {
      std::cout << "passed: addFront to empty list, size is 1" << '\n';
    }
  }
  SECTION( "repeatedly called addFront, size = (size + # times called)" )
  {
    testlist.addFront(3);
    testlist.addFront(4);
    testlist.addFront(5);
    REQUIRE( testlist.size() == 3 );
    if ( testlist.size() == 3 )
    {
      std::cout << "passed: repeatedly called addFront, size = (size + # times called)" << '\n';
    }
  }
  SECTION( "after removeBack size = (size - 1)" )
  {
    testlist.addBack(3);
    testlist.addBack(4);
    testlist.addBack(5);
    testlist.removeBack();
    REQUIRE( testlist.size() == 2 );
    if ( testlist.size() == 2 )
    {
      std::cout << "passed: after removeBack size = (size - 1)" << '\n';
    }
  }
  SECTION( "addBack repeatedly called, size = (size - # times called)" )
  {
    testlist.addBack(3);
    testlist.addBack(4);
    testlist.addBack(5);
    testlist.removeBack();
    testlist.removeBack();
    REQUIRE( testlist.size() == 1 );
    if ( testlist.size() == 1 )
    {
      std::cout << "passed: addBack repeatedly called, size = (size - # times called)" << '\n';
    }
  }
  SECTION( "after removeFront size = (previous size - 1)" )
  {
    testlist.addFront(3);
    testlist.addFront(4);
    testlist.addFront(5);
    testlist.removeFront();
    REQUIRE( testlist.size() == 2 );
    if ( testlist.size() == 2 )
    {
      std::cout << "passed: after removeFront size = (previous size - 1)" << '\n';
    }
  }
  SECTION( "addFront repeatedly called, size = (size - # times called)" )
  {
    testlist.addFront(3);
    testlist.addFront(4);
    testlist.addFront(5);
    testlist.removeFront();
    testlist.removeFront();
    REQUIRE( testlist.size() == 1 );
    if ( testlist.size() == 1 )
    {
      std::cout << "passed: addFront repeatedly called, size = (size - # times called)" << '\n';
    }
  }
}

TEST_CASE( "can search for value within linked list", "[search]" )
{
  LinkedListOfInts testlist;
  SECTION( "empty list returns false" )
  {
    REQUIRE( testlist.search(0) == false );
    if ( testlist.search(0) == false )
    {
      std::cout << "passed: empty list returns false" << '\n';
    }
  }
  SECTION( "returns false when value is not in single node list" )
  {
    testlist.addFront(3);
    REQUIRE( testlist.search(0) == false );
    if ( testlist.search(0) == false )
    {
      std::cout << "passed: returns false when value is not in single node list" << '\n';
    }
  }
  SECTION( "returns false when value is not in multi-node list" )
  {
    testlist.addFront(3);
    testlist.addBack(4);
    testlist.addFront(5);
    REQUIRE( testlist.search(1) == false );
    if ( testlist.search(1) == false )
    {
      std::cout << "passed: returns false when value is not in multi-node list" << '\n';
    }
  }
  SECTION( "returns true when value is in single node list" )
  {
    testlist.addFront(3);
    REQUIRE( testlist.search(3) == true );
    if ( testlist.search(3) == true )
    {
      std::cout << "passed: returns true when value is in single node list" << '\n';
    }
  }
  SECTION( "returns true when value is in multi-node list" )
  {
    testlist.addFront(3);
    testlist.addBack(1);
    testlist.addFront(2);
    REQUIRE( testlist.search(1) == true );
    if ( testlist.search(1) == true )
    {
      std::cout << "passed: returns true when value is in multi-node list" << '\n';
    }
  }
}

TEST_CASE( "can add a new element to back of linked list", "[addBack]" )
{
  LinkedListOfInts testlist;
  SECTION( "size increases" )
  {
    testlist.addBack(6);
    REQUIRE( testlist.size() == 1 );
    if ( testlist.size() == 1 )
    {
      std::cout << "passed: size increases" << '\n';
    }
  }
  SECTION( "adds new int to back of list" )
  {
    testlist.addBack(6);
    REQUIRE( (testlist.toVector()).back() == 6 );
    if ( (testlist.toVector()).back() == 6 )
    {
      std::cout << "passed: adds new int to back of list" << '\n';
    }
  }
  SECTION( "repeatedly called to add more than one to back" )
  {
    testlist.addBack(6);
    testlist.addBack(7);
    testlist.addBack(8);
    REQUIRE( (testlist.toVector()).back() == 8 );
    if ( (testlist.toVector()).back() == 8 )
    {
      std::cout << "passed: repeatedly called to add more than one to back" << '\n';
    }
  }
}

TEST_CASE( "can add a new element to front of linked list", "[addFront]" )
{
  LinkedListOfInts testlist;
  SECTION( "size increases" )
  {
    testlist.addFront(6);
    REQUIRE( testlist.size() == 1 );
    if ( testlist.size() == 1 )
    {
      std::cout << "passed: size increases" << '\n';
    }
  }
  SECTION( "adds node to front of list" )
  {
    testlist.addFront(6);
    REQUIRE( (testlist.toVector()).front() == 6 );
    if ( (testlist.toVector()).front() == 6 )
    {
      std::cout << "passed: adds node to front of list" << '\n';
    }
  }
  SECTION( "repeatedly called to add more than one node to front" )
  {
    testlist.addFront(6);
    testlist.addFront(7);
    testlist.addFront(8);
    REQUIRE( (testlist.toVector()).front() == 8 );
    if ( (testlist.toVector()).front() == 8 )
    {
      std::cout << "passed: repeatedly called to add more than one node to front" << '\n';
    }
  }
}

TEST_CASE( "can remove an element from back of linked list", "[removeBack]" )
{
  LinkedListOfInts testlist;
  SECTION( "size decreases" )
  {
    testlist.addBack(9);
    testlist.addBack(10);
    testlist.removeBack();
    REQUIRE( testlist.size() == 1 );
    if ( testlist.size() == 1 )
    {
      std::cout << "passed: size decreases" << '\n';
    }
  }
  SECTION( "returns false if list is empty")
  {
    REQUIRE( testlist.removeBack() == false );
    if ( testlist.removeBack() == false )
    {
      std::cout << "passed: returns false if list is empty" << '\n';
    }
  }
  SECTION( "removes node from back of list" )
  {
    testlist.addFront(9);
    testlist.addFront(10);
    testlist.addFront(11);
    testlist.removeBack();
    REQUIRE( (testlist.toVector()).back() == 10 );
    if ( (testlist.toVector()).back() == 10 )
    {
      std::cout << "passed: removes node from back of list" << '\n';
    }
  }
  SECTION( "repeatedly called to remove more than one node from back" )
  {
    testlist.addFront(9);
    testlist.addFront(10);
    testlist.addFront(11);
    testlist.removeBack();
    testlist.removeBack();
    REQUIRE( (testlist.toVector()).back() == 11 );
    if ( (testlist.toVector()).back() == 11 )
    {
      std::cout << "passed: repeatedly called to remove more than one node from back" << '\n';
    }
  }
}

TEST_CASE( "can remove an element from front of linked list", "[removeFront]" )
{
  LinkedListOfInts testlist;
  SECTION( "size decreases" )
  {
    testlist.addFront(9);
    testlist.addFront(10);
    testlist.removeFront();
    REQUIRE( testlist.size() == 1 );
    if ( testlist.size() == 1 )
    {
      std::cout << "passed: size decreases" << '\n';
    }
  }
  SECTION( "returns false if list is empty")
  {
    REQUIRE( testlist.removeFront() == false );
    if ( testlist.removeFront() == false )
    {
      std::cout << "passed: returns false if list is empty" << '\n';
    }
  }
  SECTION( "removes node from front of list" )
  {
    testlist.addFront(9);
    testlist.addFront(10);
    testlist.addFront(11);
    testlist.removeFront();
    REQUIRE( (testlist.toVector()).front() == 10 );
    if ( (testlist.toVector()).front() == 10 )
    {
      std::cout << "passed: removes node from front of list" << '\n';
    }
  }
  SECTION( "repeatedly called to remove more than one node from front" )
  {
    testlist.addFront(9);
    testlist.addFront(10);
    testlist.addFront(11);
    testlist.removeFront();
    testlist.removeFront();
    REQUIRE( (testlist.toVector()).front() == 9 );
    if ( (testlist.toVector()).front() == 9 )
    {
      std::cout << "passed: repeatedly called to remove more than one node from front" << '\n';
    }
  }
}
