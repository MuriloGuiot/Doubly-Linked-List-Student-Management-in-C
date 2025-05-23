﻿# Doubly-Linked-List-Student-Management-in-C
This project implements a flexible, menu-driven student record manager in pure C, backed by a doubly-linked list. It demonstrates core dynamic-memory and pointer concepts while providing a simple console UI for:

Creating and destroying the list

Inserting a student at the front, back, or in ascending order of matriculation number

Removing a student from the front, back, or by specific matriculation number

Searching for a student by position or by matriculation number

Swapping two student records in the list

Printing the entire roster or a single student’s details

Automated grade handling: validates scores, calculates the arithmetic mean, and assigns a pass/fail status

Key Features
Doubly-Linked Nodes
Each node stores pointers to both the previous and next elements, enabling efficient insertion and removal in any position.

Robust Input Validation

Ensures non-negative and ≤10 grade values

Rejects invalid menu options and prompts the user to retry

Clear Console UI

Color-coded output for failed students (red text)

Dynamic “Tamanho” (size) and “Lista Vazia” (empty-check) indicators after each operation

Interactive menu with options to insert, remove, search, swap, print, and bulk-load sample data

Modular Design

ListaDinEncadeadaDupla.h declares all list and student-management functions

ListaDinEncadeadaDupla.c implements list logic—memory allocation, pointer adjustments, and node traversal

main.c drives the user menu and demonstrates all operations

Sample Data Loader
A built-in function populates the list with ten predefined students, showcasing bulk insertion and media calculation.
