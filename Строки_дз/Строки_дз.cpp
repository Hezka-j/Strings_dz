#include <iostream>

using namespace std;
int main()
{
    int length;
    cout << "Enter length password - ";
    cin >> length;
    cin.ignore();
    char* text = new char[length];
    for (int i = 0; i < length; i++)
    {
        text[i] = 97 + rand() % (123 - 97);
        cout << text[i];
    }
    delete[] text;
    /////////////////////////////////////

    char* text1 = new char[100];
    bool ok = true;
    cout << "\nEnter text - ";
    gets_s(text1, 100);
    char* text2 = new char[100];
    strcpy_s(text2, 100, _strrev(text1));
    _strlwr_s(text1, 100);
    _strlwr_s(text2, 100);
    
    cout << text1 << "\n";
    cout << text2 << "\n";
    for (int i = 0; i < strlen(text1); i++)
    {
        if (text1[i] != text2[i])
        {
            ok = false;
            break;
        }
        if (text1[i] == ' ')
        {
            i++;
        }
        else
            ok = true;
    }
    if (ok)
    {
        cout << "Anogram!\n";
    }
    else
    {
        cout << "No anogram(\n";
    }
    
    delete[] text1;
    delete[] text2;
    ////////////////////////////////////////////////////////
    text = new char[100];
    cout << "Enter string - ";
    gets_s(text, 100);
    int count_symbols = strlen(text);
    int count_spaces = 0;
    int count_vowels = 0;
    int count_unspoken;//не глассные буквы
    int count_digits = 0;
    int count_punc = 0;
    int count_another = 0;
    
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            count_spaces++;
        }
        else if (text[i] == 'a' || text[i] == 'e' || text[i] == 'o' || text[i] == 'y' || text[i] == 'u' || text[i] == 'i')
        {
            count_vowels++;
        }
        else if (text[i] == 'A' || text[i] == 'E' || text[i] == 'O' || text[i] == 'Y' || text[i] == 'U' || text[i] == 'I')
        {
            count_vowels++;
        }
        else if (text[i] == ',' || text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count_punc++;
        }
        else if (text[i] == '1' || text[i] == '2' || text[i] == '3' || text[i] == '4' || text[i] == '5' || text[i] == '6' || text[i] == '7' || text[i] == '8' || text[i] == '9' || text[i] == '0')
        {
            count_digits++;
        }
        else if(text[i] < 65 || text[i] > 91 && text[i] < 97 || text[i] > 122)
        {
            count_another++;
        }
        
        
    }
    int count_word = count_spaces + 1;
    count_unspoken = count_symbols - (count_vowels + count_digits + count_spaces + count_punc + count_another);
    
    cout << "All symbols - " << count_symbols << "\n";
    
    cout << "Vowels letters - " << count_vowels << "\n";
    cout << "Unspoken letters - " << count_unspoken << "\n";
    cout << "Digits - " << count_digits << "\n";
    cout << "Punctuation marks - " << count_punc << "\n";
    cout << "Words - " << count_word  << "\n";
    cout << "Another symbols - " << count_another << "\n";
    delete[] text;
}
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	system("title strchr, strrchr, _strrev, strstr");
//
//	char* text = new char[200];
//	strcpy_s(text, 199, "London is the capital of Great Britain");
//	char look_for_symbol = 'a';
//
//	// indexes of character 'a'
//	for (int i = 0; i < strlen(text); i++)
//	{
//		if (text[i] == look_for_symbol)
//		{
//			cout << i << ", ";
//		}
//	}
//	cout << "\n\n";
//
//	// alternative way
//	char* find = strchr(text, 'a'); // strrchr - look from end
//	cout << find - text << "\n\n";
//
//	// string reverse
//	cout << _strrev(text) << "\n\n"; // string reverse
//	cout << _strrev(text) << "\n\n";
//
//	char* word = new char[50];
//	strcpy_s(word, 49, "capital");
//	cout << word << "\n";
//
//	char* help = text; // pointer to start of text
//
//	while (true)
//	{
//		// https://stackoverflow.com/questions/1634359/is-there-a-reverse-function-for-strstr // strstr from end
//		help = strstr(help, word);
//		if (!help)
//			break;
//		cout << help - text << "\n"; // all indexes
//		help += strlen(word); // search next
//	}
//
//}