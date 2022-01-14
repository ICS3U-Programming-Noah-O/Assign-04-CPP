// Copyright (c) 2022 Noah Ouellette All rights reserved.
//
// Created by: Noah Ouellette
// Created on: Jan. 10, 2022
// This program allows a user to enter two integers in order
// to compute sine, cosine and tangent for a given number
// while the other number determines the
// number of repetitons of the taylor series
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <cmath>


// The cpplint says that global strings are an
// error, I am not sure how to fix this.
std::string userNum;
std::string userCountNum;
double userNumInt;
double userCountNumInt;


double sinx() {
    // Function that calculates and displays sine
    double factSin;
    double sinX;
    int countNum;
    int counter;
    sinX = 0;
    countNum = userCountNumInt;
    for (counter = 0; counter < countNum; counter++) {
        factSin = tgamma((2 * counter + 1) + 1);
        sinX += pow(-1.0, counter) * pow(userNumInt, 2*counter+1) / factSin;
    }

    std::cout << " \n";
    std::cout << "The sine of " << userNumInt;
    std::cout << " is approximately " << sinX << "\n";
}

double cosx() {
    // Function that calculates and displays cosine
    double factCos;
    double cosX;
    int countNum;
    int counter;
    cosX = 0;
    countNum = userCountNumInt;
    for (counter = 0; counter < countNum; counter++) {
        factCos = tgamma((2 * counter) + 1);
        cosX += pow(-1.0, counter) * pow(userNumInt, 2*counter) / factCos;
    }

    std::cout << " \n";
    std::cout << "The cosine of " << userNumInt;
    std::cout << " is approximately " << cosX << "\n";
}

double tanx() {
    // Function that calculates and displays tangent by calculating both
    // sine and cosine first
    double factCos;
    double cosX;
    double factSin;
    double sinX;
    double tanX;
    int countNum;
    int counter;
    cosX = 0;
    sinX = 0;
    tanX = 0;
    countNum = userCountNumInt;
    for (counter = 0; counter <= countNum; counter++) {
        factCos = tgamma((2 * counter) + 1);
        cosX += pow(-1.0, counter) * pow(userNumInt, 2*counter) / factCos;
        factSin = tgamma((2 * counter + 1) + 1);
        sinX += pow(-1.0, counter) * pow(userNumInt, 2*counter+1) / factSin;
        tanX = sinX / cosX;
    }

    std::cout << " \n";
    std::cout << "The tangent of " << userNumInt;
    std::cout << " is approximately " << tanX << "\n";
}

int decision() {
    // Loop that allows the user to decide which
    // calculation they want to perform
    std::string userAns;
    do {
        std::cout << "Would you like to calculate sine, ";
        std::cout << "cosine or tangent? sine/cosine/tangent: ";
        std::cin >> userAns;
        std::cout << " \n";

        if (userAns == "sine" || userAns == "Sine") {
            // Calls sine function and breaks loop
            sinx();
        } else if (userAns == "cosine" || userAns == "Cosine") {
            // Calls cosine function and breaks loop
            cosx();
        } else if (userAns == "tangent" || userAns == "Tangent") {
            // Calls tangent function and breaks loop
            tanx();
        } else {
            // Invalid input message
            std::cout << "Enter either 'sine', 'cosine' or 'tangent.\n";
        }
    }while (userAns != "cosine" && userAns != "Cosine" &&
            userAns != "Sine" && userAns != "sine" &&
            userAns != "tangent" && userAns != "Tangent");
}


int main() {
    // Print introduction message to user
    std::cout << "Welcome! This program can calculate the approximate values ";
    std::cout << "of the sine, cosine and tangent ";
    std::cout << "of a given number 25 or less.\n";
    sleep(1.5);


    // Loop that gets and checks user input
    do {
        userNumInt = 0;
        std::cout << " \n";
        std::cout << "Enter the number that you'd like to calculate with: ";
        std::cin >> userNum;
        std::cout << " \n";

        try {
            // Make sure user input is an integer
            userNumInt = std::stoi(userNum);

            // Makes sure that user number is below 26 and above -26
            if (userNumInt < 26 && userNumInt > -26) {
                // Loop that asks the user for the number of times
                // that they want the series to loop
              do {
                  std::cout << " \n";
                  std::cout << "It is recommended that you loop at least ";
                  std::cout << "25 times to get accurate results. \n";
                  sleep(0.5);

                  // Make sure that user input is above 0 and an integer
                  std::cout << "Please enter the number of times that you ";
                  std::cout << "would like to loop: ";
                  std::cin >> userCountNum;
                  std::cout << " \n";

                  try {
                      userCountNumInt = std::stoi(userCountNum);

                      if (userCountNumInt > 0) {
                          // Call decision function and break loop
                          sleep(1);
                          std::cout << " \n";
                          decision();
                          break;

                      } else {
                          std::cout << "You must enter a number above 0.\n";
                      }
                    } catch (std::invalid_argument) {
                       std::cout << userCountNum << "  is not a number.\n";
                    }
              }while (userCountNumInt <= 0);

            } else if (userNumInt < -25) {
                std::cout << userNumInt << " is too small, please ";
                std::cout << "enter a number that is -25 or above.\n";
            } else {
                std::cout << userNumInt;
                std::cout << " is too big, please enter a ";
                std::cout << "number that is 25 or under.\n";
            }
        } catch (std::invalid_argument) {
            std::cout << userNum << " is not a number\n";
        }
    } while (userNumInt > 26 || userNumInt < -25 || userNumInt == 0);
}
