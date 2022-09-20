#include <iostream>
#include <vector>
using namespace std;

void SieveOfEratosthenes(int end, vector<int>& prime)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.

   
    for (int p = 2; p * p <= end; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= end; i += p)
                prime[i] = false;
        }
    }
 
    
}


int start, end_a;
int main(){
    cin >> start >> end_a;

    vector <int> prime_list (end_a + 1, true) ;
    SieveOfEratosthenes(end_a, prime_list);


    return 0;
}