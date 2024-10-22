/***********************************************************************
 * Project2FinalVersionProgram2.c
 * Final Version for Program 2.
 * Version: Program 2 Final Version: 1.0
 **********************************************************************/
/* Pre-Processor Directive */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Constants*/
const int SHIFT = 7;
/* Function Prototypes */
void EmptyBuffer(void);
void MainTitleDisplay(void);
void ClearConsole(void);
/* Get usernames and passwords from file - load to memory*/
FILE *LoadUandPFromFile(void);
/* Enter Username and Password Title  */
void LoginTitle(void);
/* Username and Password Check */
void Login(void);
/* Main Menu choice - number corresponding to menu - title*/
void MainMenuTitle(void);
/* Main Menu - number corresponding to menu - Menu Choice Input*/
int MainMenu(void);
/* Menu Choice 1 Enter patients last name and birth title display*/
void LastNameandDOBEnter(void);
/* Menu Choice 1 No users found - User input Y/N */
char YNReturn(void);
/* Menu Choice 1 Change a patients comment - title   */
void PatientCommentTitle(void);
/* Menu Choice 1 Change a patients comment - new comment */
void NewCommentandDisplay(void);
/* Menu Choice 2 -edit a nurse -name,id,password - title  */
void EditIDorPassTitle(void);
/* Menu Choice 2 -edit a nurse-name,id,password-display and input */
int EditIDorPassMenu(void);
/* Menu Choice 2-0 Add nurse title */
void AddNurseTitle(void);
/* Menu choice 2-0 Input */
void AddNurseNewDetails(void);
/* Menu choice 2-other Name title  */
void DisplayNurseEditTitle(void);
/* Menu chocie 2-other Input */
int EditIDorPassSubMenu(void);
/* Menu choice 2-other-editID- title*/
void EditIDDisplay(void);
/* Menu choice 2-other-editID- Input*/
void EnterNewID(void);
/* Menu choice 2-other-editPassword- title */
void EditPassDisplay(void);
/* Menu choice 2-other-editPassword- Input */
void EnterNewPass(void);
/* Encrypt Input */
void Encrypt(char *);
/* Decrypt Input*/
void Decrypt(char *);
/*Variables*/
/* The comments explaining each declaration are underneath where
 they would normally be on top */
char EnterUserID[6];
/* The User ID that gets entered at the start of the porgram to
then check against stored/loaded user ids*/
char EnterUserPass[8];
/* The User Password that gets entered at the start of the program to
then check against stored/loaded passwords */
char ConsultantID[6];
/* Stores the consultants user ID to check the login against */
char ConsultantPass[8];
/* Stores the consultants password to check the login against */
int MenuChoice;
/* This stores the value the user has entered when they are in the
main menu screen to see what they would like to do */
char LastNameCheck[16];
/* Stores the value the user entered to then check against the names
loaded to see if it is one of them */
char DateCheck[11];
/* Stores the values the user entered to the check against the date of
births loaded to see if it is one of them*/
char ReadInUserID[5][6];
/* All the user IDs are read from a file and stored so they can
 be checked against the ones being entered */
char ReadInUserpass[5][8];
/* All the user passwords are read from a file and stored so they can
 be checked against the ones being entered */
