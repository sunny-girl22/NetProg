#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

int main (int argc, char **argv)
{
    sockaddr_in *cAddr = new (sockaddr_in);
    cAddr->sin_family = AF_INET;
    cAddr->sin_port = 0;
    cAddr->sin_addr.s_addr = 0;
    sockaddr_in * sAddr = new (sockaddr_in);
    sAddr->sin_family = AF_INET;
    sAddr->sin_port = htons(7);
    sAddr->sin_addr.s_addr = inet_addr("172.16.40.194");
    char *buf = new char[512];
    string str ("/0");
    int msgLen = str.length();
    size_t length = str.copy(buf,msgLen);
    int s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s == -1) {
        exit(1);
    }
    int rc = connect(s,(const sockaddr*)srv_addr, sizeof(sockaddr_in));
    if (rc == -1) {
        cout << "Ошибка\n";
        return 1;
    } else {
        cout << "Было отправлено: " << endl;
        char connection_msg[50] = "Сколько времени?\n";
        send(s, connection_msg, sizeof(connection_msg), 0);
        char daytime[50];
        recv(s, daytime, sizeof(daytime), 0);
        cout << "Было получено: " << daytime << endl;
        close(s);
        return 0;
    }
    delete cAddr;
    delete sAddr;
    delete[] buf;
    return 0;
}
