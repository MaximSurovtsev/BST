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


// 				  +----+
// 				  |-08-|									           *
// 				  +----+
//
//
// 						 				    08
// 						 				   ---->
SCENARIO("BST delete root without children", "[init]") {
	BST<int> tree = {8};
	tree.remove(8);
	REQUIRE( tree.root_() == nullptr  );
}

//                +----+                                              +----+
//                |-08-|                                              | 04 |
//                +----+                                              +----+
//                  /                                                   /
//                 /                                                   /
//           +----+                                              +----+
//           | 04 |                                              | 03 |
//           +----+                                              +----+
//             /
//            /
//      +----+                              08
//      | 03 |                             ---->
//      +----+
SCENARIO("BST delete root with one child", "[init]") {
	BST<int> tree ({8, 4, 3});
	BST<int> tree2({4, 3});
	tree.remove(8);
	REQUIRE( tree == tree2 );
}

//                +----+                                              +----+
//                |-08-|                                              | 09 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /          \
//            /         /  \                                      /            \
//      +----+    +----+    +----+          08              +----+              +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |              | 13 |
//      +----+    +----+    +----+                          +----+              +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 11 |
//                     +----+                                              +----+
//                        \                                                   \
//                         \                                                   \
//                          +----+                                              +----+
//                          | 12 |                                              | 12 |
//                          +----+                                              +----+
SCENARIO("BST delete root with children", "[init]") {
	BST<int> tree ({8, 4, 3, 10, 9, 13, 11, 12});
	tree.remove(8);
	REQUIRE( tree == BST<int>({9, 4, 3, 10, 13, 11, 12}) );
}

//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                                  /\
//            /         /  \                                                /  \
//      +----+    +----+    +----+          03                        +----+    +----+
//      |-03-|    | 09 |    | 13 |         ---->                      | 09 |    | 13 |
//      +----+    +----+    +----+                                    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 11 |
//                     +----+                                              +----+
//                        \                                                   \
//                         \                                                   \
//                          +----+                                              +----+
//                          | 12 |                                              | 12 |
//                          +----+                                              +----+
SCENARIO("BST delete non root without children", "[init]") {
	BST<int> tree({8, 4, 3, 10, 9, 13, 11, 12});
	tree.remove(3);
	REQUIRE( tree == BST<int>({8, 4, 10, 9, 13, 11, 12}) );
}

//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /         /\
//            /         /  \                                      /         /  \
//      +----+    +----+    +----+          11              +----+    +----+    +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |    | 09 |    | 13 |
//      +----+    +----+    +----+                          +----+    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     |-11-|                                              | 12 |
//                     +----+                                              +----+
//                        \
//                         \
//                          +----+
//                          | 12 |
//                          +----+
SCENARIO("BST delete non root with one child", "[init]") {
	BST<int> tree ({8, 4, 3, 10, 9, 13, 11, 12});
	tree.remove(11);
	REQUIRE( tree == BST<int>({8, 4, 3, 10, 9, 13, 12}) );
}

//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    |-10-|                                    | 04 |    | 11 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /         /\
//            /         /  \                                      /         /  \
//      +----+    +----+    +----+          10              +----+    +----+    +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |    | 09 |    | 13 |
//      +----+    +----+    +----+                          +----+    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 12 |
//                     +----+                                              +----+
//                        \
//                         \
//                          +----+
//                          | 12 |
//                          +----+
SCENARIO("BST delete non root with children", "[init]") {
	BST<int> tree ({8, 4, 3, 10, 9, 13, 11, 12});
	tree.remove(10);
	REQUIRE( tree == BST<int>({8, 4, 3, 11, 9, 13, 12}) );
}
