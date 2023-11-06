/* SCENARIO

You are going grocery shopping.

The following coding challenges will task you to do the following:

 - Determine if you need to refuel your car based on the given fuel level in the
tank
 - Count how many broken eggs are in a carton containing a dozen
 - Determine the freshest bag of milk from a given set of dates
 - Locate the aisle based on a desired grocery item in a store
 - Recursively search the entire store to determine the aisle of a grocery item

You have 25 minutes, minus the time you spent reading this! Let's get shopping!
*/

#include <stdbool.h> // Boolean data type
#include <stdio.h>   // Standard Input and Output functions
#include <stdlib.h>  // Standard Library functions -> srand function
#include <string.h>  // String manipulation functions
#include <time.h>    // Date and Time functions -> time is the seed to srand

void setRandomSeed(int seed);
void generateDozen(int array[2][6]);
float getFuelLevel();
int* generateBestBeforeDates(int* bytes);
char* getItemFromList();
char* getItemToFind();
void generateStore(char** storeList);
int searchAisle(const char* item, char* aisles[], int numAisles,
                int currentAisle, int areYouLost);

bool checkRefuel(float fuelLevel) {
    bool refuel;

    if (fuelLevel < 0.25) {
        refuel = true;
    } else {
        refuel = false;
    }

    return refuel;
}

bool challenge1() {
    printf("\n=== CHALLENGE 1 ===\n");
    /*
    On the drive to the grocery store, you check if your gas tank needs
    to be refueled. If the tank is less than 25%, you refuel. Otherwise,
    do not refuel the tank.

    INPUT: fuelLevel will have a random value between 0 and 1.
    OUTPUT: Implement a function called "checkRefuel" which will determine
            whether it is necessary to refuel the gas tank or not. This
            function should take in "fuelLevel" as an argument and return
            a boolean to the "refuel" variable.
    */

    bool refuel;
    float fuelLevel;
    fuelLevel = getFuelLevel(); // DO NOT EDIT THIS FUNCTION. THE VALUE IS
                                // GENERATED FOR YOU.

    /* ENTER YOUR CODE HERE*/

    refuel = checkRefuel(fuelLevel);

    /* STOP WRITING YOUR CODE HERE*/

    if (refuel) {
        printf("Refuel");
    } else {
        printf("Do not refuel");
    }
    printf("\n");

    return refuel;
}

int challenge2() {
    printf("\n=== CHALLENGE 2 ===\n");
    /*
    The eggs at the store are very bad quality. Many eggs are broken
    Let a dozen of eggs be a 2 x 6 matrix, where each egg is a cell of
    the matrix. The "egg" has value 0 if it is GOOD and a value of -1
    if it is BROKEN.

    INPUT: A 2 x 6 integer array of values either 0 or -1.
    OUTPUT: Count the number of BROKEN eggs (-1) in the dozen.
    */

    int dozen[2][6];
    generateDozen(
        dozen); // DO NOT EDIT THIS FUNCTION. THE ARRAY IS GENERATED FOR YOU.

    int brokenEggCount = -1;

    /* ENTER YOUR CODE HERE*/

    brokenEggCount = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            if (dozen[i][j] == -1) {
                brokenEggCount++;
            }
        }
    }

    /* STOP WRITING YOUR CODE HERE*/

    printf("Number of broken eggs:\t%d\n", brokenEggCount);
    return brokenEggCount;
}

int challenge3() {
    printf("\n=== CHALLENGE 3 ===\n");
    /*
    You want to purchase the freshest milk on the shelf. Choose the milk with
    the furthest Best Before date in the future. The Best Before dates are
    given between September 1st, 2023 (230901) and October 31st, 2023 (231031).

    INPUT:  An integer array of unknown length of values between 230901-230930
    and 231001-231031. There will be an arbitrary amount of dates to check. You
    are provided with numBytes, the size of the array in bytes. You are
    guaranteed the array ends with a 0.

    OUTPUT: The newest best before date from the input list.
    */

    int numBytes;
    int* bestBeforeDates = generateBestBeforeDates(&numBytes);
    int freshestMilk = -1;

    /* ENTER YOUR CODE HERE*/
    freshestMilk = 0;
    int i = 0;
    while (bestBeforeDates[i]) {
        if (bestBeforeDates[i] > freshestMilk) {
            freshestMilk = bestBeforeDates[i];
        }
        i++;
    }
    /* STOP WRITING YOUR CODE HERE*/

    printf("The Best Before of the freshest milk is:\t%d\n", freshestMilk);
    return freshestMilk;
}

