//Copyright 2023, Bradley Peterson, Weber State University, All rights reserved. (2/2023)
#include "iterators.hpp"
#include <sstream>
#include <chrono>
#include <iostream>
#include <set>
#include <stdexcept>
#include <cstring>
#include <string>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::stringstream;
using std::set;
using std::stoi;

//This helps with testing, comment it in when ready, but do not modify the code.
template <typename T>
bool checkTest(int testNum, int& correct, T* whatItShouldBe, T* whatItIs) {

  if (strcmp(whatItShouldBe, whatItIs) == 0) {
    correct++;
    cout << "Passed " << testNum << endl;
    return true;
  }
  else {
    if (whatItShouldBe == "") {
      cout << "***Failed test " << testNum << " *** " << endl << "   Output was " << whatItIs << endl << "   Output should have been blank. " << endl;
    }
    else {
      cout << "***Failed test " << testNum << " *** " << endl << "   Output was " << whatItIs << endl << "   Output should have been " << whatItShouldBe << endl;
    }
    //cout << "The unit test checker is closing down the program now due to a failed test" << endl;
    //exit(1);
    return false;
  }
}

template <typename T>
bool checkTest(int testNum, int& correct, T whatItShouldBe, T whatItIs) {

  if (whatItShouldBe == whatItIs) {
    correct++;
    cout << "Passed " << testNum << endl;
    return true;
  }
  else {

    cout << "***Failed test " << testNum << " *** " << endl << "   Output was " << whatItIs << endl << "   Output should have been " << whatItShouldBe << endl;
    //cout << "The unit test checker is closing down the program now due to a failed test" << endl;
    //exit(1);
    return false;
  }
}


//This helps with testing, do not modify.
bool checkTestMemory(string testName, int whatItShouldBe, int whatItIs) {

  if (whatItShouldBe == whatItIs) {
    cout << "Passed " << testName << endl;
    return true;
  }
  else {
    cout << "***Failed test " << testName << " *** " << endl << "  There are " << whatItIs << " bytes of memory yet to be reclaimed!" << endl;
    return false;
    exit(1);
  }
}


//This helps with testing, do not modify.
bool testIteratorFundamentals() {

  int testNum = 1;
  int correct = 0;
  cout << "--------testIteratorFundamentals Tests--------" << endl;

  cout << "|||### You need to comment in testIteratorIncrement() when it's ready and remove this ###|||" << endl;
  cout << "|||### I strongly advise commenting in tests one at a time and testing those.  It's harder to try and do all tests at once.###|||" << endl;

  DoublyLinkedList<int> d;

  // //Our test data should have all even numbers from 2 to 20
  for (int i = 2; i <= 20; i += 2) {
   d.pushBack(i);
   }

  // //Get an iterator which points at the beginning of the list
  Iterator<int> iter = d.begin();

  // //Test the operator* operator
   checkTest(testNum++, correct, 2, *iter); // 1

  // //Test the ++ prefix increment opreator
   ++iter;
  checkTest(testNum++, correct, 4, *iter); // 2

  // //Test the != operator
  // //reset them back to the start
   iter = d.begin();
  Iterator<int> anotherIter = d.begin();

  if (iter != anotherIter) {
   cout << "****** Failed test 3 ****** " << endl << "     The two iteraters held the same data." << endl;
   }
  else {
    correct++;
   cout << "Passed 3" << endl;
  }
   testNum++;

  // //Again test the != operator
   ++iter;
  if (iter != anotherIter) {
    correct++;
    cout << "Passed 4" << endl;
   }
   else {
     cout << "****** Failed test 4 ****** " << endl << "     The two iteraters held different data." << endl;
   }
   testNum++;

  // //Test the ++postfix increment
   iter = d.begin(); //reset it back to the start
   anotherIter = iter++;  //anotherIter should be at the data 2

   checkTest(testNum++, correct, 4, *iter); // 5
   checkTest(testNum++, correct, 2, *anotherIter); // 6

  // // TODO:
  // // We have !=, *, ++, and .begin() tested by this point.  Now test .end().  Do that with a for loop.  
   stringstream ss;
  cout << "Next test - this should display 2 4 6 8 10 12 14 16 18 20." << endl;
   for (auto item : d) {
    cout << item << " ";
     ss << item << " ";
   }
   cout << endl;

   checkTest(testNum++, correct, "2 4 6 8 10 12 14 16 18 20 ", ss.str().c_str()); // 7
  ss.str("");
  return (testNum - 1 == correct && correct > 0); 

}

