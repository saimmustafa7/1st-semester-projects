#include <iostream>
#include <windows.h>
#include <cmath>
#include <conio.h>
#include <limits>
#include <climits>
using namespace std;

void header(int width, int height, string headingcolor);
int menuLineMovement(int nwidth, int &nHeight);
void menu(int width, int height, int currentwidth, int currentheight, string headingcolor, string optioncolor, string inputcolor);

// ======= Base conversion function =======
int base_conversion_function(int width, int height, string optioncolor, string inputcolor, string headingcolor);
long long convertingToDecimal(string takenNumber, int base, int width, int height, int nHeight);
string convertingToOtherBase(long long decimalNumber, int outputbase, int width, int height, int &nHeight);

// === encryption functions ===
int encryption_function(int width, int height, string optioncolor, string inputcolor);
string encrypt(string message, int base);
string toBase(int num, int base);
string mapDigits(string s);

// ------------- decrypting message
int decryption_function(int width, int height, string optioncolor, string inputcolor);
string decrypt(string cipher, int base);
int fromBase(string s, int base);
string unmapDigits(string s);

// === Default functions ======
void setColor(string hexcolor);
void gotoxy(int x, int y);
void getconsolemeasures(int &width, int &height);
void getCursorPosition(int &currentWidth, int &currentHeight);
int takingIntegerInput(int min, int max, int currentWidth, int currentHeight, string inputcolor, string optioncolor);
int integerVerification(string input);
string emptyverification(int w, int h, string inputcolor, string optioncolor);
string trimSpaces(string str);
void removeMenuOptions(int h);
bool checkPipe(const string &input);
void hideCursor();
void showCursor();
void setCursorSize(int size);

// ----------------- global variables ---------------------
string baseDigits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
string secretMap = "!$()_+ASDFQWERGHJKLTY%^UIOPZMXCVBNmjun&*hybgtvfr@#cdexswzaqlo";

int main()
{
    // variables
    int width, height, currentWidth, currentHeight;
    string optioncolor = "0B", headingcolor = "0C", headingBarColor = "B5", venuecolor = "02", inputcolor = "0E";
    // initial setting
    getconsolemeasures(width, height);
    hideCursor();
    // printing header
    header(width, height, headingcolor);
    // welcome message
    Sleep(500);
    for (int i = 0; i < 6; i++)
    {
        gotoxy(width / 2 - 20, height / 2);
        cout << "Welcome to Base conversion application";
        Sleep(500);
        gotoxy(width / 2 - 20, height / 2);
        for (int j = 0; j < 39; j++)
            cout << " ";
        Sleep(10);
    }
    menu(width, height, currentWidth, currentHeight, headingcolor, "0B", "0E");

    showCursor();
    return 0;
}

// ----------------- Header -----------------------------
void header(int width, int height, string headingcolor)
{
    system("cls");
    setColor(headingcolor);
    for (int i = 0; i < width; i++)
    {
        cout << "/";
    }
    gotoxy(width / 2 - 26, 0);
    cout << "(~~~~~~~~~~~~~~  Base Conversion  ~~~~~~~~~~~~~~~)" << endl;
    for (int i = 0; i < width - 1; i++)
    {
        gotoxy(i, height - 1);
        cout << "_";
    }
    for (int i = 0; i < height; i++)
    {
        gotoxy(0, i);
        cout << "|";
        gotoxy(width - 1, i);
        cout << "|";
    }
}

// ------------------- Main menu ----------------------------
void menu(int width, int height, int currentwidth, int currentheight, string headingcolor, string optioncolor, string inputcolor)
{
    bool invalidInputError = false;
    while (true)
    {
        int nHeight = 1, nWidth = 1, action;
        setColor(optioncolor);
        menuLineMovement(nWidth, nHeight);
        cout << "1. press 1 for Base conversion" << endl;
        menuLineMovement(nWidth, nHeight);
        cout << "2. Press 2 To encrypt message" << endl;
        menuLineMovement(nWidth, nHeight);
        cout << "3. Press 3 To decrypt message" << endl;
        menuLineMovement(nWidth, nHeight);
        cout << "4. Press 4 to exit" << endl;
        menuLineMovement(nWidth, nHeight);
        cout << "Select your option... ";
        // taking input
        action = takingIntegerInput(1, 4, currentwidth, currentheight, inputcolor, optioncolor);
        removeMenuOptions(nHeight);
        // matching input
        if (action == 1)
        {
            base_conversion_function(width, height, optioncolor, inputcolor, headingcolor);
        }
        else if (action == 2)
        {
            encryption_function(width, height, optioncolor, inputcolor);
        }
        else if (action == 3)
        {
            decryption_function(width, height, optioncolor, inputcolor);
        }
        else
        {
            setColor("07");
            system("cls");
            exit(0);
        }
    }
}

