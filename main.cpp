//Author - Roshan Mhatre

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

// cash is used to store the total amount of money of your account

int cash = 100;

void CasinoGame(int bet)
{
    int userGuess;
    
    //Allocating Memory Dynamically
    char *computer =(char*)(malloc(3*sizeof(char)));
    
    computer[0]= 'J';
    computer[1]='Q';
    computer[2]='K';
    
    cout << "Shuffling the cards........\n";
    
    // Passing current time as seed for generating absolute random values
    srand(time(NULL));
    
    //This for loop will generate computer's output
    for (int i = 0; i < 4; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = computer[x]; //For Swapping
        computer[x] = computer[y];
        computer[y] = temp; 
    }
    
cout<<"What's the position of Queen?1,2 or 3"<<endl;
    
cin>>userGuess; // Taking user input
    
if(computer[userGuess-1]=='Q'){
cash+=2 * bet; // Your Money gets doubled if you win
cout<<"You WIN!!! Result = "<<computer[0]<<" "<<computer[1]<<" "<<computer[2]<<" "<<"\nTotal Cash= "<<cash<<"$";
}else{
    cash-=bet; // You lose your bet amount from total cash
        cout<<"You Lose! Result = "<<computer[0]<<" "<<computer[1]<<" "<<computer[2]<<" "<<"\nTotal Cash= "<<cash<<"$";

}
    
// Freeing the memory from heap
free(computer);
    
}
int main()
{
    int bet;
    cout << "WELCOME TO CASINO" << endl;
    cout<<"Total Cash = "<<cash<<"$"<<endl;
    
    // This loop will run till you cash becomes <=0 
    while (cash > 0)
    {
        cout<<"What's your bet?$";
        cin>>bet;
        if(bet==0 || bet>cash) break;
        CasinoGame(bet);
        
        // To have distinction between each game played 
        cout<<"\n------------------------------------"<<endl;
        
    }
    return 0;
}
