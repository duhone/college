class ObjectManager 
{
public:
	virtual ~ObjectManager() {}

	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual void* QueryInterface(const  char* interfaceName) = 0;
};

class AbstractSwitch : public ObjectManager
{
public:
	virtual ~AbstractSwitch() {}

	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
	virtual bool getPosition() const = 0;

	virtual bool getPastPosition(unsigned int index) = 0;
};

class DomesticAppliance : public ObjectManager
{
public:
	virtual ~DomesticAppliance() {}

	virtual const char* color() const = 0;
};

class Switch : public AbstractSwitch, public DomesticAppliance 
{
public:
	virtual void Release();
	virtual void AddRef();
	virtual void* QueryInterface(const  char* interfaceName);

	Switch();
	virtual ~Switch();

	virtual void turnOn();
	virtual void turnOff();
	bool getPosition() const;

	bool getPastPosition(unsigned int index);

	virtual const char* color() const;

private:
	bool m_position;
	//int m_pastPositions;
	bool m_pastValues[300];

	long m_Ref;
};
// Implementation of Switch.cpp not provided here. Assume all 
// functions are implemented correctly.

int main()
{
	Switch aSwitchObj;
	//...
}