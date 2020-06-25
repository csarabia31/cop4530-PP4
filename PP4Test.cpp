/**************************************************************************************************/
// Test File for Programming Project 4
// Requires the Catch2 header file
// How to compile: g++ -std=c++17 -Wall -I$(CATCH_SINGLE_INCLUDE) (All cpp files)
// Example: Assuming Catch2 is in the same directory as the project and all of your source file are 
// in the directory: 
//    g++ -std=c++17 -Wall *.cpp 
//    or
//    g++ -std=gnu++17 -Wall *.cpp 
/**************************************************************************************************/

#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "Huffman.hpp"

#include "TestStrings.hpp"
// Includes: 
// const std::string turing       turingCode        turingTree
// const std::string dijkstra     dijkstraCode      dijkstraTree
// const std::string wikipedia    wikipediaCode     wikipediaTree
// const std::string constitution constitutionCode  constitutionTree

TEST_CASE("Project 4 Test Cases for Huffman Coding") {
  HuffmanTree t;

  // Turing String Tests
  SECTION("Should compress the turing string") {
    REQUIRE(t.compress(turing) == turingCode);
  }
    
  SECTION("Should serialize the tree for turing") {
    t.compress(turing);
    REQUIRE(t.serializeTree() == turingTree);
  }

  SECTION("Should decompress the turing string") {
    REQUIRE(t.decompress(turingCode, turingTree) == turing);
  }

  // Dijkstra String Tests
  SECTION("Should compress the dijkstra string") {
    REQUIRE(t.compress(dijkstra) == dijkstraCode);
  }
    
  SECTION("Should serialize the tree for dijkstra") {
    t.compress(dijkstra);
    REQUIRE(t.serializeTree() == dijkstraTree);
  }

  SECTION("Should decompress the dijkstra string") {
    REQUIRE(t.decompress(dijkstraCode, dijkstraTree) == dijkstra);
  }

  // Wikipedia String Tests
  SECTION("Should compress the wikipedia string") {
    REQUIRE(t.compress(wikipedia) == wikipediaCode);
  }
    
  SECTION("Should serialize the tree for wikipedia") {
    t.compress(wikipedia);
    REQUIRE(t.serializeTree() == wikipediaTree);
  }

  SECTION("Should decompress the wikipedia string") {
    REQUIRE(t.decompress(wikipediaCode, wikipediaTree) == wikipedia);
  }

  // Constitution String Tests
  SECTION("Should compress the constitution string") {
    REQUIRE(t.compress(constitution) == constitutionCode);
  }
    
  SECTION("Should serialize the tree for constitution") {
    t.compress(constitution);
    REQUIRE(t.serializeTree() == constitutionTree);
  }

  SECTION("Should decompress the constitution string") {
    REQUIRE(t.decompress(constitutionCode, constitutionTree) == constitution);
  }
}