char ReturnMenuCheck;
/* Used to check if the user would like to return to the main menu or
if they would like to re-enter the last name and date of birth */
char FirstName[21];
/* The first name that is getting displayed*/
char LastName[16];
/* The last name that is getting displayed*/
char Date[11];
/* The DOB that is getting displayed */
float Height;
/* The height that is getting displayed */
float Waist;
/* The waist size that is getting displayed */
float Weight;
/* The weight that will get displayed */
char Comment[256];
/* The comment that will get dislayed */
char EditCommentCheck;
/* Used to check if the consultant wants to edit the patients comment
in the form of (Y/N) */
char NewComment[256];
/* The new comment the consultant wants to write */
int EditNurseMenuCoice;
/* This is the mneu choice for the second menu option where the user
can choose a nurses name or to add a new nurse by entering a value
corrisponding to the display */
int NurseSubMenuChoice;
/* The sub-menu choice for wen the user wants to choose between edit
id and edit password */
char NewID[6];
/* Takes in the New ID  */
char NewPassword[8];
/* Takes in the New Password */
char DataToEncrypt;
char DataToDecrypt;
/*Structures*/
struct ReadInData
{
    char ReadInUserID[5][6];
    /* All the user IDs are read from a file and stored so they can
     be checked against the ones being entered */
    char ReadInUserpass[5][8];
    /* All the user passwords are read from a file and stored so they
    can be checked against the ones being entered */
};
/* Main */
int main(void)
{
    LoginTitle();
    return 0;
}
/* Get usernames and passwords from file - load to memory*/
FILE *LoadUandPFromFile(void)
{
    FILE *fp = fopen("NurseUserIDandPass.txt", "r");
    if(!fp)
    {
        puts("File: NurseUserIDandPass.txt was unable to be opened");
        exit(1);
    }
    return fp;
}
int DataToArray(FILE *fp, struct ReadInData arr[])
{
    int count = 0;
    while(fscanf(fp, "%24[^:]:%d\n", arr[count].ReadInUserID,
                &arr[count].ReadInUserpass) == 5)
    {
        count++;
    }
    return count;
}
/* Enter Username and Password Title  */
void LoginTitle(void)
{
    printf("Enter your username and password:\n"
            "==================================================\n");
    Login();
}
/* Username and Password Check */
void Login(void)
{
    printf("Username:");
    scanf("%s",&EnterUserID[6]);
    printf("Password:");
    scanf("%s",&EnterUserPass[8]);

    if(EnterUserID[6] == ReadInUserID[5][6] &&
        EnterUserPass[8] == ReadInUserpass[5][8])
    {
        MainMenuTitle();
    }else{
        printf("==================================================\n");
        printf("Error: Incorrect Username or Password."
        "Please try again:\n");
        printf("==================================================\n");
        Login();
    }
}
/* Main Menu choice - number corresponding to menu - title*/
void MainMenuTitle(void)
{
    ClearConsole();
    MainTitleDisplay();
    printf("Enter the number corresponding to the menu choice.\n"
            "==================================================\n");
    MainMenu();
}
/* Main Menu - number corresponding to menu - Menu Choice Input*/
int MainMenu(void)
{
    int MenuChoice;//Local Variable
    printf("[1] Display a patient's details.\n"
            "[2] Edit a Nurse.\n"
            "[3] Exit the program.\n");
    scanf("Input: %d", &MenuChoice);
    return MenuChoice;
}
/* Menu Choice 1 Enter patients last name and birth title display*/
void LastNameandDOBEnter(void)
{
    printf("Last name:");
    scanf("%s\n",&LastNameCheck[16]);
    printf("Date of Birth (DD/MM/YYYY): ");
    scanf("%s\n",&DateCheck[11]);
}
/* Menu Choice 1 No users found - User input Y/N */
char YNReturn(void)
{
    char MenuChoice;//Local Variable
    printf("==================================================\n"
    "Would you like to return to the main menu.:\n"
    "==================================================\n"
    "[Y] Yes. Return to the main menu.\n"
    "[N] No. Re-enter a last name and date of birth.\n"
    "Input: \n");
    scanf(" %c", &MenuChoice);
    return MenuChoice;
}
/* Menu Choice 1 Display paitents details - Y/N  edit section */

