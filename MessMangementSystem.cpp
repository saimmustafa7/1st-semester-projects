#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <ctime>
#include <fstream>
using namespace std;
//+++++++++++++++++++++++++++++++++++++++++++++++function prototypes
// -----------------------------------------Basic UI & Utility
void banner();
void gotoxy(int x, int y);
void printMenuHeader(string mainMenu, string subMenu);
void setcl(int text, int background = 0);
// Menus
string menu1();
void admin_menu();
void u_menu();
// -=========================================Interface & Setup
void admin_setup(string option2, string names[], string roll_no[], string room_no[], int attendance[], string fee_status[], string passwordsForMessUsers[], int &idx, string userNames[], string userPasswords[], string userRoles[], int &userCount, string mess_menu[], string complainRolls[], string complainTexts[], int &complainIdx, string visitorRequests[], int visitorCounts[], int &visitorIdx, string names_admin_approval[], string passwords_admin_approval[], string roles_admin_approval[], int &approval_count);
void user_interface();
void user_setup(string option, string &uN, string fee, string &name, string roll, string room, int attendance2, string userNames[], string userPasswords[], string passwordsForMessUsers[], int userCount, string names[], int idx, string complainRolls[], string complainTexts[], int &complainIdx, string visitorRequests[], int visitorCounts[], int &visitorIdx, string mess_menu[], string userRoles[], string roll_no[], string fee_status[], int attendance[], string room_no[]);
void UI();
//  -------------------------------------------------Authentication
int SignUp(string uN, string uP, string uR, string key, string userNames[], string userPasswords[], string userRoles[], int &userCount, string roll_no[], string passwordsForMessUsers[], int &idx, string names_admin_approval[], string passwords_admin_approval[], string roles_admin_approval[], int &approval_count);
void add_User(bool success, string uR, string uN, string names[], string room_no[], string fee_status[], int attendance[], int &idx, string roll_no[], string passwordsForMessUsers[], string password, string userNames[], string userPasswords[], string userRoles[], int &userCount);
string signin_check(string uN, string uP, string userNames[], string userPasswords[], string userRoles[], int userCount);
void takeInput(string names[], string room_no[], string roll_no[], int attendance[], string fee_status[], string userNames[], string userPasswords[], string userRoles[], string passwordsForMessUsers[], int &idx, int &userCount);
void detail(string name, string room, int Attendance, string fee);
int getValidInteger(string prompt = "");
void fetch(string fee_status[], string names[], string roll_no[], string room_no[], string passwordsForMessUsers[], int attendance[], int idx, string un, string up, string &fee, string &name, string &roll, string &room, int &attendance2);
void wrong_input();
//-------------------------------------------------Display & Data Handling
void showData(string names[], string room_no[], string roll_no[], string fee_status[], int attendance[], int idx);
void update1(string roll_no[],string names[],int idx , string room_no[], string fee_status[], int attendance[], string passwordsForMessUsers[]);
void update2(string roll_no[],string room_no[],int idx , string names[], string fee_status[], int attendance[], string passwordsForMessUsers[]);
void update3(string roll_no[], int idx , string names[], string room_no[], string fee_status[], int attendance[], string passwordsForMessUsers[]);
void update4(string roll_no[], string fee_status[], int idx , string names[], string room_no[], int attendance[], string passwordsForMessUsers[]);
void updateAttendance(string roll_no[], int attendance[], int idx , string names[], string room_no[], string fee_status[], string passwordsForMessUsers[]);
void delete_student(string names[], string roll_no[], string room_no[], int attendance[], string fee_status[], string passwordsForMessUsers[], int &idx, string userNames[], string userPasswords[], string userRoles[], int &userCount);
void signin_print();
void signup_print();
void update_menu(string mess_menu[]);
void o1(string mess_menu[]);
void o2(string uN, string fee, string name, string roll, string room, int attendance2);
void o3(string roll, string complainRolls[], string complainTexts[], int &complainIdx);
void o4(string roll, string visitorRequests[], int visitorCounts[], int &visitorIdx);
void view_userreq(string visitorRequests[], int visitorCounts[], int &visitorIdx,string roll_no[], int attendance[], int idx,string names[], string room_no[], string fee_status[], string passwordsForMessUsers[]);
void view_complaints_admin(string complainRolls[], string complainTexts[], int complainIdx, string names[], string roll_no[], int idx);
void admin_approval(string names_admin_approval[], string passwords_admin_approval[], string roles_admin_approval[], int &approval_count, string userNames[], string userPasswords[], string userRoles[], int &userCount);
void changePassword(string uN, string userNames[], string userPasswords[], string passwordsForMessUsers[], string names[], int userCount, int idx, string userRoles[], string roll_no[], string fee_status[], int attendance[], string room_no[]);
void changeUsername(string &uN, string &name, string userNames[], string names[], string userPasswords[], int userCount, int idx, string userRoles[], string roll_no[], string room_no[], int attendance[], string fee_status[], string passwordsForMessUsers[]);
// -------------------------------------------------File Handling- functions prototypes ----------------------------------------------
void loadLoginUserData(string userNames[], string userPasswords[], string userRoles[], int &userCount);
void saveLoginUserData(string userNames[], string userPasswords[], string userRoles[], int userCount);
void loadMessUserData(string names[], string roll_no[], string room_no[], int attendance[], string fee_status[], string passwordsForMessUsers[], int &idx);
void saveMessUserData(string names[], string roll_no[], string room_no[], int attendance[], string fee_status[], string passwordsForMessUsers[], int idx);
void loadComplaintsData(string complainRolls[], string complainTexts[], int &complainIdx);
void saveComplaintsData(string complainRolls[], string complainTexts[], int complainIdx);
void loadVisitorRequestsData(string visitorRequests[], int visitorCounts[], int &visitorIdx);
void saveVisitorRequestsData(string visitorRequests[], int visitorCounts[], int visitorIdx);
void saveMessMenuData(string mess_menu[]);
void saveAdminApprovalData(string names_admin_approval[], string passwords_admin_approval[], string roles_admin_approval[], int approval_count);
void loadapprovalData(string names_admin_approval[], string passwords_admin_approval[], string roles_admin_approval[], int &approval_count);
void loadMessMenuData(string mess_menu[]);
void loadAdminApprovalData(string names_admin_approval[], string passwords_admin_approval[], string roles_admin_approval[], int &approval_count);

