 #include <iostream>
using namespace std;
class Device
{
protected:
    string deviceName;
    int deviceID;
    int *data;
public:
    Device(string n, int id)
    {
        deviceName = n;
        deviceID = id;
        data = new int;
        *data = 100;

        cout << "Device constructor called" << endl;
    }
    ~Device()
    {
        delete data;
        cout << "Device destructor called" << endl;
    }
};
class Sensor : public Device
{
private:
    string sensorType;
    float *sensorValue;
public:
    Sensor(string n, int id, string type, float val) : Device(n, id)
    {
        sensorType = type;
        sensorValue = new float;
        *sensorValue = val;
        cout << "Sensor constructor called" << endl;
    }
    ~Sensor()
    {
        delete sensorValue;
        cout << "Sensor destructor called" << endl;
    }
};
int main()
{
    Sensor *s = new Sensor("TemperatureDevice", 101, "Temperature", 36.5);
    delete s;
}
