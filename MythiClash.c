//
//  MythiClash.c
//  1730 Test Project/Game
//  FOR EDUCATIONAL/RECREATIONAL PURPOSES ONLY
//  Please do not distribute without sole permission of the author
//
//  Created by Aaron Tharpe on 8/29/14.
//  Copyright (c) 2014 Aaron Tharpe. All rights reserved.
//  trsturbo@uga.edu


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define WIZARD 1
#define ALIEN  2
#define KNIGHT 3
#define true   1
#define false  0

//Function that takes in paramater in seconds, and produces a timed delay
void delayFunction(int delayTime){
    time_t now;
    now = time(0);
    time_t future = time(NULL) + delayTime;
    long futureInt = future;
    
    while (now < futureInt) {
        //do nothing
        now = time(0);
    }
}


int main(int argc, const char * argv[]) {
    
    void delay(int milliseconds);
    srand( time( NULL ) );
    
    //initializations
    int characterSelectionNum = 0;
    char characterSelectionText[10];
    int compSelectionNum = (rand() % 3) + 1;
    char compSelectionText[10];
    int validInput = false;
    int compHealth = 20;
    int playerHealth = 20;
    int compDamage;
    int playerDamage;
    int compChance;
    int playerChance;
    int wizardChance;
    int alienChance;
    int knightChance;
    int totalDamage;
    int totalCompDamage = 0;
    
    //Intro
    printf("///////////////////////\n/WELCOME TO MYTHICLASH/\n///////////////////////\n\n");
    delayFunction(2);
    printf("Please choose a character number:\n***********\n|(1)Wizard|  - 30 percent chance each round to do double damage\n***********");
    printf("\n|(2)Alien|   - 2 extra pts. damage each turn with 30 percent chance to regenerate 3pts of health\n***********");
    printf("\n|(3)Knight|  - 2 pts. health regen each turn with 20 percent chance to deflect 80 percent of incoming damage\n***********\n");
    
    
    //Loop to confirm number is between 1-3 and sets player's character preference
    while (validInput == false){
        scanf("%d", &characterSelectionNum);
    if (characterSelectionNum == 1){
        strcpy(characterSelectionText, "Wizard");
        validInput = true;
    } else if (characterSelectionNum == 2){
        strcpy(characterSelectionText, "Alien");
        validInput = true;
    } else if (characterSelectionNum == 3){
        strcpy(characterSelectionText, "Knight");
        validInput = true;
    } else {
        printf("Invalid input, please try again");
        validInput = false;
    }
    }
    
    //Assignment of comp's character from random number initilization
    if (compSelectionNum == 1){
        strcpy(compSelectionText, "Wizard");
        validInput = true;
    } else if (compSelectionNum == 2){
        strcpy(compSelectionText, "Alien");
        validInput = true;
    } else if (compSelectionNum == 3){
        strcpy(compSelectionText, "Knight");
        validInput = true;
    }
    printf("------------\n|GAME START|\n------------\n\n\nCharacter selection: %s\n", characterSelectionText);
    delayFunction(2);
    printf("Computer's character selection: %s\n", compSelectionText);
    delayFunction(2);
    printf("~~~~~~\n%s\n~~~~~~ \nVERSUS \n~~~~~~\n%s\n~~~~~~", characterSelectionText, compSelectionText);
    delayFunction(4);
    
    
    
   /*///////////////////////////////////////
    BEGIN GAME MECHANICS
   *////////////////////////////////////////
    
    
    
    
    while (playerHealth > 0 && compHealth > 0) { //START GAME UNTIL EITHER HEALTH REACHES 0
        
        if (compHealth < 1){
            break;
        }
    
    printf("\n\n-----------\n|YOUR TURN|\n-----------\nPlease enter the damage number 1-10: \n");
    scanf("%d", &playerDamage);
    printf("\n");
        totalDamage = 0;
        
    if (playerDamage == 1){ //if the damage is 1 (%100 damage chance)
        compHealth--;
        totalDamage++;
        printf("Guarenteed hit! 1pt damage.\n");
        delayFunction(2);
        
        //begin character specific traits
        if (characterSelectionNum == 1){ //if player is a wizard
            wizardChance = 1 + (rand() % 10);
            printf("Wizard power attempting...\n");
            delayFunction(2);
            
            if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                compHealth = compHealth - (playerDamage*2);
                totalDamage = (playerDamage*2);
                printf("Wizard bonus achieved! Double damage!\n");
                delayFunction(2);
            
            } else { //if %10 is not met
                printf("Wizard bonus failed.\n");
                delayFunction(2);
            }
            
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
        
        } else if (characterSelectionNum == 2){ //extra 2 damage if player is alien
            alienChance = 1 + (rand() % 10);
            printf("Alien bonus attempting...\n");
            delayFunction(2);
            
            if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                printf("Alien bonus achieved! + 3hp\n");
                playerHealth += 3;
                delayFunction(2);
            } else {
                printf("Alien bonus failed\n");
                delayFunction(2);
            }
            compHealth = compHealth - 2;
            totalDamage = totalDamage + 2;
             printf("Alien damage attack! - 2pts");
            delayFunction(3);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        } else if (characterSelectionNum == 3){ //extra health if player is knight
            printf("Knight bonus attempting...\n");
            delayFunction(2);
            if(knightChance == 1 || knightChance == 5){
                if (totalCompDamage > 0){
                printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                    playerHealth = playerHealth + (totalCompDamage/0.2);
                    delayFunction(2);
                } else {
                    printf("No previous attack, bonus void\n");
                    delayFunction(2);
                }
            } else {
                printf("Knight bonus failed.\n");
                delayFunction(2);
            }
            playerHealth += 2;
            delayFunction(2);
            printf("Knight health regen! +2hp");
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        }
        //end character specific traits
        
    } else if (playerDamage == 2){
        playerChance = 1 + (rand() % 10); //chance player will hit target
        if (playerChance == 1 || playerChance == 2 || playerChance == 3 || playerChance == 4 || playerChance == 5 || playerChance == 6 || playerChance == 7 || playerChance == 8 || playerChance == 9){
            compHealth = compHealth - playerDamage;
            totalDamage = playerDamage;
            printf("\nAttack hit!\n");
        } else {
            printf("Attack miss! NO DAMAGE DONE\n");
        }
        
        //begin character specific traits
        if (characterSelectionNum == 1){ //if player is a wizard
            wizardChance = 1 + (rand() % 10);
            printf("Wizard power attempting...\n");
            delayFunction(2);
            
            if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                compHealth = compHealth - (playerDamage*2);
                totalDamage = (playerDamage*2);
                printf("Wizard bonus achieved! Double damage!\n");
                delayFunction(2);
                
            } else { //if %10 is not met
                printf("Wizard bonus failed.\n");
                delayFunction(2);
            }
            
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
            
        } else if (characterSelectionNum == 2){ //extra 2 damage if player is alien
            alienChance = 1 + (rand() % 10);
            printf("Alien bonus attempting...\n");
            delayFunction(2);
            
            if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                printf("Alien bonus achieved! + 3hp\n");
                playerHealth += 3;
                delayFunction(2);
            } else {
                printf("Alien bonus failed\n");
                delayFunction(2);
            }
            compHealth = compHealth - 2;
            totalDamage = totalDamage + 2;
             printf("Alien damage attack! - 2pts");
            delayFunction(3);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        } else if (characterSelectionNum == 3){ //extra health if player is knight
            printf("Knight bonus attempting...\n");
            delayFunction(2);
            if(knightChance == 1 || knightChance == 5){
                if (totalCompDamage > 0){
                printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                    playerHealth = playerHealth + (totalCompDamage/0.2);
                    delayFunction(2);
                } else {
                    printf("No previous attack, bonus void\n");
                    delayFunction(2);
                }
            } else {
                printf("Knight bonus failed.\n");
                delayFunction(2);
            }
            playerHealth += 2;
            delayFunction(2);
            printf("Knight health regen! +2hp");
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        }
        //end character specific traits
    
    } else if (playerDamage == 3){
        playerChance = 1 + (rand() % 10); //chance player will hit target
        if (playerChance == 1 || playerChance == 2 || playerChance == 3 || playerChance == 4 || playerChance == 5 || playerChance == 6 || playerChance == 7 || playerChance == 8 ){
            compHealth = compHealth - playerDamage;
            totalDamage = playerDamage;
            printf("\nAttack hit!\n");
        } else {
            printf("Attack miss! NO DAMAGE DONE\n");
        }
        
        //begin character specific traits
        if (characterSelectionNum == 1){ //if player is a wizard
            wizardChance = 1 + (rand() % 10);
            printf("Wizard power attempting...\n");
            delayFunction(2);
            
            if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                compHealth = compHealth - (playerDamage*2);
                totalDamage = (playerDamage*2);
                printf("Wizard bonus achieved! Double damage!\n");
                delayFunction(2);
            
            } else { //if %10 is not met
                printf("Wizard bonus failed.\n");
                delayFunction(2);
            }
            
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
        
        } else if (characterSelectionNum == 2){ //extra 2 damage if player is alien
            alienChance = 1 + (rand() % 10);
            printf("Alien bonus attempting...\n");
            delayFunction(2);
            
            if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                printf("Alien bonus achieved! + 3hp\n");
                playerHealth += 3;
                delayFunction(2);
            } else {
                printf("Alien bonus failed\n");
                delayFunction(2);
            }
            compHealth = compHealth - 2;
            totalDamage = totalDamage + 2;
             printf("Alien damage attack! - 2pts");
            delayFunction(3);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        } else if (characterSelectionNum == 3){ //extra health if player is knight
            printf("Knight bonus attempting...\n");
            delayFunction(2);
            if(knightChance == 1 || knightChance == 5){
                if (totalCompDamage > 0){
                printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                    playerHealth = playerHealth + (totalCompDamage/0.2);
                    delayFunction(2);
                } else {
                    printf("No previous attack, bonus void\n");
                    delayFunction(2);
                }
            } else {
                printf("Knight bonus failed.\n");
                delayFunction(2);
            }
            playerHealth += 2;
            delayFunction(2);
            printf("Knight health regen! +2hp");
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        }
        //end character specific traits
        
    } else if (playerDamage == 4){
        playerChance = 1 + (rand() % 10); //chance player will hit target
        if (playerChance == 1 || playerChance == 2 || playerChance == 3 || playerChance == 4 || playerChance == 5 || playerChance == 6 || playerChance == 7 ){
            compHealth = compHealth - playerDamage;
            totalDamage = playerDamage;
            printf("\nAttack hit!\n");
        } else {
            printf("Attack miss! NO DAMAGE DONE\n");
        }
        
        //begin character specific traits
        if (characterSelectionNum == 1){ //if player is a wizard
            wizardChance = 1 + (rand() % 10);
            printf("Wizard power attempting...\n");
            delayFunction(2);
            
            if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                compHealth = compHealth - (playerDamage*2);
                totalDamage = (playerDamage*2);
                printf("Wizard bonus achieved! Double damage!\n");
                delayFunction(2);
            
            } else { //if %10 is not met
                printf("Wizard bonus failed.\n");
                delayFunction(2);
            }
            
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
        
        } else if (characterSelectionNum == 2){ //extra 2 damage if player is alien
            alienChance = 1 + (rand() % 10);
            printf("Alien bonus attempting...\n");
            delayFunction(2);
            
            if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                printf("Alien bonus achieved! + 3hp\n");
                playerHealth += 3;
                delayFunction(2);
            } else {
                printf("Alien bonus failed\n");
                delayFunction(2);
            }
            compHealth = compHealth - 2;
            totalDamage = totalDamage + 2;
             printf("Alien damage attack! - 2pts");
            delayFunction(3);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        } else if (characterSelectionNum == 3){ //extra health if player is knight
            printf("Knight bonus attempting...\n");
            delayFunction(2);
            if(knightChance == 1 || knightChance == 5){
                if (totalCompDamage > 0){
                printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                    playerHealth = playerHealth + (totalCompDamage/0.2);
                    delayFunction(2);
                } else {
                    printf("No previous attack, bonus void\n");
                    delayFunction(2);
                }
            } else {
                printf("Knight bonus failed.\n");
                delayFunction(2);
            }
            playerHealth += 2;
            delayFunction(2);
            printf("Knight health regen! +2hp");
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        }
        //end character specific traits
        
    } else if (playerDamage == 5){
        playerChance = 1 + (rand() % 10); //chance player will hit target
        if (playerChance == 1 || playerChance == 2 || playerChance == 3 || playerChance == 4 || playerChance == 5 || playerChance == 6 ){
            compHealth = compHealth - playerDamage;
            totalDamage = playerDamage;
            printf("\nAttack hit!\n");
        } else {
            printf("Attack miss! NO DAMAGE DONE\n");
        }
        
        //begin character specific traits
        if (characterSelectionNum == 1){ //if player is a wizard
            wizardChance = 1 + (rand() % 10);
            printf("Wizard power attempting...\n");
            delayFunction(2);
            
            if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                compHealth = compHealth - (playerDamage*2);
                totalDamage = (playerDamage*2);
                printf("Wizard bonus achieved! Double damage!\n");
                delayFunction(2);
            
            } else { //if %10 is not met
                printf("Wizard bonus failed.\n");
                delayFunction(2);
            }
            
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
        
        } else if (characterSelectionNum == 2){ //extra 2 damage if player is alien
            alienChance = 1 + (rand() % 10);
            printf("Alien bonus attempting...\n");
            delayFunction(2);
            
            if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                printf("Alien bonus achieved! + 3hp\n");
                playerHealth += 3;
                delayFunction(2);
            } else {
                printf("Alien bonus failed\n");
                delayFunction(2);
            }
            compHealth = compHealth - 2;
            totalDamage = totalDamage + 2;
             printf("Alien damage attack! - 2pts");
            delayFunction(3);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        } else if (characterSelectionNum == 3){ //extra health if player is knight
            printf("Knight bonus attempting...\n");
            delayFunction(2);
            if(knightChance == 1 || knightChance == 5){
                if (totalCompDamage > 0){
                printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                    playerHealth = playerHealth + (totalCompDamage/0.2);
                    delayFunction(2);
                } else {
                    printf("No previous attack, bonus void\n");
                    delayFunction(2);
                }
            } else {
                printf("Knight bonus failed.\n");
                delayFunction(2);
            }
            playerHealth += 2;
            delayFunction(2);
            printf("Knight health regen! +2hp");
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        }
        //end character specific traits
    
    } else if (playerDamage == 6){
        playerChance = 1 + (rand() % 10); //chance player will hit target
        if (playerChance == 1 || playerChance == 2 || playerChance == 3 || playerChance == 4 || playerChance == 5){
            compHealth = compHealth - playerDamage;
            totalDamage = playerDamage;
            printf("\nAttack hit!\n");
        } else {
            printf("Attack miss! NO DAMAGE DONE\n");
        }
        
        //begin character specific traits
        if (characterSelectionNum == 1){ //if player is a wizard
            wizardChance = 1 + (rand() % 10);
            printf("Wizard power attempting...\n");
            delayFunction(2);
            
            if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                compHealth = compHealth - (playerDamage*2);
                totalDamage = (playerDamage*2);
                printf("Wizard bonus achieved! Double damage!\n");
                delayFunction(2);
            
            } else { //if %10 is not met
                printf("Wizard bonus failed.\n");
                delayFunction(2);
            }
            
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
        
        } else if (characterSelectionNum == 2){ //extra 2 damage if player is alien
            alienChance = 1 + (rand() % 10);
            printf("Alien bonus attempting...\n");
            delayFunction(2);
            
            if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                printf("Alien bonus achieved! + 3hp\n");
                playerHealth += 3;
                delayFunction(2);
            } else {
                printf("Alien bonus failed\n");
                delayFunction(2);
            }
            compHealth = compHealth - 2;
            totalDamage = totalDamage + 2;
             printf("Alien damage attack! - 2pts");
            delayFunction(3);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        } else if (characterSelectionNum == 3){ //extra health if player is knight
            printf("Knight bonus attempting...\n");
            delayFunction(2);
            if(knightChance == 1 || knightChance == 5){
                if (totalCompDamage > 0){
                printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                    playerHealth = playerHealth + (totalCompDamage/0.2);
                    delayFunction(2);
                } else {
                    printf("No previous attack, bonus void\n");
                    delayFunction(2);
                }
            } else {
                printf("Knight bonus failed.\n");
                delayFunction(2);
            }
            playerHealth += 2;
            delayFunction(2);
            printf("Knight health regen! +2hp");
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        }
        //end character specific traits
        
    } else if (playerDamage == 7){
        playerChance = 1 + (rand() % 10); //chance player will hit target
        if (playerChance == 1 || playerChance == 2 || playerChance == 3 || playerChance == 4){
            compHealth = compHealth - playerDamage;
            totalDamage = playerDamage;
            printf("\nAttack hit!\n");
        } else {
            printf("Attack miss! NO DAMAGE DONE\n");
        }
        
        //begin character specific traits
        if (characterSelectionNum == 1){ //if player is a wizard
            wizardChance = 1 + (rand() % 10);
            printf("Wizard power attempting...\n");
            delayFunction(2);
            
            if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                compHealth = compHealth - (playerDamage*2);
                totalDamage = (playerDamage*2);
                printf("Wizard bonus achieved! Double damage!\n");
                delayFunction(2);
            
            } else { //if %10 is not met
                printf("Wizard bonus failed.\n");
                delayFunction(2);
            }
            
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
        
        } else if (characterSelectionNum == 2){ //extra 2 damage if player is alien
            alienChance = 1 + (rand() % 10);
            printf("Alien bonus attempting...\n");
            delayFunction(2);
            
            if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                printf("Alien bonus achieved! + 3hp\n");
                playerHealth += 3;
                delayFunction(2);
            } else {
                printf("Alien bonus failed\n");
                delayFunction(2);
            }
            compHealth = compHealth - 2;
            totalDamage = totalDamage + 2;
             printf("Alien damage attack! - 2pts");
            delayFunction(3);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        } else if (characterSelectionNum == 3){ //extra health if player is knight
            printf("Knight bonus attempting...\n");
            delayFunction(2);
            if(knightChance == 1 || knightChance == 5){
                if (totalCompDamage > 0){
                printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                    playerHealth = playerHealth + (totalCompDamage/0.2);
                    delayFunction(2);
                } else {
                    printf("No previous attack, bonus void\n");
                    delayFunction(2);
                }
            } else {
                printf("Knight bonus failed.\n");
                delayFunction(2);
            }
            playerHealth += 2;
            delayFunction(2);
            printf("Knight health regen! +2hp");
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        }
        //end character specific traits
        
    } else if (playerDamage == 8){
        playerChance = 1 + (rand() % 10); //chance player will hit target
        if (playerChance == 1 || playerChance == 2 || playerChance == 3){
            compHealth = compHealth - playerDamage;
            totalDamage = playerDamage;
            printf("\nAttack hit!\n");
        } else {
            printf("Attack miss! NO DAMAGE DONE\n");
        }
        
        //begin character specific traits
        if (characterSelectionNum == 1){ //if player is a wizard
            wizardChance = 1 + (rand() % 10);
            printf("Wizard power attempting...\n");
            delayFunction(2);
            
            if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                compHealth = compHealth - (playerDamage*2);
                totalDamage = (playerDamage*2);
                printf("Wizard bonus achieved! Double damage!\n");
                delayFunction(2);
            
            } else { //if %10 is not met
                printf("Wizard bonus failed.\n");
                delayFunction(2);
            }
            
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
        
        } else if (characterSelectionNum == 2){ //extra 2 damage if player is alien
            alienChance = 1 + (rand() % 10);
            printf("Alien bonus attempting...\n");
            delayFunction(2);
            
            if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                printf("Alien bonus achieved! + 3hp\n");
                playerHealth += 3;
                delayFunction(2);
            } else {
                printf("Alien bonus failed\n");
                delayFunction(2);
            }
            compHealth = compHealth - 2;
            totalDamage = totalDamage + 2;
             printf("Alien damage attack! - 2pts");
            delayFunction(3);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        } else if (characterSelectionNum == 3){ //extra health if player is knight
            printf("Knight bonus attempting...\n");
            delayFunction(2);
            if(knightChance == 1 || knightChance == 5){
                if (totalCompDamage > 0){
                printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                    playerHealth = playerHealth + (totalCompDamage/0.2);
                    delayFunction(2);
                } else {
                    printf("No previous attack, bonus void\n");
                    delayFunction(2);
                }
            } else {
                printf("Knight bonus failed.\n");
                delayFunction(2);
            }
            playerHealth += 2;
            delayFunction(2);
            printf("Knight health regen! +2hp");
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        }
        //end character specific traits
        
    } else if (playerDamage == 9){
        playerChance = 1 + (rand() % 10); //chance player will hit target
        if (playerChance == 1 || playerChance == 2){
            compHealth = compHealth - playerDamage;
            totalDamage = playerDamage;
            printf("\nAttack hit!\n");
        } else {
            printf("Attack miss! NO DAMAGE DONE\n");
        }
        
        //begin character specific traits
        if (characterSelectionNum == 1){ //if player is a wizard
            wizardChance = 1 + (rand() % 10);
            printf("Wizard power attempting...\n");
            delayFunction(2);
            
            if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                compHealth = compHealth - (playerDamage*2);
                totalDamage = (playerDamage*2);
                printf("Wizard bonus achieved! Double damage!\n");
                delayFunction(2);
            
            } else { //if %10 is not met
                printf("Wizard bonus failed.\n");
                delayFunction(2);
            }
            
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
        
        } else if (characterSelectionNum == 2){ //extra 2 damage if player is alien
            alienChance = 1 + (rand() % 10);
            printf("Alien bonus attempting...\n");
            delayFunction(2);
            
            if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                printf("Alien bonus achieved! + 3hp\n");
                playerHealth += 3;
                delayFunction(2);
            } else {
                printf("Alien bonus failed\n");
                delayFunction(2);
            }
            compHealth = compHealth - 2;
            totalDamage = totalDamage + 2;
             printf("Alien damage attack! - 2pts");
            delayFunction(3);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        } else if (characterSelectionNum == 3){ //extra health if player is knight
            printf("Knight bonus attempting...\n");
            delayFunction(2);
            if(knightChance == 1 || knightChance == 5){
                if (totalCompDamage > 0){
                printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                    playerHealth = playerHealth + (totalCompDamage/0.2);
                    delayFunction(2);
                } else {
                    printf("No previous attack, bonus void\n");
                    delayFunction(2);
                }
            } else {
                printf("Knight bonus failed.\n");
                delayFunction(2);
            }
            playerHealth += 2;
            delayFunction(2);
            printf("Knight health regen! +2hp");
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        }
        //end character specific traits
        
    } else if (playerDamage == 10){
        playerChance = 1 + (rand() % 10); //chance player will hit target
        if (playerChance == 9){
            compHealth = compHealth - playerDamage;
            totalDamage = playerDamage;
            printf("\nAttack hit!\n");
        } else {
            printf("Attack miss! NO DAMAGE DONE\n");
        }
        
        //begin character specific traits
        if (characterSelectionNum == 1){ //if player is a wizard
            wizardChance = 1 + (rand() % 10);
            printf("Wizard power attempting...\n");
            delayFunction(2);
            
            if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                compHealth = compHealth - (playerDamage*2);
                totalDamage = (playerDamage*2);
                printf("Wizard bonus achieved! Double damage!\n");
                delayFunction(2);
            
            } else { //if %10 is not met
                printf("Wizard bonus failed.\n");
                delayFunction(2);
            }
            
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
        
        } else if (characterSelectionNum == 2){ //extra 2 damage if player is alien
            alienChance = 1 + (rand() % 10);
            printf("Alien bonus attempting...\n");
            delayFunction(2);
            
            if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                printf("Alien bonus achieved! + 3hp\n");
                playerHealth += 3;
                delayFunction(2);
            } else {
                printf("Alien bonus failed\n");
                delayFunction(2);
            }
            compHealth = compHealth - 2;
            totalDamage = totalDamage + 2;
             printf("Alien damage attack! - 2pts");
            delayFunction(3);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        } else if (characterSelectionNum == 3){ //extra health if player is knight
            printf("Knight bonus attempting...\n");
            delayFunction(2);
            if(knightChance == 1 || knightChance == 5){
                if (totalCompDamage > 0){
                printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                    playerHealth = playerHealth + (totalCompDamage/0.2);
                    delayFunction(2);
                } else {
                    printf("No previous attack, bonus void\n");
                    delayFunction(2);
                }
            } else {
                printf("Knight bonus failed.\n");
                delayFunction(2);
            }
            playerHealth += 2;
            delayFunction(2);
            printf("Knight health regen! +2hp");
            delayFunction(2);
            printf("\n\nTURN COMPLETE\nTotal turn damage = %d\nRemaining Health: %d\nOpponent Health: %d\n", totalDamage, playerHealth, compHealth);
            delayFunction(4);
             
            while( getchar() != '\n' );
        }
        //end character specific traits
        
    }
    
