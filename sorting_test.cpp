#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <chrono>

// include your header with all the list generators
#include "testing.h"

// include the header with your sorting algorithms
#include "Christopher_Harrison_project1.h"  // adjust to your actual file name

using namespace std;

#include "testing.h"



/* Helper function to print vector */
template<typename T>
void print_list(vector<T>& list) {
    std::cout << "[ ";
    for(T n : list) {
        std::cout << n << ' ';
    }
    std::cout << "]\n";
}


/* Generate shuffled list of integers from 0 to len-1 */
vector<int> gen_unique_list(unsigned int len) {
    vector<int> int_list {};
    for(int i = 0; i < len; i++) {
        int_list.push_back(i+1);
    }

    auto rd = random_device {};
    auto rng = default_random_engine { rd() };

    ranges::shuffle(int_list,rng);

    return int_list;
}

/* Generate random list of integers of size len */
vector<int> gen_random_list(unsigned int len) {

    vector<int> int_list {};

    srand(time({}));
    for(int i = 0; i < len; i++) {
        int_list.push_back(static_cast<int>(rand()));
    }

    return int_list;
}

/* Generate descending list of integers of size len */
vector<int> gen_descending_list(unsigned int len) { 
    vector<int> int_list {};
    srand(time({}));
    int start_int = static_cast<int>( (rand() % len)*((-1)^(rand() % 2))  );
    for(int i = 0; i < len; i++) {
        int_list.push_back(start_int);
        --start_int;
    }

    return int_list;
}

/* Generates a list of ascending integers of size len */
vector<int> gen_ascending_list(unsigned int len) { 
    vector<int> int_list {};
    srand(time({}));
    int start_int = static_cast<int>( (rand() % len)*((-1)^(rand() % 2))  );
    for(int i = 0; i < len; i++) {
        int_list.push_back(start_int);
        ++start_int;
    }

    return int_list;
}


/* Generates an ascending list with 3 random swaps */
vector<int> gen_ascending_3swap_list(unsigned int len) {
    vector<int> int_list = gen_ascending_list(len);
    srand(time({}));
    for(int i = 0; i < 3; i++) {
        unsigned int swap_index1 = static_cast<unsigned int>( rand() % len );
        unsigned int swap_index2 = static_cast<unsigned int>( rand() % len );

        int temp = int_list[swap_index1];
        int_list[swap_index1] = int_list[swap_index2];
        int_list[swap_index2] = temp;
    }
    return int_list;
}

/* Genarates a list of all equal entries of length len */
vector<int> gen_all_equal_list(unsigned int len) {
    vector<int> int_list = {};
    srand(time({}));
    int choice = static_cast<int>( rand() );
    for(int i = 0; i < len; i++) {
        int_list.push_back(choice);
    }

    return int_list;
}

/* Generates list containing many duplicates of length len */
vector<int> gen_many_dupes_list(unsigned int len) {
    vector<int> int_list = {};
    srand(time({}));
    while(int_list.size() < len) {
        unsigned int num_dupes = static_cast<unsigned int>( rand() % 17 );
        int item = static_cast<int>( rand() );
        for(int j = 0; j < num_dupes && int_list.size() < len; j++) {
            int_list.push_back(item);
        }
    }

    return int_list;
}

/* Generate ascending list with 1% of entries then randomly changed */
vector<int> gen_one_percent_rand_list(unsigned int len) {
    vector<int> int_list = gen_ascending_list(len);

    unsigned int percent = ceil(len*.01);

    srand(time({}));
    for(int i = 0; i < percent; i++) {
        unsigned int index = static_cast<unsigned int>( rand() % len );
        unsigned int value = static_cast<int>( rand() );

        int_list[index] = value;
    }

    return int_list;
}


/**** Student Tests Here ****/
/* Feel free to write your own tests here! */

