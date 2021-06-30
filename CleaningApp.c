#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define second 1000

/*
    Clears temp, %temp%, prefetch, recent. Run tree with pyautogui then it opens CCleaner.
*/

int main()
{
    system("del /s/q C:\\Windows\\Temp");                                         // temp
    system("del /s/q C:\\Users\\Hp\\AppData\\Local\\Temp");                       // %temp%
    system("del /s/q C:\\Windows\\Prefetch");                                     // prefetch
    system("del /q C:\\Users\\Hp\\AppData\\Roaming\\Microsoft\\Windows\\Recent"); // recent
    Sleep(second);
    system("tree_runner.exe");
    Sleep(3 * second);
    char run_tree[2];
    printf("\nMake sure:\n1. All of background programs and qbittorrent are closed.\n2. All the folder are accessible.\nRuned tree? [Y/N]: ");
    scanf("%c", &run_tree);
    if (run_tree[0] == 'y' || run_tree[0] == 'Y')
    {
        system("cls");
        printf("Opening CCleaner...");
        system("start ccleaner");
        Sleep(4 * second);
    }
    else
    {
        printf("Please run tree first then start the application again.\n");
        Sleep(3 * second);
        exit(0);
    }
}