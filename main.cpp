#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>
#include <set>
#include <map>


using namespace std;

int main() {

    ifstream in("pid.in");
    ofstream out("pid.out");

    int n = 0;
    in >> n;


    set<int> free_pids;
    for (int i = 1; i < n + 1; ++i) {
        free_pids.insert(i);
    }

    map<int, int> pids;

    int creation_counter = 1;
    for (int i = 1; i < n + 1; ) {
        char command;
        in >> command;

        if (command == 'C') {
            int min = *free_pids.begin();
            free_pids.erase(free_pids.begin());
            pids[creation_counter++] = min;
            out << min << endl;
            i++;
        } else {
            int creation_number;
            in >> creation_number;
            int pid_number = pids[creation_number];
            pids.erase(creation_number);
            free_pids.insert(pid_number);
            i++;
        }
    }

    return 0;
}