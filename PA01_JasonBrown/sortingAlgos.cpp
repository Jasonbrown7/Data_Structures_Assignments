/////////////////
// Jason Brown //
// CS302 Proj2 //
/////////////////
// The two sorting algorithms I used were Bubble Sort and Quick Sort

// Bubble sort //
// Standard bubble sort which counts number of swaps for project
void bubbleSort(vector<int>& data, unsigned long int& comparisons, unsigned long int& swaps)
{
    // starts unsorted
    bool sorted = false;
    unsigned int count, index;

    for(count = 1; (count < data.size()) && sorted == false; count++)
    {
      sorted = true;

      for(index = 0; index < data.size() - count; index++)
      {
        // increase index
        comparisons++;
        // swap values if first is greater
        if(data[index] > data[index + 1])
        {
          // counts the number of swaps for sake of project requirements
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

    // counts comparisons
    comparisons++;
    if( beginning < ending )
    {
        middle = partition(data, beginning, ending, comparisons, swaps);
        // quick sort for beginning half and second half
        quickSort(data, beginning, middle, comparisons, swaps);
        quickSort(data, middle + 1, ending, comparisons, swaps);
    }
}
