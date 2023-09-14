# DS

## Linear DS with Builtin lib

- Static array (size = stated + extra space (sentinel))

- Dynamic array (C++: vector; Java: ArrayList or Vector)
  - Typical vector operations for c++: `push_back(), at(), [] operator, assign(), clear(), erase()` and iterators for traversal

### Array of Booleans: `bitset` in C++ (operations: `set, reset, [], test`)

### Searching and Sorting (two of the most common operations on array)

#### Sorting

O(n^2): comparison-based sorting
- Bubble
- Selection
- Insertion

=> Slow, and generally avoided

O(nlog(n)): comparison-based sorting
- Merge
- Heap
- QuickSort

=> Achieve best time, can be used in C++ via `sort(), partial_sort(), stable_sort()` or in Java through `Collections.sort`

O(n): Special purposes sorting
- Radix
- Bucket
- Counting: good for ints in a small range

=> Good to know if data has certain characteristics

#### Searching

O(n): Linear searching (avoid this)

O(log(n)): Binary search, use `lower_bound, upper_bound, or binary_search` in C++ (Sort the array if array is not sorted)

O(1): Hashing

### Bitmasks

Bitmasks: lightweight, small sets of Booleans (faster than `vector<bool>, set<int>, or bitset`). Can use integers as bitmasks.

Get the bit at the least significant position (the right): `x & 1`

