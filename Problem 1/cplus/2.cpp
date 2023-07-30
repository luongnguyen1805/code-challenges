#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

class Node 
{
    public:
        int value;
        Node* left;
        Node* right;
        int weight;

        Node(int val) {
            value = val;
            left = NULL;
            right = NULL;
            weight = 0;
        }
};

void addToNode(Node* root, Node* aNumber, int &shift) {
    
    if (aNumber->value >= root->value) {

        root->weight += 1;    
                
        if (root->right == NULL) {                      
            root->right = aNumber;                  
        }
        else {
            Node* currentRight = root->right;
            addToNode(currentRight,aNumber,shift);

            //root->right = balanceNode(root->right);
            
        }
    }
    else {

        shift += root->weight + 1;        
        if (root->left == NULL) {
            root->left = aNumber;   
        }
        else {
            Node* currentLeft = root->left;
            addToNode(currentLeft,aNumber,shift);

            //root->left = balanceNode(root->right);

        }
    }
        
}

int insertionSort(vector<int> arr) {

    int n = arr.size();
    int totalShift = 0;
    
    Node* root = new Node(arr[0]);
    
    for (int i = 1; i < n; i++) {
        
        Node* cur = new Node(arr[i]);
        
        int shift = 0;
        addToNode(root, cur, shift);
        
        totalShift += shift;
    }
    
    return totalShift;  
};

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

        int totalShift = 0;
        
        Node* root = NULL;

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            Node* cur = new Node(arr_item);
            if (root == NULL) 
            {
                root = cur;
                continue;
            }

            int shift = 0;
            addToNode(root, cur, shift);
            
            totalShift += shift;
        }

        int result = totalShift;

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
