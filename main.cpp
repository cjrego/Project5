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

    const unsigned long TABLE_SIZE = 1000;
/*
    SeparateChaining<int> sepChain(TABLE_SIZE, intToString);
    for(int i =0; i<streamers.size()-1; i++){
        sepChain.insert()
    } */
    int r1,r2,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15,r16,r17,r18,r19,r20=0;

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

    for(int i=0; i < streamers.size()-1; i++){
        sepChainOne.insert(streamers.at(i),ReadFile);
        sepChainTwo.insert(streamers.at(i), ReadFile);
        sepChainThree.insert(streamers.at(i), ReadFile);
        sepChainFour.insert(streamers.at(i), ReadFile);
        sepChainFive.insert(streamers.at(i), ReadFile);
        sepChainSix.insert(streamers.at(i), ReadFile);
        sepChainSeven.insert(streamers.at(i), ReadFile);
        sepChainEight.insert(streamers.at(i), ReadFile);
        sepChainNine.insert(streamers.at(i), ReadFile);
        sepChainTen.insert(streamers.at(i), ReadFile);
        dubChainOne.insert(streamers.at(i));
        dubChainTwo.insert(streamers.at(i));
        dubChainThree.insert(streamers.at(i));
        dubChainFour.insert(streamers.at(i));
        dubChainFive.insert(streamers.at(i));
        dubChainSix.insert(streamers.at(i));
        dubChainSeven.insert(streamers.at(i));
        dubChainEight.insert(streamers.at(i));
        dubChainNine.insert(streamers.at(i));
        dubChainTen.insert(streamers.at(i));
        ReadFile<<endl;
    }

    ReadFile.close();

    return 0;
}
