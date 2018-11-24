#include <QCoreApplication>
#include <QTextStream>
#include <QString>

using namespace std;

QTextStream cout(stdout);
QTextStream cin(stdin);
QString checksum(QString str);

int main()
{
    QString p;
    do
    {
    cout << "Input line:" << endl;
    QString stroka = cin.readLine();
    QString m = checksum(stroka);
    cout << "Result HEX: " << m << endl;
    cout << "Enter n to end the program" << endl;
    p = cin.readLine();
    }
    while (p != "n");

    return 0;
}

QString checksum(QString str)
{
    quint8 s;
    int k = str.length();
    int sum = 0;
    for (int i=0; i<k; i++)
    {
        s = str.at(i).toLatin1();
        sum = sum + s;
        cout << "symbol " << i+1 << " = " << s << endl;
    }
    cout << "Sum symbol = " << sum << endl;
    quint8 f = fmodl(sum , 256);
    cout << "mod 256 = " << f << endl;

    QString n;
    n.setNum(f,16);
    n = n.toUpper();

    return n;
}
