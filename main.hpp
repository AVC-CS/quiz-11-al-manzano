#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;

struct Name{
    string stname;
    string gender;
    int year;
    string name;
    int count{};
};

int rewritesplitwords(string, char);
string MFN(string stname, int thisyear);

int rewritesplitwords(string filename, char delimiter) {
    string line, buf;
    int cnt, fcnt;
    stringstream ss;
    Name n;

    ifstream ifs;
    ifs.open(filename);
    if(!ifs) {
        cerr << "File Error\n";
        exit(0);
    }

    ofstream ofs;
    ofs.open("split.txt");
    if (!ofs) {
        cerr << "File Error\n";
        exit(0);
    }

    cnt = 0;
    while (getline(ifs, line)) {
        fcnt = 0;
        ss.clear();
        ss << line;
        cnt++;
        while (getline(ss, buf, delimiter)) {
            switch(fcnt) {
                case 0:
                    n.stname = buf;
                    ofs << n.stname << " ";
                    break;
                case 1:
                    n.gender = buf;
                    ofs << n.gender << " ";
                    break;
                case 2:
                    n.year = stoi(buf);
                    ofs << n.year << " ";
                    break;
                case 3:
                    n.name = buf;
                    ofs << n.name << " ";
                    break;
                case 4:
                    n.count = stoi(buf);
                    ofs << n.count << '\n';
                    break;
                default:
                    cout << "Field Count Error\n";
                    break;
            }
            fcnt++;
        }
    }

    return cnt;
}

string MFN(string stname, int thisyear) {
    string line, buf;
    stringstream ss;
    Name most, n;


    ifstream ifs;
    ifs.open("split.txt");
    if(!ifs) {
        cerr << "File Error\n";
        exit(0);
    }

    while (getline(ifs, line)) {
        ss.clear();
        ss << line;
        ifs >> n.stname >> n.gender >> n.year >> n.name >> n.count;
        if (n.stname.compare(stname) == 0 && n.year == thisyear) {
            if (n.count > most.count) {
                most.stname = n.stname;
                most.gender = n.gender;
                most.year = n.year;
                most.name = n.name;
                most.count = n.count;
            }
        }
    }

    return most.name;
}