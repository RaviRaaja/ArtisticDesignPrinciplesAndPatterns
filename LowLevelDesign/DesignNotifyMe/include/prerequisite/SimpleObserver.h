#include <iostream>
#include <map>

using namespace std;

// g++ -std=c++17 file.cpp -o executable
// intent - proimity sensor communicate to phoneApplication and ScreenBrghtnessApp


enum class ProximityValues {
    SHORT,
    MID,
    FAR
};

// helper
ostream& operator<<(ostream& ostr, ProximityValues pv) {
    const string proxName[] = {"SHORT", "MEDIUM", "FAR"};
    return ostr << proxName[(int)pv];
}

class IProximityObservers {
    public:
    virtual void update(ProximityValues) = 0;
};

class PhoneApplication: public IProximityObservers {
    public:
     void update(ProximityValues pv) {
        cout << "PhoneApplication Proximity value received " << (pv) << endl; 
    }
};

class ScreenBrightnessController:  public IProximityObservers {
    public:
    void update(ProximityValues pv) {
        cout << "ScreenBrightnessController Proximity value received " << (pv) << endl; 
    }
};


class ProximitySensor {
    public:
        ProximitySensor() {
        }

        // sensor hardware gives me proximity value
        void notify() {
            ProximityValues pv = ProximityValues::FAR;
            for(auto itr=m_proximityObservers.begin(); itr!=m_proximityObservers.end(); ++itr) {
                itr->second->update(pv);
            }
        }

        bool subscribe(string observerName, IProximityObservers* proximityOberver) {
            
            auto mapIterator = m_proximityObservers.find(observerName);

            if (mapIterator == m_proximityObservers.end()) {
                m_proximityObservers.emplace(observerName, proximityOberver);
                cout << "Subscribed !" << endl;
                return true;
            } else {
                cout << observerName << ": Already Subscribed" << endl;
            }
            return false;
        }

        bool unSubscribe(string observerName) {
            auto mapIterator = m_proximityObservers.find(observerName);
            if (mapIterator != m_proximityObservers.end()) {
                m_proximityObservers.erase(observerName);
                cout << "UnSubscribed !" << endl;
                return true;
            } else {
                cout << observerName << ": Already UnSubscribed" << endl;
            }
            return false;
        }

    private:
        std::map<std::string, IProximityObservers*> m_proximityObservers;

};


int simpleObserverTest() {
    auto ps = new ProximitySensor();
    auto pa = new PhoneApplication();
    auto sbc = new ScreenBrightnessController();

    ps->subscribe("PHONE", pa);
    ps->subscribe("BRIGHTNESS CONTROLLER", sbc);

    ps->notify();

    ps->subscribe("PHONE", sbc);

    ps->unSubscribe("BRIGHTNESS CONTROLLER");

    ps->notify();
    
    return 0;
}