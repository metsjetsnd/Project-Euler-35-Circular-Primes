//Shane Brosnan
//pandigitalPrime.cpp
//prints largest pandigital prime for n = 2 to 9

#include <iostream>
#include <cmath>
using namespace std;

int numberLength(int);

int main(){
 
  int num;
  int pandig = 0;
  int length;
  for (int k = 2; k <= 9; k++){//for each value of n from 2 through 9
    if (k == 2)
      num = 21;
    else if (k == 3)
      num = 321;
    else if (k == 4)
      num = 4321;
    else if (k == 5)
      num = 54321;
    else if (k == 6)
      num = 654321;
    else if (k == 7)
      num = 7654321;
    else if (k == 8)
      num = 87654321;
    else if (k == 9)
      num = 987654321;
    for (int t = num; t > 0; t--){//for each n digit number <= num
      length = numberLength(t);
      if (length < k)
        break;
      int number = t;
      int array[length];
      int p = 1;
      for (int i = length; i > 0; i--){
        array[length - i] = number / pow(10, (i - 1));
        number = number - (array[length - i] * pow(10, i - 1));
      }//for i
      for(int z = 0; z < length; z++){//checks to see if t is pandigital
        for (int y = 0; y < length; y++){
          if (z != y){
            if((array[z] == array[y]) || (array[z] > length) || (array[y] > length) || (array[y] == 0) || (array[z] == 0)){
              p = 0;     
            }//if there is a repeat digit or a digit greater than n
          }//if z!= y
          if (p == 0)
            break;
        }//for y
        if (p == 0)
          break;
      }//for z
      if (p == 1){
        pandig = t;
        int count = pandig;
        if(array[length - 1] == 2 || array[length - 1] == 4 || array[length - 1] == 5 || array[length - 1] == 6 || array[length - 1] == 8)//if pandig is even or divisible by 5
          pandig = 0;
        else{
          for (int u = 3; u < (sqrt(count) + 1); u++){//determines if pandig is prime
            if ((pandig % u) == 0){
              pandig = 0;
              break;
            }//if pandig is divisible
            if (pandig == 0)
              break;
          }//for u
        }//else
      }//if p == 1
      if (pandig > 0)//if pandig is not prime
        break;
    }//for t    
 
    if (pandig > 0)
      cout << "Greatest pandigital prime for n = " << k << ": " << pandig << endl;
    else
      cout << "No pandigital prime for n = " << k << endl; 
  
  }//for k
    return 0;

}//main

int numberLength(int number){//returns length of number

  int length = 1;
  for (int i = 10; i <= pow(10,10); i *= 10){
    if((number / i ) >= 1)
      length++;
    else
      break;
  }//for i
  return length;

}//numberLength
#include <iostream>
#include <cmath>
using namespace std;

int numberLength(int);
int isPrime(int [], int, int, int);
int array2int(int [], int, int, int);
void resetArray(int[], int, int);
void int2array(int[], int, int, int);
void printArray(int[], int);

int main(){
  int size, primality;
  int length, primes = 0;
  for (int n = 2; n < 1000000; n++){//checks whether n and all its associated circular integers are prime
    primality = 1;//variable used to to keep 
    length = numberLength(n);
    size = length;
    int array[size];
    int temp[size];
    resetArray(array, size, n);
    int2array(array, size, n, length);
    if (length == 1){//if number is < 10
      if (isPrime(array, size, n, length) == 0)
        primality = 0;
    }//if length == 1
    else if(isPrime(array, size, n, length) != 0){//if n itself is prime, check to see if its associated circulars are
      for (int y = 0; y < length; y++){
        for(int z = 0; z < length; z++){
          if (z + 1 < length)
            temp[z] = array[z + 1];
          else
            temp[z] = array[0];
        }//for z
        for (int g = 0; g < length; g++)
          array[g] = temp[g];
        //printArray(array, length);
        if(isPrime(array, size, n, length) == 0){
          primality = 0;
          break;
        }//if number is not prime
      }//for y
    }//else if number itself is prime
    else
      primality = 0;
    if (primality == 1){
      cout << n << endl;
      primes++;
    }
  }//for n
  cout << "Number of primes is " << primes << endl;
  return 0;
}//main

int numberLength(int number){//returns length of number

  int length = 1;
  for (int i = 10; i <= pow(10,10); i *= 10){
    if((number / i ) >= 1)
      length++;
    else
      break;
  }//for i
  return length;
}//numberLength

int isPrime(int array[], int size, int n, int length){//returns whether number is prime or not
  int prime = 1;
  int number = array2int(array, size, n, length);
  if ((length > 1) && (array[length - 1] == 2 || array[length - 1] == 4 || array[length - 1] == 5 || array[length - 1] == 6 || array[length - 1] == 8 || array[length - 1] == 0) )//if number is even or divisible by 5
          prime = 0;
    else{
      for (int u = 2; (u * u) < (number + 1); u++){//determines if number is prime
            if (( number % u) == 0){
              prime = 0;
              break;
            }//if pandig is divisible
            if (prime == 0)
              break;
        }//for u
    }//else
    return prime;
}//isPrime

int array2int(int array[], int size, int n, int length){//converts array to integer
  int total = 0;
  for (int i = 0; i < length; i++){
    total += array[i] * pow(10, (length - i - 1));
  }//for i
  return total;
}//array2int

void resetArray(int array[], int size, int n){//resets array to all zeroes
  for (int i = 0; i < size; i++){
    array[i] = 0;
  }//for i
}//resetArray

void int2array(int array[], int size, int n, int length){//converts int to an array
  for (int i = length; i > 0; i--){
        array[length - i] = n / pow(10, (i - 1));
        n = n - (array[length - i] * pow(10, i - 1));
     }//for i
     //printArray(array, length);
}//int2array

void printArray(int array[], int length){//prints array (used for debugginh purposes)
  for (int i = 0; i < length; i++){
    cout << array[i];
  }
  cout << endl;
}//printArray