//+++++++++++===================MAIN====================+++++++++++++++++
main()
{
    // ---------------------------------------variables---------------------------------------------------
    // LOGIN DATA
    const int userSize = 100;
    string userNames[userSize] = {};
    string userPasswords[userSize] = {};
    string userRoles[userSize] = {};
    int userCount = 0;
    // MESS DATA
    string names[100] = {};
    string roll_no[100] = {};
    string room_no[100] = {};
    int attendance[100] = {};
    string fee_status[100] = {};
    string passwordsForMessUsers[100] = {};
    int idx = 0;
    // Complaints data
    string complainRolls[100] = {};
    string complainTexts[100] = {};
    int complainIdx = 0;

    // Visitor requests data
    string visitorRequests[100] = {};
    int visitorCounts[100] = {};
    int visitorIdx = 0;

    // Mess menu data
    string mess_menu[14] = {};
    // admin approval
    string names_admin_approval[100];
    string passwords_admin_approval[100];
    string roles_admin_approval[100];
    int approval_count = 0;

    //---------call to save and load data functions---------
    loadLoginUserData(userNames, userPasswords, userRoles, userCount);
    loadMessUserData(names, roll_no, room_no, attendance, fee_status, passwordsForMessUsers, idx);
    loadComplaintsData(complainRolls, complainTexts, complainIdx);
    loadVisitorRequestsData(visitorRequests, visitorCounts, visitorIdx);
    loadMessMenuData(mess_menu);
    loadAdminApprovalData(names_admin_approval, passwords_admin_approval, roles_admin_approval, approval_count);


    // ---------- utility variables----------
    string fee, name, roll, room;
    int attendance2 = 0;
    string option1 = "0";
    int width, height;
    //--------------------------------------------------------------------loop that handles login menu options
    while (option1 != "3")
    {
        system("cls");
        UI();
        printMenuHeader("Login Menu", "");
        option1 = menu1();
        system("cls");
        banner();
        // sign in menu
        if (option1 == "1")
        {
            printMenuHeader("Login Menu", "SignIn");
            string uN, uP, uR;
            signin_print();
            gotoxy(35, 9);
            cin >> uN;
            gotoxy(35, 11);
            cin >> uP;
            uR = signin_check(uN, uP, userNames, userPasswords, userRoles, userCount);
            fetch(fee_status, names, roll_no, room_no, passwordsForMessUsers, attendance, idx, uN, uP, fee, name, roll, room, attendance2);
            if (uR != "undefined")
            {
                if (uR == "Admin" || uR == "admin")

                {
                    system("cls");
                    gotoxy(31, 12);
                    setcl(10);
                    cout << "loading Admin Menu";
                    Sleep(1500);
                    setcl(7);
                    string option2 = "0";
                    //---------------------------------------------------loop that handles admin menu options
                    while (option2 != "10")
                    {
                        system("cls");
                        banner();
                        printMenuHeader("Admin Menu", " ");
                        admin_menu();
                        gotoxy(45, 6);

                        cin >> option2;
                        admin_setup(
                            option2,
                            names, roll_no, room_no, attendance, fee_status,
                            passwordsForMessUsers, idx,
                            userNames, userPasswords, userRoles, userCount,
                            mess_menu,
                            complainRolls, complainTexts, complainIdx,
                            visitorRequests, visitorCounts, visitorIdx, names_admin_approval, passwords_admin_approval, roles_admin_approval, approval_count);
                    }
                }

                else if (uR == "User" || uR == "user")
                {
                    system("cls");

                    gotoxy(31, 12);
                    setcl(4);
                    cout << "loading User Menu";
                    setcl(7);
                    Sleep(1500);
                    string option2 = "0";
                    //---------------------------------------------------loop that handles the user menu options
                    while (option2 != "7")
                    {
                        system("cls");
                        banner();
                        detail(name, room, attendance2, fee);
                        printMenuHeader("User Menu", " ");
                        user_interface();
                        gotoxy(75, 13);
                        cin >> option2;
                        user_setup(
                            option2,
                            uN, fee, name, roll, room, attendance2,
                            userNames, userPasswords, passwordsForMessUsers, userCount,
                            names, idx,
                            complainRolls, complainTexts, complainIdx,
                            visitorRequests, visitorCounts, visitorIdx,
                            mess_menu,
                            userRoles,
                            roll_no, fee_status, attendance, room_no);
                    }
                }
                else
                {
                    cout << endl
                         << "  User Not Found" << endl;
                    getch();
                }
            }
        }
        // signup menu
        if (option1 == "2")
        {
            printMenuHeader("Login Menu", "SignUp");
            string uN, uP, uR, roll, key = "101";
            signup_print();
            gotoxy(35, 9);
            cin >> uN;
            gotoxy(35, 11);
            cin >> uP;
            gotoxy(35, 13);
            cin >> uR;
            gotoxy(0, 16);
            int check = SignUp(uN, uP, uR, key, userNames, userPasswords, userRoles, userCount, roll_no, passwordsForMessUsers, idx, names_admin_approval, passwords_admin_approval, roles_admin_approval, approval_count);
            add_User(check, uR, uN, names, room_no, fee_status, attendance, idx, roll_no, passwordsForMessUsers, uP, userNames, userPasswords, userRoles, userCount);

            if (1 == check)
            {
                cout << "   SignUp Successfully" << endl;
                cout << "press any key to continue";
                getch();
            }
            else if (0 == check)
            {
                cout << "   SignUp UnSuccessfully" << endl;
                cout << "press any key to continue";
                getch();
            }
            else if (2 == check)
            {
                cout << "   Admin SignUp Pending for Approval" << endl;
                cout << "press any key to continue";
                getch();
            }
        }
        // runs if the input is wrong in login menu
        else if (option1 != "1" && option1 != "2" && option1 != "3")
        {
            system("cls");
            banner();
            gotoxy(34, 5);
            wrong_input();
            getch();
            system("cls");
        }
    }
    saveLoginUserData(userNames, userPasswords, userRoles, userCount);
    saveMessUserData(names, roll_no, room_no, attendance, fee_status, passwordsForMessUsers, idx);
    saveComplaintsData(complainRolls, complainTexts, complainIdx);
    saveVisitorRequestsData(visitorRequests, visitorCounts, visitorIdx);
    saveMessMenuData(mess_menu);
    saveAdminApprovalData(names_admin_approval, passwords_admin_approval, roles_admin_approval, approval_count);
}
// function to change colour
void setcl(int text, int background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (background << 4));
}
// function to move cursor anywhere
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
//---------------------------------------file handiling functions---------------------------------------
// Function to save login data from file
void saveLoginUserData(string userNames[], string userPasswords[], string userRoles[], int userCount)
{
    fstream file;
    file.open("login_users.txt", ios::out);

    if (file.is_open())
    {
        for (int i = 0; i < userCount; i++)
        {
            file << userNames[i] << "," << userPasswords[i] << "," << userRoles[i] << "\n";
        }
        file.close();
    }
}
// Function to load login data from file
void loadLoginUserData(string userNames[], string userPasswords[], string userRoles[], int &userCount)
{
    fstream file;
    file.open("login_users.txt", ios::in);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string username, password, role;

            getline(ss, username, ',');
            getline(ss, password, ',');
            getline(ss, role, ',');

            userNames[userCount] = username;
            userPasswords[userCount] = password;
            userRoles[userCount] = role;

            userCount++;
        }
        file.close();
    }
}
// Function to save mess user data to file
void saveMessUserData(string names[], string roll_no[], string room_no[], int attendance[], string fee_status[], string passwordsForMessUsers[], int idx)
{
    fstream file;
    file.open("mess_users.txt", ios::out);

    if (file.is_open())
    {
        for (int i = 0; i < idx; i++)
        {
            file << names[i] << "," << roll_no[i] << "," << room_no[i] << "," << attendance[i] << "," << fee_status[i] << "," << passwordsForMessUsers[i] << "\n";
        }
        file.close();
    }
}
// Function to load mess user data from file
void loadMessUserData(string names[], string roll_no[], string room_no[], int attendance[], string fee_status[], string passwordsForMessUsers[], int &idx)
{
    fstream file;
    file.open("mess_users.txt", ios::in);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string name, roll, room, fee_status_str, password;
            int attendance_val;

            getline(ss, name, ',');
            getline(ss, roll, ',');
            getline(ss, room, ',');
            ss >> attendance_val;
            ss.ignore(1, ',');
            getline(ss, fee_status_str, ',');
            getline(ss, password, ',');

            names[idx] = name;
            roll_no[idx] = roll;
            room_no[idx] = room;
            attendance[idx] = attendance_val;
            fee_status[idx] = fee_status_str;
            passwordsForMessUsers[idx] = password;

            idx++;
        }
        file.close();
    }
}
// Function to save complaints data to a text file
void saveComplaintsData(string complainRolls[], string complainTexts[], int complainIdx)
{
    fstream file;
    file.open("complains.txt", ios::out);

    if (file.is_open())
    {
        for (int i = 0; i < complainIdx; i++)
        {
            file << complainRolls[i] << "," << complainTexts[i] << "\n";
        }
        file.close();
    }
}
// Function to load complaints data (roll numbers and complaint texts) from a text file
void loadComplaintsData(string complainRolls[], string complainTexts[], int &complainIdx)
{
    fstream file;
    file.open("complains.txt", ios::in);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string roll, complaint;

            getline(ss, roll, ',');
            getline(ss, complaint, ',');

            complainRolls[complainIdx] = roll;
            complainTexts[complainIdx] = complaint;

            complainIdx++;
        }
        file.close();
    }
}
// Function to save visitor requests data (roll numbers and visitor counts) to a text file
void saveVisitorRequestsData(string visitorRequests[], int visitorCounts[], int visitorIdx)
{
    fstream file;
    file.open("visitor_requests.txt", ios::out);

    if (file.is_open())
    {
        for (int i = 0; i < visitorIdx; i++)
        {
            file << visitorRequests[i] << "," << visitorCounts[i] << "\n";
        }
        file.close();
    }
}
// Function to load visitor requests data (roll numbers and visitor counts) from a text file
void loadVisitorRequestsData(string visitorRequests[], int visitorCounts[], int &visitorIdx)
{
    fstream file;
    file.open("visitor_requests.txt", ios::in);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string roll;
            int visitors;

            getline(ss, roll, ',');
            ss >> visitors;

            visitorRequests[visitorIdx] = roll;
            visitorCounts[visitorIdx] = visitors;

            visitorIdx++;
        }
        file.close();
    }
}
// Function to save mess menu data to a text file
void saveMessMenuData(string mess_menu[])
{
    fstream file;
    file.open("mess_menu.txt", ios::out);

    if (file.is_open())
    {
        for (int i = 0; i < 14; i++)
        {
            file << mess_menu[i] << "\n";
        }
        file.close();
    }
}
// Function to load mess menu data from a text file
void loadMessMenuData(string mess_menu[])
{
    fstream file;
    file.open("mess_menu.txt", ios::in);

    if (file.is_open())
    {
        string line;
        int i = 0;
        while (getline(file, line) && i < 14)
        {
            mess_menu[i] = line;
            i++;
        }
        file.close();
    }
}
// Function to save admin approval data
void saveAdminApprovalData(string names_admin_approval[], string passwords_admin_approval[], string roles_admin_approval[], int approval_count)
{
    fstream file;
    file.open("admin_approval.txt", ios::out);

    if (file.is_open())
    {
        for (int i = 0; i < approval_count; i++)
        {
            file << names_admin_approval[i] << "," << passwords_admin_approval[i] << "," << roles_admin_approval[i] << "\n";
        }
        file.close();
    }
}
// Function to load admin approval data (names, passwords, roles) from a text file
void loadAdminApprovalData(string names_admin_approval[], string passwords_admin_approval[], string roles_admin_approval[], int &approval_count)
{
    fstream file;
    file.open("admin_approval.txt", ios::in);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string name, password, role;

            getline(ss, name, ',');
            getline(ss, password, ',');
            getline(ss, role, ',');

            names_admin_approval[approval_count] = name;
            passwords_admin_approval[approval_count] = password;
            roles_admin_approval[approval_count] = role;

            approval_count++;
        }
        file.close();
    }
}
// function which runs on wrong input (sometimes)
void wrong_input() { 
    setcl(4); 
    cout << " Wrong Input ---------- Try Again" << endl; 
    cout << " Press any key to continue " << endl; 
    setcl(7);
 }
 // functoion of signin interface
