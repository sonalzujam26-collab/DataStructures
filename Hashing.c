/* Telephone Book Hash Table
   Compatible with Turbo C
   Supports:
    - Linear probing
    - Quadratic probing
    - Double hashing
   Author: (example)
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 101   /* choose a prime table size for better hashing */
#define MAX_NAME 40
#define MAX_PHONE 20

/* status codes for each slot */
#define EMPTY 0
#define OCCUPIED 1
#define DELETED 2

typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    int status; /* EMPTY, OCCUPIED, DELETED */
} Entry;

Entry table[TABLE_SIZE];

/* Initialize table */
void init_table() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        table[i].status = EMPTY;
        table[i].name[0] = '\0';
        table[i].phone[0] = '\0';
    }
}

/* Simple primary hash: sum of chars mod TABLE_SIZE */
int hash1(const char *key) {
    unsigned int sum = 0;
    while (*key) {
        sum = sum + (unsigned char)(*key);
        key++;
    }
    return sum % TABLE_SIZE;
}

/* Secondary hash for double hashing:
   Use a prime smaller than TABLE_SIZE, e.g., 97 or 89.
   Ensure it never returns 0.
*/
int hash2(const char *key) {
    unsigned int sum = 0;
    const int R = 97; /* should be < TABLE_SIZE and preferably prime */
    while (*key) {
        sum = sum + (unsigned char)(*key);
        key++;
    }
    int h = R - (sum % R);
    if (h == 0) h = 1;
    return h;
}

/* Utility to read a line (Turbo C friendly) */
void read_line(char *buffer, int size) {
    int i=0, ch;
    /* Flush leftover newline in stdin */
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch == '\r') break;
    }
    /* Now read the actual line */
    i = 0;
    while (i < size - 1) {
        ch = getchar();
        if (ch == EOF || ch == '\n' || ch == '\r') break;
        buffer[i++] = (char)ch;
    }
    buffer[i] = '\0';
}

/* Insert using linear probing */
int insert_linear(const char *name, const char *phone) {
    int h = hash1(name);
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        int idx = (h + i) % TABLE_SIZE;
        if (table[idx].status == EMPTY || table[idx].status == DELETED) {
            strncpy(table[idx].name, name, MAX_NAME-1);
            table[idx].name[MAX_NAME-1] = '\0';
            strncpy(table[idx].phone, phone, MAX_PHONE-1);
            table[idx].phone[MAX_PHONE-1] = '\0';
            table[idx].status = OCCUPIED;
            return idx; /* success return index */
        }
    }
    return -1; /* table full */
}

/* Insert using quadratic probing (c1=1, c2=3 for example) */
int insert_quadratic(const char *name, const char *phone) {
    int h = hash1(name);
    int i;
    int c1 = 1, c2 = 3;
    for (i = 0; i < TABLE_SIZE; i++) {
        int idx = (h + c1 * i + c2 * i * i) % TABLE_SIZE;
        if (idx < 0) idx += TABLE_SIZE;
        if (table[idx].status == EMPTY || table[idx].status == DELETED) {
            strncpy(table[idx].name, name, MAX_NAME-1);
            table[idx].name[MAX_NAME-1] = '\0';
            strncpy(table[idx].phone, phone, MAX_PHONE-1);
            table[idx].phone[MAX_PHONE-1] = '\0';
            table[idx].status = OCCUPIED;
            return idx;
        }
    }
    return -1;
}

/* Insert using double hashing */
int insert_double(const char *name, const char *phone) {
    int h1 = hash1(name);
    int h2 = hash2(name);
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        int idx = (h1 + i * h2) % TABLE_SIZE;
        if (idx < 0) idx += TABLE_SIZE;
        if (table[idx].status == EMPTY || table[idx].status == DELETED) {
            strncpy(table[idx].name, name, MAX_NAME-1);
            table[idx].name[MAX_NAME-1] = '\0';
            strncpy(table[idx].phone, phone, MAX_PHONE-1);
            table[idx].phone[MAX_PHONE-1] = '\0';
            table[idx].status = OCCUPIED;
            return idx;
        }
    }
    return -1;
}

/* Search (returns index or -1) for each method */
int search_linear(const char *name) {
    int h = hash1(name);
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        int idx = (h + i) % TABLE_SIZE;
        if (table[idx].status == EMPTY) return -1; /* not found, empty stops probe */
        if (table[idx].status == OCCUPIED && strcmp(table[idx].name, name) == 0)
            return idx;
        /* continue if DELETED or name mismatch */
    }
    return -1;
}

int search_quadratic(const char *name) {
    int h = hash1(name);
    int i;
    int c1 = 1, c2 = 3;
    for (i = 0; i < TABLE_SIZE; i++) {
        int idx = (h + c1 * i + c2 * i * i) % TABLE_SIZE;
        if (idx < 0) idx += TABLE_SIZE;
        if (table[idx].status == EMPTY) return -1;
        if (table[idx].status == OCCUPIED && strcmp(table[idx].name, name) == 0)
            return idx;
    }
    return -1;
}

