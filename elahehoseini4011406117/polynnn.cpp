#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Node {
public:
    int coefficient;
    int exponent;
    Node* next;

    Node(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() : head(nullptr) {}

    ~Polynomial() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void insertTerm(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);
        if (!head || exp > head->exponent) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next && exp < current->next->exponent) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void parseAndInsertTerm(string term) {
        int coeff, exp;
        char x;
        stringstream ss(term);
        ss >> coeff >> x >> exp;
        insertTerm(coeff, exp);
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << current->coefficient << "x^" << current->exponent;
            if (current->next) {
                cout << " + ";
            }
            current = current->next;
        }
        cout << endl;
    }

    Polynomial add(Polynomial& p) {
        Polynomial result;
        Node* current1 = head;
        Node* current2 = p.head;

        while (current1 && current2) {
            if (current1->exponent > current2->exponent) {
                result.insertTerm(current1->coefficient, current1->exponent);
                current1 = current1->next;
            } else if (current2->exponent > current1->exponent) {
                result.insertTerm(current2->coefficient, current2->exponent);
                current2 = current2->next;
            } else {
                int newCoeff = current1->coefficient + current2->coefficient;
                result.insertTerm(newCoeff, current1->exponent);
                current1 = current1->next;
                current2 = current2->next;
            }
        }

        while (current1) {
            result.insertTerm(current1->coefficient, current1->exponent);
            current1 = current1->next;
        }

        while (current2) {
            result.insertTerm(current2->coefficient, current2->exponent);
            current2 = current2->next;
        }

        return result;
    }
};

int main() {
    Polynomial p1, p2, p3;

    // Insert terms into polynomial p1: "3x^2 + 5x + 2"
    p1.parseAndInsertTerm("3x^2");
    p1.parseAndInsertTerm("5x^1");
    p1.parseAndInsertTerm("2x^0");

    // Insert terms into polynomial p2: "4x^3 + 2x^2 + 6"
    p2.parseAndInsertTerm("4x^3");
    p2.parseAndInsertTerm("2x^2");
    p2.parseAndInsertTerm("6x^0");

    // Display polynomials
    cout << "Polynomial p1: ";
    p1.display();
    cout << "Polynomial p2: ";
    p2.display();

    // Add polynomials p1 and p2
    p3 = p1.add(p2);

    // Display result of addition
    cout << "Sum of p1 and p2: ";
    p3.display();

    return 0;
}
