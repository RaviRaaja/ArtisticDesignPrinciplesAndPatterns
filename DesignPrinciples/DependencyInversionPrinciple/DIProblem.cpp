#include <iostream>
using namespace std;
// llm
class EmailSender {
    public:
    
    void send(const string& to,const string& message) {
        cout << "Sending message to " << to << " Message: "<< message << endl;
    }
};

// hlm
class NotificationManager {
    EmailSender m_emailSender;
    
    public:
        NotificationManager() {}
        void sendNotification(const string& to,const string& message) {
            m_emailSender.send(to, message);
        }
};

int main() {
    NotificationManager nm;
    nm.sendNotification("test@gmail.com", "Hello google!");
    return 0;
}