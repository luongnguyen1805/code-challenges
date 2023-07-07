#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

class Node 
{
    public:
        int* value;
        Node* left;
        Node* right;
        int weight;
        int shift;
};

void addToNode(Node* root, Node* aNumber) {
    
    if ((*aNumber->value) >= (*root->value)) {

        root->weight += 1;    
                
        if (root->right == NULL) {                      
            root->right = aNumber;                  
        }
        else {
            Node* currentRight = root->right;
            addToNode(currentRight,aNumber);
        }
    }
    else {

        aNumber->shift += root->weight + 1;        
        if (root->left == NULL) {
            root->left = aNumber;   
        }
        else {
            Node* currentLeft = root->left;
            addToNode(currentLeft,aNumber);
        }
    }
        
}

/*
 * Complete the 'insertionSort' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
 
Node* createNewNode(int* val) {
    Node* node = new Node();
    node->left = NULL;
    node->right = NULL;
    node->weight = 0;
    node->value = val;
    node->shift = 0;
    return node;
}

int insertionSort(vector<int> arr) {

    int n = arr.size();
    int totalShift = 0;
    
    Node* root = createNewNode(&arr[0]);
    
    for (int i = 1; i < n; i++) {
        
        Node* cur = createNewNode(&arr[i]);
        
        addToNode(root, cur);
        
        totalShift += cur->shift;
    }
    
    return totalShift;  

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        int result = insertionSort(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