Get the bit at the isolated least significant 1: `x & (-x)` [Explanation: When we do `-x`, it's like doing `~x + 1`], so the isolated least significant and the lowest 1 would be the same.

Turn on all bits of size `n`: `(1 << n) - 1`

### Linked lists

Should be avoided because of inefficiency

### Stack (First In Last Out)

Used for problems like `bracket matching`, `postfix calculator`, `infix to postfix`, `finding strongest connecting components`

Ref: C++ `stack`; operators: `pop(), push(), top(), empty()`

### Queue (First In First Out)

Used for BFS (Breath-first-search)

Ref: C++ `queue`; operators: `pop(), push(), front(), back(), empty()`

### Double-ended queue (deque)

Supports O(1) insertion and deletion both in the front and back

Ref: C++ `deque`; operators: `push_back(), pop_front(), push_front(), pop_back()`

## Adhoc

Game (Card)
1. UVa 00162 - Beggar My Neighbour (card game simulation; straightforward)
2. UVa 00462 - Bridge Hand Evaluator * (simulation; card)
3. UVa 00555 - Bridge Hands (card game)
4. UVa 10205 - Stack ’em Up (card game)
5. UVa 10315 - Poker Hands (tedious problem)
6. UVa 10646 - What is the Card? * (shuffle cards with some rule and
then get certain card)
7. UVa 11225 - Tarot scores (another card game)
8. UVa 11678 - Card’s Exchange (actually just an array manipulation problem)
9. UVa 12247 - Jollo * (interesting card game; simple, but requires good
logic to get all test cases correct)

• Game (Chess)
1. UVa 00255 - Correct Move (check the validity of chess moves)
2. UVa 00278 - Chess * (ad hoc, chess, closed form formula exists)
3. UVa 00696 - How Many Knights * (ad hoc, chess)
4. UVa 10196 - Check The Check (ad hoc chess game, tedious)
5. UVa 10284 - Chessboard in FEN * (FEN = Forsyth-Edwards Notation
is a standard notation for describing board positions in a chess game)
6. UVa 10849 - Move the bishop (chess)
7. UVa 11494 - Queen (ad hoc, chess)

• Game (Others), Easier
1. UVa 00340 - Master-Mind Hints (determine strong and weak matches)
2. UVa 00489 - Hangman Judge * (just do as asked)
3. UVa 00947 - Master Mind Helper (similar to UVa 340)
4. UVa 10189 - Minesweeper * (simulate Minesweeper, similar to UVa 10279)
5. UVa 10279 - Mine Sweeper (a 2D array helps, similar to UVa 10189)
6. UVa 10409 - Die Game (just simulate the die movement)
7. UVa 10530 - Guessing Game (use a 1D flag array)
8. UVa 11459 - Snakes and Ladders * (simulate it, similar to UVa 647)
9. UVa 12239 - Bingo (try all 902 pairs, see if all numbers in [0..N] are there)

Game (Others), Harder (more tedious)
1. UVa 00114 - Simulation Wizardry (simulation of pinball machine)
2. UVa 00141 - The Spot Game (simulation, pattern check)
3. UVa 00220 - Othello (follow the game rules, a bit tedious)
4. UVa 00227 - Puzzle (parse the input, array manipulation)
5. UVa 00232 - Crossword Answers (complex array manipulation problem)
6. UVa 00339 - SameGame Simulation (follow problem description)
7. UVa 00379 - HI-Q (follow problem description)
8. UVa 00584 - Bowling * (simulation, games, reading comprehension)
9. UVa 00647 - Chutes and Ladders (childhood board game, also see UVa 11459)
10. UVa 10363 - Tic Tac Toe (check validity of Tic Tac Toe game, tricky)
11. UVa 10443 - Rock, Scissors, Paper * (2D arrays manipulation)
12. UVa 10813 - Traditional BINGO * (follow the problem description)
13. UVa 10903 - Rock-Paper-Scissors ... (count win+losses, output win average)

• Palindrome
1. UVa 00353 - Pesky Palindromes (brute force all substring)
2. UVa 00401 - Palindromes * (simple palindrome check)
3. UVa 10018 - Reverse and Add (ad hoc, math, palindrome check)
4. UVa 10945 - Mother Bear * (palindrome)
5. UVa 11221 - Magic Square Palindrome * (we deal with a matrix)
6. UVa 11309 - Counting Chaos (palindrome check)

• Anagram
1. UVa 00148 - Anagram Checker (uses backtracking)
2. UVa 00156 - Ananagram * (easier with algorithm::sort)
3. UVa 00195 - Anagram * (easier with algorithm::next permutation)
4. UVa 00454 - Anagrams * (anagram)
5. UVa 00630 - Anagrams (II) (ad hoc, string)
6. UVa 00642 - Word Amalgamation (go through the given small dictionary for
the list of possible anagrams)
7. UVa 10098 - Generating Fast, Sorted ... (very similar to UVa 195)

• Interesting Real Life Problems, Easier
1. UVa 00161 - Traffic Lights * (this is a typical situation on the road)
2. UVa 00187 - Transaction Processing (an accounting problem)
3. UVa 00362 - 18,000 Seconds Remaining (typical file download situation)
4. UVa 00637 - Booklet Printing * (application in printer driver software)
5. UVa 00857 - Quantiser (MIDI, application in computer music)
6. UVa 10082 - WERTYU (this typographical error happens to us sometimes)
7. UVa 10191 - Longest Nap (you may want to apply this to your own schedule)
8. UVa 10528 - Major Scales (music knowledge is in the problem description)
9. UVa 10554 - Calories from Fat (are you concerned with your weights?)
10. UVa 10812 - Beat the Spread * (be careful with boundary cases!)
11. UVa 11530 - SMS Typing (handphone users encounter this problem everyday)
12. UVa 11945 - Financial Management (a bit output formatting)
13. UVa 11984 - A Change in Thermal Unit (F◦ to C◦ conversion and vice versa)
14. UVa 12195 - Jingle Composing (count the number of correct measures)
15. UVa 12555 - Baby Me (one of the first question asked when a new baby is
born; requires a bit of input processing)

Interesting Real Life Problems, Harder (more tedious)
1. UVa 00139 - Telephone Tangles (calculate phone bill; string manipulation)
2. UVa 00145 - Gondwanaland Telecom (similar nature with UVa 139)
3. UVa 00333 - Recognizing Good ISBNs (note: this problem has ‘buggy’ test
data with blank lines that potentially cause lots of ‘Presentation Errors’)
4. UVa 00346 - Getting Chorded (musical chord, major/minor)
5. UVa 00403 - Postscript * (emulation of printer driver, tedious)
6. UVa 00447 - Population Explosion (life simulation model)
7. UVa 00448 - OOPS (tedious ‘hexadecimal’ to ‘assembly language’ conversion)
8. UVa 00449 - Majoring in Scales (easier if you have a musical background)
9. UVa 00457 - Linear Cellular Automata (simplified ‘game of life’ simulation;
similar idea with UVa 447; explore the Internet for that term)
10. UVa 00538 - Balancing Bank Accounts (the problem’s premise is quite true)
11. UVa 00608 - Counterfeit Dollar * (classical problem)
12. UVa 00706 - LC-Display (what we see in old digital display)
13. UVa 01061 - Consanguine Calculations * (LA 3736 - WorldFinals Tokyo07,
consanguine = blood; this problem asks possible combinations of blood types
and Rh factor; solvable by trying all eight possible blood + Rh types with
the information given in the problem description)
14. UVa 10415 - Eb Alto Saxophone Player (about musical instruments)
15. UVa 10659 - Fitting Text into Slides (typical presentation programs do this)
16. UVa 11223 - O: dah, dah, dah (tedious morse code conversion)
17. UVa 11743 - Credit Check (Luhn’s algorithm to check credit card numbers;
search the Internet to learn more)
18. UVa 12342 - Tax Calculator (tax computation can be tricky indeed)

• Time
1. UVa 00170 - Clock Patience (simulation, time)
2. UVa 00300 - Maya Calendar (ad hoc, time)
3. UVa 00579 - Clock Hands * (ad hoc, time)
4. UVa 00893 - Y3K * (use Java GregorianCalendar; similar to UVa 11356)
5. UVa 10070 - Leap Year or Not Leap ... (more than ordinary leap years)
6. UVa 10339 - Watching Watches (find the formula)
7. UVa 10371 - Time Zones (follow the problem description)
8. UVa 10683 - The decadary watch (simple clock system conversion)
9. UVa 11219 - How old are you? (be careful with boundary cases!)
10. UVa 11356 - Dates (very easy if you use Java GregorianCalendar)
11. UVa 11650 - Mirror Clock (some mathematics required)
12. UVa 11677 - Alarm Clock (similar idea with UVa 11650)
13. UVa 11947 - Cancer or Scorpio * (easier with Java GregorianCalendar)
14. UVa 11958 - Coming Home (be careful with ‘past midnight’)
15. UVa 12019 - Doom’s Day Algorithm (Gregorian Calendar; get DAY OF WEEK)
16. UVa 12136 - Schedule of a Married Man (LA 4202, Dhaka08, check time)
17. UVa 12148 - Electricity (easy with Gregorian Calendar; use method ‘add’ to
add one day to previous date and see if it is the same as the current date)
18. UVa 12439 - February 29 (inclusion-exclusion; lots of corner cases; be careful)
19. UVa 12531 - Hours and Minutes (angles between two clock hands)

‘Time Waster’ Problems
1. UVa 00144 - Student Grants (simulation)
2. UVa 00214 - Code Generation (just simulate the process; be careful with
subtract (-), divide (/), and negate (@), tedious)
3. UVa 00335 - Processing MX Records (simulation)
4. UVa 00337 - Interpreting Control ... (simulation, output related)
5. UVa 00349 - Transferable Voting (II) (simulation)
6. UVa 00381 - Making the Grade (simulation)
7. UVa 00405 - Message Routing (simulation)
8. UVa 00556 - Amazing * (simulation)
9. UVa 00603 - Parking Lot (simulate the required process)
10. UVa 00830 - Shark (very hard to get AC, one minor error = WA)
11. UVa 00945 - Loading a Cargo Ship (simulate the given cargo loading process)
12. UVa 10033 - Interpreter (adhoc, simulation)
13. UVa 10134 - AutoFish (must be very careful with details)
14. UVa 10142 - Australian Voting (simulation)
15. UVa 10188 - Automated Judge Script (simulation)
16. UVa 10267 - Graphical Editor (simulation)
17. UVa 10961 - Chasing After Don Giovanni (tedious simulation)
18. UVa 11140 - Little Ali’s Little Brother (ad hoc)
19. UVa 11717 - Energy Saving Micro... (tricky simulation)
20. UVa 12060 - All Integer Average * (LA 3012, Dhaka04, output format)
21. UVa 12085 - Mobile Casanova * (LA 2189, Dhaka06, watch out for PE)
22. UVa 12608 - Garbage Collection (simulation with several corner cases)


BST (C++ map/set; Java TreeMap/TreeSet):
- O(log n): search, insert, findMin, findMax, successor, predecessor, delete

Heap (C++ priority_queue; Java PriorityQueue):
- O(log n): ExtractMax, Insert
