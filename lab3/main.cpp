#include <iostream>
#include <cmath>
#include "ComplexNumbers.hpp"
#include "Person.hpp"
#include "Tree.hpp"
#include "Tests.hpp"
int main() {
    std::string byPass[6] = {"LeftRootRight",
                             "RightLeftRoot",
                             "RightRootLeft",
                             "LeftRightRoot",
                             "RootRightLeft",
                             "RootLeftRight"
                             };
    while (true){
        char c[5] = {'\0','\0','\0','\0','\0'};
    Back1:
        //----------------------------back1
        printf("\n            Welcome!\n"
               "1 - Int\n"
               "2 - class Complex\n"
               "3 - class Person\n"
               "4 - Test menu\n"
               "5 - About the program\n"
               "6 - Exit\n");
        cin >> c[0];
        getchar();
        if (c[0] == '1'){
            Tree<int> A;
            printf("\n\nYou should create a tree\n"
            "Add N element (N - Number of elements)\n");
            int N;
            cin >> N;
            getchar();
            for (int i = 0; i < N; ++i){
                int elem;
                cin >> elem;
                A.add(elem);
            }
            cout << endl;
            A.Print(byPass[5]);
            cout << endl;
        Repeat1:
            printf("1 - map (quad)\n"
                   "2 - where (All elements < 0)\n"
                   "3 - merger\n"
                   "4 - search element of tree\n"
                   "5 - Show a tree\n"
                   "6 - Filing\n"
                   "7 - Back\n"
                   "0 - Exit\n");
            char key1;
            cin >> key1;
            getchar();
            if (key1 == '1'){
                Tree<int> B;
                A.map(quadInt, B);
                B.Print(byPass[5]);
                goto Repeat1;
            }
            else if (key1 == '2'){
                Tree<int> B;
                A.where(onlyNegativeIntNum, B);
                B.Print(byPass[5]);
                goto Repeat1;
            }
            else if (key1 == '3'){
                Tree<int> B;
                int N;
                printf("You should create a second tree\n"
                       "Add N elements. Enter N: ");
                cin >> N;
                getchar();
                for (int i = 0; i < N; ++i){
                    int elem;
                    cin >> elem;
                    B.add(elem);
                }
                B.merge(A);
                cout << endl;
                A.Print(byPass[5]);
                goto Repeat1;
            }
            else if (key1 == '4'){
                int elem;
                printf("Eneter element which you want to find\n"
                        "elem");
                cin>>elem;
                getchar();
                if (A.searchElement(elem) == true){
                    cout << "YES!" << endl;
                }
                else{
                    cout << "NO!" << endl;
                    goto Repeat1;
                }
            }
            else if (key1 == '5'){
                cout << "        Tree\n\n" << endl << endl << "       ";
                A.Print(byPass[5]);
                cout << endl << endl;
                goto Repeat1;
            }
            else if (key1 == '6'){
                int elem;
                printf("Eneter element which you want to find\n"
                       "elem");
                cin>>elem;
                getchar();
                A.add(elem);
                goto Repeat1;
            }
            else if (key1 == '7'){
                //A.freetree_el();
                cout << endl;
                goto Back1;
            }
            else if (key1 == '0'){
                return false;
            }
            else{
                cout << "Try again" << endl;
                goto Repeat1;
            }
        }
        else if (c[0] == '2'){
            Tree <Complex> A;
            printf("\n\nYou should create a tree"
            "Add N elements.\nEnter N: ");
            int N;
            cin >> N;
            getchar();
            for (int i = 0; i < N; ++i){
                Complex elem;
                cin >> elem;
                A.add(elem);
            }
            cout << endl;
            A.Print(byPass[5]);
            cout << endl;
        Repeat2:
            printf("1 - map (quad)\n"
                    "2 - where\n"
                    "3 - merger\n"
                    "4 - search element\n"
                    "5 - Show a tree\n"
                    "6 - Filing\n"
                    "7 - Back\n"
                    "0 - Exit\n");
            char key1;
            cin >> key1;
            getchar();
            if (key1 == '1'){
                Tree <Complex> B;
                A.map(quadCmplx,B);
                B.Print(byPass[5]);
                goto Repeat2;
            }
            else if (key1 == '2'){
                Tree <Complex> B1;
                A.where(CmplxNum, B1);
                B1.Print(byPass[5]);
                goto Repeat2;
            }
            else if (key1 == '3'){
                printf("You should create a second tree\n"
                       "Add N elements. Enter N: ");
                Tree <Complex> B;
                int N;
                cin >> N;
                getchar();
                for (int i = 0; i < N; ++i){
                    Complex elem;
                    cin >> elem;
                    B.add(elem);
                }
                B.merge(A);
                cout << endl;
                A.Print(byPass[5]);
                goto Repeat2;
            }
            else if (key1 == '4'){
                printf("Enter the element\n");
                Complex elem;
                cin >> elem;
                if (A.searchElement(elem) == true){
                    cout << "YES!" << endl;
                }
                else{
                    cout << "NO!" << endl;
                }
                goto Repeat2;
            }
            else if (key1 == '5'){
                printf("        Tree\n\n       ");
                A.Print(byPass[5]);
                cout << endl << endl;
                goto Repeat2;
            }
            else if (key1 == '6'){
                printf("Enter the element\n");
                Complex elem;
                cin >> elem;
                getchar();
                A.add(elem);
                goto Repeat2;
            }
            else if (key1 == '7'){
                A.~Tree();
                cout << endl;
                goto Back1;
            }
            else if (key1 == '0'){
                return false;
            }
            else{
                cout << "Try again" << endl;
                goto Repeat2;
            }
        }
        else if (c[0] == '3'){
            Tree <Person> A;
            printf("\n\nYou should create a tree\n"
                   "Add N elements.\nEnter N: ");
            int N;
            cin >> N;
            getchar();
            for (int i = 0; i < N; ++i){
                Person elem;
                cin >> elem;
                getchar();
                A.add(elem);
            }
            cout << endl;
            A.Print(byPass[5]);
            cout << endl;
            Repeat3:
            printf("\n1 - map (F(str) = str.substr(1, 3))\n"
                   "2 - merger\n"
                   "3 - where (All elemets)"
                   "4 - search element\n"
                   "5 - Show a tree\n"
                   "6 - Filing\n"
                   "7 - Back\n"
                   "0 - Exit\n");
            cin >> c[1];
            getchar();
            if (c[1] == '1'){
                Tree<Person> B;
                A.map(quadPerson,B);
                B.Print(byPass[5]);
                B.~Tree();
                goto Repeat3;
            }
            else if (c[1] == '2'){
                cout << endl << "You should create a second tree" << endl;
                cout << "Add N elements.\nEnter N: ";
                Tree<Person> B;
                int N;
                cin >> N;
                getchar();
                for (int i = 0; i < N; ++i){
                    Person elem;
                    cin >> elem;
                    B.add(elem);
                }
                B.merge(A);
                cout << endl;
                A.Print(byPass[5]);
                goto Repeat3;
            }
            else if (c[1] == '3'){
                Tree<Person> B;
                cout << "Enter the element" << endl;
                Person elem;
                cin >> elem;
                getchar();
                if (A.searchElement(elem) == true){
                    cout << "YES!" << endl;
                }
                else{
                    cout << "NO!" << endl;
                }
                goto Repeat3;
            }
            else if (c[1] == '4'){
                cout << "        Tree" << endl << endl << "       ";
                A.Print(byPass[5]);
                cout << endl << endl;
                goto Repeat3;
            }
            else if (c[1] == '5'){
                Person elem;
                cin >> elem;
                A.add(elem);
                getchar();
                goto Repeat3;
            }
            else if (c[1] == '6'){
                A.~Tree();
                cout << endl;
                goto Back1;
            }
            else if (c[1] == '0'){
                return false;
            }
            else{
                cout << "Try again" << endl;
                goto Repeat3;
            }
        }
        else if (c[0] == '4'){
            AllTests();
            getchar();
            cout << endl;
        }
        else if (c[0] == '5'){
            printf("\nThe program is a demonstration of a ternary tree\n"
                   "About a ternary tree.\n"
                   "In computer science, a ternary tree is a tree data structure in which each node has at most three child nodes, usually distinguished as left, mid and right. "
                   "Nodes with children are parent nodes, and child nodes may contain references to their parents. "
                   "Outside the tree, there is often a reference to the root node (the ancestor of all nodes), if it exists. "
                   "Any node in the data structure can be reached by starting at root node and repeatedly following references to either the left, mid or right child.\n"
                   "\n                                22.05.2022\n"
                   "                                            Bulygin Fedor\n");
        }
        else if (c[0] == '6'){
            return false;
        }
        else{
            cout << "Try again" << endl;
            goto Back1;
        }
    }
    return 0;
}
