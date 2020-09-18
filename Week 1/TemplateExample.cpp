//"generic" classes of functions
//compare 2 things, return the smallest , return largest number

#include <iostream>
using namespace std;

//check 2 "things" and return the smallest
template <class T>
T min_func(T lVal, T rVal)
{
	if (lVal > rVal)
	{
		return lVal;
	}
	return lVal;
}

//check 2 things return the highest
template <class T>
T max_func(T lVal, T rVal)
{
	if (lVal < rVal)
	{
		return rVal;
	}
	return lVal;
}

//implement a templaye class here
template <class T>
class TemplateClass
{
public:
	TemplateClass(T val)
	{
		m_val = val;
	}
	//MISSING SOMETHING HERE
	bool operator<(TemplateClass& rVal)
	{
		return m_val > rVal.GetVal();
	}

	T GetVal()
	{
		return m_val;
	}

private:
	T m_val;
};

//main
/*
int main()
{
	cout << "Template Example" << endl << endl;
	cout << "Min = " << min_func("c", "d") << endl;
	cout << "Max = " << max_func(56.1, 43.6) << endl;

	//create 2 "TemplateClass" Objects and compare them 
	cout << "Max (objects) = " << max_func(TemplateClass<int>(7), TemplateClass<int>(4)).GetVal();

	return 0;
}
*/
