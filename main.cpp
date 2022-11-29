#include "OpenAddressing.h"
#include "SeparateChaining.h"
#include "Streamer.h"
using namespace std;
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

string ObjToName(Streamer s) {
    return s.getName();
}
string ObjToWatchTime(Streamer s){
    return s.getWatchTime();
}

int main() {
    vector<Streamer> streamers;
    string file = "../twitchdata-update.csv";
    getDataFromFile(file, streamers);

    const unsigned long TABLE_SIZE = 3000;
/*
    SeparateChaining<int> sepChain(TABLE_SIZE, intToString);
    for(int i =0; i<streamers.size()-1; i++){
        sepChain.insert()
    } */

    SeparateChaining<Streamer> sepChainOne(TABLE_SIZE, ObjToName);
    SeparateChaining<Streamer> sepChainTwo(TABLE_SIZE*2, ObjToName);
    SeparateChaining<Streamer> sepChainThree(TABLE_SIZE+250, ObjToName);
    SeparateChaining<Streamer> sepChainFour(TABLE_SIZE*1.5, ObjToName);
    SeparateChaining<Streamer> sepChainFive(TABLE_SIZE+101, ObjToName);
    SeparateChaining<Streamer> sepChainSix(TABLE_SIZE, ObjToWatchTime);
    SeparateChaining<Streamer> sepChainSeven(TABLE_SIZE*2, ObjToWatchTime);
    SeparateChaining<Streamer> sepChainEight(TABLE_SIZE+250, ObjToWatchTime);
    SeparateChaining<Streamer> sepChainNine(TABLE_SIZE*1.5, ObjToWatchTime);
    SeparateChaining<Streamer> sepChainTen(TABLE_SIZE+101, ObjToWatchTime);


    DoubleHash<Streamer> dubChainOne(TABLE_SIZE, ObjToName);
    DoubleHash<Streamer> dubChainTwo(TABLE_SIZE*2, ObjToName);
    DoubleHash<Streamer> dubChainThree(TABLE_SIZE+250, ObjToName);
    DoubleHash<Streamer> dubChainFour(TABLE_SIZE*1.5, ObjToName);
    DoubleHash<Streamer> dubChainFive(TABLE_SIZE+101, ObjToName);
    DoubleHash<Streamer> dubChainSix(TABLE_SIZE, ObjToWatchTime);
    DoubleHash<Streamer> dubChainSeven(TABLE_SIZE*2, ObjToWatchTime);
    DoubleHash<Streamer> dubChainEight(TABLE_SIZE+250, ObjToWatchTime);
    DoubleHash<Streamer> dubChainNine(TABLE_SIZE*1.5, ObjToWatchTime);
    DoubleHash<Streamer> dubChainTen(TABLE_SIZE+101, ObjToWatchTime);

    ofstream ReadFile;

    ReadFile.open("../reads.txt");
    ReadFile<< "SC1\tSC2\tSC3\tSC4\tSC5\tSC6\tSC7\tSC8\tSC9\tSC10\tSC11\tSC12\tSC13\tSC14\tSC15\tSC16\tSC17\tSC18\tSC19\tSC20"<<endl;

    for(int i=0; i < streamers.size(); i++){
        int r1=0,r2=0,r3=0,r4=0,r5=0,r6=0,r7=0,r8=0,r9=0,r10=0,r11=0,r12=0,r13=0,r14=0,r15=0,r16=0,r17=0,r18=0,r19=0,r20=0;
        sepChainOne.insert(streamers.at(i),r1);
        sepChainTwo.insert(streamers.at(i), r2);
        sepChainThree.insert(streamers.at(i), r3);
        sepChainFour.insert(streamers.at(i), r4);
        sepChainFive.insert(streamers.at(i), r5);
        sepChainSix.insert(streamers.at(i), r6);
        sepChainSeven.insert(streamers.at(i), r7);
        sepChainEight.insert(streamers.at(i), r8);
        sepChainNine.insert(streamers.at(i), r9);
        sepChainTen.insert(streamers.at(i), r10);
        dubChainOne.insert(streamers.at(i),r11);
        dubChainTwo.insert(streamers.at(i),r12);
        dubChainThree.insert(streamers.at(i),r13);
        dubChainFour.insert(streamers.at(i),r14);
        dubChainFive.insert(streamers.at(i),r15);
        dubChainSix.insert(streamers.at(i),r16);
        dubChainSeven.insert(streamers.at(i),r17);
        dubChainEight.insert(streamers.at(i),r18);
        dubChainNine.insert(streamers.at(i),r19);
        dubChainTen.insert(streamers.at(i),r20);
        ReadFile<<r1<<"  \t"<<r2<<"  \t"<<r3<<"  \t"<<r4<<"  \t"<<r5<<"  \t"<<r6<<"  \t"<<r7<<"  \t"<<r8<<"  \t"<<r9<<"  \t"<<r10<<"   \t"<<r11<<"   \t"<<r12<<"   \t"<<r13<<"   \t"<<r14<<"   \t"<<r15<<"   \t"<<r16<<"   \t"<<r17<<"   \t"<<r18<<"   \t"<<r19<<"   \t"<<r20<<endl;
    }

    ReadFile.close();

    return 0;
}
