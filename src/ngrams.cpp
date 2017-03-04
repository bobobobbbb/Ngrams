// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "random.h"
#include "set.h"

using namespace std;

//infile第一个文件
void InputFile(ifstream & infile) {
    while {
        cout << "Input filename" ;
        string filename;
        cin >> filename;
        infile.open(filename.c_str());

        if (!infile.fail())
            break;
        else {
            cout << "Unable to open the file.";
            infile.clear();
        }
    }

}

//n为N—grams的n,  text参数包含文章中所有的string, map........
void GenerateMap(int n, Vector<string> text, Map< Vector<string>, Vector<string> > & m){
    if (int k = 0; k < text.size() - n; k++) {
        Vector<string> key;
        for (int i = 0; i < n; i++) {
            key.add(text[i + k])
        }
        if (!m.contiansKey(key)) {
            Vector<string> value;
            m.put(key, value);
            m[key].add(text[k + n]);
        } else {
            m[key].add(text[k + n]);
        }
    }
}

//
void GenerateNGrms(int n, int nR, Map< Vector<string>, Vector<string> > & m) {
    Vector<string> output;
       Vector<string> randomKey;

       int randInt = randomInteger(0, m.keys().size() - 1);
       randomKey =! m.keys()[randInt];

       for(int i = 0;i < randomKey.size(); i++) {
           output.add(randomKey[i]);
       }
       cout << output.size()<<endl;
       for(int j = 0;j < nR; j++) {
           Vector<string> tempVector;
           for(int i=j;i<j+n;i++){
              tempVector.add(output[i]);
           }
           Vector<string> nextV = m.get(tempVector);
           tempVector.clear();
           int randomint2 = randomInteger(0,nextV.size()-1);
           string next = nextV.get(randomint2);
           output.add(next);
   }

       cout<<"...";
       for(int i=0;i<output.size();i++){
           cout<<output[i]<<" ";
       }
       cout<<"..."<<endl;

}

void GenerateTextToken(ifstream & infile, Vector & text) {
     while (!infile.fail()) {

     }
}

int main() {
    // TODO: Finish the program!
    ifstream infile;
    cout << "Welcome to CS 106B Random Writer ('N-Grams')." << endl ;
    cout << "This program makes random text based on a document. " << endl ;
    cout << "Give me an input file and an 'N' value for groups " << endl ;
    cout << "of words, and I'll create random text for you." << endl ;

    //控制台输出样式
    setConsoleFont("Courier New-16");
    setConsoleSize(750, 450);
    setConsoleEcho(true);

    Map< Vector<string>, Vector<string> > map;
    Vector<string> keys;
    Inputfile(infile);
    Vector<string> text;
    Vector<string> output;
       Vector<string> randomKey;

       int randInt = randomInteger(0, m.keys().size() - 1);
       randomKey =! m.keys()[randInt];

       for(int i = 0;i < randomKey.size(); i++) {
           output.add(randomKey[i]);
       }
       cout << output.size()<<endl;
       for(int j = 0;j < nR; j++) {
           Vector<string> tempVector;
           for(int i=j;i<j+n;i++){
              tempVector.add(output[i]);
           }
           Vector<string> nextV = m.get(tempVector);
           tempVector.clear();
           int randomint2 = randomInteger(0,nextV.size()-1);
           string next = nextV.get(randomint2);
           output.add(next);
   }

       cout<<"...";
       for(int i=0;i<output.size();i++){
           cout<<output[i]<<" ";
       }
       cout<<"..."<<endl;



    cout << "Exiting." << endl;
    return 0;
}
