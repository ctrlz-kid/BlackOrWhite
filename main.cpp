#include <QCoreApplication>
#include <iostream>

using namespace std;


int m;
string data;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cin >> m;
    cin >> data;


    int w = 0;
    int b = 0;
    int other= 0;

    for (int i=0; i<m; i++)
    {
        if (data[i] == 'w' || data[i] =='W')
        {
            w++;
        }
        else if (data[i] == 'b' || data[i] == 'B')
        {
            b++;
        }
        else
        {
            other++;
        }
    }

    // 如果有其他字符，输出-1
    if (other != 0)
    {
        cout << -1;
        return a.exec();
    }

    // 如果单数个W，则输出-1
    if ( w % 2 == 1)
    {
        cout << -1;
        return a.exec();
    }

    int count= 0;

    for(int i = 0; i<m-1; i++)
    {
        if (data[i] != 'B')
        {
            if (data[i]== 'b')
            {
                data[i] = 'B';
            }
            else
            {
                // == 'w' or 'W'
                data[i] = 'B';
                count++;

                if (data[i+1] == 'b' || data[i+1] == 'B')
                {
                    data[i+1] = 'W';
                }
                else
                {
                    // == 'w' or 'W'
                    data[i+1] = 'B';
                }
            }
        }
    }

     cout << count;


    return a.exec();
}