void signin_print()
{
    setcl(14);

    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                 Enter Username                                 |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                 Enter password                                 |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "----------------------------------------------------------------------------------" << endl
         << endl;
    setcl(7);
}
//function that checks the data
string signin_check(string uN, string uP, string userNames[], string userPasswords[], string userRoles[], int userCount)
{
    for (int i = 0; i < userCount; i++)
    {
        if (userNames[i] == uN && userPasswords[i] == uP)
        {
            return userRoles[i];
        }
    }
    return "undefined";
}
// function to print user interface
void user_interface()
{
    setcl(14);
    cout << endl
         << "                                            CHOOSE ONE OF THE OPTIONS(1-6):                       " << endl
         << endl;
    cout << "                                               1: Mess Menu" << endl;
    cout << "                                               2: Check Bill of This Month" << endl;
    cout << "                                               3: Complain" << endl;
    cout << "                                               4: Change Password" << endl;
    cout << "                                               5: Change Username" << endl;
    cout << "                                               6: Request Visitors Attendace" << endl;

    cout << "                                               7: Exit" << endl;
    setcl(7);
}

// function which runs when user chose 1
void o1(string mess_menu[])
{
    setcl(2);
    cout << endl
         << "                           **     **  ******  **   **  **   **           " << endl;
    cout << "                           **     **  **      ***  **  **   **           " << endl;
    cout << "                           ** *** **  ****    ** * **  **   **           " << endl;
    cout << "                           **  *  **  **      **  ***  **   **           " << endl;
    cout << "                           **     **  ******  **   **   *****            " << endl;
    setcl(14);
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "|   Day       |                        Lunch                   |     Dinner    |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "|  Monday     >  " << mess_menu[0] << "                                 " << mess_menu[1] << " |" << endl;
    cout << "|  Tuesday    >  " << mess_menu[2] << "                                 " << mess_menu[3] << " |" << endl;
    cout << "|  Wednesday  >  " << mess_menu[4] << "                        " << mess_menu[5] << " |" << endl;
    cout << "|  Thursday   > " << mess_menu[6] << "                      " << mess_menu[7] << " |" << endl;
    cout << "|  Friday     >  " << mess_menu[8] << "                         " << mess_menu[9] << " |" << endl;
    cout << "|  Saturday   >  " << mess_menu[10] << "                        " << mess_menu[11] << " |" << endl;
    cout << "|  Sunday     > " << mess_menu[12] << "                         " << mess_menu[13] << " |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    setcl(7);
}
// function which showes user its bill
void o2(string uN, string fee, string name, string roll, string room, int attendance2)
{
    setcl(14);

    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "Date:\t" << put_time(ltm, "%B%d,%Y") << endl;
    cout << "Student Name:\t" << uN << endl;
    cout << "Room No:\t" << room << endl;
    cout << "Total Meals This Month:\t" << attendance2 << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    setcl(4);
    cout << "Service charges:\t1200 " << endl;
    int display = attendance2 * 220;
    cout << "Mess charges:\t" << display << endl;
    cout << "Amount to be paid:\t" << display + 1200 << endl;
}
// function which handles complain section for user
void o3(string roll, string complainRolls[], string complainTexts[], int &complainIdx)
{
    setcl(14);
    string complaint;

    cout << "================================================================================" << endl;
    cout << "                      ENTER YOUR COMPLAINT (max 500 chars)                       " << endl;
    cout << "================================================================================" << endl;

    cin.ignore();
    getline(cin, complaint);

    if (complaint.length() > 150 || complaint.empty())
    {
        cout << "Invalid Input!" << endl;
        return;
    }

    complainRolls[complainIdx] = roll;
    complainTexts[complainIdx] = complaint;
    complainIdx++;

    system("cls");
    cout << "================================================================================" << endl;
    cout << "                              COMPLAINT RECEIVED                                " << endl;
    cout << "================================================================================" << endl;
    setcl(7);
    saveComplaintsData(complainRolls, complainTexts, complainIdx);
}

