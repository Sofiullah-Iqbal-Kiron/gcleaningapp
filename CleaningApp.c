#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>   // clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h> // sleep()
#include <ctype.h>

#define second 1000

/*
    Clears temp, %temp%, prefetch, recent. Run tree with pyautogui then open CCleaner.
*/

int main()
{
    // Count time lapse
    double time_spent = 0.0;

    printf("Cleaning started at temp, temp2, prefetch and recent.\n\n");

    printf("Cleaning temp...\n");
    {
        clock_t begin = clock();
        system("del /s/q C:\\Windows\\Temp"); // temp
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    printf("\"temp\" cleaned.\n");

    printf("\nCleaning temp2...\n");
    {
        clock_t begin = clock();
        system("del /s/q C:\\Users\\Hp\\AppData\\Local\\Temp"); // %temp%
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    printf("\"temp2\" cleaned.\n");

    printf("\nCleaning prefetch...\n");
    {
        clock_t begin = clock();
        system("del /s/q C:\\Windows\\Prefetch"); // prefetch
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    printf("\"prefetch\" cleaned.\n");

    printf("\nCleaning recent...\n");
    {
        clock_t begin = clock();
        system("del /q C:\\Users\\Hp\\AppData\\Roaming\\Microsoft\\Windows\\Recent"); // recent
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    printf("\"recent\" cleaned.\n");

    printf("\nGarbage folders cleaned in %.4f seconds.\n", time_spent);

    // Wait 1 second after folders clean and then run tree with tree_runner.exe(Created with pyautogui).
    Sleep(second);
    system("tree_runner.exe");
    char run_tree[2];
    printf("\nMake sure:\n1. All of background programs and qbittorrent are closed.\n2. All garbage folders are accessible.\nRuned tree? [Y/N]: ");
    scanf("%c", &run_tree);
    if (tolower(run_tree[0]) == 'y')
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

    return 0;
}