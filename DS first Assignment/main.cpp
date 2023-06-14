#include "movie.h";
#include "array7d.h";



int main()
{

    cout << "---------------------------------------------------------\n";
    cout << "\t\t\tRetrive A Value at (0,0,0,0,0,0,3)\n";
    cout << "---------------------------------------------------------\n\n";
    array7d arr(1, 1, 1, 1, 1, 1, 4);
    arr.Insert(0, 0, 0, 0, 0, 0, 3, 12);
    cout << "The Retrieved Value is: " << arr.retrieve(0, 0, 0, 0, 0, 0, 3) << endl;


    cout << "\n\n---------------------------------------------------------\n";
    cout << "\t\t\tMovie Analytics\n";
    cout << "---------------------------------------------------------\n";
    LinkedList movie;
    LinkedList actor;
    string tempMovie;
    string* tempActors = new string[6];
    ifstream file;
    file.open("movie.txt", ios::in);
    int i;
    bool flag = true;
    while (getline(file, tempMovie))
    {
        i = 0;
        flag = true;
        while (flag)
        {
            getline(file, tempActors[i]);
            if (tempActors[i] == "#") {
                flag = false;
            }
            else
                i++;
        }
        for (i; i < 5; i++)
        {
            tempActors[i] = "null";
        }
        movie.insertMovie(tempMovie, tempActors);
        actor.insertActors(tempMovie, tempActors);
    }
    file.close();
    cout << "------------Movies--------------\n";
    movie.displayMovie();

    cout << "\n\n\n------------Actors--------------\n";
    actor.displayActors();

    cout << "\n\n\n-------------------- Searching Movie -------------------\n";
    movie.searchMovie("Montrose Hagins");

    cout << "\n\n\n-------------------- Searching Actor -------------------\n";
    actor.searchActor("Montrose Hagins");

    cout << "\n\n\n----------------------------------------------\n";
    cout << "On average, an actor works in " << actor.average() << " films\n";

    cout << "\n\n\n----------------------------------------------\n";
    cout << "On average, a film has " << movie.average() << " actors\n";


    return 0;
}

