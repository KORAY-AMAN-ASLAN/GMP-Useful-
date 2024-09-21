#include <gmp.h>
#include <iostream>


// https://machinecognitis.github.io/Math.Gmp.Native/html/2ddc32dc-4ee3-18e9-dd3d-7e64c3304e1e.htm
// https://home.cs.colorado.edu/~srirams/courses/csci2824-spr14/gmpTutorial.html
// g++ -o statistic compbinatoric.cpp -lgmp
// ./statistic


// Learn more:
// https://www.britannica.com/science/permutation


void factorial(mpz_t result, unsigned long n) {
    mpz_fac_ui(result, n); 
}

// C(n, k) = n! / (k! * (n - k)!)
void combinations(mpz_t result, unsigned long n, unsigned long k) {
    mpz_t fact_n, fact_k, fact_n_k;

    // Initialize variables
    mpz_inits(fact_n, fact_k, fact_n_k, NULL);

    factorial(fact_n, n);
    factorial(fact_k, k);
    factorial(fact_n_k, n - k);

    // result = n! / (k! * (n - k)!)
    mpz_mul(result, fact_k, fact_n_k); 
    mpz_divexact(result, fact_n, result); 


    mpz_clears(fact_n, fact_k, fact_n_k, NULL);
}

//  P(n, r) = n! / (n - r)!
void permutations(mpz_t result, unsigned long n, unsigned long r) {
    mpz_t fact_n, fact_n_r;

    // Initialize variables
    mpz_inits(fact_n, fact_n_r, NULL);

    factorial(fact_n, n);
    factorial(fact_n_r, n - r);

    // result = n! / (n - r)!
    mpz_divexact(result, fact_n, fact_n_r);

    mpz_clears(fact_n, fact_n_r, NULL);
}
int main() {
    mpz_t result;
    mpz_init(result);

    int choice;
    do {
        std::cout << "Choose an operation: \n";
        std::cout << "1. Factorial\n";
        std::cout << "2. Combinations\n";
        std::cout << "3. Permutations\n";
        std::cout << "4. Exit\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Factorial calculation
                unsigned long n;
                std::cout << "Enter a number to compute factorial: ";
                std::cin >> n;

                factorial(result, n);

                std::cout << n << "! = ";
                mpz_out_str(stdout, 10, result);
                std::cout << std::endl;
                break;
            }

            case 2: {
                // Combinations calculation
                unsigned long n, k;
                std::cout << "Enter n and k for combinations C(n, k):\n";
                std::cout << "n: ";
                std::cin >> n;
                std::cout << "k: ";
                std::cin >> k;

                if (k > n) {
                    std::cout << "k cannot be greater than n.\n";
                } else {
                    combinations(result, n, k);

                    std::cout << "C(" << n << ", " << k << ") = ";
                    mpz_out_str(stdout, 10, result);
                    std::cout << std::endl;
                }
                break;
            }

            case 3: {
                // Permutations calculation
                unsigned long n, r;
                std::cout << "Enter n and r for permutations P(n, r):\n";
                std::cout << "n: ";
                std::cin >> n;
                std::cout << "r: ";
                std::cin >> r;

                if (r > n) {
                    std::cout << "r cannot be greater than n.\n";
                } else {
                    permutations(result, n, r);

                    std::cout << "P(" << n << ", " << r << ") = ";
                    mpz_out_str(stdout, 10, result);
                    std::cout << std::endl;
                }
                break;
            }

            case 4: {
                // Exit the loop
                std::cout << "Exiting..." << std::endl;
                break;
            }

            default:
                std::cout << "Invalid choice! Please select a valid option." << std::endl;
                break;
        }
    } while (choice != 4);

    // Clare memory
    mpz_clear(result);
    return 0;
}
