CRYPTO CHALLENGE GAME
CS110: Fundamentals of Computer Programming
Lab 08: Open Ended Lab | Class BESE-17A | Fall 2026
Instructor: Dr. Momina Moetesum | Lab Engineer: Ms. Sundas Dawood

GROUP MEMBERS:
-------------
Muhammad Nouman Khan – 589719
Manal Mahfooz Raja – 593630
Raheel Khan – 585476

GITHUB REPOSITORY:
-----------------
https://github.com/MNouman69/Encryption-Decryption-Game


1. GAME CONCEPT:
===============

A text-based game where the player acts as a codebreaker. Each of the three
levels shows a coded message, and the player must decode it to move forward.
The game uses three techniques: Caesar cipher, text reversal, and binary
(ASCII) encoding.

The program does the encoding itself and shows only the coded version. The
player never sees the original word. If the player is stuck, they can type
"hint" at any prompt to get help, at a cost in points (see section 4).


2. HOW TO PLAY:
==============

Requirements:
------------
Any C++ compiler (Visual Studio).
g++ OPEN-ENDED-LAB-08.cpp -o game
./game

Steps:
-----
1. Read the instructions shown at the start of the game.
2. Each level shows a coded message in brackets.
3. Decode it and type your answer after the prompt, then press Enter.
4. Type one answer per prompt, without spaces.
5. If you are stuck, type hint instead of an answer. You get at most 2 hints
   per level. Hints cost points but do not use attempts.
6. A correct answer passes the level and opens the next one.
7. A wrong answer costs points and one attempt, so guess wisely.
8. At the end the game shows the levels passed, total points and your rank.

Sample run (all levels passed, no hints used):
---------------------------------------------
Level 1: Decode a word that was shifted 3 letters forward
Level 2: Un-reverse the given word
Level 3: Convert the 8-bit binary code back to its capital letter
You can use hints but maximum 2 hints for one level and first hint cost 5 points penalty and second 10 points penalty
Hints do not use attempts
You get total 10 attempts
20 points for passing level 1, 30 for level 2 and 40 for level 3
If you fail level 1: 5 points deducted, 10 for level 2 and 15 for level 3
Every wrong answer costs you one attempt
Ranks are: noob, average, pro and heroic based on points obtained

       LAB-08: CRYPTO CHALLENGE GAME

You have total 10 attempts. Guess wisely

          Level-1: Caesar Cipher

Decode this shifted word (grj) and enter the original word (or type hint): dog
Congrats! You have passed the level 1
          Level-2: Reverse Text

Unreverse this word (maercecI) and enter the original word (or type hint): Icecream
Congrats! You passed level 2
          Level-3: Binary Conversion

Enter the capital letter for this 8-bit binary code (01011010) (or type hint): Z
Congrats! You have passed the level 3
Total levels passed: 3
Total points earned: 90
You are a heroic player

Sample run (using hints in Level 1):
-----------------------------------
Decode this shifted word (vqdnh) and enter the original word (or type hint): hint
Hint 1: Move every letter 3 places back (like d becomes a) ( -5 Points for using first hint )
Decode this shifted word (vqdnh) and enter the original word (or type hint): hint
Hint 2: First letter of the word is: s (-10 Points for using second hint )
Decode this shifted word (vqdnh) and enter the original word (or type hint): hint
No hints left for this level!
Decode this shifted word (vqdnh) and enter the original word (or type hint): snake
Congrats! You have passed the level 1

(The words and the letter are chosen randomly, so they change every game.)


3. LEVELS:
=========

Level 1 – Caesar cipher (shift 3):
---------------------------------
The player decodes a word that was shifted 3 letters forward, e.g. fdw
becomes cat.
Hint 1: move every letter 3 places back.
Hint 2: the first letter of the word.

Level 2 – Text reversal:
-----------------------
The player un-reverses a word, e.g. tsuN becomes Nust.
Hint 1: the first letter of the word.
Hint 2: the letter at the second position.

Level 3 – Binary / ASCII:
------------------------
The player converts an 8-bit code back to its capital letter, e.g. 01000001
becomes A.
Hint 1: how to convert (multiply each digit by powers of 2, increasing from
        right to left).
Hint 2: the ASCII value of the letter.


4. POINTS, PENALTIES AND ATTEMPTS:
=================================

Points division:
---------------
Passing a level earns points:
Level 1 = 20
Level 2 = 30
Level 3 = 40
The maximum is 90 (all levels passed with no wrong answers and no hints).

Reason: Harder levels are worth more, and Level 3 gives the largest reward.

Penalties for wrong answers:
---------------------------
Every wrong answer costs points:
Level 1:   -5
Level 2:  -10
Level 3:  -15

Reason: The penalty grows with difficulty, so careless guessing in later
levels hurts more.

Penalties for hints:
-------------------
Each level allows a maximum of 2 hints:
First hint:   -5 points
Second hint: -10 points
A third request in the same level shows "No hints left for this level!" and
costs nothing. Hints are counted separately for each level, so every level
has its own 2 hints.
Hints do not use attempts, but they lower the score. Using both hints in all
three levels costs 45 points in total.

