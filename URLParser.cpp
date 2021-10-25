#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
    string url = argv[1];
    string acceptedProtocols[] = {"http", "https", "ftp", "ftps"}; // List of accepted protocols
    string acceptedDomains[] = {"com", "net", "edu", "biz,", "gov"}; // List of accepted domains
    string protocol = url.substr(0, url.find("://")); // Grabs protocol from given command line argument
    
    for(int i = 0; i < 4; i++) {
        if(protocol == acceptedProtocols[i]) {
            cout << "Protocol: " << protocol << endl; // Outputs given protocol if it is valid
            break;
        }
        if(i == 3) {
            cout << "Protocol: " << protocol << " is not a valid protocol." << endl; // Outputs error message for given protocol that is not accepted

            return 0;
        }
    }

    string domainPort = url.substr(url.find("://") + 3); // Grabs domain and port from given command line argument
    string domain = domainPort.substr(0, domainPort.find("/")); // Grabs domain from domainPort string
    domain = domain.substr(0, domain.find(":")); // Grabs domain from domainPort

    for(int x = 0; x < 5; x++) {
        if(domain == acceptedDomains[x]) {
            cout << "Domain: " << domain << endl; // Outputs given domain if it is valid
            break;
        }
        if(x == 4) {
            cout << "Domain: " << domain << " is an invalid domain name." << endl; // Outputs error message for given domain that is not accepted

            return 0;
        }
    }

    int port = stoi(domain.substr(domain.find(":") + 1)); // Grabs port from domain and converts port into an int

    if(port < 1 || port > 65535) {
        cout << "Port: " << port << " port number must be between 1 and 65535" << endl; // Outputs error message for given port that is not valid

        return 0;
    }

    cout << "Port: " << port << endl; // Outputs given port

    string pathParameters = domainPort.substr(domainPort.find("/") + 1); // Grabs file path and parameters from given command line argument
    string filePath = pathParameters.substr(0, pathParameters.find("?")); // Grabs file path from pathParameters string
    cout << "File path: " << filePath << endl; // Outputs given file path

    string parameters = pathParameters.substr(pathParameters.find("?") + 1); // Grabs parameters from pathParameters string
    cout << "Parameters: " << parameters << endl; // Outputs given parameters
}
    