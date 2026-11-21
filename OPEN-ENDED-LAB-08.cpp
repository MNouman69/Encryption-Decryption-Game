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
void hint(int&, string, string);
bool level1();
bool level2();
bool level3();
int counter = 0, points = 0, attempts = 10;

int main()
{
    instructions();   // Shows the game rules to the player
    srand(time(0));  // For generating random words every time
    cout << "       LAB-08: CRYPTO CHALLENGE GAME        \n\n";
    cout << "You have total " << attempts << " attempts. Guess wisely\n\n";
    if (level1())     //  Play level 1, continue only if the player passes (returns true)
    {
        if (level2())   // Only run if level 1 is passed (true) else it is locked
        {
            level3();   // Only run if level 1 and 2 both are true else it is locked
        }
    }

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
    cout << "You can use hints but maximum 2 hints for one level and first hint cost 5 points penalty and second 10 points penalty\n";
    cout << "Hints do not use attempts\n";
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
            result[i] = text[i] + 32;   // Every uppercase letter is 32 behind lowercase so adding 32 converts upper to lowercase
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
    int value = ch;    //  Cpp will convert character like 'A' to 65 because we used int and will store it in value
    for (int i = 0; i < 8; i++)
    {
        if (value % 2 == 0)    // If value is divisible by 2 then remainder is 0
        {
            result += "0";
        }
        else
        {
            result += "1";   
        }
        value = value / 2;   // Move to the next bit (the current bit is already saved in result)
    }
    return reversetext(result); // Because value is written backward for result and we reverse it
}
void hint(int& hints_used, string hint_1, string hint_2)
{
    if (hints_used == 0)
    {
        cout << "\nHint 1: " << hint_1 << " ( -5 Points for using first hint )\n\n";
        points = points - 5;
        hints_used++;
    }
    else if (hints_used == 1)
    {
        cout << "\nHint 2: " << hint_2 << " (-10 Points for using second hint )\n\n";
        points -= 10;
        hints_used++;
    }
    else
    {
        cout << "\nNo hints left for this level!\n";
    }
   
}
bool level1()
{
    cout << "\n          Level-1: Caesar Cipher            \n\n";
    string words[5] = { "cat", "dog", "tiger", "lion", "snake" };
    string word = words[rand() % 5];
    string coded = caepher(word, 3);          // the program encrypts the word
    int hints_used = 0;
    while (attempts > 0)
    {
        string text;
        cout << "Decode this shifted word (" << coded << ") and enter the original word (or type hint): ";
        cin >> text;
        if (to_lower(text) == "hint")
        {
            string hint_1 = "Move every letter 3 places back (like d becomes a)";
            string hint_2 = string("First letter of the word is: ") + word[0];  // We used string because character with quoted text will give garbage value without string
            hint(hints_used, hint_1, hint_2);
            continue;      // Jump back to top to start of loop to take input again after giving hint
        }
        if (to_lower(text) == word)
        {
            cout << "Congrats! You have passed the level 1\n";
            points += 20;
            counter++;
            return true;
        }
        else
        {
            cout << "\nIncorrect! Try again\n";
            attempts--;
            points -= 5;
            cout << "You have only " << attempts << " attempts left. Guess wisely \n\n";
        }
    }
    return false;  // No attempts left so user will not be able to play level 2 and game ends with just level 1
}
bool level2()
{
    cout << "          Level-2: Reverse Text            \n\n";
    string words[5] = { "Computer", "Icecream", "Tablet", "Mobile", "Nust" };
    string word = words[rand() % 5];
    string coded = reversetext(word);         // the program reverses the word
    string text;
    int hints_used = 0;
    while (attempts > 0)
    {
        cout << "Unreverse this word (" << coded << ") and enter the original word (or type hint): ";
        cin >> text;

        if (to_lower(text) == "hint")
        {
            string hint_1 = "The first letter of word is: " + string(1,word[0]);   // This will make a string with 1 copy of character because cpp dont simple allow to add string with word[0]
            string hint_2 = string("The letter at second position is: ") + word[1]; // We can also write like this
            hint(hints_used, hint_1, hint_2);
            continue;
        }

        if (to_lower(text) == to_lower(word))
        {
            cout << "Congrats! You passed level 2\n";
            points += 30;
            counter++;
            return true;
        }
        else
        {
            cout << "\nIncorrect! Please try again\n";
            attempts--;
            points -= 10;
            cout << "You have only " << attempts << " attempts left. Guess wisely\n" << endl;
        }
    }
    return false; // No attempts left so user will not be able to play level 3 and game ends with just level 2
}
bool level3()
{
    cout << "          Level-3: Binary Conversion       \n\n";
    char letter = 'A' + rand() % 26;  //  rand % 26 gives a random number between 0 and 25 and adding it to 65 gives any capital letter between A-Z
    string coded = binary_convert(letter);    // the program converts the letter to binary by calling our own function
    string text;
    int hints_used = 0;
    while (attempts > 0)
    {
        cout << "Enter the capital letter for this 8-bit binary code (" << coded << ") (or type hint): ";
        cin >> text;

        if (to_lower(text) == "hint")
        {
            string hint_1 = "Multiply with 2 power increasing from right to left with digits";
            string hint_2 = "The ASCII value is: " + to_string(int(letter));        // int letter convert letter like 'C' to 67 and to_string convert it to "67" to be used with string catenation concept 
            hint(hints_used, hint_1, hint_2);
            continue;
        }
        if (text.length() == 1 && text[0] == letter)   // Making sure user dont typed hint and tried to guess actual letter instead because we are limiting this condition to only one letter
        {
            cout << "Congrats! You have passed the level 3\n";
            counter++;
            points += 40;
            return true;
        }
        else
        {
            cout << "\nInvalid guess! Please try again\n";
            attempts--;
            points -= 15;
            cout << "You only have " << attempts << " attempts left. Guess wisely\n" << endl;
        }
    }
    return false;   //  No attempts left so the game ends at level 3
}
