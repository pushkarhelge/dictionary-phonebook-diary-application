#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;

void diary();
void phonebook();
void add_diary();
void add_contact();
void search_diary();
void search_contact();
void delete_diary();
void delete_contact();
void view_all_diaries();
void view_all_contact();
void infomem();
void dictionary();

int main()
{
start:
    system("cls");
    int a;
    system("color FC");
    printf("\t\t\t\t\t    AI-A B2 Group 9\t\t\tDate :%s Time:%s\n\n\n", __DATE__, __TIME__);
    printf("\t1. Dictionary\n\n");
    printf("\t2. Phonebook\n\n");
    printf("\t3. Diary\n\n");
    printf("\t4. Information about member\n\n");
    printf("\t5. Exit");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nEnter your selection : ");
    scanf("%d", &a);
    if (a == 1)
        dictionary();
    if (a == 2)
        phonebook();
    if (a == 3)
        diary();
    if (a == 4)
        infomem();
    if (a == 5)
        return 0;
    goto start;
}

void phonebook()
{
    system("cls");
    system("color F5");
    printf("\t\t\t\t\t          PHONEBOOK\n\n\n");
    printf("\t1. Add contact\n\n");
    printf("\t2. Search contact\n\n");
    printf("\t3. Delete contact\n\n");
    printf("\t4. View all contact\n\n");
    printf("\t5. Go to main menu\n\n");
    printf("\t6. Exit\n\n");
    printf("\n\n\n\n\n\n\n\n\n\nEnter your selection : ");
    int option;
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        add_contact();
        break;
    case 2:
        search_contact();
        break;
    case 3:
        delete_contact();
        break;
    case 4:
        view_all_contact();
        break;
    case 5:
        main();
    case 6:
        exit(0);
    default:
        phonebook();
    }
}

void add_contact()
{
    system("color F6");
    FILE *fp;
    fp = fopen("contact.txt", "a+");
    system("cls");
    printf("\t\t\t\t\t ADD CONTACT");
    printf("\n\n\n\tName : ");
    char name[20];
    scanf("%s", name);
    printf("\n\tSurname : ");
    char sur[20];
    scanf("%s", sur);
    printf("\n\tMobile no. : ");
    long long int mobile;
    scanf("%lld%*c", &mobile);
    if (mobile < 1000000000 || mobile > 9999999999)
    {
        char mo;
        printf("\n\tMobile no. entered is invalid\n\tDo you still want to continue [Y/N] : ");
        scanf("%c", &mo);
        if (mo != 89 && mo != 121)
        {
            printf("\n\tMobile No. : ");
            scanf("%lld%*c", &mobile);
        }
        else
            scanf("%*c");
    }
    char op;
    printf("\n\tAdd more details [Y/N] : ");
    scanf("%c", &op);
    if (op == 89 || op == 121)
    {
        printf("\n\tEmail Id : ");
        char emailid[30];
        scanf("%s", emailid);
        printf("\n\tBirthdate : ");
        char birthd[15];
        scanf("%s", birthd);
        printf("\n\tRelation : ");
        char rel[15];
        scanf("%s", rel);
        fprintf(fp, "%s %s %lld %s %s %s\n", name, sur, mobile, emailid, birthd, rel);
        fclose(fp);
    }
    else
    {
        char emailid[30] = "-------";
        char birthd[15] = "-------";
        char rel[15] = "-------";
        fprintf(fp, "%s %s %lld %s %s %s\n", name, sur, mobile, emailid, birthd, rel);
        fclose(fp);
        printf("\n\n\n\n");
    }
    printf("\n\n\n\n\n\n\n\n\tsaving contact");
    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        printf(".");
    }
    printf("\n\n\tContact Saved Successfully");
    printf("\n\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    phonebook();
}

