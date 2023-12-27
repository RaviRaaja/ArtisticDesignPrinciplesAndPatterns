#include <iostream>
using namespace std;

class INotificationSender {
    public:
        virtual void send() = 0;
        virtual ~INotificationSender() {} 
};


// llm
class EmailSender: public INotificationSender {
    public:
        EmailSender(string to, string message): m_to(to), m_message(message) {}
    void send() override {
        cout << "Sending email message to " << m_to << " Message: "<< m_message << endl;
    }
    private:
        string m_to, m_message;
};

class WhatsappMessageSender: public INotificationSender {
    public:
        WhatsappMessageSender(string phoneNumber, string message): m_phNo(phoneNumber), m_message(message) {}
    void send() override {
        cout << "Sending whats app message to " << m_phNo << " Message: "<< m_message << endl;
    }
    private:
        string m_phNo, m_message;
};

// hlm
class NotificationManager {
    private:
        INotificationSender* m_notificationSender;
    
    public:
        NotificationManager(INotificationSender* notificationSender) {
            m_notificationSender = notificationSender;
        }

        void sendNotification() {
            m_notificationSender->send();
        }
};

int main() {
    INotificationSender* whatsappMesageSender = new WhatsappMessageSender("9898912311", "Hi good morning");
    NotificationManager nm(whatsappMesageSender);
    nm.sendNotification();
    delete whatsappMesageSender;
    return 0;
}