// Function for users to request visitor attendance
void o4(string roll, string visitorRequests[], int visitorCounts[], int &visitorIdx)
{
    setcl(14);
    int visitors;
    visitors = getValidInteger("Enter the number of visitors: ");
    if (visitors <= 0 || visitors > 10)
    {
        cout << "Invalid number of visitors! Please enter a number between 1 and 10." << endl;
        return;
    }

    visitorRequests[visitorIdx] = roll;
    visitorCounts[visitorIdx] = visitors;
    visitorIdx++;

    cout << "Visitor attendance request submitted successfully!" << endl;
    setcl(7);
    saveVisitorRequestsData(visitorRequests, visitorCounts, visitorIdx);
}
// fucntion to display details of user
void detail(string name, string room, int attendance2, string fee)
{
    setcl(2);
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "| No | Name         | Room No  | Meals This Month | Fee Status     |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "| 1  | " << name << "         |  " << room << "       | " << attendance2;
    cout << "               | " << fee << "           |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl
         << endl;
    setcl(7);
}
// function to display admin menu
void admin_menu()
{
    setcl(9);
    cout << " Choose what action you want to perform(1-8): " << endl;
    setcl(14);
    cout << " 1. Add a Student" << endl;
    cout << " 2. Update Students Information" << endl;
    cout << " 3. Delete Student from Mess" << endl;
    cout << " 4. Show All active Students enrolled in Mess" << endl;
    cout << " 5. Update MESS menu" << endl;
    cout << " 6. Update Attendance of Student" << endl;
    cout << " 7. View Recent complain" << endl;
    cout << " 8. View Visitor Requests" << endl;
    cout << " 9. Admin Request" << endl;
    cout << "10. Exit " << endl;
    setcl(7);
}
// function to show all active mess users
void showData(string names[], string room_no[], string roll_no[], string fee_status[], int attendance[], int idx)
{
    setcl(14);
    cout << setw(15) << "Names" << setw(15) << "Room No." << setw(15) << "Roll No." << setw(15) << "Fee status" << setw(15) << "Attendance" << endl;

    for (int x = 0; x < idx; x++)
    {
        cout << setw(15) << names[x] 
             << setw(15) << room_no[x]
             << setw(15) << roll_no[x] 
             << setw(15) << fee_status[x]
             << setw(15) << attendance[x] << endl;
    }
    setcl(7);
}

// function to add person in mess
void takeInput(string names[], string room_no[], string roll_no[], int attendance[], string fee_status[], string userNames[], string userPasswords[], string userRoles[], string passwordsForMessUsers[], int &idx, int &userCount)
{
    setcl(14);
    cout << "Enter Name: ";
    cin >> names[idx];

    cout << "Enter Room No: ";
    cin >> room_no[idx];

    cout << "Enter Roll No: ";
    cin >> roll_no[idx];
    for (int i = 0; i < idx; i++)
    {
        if (roll_no[idx] == roll_no[i] && i != idx)
        {
            cout << "Roll No already exists. Please enter a unique Roll No." << endl;
            return;
        }
    }

    attendance[idx] = getValidInteger( "Enter Attendance: ");

    cout << "Enter Fee Status: ";
    cin >> fee_status[idx];

    cout << "Set Password: ";
    cin >> passwordsForMessUsers[idx];

    userNames[userCount] = names[idx];
    userPasswords[userCount] = passwordsForMessUsers[idx];
    userRoles[userCount] = "User";

    idx++;
    userCount++;
    saveLoginUserData(userNames, userPasswords, userRoles, userCount);
    saveMessUserData(names, roll_no, room_no, attendance, fee_status, passwordsForMessUsers, idx);
    setcl(7);
}

// function to display update details of mess user
void u_menu()
{

    cout << endl
         << "1.\tName" << endl
         << "2.\tRoom  No" << endl
         << "3.\tRoll No" << endl;
    cout << "4.\tFee Status" << endl;
    cout << " Choose what you want to update(type 1-4):";
}
// fucntion to update first option in mess user details
void update1(
    string roll_no[],
    string names[],
    int idx , string room_no[], string fee_status[], int attendance[], string passwordsForMessUsers[])
{
    setcl(1);
    string roll_number;
    cout << " Enter the roll number of student whose name you want to change(format--2025-CS-18): ";
    cin >> roll_number;

    for (int x = 0; x < idx; x++)
    {
        if (roll_number == roll_no[x])
        {
            cout << "Enter new name:";
            cin >> names[x];
            break;
        }
    }
    saveMessUserData(names, roll_no, room_no, attendance, fee_status, passwordsForMessUsers, idx);
    setcl(7);
}