/////////////////////////////
    //END PLAYER TURN
////////////////////////////
        
        
        
////////////////////////////
    //BEGIN COMPUTER TURN
////////////////////////////
        
        if (compHealth < 1){
            break;
        }
        
        printf("\n\n-----------------\n|OPPONENT'S TURN|\n-----------------\n\n");
        totalCompDamage = 0;
        delayFunction(2);
        compDamage = 1 + (rand() % 10);
        printf("\n\nComputer damage selection: %d\n", compDamage);
    
        if (compDamage == 1){ //if the damage is 1 (%100 damage chance)
            playerHealth--;
            totalCompDamage++;
            delayFunction(2);
            printf("Guarenteed hit! 1pt damage.\n");
            
            //begin character specific traits
            if (compSelectionNum == 1){ //if player is a wizard
                wizardChance = 1 + (rand() % 10);
                delayFunction(2);
                printf("Wizard power attempting...\n");
        
                if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                    playerHealth = playerHealth - (compDamage*2);
                    totalCompDamage = (compDamage*2);
                    delayFunction(2);
                    printf("Wizard bonus achieved! Double damage!\n");
                    
                } else { //if %10 is not met
                    delayFunction(2);
                    printf("Wizard bonus failed.\n");
                }
                
                delayFunction(2);
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            
            } else if (compSelectionNum == 2){ //extra 2 damage if player is alien
                alienChance = 1 + (rand() % 10);
                printf("Alien bonus attempting...\n");
                delayFunction(2);
                
                if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                    printf("Alien bonus achieved! + 3hp\n");
                    compHealth += 3;
                    delayFunction(2);
                } else {
                    printf("Alien bonus failed\n");
                    delayFunction(2);
                }
                playerHealth -= 2;
                totalDamage = totalDamage + 2;
                printf("Alien damage attack! - 2pts");
                delayFunction(2);
                totalCompDamage = totalCompDamage + 2;
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (characterSelectionNum == 3){ //extra health if player is knight
                printf("Knight bonus attempting...");
                delayFunction(2);
                if(knightChance == 1 || knightChance == 5){
                    if (totalDamage > 0){
                        printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                        compHealth = compHealth + (totalDamage/0.2);
                        delayFunction(2);
                    } else {
                        printf("No previous attack, bonus void\n");
                        delayFunction(2);
                    }
                } else {
                    printf("Knight bonus failed.\n");
                compHealth += 2;
                delayFunction(2);
                printf("Knight health regen! +2hp");
                delayFunction(2);
                printf("\n\nOPPONENT TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            }
            //end character specific traits
            }
        } else if (compDamage == 2){
            compChance = 1 + (rand() % 10); //chance player will hit target
            if (compChance == 1 || compChance == 2 || compChance == 3 || compChance == 4 || compChance == 5 || compChance == 6 || compChance == 7 || compChance == 8 || compChance == 9){
                playerHealth = playerHealth - compDamage;
                printf("\nAttack hit!\n");
                totalCompDamage += 2;
            } else {
                printf("Attack miss! NO DAMAGE DONE\n");
            }
            
            //begin character specific traits
            if (compSelectionNum == 1){ //if player is a wizard
                wizardChance = 1 + (rand() % 10);
                delayFunction(2);
                printf("Wizard power attempting...\n");
                
                if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                    playerHealth = playerHealth - (compDamage*2);
                    totalCompDamage = (compDamage*2);
                    delayFunction(2);
                    printf("Wizard bonus achieved! Double damage!\n");
                    
                } else { //if %10 is not met
                    delayFunction(2);
                    printf("Wizard bonus failed.\n");
                }
                
                delayFunction(2);
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (compSelectionNum == 2){ //extra 2 damage if player is alien
                alienChance = 1 + (rand() % 10);
                printf("Alien bonus attempting...\n");
                delayFunction(2);
                
                if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                    printf("Alien bonus achieved! + 3hp\n");
                    compHealth += 3;
                    delayFunction(2);
                } else {
                    printf("Alien bonus failed\n");
                    delayFunction(2);
                }
                playerHealth -= 2;
                totalDamage = totalDamage + 2;
                printf("Alien damage attack! - 2pts");
                delayFunction(2);
                totalCompDamage = totalCompDamage + 2;
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (characterSelectionNum == 3){ //extra health if player is knight
                printf("Knight bonus attempting...");
                delayFunction(2);
                if(knightChance == 1 || knightChance == 5){
                    if (totalDamage > 0){
                        printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                        compHealth = compHealth + (totalDamage/0.2);
                        delayFunction(2);
                    } else {
                        printf("No previous attack, bonus void\n");
                        delayFunction(2);
                    }
                } else {
                    printf("Knight bonus failed.\n");
                compHealth += 2;
                delayFunction(2);
                printf("Knight health regen! +2hp");
                delayFunction(2);
                printf("\n\nOPPONENT TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            }
            //end character specific traits
            }
        } else if (compDamage == 3){
            compChance = 1 + (rand() % 10); //chance player will hit target
            if (compChance == 1 || compChance == 2 || compChance == 3 || compChance == 4 || compChance == 5 || compChance == 6 || compChance == 7 || compChance == 8){
                playerHealth = playerHealth - compDamage;
                printf("\nAttack hit!\n");
                totalCompDamage += 3;
            } else {
                printf("Attack miss! NO DAMAGE DONE\n");
            }
            
            //begin character specific traits
            if (compSelectionNum == 1){ //if player is a wizard
                wizardChance = 1 + (rand() % 10);
                delayFunction(2);
                printf("Wizard power attempting...\n");
                
                if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                    playerHealth = playerHealth - (compDamage*2);
                    totalCompDamage = (compDamage*2);
                    delayFunction(2);
                    printf("Wizard bonus achieved! Double damage!\n");
                    
                } else { //if %10 is not met
                    delayFunction(2);
                    printf("Wizard bonus failed.\n");
                }
                
                delayFunction(2);
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (compSelectionNum == 2){ //extra 2 damage if player is alien
                alienChance = 1 + (rand() % 10);
                printf("Alien bonus attempting...\n");
                delayFunction(2);
                
                if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                    printf("Alien bonus achieved! + 3hp\n");
                    compHealth += 3;
                    delayFunction(2);
                } else {
                    printf("Alien bonus failed\n");
                    delayFunction(2);
                }
                playerHealth -= 2;
                totalDamage = totalDamage + 2;
                printf("Alien damage attack! - 2pts");
                delayFunction(2);
                totalCompDamage = totalCompDamage + 2;
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            
            } else if (characterSelectionNum == 3){ //extra health if player is knight
                printf("Knight bonus attempting...");
                delayFunction(2);
                if(knightChance == 1 || knightChance == 5){
                    if (totalDamage > 0){
                        printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                        compHealth = compHealth + (totalDamage/0.2);
                        delayFunction(2);
                    } else {
                        printf("No previous attack, bonus void\n");
                        delayFunction(2);
                    }
                } else {
                    printf("Knight bonus failed.\n");
                compHealth += 2;
                delayFunction(2);
                printf("Knight health regen! +2hp");
                delayFunction(2);
                printf("\n\nOPPONENT TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            }
            //end character specific traits
            }
        } else if (compDamage == 4){
            compChance = 1 + (rand() % 10); //chance player will hit target
            if (compChance == 1 || compChance == 2 || compChance == 3 || compChance == 4 || compChance == 5 || compChance == 6 || compChance == 7){
                playerHealth = playerHealth - compDamage;
                printf("\nAttack hit!\n");
                totalCompDamage += 4;
            } else {
                printf("Attack miss! NO DAMAGE DONE\n");
            }
            
            //begin character specific traits
            if (compSelectionNum == 1){ //if player is a wizard
                wizardChance = 1 + (rand() % 10);
                delayFunction(2);
                printf("Wizard power attempting...\n");
                
                if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                    playerHealth = playerHealth - (compDamage*2);
                    totalCompDamage = (compDamage*2);
                    delayFunction(2);
                    printf("Wizard bonus achieved! Double damage!\n");
                    
                } else { //if %10 is not met
                    delayFunction(2);
                    printf("Wizard bonus failed.\n");
                }
                
                delayFunction(2);
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (compSelectionNum == 2){ //extra 2 damage if player is alien
                alienChance = 1 + (rand() % 10);
                printf("Alien bonus attempting...\n");
                delayFunction(2);
                
                if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                    printf("Alien bonus achieved! + 3hp\n");
                    compHealth += 3;
                    delayFunction(2);
                } else {
                    printf("Alien bonus failed\n");
                    delayFunction(2);
                }
                playerHealth -= 2;
                totalDamage = totalDamage + 2;
                printf("Alien damage attack! - 2pts");
                delayFunction(2);
                totalCompDamage = totalCompDamage + 2;
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (characterSelectionNum == 3){ //extra health if player is knight
                printf("Knight bonus attempting...");
                delayFunction(2);
                if(knightChance == 1 || knightChance == 5){
                    if (totalDamage > 0){
                        printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                        compHealth = compHealth + (totalDamage/0.2);
                        delayFunction(2);
                    } else {
                        printf("No previous attack, bonus void\n");
                        delayFunction(2);
                    }
                } else {
                    printf("Knight bonus failed.\n");
                compHealth += 2;
                delayFunction(2);
                printf("Knight health regen! +2hp");
                delayFunction(2);
                printf("\n\nOPPONENT TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            }
            //end character specific traits
            }
        } else if (compDamage == 5){
            compChance = 1 + (rand() % 10); //chance player will hit target
            if (compChance == 1 || compChance == 2 || compChance == 3 || compChance == 4 || compChance == 5 || compChance == 6){
                playerHealth = playerHealth - compDamage;
                printf("\nAttack hit!\n");
                totalCompDamage += 5;
            } else {
                printf("Attack miss! NO DAMAGE DONE\n");
            }
            
            //begin character specific traits
            if (compSelectionNum == 1){ //if player is a wizard
                wizardChance = 1 + (rand() % 10);
                delayFunction(2);
                printf("Wizard power attempting...\n");
                
                if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                    playerHealth = playerHealth - (compDamage*2);
                    totalCompDamage = (compDamage*2);
                    delayFunction(2);
                    printf("Wizard bonus achieved! Double damage!\n");
                    
                } else { //if %10 is not met
                    delayFunction(2);
                    printf("Wizard bonus failed.\n");
                }
                
                delayFunction(2);
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (compSelectionNum == 2){ //extra 2 damage if player is alien
                alienChance = 1 + (rand() % 10);
                printf("Alien bonus attempting...\n");
                delayFunction(2);
                
                if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                    printf("Alien bonus achieved! + 3hp\n");
                    compHealth += 3;
                    delayFunction(2);
                } else {
                    printf("Alien bonus failed\n");
                    delayFunction(2);
                }
                playerHealth -= 2;
                totalDamage = totalDamage + 2;
                printf("Alien damage attack! - 2pts");
                delayFunction(2);
                totalCompDamage = totalCompDamage + 2;
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (characterSelectionNum == 3){ //extra health if player is knight
                printf("Knight bonus attempting...");
                delayFunction(2);
                if(knightChance == 1 || knightChance == 5){
                    if (totalDamage > 0){
                        printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                        compHealth = compHealth + (totalDamage/0.2);
                        delayFunction(2);
                    } else {
                        printf("No previous attack, bonus void\n");
                        delayFunction(2);
                    }
                } else {
                    printf("Knight bonus failed.\n");
                compHealth += 2;
                delayFunction(2);
                printf("Knight health regen! +2hp");
                delayFunction(2);
                printf("\n\nOPPONENT TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            }
            //end character specific traits
            }
        } else if (compDamage == 6){
            compChance = 1 + (rand() % 10); //chance player will hit target
            if (compChance == 1 || compChance == 2 || compChance == 3 || compChance == 4 || compChance == 5){
                playerHealth = playerHealth - compDamage;
                printf("\nAttack hit!\n");
                totalCompDamage += 6;
            } else {
                printf("Attack miss! NO DAMAGE DONE\n");
            }
            
            //begin character specific traits
            if (compSelectionNum == 1){ //if player is a wizard
                wizardChance = 1 + (rand() % 10);
                delayFunction(2);
                printf("Wizard power attempting...\n");
                
                if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                    playerHealth = playerHealth - (compDamage*2);
                    totalCompDamage = (compDamage*2);
                    delayFunction(2);
                    printf("Wizard bonus achieved! Double damage!\n");
                    
                } else { //if %10 is not met
                    delayFunction(2);
                    printf("Wizard bonus failed.\n");
                }
                
                delayFunction(2);
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (compSelectionNum == 2){ //extra 2 damage if player is alien
                alienChance = 1 + (rand() % 10);
                printf("Alien bonus attempting...\n");
                delayFunction(2);
                
                if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                    printf("Alien bonus achieved! + 3hp\n");
                    compHealth += 3;
                    delayFunction(2);
                } else {
                    printf("Alien bonus failed\n");
                    delayFunction(2);
                }
                playerHealth -= 2;
                totalDamage = totalDamage + 2;
                printf("Alien damage attack! - 2pts");
                delayFunction(2);
                totalCompDamage = totalCompDamage + 2;
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (characterSelectionNum == 3){ //extra health if player is knight
                printf("Knight bonus attempting...");
                delayFunction(2);
                if(knightChance == 1 || knightChance == 5){
                    if (totalDamage > 0){
                        printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                        compHealth = compHealth + (totalDamage/0.2);
                        delayFunction(2);
                    } else {
                        printf("No previous attack, bonus void\n");
                        delayFunction(2);
                    }
                } else {
                    printf("Knight bonus failed.\n");
                compHealth += 2;
                delayFunction(2);
                printf("Knight health regen! +2hp");
                delayFunction(2);
                printf("\n\nOPPONENT TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            }
            //end character specific traits
            }
        } else if (compDamage == 7){
            compChance = 1 + (rand() % 10); //chance player will hit target
            if (compChance == 1 || compChance == 2 || compChance == 3 || compChance == 4){
                playerHealth = playerHealth - compDamage;
                printf("\nAttack hit!\n");
                totalCompDamage += 7;
            } else {
                printf("Attack miss! NO DAMAGE DONE\n");
            }
            
            //begin character specific traits
            if (compSelectionNum == 1){ //if player is a wizard
                wizardChance = 1 + (rand() % 10);
                delayFunction(2);
                printf("Wizard power attempting...\n");
                
                if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                    playerHealth = playerHealth - (compDamage*2);
                    totalCompDamage = (compDamage*2);
                    delayFunction(2);
                    printf("Wizard bonus achieved! Double damage!\n");
                    
                } else { //if %10 is not met
                    delayFunction(2);
                    printf("Wizard bonus failed.\n");
                }
                
                delayFunction(2);
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (compSelectionNum == 2){ //extra 2 damage if player is alien
                alienChance = 1 + (rand() % 10);
                printf("Alien bonus attempting...\n");
                delayFunction(2);
                
                if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                    printf("Alien bonus achieved! + 3hp\n");
                    compHealth += 3;
                    delayFunction(2);
                } else {
                    printf("Alien bonus failed\n");
                    delayFunction(2);
                }
                playerHealth -= 2;
                totalDamage = totalDamage + 2;
                printf("Alien damage attack! - 2pts");
                delayFunction(2);
                totalCompDamage = totalCompDamage + 2;
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (characterSelectionNum == 3){ //extra health if player is knight
                printf("Knight bonus attempting...");
                delayFunction(2);
                if(knightChance == 1 || knightChance == 5){
                    if (totalDamage > 0){
                        printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                        compHealth = compHealth + (totalDamage/0.2);
                        delayFunction(2);
                    } else {
                        printf("No previous attack, bonus void\n");
                        delayFunction(2);
                    }
                } else {
                    printf("Knight bonus failed.\n");
                compHealth += 2;
                delayFunction(2);
                printf("Knight health regen! +2hp");
                delayFunction(2);
                printf("\n\nOPPONENT TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            }
            //end character specific traits
            }
        } else if (compDamage == 8){
            compChance = 1 + (rand() % 10); //chance player will hit target
            if (compChance == 1 || compChance == 2 || compChance == 3){
                playerHealth = playerHealth - compDamage;
                printf("\nAttack hit!\n");
                totalCompDamage += 8;
            } else {
                printf("Attack miss! NO DAMAGE DONE\n");
            }
            
            //begin character specific traits
            if (compSelectionNum == 1){ //if player is a wizard
                wizardChance = 1 + (rand() % 10);
                delayFunction(2);
                printf("Wizard power attempting...\n");
                
                if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                    playerHealth = playerHealth - (compDamage*2);
                    totalCompDamage = (compDamage*2);
                    delayFunction(2);
                    printf("Wizard bonus achieved! Double damage!\n");
                    
                } else { //if %10 is not met
                    delayFunction(2);
                    printf("Wizard bonus failed.\n");
                }
                
                delayFunction(2);
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (compSelectionNum == 2){ //extra 2 damage if player is alien
                alienChance = 1 + (rand() % 10);
                printf("Alien bonus attempting...\n");
                delayFunction(2);
                
                if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                    printf("Alien bonus achieved! + 3hp\n");
                    compHealth += 3;
                    delayFunction(2);
                } else {
                    printf("Alien bonus failed\n");
                    delayFunction(2);
                }
                playerHealth -= 2;
                totalDamage = totalDamage + 2;
                printf("Alien damage attack! - 2pts");
                delayFunction(2);
                totalCompDamage = totalCompDamage + 2;
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (characterSelectionNum == 3){ //extra health if player is knight
                printf("Knight bonus attempting...");
                delayFunction(2);
                if(knightChance == 1 || knightChance == 5){
                    if (totalDamage > 0){
                        printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                        compHealth = compHealth + (totalDamage/0.2);
                        delayFunction(2);
                    } else {
                        printf("No previous attack, bonus void\n");
                        delayFunction(2);
                    }
                } else {
                    printf("Knight bonus failed.\n");
                compHealth += 2;
                delayFunction(2);
                printf("Knight health regen! +2hp");
                delayFunction(2);
                printf("\n\nOPPONENT TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            }
            //end character specific traits
            }
        } else if (compDamage == 9){
            compChance = 1 + (rand() % 10); //chance player will hit target
            if (compChance == 1 || compChance == 2){
                playerHealth = playerHealth - compDamage;
                printf("\nAttack hit!\n");
                totalCompDamage += 9;
            } else {
                printf("Attack miss! NO DAMAGE DONE\n");
            }
            
            //begin character specific traits
            if (compSelectionNum == 1){ //if player is a wizard
                wizardChance = 1 + (rand() % 10);
                delayFunction(2);
                printf("Wizard power attempting...\n");
                
                if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                    playerHealth = playerHealth - (compDamage*2);
                    totalCompDamage = (compDamage*2);
                    delayFunction(2);
                    printf("Wizard bonus achieved! Double damage!\n");
                    
                } else { //if %10 is not met
                    delayFunction(2);
                    printf("Wizard bonus failed.\n");
                }
                
                delayFunction(2);
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (compSelectionNum == 2){ //extra 2 damage if player is alien
                alienChance = 1 + (rand() % 10);
                printf("Alien bonus attempting...\n");
                delayFunction(2);
                
                if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                    printf("Alien bonus achieved! + 3hp\n");
                    compHealth += 3;
                    delayFunction(2);
                } else {
                    printf("Alien bonus failed\n");
                    delayFunction(2);
                }
                playerHealth -= 2;
                totalDamage = totalDamage + 2;
                printf("Alien damage attack! - 2pts");
                delayFunction(2);
                totalCompDamage = totalCompDamage + 2;
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (characterSelectionNum == 3){ //extra health if player is knight
                printf("Knight bonus attempting...");
                delayFunction(2);
                if(knightChance == 1 || knightChance == 5){
                    if (totalDamage > 0){
                        printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                        compHealth = compHealth + (totalDamage/0.2);
                        delayFunction(2);
                    } else {
                        printf("No previous attack, bonus void\n");
                        delayFunction(2);
                    }
                } else {
                    printf("Knight bonus failed.\n");
                compHealth += 2;
                delayFunction(2);
                printf("Knight health regen! +2hp");
                delayFunction(2);
                printf("\n\nOPPONENT TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            }
            //end character specific traits
            }
        } else if (compDamage == 10){
            compChance = 1 + (rand() % 10); //chance player will hit target
            if (compChance == 9){
                playerHealth = playerHealth - compDamage;
                printf("\nAttack hit!\n");
                totalCompDamage += 10;
            } else {
                printf("Attack miss! NO DAMAGE DONE\n");
            }
            
            //begin character specific traits
            if (compSelectionNum == 1){ //if player is a wizard
                wizardChance = 1 + (rand() % 10);
                delayFunction(2);
                printf("Wizard power attempting...\n");
                
                if ( wizardChance == 5 || wizardChance == 9 || wizardChance == 1){ //if %30 chance is met
                    playerHealth = playerHealth - (compDamage*2);
                    totalCompDamage = (compDamage*2);
                    delayFunction(2);
                    printf("Wizard bonus achieved! Double damage!\n");
                    
                } else { //if %10 is not met
                    delayFunction(2);
                    printf("Wizard bonus failed.\n");
                }
                
                delayFunction(2);
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (compSelectionNum == 2){ //extra 2 damage if player is alien
                alienChance = 1 + (rand() % 10);
                printf("Alien bonus attempting...\n");
                delayFunction(2);
                
                if (alienChance == 1 || alienChance == 2 || alienChance == 3){
                    printf("Alien bonus achieved! + 3hp\n");
                    compHealth += 3;
                    delayFunction(2);
                } else {
                    printf("Alien bonus failed\n");
                    delayFunction(2);
                }
                playerHealth -= 2;
                totalDamage = totalDamage + 2;
                printf("Alien damage attack! - 2pts");
                delayFunction(2);
                totalCompDamage = totalCompDamage + 2;
                printf("\n\nOPPONENT'S TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            } else if (characterSelectionNum == 3){ //extra health if player is knight
                printf("Knight bonus attempting...");
                delayFunction(2);
                if(knightChance == 1 || knightChance == 5){
                    if (totalDamage > 0){
                        printf("Knight bonus achieved! 80 percent damage from last turn regained.\n");
                        compHealth = compHealth + (totalDamage/0.2);
                        delayFunction(2);
                    } else {
                        printf("No previous attack, bonus void\n");
                        delayFunction(2);
                    }
                } else {
                    printf("Knight bonus failed.\n");
                compHealth += 2;
                delayFunction(2);
                printf("Knight health regen! +2hp");
                delayFunction(2);
                printf("\n\nOPPONENT TURN COMPLETE\nTotal turn damage = %d\nYour Remaining Health: %d\nOpponent Health: %d\n", totalCompDamage, playerHealth, compHealth);
                delayFunction(4);
            }
            //end character specific traits
            }
        }
        
}
    
    printf("\n\nGAME OVER");
    delayFunction(3);
    if(playerHealth > compHealth){
        printf("\n\nCongrats! You win!!");
    } else if (playerHealth < compHealth){
        printf("\n\nUh oh. You Lose");
    } else if (playerHealth == compHealth){
        printf("It's a tie!");
    }
    
    delayFunction(2);
    printf("\n\nThanks for playing! 2014 Aaron Tharpe\n\n");

    
}


