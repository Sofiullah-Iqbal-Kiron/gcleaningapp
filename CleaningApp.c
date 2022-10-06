#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>   // clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h> // sleep()
#include <ctype.h>

#define second 1000

/*
    v3: Clears temp, %temp%, prefetch, recent. Run tree with pyautogui then open CCleaner.
    v4: Clears temp, %temp%, prefetch, recent. Run tree by command "start tree" then open CCleaner.
*/

int main()
{
    // Count time lapse
    double time_spent = 0.0;
    char percent_sign = '%';

    printf("Cleaning process started on temp, %ctemp%c, prefetch and recent.\n\n", percent_sign, percent_sign);

    printf("Cleaning \"temp\"...\n");
    {
        clock_t begin = clock();
        system("del /s/q C:\\Windows\\Temp"); // temp
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    printf("[+] \"temp\" cleaned.\n");

    printf("\nCleaning \"%ctemp%c\"...\n", percent_sign, percent_sign);
    {
        clock_t begin = clock();
        system("del /s/q C:\\Users\\Hp\\AppData\\Local\\Temp"); // %temp%
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    printf("[+] \"%ctemp%c\" cleaned.\n", percent_sign, percent_sign);

    printf("\nCleaning \"prefetch\"...\n");
    {
        clock_t begin = clock();
        system("del /s/q C:\\Windows\\Prefetch"); // prefetch
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    printf("[+] \"prefetch\" cleaned.\n");

    printf("\nCleaning \"recent\"...\n");
    {
        clock_t begin = clock();
        system("del /q C:\\Users\\Hp\\AppData\\Roaming\\Microsoft\\Windows\\Recent"); // recent
        clock_t end = clock();
        time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    }
    printf("[+] \"recent\" cleaned.\n");

    printf("\n[+] Garbage folders cleaned in %.4f seconds.\n[+] Running tree...", time_spent);
    system("start tree");
    printf("Yep! Completed.\n");
    // system("start ccleaner");
    // printf("[+] Opening CCleaner...");
    // Sleep(4 * second);
    getch();+

    return 0;
}

// Wait 1 second after folders clean and then run tree with tree_runner.exe(Created with pyautogui).
// Sleep(second);
// system("tree_runner.exe");
// char run_tree[2];
// printf("\nMake sure:\n1. All of background programs and qbittorrent are closed.\n2. All garbage folders are accessible.\nRuned tree? [Y/N]: ");
// scanf("%c", &run_tree);
// if (tolower(run_tree[0]) == 'y')
// {
//     system("cls");
//     printf("Opening CCleaner...");
//     system("start ccleaner");
//     Sleep(4 * second);
// }
// else
// {
//     printf("Please run tree first then start the application again.\n");
//     Sleep(3 * second);
//     exit(0);
// }