void update2(
    string roll_no[],
    string room_no[],
    int idx , string names[], string fee_status[], int attendance[], string passwordsForMessUsers[])
{
    setcl(1);
    string roll_number;
    cout << " Enter the roll number of student whose room you want to update(format--2025-CS-18): ";
    cin >> roll_number;

    for (int x = 0; x < idx; x++)
    {
        if (roll_number == roll_no[x])
        {
            cout << "Enter new Room number:";
            cin >> room_no[x];
            break;
        }
    }
    saveMessUserData(names, roll_no, room_no, attendance, fee_status, passwordsForMessUsers, idx);
    setcl(7);
}

// fucntion to update third option in mess user details
void update3(
    string roll_no[],
    int idx , string names[], string room_no[], string fee_status[], int attendance[], string passwordsForMessUsers[])
{
    setcl(1);
    string roll_number;
    cout << " Enter the Wroll_numberg Roll Number you want to change: ";
    cin >> roll_number;

    for (int x = 0; x < idx; x++)
    {
        if (roll_number == roll_no[x])
        {
            cout << "Enter new roll number(format--2025-CS-18):";
            cin >> roll_no[x];
            break;
        }
    }
    saveMessUserData(names, roll_no, room_no, attendance, fee_status, passwordsForMessUsers, idx);
    setcl(7);
}

// fucntion to update four option in mess user details
void update4(
    string roll_no[],
    string fee_status[],
    int idx , string names[], string room_no[], int attendance[], string passwordsForMessUsers[])
{
    setcl(1);
    string in, inn;
    cout << "Enter the roll number of student(format--2025-CS-18)" << endl;
    cin >> in;

    for (int x = 0; x < idx; x++)
    {
        if (in == roll_no[x])
        {
            cout << "Enter (Paid or Unpaid): ";
            cin >> inn;
            fee_status[x] = inn;
        }
    }
    saveMessUserData(names, roll_no, room_no, attendance, fee_status, passwordsForMessUsers, idx);
    setcl(7);
}
// function to delete user from mess
void delete_student(string names[], string roll_no[], string room_no[], int attendance[], string fee_status[], string passwordsForMessUsers[], int &idx, string userNames[], string userPasswords[], string userRoles[], int &userCount)
{
    setcl(14);
    string roll_number;
    cout << " Enter Roll No of the Student you want to delete(format--2025-CS-18): ";
    cin >> roll_number;

    int stuIndex = -1;
    for (int x = 0; x < idx; x++)
    {
        if (roll_number == roll_no[x])
        {
            stuIndex = x;
            break;
        }
    }

    if (stuIndex == -1)
    {
        cout << "Student not found!" << endl;
        return;
    }

    int loginIndex = -1;
    for (int i = 0; i < userCount; i++)
    {
        if (userNames[i] == names[stuIndex] &&
            (userRoles[i] == "User" || userRoles[i] == "user"))
        {
            loginIndex = i;
            break;
        }
    }

    for (int x = stuIndex; x < idx - 1; x++)
    {
        names[x] = names[x + 1];
        roll_no[x] = roll_no[x + 1];
        room_no[x] = room_no[x + 1];
        attendance[x] = attendance[x + 1];
        fee_status[x] = fee_status[x + 1];
        passwordsForMessUsers[x] = passwordsForMessUsers[x + 1];
    }

    idx = idx - 1;

    if (loginIndex != -1)
    {
        for (int i = loginIndex; i < userCount - 1; i++)
        {
            userNames[i] = userNames[i + 1];
            userPasswords[i] = userPasswords[i + 1];
            userRoles[i] = userRoles[i + 1];
        }
        userCount = userCount - 1;
    }
    saveLoginUserData(userNames, userPasswords, userRoles, userCount);
    saveMessUserData(names, roll_no, room_no, attendance, fee_status, passwordsForMessUsers, idx);

    setcl(7);
} // function to display banner of my application
void banner()
{
    setcl(10);
    
    cout << "========================================================================================================================" << endl;
    cout << "                                               MESS MANAGEMENT SYSTEM                                                " << endl;
    cout << "========================================================================================================================" << endl
    << endl;
    setcl(7);
}
// function to show in which section is user right now
void printMenuHeader(string mainMenu, string subMenu)
{
    setcl(4);
    string msg = mainMenu + " > " + subMenu;
    cout << msg << endl;
    cout << "------------------------------" << endl;
    setcl(7);
}
// function to print signup interface
void signup_print()
{
    setcl(14);

    cout << "----------------------------------------------------------------------------------" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                 Enter Username                                 |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                 Enter password                                 |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                 Enter Role(Admin/User)                         |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "|                                                                                |" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
    setcl(7);
}
// function to verify signup
int SignUp(string uN, string uP, string uR, string key, string userNames[], string userPasswords[], string userRoles[], int &userCount, string roll_no[], string passwordsForMessUsers[], int &idx, string names_admin_approval[], string passwords_admin_approval[], string roles_admin_approval[], int &approval_count)
{
    setcl(14);

    if (uR != "Admin" && uR != "admin" && uR != "User" && uR != "user")
        return 0;

    for (int i = 0; i < userCount; i++)
    {
        if (userNames[i] == uN && userPasswords[i] == uP)
            return 0;
    }

    if (uR == "Admin" || uR == "admin")
    {
        cout << "Your request is forwarded to the admin for approval." << endl;

        names_admin_approval[approval_count] = uN;
        passwords_admin_approval[approval_count] = uP;
        roles_admin_approval[approval_count] = uR;
        approval_count++;
        saveAdminApprovalData(names_admin_approval, passwords_admin_approval, roles_admin_approval, approval_count);
        return 2;
    }

    userNames[userCount] = uN;
    userPasswords[userCount] = uP;
    userRoles[userCount] = uR;
    userCount++;
    saveLoginUserData(userNames, userPasswords, userRoles, userCount);

    return 1;
}

// function to print interface  at start
string menu1()
{
    setcl(14);
    string option;
    cout << "1. SignIn" << endl;
    cout << "2. SignUp" << endl;
    cout << "3. Exit" << endl;
    cin >> option;
    setcl(7);
    return option;
}
// function that add login users to mess users array
void add_User(bool success, string uR, string uN, string names[], string room_no[], string fee_status[], int attendance[], int &idx, string roll_no[], string passwordsForMessUsers[], string password,
              string userNames[], string userPasswords[], string userRoles[], int &userCount)
{
    if (!success)
        return;

    if (uR == "User" || uR == "user")
    {
        names[idx] = uN;
        cout << "Enter Roll No: ";
        cin >> roll_no[idx];

        room_no[idx] = "To be Updated";
        fee_status[idx] = "To be Updated";
        attendance[idx] = 0;
        passwordsForMessUsers[idx] = password;

        idx++;
        saveLoginUserData(userNames, userPasswords, userRoles, userCount);
        saveMessUserData(names, roll_no, room_no, attendance, fee_status, passwordsForMessUsers, idx);
    }
}