// ================================================ Base conversion function =============================================================
int base_conversion_function(int width, int height, string optioncolor, string inputcolor, string headingcolor)
{
    int nHeight = height / 2 - 4, newwidth = width / 2 - 20, base, i = 10, currentwidth, currentheight;
    string finalAnswer, takenNumber;
    bool validation = false;
    setColor(headingcolor);
    menuLineMovement(newwidth, nHeight);
    cout << "=====================================" << endl;
    menuLineMovement(newwidth + 11, nHeight);
    cout << "Base Conversion" << endl;
    menuLineMovement(newwidth, nHeight);
    cout << "=====================================" << endl;
    setColor(optioncolor);
    menuLineMovement(newwidth, nHeight);
    cout << "Enter number system base (2 - 62): ";
    base = takingIntegerInput(2, 62, newwidth + 42, nHeight - 1, inputcolor, optioncolor);
    menuLineMovement(newwidth, nHeight);
    cout << "Enter number to convert: ";
    getCursorPosition(currentwidth, currentheight);
    while (true)
    {

        validation = false;
        takenNumber = emptyverification(newwidth + 25, nHeight - 1, inputcolor, optioncolor);
        for (char c : takenNumber)
        {
            int value;
            if (c >= '0' && c <= '9')
            {
                value = c - '0';
            }
            else if (c >= 'A' && c <= 'Z')
            {
                value = c - 'A' + 10;
            }
            else if (c >= 'a' && c <= 'z')
            {
                value = c - 'a' + 36;
            }
            else
            {
                validation = true;
                break;
            }

            if (value >= base)
            {
                validation = true;
                break;
            }
        }
        if (!validation)
        {
            break;
        }
        else
        {
            gotoxy(currentwidth, currentheight);
            for (int i = 0; i < takenNumber.length(); i++)
            {
                cout << " ";
            }
            gotoxy(currentwidth, currentheight);
            setColor(inputcolor);
            cout << "invalid input";
            setColor(optioncolor);
            Sleep(1000);
            gotoxy(currentwidth, currentheight);
            cout << "                     ";
        }
        validation = false;
    }
    menuLineMovement(newwidth, nHeight);
    cout << "To base(2-62): ";
    int currentWidth, currentHeight;
    while (true)
    {
        getCursorPosition(currentWidth, currentHeight);
        int outputbase = takingIntegerInput(2, 62, newwidth + 42, nHeight - 1, inputcolor, optioncolor);
        if (base != outputbase)
        {
            int newHeight = 3;
            if (base != 10)
            {
                takenNumber = to_string(convertingToDecimal(takenNumber, base, width, height, newHeight));
                menuLineMovement(0, newHeight);
            }
            if (outputbase == 10)
                finalAnswer = takenNumber;
            else
                finalAnswer = convertingToOtherBase(stoll(takenNumber), outputbase, width, height, newHeight);
            int answerlength = finalAnswer.length();
            gotoxy(width / 2 - answerlength - 5, height - 8);
            cout << "Answer: " << finalAnswer;
            gotoxy(width / 2 - 15, height - 2);
            cout << "Press any key to continue...";
            _getch();
            system("cls");
            header(width, height, headingcolor);
            break;
        }
        else
        {
            gotoxy(currentWidth, currentHeight);
            setColor(inputcolor);
            cout << "invalid input";
            Sleep(1000);
            gotoxy(currentWidth, currentHeight);
            cout << "                     ";
        }
    }
    return 0;
}

