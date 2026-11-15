#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
void instructions();
string caepher(string, int);
string reversetext(string);
string binary_convert(char);
string to_lower(string);
bool level1();
bool level2();
bool level3();
int counter = 0, points = 0, attempts = 10;

int main()
{
    instructions();
    srand(time(0));
    cout << "       LAB-08: CRYPTO CHALLENGE GAME        \n\n";
    cout << "You have total " << attempts << " attempts. Guess wisely\n\n";
    if (level1())
    {
        if (level2())
        {
            level3();
        }
    }

    /*    This can also be done like this
          if (level1()&&level2())
                 {
                    level3();
                 }

    */

    if (points < 0) // In case user has negative points we give them zero
    {
        points = 0;
    }

    if (attempts == 0)
    {
        cout << "You ran out of attempts\n";
    }

    cout << "Total levels passed: " << counter << endl;
    cout << "Total points earned: " << points << endl;
    if (points >= 0 && points < 20)
    {
        cout << "You are a noob\n";
    }
    else if (points >= 20 && points <= 40)
    {
        cout << "You are an average player\n";
    }
    else if (points > 40 && points <= 60)
    {
        cout << "You are a pro player\n";
    }
    else if (points > 60 && counter >= 3)
    {
        cout << "You are a heroic player\n";
    }

    return 0;
}

void instructions()
{
    cout << "Level 1: Decode a word that was shifted 3 letters forward\n";
    cout << "Level 2: Un-reverse the given word\n";
    cout << "Level 3: Convert the 8-bit binary code back to its capital letter\n";
    cout << "You get total 10 attempts\n";
    cout << "20 points for passing level 1, 30 for level 2 and 40 for level 3\n";
    cout << "If you fail level 1: 5 points deducted, 10 for level 2 and 15 for level 3\n";
    cout << "Every wrong answer costs you one attempt\n";
    cout << "Ranks are: noob, average, pro and heroic based on points obtained\n\n";
}
string to_lower(string text)
{
    string result = text;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            result[i] = text[i] + 32;
        }
    }
    return result;
}
string caepher(string text, int shift)
{
    string result = text;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            result[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
    }
    return result;
}
string reversetext(string text)
{
    string result = ""; // Length of result and text is same so we can also use result = text
    for (int i = text.length() - 1; i >= 0; i--)
    {
        result += text[i];
    }
    return result;
}
string binary_convert(char ch)
{
    string result = "";
    int value = ch;
    for (int i = 0; i < 8; i++)
    {
        if (value % 2 == 0)
        {
            result += "0";
        }
        else
        {
            result += "1";
        }
        value = value / 2;
    }
    return reversetext(result); // Because value is written backward for result and we reverse it
}
bool level1()
{
    cout << "          Level-1: Caesar Cipher            \n\n";
    string words[5] = { "cat", "dog", "tiger", "lion", "snake" };
    string word = words[rand() % 5];
    string coded = caepher(word, 3);          // the program encrypts the word
    while (attempts > 0)
    {
        string text;
        cout << "Decode this shifted word (" << coded << ") and enter the original word: ";
        cin >> text;
        if (to_lower(text) == word)
        {
            cout << "Congrats! You have passed the level 1\n";
            points += 20;
            counter++;
            return true;
        }
        else
        {
            cout << "Incorrect! Try again\n";
            attempts--;
            points -= 5;
            cout << "You have only " << attempts << " attempts left. Guess wisely \n";
        }
    }
    return false;
}
bool level2()
{
    cout << "          Level-2: Reverse Text            \n\n";
    string words[5] = { "Computer", "Icecream", "Tablet", "Mobile", "Nust" };
    string word = words[rand() % 5];
    string coded = reversetext(word);         // the program reverses the word
    string text;
    while (attempts > 0)
    {
        cout << "Unreverse this word (" << coded << ") and enter the original word: ";
        cin >> text;

        if (to_lower(text) == to_lower(word))
        {
            cout << "Congrats! You passed level 2\n";
            points += 30;
            counter++;
            return true;
        }
        else
        {
            cout << "Incorrect! Please try again\n";
            attempts--;
            points -= 10;
            cout << "You have only " << attempts << " attempts left. Guess wisely" << endl;
        }
    }
    return false;
}
bool level3()
{
    cout << "          Level-3: Binary Conversion       \n\n";
    char letter = 'A' + rand() % 26;
    string coded = binary_convert(letter);    // the program converts the letter to binary
    char text;
    while (attempts > 0)
    {
        cout << "Enter the capital letter for this 8-bit binary code (" << coded << "): ";
        cin >> text;
        if (text == letter)
        {
            cout << "Congrats! You have passed the level 3\n";
            counter++;
            points += 40;
            return true;
        }
        else
        {
            cout << "Invalid guess! Please try again\n";
            attempts--;
            points -= 15;
            cout << "You only have " << attempts << " attempts left. Guess wisely" << endl;
        }
    }
    return false;
}
