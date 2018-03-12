#include<bits/stdc++.h>
using namespace std;

int MAX_TRIES=5;
const int MAX=10;
struct node
{
    char value;
    struct node *left,*right;
}*start;

void create(char z,struct node *temp)
{

    if(temp==NULL)
    {
        temp=new node;
        temp->value=z;
        temp->left=NULL;
        temp->right=NULL;
        start=temp;
    }
    else
    {
        if(z<temp->value)
        {
            if(temp->left==NULL)
            {
                struct node *r;
                 r=(struct node*)malloc(sizeof(struct node));
                 r->value=z;
                 r->left=NULL;
                 temp->left= r;
                 r->right=NULL;

            }
            else
                create(z,temp->left);
        }
        else
        {
            if(temp->right==NULL)
            {
                struct node *r;
                 r=(struct node*)malloc(sizeof(struct node));
                 r->value=z;
                  r->left=NULL;
                  r->right=NULL;
                 temp->right=r;
            }
            else
                create(z,temp->right);

        }
    }

}

int finde(char check,struct node* temp)
{
    if(check==temp->value)
    {
        return 1;
    }
    else if(check<temp->value)
    {
        if(temp->left==NULL)
            return 0;
        else
        finde(check,temp->left);
    }
    else
    {
        if(temp->right==NULL)
            return 0;
        else
         finde(check,temp->right);
    }
}

int main()
{
     // welcome the user

    cout << "\n\nGuess a country Name";
    cout << "\n\nEach consonants is represented by a star.";
    cout << "\n\nYou have to type only one letter in one try";
    cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n               ";



   string line,s;
  ifstream myfile ("project.txt");
  if (myfile.is_open())
  {
    while (! myfile.eof() )
    {
         srand(time(NULL));
         int x=rand()%15;
       for (int lineno = 0; getline (myfile,line) && lineno < x; lineno++)
           {
               if (lineno == (x-1))
                s=line;
           }
    }
    myfile.close();
  }


    string w,remain;
    int i=0,j,k,l;
    l=s.size();
    start=NULL;
    struct node *temp,*r;
    temp=start;
    while(l--)
    {
        create(s[i],start);
        i++;
    }

    for(i=0;i<s.size();i++)
        {
            if(s[i]==' ')
                {
                    w.push_back(' ');
                    cout<<" ";
                }
                else if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
                {
                    w.push_back(s[i]);
                    cout<<s[i];
                }
            else
            {w.push_back('*');
            cout<<"*";
            }
        }
    cout<<endl;




    while(MAX_TRIES!=0)
    {
        cout << "\n\nGuess a letter: ";

        char check;
        cin>>check;


        if(check>=97 && check<=122)
            check=toupper(check);

        int y=finde(check,start);
       // cout<<y<<endl;
        if(y==1)
        {

            cout << endl << "You found a letter! Isn't that exciting!" << endl;

             if(w!=s)
           {cout << "You have " << MAX_TRIES;
             cout << " guesses left.\n" << endl;}
          cout<<endl;

           for(i=0;i<s.size();i++)
           {

               if(s[i]==check)
               {
                   w[i]=s[i];
                   cout<<s[i];
               }
               else if(w[i]=='*')
               {
                   cout<<"*";
               }
               else
                    cout<<w[i];
           }
           cout<<endl;

        }
        else if(y==0)
        {
            check=tolower(check);
            remain.push_back(check);
            cout << endl << "Whoops! That letter isn't in there!"<< endl;
            MAX_TRIES--;
            cout << "You have " << MAX_TRIES;
            cout << " guesses left." << endl;

            cout<<"\nLetters used:"<<remain<<endl;
        }
      //  cout<<w<<endl;
        if(find(w.begin(),w.end(),'*')==w.end())
            {cout << "\nYeah! You got it!\n";
          //  cout<<"The word was " <<s<<endl;
            break;}
    }
    if(MAX_TRIES==0)
    {
        cout << "\nSorry, you lose...you've been hanged.\n" << endl;
        cout << "The word was : " << s << endl;
    }

}
