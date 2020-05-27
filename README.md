# SimpleXPalindrome

C++ Palindrome Created With Visual Studio

## main()
main() handles the input, length of the c-style string, and calls the **getReversedCString()** function

## getReversedCString()
This function gets the array passed through the parameter and creates a new second array, but reverses the array passed through parameter
and puts it inside the second array created within the function. Then all the characters inside both arrays will be changed to lowercase to
ensure that the Palindrome check is correctly validated. Before calling the Palindrome function, this function will remove any '\0' so that
when we pass the second array through the Palindrome function, the '\0' doesn't end up on the start. Once everything is done, this function
will call the **Palindromes()** function, to check if its a Palindrome or not, which will return True or False

## Palindromes()
This function will get the two arrays passed through the parameter, and check each element inside the array. If all checks passed and
the amount of success {counter} is equal to the size of the array, the function will return True otherwise it will return False

## getStringLength()
This function will return the length of the array passed through the function




