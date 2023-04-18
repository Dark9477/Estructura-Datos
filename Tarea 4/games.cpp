#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string find_median_name(vector<string>guests) {
    int n = guests.size();
    sort(guests.begin(), guests.end());

    string median1 = guests[n/2 - 1];
    string median2 = guests[n/2];
    string median_name = "";

    bool end_loop = false;
    for(int i = 0; i < median1.size() && !end_loop; i++){
        if(median1[i] == median2[i]){
            median_name += median1[i];
        }
        else{
            if(median2[i] > median1[i] + 1 || i < median2.size() - 1){
                if (i == median1.size() - 1){
                    median_name += median1[i];
                }
                else{
                    median_name += median1[i] + 1;
                    i = median1.size() - 1;
                }
            }
            else{
                median_name += median1[i];
                for (int j = i + 1; j < median1.size(); j++)
                {
                    if (j == median1.size() - 1){
                        median_name += median1[j];
                    }
                    else if (median1[j] != 'Z')
                    {
                        median_name += median1[j] + 1;
                        i = median1.size() - 1;
                        j = median1.size() - 1;
                    }
                    else{
                        median_name += 'Z';
                    }
                }
                i = median1.size() - 1;
            }
        }
    }
    return median_name;
}

int main(){
    int n;
    cin >> n;
    while (n != 0){
        vector<string> guests(n);
        for(int i = 0; i < n; i++){
            cin >> guests[i];
        }
        string median_name = find_median_name(guests);
        cout << median_name << endl;
        cin >> n;
    }
    return 0;
}