void search_contact()
{
    system("color F9");
    FILE *fp;
    int a = 1, i = 1;
    fp = fopen("contact.txt", "r");
    system("cls");
    printf("\t\t\t\t\t        SEARCH CONTACT");
    printf("\n\n\n\tEnter Name : ");
    char name[20];
    scanf("%s", name);
    printf("\n\n\tsearching contact");
    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        printf(".");
    }
    char name1[20], sur[20], emailid[30], birthd[15], rel[15];
    long long int mobile;
    while (fscanf(fp, "%s %s %lld %s %s %s\n", name1, sur, &mobile, emailid, birthd, rel) != EOF)
    {
        if (strcmp(name, name1) == 0)
        {
            printf("\n\tName        : %s", name1);
            printf("\n\tSurname     : %s", sur);
            printf("\n\tMobile no.  : %lld", mobile);
            printf("\n\tEmail ID    : %s", emailid);
            printf("\n\tBirthdate   : %s", birthd);
            printf("\n\tRelation    : %s", rel);
            printf("\n\n\n\n\n\n\n\n\n\n");
        }
        else
            a++;
        i++;
    }
    if (a == i)
        printf("\n\n\n\tNo such contact found\n\n\n\n\n\n\n\n\n\n\n\n\n");
    fclose(fp);
    printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    phonebook();
}

void delete_contact()
{
    system("color FA");
    int a = 0, i = 0;
    FILE *fp, *fp1;
    fp = fopen("contact.txt", "r+");
    fp1 = fopen("temp.txt", "w");
    system("cls");
    printf("\t\t\t\t\t        DELETE CONTACT");
    printf("\n\n\n\tEnter Name : ");
    char name[20];
    scanf("%s", name);
    printf("\n\n\tsearching contact");
    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        printf(".");
    }
    char name1[20], sur[20], emailid[30], birthd[15], rel[15];
    long long int mobile;
    while (fscanf(fp, "%s %s %lld %s %s %s\n", name1, sur, &mobile, emailid, birthd, rel) != EOF)
    {
        i++;
        if (strcmp(name, name1) == 0)
        {
            continue;
        }
        fprintf(fp1, "%s %s %lld %s %s %s\n", name1, sur, mobile, emailid, birthd, rel);
        if (strcmp(name, name1) != 0)
            a++;
    }
    fclose(fp);
    fclose(fp1);
    fp = fopen("contact.txt", "w");
    fp1 = fopen("temp.txt", "r");
    while (fscanf(fp1, "%s %s %lld %s %s %s\n", name1, sur, &mobile, emailid, birthd, rel) != EOF)
    {
        fprintf(fp, "%s %s %lld %s %s %s\n", name1, sur, mobile, emailid, birthd, rel);
    }
    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    if (a == i)
        printf("\n\n\n\tNo such contact found\n");
    else
    {
        printf("\n\tcontact found");
        printf("\n\tdeleting contact");
        for (int i = 0; i < 3; i++)
        {
            sleep(1);
            printf(".");
        }
        printf("\n\n\n\tContact deleted Successfully");
    }
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    phonebook();
}

void view_all_contact()
{
    system("color FA");
    FILE *fp;
    int i = 0;
    fp = fopen("contact.txt", "r");
    system("cls");
    printf("\t\t\t\t\t        ALL CONTACTS\n");
    char name1[20], sur[20], emailid[30], birthd[15], rel[15];
    long long int mobile;
    while (fscanf(fp, "%s %s %lld %s %s %s\n", name1, sur, &mobile, emailid, birthd, rel) != EOF)
    {
        printf("\n\n\tName        : %s", name1);
        printf("\n\tSurname     : %s", sur);
        printf("\n\tMobile no.  : %lld", mobile);
        printf("\n\tEmail ID    : %s", emailid);
        printf("\n\tBirthdate   : %s", birthd);
        printf("\n\tRelation    : %s", rel);
        i++;
    }
    printf("\n\n\n\t%d contacts found", i);
    fclose(fp);
    printf("\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    phonebook();
}

struct Trie
{
    bool isEndOfWord;
    unordered_map<char, Trie *> map;
    string meaning;
};

Trie *getNewTrieNode()
{
    Trie *node = new Trie;
    node->isEndOfWord = false;
    return node;
}

void insert(Trie *&root, const string &str,
            const string &meaning)
{
    if (root == NULL)
        root = getNewTrieNode();

    Trie *temp = root;
    for (int i = 0; i < str.length(); i++)
    {
        char x = str[i];

        if (temp->map.find(x) == temp->map.end())
            temp->map[x] = getNewTrieNode();

        temp = temp->map[x];
    }

    temp->isEndOfWord = true;
    temp->meaning = meaning;
}

string getMeaning(Trie *root, const string &word)
{
    if (root == NULL)
        return "";

    Trie *temp = root;

    for (int i = 0; i < word.length(); i++)
    {
        temp = temp->map[word[i]];
        if (temp == NULL)
            return "";
    }

    if (temp->isEndOfWord)
        return temp->meaning;
    return "";
}

Trie *trie = NULL;

void insertD()
{
    system("color F6");
    system("cls");
    printf("\t\t\t\t  DEFINE WORD");
    printf("\n\n\n\tWord : ");
    char word[20];
    scanf("%s", word);
    // std::cin.clear();
    // string meaning;
    printf("\n\n\n\tMeaning : ");
    char meaning[200];
    scanf("%s", meaning);
    // getline(cin, meaning);
    insert(trie, word, meaning);
    printf("\n\n\n\n\n\n\n\n\tdefining word");
    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        printf(".");
    }
    printf("\n\n\tWord defined Successfully");
    printf("\n\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    dictionary();
}

void searchD()
{
    system("color F6");
    system("cls");
    printf("\t\t\t\t  SEARCH WORD");
    printf("\n\n\n\tWord : ");
    char word[20];
    scanf("%s", word);
    cout<<"\n\tMeaning: ";
    cout << "\t" << getMeaning(trie, word);
    printf("\n\n\tPRESS ANY KEY TO CONTINUE");
    getch();
    dictionary();
}

void dictionary()
{
    system("cls");
    system("color FA");
    printf("\t\t\t\t\t          Dictionary\n\n\n");
    printf("\t1. Define meaning\n\n");
    printf("\t2. Search meaning\n\n");
    printf("\t3. Go to main menu\n\n");
    printf("\t4. Exit\n\n");
    printf("\n\n\n\n\n\n\n\n\n\nEnter your selection : ");
    int option;
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        insertD();
        break;
    case 2:
        searchD();
        break;
    case 3:
        main();
    case 4:
        exit(0);
    default:
        dictionary();
    }
}

