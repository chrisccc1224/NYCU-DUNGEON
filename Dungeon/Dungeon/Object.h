#pragma once
#include<string>
using namespace std;
class Object
{
public:
	Object();
	Object(string, string);
	void setName(string);
	void setTag(string);
	string getName() const;
	string getTag()const;
	virtual bool  triggerEvent(Object*) = 0;
	virtual void showStatus()=0;

private:
	string name;
	string tag;


};