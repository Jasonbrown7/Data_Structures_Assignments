/////////////////
// Jason Brown //
// CS302 Proj2 //
/////////////////
// The two sorting algorithms I used were Bubble Sort and Quick Sort

// all included libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>

// standard namespace
using namespace std;

// Random Number Generator //
// creates a random integer within the bounds
int randomNumberGenerator()
{
    // seed creates a random digit
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    // generates the random digit with seed
    default_random_engine dre(seed);
    mt19937 mt(seed);

    // creates the bounds for the random digit to respect
    uniform_int_distribution<int> dist(0, 1000000);

// finally return random digit
return dist(mt);
}

// Create File //
// Creates a file which stores the randomly generated digits
void createFile(int numValues)
{
    // File I/O
    int counter;
    ofstream fout;

    // opens file
    fout.clear();
    fout.open("randomizedValues.txt");

    cout << "Hello! I'm generating " << numValues << " random digits between the given bounds." << endl << endl;

    // acts as a counting mechanism
    for(counter = 0; counter < numValues; counter++)
    {
      // file output
      fout << randomNumberGenerator() << endl;
    }
    // closes file
    fout.close();
}

// File Load //
// loads the file with randomly generated digits
void loadFile(vector<int>& vec, int numValues)
{
    // File I/O
    int index, number;
    ifstream fin;

    // clears what is of the file and opens it
    fin.clear();
    fin.open("randomizedValues.txt");

    // fills the file with random numbers
    for(index = 0; index < numValues; index++)
    {
      fin >> number;
      vec[index] = number;
    }
    fin.close();
}

// Bubble Sort //
// Standard bubble sort implementation which counts the number of swaps
void bubbleSort(vector<int>& data, unsigned long int& comparisons, unsigned long int& swaps)
{
    // automatically not sorted
    bool sorted = false;
    unsigned int count, index;

    for(count = 1; (count < data.size()) && sorted == false; count++)
    {
      sorted = true;

      for(index = 0; index < data.size() - count; index++)
      {
        comparisons++;
        // swap values if beginning is greater
        if(data[index] > data[index + 1])
        {
          // counts number of swaps for project
          swaps++;
          swap(data[index], data[index + 1] );
          sorted = false;
      }
    }
  }
}

// Partition Function //
// Splits data in half - helper function for quick sort
int partition(vector<int>& data, int beginning, int ending, unsigned long int& comparisons, unsigned long int& swaps)
{
      int x = data[beginning];
      int y = beginning;
      int z;

      for(z = beginning + 1; z < ending; z++)
      {
          comparisons++;
          if(data[z] <= x)
          {
              y++;
              swaps++;
  			   swap(data[y], data[z]);
          }
      }
      swaps++;
      swap(data[y], data[beginning]);

return y; // returns
}

// Quick Sort //
// Implementation for quick sort with use of Partition method
void quickSort(vector<int>& data, int beginning, int ending, unsigned long int& comparisons, unsigned long int& swaps)
{
    // middle is used by partition method which splits data in half
    int middle;

    comparisons++;
    if( beginning < ending )
    {
        // quick sort for beginning half and second half
        middle = partition(data, beginning, ending, comparisons, swaps);
        quickSort(data, beginning, middle, comparisons, swaps);
        quickSort(data, middle + 1, ending, comparisons, swaps);
    }
}

// Run //
// Runs the sorting algorithms and records the data (time, swaps)
double run(string sort, vector<int>& data, int numValues, unsigned long int& comparisons, unsigned long int& swaps)
{
    clock_t t1, t2, t3;

    //clear and resize vectors as a safety check
    data.clear();
    data.resize(numValues);

    loadFile(data, numValues);

    comparisons = 0, swaps = 0;

    // check which sort should be run with argument passed in
    if(sort == "Bubble Sort")
    {
      t1 = clock(); // start clock
      bubbleSort(data, comparisons, swaps);
      t2 = clock(); // end clock

      // difference of two clocks to find duration
      t3 = t2 - t1;
    }

    else if( sort == "Quick Sort" )
    {
       // start clock
       t1 = clock();
       // quicksort run
       quickSort(data, 0, data.size(), comparisons, swaps );
       // finish clock
       t2 = clock();

       // difference of two clocks to find duration
       t3 = t2 - t1;
    }
return (double)t3;
}


