//
// Created by royga on 9/9/2026.
//
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include "ALGO.h"


//SHORTCUT COPY PASTE: [=====][std::cout<<"\n\n";]
//constant number of votes
const int voters = 100;

//to show the array elements
void showArr(const int arr[], int size);

// function to show candidates number to their name
std::string CandNames(int candID) {
    switch (candID) {
        case 1:
            return "Bo Dalton Capistrano";
        case 2:
            return "Cornelius Raymon Agustin";
        case 3:
            return "Deja Jayla Bañaga";
        case 4:
            return "Lalla Brielle Yabut";
        case 5:
            return "Franklin Relano Castro";
        default:
            return "UNKNOWN";
    }
}

int main() {
    int votes[voters];
    //seed
    srand(time(0));
    //generate the 100 elements but limit it to only to numbers 1 to 5
    for (int i = 0; i < voters; i++) {
        votes[i] = (rand() % 5)+1;//cheating the generation to get the 5 instead of just using %6
    }

    //show the unsorted array
    std::cout<< "==========UNSORTED VOTES==========\n";
    showArr(votes, voters);
    std::cout<<"\n\n";

    //sort using insertion sort
    std::cout<<"==========INSERTION SORT==========\n";
    insertionSort(votes, voters);
    std::cout<<"\n\n";

    //show the sorted numbers
    showArr(votes, voters);
    std::cout<<"\n\n";

    //tally the votes
    int voteCount[6] = {0};
    for (int i = 0; i < voters; i++) {
        voteCount[votes[i]]++;
    }

    //display the tallied number of votes
    std::cout<<"========== TALLY ==========\n";
    for (int i=1; i<=5; i++) {
        std::cout<<"CANDIDATE"<<i<<": "<<CandNames(i)<<": "<<voteCount[i]<<" VOTES\n";
    }
    std::cout<<"\n\n";

    //finding the highes vote count
    int maxVotes = 0;
    for (int i=1; i<=5; i++) {
        if (voteCount[i] > maxVotes) {
            maxVotes = voteCount[i];
        }
    }

    //if in any case has ties(nah)
    int winnerCount = 0;
    for (int i=1; i<=5; i++) {
        if (voteCount[i] == maxVotes) {
            winnerCount++;
        }
    }

    //Show the result
    std::cout<<"========== WINNER ==========";
    if (winnerCount ==1) {
        //for single win
        for (int i=1; i<=5; i++) {
            if (voteCount[i] == maxVotes) {
                std::cout<<"\nCANDIDATE "<< i << " ("<< CandNames(i)<< ") with " << maxVotes << " votes!\n";
            }
        }
    }else {//for the tie
        std::cout<<"IT IS A TIE! The following " << winnerCount << " candidates tied with " << maxVotes << " votes each:\n";

        for (int i = 1; i <= 5; i++) {
            if (voteCount[i] == maxVotes) {
                std::cout << " - Candidate " << i << " (" << CandNames(i) << ")\n";
            }
        }
    }
    return 0;
}

void showArr(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}