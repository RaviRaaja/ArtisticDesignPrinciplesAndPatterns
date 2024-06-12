#include <iostream>

using namespace std;

class PaymentMethod {
    public:
		PaymentMethod(string type): m_type(type) {}
        string type() const { return m_type;}
	private:
		string m_type;
};

class PaymentHandler {
    public:
        void handlePayment(PaymentMethod* paymentMethod) {
            if (paymentMethod->type() == "CreditCard") {
				cout << "handle cc payment";
			}
			if (paymentMethod->type() == "DebitCard") {
				cout << "handle dc payment";
			}
			if (paymentMethod->type() == "CashOnDelivery") {
				cout << "handle cash on delivery";
			}
			if (paymentMethod->type().empty()) {
				cout << "Invalid payment method";
			}
        }
};

int main() {
    PaymentHandler ph;
    PaymentMethod pm("CreditCard");
    ph.handlePayment(&pm);
    return 0;
}