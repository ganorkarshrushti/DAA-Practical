
//final daa1
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main() {
    for (int i = 1; i <= 10; i++) {
        int n = i * 1000;      //The size of the array increases by increments of 10,000 in each iteration of the loop.(when i=2, n=20k, i=3 ,n=30k)
        int* arr = new int[n]; // Dynamically allocate memory for array

        // Generate unsorted numbers between 500 and 5000 and store in the array
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % (5000 - 500 + 1) + 500;
        }

        // Open new files in write mode for unsorted numbers
        std::ofstream unsortedFile("unsorted_numbers.txt");

        if (!unsortedFile.is_open()) {
            std::cerr << "Error opening the file for writing unsorted numbers.\n";
            return 1; // Return an error code
        }
        
        // Write unsorted numbers between 500 and 5000 to the file
        for (int j = 0; j < n; j++) {
            unsortedFile << arr[j] << "\n";
        }
        unsortedFile.close();

        // Measure time complexity for Bubble Sort 
        auto start_bubble = std::chrono::high_resolution_clock::now();   //records the current time before starting the bubble sort
        bubbleSort(arr, n);
        auto end_bubble = std::chrono::high_resolution_clock::now();       //from std::(fetches the current time with very high precision from a clock designed to provide the most accurate time measurements)
        std::chrono::duration<double> total_time_bubble = end_bubble - start_bubble;

        // Measure time complexity for Selection Sort
        auto start_selection = std::chrono::high_resolution_clock::now();    //records the current time before starting the selection sort
        selectionSort(arr, n);
        auto end_selection = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> total_time_selection = end_selection - start_selection;          // a duration class that can store time intervals with decimal (fractional) seconds

        // Display the time complexity for both sorting algo
        std::cout << "Time complexity for Bubble Sort (n = " << n << "): " << total_time_bubble.count() << " seconds\n";
        std::cout << "Time complexity for Selection Sort (n = " << n << "): " << total_time_selection.count() << " seconds\n";

        // Open new files in write mode for sorted numbers
        std::ofstream sortedFile_bubble("sorted_numbers_bubble.txt");    //for writing data to files.
        std::ofstream sortedFile_selection("sorted_numbers_selection.txt");

        if (!sortedFile_bubble.is_open() || !sortedFile_selection.is_open()) {
            std::cerr << "Error opening the files for writing sorted numbers.\n";
            return 1; // Return an error code
        }

        // Write the sorted numbers to the new files
        for (int j = 0; j < n; j++) {
            sortedFile_bubble << arr[j] << "\n";
            sortedFile_selection << arr[j] << "\n";
        }

        sortedFile_bubble.close();      //Close the output files
        sortedFile_selection.close();

        std::cout << "Sorted the numbers using bubble sort and wrote them to 'sorted_numbers_bubble.txt'.\n";
        std::cout << "Sorted the numbers using selection sort and wrote them to 'sorted_numbers_selection.txt'.\n";

        delete[] arr; // Free dynamically allocated memory
    }

    return 0;
}