/* Helper to check sorted order */
template<typename T>
bool is_sorted_order(const vector<T>& v, bool descending = false) {
    if (v.empty()) return true;
    if (descending) {
        for (size_t i = 1; i < v.size(); i++) {
            if (v[i-1] < v[i]) return false;
        }
    } else {
        for (size_t i = 1; i < v.size(); i++) {
            if (v[i-1] > v[i]) return false;
        }
    }
    return true;
}

/* Run a test on a single sorting function (with timing) */
template<typename T>
void run_sort_test(
    const string& name,
    function<void(vector<T>&)> sorter,
    const vector<T>& input,
    bool descending)
{
    vector<T> data = input;

    auto start = chrono::high_resolution_clock::now();
    sorter(data);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed = end - start;

    bool ok = is_sorted_order(data, descending);
    cout << "Test " << name << " on input size " << input.size()
         << (descending ? " (desc)" : " (asc)") << ": "
         << (ok ? "PASS" : "FAIL")
         << " | Time: " << elapsed.count() << " ms\n";
}









#include "Christopher_Harrison_project1.h"
#include "testing.h"

#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

/****************
 * INSTRUCTIONS *
 ****************
 *
 * - Replace all instances of "Firstname_Lastname" with your firstname and
 *   your last name. This include the .h and .cpp files, along with the
 *   header guards at the top of the .h file.
 *
 * - Implement the appropriate algorithms as described below.
 *   You must follow the specifications as written
 *   below (e.g., stability, in-place, etc.).
 *
 * - DO NOT MODIFY THE FUNCTION SIGNATURES!!!
 *
 * - You are allowed to add helper functions. Be sure to add the appropriate
 *   function prototypes in "Fistname_Lastname_project1.h".
 *
 * - The file "testing.cpp" has various functions you can utilize to test
 *   your code. You can also add your own tests!
 *
 * - If you are working in a group, please modify the comments directly below.
 *
 */



/*** GROUP PROJECT ***/
// Please list ALL of your other group members as comments below.
//   Talha
//   Manan



/* Bubble Sort - Chris
 *
 * 5 points
 * 
 * Algorithm: Continuously compare adjacent elements and swap them if necessary.
 *            This is a stable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void bubble_sort(vector<T> &list, bool descending) {
    int numSwaps = 0;
    for (size_t i = 0; i < list.size(); i++)
    {
        numSwaps = 0;
        //size - 1 - i because the last i elements are already sorted
        for (size_t j = 0; j < list.size() - 1 - i; j++)
        {
            if (!descending && list[j+1] < list[j] || descending && list[j+1] > list[j])
            {
                //perform swap
                std::swap(list[j], list[j+1]);
                numSwaps++;
            }
        }
        if (numSwaps == 0)
            break;
    }
    return;
}




/* Selection Sort 
 *
 * 5 points
 * 
 * Algorithm: Continuously finds the minimium (or maximum) element in the list, 
 *            then swaps it with the first non-sorted element of the list.
 *            This is an unstable, in-place sorting algorithm. Your implementation must be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void selection_sort(std::vector<T> &list, bool descending) {
  int n = list.size();
    if (n <= 1) return; // No sorting needed

    for (int i = 0; i < n - 1; i++) {
        int swap_index = i; 
        for (int j = i + 1; j < n; j++) {
            if (descending) {
                // If descending order, find the maximum
                if (list[j] > list[swap_index]) {
                    swap_index = j;
                }
            } else {
                // If ascending order, find the minimum
                if (list[j] < list[swap_index]) {
                    swap_index = j;
                }
            }
        }
        // Swap with the first ith element 
        if (swap_index != i) {
            T temp = list[i];
            list[i] = list[swap_index];
            list[swap_index] = temp;
        }
    }
}





/* Insertion Sort - Chris
 *
 * 5 points
 * 
 * Algorithm: Iterates through the list and inserts the current element into
 *            the correct sorted position of the prefix of the list.
 *            This is a stable, in-place sorting algorithm. Your implementation
 *            does not need to be in-place.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 * */
