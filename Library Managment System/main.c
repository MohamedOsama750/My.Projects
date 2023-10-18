#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to store book information
struct Book {
    int id;
    char title[50];
    char author[50];
    int copies;
    int publication_year;
    float price;
};

// Function to add a new book to the library
void addBook(struct Book library[], int *numBooks) {
    if (*numBooks < MAX_BOOKS) {
        struct Book newBook;
        newBook.id = *numBooks + 1;

        printf("Enter book title: ");
        scanf(" %[^\n]", newBook.title);

        printf("Enter author: ");
        scanf(" %[^\n]", newBook.author);

        printf("Enter the number of copies: ");
        scanf("%d", &newBook.copies);

        printf("Enter Publication year: ");
        scanf("%d", &newBook.publication_year);

        printf("Enter price: ");
        scanf("%f", &newBook.price);

        library[*numBooks] = newBook;
        (*numBooks)++;
        printf("Book added successfully.\n");
    } else {
        printf("Library is full. Cannot add more books.\n");
    }
}

// Function to display book information
void displayBooks(struct Book library[], int numBooks) {
    if (numBooks == 0) {
        printf("Library is empty.\n");
    } else {
        printf("Library Books:\n");
        for (int i = 0; i < numBooks; i++) {
            printf("Book ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Copies available: %d\n", library[i].copies);
            printf("Publication year: %d\n", library[i].publication_year);
            printf("Price: %.2f\n", library[i].price);
            printf("\n");
        }
    }
}

// Function to count the number of books in the library
void countBooks(int numBooks) {
    printf("Total number of books in the library: %d\n", numBooks);
}

// Function to borrow a book from the library
void borrowBook(struct Book library[], int *numBooks) {
    int bookID;
    printf("Enter the ID of the book you want to borrow: ");
    scanf("%d", &bookID);

    if (bookID >= 1 && bookID <= *numBooks) {
        if (library[bookID - 1].copies > 0) {
            library[bookID - 1].copies--;
            printf("You have successfully borrowed the book.\n");
        } else {
            printf("Sorry, no copies of this book are available at the moment.\n");
        }
    } else {
        printf("Invalid book ID.\n");
    }
}

// Function to buy a book from the library
void buyBook(struct Book library[], int *numBooks) {
    int bookID;
    printf("Enter the ID of the book you want to buy: ");
    scanf("%d", &bookID);

    if (bookID >= 1 && bookID <= *numBooks) {
        library[bookID - 1].copies++;
        printf("You have successfully bought the book.\n");
    } else {
        printf("Invalid book ID.\n");
    }
}

// Function to delete a book from the library
void deleteBook(struct Book library[], int *numBooks) {
    int bookID;
    printf("Enter the ID of the book you want to delete: ");
    scanf("%d", &bookID);

    if (bookID >= 1 && bookID <= *numBooks) {
        for (int i = bookID - 1; i < *numBooks - 1; i++) {
            library[i] = library[i + 1];
            library[i].id = i + 1;
        }
        (*numBooks)--;
        printf("Book deleted successfully.\n");
    } else {
        printf("Invalid book ID.\n");
    }
}

int main() {
    struct Book library[MAX_BOOKS];
    int numBooks = 0;
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add a book\n");
        printf("2. Display books\n");
        printf("3. Count books\n");
        printf("4. Borrow a book\n");
        printf("5. Buy a book\n");
        printf("6. Delete a book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &numBooks);
                break;
            case 2:
                displayBooks(library, numBooks);
                break;
            case 3:
                countBooks(numBooks);
                break;
            case 4:
                borrowBook(library, &numBooks);
                break;
            case 5:
                buyBook(library, &numBooks);
                break;
            case 6:
                deleteBook(library, &numBooks);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
