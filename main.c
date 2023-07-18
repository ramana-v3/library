/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

// Structure to represent a book
typedef struct {
    int bookId;
    char title[50];
    char author[50];
} Book;

// Function to add a book
void addBook(Book *books, int *numBooks) {
    Book newBook;
    printf("Enter book ID: ");
    scanf("%d", &newBook.bookId);
    printf("Enter book title: ");
    scanf(" %[^\n]s", newBook.title);
    printf("Enter book author: ");
    scanf(" %[^\n]s", newBook.author);

    books[*numBooks] = newBook;
    (*numBooks)++;
    printf("Book added successfully.\n");
}

// Function to search for a book by title
void searchBookByTitle(const Book *books, int numBooks, const char *title) {
    int found = 0;
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(books[i].title, title) == 0) {
            printf("Book ID: %d\n", books[i].bookId);
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            found = 1;
        }
    }

    if (!found) {
        printf("No books found with the given title.\n");
    }
}

// Main function
int main() {
    Book books[100];    // Array to store books
    int numBooks = 0;   // Number of books in the array
    int choice;

    do {
        printf("\n======= Library Management System =======\n");
        printf("1. Add Book\n");
        printf("2. Search Book by Title\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &numBooks);
                break;
            case 2: {
                char searchTitle[50];
                printf("Enter the title to search: ");
                scanf(" %[^\n]s", searchTitle);
                searchBookByTitle(books, numBooks, searchTitle);
                break;
            }
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}