#include <gmp.h> // Gnu MultiPrecision Library.
#include <iostream>


// To compile 
// Read more: // https://home.cs.colorado.edu/~srirams/courses/csci2824-spr14/gmpTutorial.html
// g++ -o factorial main.cpp -lgmp
//./factorial

int main() {
    // Init
    mpz_t result;
    mpz_init(result);
    
    // fact 50!
    mpz_fac_ui(result, 50);


    std::cout << "50!= ";
    // Base 10
    mpz_out_str(stdout, 10, result);
    std::cout << std::endl;

    // Clear memory
    mpz_clear(result);

    return 0;
}
