/**
 *  Author: Derek Schawang, Troy Hunsicker
 *          dschawang3@huskers.unl.edu
 *  Date: 2022/09/01
 *
 *  This program determines data plan info, off of user inputs. it outputs how much data they can use per day to stay under their plan,
 * along with rate
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main (int argc, char **argv) {

    if(argc != 4) {
    printf("Invalid input, please enter 3 inputs.\n");
    exit(1);
    }

    double planGB = atof(argv[1]);
    int dayOn = atof(argv[2]);
    double usedGB = atof(argv[3]);

    if(dayOn == 0){
        dayOn = 1;
    }

    if(dayOn > 30){
        printf("Please enter a day number between 1 and 30\n");
        return 0;
    }
    if(dayOn < 1){
        printf("Please enter a day number between 1 and 30\n");
        return 0;
    }
    double targetAve;
    double realAve;
    double leftGB;
    int dayLeft;
    double maintainAve;
    double onTrackUse;
    double extraGB;

    targetAve = planGB / 30;
    realAve = usedGB / dayOn;
    leftGB = planGB - usedGB;
    dayLeft = (30 - dayOn);
    maintainAve = leftGB / dayLeft;
    onTrackUse = realAve * dayLeft + usedGB;
    extraGB = planGB - usedGB - (realAve * dayLeft);

    printf("Your plan was %.2lf GB which allowed for %.2lf GB/day\n", planGB, targetAve);
    printf("%d days used and %d days remaining\n", dayOn, dayLeft);
    printf("Average daily use is: %.2lfGB\n", realAve);
    printf("You are on track to use %.2lf GB of data this period\n", onTrackUse);

    if(usedGB > planGB){
        printf("You have surpassed your limit and will be charged accordingly, sorry for the inconvenience.\n");
        printf("Your plan was %.2lf GB and you used %.2lf GB already this period.\n", planGB, usedGB);
        return 0;
    }

    if(realAve > targetAve){
        printf("You are exceeding your daily average limit\n");
        printf("You will need to maintain a %.2lf GB/day average for %d days\n", maintainAve, dayLeft);
    }
    if(realAve < targetAve){
        printf("You are below your daily average limit \n");
        printf("At this pace you will have %.2lf GB leftover at the end of the period\n", extraGB);
    }
    if(realAve == targetAve){
        printf("You are right on target keep using %.2lf GB/day\n", realAve);
    }







    return 0;
}