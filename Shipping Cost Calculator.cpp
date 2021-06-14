// Week 3 Programming Assignment.cpp : Shipping Cost Calculator

/* *********************************************************************************************************************************************************************************************************

    Write a Shipping Cost Calculator program that does the following:


        * Prompt and retrieve the following input from the user (through the console):
            - Item name
            - Is the item fragile (if the item is fragile add $2.00 to the shipping cost)
            - The order total (without shipping)
            - The destination to which the item will be shipped (USA, Canada, Australia)

        * Format the output exactly as in the following image:

        * If the user enters an incorrect value for the question "Is the item fragile?" or "Please enter your destination", the program should indicate that an incorrect value was entered and then exit
        the program.

        * The Program should perform as intended with either uppercase or lowercase text entry (e.g. the user can enter either "y" or Y").

        * The program should not only write to the console window but also to a file named "Order.txt"


        * Use the following table to determine the calculations to perform:
        * Add one more destination (Mars or some other planet)

                Order Total             Ship to USA         Ship to Canada          Ship to Australia       Ship to Neptune

                Less than $50.00        $6.00               $8.00                   $10.00                  $200,000.00
                $50.01 to $100.00       $9.00               $12.00                  $14.00                  $200,150.00
                $100.01 to $150.00      $12.00              $15.00                  $17.00                  $200,500.00
                Over $150.00            Free                Free                    Free                    Free





********************************************************************************************************************************************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>

using namespace std;




// Name contsants for the shipping costs in each total order price range. Name a constant for the fragile object cost as well.
const double ORDER_TOTAL_RANGE1_toUSA = 6.00;
const double ORDER_TOTAL_RANGE1_toCAN = 8.00;
const double ORDER_TOTAL_RANGE1_toAUS = 10.00;
const double ORDER_TOTAL_RANGE1_toNEP = 200000.00;

const double ORDER_TOTAL_RANGE2_toUSA = 9.00;
const double ORDER_TOTAL_RANGE2_toCAN = 12.00;
const double ORDER_TOTAL_RANGE2_toAUS = 14.00;
const double ORDER_TOTAL_RANGE2_toNEP = 200150.00;

const double ORDER_TOTAL_RANGE3_toUSA = 12.00;
const double ORDER_TOTAL_RANGE3_toCAN = 15.00;
const double ORDER_TOTAL_RANGE3_toAUS = 17.00;
const double ORDER_TOTAL_RANGE3_toNEP = 200500.00;

const double ORDER_TOTAL_RANGE4_toUSA = 0.00;
const double ORDER_TOTAL_RANGE4_toCAN = 0.00;
const double ORDER_TOTAL_RANGE4_toAUS = 0.00;
const double ORDER_TOTAL_RANGE4_toNEP = 0.00;


const double FRAGILE_OBJECT = 2.00;




int main()
{
    // Display the heading in the console
    cout << ".................................................." << endl;
    cout << "ITCS 2530 - Programming Assignment for Week #3" << endl;
    cout << ".................................................." << endl;


    // Declare variables for user inputs
    string enteredItemName;                 // To store the item name
    char itemFragile;                       // To store the response to whether the item is fragile
    double enteredOrderTotal = 0;           // To store the amount of the total order
    string enteredDestination;              // To store the response for the shipping destination

    // Declare output variables
    double shippingCost = 0;                // To display the final shipping cost
    string shippingLocation;                // To display the shipping location
    double totalCost = 0;                   // To display the total cost (order total + shipping)
    double fragileObjectCost = 0;           // To add $2.00 if the user enters that the object is fragile



    // Prompt user for the item name, store it in the string variable
    cout << "\nPlease enter the item name (no spaces)" << setw(15) << setfill('.') << ": ";
    cin >> enteredItemName;


    // Ask user if the item is fragile, store response in the char variable
    cout << "Is the item fragile? (y = yes / n = no)" << setw(14) << setfill('.') << ": ";
    cin >> itemFragile;

    // Determine whether the user entered a valid response, and add $2.00 if they answered yes

    if (itemFragile == 'y' || itemFragile == 'Y')                                     // If the user responds yes, the fragile object cost is $2.00
    {
        fragileObjectCost = FRAGILE_OBJECT;
    }
    else if (itemFragile == 'n' || itemFragile == 'N')                                // If the user responds no, there is no additional cost
    {
        fragileObjectCost = 0.00;
    }
    else
    {
        cout << "\nInvalid entry, exiting program" << endl;                           // If a valid char is not entered by the user, display this message & end the program
        return 1;
    }


    // Prompt user for the order total, store it in the double variable
    cout << "Please enter your order total" << setw(24) << setfill('.') << ": ";
    cin >> enteredOrderTotal;

    // Prompt user for the shipping destination, store it in the string variable
    cout << "Please enter the destination (usa/can/aus/nep)" << setw(7) << setfill('.') << ": ";
    cin >> enteredDestination;



    /* _____________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ */

        // Determine the shipping and total costs. First, determine the shipping destination of the item. Then, evaluate which price range the user's entered order total falls withtin. Calculate the shipping costs using
        // the declared constants from the table values, and add any additional costs for fragile objects.

    if (enteredDestination == "usa" || enteredDestination == "USA")             // If the entered destination is USA,
    {
        shippingLocation = "USA";                                                   // Change shipping location to "USA"

        if (enteredOrderTotal <= 50.00)                                                     // If the user's order total falls in Range 1 ($0.00 - $50.00)
        {
            shippingCost = ORDER_TOTAL_RANGE1_toUSA + fragileObjectCost;                            // Add the shipping cost to any cost for fragile objects
            totalCost = enteredOrderTotal + shippingCost;                                           // Add the total order amount entered by the user to the total shipping cost
        }
        else if (enteredOrderTotal >= 50.01 && enteredOrderTotal <= 100.00)                 // If the user's order total falls in Range 2 ($50.01 - $100.00)
        {
            shippingCost = ORDER_TOTAL_RANGE2_toUSA + fragileObjectCost;                            // Add the shipping cost to any cost for fragile objects
            totalCost = enteredOrderTotal + shippingCost;                                           // Add the total order amount entered by the user to the total shipping cost
        }
        else if (enteredOrderTotal >= 100.01 && enteredOrderTotal <= 150.00)                // If the user's order total falls in Range 3 ($100.01 - $150.00)
        {
            shippingCost = ORDER_TOTAL_RANGE3_toUSA + fragileObjectCost;                            // etc.
            totalCost = enteredOrderTotal + shippingCost;                                           // etc.
        }
        else if (enteredOrderTotal > 150.00)                                                // If the user's order total falls in Range 4 (more than $150.00)
        {
            shippingCost = ORDER_TOTAL_RANGE4_toUSA;                                                // Shipping for all orders in this price range is free, so no fragile object cost is added
            totalCost = enteredOrderTotal + shippingCost;                                           // etc.
        }
    }
    else if (enteredDestination == "can" || enteredDestination == "CAN")        // If the entered destination is Canada,
    {
        shippingLocation = "CAN";                                                   // Change the shipping location to "CAN"

        if (enteredOrderTotal <= 50.00)                                                     // If the user's order total falls in Range 1 ($0.00 - $50.00)
        {
            shippingCost = ORDER_TOTAL_RANGE1_toCAN + fragileObjectCost;                            // etc.
            totalCost = enteredOrderTotal + shippingCost;                                           // etc.
        }
        else if (enteredOrderTotal >= 50.01 && enteredOrderTotal <= 100.00)
        {
            shippingCost = ORDER_TOTAL_RANGE2_toCAN + fragileObjectCost;
            totalCost = enteredOrderTotal + shippingCost;
        }
        else if (enteredOrderTotal >= 100.01 && enteredOrderTotal <= 150.00)
        {
            shippingCost = ORDER_TOTAL_RANGE3_toCAN + fragileObjectCost;
            totalCost = enteredOrderTotal + shippingCost;
        }
        else if (enteredOrderTotal > 150.00)
        {
            shippingCost = ORDER_TOTAL_RANGE4_toCAN;
            totalCost = enteredOrderTotal + shippingCost;
        }
    }
    else if (enteredDestination == "aus" || enteredDestination == "AUS")        // If the entered destination is Australia,
    {
        shippingLocation = "AUS";                                                   // Change the shipping location to "AUS"

        if (enteredOrderTotal <= 50.00)                                                     // If the user's order total falls in Range 1 ($0.00 - $50.00)
        {
            shippingCost = ORDER_TOTAL_RANGE1_toAUS + fragileObjectCost;                            // etc.
            totalCost = enteredOrderTotal + shippingCost;                                           // etc.     
        }
        else if (enteredOrderTotal >= 50.01 && enteredOrderTotal <= 100.00)
        {
            shippingCost = ORDER_TOTAL_RANGE2_toAUS + fragileObjectCost;
            totalCost = enteredOrderTotal + shippingCost;
        }
        else if (enteredOrderTotal >= 100.01 && enteredOrderTotal <= 150.00)
        {
            shippingCost = ORDER_TOTAL_RANGE3_toAUS + fragileObjectCost;
            totalCost = enteredOrderTotal + shippingCost;
        }
        else if (enteredOrderTotal > 150.00)
        {
            shippingCost = ORDER_TOTAL_RANGE4_toAUS;
            totalCost = enteredOrderTotal + shippingCost;
        }
    }
    else if (enteredDestination == "nep" || enteredDestination == "NEP")        // If the entered destination is Neptune,
    {
        shippingLocation = "NEPTUNE";                                                   // Change the shipping location to "NEP"

        if (enteredOrderTotal <= 50.00)                                                     // If the user's order total falls in Range 1 ($0.00 - $50.00)
        {
            shippingCost = ORDER_TOTAL_RANGE1_toNEP + fragileObjectCost;                            // etc.
            totalCost = enteredOrderTotal + shippingCost;                                           // etc.     
        }
        else if (enteredOrderTotal >= 50.01 && enteredOrderTotal <= 100.00)
        {
            shippingCost = ORDER_TOTAL_RANGE2_toNEP + fragileObjectCost;
            totalCost = enteredOrderTotal + shippingCost;
        }
        else if (enteredOrderTotal >= 100.01 && enteredOrderTotal <= 150.00)
        {
            shippingCost = ORDER_TOTAL_RANGE3_toNEP + fragileObjectCost;
            totalCost = enteredOrderTotal + shippingCost;
        }
        else if (enteredOrderTotal > 150.00)
        {
            shippingCost = ORDER_TOTAL_RANGE4_toNEP;
            totalCost = enteredOrderTotal + shippingCost;
        }
    }
    else                                                                        // If a valid destination is not entered by the user, display this message and end the program
    {
        cout << "\nInvalid entry, exiting program" << endl;
        return 1;
    }




    /* _______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________ */

        // Display the output in the console

    transform(enteredItemName.begin(), enteredItemName.end(), enteredItemName.begin(), ::toupper);                          // Capitalize the item name 

        // Display the capitalized item name, shipping cost, shipping location, total cost, and thank you message. All lines of output should align at the right of the console. 
        // The shipping and total costs should be displayed to two decimal points. */
    cout << "\n";
    cout << "\nYour item is" << setw(23) << setfill('.') << " " << enteredItemName;
    cout << "\nYour shipping cost is" << setw(15) << setfill('.') << fixed << setprecision(2) << " $" << shippingCost;
    cout << "\nYou are shipping to" << setw(16) << setfill('.') << " " << shippingLocation;
    cout << "\nYour total cost is" << setw(18) << setfill('.') << fixed << setprecision(2) << " $" << totalCost << endl;
    cout << "\n---------------------------------- Thank You!" << endl;
    cout << "\n";



    // Write the output to a file

    ofstream orderFile;                             // Create and open a file named "Order.txt"
    orderFile.open("Order.txt");

    if (!orderFile)                                 // Display an error message if the file cannot be opened.
    {
        cout << "Unable to open file." << endl;
    }

    // Write the order details to the Order.txt file
    orderFile << "\n";
    orderFile << "\nYour item is" << setw(23) << setfill('.') << " " << enteredItemName;
    orderFile << "\nYour shipping cost is" << setw(15) << setfill('.') << fixed << setprecision(2) << " $" << shippingCost;
    orderFile << "\nYou are shipping to" << setw(16) << setfill('.') << " " << shippingLocation;
    orderFile << "\nYour total cost is" << setw(18) << setfill('.') << fixed << setprecision(2) << " $" << totalCost << endl;
    orderFile << "\n---------------------------------- Thank You!" << endl;
    orderFile << "\n";

    orderFile.close();                              // Close the file  



    system("pause");
    return 0;
}
