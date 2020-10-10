#include <iostream>
using namespace std;
int array2D[100][100];
void displayMatrix(int v) {
    int i, j;
    char letter = 'A';
    char anotherLetter = 'A';
    cout << " ";
    for (i = 0; i < v; i++) {
        cout << " " << anotherLetter;
        anotherLetter++;
    }
    cout << endl;
        for (i = 0; i < v; i++) {
            cout << letter << " ";
            for (j = 0; j < v; j++) {
            cout << array2D[i][j] << " ";
            }
            cout << endl;
            letter++;
        }
}
void printList(int vertices) {
    int i, j;
    char letter = 'A';
    for (i = 0; i < vertices; i++) {
        cout << letter << " => ";

             for (char newLetter = 'A',j = 0; j < vertices;newLetter++, j++) {     
                if (array2D[i][j] == 1 && array2D[j][i] == 1) {
                    cout << newLetter << " ";
                }
            }   
        cout << endl;
        letter++;
    }
}
void printOutDegree(int vertices)
{
       int i, j;
    char letter = 'A';
    for (int outDegree = 0, i = 0; i < vertices; i++) {
        cout << letter << " => ";
        for ( j = 0; j < vertices; j++) {
                if (array2D[i][j] == 1) {
                    outDegree++;
                }
            }   
        cout << outDegree;
        cout << endl;
        outDegree = 0;
        letter++;
    }
}

void printInDegree(int vertices)
{
    int i, j;
    char letter = 'A';
    for (int inDegree = 0, i = 0; i < vertices; i++) {
        cout << letter << " =>";
        for (j = 0; j < vertices; j++) {
            if (array2D[j][i] == 1) {
                inDegree++;
            }
        }
        cout << inDegree;
        cout << endl;
        inDegree = 0;
        letter++;
    }

}
void add_edge(int u, int v) {  //row coordinate, columnCoordinate
    array2D[u][v] = 1;
    array2D[v][u] = 1;
}
int main() {
    int vertices = 0;  
    cout << "Enter how many vertices: ";
    cin >> vertices;
    char promptEnter = 'y';
    int rowCoord;
    int columnCoord;
    int edge = 0;
    while (promptEnter == 'y' || promptEnter == 'Y')
    {
        cout << "Enter a row coordinate : ";
        cin >> rowCoord;
        cout << "Enter a column coordinate : ";
        cin >> columnCoord;
        cout << "Insert another edge? [y/n] : ";
        cin >> promptEnter;
        edge++;
        add_edge(rowCoord, columnCoord);
    }
    cout << "ADJACENCY MATRIX " << endl;
    displayMatrix(vertices);
    cout << "ADJANCENCY LISTS " << endl;
    printList(vertices);
    cout << "IN DEGREE : " << endl;
    printInDegree(vertices);
    cout << "OUT DEGREE : " << endl;
    printOutDegree(vertices);
}