// ================================================= converting base to decimal ========================================
long long convertingToDecimal(string takenNumber, int base, int width, int height, int nHeight)
{

    int nwidth = 2;
    long long decimalNumber = 0, power = 0;
    for (int i = takenNumber.length() - 1; i >= 0; i--)
    {
        if (takenNumber[i] >= '0' && takenNumber[i] <= '9')
        {
            menuLineMovement(nwidth, nHeight);
            decimalNumber += (takenNumber[i] - '0') * pow(base, power);
            cout << decimalNumber << " = " << takenNumber[i] << " * " << base << "^" << power << " + " << decimalNumber - (takenNumber[i] - '0') * pow(base, power) << endl;
        }
        else if (takenNumber[i] >= 'A' && takenNumber[i] <= 'Z')
        {
            menuLineMovement(nwidth, nHeight);
            decimalNumber += (takenNumber[i] - 'A' + 10) * pow(base, power);
            cout << decimalNumber << " = " << takenNumber[i] - 'A' + 10 << " * " << base << "^" << power << " + " << decimalNumber - (takenNumber[i] - 'A' + 10) * pow(base, power) << endl;
        }
        else if (takenNumber[i] >= 'a' && takenNumber[i] <= 'z')
        {
            menuLineMovement(nwidth, nHeight);
            decimalNumber += (takenNumber[i] - 'A' + 36) * pow(base, power);
            cout << decimalNumber << " = " << takenNumber[i] - 'A' + 36 << " * " << base << "^" << power << " + " << decimalNumber - (takenNumber[i] - 'A' + 36) * pow(base, power) << endl;
        }
        Sleep(500);
        power++;
    }
    return decimalNumber;
}

// ================================================= converting decimal to any base ========================================
string convertingToOtherBase(long long decimalNumber, int outputbase, int width, int height, int &nHeight)
{
    long long baseNumber = 0, temp;
    bool firstdecimal = true;
    int nwidth = width - 24;
    string simpleNumber = "", returnNumber = "";

    if (decimalNumber == 0)
        return "0";

    while (decimalNumber > 0)
    {
        menuLineMovement(nwidth, nHeight);
        cout << outputbase << " | " << decimalNumber;
        if (!firstdecimal)
            cout << " --> " << temp;
        else
            firstdecimal = false;
        menuLineMovement(nwidth, nHeight);
        cout << "-----------------------";
        Sleep(500);
        temp = decimalNumber % outputbase;
        if (temp < 10)
            simpleNumber += char('0' + temp);
        else if (temp < 36)
            simpleNumber += char('A' + (temp - 10));
        else
            simpleNumber += char('a' + (temp - 36));
        decimalNumber /= outputbase;
        if (decimalNumber < outputbase)
        {
            menuLineMovement(nwidth, nHeight);
            cout << outputbase << " | " << decimalNumber << " --> ";
            cout << temp;
            // saving number
            temp = decimalNumber % outputbase;
            if (temp < 10)
                simpleNumber += char('0' + temp);
            else if (temp < 36)
                simpleNumber += char('A' + (temp - 10));
            else
                simpleNumber += char('a' + (temp - 36));
            break;
        }
    }
    for (int i = simpleNumber.length() - 1; i >= 0; i--)
    {
        returnNumber += simpleNumber[i];
    }
    return returnNumber;
}

// ================================================= encryption ================================================================================
int encryption_function(int width, int height, string optioncolor, string inputcolor)
{
    int nwidth = width / 2 - 20, nheight = height / 2 - 4, currentwidth, currentheight, base;
    string input;
    menuLineMovement(nwidth, nheight);
    cout << "=====================================" << endl;
    menuLineMovement(nwidth + 11, nheight);
    cout << "Encryption" << endl;
    menuLineMovement(nwidth, nheight);
    cout << "=====================================" << endl;
    menuLineMovement(nwidth, nheight);
    cout << "Enter encryption base(2-62): ";
    base = takingIntegerInput(2, 62, nwidth + 42, nheight - 1, "0E", "0B");
    menuLineMovement(nwidth, nheight);
    cout << "Enter message to encrypt: ";
    bool validation = true;
    input = emptyverification(nwidth + 25, nheight - 1, "0E", "0B");
    string encrypted = encrypt(input, base);
    int answerlength = encrypted.length();
    gotoxy(width / 2 - answerlength / 2 - 5, height - 8);
    cout << "Answer: " << encrypted;
    gotoxy(width / 2 - 15, height - 2);
    cout << "Press any key to continue...";
    _getch();
    system("cls");
    header(width, height, "0C");
    return 0;
}

