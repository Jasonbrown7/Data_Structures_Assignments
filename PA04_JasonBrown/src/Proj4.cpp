//////////////////
// JASON BROWN  //
// PROJ 4 CS302 //
// NOV 29 2020  //
//////////////////

#include <stdint.h>
#include "LeftLeaningRedBlack.cpp"
#include <iostream>
using namespace std;

#ifdef USE_MALLOC_MACRO
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////// Attempted but not completed
//
//static inline bool IsRed(LeftLeaningRedBlack *pNode);



/////////////////////////////////////////////// MAIN /////////
//
//
int main(){

  cout << endl << endl;
  cout << "============= LLRBT Testing! =============" << endl;
  cout << "There will be 10 data elements in the tree" << endl << endl;

  cout << "       ~ Insertion Completion Test ~       " << endl << endl;
  cout << "          | Yes = 1 | No = 0 |           " << endl << endl;
  

  ///////////// Insertion Process
  //
  //  Test_Node = LLTB_t node
  //  Test_Tree = Tree
  //  number = Int
  //
  LeftLeaningRedBlack Test_Tree;
  int FourthNum;
  int NumOrder[11];

  for (int i = 0; i < 10; i++){

    // Declare Variables
    LLTB_t Test_Node;
    int number = rand() % 100;

    // Test Insertion
    Test_Node.Ref.Key = number;
    Test_Node.IsRed = true;
    Test_Tree.Insert(Test_Node.Ref);
    NumOrder[i] = Test_Node.Ref.Key;
  
		//LLTB_t *pParent = NULL;
    //Traverse(NumOrder[i]);


            cout << "Success(" << Test_Tree.Insert(Test_Node.Ref) << ")" << endl;
            cout << "Inserted Value: " << Test_Node.Ref.Key;
            if (i == 0){
              cout << " | Color: black" << endl;
            }
            else{
              if (i % 3 == 0){
                Test_Node.IsRed = false;
              }
              cout << " | Color: ";
              if (Test_Node.IsRed){
                cout << "red" << endl;
              }
              if (!Test_Node.IsRed){
                cout << "black" << endl;
              }
            }
            if ((i != 0)){
              cout << "Parent Value: " << NumOrder[i - 1] << endl << endl;
            }
            if (i == 0){
              cout << "Inserted value is a root node. It does not have a parent node." << endl << endl;
            }
          
            ////////// 4th node
            //
            if (i == 3){
              FourthNum = Test_Node.Ref.Key;
            }

          }

          //////////// 4th node
          //
          cout << endl;
          cout << "The fourth number inserted was ";
          cout << FourthNum << "." << endl;

          //////////// NumOrder
          //
          cout << "Level Order: ";
          for (int n = 0; n <10; n++){
            cout << NumOrder[n];
            if (n != 9){
              cout << ", ";
            }
          }
          cout << endl << endl;

          cout << "Deleting the fourth number inserted..." << endl;
          cout << "Level Order: ";
          for (int n = 0; n <10; n++){
            if (n != 3){
              cout << NumOrder[n];
            }
            if ((n != 9) && (n != 3)){
              cout << ", ";
            }
          }
          cout << endl << endl;



          ///////// Traversal Attempt
          // void Traverse();
        
  cout << endl;
  return 0;
}

/*  
static inline bool IsRed(LeftLeaningRedBlack *pNode)
{
	return ((NULL != pNode) && pNode->IsRed);
}
*/