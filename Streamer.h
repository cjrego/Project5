//
// Created by regoc on 10/6/2022.
//

#ifndef PROJECT3_STREAMER_H
#define PROJECT3_STREAMER_H
//
// Created by regoc on 9/14/2022.
//

/* Created by regoc on 9/9/2022.
 * This is Header class Streamer.
 * This class is designed to create a streamer object .
 * A streamer contains a name, as well as multiple statistics about their performance on twitch.
 * It also contains the maturity of their content as well as if they are partnered with the site.
*/
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using std::vector, std::string, std::cout, std::cin, std::endl, std::fstream, std::ifstream, std::to_string, std::ostream;

class Streamer{
private:
    string name; // Streamer name (not legal name)
    string watchTime; //total number of minutes that they were watched over the year (made a string due to extraordinarily large numbers)
    int streamTime; // total number of minutes that the Streamer was live
    int peakViewers; //single highest concurrent viewer count
    int averageViewers; //average live viewers per stream
    int followers; //total followers
    int followersGained; //Followers gained or lost over the past year
    int viewsGained; //Total views gained or lost compared to the year prior
    bool partnered; //If they are partnered with Twitch
    bool mature; //If their content is mature or kid friendly
    string language; //the language that is spoken in the stream

public:
    //Default constructor for no inputs. Everything set to null.
    Streamer() {
        name = " ";
        watchTime = " ";
        streamTime = 0;
        peakViewers = 0;
        averageViewers = 0;
        followers = 0;
        followersGained = 0;
        viewsGained = 0;
        partnered = false;
        mature = false;
        language = " ";
    }

    //Streamer constructor that takes a value for all variables
    Streamer(string n, string w, int streamTime, int peakViewers, int averageViewers, int followers, int followersGained, int viewsGained, bool partnered, bool mature, string lang) {
        name.swap(n);
        watchTime.swap(w);
        this -> streamTime = streamTime;
        this -> peakViewers = peakViewers;
        this -> averageViewers = averageViewers;
        this -> followers = followers;
        this -> followersGained = followersGained;
        this -> viewsGained = viewsGained;
        this -> partnered = partnered;
        this -> mature = mature;
        language.swap(lang);
    }

    //All getters and setters for private variables
    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Streamer::name = name;
    }

    const string &getWatchTime() const {
        return watchTime;
    }

    void setWatchTime(string watchTime) {
        Streamer::watchTime = watchTime;
    }

    int getStreamTime() const {
        return streamTime;
    }

    void setStreamTime(int streamTime) {
        Streamer::streamTime = streamTime;
    }

    int getPeakViewers() const {
        return peakViewers;
    }

    void setPeakViewers(int peakViewers) {
        Streamer::peakViewers = peakViewers;
    }

    int getAverageViewers() const {
        return averageViewers;
    }

    void setAverageViewers(int averageViewers) {
        Streamer::averageViewers = averageViewers;
    }

    int getFollowers() const {
        return followers;
    }

    void setFollowers(int followers) {
        Streamer::followers = followers;
    }

    int getFollowersGained() const {
        return followersGained;
    }

    void setFollowersGained(int followersGained) {
        Streamer::followersGained = followersGained;
    }

    int getViewsGained() const {
        return viewsGained;
    }

    void setViewsGained(int viewsGained) {
        Streamer::viewsGained = viewsGained;
    }

    bool isPartnered() const {
        return partnered;
    }

    void setPartnered(bool partnered) {
        Streamer::partnered = partnered;
    }

    bool isMature() const {
        return mature;
    }

    void setMature(bool mature) {
        Streamer::mature = mature;
    }

    const string &getLanguage() const {
        return language;
    }

    void setLanguage(const string &language) {
        Streamer::language = language;
    }

    friend bool operator < (const Streamer& sLeft, const Streamer& sRight){
        if(sLeft.getFollowers() < sRight.getFollowers())
            return true;
        else
            return false;
    }

    friend bool operator <= (const Streamer& sLeft, const Streamer& sRight){
        if(sLeft.getFollowers() <= sRight.getFollowers())
            return true;
        else
            return false;
    }

    friend bool operator > (const Streamer& sLeft, const Streamer& sRight){
        if(sLeft.getFollowers() > sRight.getFollowers())
            return true;
        else
            return false;
    }

    friend bool operator >= (const Streamer& sLeft, const Streamer& sRight){
        if(sLeft.getFollowers() >= sRight.getFollowers())
            return true;
        else
            return false;
    }

    friend bool operator == (const Streamer& sLeft, const Streamer& sRight){
        if(sLeft.getName() == sRight.getName())
            return true;
        else
            return false;
    }
    friend ostream & operator << (ostream &out, const Streamer &c );

};