Attempts:
--------
The player has 10 attempts in total, shared by all levels. Each wrong answer
uses one attempt, so mistakes in an early level leave fewer chances for the
later ones. Typing "hint" never uses an attempt. If the attempts reach 0, the
game prints "You ran out of attempts" and moves to the final result.

Negative points:
---------------
Wrong answers and hints can push the score below zero during play. At the
end, any negative total is reset to 0, because a negative score makes no
sense for a player and would break the rank ranges.


5. LEVEL UNLOCKING (WHAT IF LEVEL 1 FAILS?):
===========================================

Levels are nested: Level 2 opens only after Level 1 is passed, and Level 3
only after Level 2. A level fails only when the attempts run out, so if
Level 1 fails, the game ends and Levels 2 and 3 never start.


6. RANKS:
========

Ranks are based on the final points:

0 to 19:      Noob
20 to 40:     Average
41 to 60:     Pro
61 or more:   Heroic (only if all 3 levels are passed)

The maximum after two levels is 50, so Heroic is only reachable by passing
all three. Because hints and wrong answers reduce the score, a player who
passes all three levels can still end up as Pro or lower
(for example, passing all three levels with both hints used in every level
gives 90 - 45 = 45 points, which is Pro).


7. INPUT HANDLING:
=================

Answers in Levels 1 and 2 are not case-sensitive, so CAT, Cat and cat all
work. The word "hint" is also not case-sensitive (HINT and Hint work).
Level 3 asks for the capital letter and checks it exactly: the answer must be
a single character, and a lowercase letter is treated as a wrong answer
("Invalid guess!") and uses one attempt.


8. DESIGN DECISIONS:
===================

- Program encrypts, player decrypts: the same cipher functions create the
  puzzle, so the game never relies on hardcoded coded words.
- Global variables: counter, points and attempts are shared by all levels,
  which is what makes the attempts and score system work.
- Levels return true or false: main uses the result to decide whether the
  next level opens.
- Random words: each level picks its word or letter randomly, so every game
  is different.
- Hint system: one shared hint() function handles the penalty and the hint
  limit for all levels. Each level keeps its own hints_used counter and
  passes its own hint texts to the function, so the limit is 2 hints per
  level. The loop uses "continue" after a hint so the player is asked for an
  answer again without losing an attempt.


9. PROGRAMMING CONCEPTS USED:
============================

- Functions with return values and prototypes
- Pass by reference (hint() changes hints_used of the calling level)
- Global variables
- Arrays
- for and while loops, continue statement
- Nested if/else
- rand() and srand() for random words
- String and char handling
- ASCII arithmetic

Helper functions:
----------------
caepher()         Shifts letters forward (Caesar cipher, Level 1)
reversetext()     Reverses a string (Level 2, also used by binary_convert)
binary_convert()  Converts a character to 8-bit binary (Level 3)
to_lower()        Converts text to lowercase for case-insensitive checking
                  (answers and the word "hint")
hint()            Shows hint 1 or hint 2, applies the point penalty, and
                  blocks a third hint in the same level
instructions()    Prints the rules before the game starts


10. TEST RESULTS:
================

The game was compiled and run for each of these scenarios.

1. All three levels answered correctly, no hints
   Expected: 3 levels, 90 points, Heroic
   Actual:   Matches

2. Level 1 fails (10 wrong answers)
   Expected: "You ran out of attempts", no Level 2, points reset to 0, Noob
   Actual:   Matches

3. Level 1 passed, Level 2 fails
   Expected: Level 3 never starts, 1 level passed, points reset to 0, Noob
   Actual:   Matches

4. One wrong answer in Level 1, then all correct
   Expected: 20 - 5 + 30 + 40 = 85 points, Heroic
   Actual:   Matches

5. Answers typed in CAPITAL letters (Levels 1 and 2)
   Expected: Accepted as correct
   Actual:   Matches

6. Both hints used in every level, then correct answers
   Expected: 90 - 15 - 15 - 15 = 45 points, 3 levels, Pro
   Actual:   Matches

7. Three hints requested in Level 1, then correct answers
   Expected: Third request shows "No hints left for this level!" with no
             penalty; 90 - 15 = 75 points, Heroic
   Actual:   Matches

8. Lowercase letter entered in Level 3, then the correct capital letter
   Expected: "Invalid guess!", 1 attempt used (9 left), -15 points;
             90 - 15 = 75 points, Heroic
   Actual:   Matches

9. One hint used in Level 1, then all correct
   Expected: 20 - 5 + 30 + 40 = 85 points, Heroic (hint uses no attempt)
   Actual:   Matches


11. GROUP CONTRIBUTIONS:
=======================

Muhammad Nouman Khan (589719)
- Level 1 (Caesar cipher): level1(); cipher function caepher()
- Helper function to_lower()
- Hint function hint()
- main()
- Points and ranks

Manal Mahfooz Raja (593630)
- Level 2 (Reverse text): level2(); reversetext() 
- instructions()
- Output obtained (output testing and screenshots)
- Word report document

Raheel Khan (585476)
- Level 3 (Binary): level3(); binary_convert()
- Read me report


