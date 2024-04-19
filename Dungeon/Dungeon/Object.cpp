#include "Object.h"
#include<iostream>
#include<string>
using namespace std;
Object::Object()
{
	 
}
Object::Object(string name, string tag)
{
	this->name = name;
	this->tag = tag;
}
void Object:: setName(string name)
{
	this->name = name;
}
void Object::setTag(string tag)
{
	this->tag = tag;
}
string Object::getName()const 
{
	return this->name;
}
string Object::getTag()const
{
	return this->tag;
}