// Allowed libraries are already included
// DO NOT MODIFY
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Protoypes
void print_int_array(int *arr, size_t arr_len);
int sum_int_array(int *arr, size_t arr_len);
double average_int_array(int *arr, size_t arr_len);

void fill_random(int array[], int length, int max);

// IMPORTANT REQUIREMENTS/LIMITATIONS
//
// Read the requirements and limitations carefully.
// You can find them in the README.md file.

int main(int argc, char const *argv[])
{
    system("clear");

    // Predefined length of int array
    size_t numbers_len = 50;

    // Predefined pointer to array

    int numbers_arr[50];
    
    // TODO: Write your code here

    // Step 0: Fill Array with Random Numbers

    srand(time (NULL));     //returns the current time 

    for (size_t i = 0; i < numbers_len; i++)
    {
        numbers_arr[i] = (rand() % 99 ) + 1;  // this will fill the numbers_arr with random numbers between 0 and 99
    }                                         // result inside braces returns values between 0 and 98, hence we have to add 1 to get a range from 1 to 99 

    // Step 1: Compute sum of the array

    int result_sum = sum_int_array(numbers_arr, numbers_len);
    
    // Step 2: Compute average of the array

    double result_average = average_int_array(numbers_arr, numbers_len);

    // Step 3: Print array with print_int_array()

    print_int_array(numbers_arr, numbers_len);

    // Step 4: Print sum of the array

    printf("sum = %d \n", result_sum);
    

    // Step 5: Print average of the array

    printf("average = %lf \n", result_average);

    return 0;
}

// Implement this function
void print_int_array(int *arr, size_t arr_len)
{
    for (size_t i = 0; i < arr_len; i++)
    {
        printf("a[%zu] = %d\n", i, arr[i]);
    }   

    return;
}

// Implement this function
int sum_int_array(int *arr, size_t arr_len)
{
    int sum = 0;

    for (size_t i = 0; i < arr_len; i++)
    {
        sum = sum + arr[i];
    }

    return sum;
}

// Implement this function
double average_int_array(int *arr, size_t arr_len)
{
    double average = 0;

    average = (sum_int_array(arr, arr_len) / arr_len);

    return average;
}