// function that updates mess menu
void update_menu(string mess_menu[])
{
    setcl(14);
    string day, type;

    while (true)
    {
        cout << "Enter day which you want to change: ";
        cin >> day;
        transform(day.begin(), day.end(), day.begin(), ::tolower);

        if (day == "monday" || day == "tuesday" || day == "wednesday" ||
            day == "thursday" || day == "friday" ||
            day == "saturday" || day == "sunday")
            break;
         else
            cout << "Invalid day. Please enter a valid day of the week." << endl;
    }

    while (true)
    {
        cout << "Enter meal type you want to change(lunch-dinner): ";
        cin >> type;
        transform(type.begin(), type.end(), type.begin(), ::tolower);

        if (type == "lunch" || type == "dinner")
            break;
            else
            cout << "Invalid meal type. Please enter 'lunch' or 'dinner'." << endl;
    }

    cout << "Enter new meal: ";
    cin.ignore();

    if (day == "monday")
        getline(cin, mess_menu[type == "lunch" ? 0 : 1]);
    else if (day == "tuesday")
        getline(cin, mess_menu[type == "lunch" ? 2 : 3]);
    else if (day == "wednesday")
        getline(cin, mess_menu[type == "lunch" ? 4 : 5]);
    else if (day == "thursday")
        getline(cin, mess_menu[type == "lunch" ? 6 : 7]);
    else if (day == "friday")
        getline(cin, mess_menu[type == "lunch" ? 8 : 9]);
    else if (day == "saturday")
        getline(cin, mess_menu[type == "lunch" ? 10 : 11]);
    else if (day == "sunday")
        getline(cin, mess_menu[type == "lunch" ? 12 : 13]);
    setcl(2);

    cout << "Updated successfully" << endl;
       saveMessMenuData(mess_menu);
    setcl(7);
}

// function that updates attendance of active users of mess
void updateAttendance(string roll_no[], int attendance[], int idx , string names[], string room_no[], string fee_status[], string passwordsForMessUsers[])
{
    setcl(14);
    string roll;
    cout << "Enter roll number to update attendance(format--2025-CS-18): ";
    cin >> roll;

    int index = -1;
    for (int i = 0; i < idx; i++)

    {
        if (roll_no[i] == roll)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        cout << "Current attendance for roll number "
             << roll_no[index] << ": " << attendance[index] << endl;

        int newAttendance;
        newAttendance = getValidInteger("Enter new attendance: ");
        attendance[index] = newAttendance;
        cout << "Attendance updated successfully!" << endl;
         saveMessUserData(names, roll_no, room_no, attendance, fee_status, passwordsForMessUsers, idx);
    }
    else
    {
        cout << "Roll number not found!" << endl;
    }
}

// function that fethes user details
void fetch(string fee_status[], string names[], string roll_no[], string room_no[], string passwordsForMessUsers[], int attendance[], int idx, string un, string up, string &fee, string &name, string &roll, string &room, int &attendance2)
{
    for (int i = 0; i < idx; i++)
    {
        if (passwordsForMessUsers[i] == up && names[i] == un)
        {
            fee = fee_status[i];
            name = names[i];
            roll = roll_no[i];
            room = room_no[i];
            attendance2 = attendance[i];
            return;
        }
    }
    setcl(7);
}
// this function changes the password of user
void changePassword(string uN, string userNames[], string userPasswords[], string passwordsForMessUsers[], string names[], int userCount, int idx, string userRoles[], string roll_no[], string fee_status[], int attendance[], string room_no[])
{
    setcl(14);
    string currentPass, newPass, confirmPass;
    cout << "Enter current password: ";
    cin >> currentPass;

    int loginIndex = -1;
    for (int i = 0; i < userCount; i++)
        if (userNames[i] == uN && userPasswords[i] == currentPass)
            loginIndex = i;

    if (loginIndex == -1)
    {
        cout << "Wrong password\n";
        return;
    }

    cout << "Enter new password: ";
    cin >> newPass;



    // checking if the uername and passwrod is same as the other users



    for (int i = 0; i < userCount; i++)
    {
         if (i == loginIndex)
            continue;
        if (userNames[i] == uN && userPasswords[i] == newPass)
        {
            cout << "This password is already in use\n";
            return;
        }
    }
    cout << "Confirm new password: ";
    cin >> confirmPass;

    if (newPass != confirmPass)
    {
        cout << "Mismatch\n";
        return;
    }
    
       

    userPasswords[loginIndex] = newPass;

    for (int i = 0; i < idx; i++)
        if (names[i] == uN)
            passwordsForMessUsers[i] = newPass;

    cout << "Password updated\n";
    saveLoginUserData(userNames, userPasswords, userRoles, userCount);
    saveMessUserData(names, roll_no, room_no, attendance, fee_status, passwordsForMessUsers, idx);

    setcl(7);
}


// function that runs for visitors feature in admin menu
void view_userreq(string visitorRequests[], int visitorCounts[], int &visitorIdx,string roll_no[], int attendance[], int idx,string names[], string room_no[], string fee_status[], string passwordsForMessUsers[])
{
    setcl(14);

    if (visitorIdx <= 0)
    {
        cout << "No visitor requests pending." << endl;
        setcl(7);
        return;
    }

    cout << "Visitor Requests:\n";
    for (int i = 0; i < visitorIdx; i++)
    {
        cout << i + 1 << ". Roll Number: " << visitorRequests[i]
             << " ------- Visitors: " << visitorCounts[i] << endl;
    }

    int choice;
  choice = getValidInteger("\nEnter the request number (0 to go back): ");

    if (choice == 0)
    {
        setcl(7);
        return;
    }

    if (choice < 1 || choice > visitorIdx)
    {
        cout << "Invalid request number." << endl;
        setcl(7);
        return;
    }

    int reqIndex = choice - 1;
    string rollNo = visitorRequests[reqIndex];
    int visitors = visitorCounts[reqIndex];

    cout << "\nRequest from Roll No " << rollNo
         << " for " << visitors << " visitors.\n";

    string approve;
    cout << "Approve (Yes/No): ";
    cin >> approve;

    // converting to small characters
    transform(approve.begin(), approve.end(), approve.begin(), ::tolower);

    if (approve == "yes")
    {
        
        int stuIndex = -1;
        for (int i = 0; i < idx; i++)
        {
            if (roll_no[i] == rollNo)
            {
                stuIndex = i;
                break;
            }
        }

        if (stuIndex != -1)
        {
            attendance[stuIndex] += visitors;
            cout << "Attendance updated for Roll No " << rollNo << endl;

            saveMessUserData(names, roll_no, room_no, attendance, fee_status, passwordsForMessUsers, idx);
        }
        else
        {

            cout << "Warning: Roll No not found in mess data, request will still be cleared." << endl;
        }
    }
    else if (approve == "no")
    {
        cout << "Request rejected." << endl;
    }
    else
    {
        cout << "Invalid input (type Yes or No). Request NOT processed." << endl;
        setcl(7);
        return; 
    }

    for (int i = reqIndex; i < visitorIdx - 1; i++)
    {
        visitorRequests[i] = visitorRequests[i + 1];
        visitorCounts[i] = visitorCounts[i + 1];
    }

    visitorRequests[visitorIdx - 1] = "";
    visitorCounts[visitorIdx - 1] = 0;

    visitorIdx--;

    saveVisitorRequestsData(visitorRequests, visitorCounts, visitorIdx);

    setcl(7);
}

