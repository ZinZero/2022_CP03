#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

#define ADD 1
#define DELETE 2
#define FIND 3
#define PRINTALL 4
#define QUIT 5

#define NAMEMAX 10
#define PHONEMAX 15

typedef struct Address
{
    char name[NAMEMAX];
    char phone[PHONEMAX];
} Address;


typedef struct AddressBlock
{
    unsigned size;
    Address* book;
    struct AddressBlock* next;
} AddressBlock;

typedef struct AddressBook
{
    unsigned size;
    AddressBlock* head;
} AddressBook;

//function : You should complete the function
void initializeAddressBook(AddressBook* addrbook){}

//function : You should complete the function
void finalizeAddressBook(AddressBook* addrbook){}

//function : You should complete the function
Address* findAddressByName(char* name, AddressBook* addrbook){return NULL;}

//function : You should complete the function
AddressBlock* findMergingTarget(AddressBook* addrbook, AddressBlock* source){return NULL;}

//function : You should complete the function
int addAddress_first(Address* addr, AddressBook* addrbook){return TRUE;}

//function : You should complete the function
int deleteAddressByName(char* name, AddressBook* addrbook){return FALSE;}

int main_menu()
{
    int menu = 0;
    do {
        printf("1. Add an address\n");
        printf("2. Delete an address\n");
        printf("3. Find an address\n");
        printf("4. Print all\n");
        printf("5. Quit\n");
        printf("Select: ");

        scanf("%d", &menu);
    } while (menu < 1 || menu > 5);

    return menu;
}

//function : You should complete the function
void name_menu(char* name)
{
    printf("Type a name: ");
}

//function : You should complete the function
void add_menu(Address* addr)
{
    printf("Type a name: ");
    printf("Type a phone number: ");
}

//function : You should complete the function
//The code below does not print the appropriate results
int main()
{
    int menu = 0;
    AddressBook addrbook;
    Address addr;
    char name[10];

    initializeAddressBook(&addrbook);

    do {
        menu = main_menu();
        printf("\n");

        switch (menu) {
        case ADD:
            add_menu(&addr);
            if (addAddress_first(&addr, &addrbook))
                printf("%s is added successfully!\n", addr.name);
            else
                printf("%s already exists in the book\n", addr.name);
            break;
        case DELETE:
            // fill code!
            if (deleteAddressByName(name, &addrbook))
                printf("{name} is deleted\n");
            else
                printf("{name} does not exist in the book\n");
            break;
        case FIND:
            // fill code!
            Address* p = findAddressByName(name, &addrbook);
            if (p == NULL)
                printf("{name} is not found\n");
            else
                printf("{name}: phone\n");
            break;
        case PRINTALL:
            // fill code!
            printf("{name}: phone\n");
            break;
        }

        if (menu != QUIT) {
            printf("\n");
            printf("---------------------------Providing My AddressBook---------------------------------------\n");

            printf("(Address Book Size: )\n\n");

            for (AddressBlock* p = addrbook.head; p != NULL; p = p->next) 
                printf("block size : {}\n");
			
            printf("------------------------------------------------------------------------------------------\n");
            printf("\n");
           
        }
           
           
    } while (menu != QUIT);

    finalizeAddressBook(&addrbook);

    return 0;
}