/* Menu Choice 1 Change a patients comment - title   */
void PatientCommentTitle(void)
{
    printf("Change a patients comment.\n"
            "==================================================\n");
    NewCommentandDisplay();
}
/* Menu Choice 1 Change a patients comment - new comment */
void NewCommentandDisplay(void)
{
    printf("\nCurrent User: %s",ReadInUserID[5][6] );
    printf("\nName: %s %s.",FirstName[21], LastName[16]);
    printf("\nData of birth: %s", Date[11]);
    printf("\nCurrent Comment: %s", Comment[256]);
    scanf("\nNew comment: %s",NewComment[256]);
    Comment[256] = NewComment[256];
}
/* Menu Choice 2 -edit a nurse -name,id,password - title  */
void EditIDorPassTitle(void)
{
    printf("Edit a ID or Password. Please choose a number.\n"
            "==================================================\n");
    EditIDorPassMenu();
}
/* Menu Choice 2 -edit a nurse-name,id,password-display and input */
int EditIDorPassMenu(void)
{
    int MenuChoice;//Local Variable
    printf("");
    printf("==================================================");
    printf("[1] Edit ID.\n"
            "[2] Edit Password.\n"
            "Input:");
    scanf("%d\n", &MenuChoice);
    return MenuChoice;
}
/* Menu Choice 2-0 Add nurse title */
void AddNurseTitle(void)
{
    printf("[0] Add a Nurse\n"
            "==================================================\n");
    AddNurseNewDetails();
}
/* Menu choice 2-0 Input */
void AddNurseNewDetails(void)
{
    printf("Enter New ID: ");
    scanf("%s\n",&NewID[6]);
    printf("Enter Password ID: ");
    scanf("%s\n",&NewPassword[8]);
}
/* Menu choice 2-other Name title  */
void DisplayNurseEditTitle(void)
{
    printf("Edit a Nurse's ID or password.\n"
            "==================================================\n");
    EditIDorPassSubMenu();
}
/* Menu chocie 2-other Input */
int EditIDorPassSubMenu(void)
{
   int MenuChoice;//Local Variable
    printf("[1] Edit ID.\n"
            "[2] Edit Password.\n"
            "Input:\n");
    scanf(" %d", &MenuChoice);
    return MenuChoice;
}
/* Menu choice 2-other-editID- title*/
void EditIDDisplay(void)
{
    printf("[1] Edit ID.\n"
            "==================================================\n");
    EnterNewID();
}
/* Menu choice 2-other-editID- Input*/
void EnterNewID(void)
{
    printf("Current ID: %s\n",EnterUserID[6]);
    printf("Enter new password: \n");
    scanf("%s",&NewID[6]);
    printf("ID Changed Successfully.\n");
    EnterUserID[6] =NewID[6];
}
/* Menu choice 2-other-editPassword- title */
void EditPassDisplay(void)
{
    printf("[2] Edit Password.\n"
            "==================================================\n");
    EnterNewPass();
}
/* Menu choice 2-other-editPassword- Input */
void EnterNewPass(void)
{
    printf("Current Password: %s\n",EnterUserPass[8]);
    printf("Enter new password: \n");
    scanf("%s",&NewPassword[8]);
    printf("Password Changed Successfully.\n");
    EnterUserPass[8] = NewPassword[8];
}
/* Encrypt Input */
void Encrypt(char *DataToEncrypt)
{
    for (int i = 0; i < strlen(DataToEncrypt); i++)
    {
    DataToEncrypt[i] = DataToEncrypt[i] + SHIFT;
    }
    printf("Encrypted data that is being saved to a file: %s\n",
             DataToEncrypt);
}
/* Decrypt Input*/
void Decrypt(char *DataToDecrypt)
{
    for (int i = 0; i < strlen(DataToDecrypt); i++)
    {
    DataToDecrypt[i] = DataToDecrypt[i] - SHIFT;
    }
    printf("Decrypted data being read from the file: %s\n",
            DataToDecrypt);
}
/* Clears the console */
void ClearConsole(void)
{
    getchar();
    system("cls");
}
/* Displays the main title */
void MainTitleDisplay(void)
{
    printf("==============================================\n"
            "Action on Weight. Consultant's Program.\n"
            "==============================================\n");
}
/* Empty the keyboard buffer */
void EmptyBuffer(void)
{
    while(getchar() != '\n')
    {
        ;
    }
}
