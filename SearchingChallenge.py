"""
Searching Challenge

Have the function SearchingChallenge(str) take the str parameter being passed and find the longest substring that contains k unique characters,
where k will be the first character from the string. The substring will start from the second position in the string because the first character
will be the integer k. For example: if str is "2aabbacbaa" there are several substrings that all contain 2 unique characters,
namely: ["aabba", "ac", "cb", "ba"], but your program should return "aabba" because it is the longest substring. If there are 
multiple longest substrings, then return the first substring encountered with the longest length. k will range from 1 to 6.
Once your function is working, take the final output string and combine it with your ChallengeToken, both in reverse order and separated by a colon.

Examples

Input: "3aabacbebebe"
Output: cbebebe
Final Output: ebebebc

Input: "2aabbcbbbadef"
Output: bbcbbb
Final Output: bbbcbb

"""

def SearchingChallenge(strParam):
  num = int(strParam[0])
  count = 1
  word = strParam[1:]

  sublist = []
  diff_char = []
  diff_char.append(word[0])
  s = ""
  s += word[0]
  i = 1
  while i < len(word):  
    if (word[i] not in diff_char) and count < num:      
      diff_char.append(word[i]) 
      s += word[i]     
      count += 1
      if num == count:
        son_farklı_index = i  
    elif (word[i] in diff_char) and count <= num:
      s += word[i]  
      if i == len(word)-1:
        sublist.append(s)
    else:
      sublist.append(s)
      s = word[son_farklı_index]
      diff_char = []
      diff_char.append(word[son_farklı_index]) 
      count = 1
      i = son_farklı_index
    i += 1
  
  length = 1
  for k in sublist:
    if len(k) >= length:
      length = len(k)
      strParam = k[::-1]

  return strParam

# keep this function call here 
print(SearchingChallenge(input()))