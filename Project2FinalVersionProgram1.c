/***********************************************************************
 * Project2FinalVersionProgram1.c
 * Final Version for Program 1.
 * Version: Program 1 Final Version: 1.0
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
/* Menu Choice 1 - Enter patients details - list details */
void EnterDetails(void);
/* Check Details are entered correctly Y/N Input */
char YNReturn(void);
/* Encrypt Input */
void Encrypt(char *);
/* Decrypt Input*/
void Decrypt(char *);
/*Save to file*/
void SavetoFile(void);
/*Variables*/
/* The comments explaining each declaration are underneath where
 they would normally be on top */
 char ReadInUserID[5][6];
/* All the user IDs are read from a file and stored so they can
be checked against the ones being entered */
char ReadInUserpass[5][8];
/* All the user passwords are read from a file and stored so they
can be checked against the ones being entered */
char EnterUserID[6];
/* The User ID that gets entered at the start of the porgram to
then check against stored/loaded user ids*/
char EnterUserPass[8];
/* The User Password that gets entered at the start of the program to
then check against stored/loaded passwords */
char FirstName[21];
/* Stores the first name before saving to a file */
char LastName[16];
/* Stores the last name before saving to a file */
char Date[11];
/* Stores the date of birth(DOB) in the format (DD/MM/YYYY) before
saving to a file */
float Height;
/* Stores the height in cm before saving to a file */
float Waist;
/* Stores the waist size measurment in cm before saving to a file */
float Weight;
/* Stores the weight in kgs before saving to a file */
char Comment[256];
/* Stores a comment as an array of characters up to 256 characters
 before saving to a file */
char CorrectDetails;
/* Used to check the user input if the user is happy with all the
details entered. It willl take in one of two values (Y/N) */
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
int main(void){
    LoginTitle();
    Login();
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
    printf("[1] Enter a patient's details.\n"
            "[2] Exit the program.\n"
            "Menu Choice: \n");
    scanf(" %d", &MenuChoice);
    return MenuChoice;
}
/* Menu Choice 1 - Enter patients details - list details */
void EnterDetails(void)
{
    printf("First Name:\n");
    scanf("%s",&FirstName[21]);
    printf("last Name\n");
    scanf("%s",&LastName[16]);
    printf("Date of Birth (DD/MM/YYYY):\n");
    scanf("%s",&Date[11]);
    printf("Height (cm): \n");
    scanf("%f",&Height);
    printf("Waist Measurement (cm): \n");
    scanf("%f",&Waist);
    printf("Weight (kg): \n");
    scanf("%f",&Weight);
    printf("Comment (Optional): \n");
    scanf("%s",&CorrectDetails);
    YNReturn();
}
/* Check Details are entered correctly Y/N Input */
char YNReturn(void)
{
    char MenuChoice;//Local Variable
    printf("==================================================\n"
    "Please check the details entered:\n"
    "==================================================\n"
    "[Y] Yes. All of the details are correct.\n"
    "[N] No. One or more of the details is incorrect.\n"
    "Input: \n");
    scanf(" %c", &MenuChoice);
    return MenuChoice;
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
void SavetoFile(void)
{
    FILE *fptr;
    if((fptr = fopen("agents.txt", "w")) == NULL)
    {
        printf("\nCan't open file agents.txt\n");
        return;
    }
    for(int i = 0; i < 8; i++)
    {

        fprintf(fptr, "%s\n%s\n%s\n%f\n%f\n%f\n%s\n", FirstName[21],
        LastName[16], Date[11], Height, Waist, Weight, Comment[256]);
    }
    fclose(fptr);
    printf("File of records made\n");

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
            "Action on Weight. Nurse's Program.\n"
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
