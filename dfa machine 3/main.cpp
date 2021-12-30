#include<bits/stdc++.h>
using namespace std;

map< pair< string,char >, string > creat_trans_table()
{
    /*
    this machine accept empty string
    ===============
    state|  a | b
    ===============
    acc1 |acc1|acc2
    -----|----|-----
    acc2 |acc1|acc3
    -----|----|-----
    acc3 |acc1|trap
    -----|----|-----
    trap |trap|trap
    -----|----|-----

    */
    map< pair< string,char >, string > trans_table;   // define the transition table

    //initialize acc1 state
    trans_table.insert({make_pair("acc1",'a'),"acc1"});
    trans_table.insert({make_pair("acc1",'b'),"acc2"});

    //initialize acc2 state
    trans_table.insert({make_pair("acc2",'a'),"acc1"});
    trans_table.insert({make_pair("acc2",'b'),"acc3"});

    //initialize acc3 state
    trans_table.insert({make_pair("acc3",'a'),"acc1"});
    trans_table.insert({make_pair("acc3",'b'),"trap"});

    //initialize trap state
    trans_table.insert({make_pair("trap",'a'),"trap"});
    trans_table.insert({make_pair("trap",'b'),"trap"});

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

    string intial_state="acc1";// acc1 is the start state
    state_sequance.push_back(intial_state);

    map< pair< string,char >, string > trans_table= creat_trans_table(); // call the defined transition table

    // var to check if state is trap state or not, if var still (0) this mean that string does not enter in trap state
    int check_state_trap=0;


    // begin to iterate on the string to check state
    for(int i=0; i<s.size(); i++)
    {
       state_sequance.push_back(trans_table[ {intial_state,s[i]}]); //push which state we locate in
        if(trans_table[ {intial_state,s[i]}]!="trap")
        {
            // if the state is not trap state,we should continue and make initial state equal to state we locate in
            intial_state=trans_table[ {intial_state,s[i]}];
        }
        else
        {
            check_state_trap=1;
            break;
        }

    }

    // print the string and state seq. of this string
    cout<<"string which entered : "<<s<<endl;
    for (int i=0; i<state_sequance.size(); i++)
    {
        if(i==state_sequance.size()-1)
        {
            cout<<state_sequance[i]<<endl;
            break;
        }

        cout<<state_sequance[i]<<" -> ";
    }

    //check that there is no trap state and the string is not empty
    if(check_state_trap==0&&(state_sequance.back()=="acc1"||state_sequance.back()=="acc2"||state_sequance.back()=="acc3"))
    {
        cout<<"the string is Accepted"<<endl;
    }

    else
    {
        cout<<"this string is REJECTED"<<endl;
    }
}
int main()
{
    string str;
    cout<<" enter the string you want to check: ";
    cin>>str;
    if(str=="")
    {

        checkString("");
        cout<<"<<This machine accept empty string>>"<<endl;
    }
    else
    {

        checkString(str);
    }
    return 0;
}
