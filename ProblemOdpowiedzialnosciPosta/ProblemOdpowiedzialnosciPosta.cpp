// Cezary Skorupski 2022
// Program wpsomagający poszukiwania rozwiązania Problemu Odpowiedniości Posta(POP)

#include <iostream>

using namespace std;

int main()
{
    int n, m = 0;
    int in;
    string w = "", x = "";

    cout << "Program wspomagający poszukiwania rozwiązania\nProblemu Odpowiedniości Posta(POP)\n";
    cout << "Dla alfabetu Σ={0,1}\n\n";

    cout << "-----------------------------" << endl;
    cout << "Podaj ilość łańcuchów w listach A i B: ";
    cin >> n;
    string * A = new string[n];
    string * B = new string[n];

    cout << "\nPodaj łancuchy listy A (" << n << "):\n";
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "\nPodaj łancuchy listy B (" << n << "):\n";
    for (int i = 0; i < n; i++)
        cin >> B[i];
    cout << "-----------------------------" << endl;
    cout << "\nWczytano lista A:\n";
    for (int i = 0; i < n; i++)
        cout << "w" << i + 1 << " = " << A[i] << endl;
    cout << "\nWczytano lista B:\n";
    for (int i = 0; i < n; i++)
        cout << "x" << i + 1 << " = " << B[i] << endl;
    
    cout << endl;
    string t_i = "";
    do {
        cout << "\nPodaj i" << m+1 << "(aby przerwać wpisz 0): ";
        cin >> in;
        while (in < 0 || in > n) {
            cout << "Wartość " << in << " jest niepoprawna.\nProszę wpisać wartość z przedziału 1-" << n << " aby kontynuować, lub 0, aby przerwać poszukiwania rozwiązania." << endl;
            cin >> in;
        }
        if (in == 0) break;
        t_i += (in+'0'); 
        w += A[in-1];
        x += B[in-1]; 
        m++;
        cout << "w: " << w << endl;
        cout << "y: " << x << endl;
    } while (x != w);

    if (x == w && in != 0) {
        cout << "\nW tym przypadku POP ma rozwiązanie.\n";
        cout << "Niech m=" << m;
        for (int i = 0; i < m; i++)
            cout << ", " << "i" << i+1 << "=" << t_i[i];
        cout << ".";
        cout << "\nWtedy w = x = " << w << endl;
    }
    else {
        cout << "\nPrzerwano poszukiwania rozwiązania.\n";
    }

    return 0;
}