int search_double(const char *name) {
    int h1 = hash1(name);
    int h2 = hash2(name);
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        int idx = (h1 + i * h2) % TABLE_SIZE;
        if (idx < 0) idx += TABLE_SIZE;
        if (table[idx].status == EMPTY) return -1;
        if (table[idx].status == OCCUPIED && strcmp(table[idx].name, name) == 0)
            return idx;
    }
    return -1;
}

/* Delete entry (mark as DELETED) for each method */
int delete_linear(const char *name) {
    int idx = search_linear(name);
    if (idx >= 0) {
        table[idx].status = DELETED;
        table[idx].name[0] = '\0';
        table[idx].phone[0] = '\0';
        return idx;
    }
    return -1;
}
int delete_quadratic(const char *name) {
    int idx = search_quadratic(name);
    if (idx >= 0) {
        table[idx].status = DELETED;
        table[idx].name[0] = '\0';
        table[idx].phone[0] = '\0';
        return idx;
    }
    return -1;
}
int delete_double(const char *name) {
    int idx = search_double(name);
    if (idx >= 0) {
        table[idx].status = DELETED;
        table[idx].name[0] = '\0';
        table[idx].phone[0] = '\0';
        return idx;
    }
    return -1;
}

/* Display table contents */
void display_table() {
    int i;
    printf("\nIndex\tStatus\tName\t\tPhone\n");
    printf("-----\t------\t----\t\t-----\n");
    for (i = 0; i < TABLE_SIZE; i++) {
        printf("%d\t", i);
        if (table[i].status == EMPTY) {
            printf("EMPTY\t-\t\t-\n");
        } else if (table[i].status == DELETED) {
            printf("DELETED\t-\t\t-\n");
        } else {
            printf("OCC\t%s\t\t%s\n", table[i].name, table[i].phone);
        }
    }
}

/* Main menu and program */
void main_menu() {
    int choice, method;
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    int res;
    while (1) {
        clrscr();
        printf("Telephone Book Hash Table (TABLE_SIZE=%d)\n", TABLE_SIZE);
        printf("Choose collision handling technique:\n");
        printf("1. Linear Probing\n");
        printf("2. Quadratic Probing\n");
        printf("3. Double Hashing\n");
        printf("4. Exit Program\n");
        printf("Enter choice: ");
        scanf("%d", &method);
        if (method == 4) break;
        while (1) {
            clrscr();
            printf("Technique: %s\n",
                (method==1) ? "Linear" : (method==2) ? "Quadratic" : "Double Hashing");
            printf("1. Insert a client\n");
            printf("2. Search a client\n");
            printf("3. Delete a client\n");
            printf("4. Display table\n");
            printf("5. Change technique / Back\n");
            printf("Enter choice: ");
            scanf("%d", &choice);
            if (choice == 5) break;
            switch (choice) {
                case 1:
                    printf("\nEnter name: ");
                    read_line(name, MAX_NAME);
                    if (strlen(name) == 0) { printf("Name cannot be empty.\n"); getch(); break; }
                    printf("Enter phone: ");
                    read_line(phone, MAX_PHONE);
                    if (strlen(phone) == 0) { printf("Phone cannot be empty.\n"); getch(); break; }
                    if (method == 1) res = insert_linear(name, phone);
                    else if (method == 2) res = insert_quadratic(name, phone);
                    else res = insert_double(name, phone);

                    if (res >= 0) {
                        printf("Inserted at index %d.\n", res);
                    } else {
                        printf("Insertion failed: table full.\n");
                    }
                    getch();
                    break;

                case 2:
                    printf("\nEnter name to search: ");
                    read_line(name, MAX_NAME);
                    if (method == 1) res = search_linear(name);
                    else if (method == 2) res = search_quadratic(name);
                    else res = search_double(name);

                    if (res >= 0) {
                        printf("Found at index %d.\nName: %s\nPhone: %s\n", res, table[res].name, table[res].phone);
                    } else {
                        printf("Not found.\n");
                    }
                    getch();
                    break;

                case 3:
                    printf("\nEnter name to delete: ");
                    read_line(name, MAX_NAME);
                    if (method == 1) res = delete_linear(name);
                    else if (method == 2) res = delete_quadratic(name);
                    else res = delete_double(name);
                    if (res >= 0) {
                        printf("Deleted entry at index %d.\n", res);
                    } else {
                        printf("Name not found; cannot delete.\n");
                    }
                    getch();
                    break;

                case 4:
                    display_table();
                    printf("\nPress any key to continue...");
                    getch();
                    break;

                default:
                    printf("Invalid choice.\n");
                    getch();
            } /* end switch */
        } /* end inner while */
    } /* end outer while */
}

/* Program entry */
void main() {
    init_table();
    clrscr();
    printf("Telephone Book Hash Table\n");
    printf("Table size set to %d. Press any key to continue...\n", TABLE_SIZE);
    getch();
    main_menu();
    clrscr();
    printf("Exiting program. Press any key.\n");
    getch();
}
