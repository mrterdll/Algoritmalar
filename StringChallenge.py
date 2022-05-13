"""
String Challenge

Have the function StringChallenge(str) take the str parameter being passed and determine 
if a palindrome can be created by swapping two adjacent characters in the string.
If it is possible to create a palindrome, then your program should return the palindrome, 
if not then return the string -1. The input string will only contain alphabetic characters. 
For example: if str is "rcaecar" then you can create a palindrome by swapping the second and 
third characters, so your program should return the string racecar which is the final palindromic string.

Examples
Input: "anna"
Output: anna

Input: "kyaak"
Output: kayak

"""
def StringChallenge(strParam):
  i = 0
  j = len(strParam) -1

  while i < (len(strParam)/2):
    if strParam[i] != strParam[j]:
      if strParam[i+1] != strParam[j]:
        return -1
      else:
        strParam_list = list(strParam)
        strParam_list[i] = strParam[i+1]
        strParam_list[i+1] = strParam[i]
        strParam = "".join(strParam_list)
    i += 1
    j -= 1

  return strParam

# keep this function call here 
print(StringChallenge(input()))