int main()
{
    int numValues;
    unsigned long int comparisons = 0, swaps = 0;
    vector<int> bubbleSortSet, quickSortSet;
    double averageTime = 0;
    int numRuns = 10;
    clock_t t1, t2, t3;

    // run loop 3 times, once for 1 000, twice for 10 000, three for 100 000
    for( int i = 1, count = 0; count < 3; i *= 10, count++ )
    {
      numValues = i * 1000;

      // generates the file
      createFile( numValues );

      if( numValues == 100000 )
      {
        numRuns = 2;
      }
      // Bubble Sort //
      cout << "Running bubble sort " << numRuns << " times with " << numValues << " values" << endl;

      for( int i = 0; i < numRuns; i++ )
      {
        averageTime += run( "Bubble Sort", bubbleSortSet, numValues, comparisons, swaps );
      }
      // output results
      cout << "--------------------------------------------------" << endl;
      cout << "Average time for " << numRuns << " runs with bubble sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " sec" << endl;
      cout << "Average # of comparisons for " << numRuns << " runs with bubble sort: " << comparisons / numRuns << endl;
      cout << "Average # of swaps for " << numRuns << " runs with bubble sort: " << swaps / numRuns << endl << endl;

      // quick Sort
      averageTime = 0, comparisons = 0, swaps = 0;


      numRuns = 10;
      if( numValues == 100000 )
      {
        numRuns = 2;
      }

      cout << endl << "Running quick sort " << numRuns << " times containing " << numValues << " values" << endl;

      for( int i = 0; i < numRuns; i++ )
      {
         averageTime += run("Quick Sort", quickSortSet, numValues, comparisons, swaps);
      }

      // output results
      cout << "--------------------------------------------------" << endl;
      cout << "Average sorting time for " << numRuns << " runs with quick sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " sec" << endl;
      cout << "Average # of comparisons for " << numRuns << " runs with quick sort: " << comparisons / numRuns << endl;
      cout << "Average # of swaps for " << numRuns << " runs with quick sort: " << swaps / numRuns << endl << endl;
    }

    cout << endl << endl << "After data has been sorted" << endl << endl;
    run("Bubble Sort", bubbleSortSet, 10000, comparisons, swaps);

    averageTime = 0, comparisons = 0, swaps = 0;
    numRuns = 10;
    t1 = clock();
    bubbleSort(bubbleSortSet, comparisons, swaps);
    t2 = clock();
    t3 = t2 - t1;

    // output results
    cout << "--------------------------------------------------" << endl;
    cout << "After bubble sort has sorted 10,000 values" << endl;
    cout << "Average sorting time for " << numRuns << " runs with bubble sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " sec" << endl;
    cout << "Average # of comparisons for " << numRuns << " runs with bubble sort: " << comparisons / numRuns << endl;
    cout << "Average # of swaps for " << numRuns << " runs with bubble sort: " << swaps / numRuns << endl << endl;


    run("Quick Sort", quickSortSet, 10000, comparisons, swaps);

    averageTime = 0, comparisons = 0, swaps = 0;
    numRuns = 10;
    t1 = clock();
    quickSort(quickSortSet, 0, quickSortSet.size(), comparisons, swaps );
    t2 = clock();
    t3 = t2 - t1;

    // output results
    cout << "--------------------------------------------------" << endl;
    cout << "After quick sort has sorted 10,000 values" << endl;
    cout << "Average sorting time for " << numRuns << " runs with quick sort: " << ( averageTime / CLOCKS_PER_SEC ) / numRuns << " sec" << endl;
    cout << "Average # of comparisons for " << numRuns << " runs with quick sort: " << comparisons / numRuns << endl;
    cout << "Average # of swaps for " << numRuns << " runs with quick sort: " << swaps / numRuns << endl << endl;

    // all done
    return EXIT_SUCCESS;
}
