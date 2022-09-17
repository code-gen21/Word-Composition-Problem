# Word Composition Problem
### Steps of execution of my code
- I have made a class "Solution" which contains all the functions required by the programm. 
- Then i write the code to open the file which contains the input.
- Now we store that input in a vector "ans".
- Then i made a function "longestWord" which prints the longest compounded as well as the second longest compounded word.

### Overview and Approach of my program
- Used Trie data structure its a special tree that stores strings. Trie supports search, insert and delete operations in O(k) time where k is length of key/word which is faster than hashing.
- #### First we called longestWord function through the Solution class.Now, we are inserting all the words in a trie and then sort the vector so that we have the longest words at the starting and the smallest words at the end of the vector which will eventually help in finding our answer. In the longestWord function we made two strings which store the longest compounded word and second longest compounded word.
- Now we iterate in our vector which stores all the input string so that we can access all the words. And then in loop we called a function "st" which mark the flag as false of the current word.
- After that we called a function "search", which will search whether the given word can be formed by using two or more words from all the given words.
- If the function "search" return true then that word would be a possible answer.
- At last we call function "insert" to mark the flag of the given word as true. 
- Then we print both the strings.

![](https://img.shields.io/badge/Word%20Composition-Problem-red)