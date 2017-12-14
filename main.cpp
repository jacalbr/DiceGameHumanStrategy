//
//  main.cpp
//  MathModelingDice2
//
//  Created by Jack Albright on 12/8/17.
//  Copyright © 2017 Jack Albright. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
double oldprob[10];
double prob[10];
double oldprobAI[10];
double probAI[10];

double totalprob(){
    return prob[0]/2 + prob[1]/3 + prob[2]*2/3 + prob[3]/6 + prob[4]/2 + prob[5]*5/6 + prob[7]/3 + prob[8]*2/3 + prob[9];
}

double totaloldprob(){
    return oldprob[0]/2 + oldprob[1]/3 + oldprob[2]*2/3 + oldprob[3]/6 + oldprob[4]/2 + oldprob[5]*5/6 + oldprob[7]/3 + oldprob[8]*2/3 + oldprob[9];
}

double totalprobAI(){
    return probAI[0]/2 + probAI[1]/3 + probAI[2]*2/3 + probAI[3]/6 + probAI[4]/2 + probAI[5]*5/6 + probAI[7]/3 + probAI[8]*2/3 + probAI[9];
}

double totaloldprobAI(){
    return oldprobAI[0]/2 + oldprobAI[1]/3 + oldprobAI[2]*2/3 + oldprobAI[3]/6 + oldprobAI[4]/2 + oldprobAI[5]*5/6 + oldprobAI[7]/3 + oldprobAI[8]*2/3 + oldprobAI[9];
}