void diary(){
start:
system("cls");
system("color F1");
printf("\t\t\t\t\t          DIARY\n\n\n");
printf("\t1. Add Diary\n\n");
printf("\t2. View Diary\n\n");
printf("\t3. Delete a Diary\n\n");
printf("\t4. View all diaries\n\n");
printf("\t5. Go to main menu\n\n");
printf("\t6. Exit\n\n");
printf("\n\n\n\n\n\n\n\n\n\nEnter your selection : ");
int option;
scanf("%d",&option);
switch(option)
{
case 1:
add_diary();
break;
case 2:
search_diary();
break;
case 3:
delete_diary();
break;
case 4:
view_all_diaries();
break;
case 5:
main();
case 6:
exit(0);
default:
diary();
}
goto start;
}

void add_diary()
{
system("color F2");
FILE *dp;
dp=fopen("diary.txt","a+");
system ("cls");
printf("\t\t\t\t\t        ADD DIARY");
printf("\n\n\n\tDay         : ");
char day[20];
scanf("%s",day);
printf("\n\tDate        : ");
char date[20];
scanf("%s",date);
printf("\n\tName        : ");
char name[20];
scanf("%s",name);
printf("\n\tDiary Title : ");
char dname[20];
scanf("%s",dname);
printf("\n\tDiary       : ");
char diary[200];
scanf("%s",diary);
fprintf(dp,"%s %s %s %s %s\n",day,date,name,dname,diary);
fclose(dp);
printf("\n\n\n\n\tsaving record");
for(int i=0;i<3;i++){
sleep(1);
printf(".");}
printf("\n\tRecord Saved Successfully ");
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
diary;
}

void search_diary()
{
system("color F3");
FILE *dp;
int a=1,i=1;
dp=fopen("diary.txt","r");
system("cls");
printf("\t\t\t\t\t        SEARCH DIARY");
printf("\n\n\n\tEnter Diary Title : ");
char dname[20];
scanf("%s",dname);
printf("\n\n\tsearching diary");
for(int i=0;i<3;i++){
sleep(1);
printf(".");}
char day[20],date[20],name[20],dname1[20],diary[200];
while(fscanf(dp,"%s %s %s %s %s\n",day,date,name,dname1,diary)!=EOF)
{
if(strcmp(dname,dname1)==0){
printf("\n\n\tDay         : %s",day);
printf("\n\tDate        : %s",date);
printf("\n\tName        : %s",name);
printf("\n\tDiary Title : %s",dname1);
printf("\n\tDiary       : %s",diary);
printf("\n\n");
}
else
a++;
i++;
}
if(a==i)
printf("\n\n\n\tNo such record found\n\n\n\n\n\n");
fclose(dp);
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
diary;
}

