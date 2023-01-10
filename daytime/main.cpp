#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

int main (int argc, char **argv)
{
    //Адрес программы-клиента
    sockaddr_in *cAddr = new (sockaddr_in);
    cAddr->sin_family = AF_INET;
    cAddr->sin_port = 0;
    cAddr->sin_addr.s_addr = 0;
    //Адрес программы-сервера)
    sockaddr_in * sAddr = new (sockaddr_in);
    sAddr->sin_family = AF_INET;
    sAddr->sin_port = htons(13);
    sAddr->sin_addr.s_addr = inet_addr("172.16.40.1");
    char *buf = new char[512];
    string str ("Сколько времени?\n");
    int msgLen = str.length();
    size_t length = str.copy(buf,msgLen);
    int Socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (Socket == -1) {
        exit(1);
    }
    int rc = connect(s,(const sockaddr*)srv_addr, sizeof(sockaddr_in));
    if (rc == -1) {
        cout << "Error: failed connect to server.\n";
        return 1;
    } else {
        char connection_msg[50] = "Привет";
        send(s, connection_msg, sizeof(connection_msg), 0);
        char daytime[50];
        recv(s, daytime, sizeof(daytime), 0);
        cout << "Daytime from server: " << daytime << endl;
        cout << "Session close!" << endl;
        close(s);
        return 0;
    }
    delete cAddr;
    delete sAddr;
    delete[] buf;
    return 0;
}