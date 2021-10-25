#pragma once

class Extension;
class Mask;

class People {
public:
	//...
	virtual Extension* GetExtension(const char* name)
	{
		return nullptr;
	}
};

class Audience : public People {
public:
	//...
	virtual Extension* GetExtension(const char* name);
private:
	Mask* mask;
};

class Extension {
protected:
	People* _owner;
public:
	Extension(People* owner)
	{
		_owner = owner;
	}
};

class AntiepidemicExtension : public Extension {
public:
	AntiepidemicExtension(People* owner) :Extension(owner){}
};

class Mask : public AntiepidemicExtension {
public:
	Mask(People* owner):AntiepidemicExtension(owner){}

	void putOnMask()
	{
		std::cout << std::endl << "Mask:: putOnMask : ͻ�������������ܴ�����" << std::endl;
		std::cout << std::endl << "���ڴ����˿���" << std::endl;
	}
};

Extension* Audience::GetExtension(const char* name)
{
	if (strcmp(name, "Mask") == 0)
	{
		if (mask == nullptr)
			mask = new Mask(this);
		return (Extension*)mask;
	}
	return People::GetExtension(name);
}

void extensionObjectTest()
{
	std::cout << "***************  ����ΪExtensionObject(��չ����)���ģʽ  **************************************" << std::endl << std::endl;
	Mask* mask;
	Audience* audience = new Audience;
	mask = (Mask*)audience->GetExtension("Mask");
	if (mask != nullptr)
	{
		mask->putOnMask();
	}
	std::cout << std::endl << "***************  ExtensionObject(��չ����)���ģʽ����  **************************************" << std::endl << std::endl;
}