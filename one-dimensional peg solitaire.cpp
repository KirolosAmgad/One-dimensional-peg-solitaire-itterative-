#include <iostream>
using namespace std;

void solve_peg(int *peg_board, int nb_pegs, int free_hole) {
    int count = 3;  
    int search_flag = 0;
    do
    {
        if (free_hole == nb_pegs - 1 || free_hole == 2)
        {
            for (int i = 0; i < nb_pegs - 2; i++) {

                if (peg_board[i] == 1) {
                    if (peg_board[i + 1] == 1) {
                        if (peg_board[i + 2] == 0) {
                            peg_board[i] = 0;
                            peg_board[i + 1] = 0;
                            peg_board[i + 2] = 1;
                            break;
                        }
                    }
                }
                if (peg_board[i] == 0) {
                    if (peg_board[i + 1] == 1) {
                        if (peg_board[i + 2] == 1) {
                            peg_board[i] = 1;
                            peg_board[i + 1] = 0;
                            peg_board[i + 2] = 0;
                            break;
                        }
                    }
                }
            }       
        }
        if (free_hole == nb_pegs - 4 || free_hole == 5)
        {
            if (search_flag == 0)
            {
                for (int i = 0; i < nb_pegs - 2; i++) {

                    if (peg_board[i] == 0) {
                        if (peg_board[i + 1] == 1) {
                            if (peg_board[i + 2] == 1) {
                                peg_board[i] = 1;
                                peg_board[i + 1] = 0;
                                peg_board[i + 2] = 0;
                                break;
                            }
                        }
                    }
                    if (i == nb_pegs - 3) { search_flag = 1; }
                }
            }
            if (search_flag == 1)
            {
                for (int i = 0; i < nb_pegs - 2; i++)
                {
                    if (peg_board[i] == 1) {
                        if (peg_board[i + 1] == 1) {
                            if (peg_board[i + 2] == 0) {
                                peg_board[i] = 0;
                                peg_board[i + 1] = 0;
                                peg_board[i + 2] = 1;
                                break;
                            }
                        }
                    }
                }
            }
            search_flag = 0;
        }
        if (count == 2) { cout << "The peg board (after solving): [ "; }
        else { cout << "The peg board (now): [ "; }
        for (int i = 0; i < nb_pegs; i++)
        {
            if (nb_pegs > 6)
            {
                if (free_hole == 2 || free_hole == 5) { cout << peg_board[nb_pegs - i - 1] << " "; }
                else { cout << peg_board[i] << " "; }
            }
            else
            {
                if (free_hole == 2) { cout << peg_board[nb_pegs - i - 1] << " "; }
                else { cout << peg_board[i] << " "; }
            }
        }
        cout << "]" << endl << endl;
        count = 0;
        for (int i = 0; i < nb_pegs; i++) {
            if (peg_board[i] == 1) { count++; }
        }
    } while (count > 1);    
}

int main(){
    cout <<endl<< "                         Welcome to the Peg Solitaire Solver" << endl << endl;
    int again = 1;
    while (again) {
        int nb_pegs = 1;
        int* peg_board = nullptr;
        int free_hole = 0;
        int right_hole_1 = 0;
        int right_hole_2 = 0;
        while (nb_pegs%2 !=0 || nb_pegs<3)
        {
            cout << "Please enter number of places in the board(must be even and bigger than 2): ";
            cin >> nb_pegs;
            cout << "\n";
            if (nb_pegs % 2 != 0 || nb_pegs < 3) { cout << "Cannot be solved (Please enter a valid number)\n"; }
        }
        right_hole_1 = nb_pegs - 1;
        right_hole_2 = nb_pegs - 4;
        if (nb_pegs < 7)
        {
            cout << "The available places of holes are 2 and " << right_hole_1 << endl;
            while (free_hole != 2 && free_hole != right_hole_1)
            {
                cout << "Choose from available places: ";
                cin >> free_hole;
                cout << "\n";
                if (free_hole != 2 && free_hole != right_hole_1) { cout << "Cannot be solved (Please enter a valid place)\n"; }
            }
            peg_board = new int(nb_pegs - 1);
            for (int i = 0; i < nb_pegs; i++) {
                if (i != right_hole_1 - 1) { peg_board[i] = 1; }
                else { peg_board[i] = 0; }
            }
        }
        else if (nb_pegs > 6)
        {
            cout << "The available places of holes are 2, " << "5, " << right_hole_2 << " & " << right_hole_1 << endl;
            while (free_hole != 2 && free_hole !=5 && free_hole != right_hole_1 && free_hole != right_hole_2)
            {
                cout << "Choose from available places: ";
                cin >> free_hole;
                cout << "\n";
                if (free_hole != 2 && free_hole != 5 && free_hole != right_hole_1 && free_hole != right_hole_2)
                {
                    cout << "Cannot be solved (Please enter a valid place)\n";}
            }
            peg_board = new int(nb_pegs - 1);
            if (free_hole == right_hole_1 || free_hole == 2)
            {
                for (int i = 0; i < nb_pegs; i++) {
                    if (i != right_hole_1 - 1) { peg_board[i] = 1; }
                    else {peg_board[i] = 0;}
                }
            }
            else if (free_hole == right_hole_2 || free_hole == 5) {
                for (int i = 0; i < nb_pegs; i++) {
                    if (i != right_hole_2 - 1) { peg_board[i] = 1; }
                    else { peg_board[i] = 0; }
                }
            }            
        }       
        cout << "The peg board : [ ";
        for (int i = 0; i < nb_pegs; i++)
        {
            if (nb_pegs > 6)
            {
                if (free_hole == 2 || free_hole == 5) { cout << peg_board[nb_pegs - i - 1] << " "; }
                else { cout << peg_board[i] << " "; }
            }
            else{
                if (free_hole == 2){ cout << peg_board[nb_pegs - i - 1] << " ";}
                else{ cout << peg_board[i] << " ";}
            }            
        }
        cout << "]" << endl << endl;
        solve_peg(peg_board, nb_pegs, free_hole);        
        cout << "Do you want to simulate another case (if yes enter 1 / if no enter 0): ";
        cin >> again;
        cout << "\n";
    }
    cout << "Good bye!\n";
}