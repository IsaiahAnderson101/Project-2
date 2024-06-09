/* 
 * File:   main.cpp
 * Author: mlehr
 * Created on March 21st, 2023, 11:03 AM
 * Purpose:  Template to be used for all
 *           future Hmwk, Labs, Exams, Projects
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip> //Manipulate cout statements
#include <cstdlib> //Utilize random generator 
#include <ctime> //Utilize time in c++

using namespace std;

//User Libraries

//Global Constants not Variables
const int SIZE = 52;
//Science, Math, Conversions, Dimensions

//Function Prototypes
void hit(int [], char [], int &);
void fillAr(int [], const int); //52 random card numbers (parallel  array)
void fillSu(char [], const int); //4 suits divided into 13 cards (parallel array)
void prinAr(int [], const int, int);
void start(int [], char [], int&, string); //Start of game, player is given two cards
bool decide(int [], char [], int&); //The player is given his options and once he's done, the function turns false to signal the dealers turn
void deal(int [], char[], int&);
void winner(int, int);
void shuffle(int [], const int);
string nameC(int, char[], int);
string suitC(char [], int);

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    string user1;
    string dealer;
    int player;
    int dealr;
    int array[SIZE];
    char suit[SIZE];
    bool again;
    //Initialize Variables
    user1 = "Player"; //Adds an extra parameter for hit function to personalize based on the player/dealer 
    dealer = "Dealer";
    again = true;
    //Map/Process the Inputs -> Outputs
    fillAr(array, SIZE);
    fillSu(suit, SIZE);
    //prinAr(array, SIZE, 13);
    start(array, suit, player, user1);
    start(array, suit, dealr, dealer);
    while(again == true) {
        again = decide(array, suit, player); //if the player stands or gets over 21, again will return false
    }
    if(player<=21) {
    deal(array, suit, dealr);
    }
    //Display Inputs/Outputs
    winner(player, dealr);
    //Clean up memory and files
    
    //Exit the Program
    return 0;
}

void shuffle(int array[], const int SIZE){ //Shuffling feature when the game is over
    int holder = 0;
    int ranNum = 0;
    for(int i = 0; i<SIZE; i++) {
        ranNum = rand()%51+1;
        holder = array[ranNum];
        array[i] = array[ranNum];
        array[i] = holder;
    }
    
}
void start(int arr[], char suit[], int& score, string user) { //Beginning of game, player is given 2 cards
    score = 0;
    if(user == "Player") {
        cout << "╔═════════════════════════════╗" << endl;
        cout << "║      ★ WELCOME TO ★         ║" << endl;
        cout << "║    ★☆★  BLACK JACK  ★☆★     ║" << endl;
        cout << "╚═════════════════════════════╝" << endl;
        cout << "You are given two cards: ";
        hit(arr, suit, score); 
        cout << " and ";
        hit(arr, suit, score);
        cout << endl;
        cout << "This makes your grand total " << score << endl << endl;
    }
    if(user == "Dealer") {
        cout << "The dealer reveals his face up:" << endl;
        hit(arr, suit, score);
        cout << endl << endl;
    }
   
}


bool decide(int array[], char suit[], int& score){
    string choice;
    cout << "Would you like to: " << "   (H) Hit" << "     " << "(S) Stand" << "     " << "(D) Double Down" << "     " << "(S) Surrender" << endl;
    cin >> choice;
    if((choice == "H")||(choice == "Hit")||(choice == "h")||(choice == "hit")) {
        cout << "You are given a card: ";
        hit(array, suit, score);
        cout << endl;
        cout << "This makes your new total: " << score << endl;
        while(score<=21){
            string hitA; 
            cout << "Would you like to hit again?" << endl;
            cout << "-Y Yes" << endl;
            cout << "-N No" << endl;
            cin>> hitA;
            if((hitA == "Y")||(hitA == "Yes")||(hitA == "y")||(hitA == "yes")) {
                cout << "You are given a card: ";
                hit(array, suit, score);
                cout << endl;
                
                cout << "This makes your new total: " << score << endl;
            } 
            if((hitA == "N")||(hitA == "No")||(hitA == "n")||(hitA == "no")) {
                return false;
            } 
            if(score>21) {
                cout << "You lose!" << endl;
                return false;
            }
        }
    }
    if((choice == "S")||(choice == "Stand")||(choice == "s")||(choice == "stand")) {
        return false;
    }  
}


void deal(int arr[], char suit[], int& score) {
    cout << "The dealer reveals his face down: ";
    hit(arr, suit, score);
    cout << endl;
    
    while(score<17) {
        cout << "The dealer hits again: ";
        hit(arr, suit, score);
        cout << endl;
    }
}

void winner(int player, int dealr) {
    if(dealr>21) {
        cout << "The dealer busted! You win!" << endl;
    }
    if(player>21) {
        cout << "You busted! The dealer wins!" << endl;
    }
    if(player>dealr) {
        cout << "You win! Your score was " << player << " while the dealer was " << dealr << endl;
    }
    if(dealr>player) {
        cout << "The dealer wins! The dealer score was " << dealr << " while your score was " << player << endl; 
    }
    if(dealr==player) {
        cout << "It was a tie!" << " Both player and dealer got " << player << endl;
    }
}
void fillAr(int arr[], const int SIZE){ //Fills the array with random cards
    for(int i = 0; i<SIZE; i++) {
        arr[i] = rand()%10+1;
    }
}

void fillSu(char arr[], const int SIZE) { //Divides the array into 4 sections (13 suits for each section)
    for(int i = 0; i<SIZE; i++) {
        if(i<13) {
            arr[i] = 'S';
        }
        else if(i<26) {
            arr[i] = 'D';
        }
        else if(i<39) {
            arr[i] = 'H';
        }
        else if(i<52) {
            arr[i] = 'C';
        }
    }
}
void prinAr(int arr[], const int SIZE, int newLin){
    for(int i = 0; i<SIZE; i++) {
        cout << setw(3) << arr[i] << "";
        if((i+1)%newLin==0) {
            cout << endl;
        }
    }
}
string nameC(int num, char suits[], int index) {
    int tenR;
    string name;
    switch(num) {
        case 1: name = "Ace";
                break;
        case 2: name = "Two";
                break;
        case 3: name = "Three";
                break;
        case 4: name = "Four";
                break;
        case 5: name = "Five";
                break;
        case 6: name = "Six";
                break;
        case 7: name = "Seven";
                break;
        case 8: name = "Eight";
                break;
        case 9: name = "Nine";
                break;
        case 10: name = "Ten";
                break;
        case 11: name = "Ace";
                break; 
    }
    if(name == "Ten") {
        tenR = rand()%3+1;
        if(tenR == 1)  {
            name = "Ten";
         }
        else if(tenR == 2) {
            name = "Jack";
        }
        else if(tenR == 3) {
            name = "Queen";
        }
        else {
            name = "King";
        }
    }
    if(suits[index] == 'S') {
        name += " of Spades";
    }
    if(suits[index] == 'D') {
        name += " of Diamonds";
    }
    if(suits[index] == 'H') {
        name += " of Hearts";
    }
    if(suits[index] == 'C') {
        name += " of Clubs";
    }
    return name;
}
string suitC(char suits[], int index) {
    if(suits[index] == 'S') {
        return "Spades";
    }
    if(suits[index] == 'D') {
        return "Diamonds";
    }
    if(suits[index] == 'H') {
        return "Hearts";
    }
    if(suits[index] == 'C') {
        return "Clubs";
    }
}
void hit(int array[], char suit[], int &total) {
    string nameS;
    int numR;
    int pullC;
    
    numR = rand()%51+0; //Gets a random number to utilize on both arrays
    nameS = suitC(suit, numR); //Parallel Array, connects integer array index to char array index to get suit
   
    pullC = array[numR];
    if((total<=10)&&(pullC==1)) { //Decides if 11 or 1 is the best choice if the player/dealer pulls an Ace
        pullC = 11;
    }
    total += pullC; //Adds to players/dealers total
    
    cout << nameC(pullC, suit, numR);
    
}