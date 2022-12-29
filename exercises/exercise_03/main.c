// Allowed libraries are already included
// You can add your own libraries if you need to
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// ...

// Macros
// You may change these to your likings
#define CELSIUS_OFFSET 273.15
#define FAHRENHEIT_FRACTION 9/5
#define FAHRENHEIT_OFFSET 32

#define CLA
// ...

// Protoypes
float get_float(char text[], float MIN, float MAX);
float celsius_to_fahrenheit(float input_celsius);


// IMPORTANT REQUIREMENTS/LIMITATIONS
//
// Read the requirements and limitations carefully.
// You can find them in the README.md file.
//
// Example CLI usage:
// $ ./temp-conv 293.15 kelvin -t celsius
//
// Use dedicated functions to convert temperatures.
// Use dedicated functions to print the output.
// stdin/stdout should not happend in the main!!!

int main(int argc, char const *argv[])
{
    #ifdef STDIN
    system("clear");

    double input_celsius = get_float("Geben Sie eine Temperatur in Celcius ein", -100, 100);
    
    //Celcius into Fahrenheit
    celsius_to_fahrenheit(input_celsius);

    return 0;
    #endif

    #ifdef CLA

    system("clear");

    //Celcius into Fahrenheit
    char* temp = argv[1];              

    float temp_in_float = atof(temp);     

    celsius_to_fahrenheit(temp_in_float);

    return 0;
    #endif

}



float celsius_to_fahrenheit(float input_celsius)
{
    float temp_in_fahrenheit;
    temp_in_fahrenheit = (input_celsius * 9/5) + 32;
    printf("Temperatur in Fahrenheit: %.2lf\n", temp_in_fahrenheit);

    return temp_in_fahrenheit;
}


float get_float(char text[], float MIN, float MAX)
{
    //declare working variables 
    float value;
    int finished = 0; //0 für FALSE
    char ch;
    int retVal;


    do
    {
        printf("%s: ", text); //Abkürzung "s" für "string" / Zeichenkette

        ch = '\0'; // \0 wird als ein Buchstabe gewertet; O ist nicht die Zahl 0 sondern ein "Null Character"; Null Character hat in der Ascii Tabelle auch den Wert 0

        retVal = scanf("%f%c", &value, &ch); // -> "hd" steht für short -> Adresse ist "Value"; scanf gibt auch einen Wert zurück, diesen speichern wir in retVal 

        // check for valid user input

        if (retVal != 2) printf("Das war keine korrekte Zahl!\n");

        else if (ch != '\n') printf("Unerwartete Zeichen hinter der Zahl!\n");

        else if (value < MIN) printf("Zahl ist zu klein (MIN: %f)\n", MIN);

        else if (value > MAX) printf("Zahl ist zu groß (MAX: %f)\n", MAX);

        else finished = 1; // falls die Variable tatsächlich 2 ist; und der character ein newline, ist alles richtig und die loop wird beendet

        //Variable finished wird auf 1 gesetzt -> weil 1 für TRUE

        //clear input stream buffer

        while (ch != '\n') scanf("%c", &ch); //Variation mit scanf von getchar

    } while (!finished); //repeat if not finished 

    //return user input
    return value; //wer auch immer die Funktion get_short aufruft bekomm "value" zurück
}