//This helps with testing, do not modify.
bool testIteratorIncrement() {

  int testNum = 1;
  int correct = 0;
  cout << "--------testIteratorIncrement Tests--------" << endl;

  cout << "|||### You need to comment in testIteratorIncrement() when it's ready and remove this ###|||" << endl;
   DoublyLinkedList<int>* d = new DoublyLinkedList<int>;

  // //Our test data should have all even numbers from 2 to 20
  for (int i = 2; i <= 20; i += 2) {
     d->pushBack(i);
   }

  // //Get an iterator which points at the beginning of the list
   Iterator<int> iter = d->begin();

  // //Test that it does point to the first
   checkTest(testNum++, correct, 2, *iter); // 1

  // //Test that our Iterator can move forward;
  ++iter;
   checkTest(testNum++, correct, 4, *iter); // 2


  // //Test that our Iterator can move forward again;
   ++iter;
   checkTest(testNum++, correct, 6, *iter); // 3

  // //move it some more
   for (int i = 0; i < 6; i++) {
    ++iter;
   }
   checkTest(testNum++, correct, 18, *iter); // 4

  // //Hit the end
   ++iter;
   checkTest(testNum++, correct, 20, *iter); // 5

  // //Verify we move the iterator past the end without crashing
   ++iter;
   string didntCrash = "did not crash";
   checkTest(testNum++, correct, didntCrash, didntCrash); // 6


   delete d;

  return (testNum - 1 == correct && correct > 0);

}

//This helps with testing, do not modify.
bool testIteratorDecrement() {

  int testNum = 1;
  int correct = 0;
  cout << "--------testIteratorDecrement Tests--------" << endl;

  cout << "|||### You need to comment in testIteratorDecrement() when it's ready and remove this###|||" << endl;

 DoublyLinkedList<int>* d = new DoublyLinkedList<int>;

//   //Our test data should have all even numbers from 2 to 20
  for (int i = 2; i <= 20; i += 2) {
     d->pushBack(i);
  }

//   //Get an Iterator which points at the end of the list    (Not on the last item, but on the "end" state)
   Iterator<int> iter = d->end();

  --iter;  // We have to do a decrement otherwise the iterator is in the past-the-end state and isn't pointing at a value
//            // Don't comment out this line, even if it makes your test #2 pass.  It will make later tests fail.
//            // If you comment out this line and later contact me for help, then I will drive up to your residence, 
//            // ring your doorbell, and stare at you angrily.  

//   //Test that it does point to the first
  checkTest(testNum++, correct, 20, *iter); // 1

//   //Test that our Iterator can move forward;
  --iter;
  checkTest(testNum++, correct, 18, *iter); // 2

//   //move it some more
   for (int i = 0; i < 7; i++) {
    --iter;
  }
  checkTest(testNum++, correct, 4, *iter); // 3

//   //Hit the end
  --iter;
  checkTest(testNum++, correct, 2, *iter); // 4

//   //Now go back forward
 ++iter;
  checkTest(testNum++, correct, 4, *iter); // 5

  delete d;
  
  return (testNum - 1 == correct && correct > 0);

}

//This helps with testing, do not modify.
bool testIterationTricky() {

  int testNum = 1;
  int correct = 0;
  cout << "--------testIterationTricky Tests--------" << endl;

  cout << "|||### You need to comment in testIterationTricky() when it's ready and remove this###|||" << endl;

   DoublyLinkedList<int> myListOneNode;

  myListOneNode.pushBack(42);
   cout << "Test 1, the next line should display 42" << endl;
   stringstream ss;
//   //see if we can just iterator through one item.
   for (auto i : myListOneNode) {
    cout << i << " ";
    ss << i << " ";
   }
   cout << endl;
   checkTest(testNum++, correct, "42 ", ss.str().c_str()); // 1
   ss.str("");

  DoublyLinkedList<int> myListEmpty;
  cout << "Test 2, the next line shouldn't display anything" << endl;
//   //see if we can just iterator through one item.
  for (auto i : myListEmpty) {
     cout << i << " ";
    ss << i << " ";
   }
  cout << endl;
   checkTest(testNum++, correct, "", ss.str().c_str()); // 2
   ss.str("");
  
  return (testNum - 1 == correct && correct > 0);

}