void delete_diary()
{
system("color F4");
int a=0,i=0;
FILE *dp,*dp1;
dp=fopen("diary.txt","r+");
dp1=fopen("tmp.txt","w");
system("cls");
printf("\t\t\t\t\t        DELETE DIARY");
printf("\n\n\n\tEnter Diary Title : ");
char dname[20];
scanf("%s",dname);
printf("\n\n\tsearching diary");
for(int i=0;i<3;i++){
sleep(1);
printf(".");}
char day[20],date[20],name[20],dname1[20],diary[200];
while(fscanf(dp,"%s %s %s %s %s\n",day,date,name,dname1,diary)!=EOF)
{
i++;
if(strcmp(dname,dname1)==0)
{
continue;
}
fprintf(dp1,"%s %s %s %s %s\n",day,date,name,dname1,diary);
if(strcmp(dname,dname1)!=0)
a++;
}
fclose(dp);
fclose(dp1);
dp=fopen("diary.txt","w");
dp1=fopen("tmp.txt","r");
while(fscanf(dp1,"%s %s %s %s %s\n",day,date,name,dname1,diary)!=EOF)
{
    fprintf(dp,"%s %s %s %s %s\n",day,date,name,dname1,diary);
}
fclose(dp);
fclose(dp1);
remove("tmp.txt");
if(a==i)
printf("\n\n\n\tNo such diary found");
else{
printf("\n\tdiary found");
printf("\n\n\tdeleting diary");
for(int i=0;i<3;i++){
sleep(1);
printf(".");}
printf("\n\tDiary Deleted Successfully");}
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\tPRESS ANY KEY TO CONTINUE");
getch();
diary;
}

void view_all_diaries()
{
int j=0;
char a[11],b[11];
start:
system("color F5");
FILE *dp;
int i=0,k;
char id[5],pass[11];
char d[5]="psap";
static char s[11]="H9";
dp=fopen("diary.txt","r");
system("cls");
printf("\t\t\t\t\t      ALL DIARIES \n");
if(j==3)
diary();
printf("\n\tEnter Id : ");
scanf("%s",id);
printf("\n\tPassword : ");
scanf("%s",pass);
printf("\n\n\tchecking password");
for(int i=0;i<3;i++){
sleep(1);
printf(".");}
if(strcmp(id,d)==0&&strcmp(pass,s)==0)
{
printf("\n\n\tcorrect password entered");
sleep(1);
system("cls");
printf("\t\t\t\t\t      ALL DIARIES \n");
char day[20],date[20],name[20],dname1[20],diary[200];
while(fscanf(dp,"%s %s %s %s %s\n",day,date,name,dname1,diary)!=EOF)
{
printf("\n\tDay         : %s",day);
printf("\n\tDate        : %s",date);
printf("\n\tName        : %s",name);
printf("\n\tDiary Title : %s",dname1);
printf("\n\tDiary       : %s\n",diary);
i++;
}
printf("\n\n\n\t%d records found",i);
fclose(dp);}
else
{printf("\n\n\tInvalid id or password");
sleep(1);
j++;
goto start;}
printf("\n\n\n\n\n\n\n\tPress 1 to change password or any other number to continue : ");
scanf("%d",&k);
if(k==1){
system("cls");
printf("\t\t\t\t\t   CHANGE PASSWORD");
printf("\n\n\n\tEnter new password       : ");
scanf("%s",a);
printf("\n\tEnter new password again : ");
scanf("%s",b);
if(strcmp(a,b)==0)
{strcpy(s,a);
printf("\n\n\n\n\n\n\n\tPassword Changed Successfully");}
else{
printf("\n\n\n\n\n\n\n\tPasswords don't match");
printf("\n\n\tError occurred during changing password");}
sleep(1);}
else{
diary();
}
}

void infomem()
{
    int a;
    system("cls");
    system("Color FD");
    printf("\t\t\t\t\t  Member\n\n\n");
    printf("\t  1. Chetanya Rathi\n\n");
    printf("\t  2. Harsh Dhabekar\n\n");
    printf("\t  3. Pushkar Helge\n\n");
    printf("\t  4. Harshit Mundhra\n\n");
    printf("\t  5. Kartik Rajput\n\n");
    printf("\t\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nPress any key to go back to main menu ");
    getch();
    main();
}