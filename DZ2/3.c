#include <stdio.h>

struct student
{
    // local data
    char secondName[12];
    int numberOfGroup;
    // scores
    int informationalSystems;
    int webTechnologies;
    int ukrainianLanguage;
} students[30];

// methods to navigate with structure
void printStudents(int currentNumberOfStudents)
{
    int i;
    printf("\n");
    for (i = 0; i < currentNumberOfStudents; i++)
    {
        printf("\n%d. %s", i, &students[i].secondName);
    }
}

void addStudent(int currentNumberOfStudents)
{
    if (currentNumberOfStudents + 1 == 30)
    {
        printStudents(currentNumberOfStudents);
        printf("\n\nLooks like your number of student is reach maximum number! (30) Select the student to overwrite: ");
        scanf("%d", &currentNumberOfStudents);
    }

    printf("\n\nEnter second name of a student: ");
    scanf("%s", &students[currentNumberOfStudents].secondName);
    while (students[currentNumberOfStudents].numberOfGroup > 4 || students[currentNumberOfStudents].numberOfGroup < 1 || students[currentNumberOfStudents].numberOfGroup == NULL)
    {
        printf("\nEnter number of group of a student (1-4): ");
        scanf("%d", &students[currentNumberOfStudents].numberOfGroup);
        if (students[currentNumberOfStudents].numberOfGroup > 4 || students[currentNumberOfStudents].numberOfGroup < 1)
        {
            printf("\nERROR! MUST ENTER A DIGIT FROM 1 TO 4! TRY AGAIN!");
        }
    }
    printf("\nEnter informational systems score of a student: ");
    scanf("%d", &students[currentNumberOfStudents].informationalSystems);
    printf("\nEnter web-technologies score of a student: ");
    scanf("%d", &students[currentNumberOfStudents].webTechnologies);
    printf("\nEnter ukrainian language score of a student: ");
    scanf("%d", &students[currentNumberOfStudents].ukrainianLanguage);
}

void deleteStudent(int currentNumberOfStudents)
{
    int index;

    printStudents(currentNumberOfStudents);
    while (index == NULL || index > 30 || index < 1)
    {
        printf("\n\nEnter number of student you wants to delete: ");
        scanf("%d", &index);
        if (index < 1 || index > 30)
        {
            printf("ERROR! YOU MUST ENTER NUMBER BETWEEN 1 AND 30! REENTER NUMBER!");
        }
    }

    int i;
    for (i = 0; i < currentNumberOfStudents - 1; i++)
    {
        students[i] = students[i + 1];
    }
}

// methods for ex
void printPenaltyStudents(int currentNumberOfStudents)
{
    int i, j = 0;

    for (i = 0; i < currentNumberOfStudents; i++)
    {
        if (students[i].ukrainianLanguage < 50 || students[i].webTechnologies < 50 || students[i].informationalSystems < 50)
        {
            printf("\n%d. %s;", j, students[i].secondName);
        }
    }
}

void goodStudentsPercentage(int currentNumberOfStudents)
{
    int numb = 0, i;

    for (i = 0; i < currentNumberOfStudents; i++)
    {
        if (students[i].ukrainianLanguage > 70 && students[i].webTechnologies > 70 && students[i].informationalSystems > 70)
        {
            numb++;
        }
    }

    print("\n\n Percentage: %f", (float)numb / currentNumberOfStudents);
}

void bestSubject(int currentNumberOfStudents)
{
    int sumWT = 0, sumUL = 0, sumIS = 0, i;

    for (i = 0; i < currentNumberOfStudents; i++)
    {
        sumWT += students[i].webTechnologies;
        sumUL += students[i].ukrainianLanguage;
        sumIS += students[i].informationalSystems;
    }

    if (sumWT > sumUL && sumWT > sumIS)
    {
        printf("\n\n Best subject is: WEB-TECHNOLOGIES.");
    }
    else if (sumIS > sumWT && sumIS > sumUL)
    {
        printf("\n\n Best subject is: INFORMATIONAL SYSTEMS.");
    }
    else
    {
        printf("\n\n Best subject is: UKRAINIAN LANGUAGE");
    }
}

void worstGroup(int currentNumberOfStudents)
{
    int i, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;

    for (i = 0; i < currentNumberOfStudents; i++)
    {
        if (students[i].numberOfGroup == 1)
        {
            sum1 += students[i].ukrainianLanguage;
            sum1 += students[i].informationalSystems;
            sum1 += students[i].webTechnologies;
        }
        else if (students[i].numberOfGroup == 2)
        {
            sum2 += students[i].ukrainianLanguage;
            sum2 += students[i].informationalSystems;
            sum2 += students[i].webTechnologies;
        }
        else if (students[i].numberOfGroup == 3)
        {
            sum3 += students[i].ukrainianLanguage;
            sum3 += students[i].informationalSystems;
            sum3 += students[i].webTechnologies;
        }
        else
        {
            sum4 += students[i].ukrainianLanguage;
            sum4 += students[i].informationalSystems;
            sum4 += students[i].webTechnologies;
        }
    }

    if (sum1 < sum2 && sum1 < sum3 && sum1 < sum4)
    {
        printf("\n\nWorst group is: FIRST");
    }
    else if (sum2 < sum1 && sum2 < sum3 && sum2 < sum4)
    {
        printf("\n\nWorst group is: SECOND");
    }
    else if (sum3 < sum1 && sum3 < sum2 && sum3 < sum4)
    {
        printf("\n\nWorst group is: THIRD");
    }
    else
    {
        printf("\n\nWorst group is: FOURTH");
    }
}

int main()
{
    int choice, currentNumberOfStudents = 0;

    while (1)
    {
        printf("Choose option:\n1. Add student;\n2. Delete student;\n3. Go to student menu;\n4. Print list of students;\n5. Quit.");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent(currentNumberOfStudents);
            if (currentNumberOfStudents + 1 < 30)
            {
                currentNumberOfStudents++;
            }
            break;
        case 2:
            deleteStudent(currentNumberOfStudents);
            if (currentNumberOfStudents + 1 > 1)
            {
                currentNumberOfStudents--;
            }
            break;
        case 3:
            while (choice != 5)
            {
                printf("\n\nChoose option:\n1. Students with at least one penalty subject;\n2. Percentage of students that score is greater than >70;\n3. Name of subject was completed better than others;\n4. Number of worst group.\n5. Quit;");
                scanf("%d", &choice);

                switch (choice)
                {
                case 1:
                    printPenaltyStudents(currentNumberOfStudents);
                    break;
                case 2:
                    goodStudentsPercentage(currentNumberOfStudents);
                    break;
                case 3:
                    bestSubject(currentNumberOfStudents);
                    break;
                case 4:
                    worstGroup(currentNumberOfStudents);
                    break;
                case 5:
                    break;
                default:
                    printf("Entered wrong command! Try again!");
                    break;
                }
            }
            break;
        case 4:
            printStudents(currentNumberOfStudents);
            break;
        case 5:
            exit(-1);
        default:
            printf("Entered wrong command! Try again!");
        }
    }
}