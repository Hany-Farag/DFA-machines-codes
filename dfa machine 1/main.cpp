#include<bits/stdc++.h>
using namespace std;

map< pair< string,char >, string > creat_trans_table()
{
    /*
    ===============
    state|  0 | 1
    ===============
    q0   |q1  |acc
    -----|----|-----
    q1   |q0  |trap
    -----|----|-----
    acc  |trap|trap
    -----|----|-----
    trap |trap|trap
    -----|----|-----

    */
    map< pair< string,char >, string > trans_table;   // define the transition table

    //initialize q0 state
    trans_table.insert({make_pair("q0",'0'),"q1"});
    trans_table.insert({make_pair("q0",'1'),"acc"});

    //initialize q1 state
    trans_table.insert({make_pair("q1",'0'),"q0"});
    trans_table.insert({make_pair("q1",'1'),"trap"});

    //initialize accept state
    trans_table.insert({make_pair("acc",'0'),"trap"});
    trans_table.insert({make_pair("acc",'1'),"trap"});

    //initialize trap state
    trans_table.insert({make_pair("trap",'0'),"trap"});
    trans_table.insert({make_pair("trap",'1'),"trap"});

    cout<<" << TRANSITION TABLE >> "<<endl;
    for(auto p:trans_table)
    {
        cout<<"( "<< p.first.first << ", " <<p.first.second<<" ) ->"<<p.second <<endl;
    }
    cout<<"<<===============================================================================================>>"<<"\n\n";
    return trans_table;
}

void checkString(string s)
{
    vector<string> state_sequance; // push the steps of state in this vector to print it

    string intial_state="q0";// q0 is the start state
    state_sequance.push_back(intial_state);

    map< pair< string,char >, string > trans_table= creat_trans_table(); // call the defined transition table


    // var to check if state is trap state or not, if var still (0) this mean that string does not enter in trap state
    int check_state_trap=0;


    // begin to iterate on the string to check state
    for(int i=0; i<s.size(); i++)
    {

        if(trans_table[ {intial_state,s[i]}]!="trap")
        {
            state_sequance.push_back(trans_table[ {intial_state,s[i]}]); //push which state we locate in

            // if the state is not trap state,we should continue and make initial state equal to state we locate in
            intial_state=trans_table[ {intial_state,s[i]}];
        }
        else
        {
            state_sequance.push_back(trans_table[ {intial_state,s[i]}]); //push which state we locate in

            check_state_trap=1;
            break;
        }

    }

    // print the string and state seq. of this string
    cout<<"string which entered : "<<s<<endl;
    for (int i=0;i<state_sequance.size();i++)
    {
        if(i==state_sequance.size()-1)
        {
            cout<<state_sequance[i]<<endl;
            break;
        }

        cout<<state_sequance[i]<<" -> ";
    }

    if(check_state_trap==0&&state_sequance.back()!="q0"&&state_sequance.back()=="acc") //check that there is no trap state and the string is not empty
    {
        cout<<"the string is Accepted"<<endl;
    }

    else{
        cout<<"this string is REJECTED"<<endl;
    }
}
int main()
{
    string str;
    cout<<" enter the string you want to check: ";
    cin>>str;
    checkString(str);
    return 0;
}
