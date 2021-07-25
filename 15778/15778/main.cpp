#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Team
{
    char name;
    string move;
};

int N;
vector<Team> t1,t2;
vector<string> Map;
string init = "..----..----..----..----..----....    ..    ..    ..    ..    ..| \\                          / ||  \\                        /  ||   \\                      /   ||    ..                  ..    |..   ..                  ..   ....     \\                /     ..|       \\              /       ||        \\            /        ||         ..        ..         ||         ..        ..         |..          \\      /          ....           \\    /           ..|             \\  /             ||              ..              ||              ..              ||             /  \\             |..           /    \\           ....          /      \\          ..|         ..        ..         ||         ..        ..         ||        /            \\        ||       /              \\       |..     /                \\     ....   ..                  ..   ..|    ..                  ..    ||   /                      \\   ||  /                        \\  || /                          \\ |..    ..    ..    ..    ..    ....----..----..----..----..----..";

void initMap(void)
{
    for(int i = 0; i < (int)init.length(); i++)
    {
        int start = i;
        string str = "";
        for(int j = start; j < start+32; j++)
        {
            str += init[j];
            i++;
        }
        i--;
        Map.push_back(str);
    }
}

int main(int argc,char *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    initMap();
    
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        char name;
        string move;
        cin >> name >> move;
        
        if(islower(name))
            t1.push_back({name,move});
        else
            t2.push_back({name,move});
    }
    
    return 0;
}
