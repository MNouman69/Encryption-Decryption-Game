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
player never sees the original word.


2. HOW TO PLAY:
==============

Requirements:
------------
Any C++ compiler (Visual Studio).


Steps:
-----
1. Read the instructions shown at the start of the game.
2. Each level shows a coded message in brackets.
3. Decode it and type your answer after the prompt, then press Enter.
4. Type one answer per prompt, without spaces.
5. A correct answer passes the level and opens the next one.
6. A wrong answer costs points and one attempt, so guess wisely.
7. At the end the game shows the levels passed, total points and your rank.

Sample run (all levels passed):
------------------------------
Decode this shifted word (fdw) and enter the original word: cat
Congrats! You have passed the level 1
Unreverse this word (tsuN) and enter the original word: Nust
Congrats! You passed level 2
Enter the capital letter for this 8-bit binary code (01000001): A
Congrats! You have passed the level 3
Total levels passed: 3
Total points earned: 90
You are a heroic player

(The words and the letter are chosen randomly, so they change every game.)


3. LEVELS:
=========

Level 1 – Caesar cipher (shift 3):
---------------------------------
The player decodes a word that was shifted 3 letters forward, e.g. fdw
becomes cat.

Level 2 – Text reversal:
-----------------------
The player un-reverses a word, e.g. tsuN becomes Nust.

Level 3 – Binary / ASCII:
------------------------
The player converts an 8-bit code back to its capital letter, e.g. 01000001
becomes A.


4. POINTS, PENALTIES AND ATTEMPTS:
=================================

Points division:
---------------
Passing a level earns points:
Level 1 = 20
Level 2 = 30
Level 3 = 40
The maximum is 90.

Reason: Harder levels are worth more, and Level 3 gives the largest reward.

Penalties:
---------
Every wrong answer costs points:
Level 1:   -5
Level 2:  -10
Level 3:  -15

Reason: The penalty grows with difficulty, so careless guessing in later
levels hurts more.

Attempts:
--------
The player has 10 attempts in total, shared by all levels. Each wrong answer
uses one attempt, so mistakes in an early level leave fewer chances for the
later ones.

Negative points:
---------------
Wrong answers can push the score below zero during play. At the end, any
negative total is reset to 0, because a negative score makes no sense for a
player and would break the rank ranges.


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
61 or more:   Heroic

The maximum after two levels is 50, so Heroic is only reachable by passing
all three.


7. INPUT HANDLING:
=================

Answers in Levels 1 and 2 are not case-sensitive, so CAT, Cat and cat all
work. Level 3 asks for the capital letter and checks it exactly.


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


9. PROGRAMMING CONCEPTS USED:
============================

- Functions with return values and prototypes
- Global variables
- Arrays
- for and while loops
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


10. TEST RESULTS:
================

The game was compiled and run for each of these scenarios.

1. All three levels answered correctly
   Expected: 3 levels, 90 points, Heroic
   Actual:   Matches

2. Level 1 fails (10 wrong answers)
   Expected: Game ends, no Level 2, points reset to 0, Noob
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


11. GROUP CONTRIBUTIONS:
=======================

Muhammad Nouman Khan (589719)
- Level 1 (Caesar cipher): level1(); cipher function caepher()
- Helper function to_lower()
- main()
- Points and ranks

Manal Mahfooz Raja (593630)
- Level 2 (Reverse text): level2(); reversetext()
- instructions() 
- Word report document

Raheel Khan (585476)
- Level 3 (Binary): level3(); binary_convert()
- Output obtained (output testing and screenshots)
- Read me report
