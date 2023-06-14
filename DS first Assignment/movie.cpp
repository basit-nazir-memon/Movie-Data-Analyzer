#include "movie.h"

node::node()
{
    data = "";
    next = NULL;
    below = NULL;
}

LinkedList::LinkedList()
{
    head = NULL;
}

void LinkedList::insertActors(string data, string* below) {
    node* temp = head;
    node* belowTemp = NULL;
    bool dataExist = false;
    for (int i = 0; below[i] != "null" && i < 5; i++) {
        temp = head;
        dataExist = false;
        belowTemp = NULL;

        if (temp == NULL) {
            temp = new node;
            temp->data = below[i];
            head = temp;
        }
        else {
            if (temp->data == below[i]) {
                dataExist = true;
            }
            while (temp->next != NULL) {
                if (temp->data == below[i]) {
                    dataExist = true;
                    break;
                }
                temp = temp->next;
            }
            if (!dataExist) {
                temp->next = new node;
                temp = temp->next;
                temp->data = below[i];
            }
        }
        belowTemp = temp;
        if (belowTemp->below == NULL) {
            belowTemp->below = new node;
        }
        else {
            while (belowTemp->below != NULL) {
                belowTemp = belowTemp->below;
            }
            belowTemp->below = new node;
        }
        belowTemp->below->data = data;
    }
}

void LinkedList::insertMovie(string data, string* below)
{
    node* temp = head;
    node* belowtemp = head;
    if (temp == NULL)
    {
        temp = new node;
        head = temp;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new node;
        temp = temp->next;
    }
    temp->data = data;
    belowtemp = temp;
    for (int i = 0; i < 5; i++)
    {
        if (below[i] != "null")
        {
            belowtemp->below = new node;
            belowtemp->below->data = below[i];
            belowtemp = belowtemp->below;
        }
    }
}

void LinkedList::displayMovie()
{
    node* temp = head;
    node* actorPointer = nullptr;

    while (temp != NULL)
    {
        cout << "Movie Name: " << temp->data << "\n";
        actorPointer = temp;
        while (actorPointer->below != NULL)
        {
            cout << "Actor: " << actorPointer->below->data << endl;
            actorPointer = actorPointer->below;
        }
        cout << "\n\n\n";
        temp = temp->next;

    }
}

void LinkedList::displayActors() {
    node* temp = head;
    node* moviePointer = nullptr;

    while (temp != NULL)
    {
        cout << "Actor Name: " << temp->data << "\n";
        moviePointer = temp;
        while (moviePointer->below != NULL)
        {
            cout << "Movie: " << moviePointer->below->data << endl;
            moviePointer = moviePointer->below;
        }
        cout << "\n\n\n";
        temp = temp->next;

    }
}

float LinkedList::average() {
    int below = 0, right = 0;
    node* currPointer = head;
    node* belowPtr = NULL;
    while (currPointer != NULL) {
        belowPtr = currPointer->below;
        while (belowPtr != NULL) {
            below++;
            belowPtr = belowPtr->below;
        }
        right++;
        currPointer = currPointer->next;
    }
    return float(below) / float(right);
}

void LinkedList::searchMovie(string name) {
    node* temp = head;
    bool dataFound = false;
    if (temp != NULL) {
        do {
            if (temp->data == name) {
                dataFound = true;
                cout << "Movie Name: " << temp->data << endl;
                temp = temp->below;
                while (temp != NULL) {
                    cout << "Actor : " << temp->data << endl;
                    temp = temp->below;
                }
                break;
            }
            else {
                temp = temp->next;
            }
        } while (temp != NULL);
    }
    if (!dataFound) {
        cout << "Movie Not Exist...\n";
    }
}

void LinkedList::searchActor(string name) {
    node* temp = head;
    bool dataFound = false;
    if (temp != NULL) {
        do {
            if (temp->data == name) {
                dataFound = true;
                cout << "Actor Name: " << temp->data << endl;
                temp = temp->below;
                while (temp != NULL) {
                    cout << "Movie : " << temp->data << endl;
                    temp = temp->below;
                }
                break;
            }
            else {
                temp = temp->next;
            }
        } while (temp != NULL);
    }
    if (!dataFound) {
        cout << "Actor Not Exist...\n";
    }
}