//This helps with testing, do not modify.
bool testAlgorithms() {

    int testNum = 1;
    int correct = 0;
    cout << "--------testAlgorithms Tests--------" << endl;

  cout << "|||### You need to comment in testAlgorithms() when it's ready and remove this###|||" << endl;

DoublyLinkedList<int> myList;

  // //Our test data should have all even numbers from 2 to 20
   for (int i = 2; i <= 6; i += 2) {
  myList.pushBack(i);
   }
  myList.pushBack(100);
  for (int i = 8; i <= 12; i += 2) {
   myList.pushBack(i);
   }
   myList.pushBack(100);
   for (int i = 14; i <= 20; i += 2) {
     myList.pushBack(i);
   }
  stringstream ss;
   cout << "Test 1, this should display 2 4 6 100 8 10 12 100 14 16 18 20." << endl;
   for (auto i : myList) {
    cout << i << " ";
     ss << i << " ";
  }
  cout << endl;
   checkTest(testNum++, correct, "2 4 6 100 8 10 12 100 14 16 18 20 ", ss.str().c_str()); // 1
   ss.str("");

  // //Test the STL reverse algorithm on our iterator
   cout << "Test 2, this should display 20 18 16 14 100 12 10 8 100 6 4 2." << endl;
   std::reverse(myList.begin(), myList.end());
   for (auto i : myList) {
    cout << i << " ";
    ss << i << " ";
   }
   cout << endl;
   checkTest(testNum++, correct, "20 18 16 14 100 12 10 8 100 6 4 2 ", ss.str().c_str()); // 2
   ss.str("");

  // //Get it back in ascending order using the STL reverse algorithm
   std::reverse(myList.begin(), myList.end());
   for (auto i : myList) {
    cout << i << " ";
     ss << i << " ";
   }
   cout << endl;
  checkTest(testNum++, correct, "2 4 6 100 8 10 12 100 14 16 18 20 ", ss.str().c_str()); // 3
   ss.str("");

  // // Try a custom assignmentReverse function

   assignmentReverse(myList.begin(), myList.end());
  for (auto i : myList) {
    cout << i << " ";
     ss << i << " ";
   }
   cout << endl;
  checkTest(testNum++, correct, "20 18 16 14 100 12 10 8 100 6 4 2 ", ss.str().c_str()); // 4
   ss.str("");

  // //Get it back in ascending order using the STL reverse algorithm
   assignmentReverse(myList.begin(), myList.end());
   for (auto i : myList) {
    cout << i << " ";
     ss << i << " ";
   }
  cout << endl;

   checkTest(testNum++, correct, "2 4 6 100 8 10 12 100 14 16 18 20 ", ss.str().c_str()); // 5
   ss.str("");

  // // Test assignmentReverse on an STL container:


   list<int> stlList;

  // //Our test data should have all even numbers from 2 to 20
   for (int i = 2; i <= 6; i += 2) {
     stlList.push_back(i);
   }
   stlList.push_back(100);
  for (int i = 8; i <= 12; i += 2) {
     stlList.push_back(i);
   }
   stlList.push_back(100);
   for (int i = 14; i <= 20; i += 2) {
    stlList.push_back(i);
   }
   for (auto i : stlList) {
     cout << i << " ";
     ss << i << " ";
   }
   cout << endl;
  checkTest(testNum++, correct, "2 4 6 100 8 10 12 100 14 16 18 20 ", ss.str().c_str()); // 6
   ss.str("");

  // // Try a custom assignmentReverse function

  assignmentReverse(stlList.begin(), stlList.end());
   for (auto i : stlList) {
   cout << i << " ";
    ss << i << " ";
   }
   cout << endl;
   checkTest(testNum++, correct, "20 18 16 14 100 12 10 8 100 6 4 2 ", ss.str().c_str()); // 7
   ss.str("");

  return (testNum - 1 == correct && correct > 0);

}

//This helps with testing, do not modify.
bool testLambda() {
  int testNum = 1;
  int correct = 0;
  cout << "--------testLambda Tests--------" << endl;

  cout << "|||### You need to comment in testLambda() when it's ready and remove this###|||" << endl;

   DoublyLinkedList<string> myWords;

   myWords.pushBack("bob");
   myWords.pushBack("racecar");
   myWords.pushBack("peep");
   myWords.pushBack("redder");
   myWords.pushBack("sells");
   myWords.pushBack("pneumonoultramicroscopicsilicovolcanoconiosis");
   myWords.pushBack("Was it a car or a cat I saw?");
   myWords.pushBack("Madam, in Eden, I'm Adam");
   myWords.pushBack("A nut for a jar of tuna");
   myWords.pushBack("Borrow or rob?");
   myWords.pushBack("This is a palindrome!");


  // // Prepare a container to hold output.  
   vector<string> output(11);
  loadOnlyPalindromes(myWords, output);
  
  std::stringstream ss;
   for (auto& str : output) {
    ss << str << "|";
   }
   checkTest(testNum++, correct, "bob|racecar|peep|redder|Was it a car or a cat I saw?|Madam, in Eden, I'm Adam|A nut for a jar of tuna|Borrow or rob?|", ss.str().c_str());
  
  return (testNum - 1 == correct && correct > 0);

}


int main(int argc, char** argv) {

  int test = 0;
  int count = 0;

  if (argc > 1) {
    test = stoi(argv[1]);
  }
  switch (test) {
  case 0:
    if (testIteratorFundamentals()) count++;
    if (testIteratorIncrement()) count++;
    if (testIteratorDecrement()) count++;
    if (testIterationTricky()) count++;
    if (testAlgorithms()) count++;
    if (testLambda()) count++;
    cout << "----------------" << endl;
    cout << "Passed " << count << " out of 6 group tests" << endl;
    cout << "--End of tests--" << endl;
    return count != 6;
  case 1:
    return !testIteratorFundamentals();
  case 2:
    return !testIteratorIncrement();
  case 3:
    return !testIteratorDecrement();
  case 4:
    return !testIterationTricky();
  case 5:
    return !testAlgorithms();
  case 6:
    return !testLambda();
  }
}