int main() {
    srand(time(0));
    char prompt;
    double finprob;
    double finprobAI;
    double buffer = 0.03;
    prob[0] = 1.0;
    oldprob[0] = 1.0;
    probAI[0] = 1.0;
    oldprobAI[0] = 1.0;
    while(true){
        cin >> prompt;
        if(prompt == 'R'){
            for(int i = 0; i < 10; i++){
                prob[i] = 0.0;
                oldprob[i] = 0.0;
                probAI[i] = 0.0;
                oldprobAI[i] = 0.0;
            }
            prob[0] = 1.0;
            oldprob[0] = 1.0;
            probAI[0] = 1.0;
            oldprobAI[0] = 1.0;
            continue;
        }else if(prompt == 'E'){
            prob[0] = 0.0;
            prob[1] = 0.0;
            prob[2] = (1/2.0)*oldprob[0]/totaloldprob() + (2/3.0)*(oldprob[2]/2.0)/totaloldprob();
            prob[3] = 0.0;
            prob[4] = (1/3.0)*oldprob[1]/totaloldprob() + (1/2.0)*(oldprob[4]*2/3.0)/totaloldprob();
            prob[5] = (2/3.0)*(oldprob[2]/2.0)/totaloldprob() + (5/6.0)*(oldprob[5]*4/5.0)/totaloldprob();
            prob[6] = 0*oldprob[6]/totaloldprob();
            prob[7] = (1/3.0)*oldprob[7]/totaloldprob() + (1/6.0)*oldprob[3]/totaloldprob();
            prob[8] = (2/3.0)*oldprob[8]/totaloldprob() + (1/2.0)*(oldprob[4]/3.0)/totaloldprob();
            prob[9] = 1*oldprob[9]/totaloldprob() + (5/6.0)*(oldprob[5]/5.0)/totaloldprob();
            
            for(int j = 0; j < 10; j++){
                oldprob[j] = prob[j];
            }
        }else if(prompt == 'O'){
            prob[0] = 0.0;
            prob[1] = (1/2.0)*oldprob[0]/(1-totaloldprob()) + (2/3.0)*(oldprob[1]/2.0)/(1-totaloldprob());
            prob[2] = 0.0;
            prob[3] = (2/3.0)*(oldprob[1]/2.0)/(1-totaloldprob()) + (5/6.0)*(oldprob[3]*4/5.0)/(1-totaloldprob());
            prob[4] = (1/3.0)*oldprob[2]/(1-totaloldprob()) + (1/2.0)*(oldprob[4]*2/3.0)/(1-totaloldprob());
            prob[5] = 0.0;
            prob[6] = 1*oldprob[6]/(1-totaloldprob()) + (5/6.0)*(oldprob[3]/5.0)/(1-totaloldprob());
            prob[7] = (2/3.0)*oldprob[7]/(1-totaloldprob()) + (1/2.0)*(oldprob[4]/3.0)/(1-totaloldprob());
            prob[8] = (1/3.0)*oldprob[8]/(1-totaloldprob()) + (1/6.0)*oldprob[5]/(1-totaloldprob());
            prob[9] = 0*oldprob[9]/(1-totaloldprob());
            
            for(int j = 0; j < 10; j++){
                oldprob[j] = prob[j];
            }
        }else{
            break;
        }
        cin >> prompt;
        if(prompt == 'R'){
            for(int i = 0; i < 10; i++){
                prob[i] = 0.0;
                oldprob[i] = 0.0;
                probAI[i] = 0.0;
                oldprobAI[i] = 0.0;
            }
            prob[0] = 1.0;
            oldprob[0] = 1.0;
            probAI[0] = 1.0;
            oldprobAI[0] = 1.0;
            continue;
        }else if(prompt == 'E'){
            probAI[0] = 0.0;
            probAI[1] = 0.0;
            probAI[2] = (1/2.0)*oldprobAI[0]/totaloldprobAI() + (2/3.0)*(oldprobAI[2]/2.0)/totaloldprobAI();
            probAI[3] = 0.0;
            probAI[4] = (1/3.0)*oldprobAI[1]/totaloldprobAI() + (1/2.0)*(oldprobAI[4]*2/3.0)/totaloldprobAI();
            probAI[5] = (2/3.0)*(oldprobAI[2]/2.0)/totaloldprobAI() + (5/6.0)*(oldprobAI[5]*4/5.0)/totaloldprobAI();
            probAI[6] = 0*oldprobAI[6]/totaloldprobAI();
            probAI[7] = (1/3.0)*oldprobAI[7]/totaloldprobAI() + (1/6.0)*oldprobAI[3]/totaloldprobAI();
            probAI[8] = (2/3.0)*oldprobAI[8]/totaloldprobAI() + (1/2.0)*(oldprobAI[4]/3.0)/totaloldprobAI();
            probAI[9] = 1*oldprobAI[9]/totaloldprobAI() + (5/6.0)*(oldprobAI[5]/5.0)/totaloldprobAI();
            
            for(int j = 0; j < 10; j++){
                oldprobAI[j] = probAI[j];
            }
        }else if(prompt == 'O'){
            probAI[0] = 0.0;
            probAI[1] = (1/2.0)*oldprobAI[0]/(1-totaloldprobAI()) + (2/3.0)*(oldprobAI[1]/2.0)/(1-totaloldprobAI());
            probAI[2] = 0.0;
            probAI[3] = (2/3.0)*(oldprobAI[1]/2.0)/(1-totaloldprobAI()) + (5/6.0)*(oldprobAI[3]*4/5.0)/(1-totaloldprobAI());
            probAI[4] = (1/3.0)*oldprobAI[2]/(1-totaloldprobAI()) + (1/2.0)*(oldprobAI[4]*2/3.0)/(1-totaloldprobAI());
            probAI[5] = 0.0;
            probAI[6] = 1*oldprobAI[6]/(1-totaloldprobAI()) + (5/6.0)*(oldprobAI[3]/5.0)/(1-totaloldprobAI());
            probAI[7] = (2/3.0)*oldprobAI[7]/(1-totaloldprobAI()) + (1/2.0)*(oldprobAI[4]/3.0)/(1-totaloldprobAI());
            probAI[8] = (1/3.0)*oldprobAI[8]/(1-totaloldprobAI()) + (1/6.0)*oldprobAI[5]/(1-totaloldprobAI());
            probAI[9] = 0*oldprobAI[9]/(1-totaloldprobAI());
            
            for(int j = 0; j < 10; j++){
                oldprobAI[j] = probAI[j];
            }
        }else{
            break;
        }
        finprob = totalprob();
        finprobAI = totalprobAI();
        
        cout << "Our Probability of rolling Even: " << finprob << endl;
        cout << "AI Probability of rolling Even: " << finprobAI << endl;
        
        if(finprob < 0.5){
            if(finprobAI <= 0.5 or abs(finprob - 0.5) >= abs(finprobAI - 0.5)){
                cout << -1;
            }else{
                cout << 1;
            }
        }else if(finprob > 0.5){
            if(finprobAI >= 0.5 or abs(finprob - 0.5) <= abs(finprobAI - 0.5)){
                cout << 1;
            }else{
                cout << -1;
            }
        }else{
            if(finprobAI >= 0.5){
                cout << 1;
            }else{
                cout << -1;
            }
        }
        
        /*if(abs(finprobAI - 0.5) - abs(finprob - 0.5) > buffer){
            cout << abs(finprobAI - 0.5)/(finprobAI - 0.5);
        }else if(abs(finprob - 0.5) - abs(finprobAI - 0.5) > buffer){
            cout << abs(finprob - 0.5)/(finprob - 0.5);
        }else{
            if(finprob == 0.5){
                cout << finprob/finprob;
            }else if(finprob == finprobAI){
                cout << abs(finprob - 0.5)/(finprob - 0.5);
            }else{
                cout << ((double) rand())/RAND_MAX;
            }
        }*/
        cout << endl;
    }
    return 0;
}
