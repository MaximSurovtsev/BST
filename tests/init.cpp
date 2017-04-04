#include <BST.h>
#include <catch.hpp>

SCENARIO ("init", "[init]")
{
  BST<int> test;
  REQUIRE(test.root_() == NULL);
  REQUIRE(test.get_count() == 0);
}

SCENARIO("insert", "[init]")
{
  BST<int> test;
  test.insert(4);
  REQUIRE(test.get_count() == 1);
  REQUIRE(test.search_result(4) == 1);
}

SCENARIO("get_pointer", "[init]")
{
  BST<int> test;
  test.insert(4);
  REQUIRE(test.get_pointer(4, test.root_()) != 0);
}

SCENARIO("get root", "[init]")
{
  BST<int> test;
  test.insert(4);
  REQUIRE(test.root_() != 0);
}
SCENARIO ("reading", "[init]")
{
   BST<int> test;
   test.reading("file1.txt");
   REQUIRE(test.search_result(1) == 0);
   REQUIRE(test.get_count() == 0);
}

SCENARIO ("writing", "[init]")
{
  BST<int> test;
  
  test.writing("file1.txt");
  BST<int> test2;
  test.reading("file1.txt");
  REQUIRE(test.get_count() == test2.get_count());
}