template<typename T>
void insertion_sort(vector<T> &list, bool descending) 
{
	for (size_t i = 1; i < list.size(); i++)
	{
		T unsortedVal = list[i];
		int j = i - 1;
		//keep going until our unsorted val is in the right spot
		while ((!descending && j >= 0 && list[j] > unsortedVal) || (descending && j >= 0 && list[j] < unsortedVal)) 
		{
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = unsortedVal;
	}
}








/* Quicksort
 *
 * 10 points
 *
 * Algorithm: Sorts by first choosing a random pivot from the list, then
 *            partitioning the list into two halves with respect to the
 *            pivot, then recursing on each half.
 *            This is an unstable sorting algorithm. Not required to be
 *            implemented as an in-place sort.
 *
 *
 * Parameters:
 *  std::vector<T> &list: reference to a list of type T. You can assume this
 * type has all of the normal binary comparison operators such as <, >, ==, !=,
 * etc. bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template <typename T>
void quicksort(std::vector<T> &list, bool descending) {
  if (list.size() <= 1) return;
  if (is_sorted(list.begin(), list.end())) return;
  quicksort_helper(list, 0, list.size() - 1, descending);
}

/* Quick Partition
 *
 * Helper function for Quicksort. You will implement this to help with your
 * quicksort algorithm above.
 *
 */
template <typename T>
std::vector<T> &quick_partition(std::vector<T> &list, bool descending) {
//   partition_helper(list, 0, list.size() - 1, descending);
  return list;
}

template <typename T>
void quicksort_helper(std::vector<T> &list, int low, int high,
                      bool descending) {
  if (low < high) {
    int j = partition_helper(list, low, high, descending);
    quicksort_helper(list, low, j, descending);
    quicksort_helper(list, j + 1, high, descending);
  }
}

int random_num(int min, int max) {
  std::random_device
      rd;  // Hardware-based entropy (true randomness if supported)
  std::mt19937 gen(rd());  // Mersenne Twister seeded with rd
  std::uniform_int_distribution<> dis(
      min, max);  // Uniform distribution in [min, max]
  return dis(gen);
}


template <typename T>
int partition_helper(std::vector<T> &list, int low, int high, bool descending) {
  std::swap(list[low], list[random_num(low, high)]);
  T pivot = list[low];
  int i = low - 1, j = high + 1;
  while (true) {
    do {
      ++i;
    } while (descending ? list[i] > pivot : list[i] < pivot);
    do {
      --j;
    } while (descending ? list[j] < pivot : list[j] > pivot);
    if (i >= j) return j;
    std::swap(list[i], list[j]);
  }
}




/* Merge Sort 
 *
 * 10 points
 * 
 * Algorithm: Sorts the list by recursively sorting the left and right
 *            halves, then merging the two left and right halves together.
 *            This is a stable sorting algorithm. Not required to be implemented
 *            as an in-place sort.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 * */
template <typename T>
void merge_sort(std::vector<T> &list, bool descending) {
  std::uint64_t n = list.size();
  if (n <= 1) return;
  if (descending && std::is_sorted(list.begin(), list.end(), std::greater<T>())) return;
  else if (!descending && std::is_sorted(list.begin(), list.end())) return;

  std::vector<T> left(list.begin(), list.begin() + n / 2);
  std::vector<T> right(list.begin() + n / 2, list.end());
  merge_sort(left, descending);
  merge_sort(right, descending);
  merge_helper(left, right, list, descending);
}

template <typename T>
void merge_helper(std::vector<T> &left, std::vector<T> &right, std::vector<T> &list, bool descending) {
  list.clear();
  std::uint64_t i{0}, j{0}, k{0};
  std::uint64_t left_size{left.size()}, right_size{right.size()};
  while (i < left_size && j < right_size) {
    if (descending) {
      if (left[i] > right[j]) {
        list.push_back(left[i]);
        i++;
      } else {
        list.push_back(right[j]);
        j++;
      }
    } else {
      if (left[i] < right[j]) {
        list.push_back(left[i]);
        i++;
      } else {
        list.push_back(right[j]);
        j++;
      }
    }
  }

  for (; i < left_size; i++)
    list.push_back(left[i]);
  for (; j < right_size; j++)
    list.push_back(right[j]);
}

template <typename T>
void modified_merge_helper(std::vector<T>& list, int left, int mid, int right, bool descending) {
    // For small segments simply do insertion sort
    //TODO FIX THIS!!
    if (right - left <= 32) {
        insertion_sort_helper(list, left, right + 1, descending);
        return;
    }

    int i = left;   // left 
    int j = mid + 1; // right 

    while (i <= mid && j <= right) {
        bool advance_left = false;
        // Check if we've exhausted the right segment
        if (j > right) {
            advance_left = true;
        } else {
            if (descending) {
                // For descending order, keep list[i] if it's >= list[j]
                if (list[i] >= list[j]) {
                    advance_left = true;
                }
            } else {
                // For ascending order, keep list[i] if it's <= list[j]
                if (list[i] <= list[j]) {
                    advance_left = true;
                }
            }
        }

        if (advance_left) {
            // Just move to the left
            ++i;
        } else {
            // Insert list[j] at position i and shift elements
            T temp = list[j];
            for (size_t k = j; k > i; --k) {
                list[k] = list[k - 1];
            }
            list[i] = temp;
            ++i;
            ++j;
            ++mid;
        }
    }
}

template <typename T>
void insertion_sort_helper(std::vector<T> &list, int start, int end, bool descending) {
    for (int i = start + 1; i < end; i++) {
        T key = list[i];
        int j = i;
        if (descending) {
            while (j > start && list[j - 1] < key) {
                list[j] = list[j - 1];
                j--;
            }
        } else {
            while (j > start && list[j - 1] > key) {
                list[j] = list[j - 1];
                j--;
            }
        }
        list[j] = key;
    }
}

/* Bucket Merge Sort
 *
 * 20 points
 * 
 * Algorithm: Bucket Merge Sort we discussed in class. Works by
 *            partitioning the input list into small, fixed-length segments,
 *            sorting each of those segments using some fast algorithm, then
 *            merging each of the segments together.
 *            This is a stable, in-place sorting algorithm.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 *
 */
template<typename T>
void bucket_merge_sort(std::vector<T> &list, bool descending) {
  int size = list.size();
  const int bucket_size = 32;
  int i = 0;

  for (; i + bucket_size <= size; i += bucket_size){
    insertion_sort_helper(list, i, i + bucket_size, descending);
  }

  // For any remaining data
  if (i < size)
    insertion_sort_helper(list, i, size , descending);

  for (int n = bucket_size; n < size; n *= 2) {
    for (int left = 0; left < size; left += 2 * n) {
        int mid = left + n - 1;
        int right = left + 2 * n - 1;
        if (right >= size){
          right = size - 1;
        }
        if (mid < size - 1) {
            modified_merge_helper(list, left, mid, right, descending);
        }
    }
  }
}




/* Binary Radix Sort
 *
 * 20 points
 *
 * Algorithm:
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 */
template<Integral T> 
void binary_radix_sort(vector<T> &list, bool descending) {
    // Since C++ uses 2's compliment, we'll handle both cases.
    vector<T> negatives;
    vector<T> nonNegatives;
    for (T val : list)
        // we can flip the sign so we don't have to deal with 2's compliment
        if (val < 0)
            negatives.push_back(-1 * val);
        else
            nonNegatives.push_back(val);
    binary_radix_sort_helper(negatives, !descending); // flip negatives!
    binary_radix_sort_helper(nonNegatives, descending);
    // flip the sign of negative numbers back
    for (T& val : negatives)
        val = -1 * val;
    //append negatives to the front of nonNegatives or vice versa if descending
    list.clear();
    if (descending)
    {
        list.insert(list.end(), nonNegatives.begin(), nonNegatives.end());
        list.insert(list.end(), negatives.begin(), negatives.end());
    }
    else
    {
        list.insert(list.end(), negatives.begin(), negatives.end());
        list.insert(list.end(), nonNegatives.begin(), nonNegatives.end());   
    }
}

/* Binary Radix Helper
 *
 * Helper function for Binary Radix Sort. You will implement this to help with your
 * Binary Radix Sort algorithm above.
 *
 */
template<typename T> 
void binary_radix_sort_helper(vector<T> &list, bool descending) {
    if (list.size() == 0) return;
    T maxValue = list[0];
    for (int i = 1; i < list.size(); i++)
        if (list[i] > maxValue)
            maxValue = list[i];
    // to avoid doing unnecessary work ( counting sort on a bunch of just 0s ), we want to find the most significant 1 bit
    // we can shift right until we hit 0 and track how many shifts
    int maxBitsToSort = 0;
    for (int i = maxValue; i > 0; i = i >> 1)
        maxBitsToSort++;

    // we only need to go maxBitsToSort times
    for (int i = 0; i < maxBitsToSort; i++)
    {
        vector<T> zeroList;
        vector<T> oneList;

        for (T num : list)
        {
            if ((num >> i) & 1) // checks LEAST SIGNIFICANT BIT after shift!!
                oneList.push_back(num);  //if the current bit is 1
            else
                zeroList.push_back(num); //if the current bit is 0
        }

        list.clear();
        if (descending)
        {
            list.insert(list.end(), oneList.begin(), oneList.end());
            list.insert(list.end(), zeroList.begin(), zeroList.end());
        }
        else
        {
            list.insert(list.end(), zeroList.begin(), zeroList.end());
            list.insert(list.end(), oneList.begin(), oneList.end());
        }
    }
}


/* Your Hybrid Sort - Chris
 *
 * 25 points
 *
 * Algorithm: Your own custom Hybrid Sorting algorithm! Remember, a hybrid
 *            sort tries to take advantage of two (or more) sorting algorithms
 *            to speed up data processing.
 *
 * Parameters:
 *  vector<T> &list: reference to a list of type T. You can assume this type
 *                   has all of the normal binary comparison operators such
 *                   as <, >, ==, !=, etc.
 *  bool decending:  if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default)
 *
 */
template<typename T>
void my_hybrid_sort(vector<T> &list, bool descending) {
    // Quick sort into insertion sort!
    if (list.size() <= 1) return;
    if (is_sorted(list.begin(), list.end())) return;
    hybrid_helper(list, 0, list.size() - 1, descending);
}

template <typename T>
void hybrid_helper(std::vector<T> &list, int low, int high, bool descending) {
    if (high - low <= 32)
    {
        // not in place!
        // if we wanted to make it in place we could change insertion sort to take in iterators.
        vector<T> subList(list.begin() + low, list.begin() + high + 1);
        insertion_sort(subList, descending);
        //copies our sublist and replaces that part in list!
        copy(subList.begin(), subList.end(), list.begin() + low);
        return;
    }
    if (low < high) {
    //we can still use partition helper from above!
    int j = partition_helper(list, low, high, descending);
    hybrid_helper(list, low, j, descending);
    hybrid_helper(list, j + 1, high, descending);
  }
}



/* Base B Radix Sort 
 *
 * 25 Points
 *
 * Algorithm: Implement Radix Sort as discussed in class, but with
 *            respect to any unspecified base.
 *
 * Parameters: 
 *   vector<T> &list: reference to a list of type T.
 *                    IMPORTANT: this type T is assumed to be *integral*. It
 *                    can be any of the following integral types in C++:
 *                      - (unsigned) short int
 *                      - (unsigned) int
 *                      - (unsigned) long int
 *
 *   unsigned int base: the base with which to implement the radix sort. 
 *                      Note that base should be at least 2. The default
 *                      base is 10.
 *
 *   bool decending: if true, then sort in descending order; otherwise sort
 *                   in ascending order (the default).
 *
 *
 * Additional Information:
 *   - If you are enrolled in the graduate section of this course, you MUST
 *     implement this function (i.e., it counts towards your total grade).
 *
 *   - If you are enrolled in the undergraduate section of this course, this
 *     function is optional and worth extra credit.
 *
 *
 */
template<Integral T>
void radix_sort(vector<T> &list, unsigned int base, bool descending) {
    // Your code here!
}



int main() {
    /**** STUDENT CODE HERE ****/ 

    // generate test lists
    vector<vector<int>> test_lists;
    test_lists.push_back(gen_unique_list(20000));
    test_lists.push_back(gen_random_list(20000));
    test_lists.push_back(gen_descending_list(20000));
    test_lists.push_back(gen_ascending_list(20000));
    test_lists.push_back(gen_all_equal_list(20000));
    test_lists.push_back(gen_many_dupes_list(20000));
    test_lists.push_back(gen_one_percent_rand_list(20000));

    // sorting algorithms:
    auto bubble_sort_asc = [](vector<int>& v){ bubble_sort(v, false); };
    auto bubble_sort_desc = [](vector<int>& v){ bubble_sort(v, true); };

    auto selection_sort_asc = [](vector<int>& v){ selection_sort(v, false); };
    auto selection_sort_desc = [](vector<int>& v){ selection_sort(v, true); };

    auto insertion_sort_any = [](vector<int>& v){ insertion_sort(v); };
    auto quicksort_any = [](vector<int>& v){ quicksort(v); };
    auto merge_sort_any = [](vector<int>& v){ merge_sort(v); };
    auto bucket_merge_sort_any = [](vector<int>& v){ bucket_merge_sort(v); };
    auto binary_radix_sort_any = [](vector<int>& v){ binary_radix_sort(v); };
    auto my_hybrid_sort_any = [](vector<int>& v){ my_hybrid_sort(v, false); };
    // auto radix_sort_any = [](vector<int>& v){ radix_sort(v); };

    // test them:
    for (auto &list : test_lists) {
        run_sort_test<int>("Bubble Sort Asc", bubble_sort_asc, list, false);
        run_sort_test<int>("Bubble Sort Desc", bubble_sort_desc, list, true);
        run_sort_test<int>("Selection Sort Asc", selection_sort_asc, list, false);
        run_sort_test<int>("Selection Sort Desc", selection_sort_desc, list, true);
        run_sort_test<int>("Insertion Sort", insertion_sort_any, list, false);
        run_sort_test<int>("Quicksort", quicksort_any, list, false);
        run_sort_test<int>("Merge Sort", merge_sort_any, list, false);
        run_sort_test<int>("Bucket Merge Sort", bucket_merge_sort_any, list, false);
        run_sort_test<int>("Binary Radix Sort", binary_radix_sort_any, list, false);
        run_sort_test<int>("My Hybrid Sort", my_hybrid_sort_any, list, false);
        // run_sort_test<int>("Radix Sort", radix_sort_any, list, false);
        cout << "-----------------------------------\n";
    }


    /**** END STUDENT CODE ****/

    /***** DO NOT MODIFY BELOW THIS LINE *****/
    /*** INSTRUCTIONS ***
     *
     * Before submitting your code: 
     *   - remove all code within the main function that you have written above the `do-not-modify` line;
     *   - uncomment all lines below that begin with "//".
     *
     */
    // vector<int> test_list {1, 2, 3, 4, 5};
    // bubble_sort(test_list);
    //selection_sort(test_list);
    //insertion_sort(test_list);
    //quicksort(test_list);
    //merge_sort(test_list);
    //bucket_merge_sort(test_list);
    //binary_radix_sort(test_list);
    //my_hybrid_sort(test_list);
    //radix_sort(test_list);
    return 0;
}








