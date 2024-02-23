#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc,char *argv[]){
    double sum=0;
    int i=0;
    if(argc < 2) cout << "Please input numbers to find average.\n";
    else {
        while(i<argc){
            sum+=atoi(argv[i]);
            i++;
        }
        cout << "---------------------------------\n";
        cout << "Average of " << i-1 << " numbers = " << sum/(i-1) << endl;
        cout << "---------------------------------";
    }
}
