#include <iostream>
using namespace std;

int main()
{
    char data[90], stuffed[90], destuffed[90];
    int i, j = 0, count = 0;
    cout << "Enter String: ";
    cin >> data;
    cout << "\nSender Side\n";
    cout << "Before Stuffing input: " << data << endl;

    for(i = 0; data[i] != '\0'; i++)
    {
     stuffed[j++] = data[i];

    if(data[i] == '1')
            count++;
 else
            count = 0;

            if(count == 5)
        {
            stuffed[j++] = '0';
            count = 0;
        }
    }

    stuffed[j] = '\0';
    cout << "After Stuffing output: " << stuffed << endl;
    cout << "\nReceiver Side\n";
    cout << "Before De-stuffing input: " << stuffed << endl;
    j = 0;
    count = 0;

    for(i = 0; stuffed[i] != '\0'; i++)
    {
        destuffed[j++] = stuffed[i];

        if(stuffed[i] == '1')
            count++;
        else
            count = 0;

        if(count == 5)
        {
            i++;
            count = 0;
        }
    }

    destuffed[j] = '\0';

    cout << "After De-stuffing output: " << destuffed << endl;

    return 0;
}

