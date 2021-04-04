#include <map>
#include "TwitterData.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    // Schema: UserName,Last,First,Email,NumTweets,MostViewedCategory
    string raw_data[5][6] = {{"rangerPower","Smit","Rick","smitRick@gmail.com","1117","power lifting"},
                             {"kittyKat72","Smith","Kathryn","kat@gmail.com","56","health"},
                             {"lexi5","Anderson","Alexis","lexi5@gmail.com","900","education"},
                             {"savage1","Savage","Ken","ksavage@gmail.com","17","president"},
                             {"smithMan","Smith","Rick","rick@hotmail.com","77","olympics"}};
    TwitterData *twitter_data = new TwitterData[5];
    for (int i = 0; i < 5; ++i) {
        twitter_data[i].setUserName(raw_data[i][0]);
        twitter_data[i].setActualName(raw_data[i][2] + " " + raw_data[i][1]);
        twitter_data[i].setEmail(raw_data[i][3]);
        twitter_data[i].setNumTweets(stoi(raw_data[i][4]));
        twitter_data[i].setCategory(raw_data[i][5]);
    }


    map<string, TwitterData*> s1;
    cout << "Scenario 1, searching Username based" << endl;

    for(int i = 0; i < 5; ++i)
    {
        s1.insert({twitter_data[i].getUserName(), &twitter_data[i]});
    }

    cout << "Printing the map line by line: " << endl;
    cout << endl;
    for(auto i : s1)
    {
        string k = i.first;
        TwitterData *v = i.second;

        cout << k << " " << v->print() << endl;

    }

    cout << "Searching for Savage1....." << endl << s1["savage1"]->print() << endl;
    cout << endl;
    cout << "Removing Savage1....." << endl;
    s1.erase("savage1");
    for(auto i : s1)
    {
        string k = i.first;
        TwitterData *v = i.second;

        cout << k << " " << v->print() << endl;

    }
    cout << endl;


    map<string, TwitterData*> s2;
    cout << "Scenario 2, Search by Email" << endl;

    for(int i = 0; i < 5; ++i)
    {
        s2.insert({twitter_data[i].getEmail(), &twitter_data[i]});
    }

    cout << "Printing the map line by line: " << endl;
    cout << endl;
    for(auto i : s2)
    {
        string k = i.first;
        TwitterData *v = i.second;

        cout << k << " " << v->print() << endl;

    }

    cout << endl;
    cout << "Searching for kat@gmail.com....." << endl << s2["kat@gmail.com"]->print() << endl;
    cout << endl;
    cout << "Removing kat@gmail.com....." << endl;
    s2.erase("kat@gmail.com");
    for(auto i : s2)
    {
        string k = i.first;
        TwitterData *v = i.second;

        cout << k << " " << v->print() << endl;

    }


    return 0;
}