/*
 * Global method getDataFromFile
 * Takes a file name and a vector of streamers
 * Reads a file with Streamer statistics and will populate the vector of streamers
 */
void getDataFromFile(string filename, vector<Streamer>& streamerList) {
    fstream fs;
    string name, language, watch; //instance variables for all necessary variables
    int stream=0, peak=0, avgViewers=0, follow=0, followGained=0, viewGained=0;
    bool mature, partnered;
    char comma= ','; //delimeter for reading through the file
    string b; //String to temporarily hold values from file
    Streamer s; //Streamer instance variable
    fs.open(filename); //opens file
    if(!fs){ //checks if the file works
        cout<<"Bad file"<<endl;
    }
    while (fs && fs.peek() != EOF) { //while the file is open and not at end of file
        getline(fs, name, comma); //gets first segment for name

        getline(fs, watch, comma); //next segment is saved to watchTime

        fs >> stream; //int inputs saved to proper variables
        fs >> comma;

        fs >> peak;
        fs >> comma;

        fs >> avgViewers;
        fs >> comma;

        fs >> follow;
        fs >> comma;

        fs >> followGained;
        fs >> comma;

        fs >> viewGained;
        fs >> comma;

        getline(fs, b, comma);  //bool values saved as a string and checked to see if true or false
        if(b=="True"){
            partnered = true;
        } else {
            partnered = false;
        }
        getline(fs,b,comma);
        if(b=="True"){
            mature = true;
        } else {
            mature = false;
        }
        getline(fs,language);
        s = Streamer(name,watch,stream,peak,avgViewers,follow,followGained,viewGained,partnered,mature,language); //creates a streamer object with values
        streamerList.push_back(s); //puts streamer into vector
    }
    fs.close(); //closes file
}
/*
 * Gloabal method avgFollowers
 * Takes a vector of Streamers and returns an integer
 * int returned represents average follower count of top 1000 streamers
 */
int avgFollowers(vector<Streamer> list){
    int nums = list.size();
    int sum=0;
    for(int i=0;i<nums;i++){
        sum += list.at(i).getFollowers();
    }
    return sum/nums;
}

string print(Streamer s){
    string mat;
    if(s.isMature() ==1)
        mat = "is";
    else
        mat="is not";
    string part;
    if(s.isPartnered()==1)
        part = " are";
    else
        part = " are not";

    string line1 = s.getName() + "\nWas watched for: " + s.getWatchTime() + " minutes and streamed for a total of " + to_string(s.getStreamTime()) + " minutes\n";
    string line2 = "They averaged " + to_string(s.getAverageViewers()) + " viewers and had " + to_string(s.getPeakViewers()) + " peak viewers\n";
    string line3 = "They gained " + to_string(s.getFollowersGained()) + "followers for a total of " + to_string(s.getFollowers()) + " followers\n";
    string line4 = "The broadcast is done in " + s.getLanguage() + "\n";
    string line5 = s.getName() + mat + " a mature broadcast and they" + part + " partnered by Twitch\n";
    return line1+line2+line3+line4+line5;
}

ostream & operator << (ostream &out, const Streamer &c ){
    out << c.getName();
    return out;
}


#endif //PROJECT3_STREAMER_H