// ------------------------- encrypting message ---------------------------
string encrypt(string message, int base)
{
    string encrypted = "";

    for (char ch : message)
    {
        int ascii = static_cast<unsigned char>(ch);
        string baseValue = toBase(ascii, base);
        string mapped = mapDigits(baseValue);

        encrypted += mapped + "|";
    }
    if (!encrypted.empty())
        encrypted.pop_back();
    return encrypted;
}
string toBase(int num, int base)
{
    if (num == 0)
        return "0";

    string result = "";
    while (num > 0)
    {
        result = baseDigits[num % base] + result;
        num /= base;
    }
    return result;
}
string mapDigits(string s)
{
    string result = "";
    for (char c : s)
    {
        int index = baseDigits.find(c);
        result += secretMap[index];
    }
    return result;
}

// =================================================================== decryption function ===========================================================================
int decryption_function(int width, int height, string optioncolor, string inputcolor)
{
    int nwidth = width / 2 - 20, nheight = height / 2 - 4, currentwidth, currentheight, base;
    string input;
    menuLineMovement(nwidth, nheight);
    cout << "=====================================" << endl;
    menuLineMovement(nwidth + 11, nheight);
    cout << "Decryption" << endl;
    menuLineMovement(nwidth, nheight);
    cout << "=====================================" << endl;
    menuLineMovement(nwidth, nheight);
    cout << "Enter decryption base(2-62): ";
    base = takingIntegerInput(2, 62, nwidth + 42, nheight - 1, "0E", "0B");
    menuLineMovement(nwidth, nheight);
    cout << "Enter message to decrypt: ";
    bool validation = true;
    getCursorPosition(currentwidth, currentheight);
    while (true)
    {
        validation = true;
        input = emptyverification(currentwidth, currentheight, "0E", "0B");
        for (char c : input)
        {
            if (c != '|' && secretMap.find(c) == string::npos)
            {
                validation = false;
                break;
            }
        }
        if (validation)
        {
            break;
        }
        else
        {
            gotoxy(currentwidth, currentheight);
            for (int i = 0; i < input.length(); i++)
            {
                cout << " ";
            }
            gotoxy(currentwidth, currentheight);
            setColor(inputcolor);
            cout << "invalid input";
            setColor(optioncolor);
            Sleep(1000);
            gotoxy(currentwidth, currentheight);
            cout << "                     ";
        }
    }
    string decrypted = decrypt(input, base);
    int answerlength = decrypted.length();
    gotoxy(width / 2 - answerlength / 2 - 5, height - 8);
    cout << "Answer: " << decrypted;
    gotoxy(width / 2 - 15, height - 2);
    cout << "Press any key to continue...";
    _getch();
    system("cls");
    header(width, height, "0C");
    return 0;
}

// ------------------------------ decrypting message ---------------------------------
string decrypt(string cipher, int base)
{
    string decrypted = "";
    string token = "";

    for (char c : cipher)
    {
        if (c == '|')
        {
            string unmapped = unmapDigits(token);
            int ascii = fromBase(unmapped, base);
            decrypted += (char)ascii;
            token = "";
        }
        else
        {
            token += c;
        }
    }
    string unmapped = unmapDigits(token);
    int ascii = fromBase(unmapped, base);
    decrypted += (char)ascii;

    return decrypted;
}
int fromBase(string s, int base)
{
    int value = 0;
    for (char c : s)
    {
        int digit = baseDigits.find(c);
        if (digit == string::npos)
            throw runtime_error("Invalid character in fromBase: " + string(1, c));
        value = value * base + digit;
    }
    return value;
}
string unmapDigits(string s)
{
    string result = "";
    for (char c : s)
    {
        int index = secretMap.find(c);
        result += baseDigits[index];
    }
    return result;
}

