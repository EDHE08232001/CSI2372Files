#include <iostream>
#include <vector>

using namespace std;

/* Index search selector function that returns the index of the min value of an array
**
*/
int searchIndex(const vector<int>& T, int imax) {
    if (T.size() <= imax) {
        cout << "Erreur ! Tableau trop petit ! " << endl;
        return -1;
    }
    int res = 0;
    for (int i = 1; i <= imax; i++)
        if (T[i] < T[res]) res = i; // Find the index of the minimum value
    return res;
}

/* Exchange function that exchanges the values of the arguments
**
*/
void exchange(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}

/* Sort function with Pass by value
**
*/
vector<int> sort(vector<int> T) {
    int number = T.size();
    for (int m = 0; m < number - 1; m ++) {
        // Finding the index of the minimum element in the unsorted array
        int minimumIndexArray = m;  // Starting with the current index as minimumIndexArray
        for (int s = m + 1; s < number; s++) {
            if (T[s] < T[minimumIndexArray]) {
                minimumIndexArray = s;  // Updating minimumIndexArray if a smaller element is found
            }
        }
        
        // Swapping the found minimum element with the first unsorted element
        exchange(T[m], T[minimumIndexArray]);
    }
    return T;
}

/* arrayEntry function to enter values from your table
**
*/
vector<int> arrayEntry() {
    int size;
    cout << "Enter the size of your array: ";
    cin >> size;
    vector<int> res(size, 0);
    cout << "Enter the values of your array: \n";
    for (int i = 0; i < size; i++) {
        cout << "val[ " << i << "] = ";
        cin >> res[i];
    }
    cout << "\n";
    return res;
}

/* main
**
*/
int main() {
    vector<int> a;
    vector<int> arraySorted;
    a = arrayEntry();
    
    cout << "My array values are: ";
    for (int i = 0; i < a.size(); i++) {
        cout << "\n" << a[i];
    }
    cout << "\n";

    arraySorted = sort(a);
    
    cout << "\nMy sorted array values are: ";
    for (int i = 0; i < arraySorted.size(); i++) {
        cout << "\n" << arraySorted[i];
    }
    cout << "\n";

    return 0;
}