int challenge4() {
    printf("\n=== CHALLENGE 4 ===\n");
    /*
    You are implementing an algorithm to tell you the aisle a grocery
    item is in. You successfully managed to make it with a nested-switch
    block. This is not an intuitive way to code this and it is difficult
    to read. Adding more items will add more layers to the switch block.

    GOAL: Convert the below switch block into an if, else if, else block.
    */

    char* groceryItem = getItemFromList();
    int aisleNum = -1;

    /* ENTER YOUR CODE HERE*/

    if (strcmp(groceryItem, "Cheerios") == 0) {
        aisleNum = 6;
    } else if (strcmp(groceryItem, "Kraft Dinner") == 0) {
        aisleNum = 7;
    } else {
        aisleNum = 0;
    }

    /* STOP WRITING YOUR CODE HERE*/

    printf("Grocery Item:\t%s\tAisle Number:\t%d\n", groceryItem, aisleNum);

    return aisleNum;
}

int challenge5() {
    printf("\n=== CHALLENGE 5 ===\n");
    /*
    Let's try a different approach to finding the Aisle Number of an item.
    Rather than checking the Aisle Number corresponding to a specific item,
    you will recursively search for an item throughout the entire store,
    aisle by aisle, until you find the aisle that the item is located in.

    This has been implemented in the function searchAisle, but the recursion
    is not fully working. Figure out what's wrong and fix it!

    GOAL: Fix the recursion in searchAisle() defined below, just after this
    function

    Do not edit the challenge5() function. Only edit searchAisle().
    */

    // Select an item to find in the store
    char* itemToLocate = getItemToFind(); // DO NOT EDIT THIS FUNCTION. THE
                                          // VALUE IS GENERATED FOR YOU.

    // Create the list of items on each aisle of the store
    int numAisles = 10;
    char* storeList[numAisles];
    generateStore(storeList); // DO NOT EDIT THIS FUNCTION. THE VALUE IS
                              // GENERATED FOR YOU.

    // Recursively search to find the located aisle
    int locatedAisle = searchAisle(itemToLocate, storeList, numAisles, 0, 0);

    printf("%s\n", itemToLocate);
    if (locatedAisle != -1) {
        printf("Item found in Aisle %d\n",
               locatedAisle); // Adding 1 because aisles are typically numbered
                              // starting from 1.
    } else if (locatedAisle == -2) {
        printf("You got lost!.\n");
    } else {
        printf("Item not found in any aisle.\n");
    }
    return locatedAisle;
}

int searchAisle(const char* item, char* aisles[], int numAisles,
                int currentAisle, int areYouLost) {
    if (areYouLost == 100) {
        // This is preventing the code from running into a segmentation fault
        printf("You're lost in the store (you have infinite recursion)\n");
        return -2;
    }

    // Base case: All aisles have been searched, and the item hasn't been found
    if (currentAisle == numAisles) {
        return -1;
    }

    // Search for the item in the current aisle.
    const char* currentItems = aisles[currentAisle];
    if (strstr(currentItems, item) != NULL) {
        return currentAisle; // Found the item in the current aisle.
    }

    // Recursively search the next aisle.
    return searchAisle(item, aisles, numAisles, ++currentAisle, ++areYouLost);
}

// ------------- IGNORE FROM HERE ------------- //
int main(int argc, char* argv[]) {
    if (argc < 2) {
        setRandomSeed(0);
        challenge1();
        challenge2();
        challenge3();
        challenge4();
        challenge5();
    } else {
        printf("SOMETHING IS WRONG WITH YOUR EXECUTION. DO NOT PASS IN COMMAND "
               "LINE ARGUMENTS");

        int seedValue = atoi(argv[1]);
        setRandomSeed(seedValue);

        bool test1 = challenge1();
        int test2 = challenge2();
        int test3 = challenge3();
        int test4 = challenge4();
        int test5 = challenge5();

        char file1_name[256], file2_name[256], file3_name[256], file4_name[256],
            file5_name[256];

        snprintf(file1_name, sizeof(file1_name), "test1_%i.txt", seedValue);
        snprintf(file2_name, sizeof(file2_name), "test2_%i.txt", seedValue);
        snprintf(file3_name, sizeof(file3_name), "test3_%i.txt", seedValue);
        snprintf(file4_name, sizeof(file4_name), "test4_%i.txt", seedValue);
        snprintf(file5_name, sizeof(file5_name), "test5_%i.txt", seedValue);

        FILE* file1 = fopen(file1_name, "w");
        FILE* file2 = fopen(file2_name, "w");
        FILE* file3 = fopen(file3_name, "w");
        FILE* file4 = fopen(file4_name, "w");
        FILE* file5 = fopen(file5_name, "w");

        // Check if file openings were successful
        if (file1 == NULL || file2 == NULL || file3 == NULL || file4 == NULL ||
            file5 == NULL) {
            printf("Error opening files!\n");
            exit(1);
        }

        // Write test results to their respective files
        fprintf(file1, "%d", test1);
        fprintf(file2, "%d", test2);
        fprintf(file3, "%d", test3);
        fprintf(file4, "%d", test4);
        fprintf(file5, "%d", test5);

        // close the files
        fclose(file1), fclose(file2), fclose(file3), fclose(file4),
            fclose(file5);
        return 0;
    }
}