// ================================================= Default functions =========================================================================
// -------------------- integer input verification ----------------------
int takingIntegerInput(int min, int max, int currentWidth, int currentHeight, string inputcolor, string optioncolor)
{
    string a;
    int action;
    getCursorPosition(currentWidth, currentHeight);
    while (true)
    {
        a = emptyverification(currentWidth, currentHeight, inputcolor, optioncolor);
        action = integerVerification(a);
        if (action >= min && action <= max)
            break;
        else
        {
            gotoxy(currentWidth, currentHeight);
            for (int i = 0; i < a.length(); i++)
            {
                cout << " ";
            }
            gotoxy(currentWidth, currentHeight);
            setColor(inputcolor);
            cout << "invalid input";
            setColor(optioncolor);
            Sleep(1000);
            gotoxy(currentWidth, currentHeight);
            cout << "             ";
        }
    }
    return action;
}

int integerVerification(string input)
{
    for (char c : input)
    {
        if (!isdigit(c))
            return INT_MIN;
    }
    try
    {
        int value = stoi(input);
        return value;
    }
    catch (const std::exception &e)
    {
        return INT_MIN;
    }
}

// ---------------- Empty verification ---------------------
string emptyverification(int w, int h, string inputcolor, string optioncolor)
{
    string temp;
    while (true)
    {
        setColor(inputcolor);
        showCursor();
        gotoxy(w, h);
        getline(cin, temp);
        hideCursor();
        if (!temp.empty())
        {
            temp = trimSpaces(temp);
            if (!checkPipe(temp))
            {
                gotoxy(w, h);
                cout << "This credential cannot contain \"|\".";
                Sleep(1000);
                gotoxy(w, h);
                cout << "                                       ";
            }
            else
                break;
        }
        else
        {
            gotoxy(w, h);
            cout << "This credential cannot be empty.";
            Sleep(1000);
            gotoxy(w, h);
            cout << "                                ";
        }
    }
    setColor(optioncolor);
    return temp;
}
bool checkPipe(const string &input)
{
    return true;
}
// ----------------- trim spaces ------------------------------
string trimSpaces(string str)
{
    string result = "";
    bool lastWasSpace = false;

    for (char c : str)
    {
        if (isspace(c))
        {
            if (!lastWasSpace)
            {
                result += ' ';
                lastWasSpace = true;
            }
        }
        else
        {
            result += c;
            lastWasSpace = false;
        }
    }
    return result;
}

// ----------------- set color function --------------------------
void setColor(string hexcolor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = stoi(hexcolor, nullptr, 16);
    SetConsoleTextAttribute(hConsole, color);
}
// ----------------- gotoxy fuction --------------------------
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// ------------- console measures -------------------------
void getconsolemeasures(int &width, int &height)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
// -------------------- get cursor current position -------------------
void getCursorPosition(int &currentWidth, int &currentHeight)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        currentWidth = csbi.dwCursorPosition.X;
        currentHeight = csbi.dwCursorPosition.Y;
    }
}

// ------- remove options in menu bar ------------------
void removeMenuOptions(int h)
{
    for (int i = 1; i <= h; i++)
    {
        gotoxy(1, i);
        cout << "                                                             ";
    }
}
// ------------------------------- cursor handling -------------------------------------------
void hideCursor()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);

    cursorInfo.bVisible = FALSE; // hide cursor
    SetConsoleCursorInfo(out, &cursorInfo);
}
void showCursor()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);

    cursorInfo.bVisible = TRUE; // show cursor
    SetConsoleCursorInfo(out, &cursorInfo);
}
void setCursorSize(int size)
{
    if (size < 1)
        size = 1;
    if (size > 100)
        size = 100;

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);

    cursorInfo.dwSize = size; // set cursor height
    SetConsoleCursorInfo(out, &cursorInfo);
}
void clearconsole(int width, int min, int max)
{
    for (int i = min; i <= max; i++)
    {
        gotoxy(width, i);
        cout << "                                                           ";
    }
}

// ------------ menu line movement ----------------
int menuLineMovement(int nwidth, int &nHeight)
{
    gotoxy(nwidth, nHeight);
    return nHeight++;
}
