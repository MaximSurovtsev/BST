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
  test2.reading("file1.txt");
  REQUIRE(test.get_count() == test2.get_count());
}

SCENARIO("deleting Node", "[init]")
{
  BST<int> test;
  test.insert(20);
  test.insert(28);
  test.remove(28);
  REQUIRE(test.search_result(28) == 0);
}


SCENARIO("BST delete root without children", "[init]") {
	BST<int> tree = {8};
	tree.remove(8);
	REQUIRE( tree.root_() == nullptr  );
}

SCENARIO("BST delete root with one child", "[init]") {
	BST<int> tree ={8, 4, 3};
	BST<int> tree2={4, 3};
	tree.remove(8);
	REQUIRE(tree == tree2);
}


SCENARIO("BST delete root with children", "[init]") {
	BST<int> tree1 ={8, 4, 3, 10, 9, 13, 11, 12};
	BST<int> tree2 ={9, 4, 3, 10, 13, 11, 12};
	tree1.remove(8);
	REQUIRE( tree1 == tree2 );
}


SCENARIO("BST delete non root without children", "[init]") {
	BST<int> tree1={8, 4, 3, 10, 9, 13, 11, 12};
	BST<int> tree2={8, 4, 10, 9, 13, 11, 12};
	tree1.remove(3);
	REQUIRE( tree1 ==tree2 );
}


SCENARIO("BST delete non root with one child", "[init]") {
	BST<int> tree1 ={8, 4, 3, 10, 9, 13, 11, 12};
	BST<int> tree2 ={8, 4, 3, 10, 9, 13, 12};
	tree1.remove(11);
	REQUIRE( tree1 == tree2 );
}


SCENARIO("BST delete non root with children", "[init]") {
	BST<int> tree1 ={8, 4, 3, 10, 9, 13, 11, 12};
	BST<int> tree2 ={8, 4, 3, 11, 9, 13, 12};
	tree1.remove(10);
	REQUIRE( tree1 == tree2 );
}
