template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>* &found_ptr)
{
    bool debug = true;

    if(!root)
    {
        cout << "root=NULL"<< endl;
        return false;
    }

    //if not null
    else
    {
        if(target == root->_item)
        {
            cout <<"target found"<<endl;
            found_ptr = root;
            return true;
        }

        else if(target > root->_item)
        {
            if(debug) {
                cout << "target > root->_item"<<endl;
                cout<<"search right"<<endl;
            }
            tree_search(root->_right, target, found_ptr);

            if(debug) {
                cout <<"back from search right"<<endl;
            }
        }

        else if(target < root->_item)
        {
            if(debug) {
                cout << "target < root->_item"<<endl;
                cout<<"search left"<<endl;
            }
            tree_search(root->_left, target, found_ptr);
            if(debug) {
                cout<<"back from search left"<<endl;
            }
        }

    }

}

int main()
{


    avlMenu();
//    randomBalanceTests();

    return 0;
}

void avlMenu()
{
    char selection = ' ';

    avl<int> a;
    tree_node<int> *found_ptr = nullptr;
    bool isFound = false;
//    tree_node<int> *add_tree = nullptr;
//    tree_node<int> *root = nullptr;
    int insert_me_value = 0;
    int search_value = 0;
    int nodeCounter = 0;

    while(selection != 'x' && selection != 'X')
    {
        cout<< nodeCounter << " node(s) in tree" << endl;
        cout << "[R]andom  [I]nsert  [C]lear  [S]earch  [E]rase  e[X]it: ";
        cin >> selection;

        if(selection == 'r' || selection == 'R'){
            insert_me_value = rand()%100;
            cout << "-- Inserting " << insert_me_value << endl;
            a.insert(insert_me_value);
            nodeCounter++;
            //            cout << a;
        } else if(selection == 'i' || selection == 'I') {
            cout << "Input value to insert: ";
            cin >> insert_me_value;
            a.insert(insert_me_value);
            nodeCounter++;
            //            cout << a;
        } else if(selection == 'c' || selection == 'C') {
            a.clear();
            nodeCounter = 0;
        } else if(selection == 's' || selection == 'S') {
            cout << "Input value to search: ";
            cin >> search_value;

            isFound = a.search(search_value, found_ptr);
            if(isFound) {
                cout << "Item is found " /*<< found_ptr->_item */<< endl;
            } else {
                cout << "Item not found." << endl;
            }

        } else if(selection == 'e' || selection == 'E') {
            cout << "Input value to delete: ";
            cin >> search_value;
            if(a.search(search_value,found_ptr)) {
                cout << "Item deleted" << endl;
                a.erase(search_value);
                nodeCounter--;
            } else {
                cout << "Item not found. No deletion occurred." << endl;
            }
        }

        cout << a;

    }

    cout << "Exiting..." << endl;
}