void setRandomSeed(int seed) {
    if (seed == 0) {
        seed = (int)time(NULL);
    }
    srand(seed); // Set the seed
}

// Generate a random float between 0 and 1
float getFuelLevel() { return (float)rand() / (float)RAND_MAX; }

// Generate a 2 x 6 array of 0s and -1s
void generateDozen(int array[2][6]) {
    // Generate and populate the array with random -1s and 0s
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 6; j++) {
            // Generate a random number that's either -1 or 0
            array[i][j] = (rand() % 2 == 0) ? 0 : -1;
        }
    }
}

/* Generates an integer array.
Returns an unknown length array of values with a 0 at the end
Sets the bytes variable to the size of the array in bytes
*/
int* generateBestBeforeDates(int* bytes) {
    // Generate a random number of best before dates
    int numDates = (rand() % 30);

    // Allocate memory for the array
    int* array = (int*)malloc((numDates + 1) * sizeof(int));
    *bytes = numDates * sizeof(int);

    if (array == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }

    int randVal;
    for (int i = 0; i < numDates; i++) {
        // Generate a random integer between min and max (inclusive)
        randVal = (rand() % 61);
        if (randVal > 29) {
            array[i] = randVal + 231001 - 30;
        } else {
            array[i] = randVal + 230901;
        }
        // printf("%d\n", array[i]);
    }
    array[numDates] = 0;

    return array;
}

/*
Returns a random string from a list of items
*/
char* getItemFromList() {
    // An array of strings
    char* groceryItems[] = {"Apples",  "Bananas", "Bread",        "Cheerios",
                            "Eggs",    "Milk",    "Kraft Dinner", "Spinach",
                            "Chicken", "Oreos"};

    int length = sizeof(groceryItems) / sizeof(groceryItems[0]);

    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        // Swap the strings at positions i and j
        char* temp = groceryItems[i];
        groceryItems[i] = groceryItems[j];
        groceryItems[j] = temp;
    }

    return groceryItems[0];
}

/*
Returns a random string from a list of items
*/
char* getItemToFind() {
    char* listOfItems[32] = {
        "Pineapple", "Bananas",       "Bread",      "Milk",
        "Eggs",      "Cheese",        "Chicken",    "Rice",
        "Tomatoes",  "Potatoes",      "Onions",     "Pasta",
        "Cereal",    "Yogurt",        "Oranges",    "Carrots",
        "Broccoli",  "Salmon",        "Applesauce", "Pepper",
        "Salt",      "Peanut Butter", "Jelly",      "Lettuce",
        "Cucumbers", "Ketchup",       "Mustard",    "Mayonnaise",
        "Pickles",   "Kraft Dinner",  "Oreos",      "Gingerale"};

    int length = sizeof(listOfItems) / sizeof(listOfItems[0]);

    int i = rand() % (length);

    return listOfItems[i];
}

/*
Sets storeList to be an array of 10 strings
Each string contains various food items as substrings
*/
void generateStore(char** storeList) {
    char* aisleItems[10] = {"",
                            "Bananas, Bread, Milk, Eggs",
                            "Cheese, Chicken, Rice, Tomatoes",
                            "Potatoes, Onions, Pasta",
                            "Yogurt, Oranges, Carrots, Broccoli",
                            "Salmon, Applesauce, Pepper, Salt",
                            "Peanut Butter, Jelly",
                            "Lettuce, Cucumbers",
                            "Pickles",
                            "Ketchup, Mustard, Mayonnaise"};

    for (int i = 0; i < 10; i++) {
        storeList[i] = (char*)malloc(256); // Allocate memory for each string
        strcpy(storeList[i], aisleItems[i]);
    }
}