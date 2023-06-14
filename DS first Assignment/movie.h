#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class node
{
public:
    string data;
    node* next;
    node* below;
    node();
};

class LinkedList
{
public:
    node* head;

public:
    LinkedList();
    void insertActors(string, string*);
    void insertMovie(string, string*);
    void displayMovie();
    void displayActors();
    float average();
    void searchMovie(string);
    void searchActor(string);
};