#include <iostream>

using namespace std;

class PaymentMethod {
    public:
        virtual void handle() = 0;
        virtual ~PaymentMethod() {}         
};

class CreditCardPayment : public PaymentMethod {
    public:
    void handle() {
        cout << "Handling cc payment";
    }
};
class DebitCardPayment: public PaymentMethod {
    public:
    void handle() {
        cout << "Handling dc payment";
    }
};
class CashOnDeliveryPayment: public PaymentMethod {
    public:
    void handle() {
        cout << "Handling cod payment";
    }
};

class PaymentHandler {
    public:
        void handlePayment(PaymentMethod* paymentMethod) {
            paymentMethod->handle();
        }
};

int main() {
    PaymentHandler ph;
    CreditCardPayment CCpm;
    ph.handlePayment(&CCpm);
    return 0;
}