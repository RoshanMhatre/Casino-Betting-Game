#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int cash = 100;
void CasinoGame(int bet)
{
    int userGuess;
    char *computer =(char*)(malloc(3*sizeof(char)));
    computer[0]= {'J'};
    computer[1]='Q';
    computer[2]='K';
    cout << "Shuffling the cards........\n";
    srand(time(NULL)); //Generating Random Number
    for (int i = 0; i < 4; i++)
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = computer[x];
        computer[x] = computer[y];
        computer[y] = temp; //For Swapping
    }
cout<<"What's the position of Queen?1,2 or 3"<<endl;
cin>>userGuess;
if(computer[userGuess-1]=='Q'){
cash+=2 * bet;
cout<<"You WIN!!! Result = "<<computer[0]<<" "<<computer[1]<<" "<<computer[2]<<" "<<"\nTotal Cash= "<<cash<<"$";
}else{
    cash-=bet;
        cout<<"You Lose! Result = "<<computer[0]<<" "<<computer[1]<<" "<<computer[2]<<" "<<"\nTotal Cash= "<<cash<<"$";

}
free(computer);
}
int main()
{
    int bet;
    cout << "WELCOME TO CASINO" << endl;
    cout<<"Total Cash = "<<cash<<"$"<<endl;
    while (cash > 0)
    {
        cout<<"What's your bet?$";
        cin>>bet;
        if(bet==0 || bet>cash) break;
        CasinoGame(bet);
        cout<<"\n------------------------------------"<<endl;
    }
    return 0;
}