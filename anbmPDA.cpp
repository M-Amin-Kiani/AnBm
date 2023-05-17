// mohammad amin kiani         محمد امین کیانی
// ali hosseini fard           علی حسینی فرد
// group : 5
// phase 2
//------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
//------------------------------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------------------------------
void StrMaker();
void StrChecker();
bool checker_func(string input_str);
void Rejection();
//------------------------------------------------------------------------------------------------------
struct Stack_node
{
    int data;
    Stack_node* next;
    Stack_node* previos;

    Stack_node()  //start
    {
        data = 0;
        next = nullptr;
        previos = nullptr;
    }
    ~Stack_node()  //end
    {
        data = 0;
        next = nullptr;
        previos = nullptr;
    }
};

struct Stack_linkedlist
{
    int size;
    Stack_node * head;
    Stack_node * tail;

    Stack_linkedlist()  //start
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    ~Stack_linkedlist()   //end
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty()
    {
        if(size == 0)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void Push(int x)  // add first
    {
        Stack_node * temp = new Stack_node;
        temp->data = x;

        if(head == nullptr)
        {
            head = temp;
            tail = temp;
        }

        else
        {
            temp->next = head;
            head->previos = temp;
            head = temp;

        }

        size++;
    }

    int pop()          // delete first ( means the last data that push at the end)
    {
        if(isEmpty())
        {
            return NULL;
        }

        int stack_top = head->data ;

        head->data = 0;
        head = head->next;
        size--;

        return stack_top;
    }

    int top()
    {
        if(isEmpty())
        {
            return NULL ;
        }

        int curr_top = head->data;

        return curr_top;
    }

    void print()  // print from first one (that at the end of stack)
    {
        Stack_node * temp = new Stack_node();

        temp = tail;

        while( tail != nullptr)
        {
            cout << tail->data;

            tail = tail->previos;
        }
    }

};
//------------------------------------------------------------------------------------------------------
int main()
{
    cout << " ----------------------------------------------------------------------------------- \n";
    cout << " ______________________    ! Welcome to the PDA System !    ________________________ \n";
    cout << " ________________________                                 __________________________ \n";
    cout << " __________________________    * Owner: Amin + Ali *    ____________________________ \n";
    cout << " ----------------------------------------------------------------------------------- \n \n";
    cout << " Options :  \n\n   1-Enter a Number to Get the N_String of your language.";
    cout << "   \n   2-Check a String for the acceptence by your Language.";
    cout << "   \n   0-Exit.";
    cout << "\n \n   =============";
    cout << " \n \n   Enter your Order Number Here: ";

    int chooser;

    cin >> chooser;
    cout << "\n   =============" << endl;

    if(chooser == 1)
    {
        StrMaker();
    }
    else if(chooser == 2)
    {
        StrChecker();
    }
    else if(chooser == 0)
    {
        return 0;
    }
    else
    {
        system("cls");
        main();
    }

}
//------------------------------------------------------------------------------------------------------
void StrMaker()
{
    string input[2];
    int n, m;

    cout << endl << "Enter n: ";
    cin >> input[0];
    cout << endl << "Enter m: ";
    cin >> input[1];

    try
    {
        n = stoi(input[0]);
        m = stoi(input[1]);

        for(int i = 0 ; i < n; i++ )
        {
            cout << 'a';
        }
        for(int j = 0 ; j < m; j++ )
        {
            cout << 'b';
        }

        cout << endl;

        StrMaker();
    }
    catch (const std::invalid_argument& e)
    {
        system("cls");
        if (input[0] == "back")
        {
            main();
        }
        else
        {
            cout<< "Invalid...!";

            StrMaker();
        }
    }
}

void StrChecker()
{
    string input;

    cout << "Enter String: ";

    cin >> input;

    if(input == "back")
    {
        system("cls");
        main();
    }
    else if (checker_func(input))
    {
        cout << "Accepted" << endl;
        StrChecker();
    }
    else
    {
        Rejection();
    }
}

bool checker_func(string input_str)
{
    Stack_linkedlist stack;
    long long c = 0;
    bool checker = false;

    if(input_str[0] == '0')  // landa
    {
        for (int i = 1; i < input_str.length(); i++)
        {
            if(input_str[i] != 'a' && input_str[i] != 'b' && input_str[i] != '0')
                return false;
        }
        return true;
    }

    for (int i = 0; i < input_str.length(); i++)
    {
        if (input_str[i] == 'a')
        {
            stack.Push(1);
            if(checker == true) Rejection();
            c++; // tedad a
            for (int j = c; j < input_str.length(); j++)
            {
                if (input_str[j] != 'a' && input_str[j] != 'b' && input_str[j] != '0')
                    return false;
            }
            //return true;
        }
        else if (input_str[i] == 'b')
        {
            stack.pop();
            checker = true;
            for (int k = c; k < input_str.length(); k++)
            {
                if (input_str[k] != 'b' && input_str[k] != '0')
                    return false;
                stack.pop();
                c++;
            }
            return true;
        }
        else if (input_str[i] == '0')
        {

        }
        else
        {
            return false; // invalid character
        }
    }
    if(stack.isEmpty())
    {
        cout << "Accepted" << endl;
        StrChecker();
    }
}

void Rejection()
{
    cout << "Rejected" << endl;

    StrChecker();
}

//------------------------------------------------------------------------------------------------------