void UI()
{
    setcl(2);
    cout << R"(
 __ __ ___   ___  ________
 | '_ ` _ \ / _ \/ __/ __|                                    _   
 | | | | | |  __/\__ \__ \                                   | |  
 |_|_|_|_|_|\___||___/___/_ _  __ _  ___ _ __ ___   ___ _ __ | |_ 
 | '_ ` _ \ / _` | '_ \ / _` |/ _` |/ _ \ '_ ` _ \ / _ \ '_ \| __|
 | | | | | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_ 
 |_| |_| |_|\__,_|_| |_|\__,_|\__, |\___|_| |_| |_|\___|_| |_|\__|
               | |              /  |                             
  ___ _   _ ___| |_ ___ _ __ _|___/                               
 / __| | | / __| __/ _ \ '_ ` _ \                                 
 \__ \ |_| \__ \ ||  __/ | | | | |                                
 |___/\__, |___/\__\___|_| |_| |_|                                
       __/ |                                                      
      |___/ 
    )" << endl;
    setcl(7);
}
void view_complaints_admin(string complainRolls[], string complainTexts[], int complainIdx, string names[], string roll_no[], int idx)
{
    setcl(14);
    if (complainIdx == 0)
    {
        cout << "No complaints submitted yet." << endl;
        return;
    }

    cout << "Users Who Submitted Complaints\n";
    cout << "------------------------------\n";
    cout << "Name\t\tRoll No\n";
    cout << "------------------------------\n";

    for (int i = 0; i < complainIdx; i++)
    {
        for (int j = 0; j < idx; j++)
        {
            if (complainRolls[i] == roll_no[j])
            {
                cout << names[j] << "\t\t" << roll_no[j] << endl;
                break;
            }
        }
        setcl(7);

    }

    string roll;
    cout << "\nEnter Roll No to view complaint (0 to exit): ";
    cin >> roll;

    if (roll == "0")
        return;

    cout << "\nComplaints for Roll No: " << roll << endl;
    cout << "------------------------------\n";

    bool found = false;
    for (int i = 0; i < complainIdx; i++)
    {
        if (complainRolls[i] == roll)
        {
            cout << "- " << complainTexts[i] << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No complaints found for this roll number." << endl;
    }
    saveComplaintsData(complainRolls, complainTexts, complainIdx);
}
void changeUsername(string &uN, string &name, string userNames[], string names[], string userPasswords[], int userCount, int idx, string userRoles[], string roll_no[], string room_no[], int attendance[], string fee_status[], string passwordsForMessUsers[])
{
    setcl(14);
    string currentPass;
    cout << "Enter your current password: ";
    cin >> currentPass;

    int loginIndex = -1;
    for (int i = 0; i < userCount; i++)
    {
        if (userNames[i] == uN && userPasswords[i] == currentPass)
        {
            loginIndex = i;
            break;
        }
    }

    if (loginIndex == -1)
    {
        cout << "Incorrect password!" << endl;
        return;
    }

    string newUsername;
    cout << "Enter new username: ";
    cin >> newUsername;

    for (int i = 0; i < userCount; i++)
    {
        if (userNames[i] == newUsername )
        {
            cout << "Username already exists!" << endl;
            return;
        }
    }

    userNames[loginIndex] = newUsername;

    for (int i = 0; i < idx; i++)
    {
        if (names[i] == name)
        {
            names[i] = newUsername;
            break;
        }
    }

    uN = newUsername;
    name = newUsername;

    cout << "Username changed successfully!" << endl;
    saveLoginUserData(userNames, userPasswords, userRoles, userCount);
    saveMessUserData(names, roll_no, room_no, attendance, fee_status, passwordsForMessUsers, idx);

    setcl(7);
}
// Function to approve or reject admin requests
void admin_approval(string names_admin_approval[], string passwords_admin_approval[], string roles_admin_approval[], int &approval_count, string userNames[], string userPasswords[], string userRoles[], int &userCount)
{
    setcl(14);
    if (approval_count == 0)
    {
        cout << "No pending admin approval requests." << endl;
        return;
    }

    cout << "Pending Admin Requests:" << endl;
    for (int i = 0; i < approval_count; i++)
    {
        cout << i + 1 << ". " << names_admin_approval[i] << endl;
    }

    int choice;
     choice = getValidInteger("Enter the request number to approve (0 to exit): ");

    if (choice == 0)
        return;

    if (choice > 0 && choice <= approval_count)
    {

        string approvalChoice;
        cout << "Are you sure you want to approve the request for " << names_admin_approval[choice - 1] << " (Yes/No)? ";
        cin >> approvalChoice;

        transform(approvalChoice.begin(), approvalChoice.end(), approvalChoice.begin(), ::tolower);

        if (approvalChoice == "yes")
        {
            // Approve the selected admin request
            int index = choice - 1;
            userNames[userCount] = names_admin_approval[index];
            userPasswords[userCount] = passwords_admin_approval[index];
            userRoles[userCount] = "Admin";
            userCount++;

            for (int i = index; i < approval_count - 1; i++)
            {
                names_admin_approval[i] = names_admin_approval[i + 1];
                passwords_admin_approval[i] = passwords_admin_approval[i + 1];
                roles_admin_approval[i] = roles_admin_approval[i + 1];
            }
            approval_count--;

            cout << "Admin request approved successfully!" << endl;
        }
        else if (approvalChoice == "no")
        {
            cout << "Admin request rejected!" << endl;

            int index = choice - 1;
            for (int i = index; i < approval_count - 1; i++)
            {
                names_admin_approval[i] = names_admin_approval[i + 1];
                passwords_admin_approval[i] = passwords_admin_approval[i + 1];
                roles_admin_approval[i] = roles_admin_approval[i + 1];
            }
            approval_count--;
        }
        else
        {
            cout << "Invalid choice. Please enter 'Yes' or 'No'." << endl;
        }
    }
    else
    {
        cout << "Invalid request number." << endl;
    }
    saveAdminApprovalData(names_admin_approval, passwords_admin_approval, roles_admin_approval, approval_count);
  saveLoginUserData(userNames, userPasswords, userRoles, userCount);
    setcl(7);
}
// function that handles whole usermenu
void user_setup(string option, string &uN, string fee, string &name, string roll, string room, int attendance2, string userNames[], string userPasswords[], string passwordsForMessUsers[], int userCount, string names[], int idx, string complainRolls[], string complainTexts[], int &complainIdx, string visitorRequests[], int visitorCounts[], int &visitorIdx, string mess_menu[], string userRoles[], string roll_no[], string fee_status[], int attendance[], string room_no[])
{
    if (option == "1")
    {
        system("cls");
        banner();
        printMenuHeader("User Menu", "Mess Menu");
        o1(mess_menu);
        setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);
        getch();
    }

    else if (option == "2")
    {
        system("cls");
        banner();
        printMenuHeader("User Menu", "Check Bill");
        o2(uN, fee, name, roll, room, attendance2);
        setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);

        getch();
    }

    else if (option == "3")
    {
        system("cls");
        banner();
        printMenuHeader("User Menu", "Complain");

        o3(roll, complainRolls, complainTexts, complainIdx);
        setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);

        getch();
    }

    else if (option == "4")
    {
        system("cls");
        banner();
        printMenuHeader("User Menu", "Change Password");

        changePassword(
            uN, userNames, userPasswords,
            passwordsForMessUsers, names,
            userCount, idx, userRoles, roll_no,
            fee_status, attendance, room_no);
        setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);

        getch();
    }

    else if (option == "5")
    {
        system("cls");
        banner();
        printMenuHeader("User Menu", "Change Username");

        changeUsername(uN, name, userNames, names, userPasswords, userCount, idx, userRoles, roll_no, room_no, attendance, fee_status, passwordsForMessUsers);
        setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);

        getch();
    }

    else if (option == "6")
    {
        system("cls");
        banner();
        printMenuHeader("User Menu", "Visitor Request");

        o4(roll, visitorRequests, visitorCounts, visitorIdx);
        setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);

        getch();
    }
    else if (option != "1" && option != "2" && option != "3" && option != "4" && option != "5" && option != "6" && option != "7")
    {
        system("cls");
        banner();
        gotoxy(34, 5);
        wrong_input();
        getch();
        system("cls");
    }
}
// function that handles all the admin menu
void admin_setup(string option2, string names[], string roll_no[], string room_no[], int attendance[], string fee_status[], string passwordsForMessUsers[], int &idx, string userNames[], string userPasswords[], string userRoles[], int &userCount, string mess_menu[], string complainRolls[], string complainTexts[], int &complainIdx, string visitorRequests[], int visitorCounts[], int &visitorIdx, string names_admin_approval[], string passwords_admin_approval[], string roles_admin_approval[], int &approval_count)
{
    if (option2 == "1")
    {
        system("cls");
        banner();
        printMenuHeader("Admin Menu", "Add Student");

        takeInput(
            names, room_no, roll_no, attendance, fee_status,
            userNames, userPasswords, userRoles,
            passwordsForMessUsers, idx, userCount);
            setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);
        getch();
    }

    else if (option2 == "2")
    {
        system("cls");
        banner();
        printMenuHeader("Admin Menu", "Update Student Information");

        setcl(14);
        u_menu();
        string choice;
        cin >> choice;
        setcl(7);

        if (choice == "1")
            update1(roll_no, names, idx , room_no, fee_status, attendance, passwordsForMessUsers);
        else if (choice == "2")
            update2(roll_no, room_no, idx, names, fee_status, attendance, passwordsForMessUsers);
        else if (choice == "3")
            update3(roll_no, idx , names, room_no, fee_status, attendance, passwordsForMessUsers);
        else if (choice == "4")
            update4(roll_no, fee_status, idx , names, room_no, attendance, passwordsForMessUsers);
        else
        {
            system("cls");
            banner();
            setcl(14);
            cout << "Invalid Option Selected!" << endl;
            setcl(7);
        }
        setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);
        getch();
    }

    else if (option2 == "3")
    {
        system("cls");
        banner();
        printMenuHeader("Admin Menu", "Delete Student");
        
        delete_student(
            names, roll_no, room_no, attendance, fee_status,
            passwordsForMessUsers, idx,
            userNames, userPasswords, userRoles, userCount);
        setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);
        getch();
    }

    else if (option2 == "4")
    {
        system("cls");
        banner();
        printMenuHeader("Admin Menu", "All Students");

        showData(
            names, room_no, roll_no,
            fee_status, attendance, idx);
        setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);
        getch();
    }

    else if (option2 == "5")
    {
        system("cls");
        banner();
        printMenuHeader("Admin Menu", "Update Menu");

        update_menu(mess_menu);
        setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);
        getch();
    }

    else if (option2 == "6")
    {
        system("cls");
        banner();
        printMenuHeader("Admin Menu", "Update Attendance");

        updateAttendance(
            roll_no, attendance, idx, names, room_no, fee_status, passwordsForMessUsers);
        setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);
        getch();
    }

    else if (option2 == "7")
    {
        system("cls");
        banner();
        printMenuHeader("Admin Menu", "View Complaints");

        view_complaints_admin(
            complainRolls, complainTexts, complainIdx,
            names, roll_no, idx);
        setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);
        getch();
    }

    else if (option2 == "8")
    {
        system("cls");
        banner();
        printMenuHeader("Admin Menu", "Visitor Requests");

        view_userreq( 
            visitorRequests, visitorCounts, visitorIdx,
            roll_no, attendance, idx, names, room_no, fee_status, passwordsForMessUsers);
        setcl(14);
        cout << "\nPress any key to return...";
        setcl(7);
        getch();
    }
    else if (option2 == "9")
    {
        system("cls");
        banner();
        printMenuHeader("Admin Menu", "Approve Admin Requests");
        admin_approval(names_admin_approval, passwords_admin_approval, roles_admin_approval, approval_count, userNames, userPasswords, userRoles, userCount);
        setcl(14);
        cout << "\nPress any key to return...";
        getch();
        setcl(7);
    }

    else if (option2 != "1" && option2 != "2" && option2 != "3" && option2 != "4" && option2 != "5" && option2 != "6" && option2 != "7" && option2 != "8" && option2 != "9" && option2 != "10")
    {
        system("cls");
        banner();
        gotoxy(34, 5);
        wrong_input();
        getch();
        system("cls");
    }
}


// Function to safely read an integer with validation
int getValidInteger(string prompt) {
    setcl(14);
    int value;
    while (true) {
        if (!prompt.empty()) {
            cout << prompt;
        }
        
        if (cin >> value) {
            //-----Successfully read an integer
            cin.ignore(1000, '\n');
            return value;
        } else {
            //-------input was not an integer
            cin.clear();
            cin.ignore(1000, '\n'); 
            cout << "Invalid input! "<< endl ;
            cout << " Please enter a valid integer." << endl;
            
        }
    }
    setcl(7);
}

