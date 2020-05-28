//程序小白，反正这东西能跑起来就不错了
//自用
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
//输入xDy+z 出结果
class Dice
{
private:
	int diceCount;
	int diceMaxNum;
	int diceAdd;
	int diceValue;

public:
	Dice(int c = 1, int mn = 100, int a = 0)
	{ //默认调用1D100
		diceCount = c;
		diceMaxNum = mn;
		diceAdd = a;
		diceValue = 0;
	}
	int getCount()
	{
		return diceCount;
	}
	int roll();
	void input(string str);
};
int Dice::roll()
{
	srand(time(0));
	int t = 0;
	diceValue = 0;
	cout << diceCount << 'd' << diceMaxNum;
	if (diceAdd != 0)
	{
		if(diceAdd>0){
			cout << '+' << diceAdd;
		}else{
			cout << diceAdd;
		}
	}
	cout << '=';
	for (int i = 0; i < diceCount; i++)
	{
		t = rand() % diceMaxNum + 1;
		diceValue += t;
		cout << t;
		if (i != diceCount - 1)
		{
			cout << '+';
		}
	}
	if (diceAdd != 0)
	{
		if(diceAdd>0){
			cout << '+' << diceAdd;
		}else{
			cout << diceAdd;
		}
		diceValue+=diceAdd;
	}
	cout << '=' << diceValue << endl;
	return diceValue;
}
void Dice::input(string st)
{ //重载出问题了，总之先处理字符串
	diceAdd = 0;
	size_t pos = 0;
	int ln = st.length();
	int i = 0;
	string childst = st;
	diceCount = stoi(childst, &pos); //读出个数
	for (i; i < ln && st[i] != 'd'; i++)
	{
	}
	childst = st.substr(i + 1, ln);
	diceMaxNum = stoi(childst, &pos); //读出最大值
	for (i; i < ln; i++)
	{
		if(st[i]=='+' || st[i]=='-'){
			break;
		}
	}
	if (i != ln)
	{
		childst = st.substr(i + 1, ln);
		if(st[i]=='-'){
			diceAdd = -stoi(childst, &pos);
		}else if(st[i]=='+'){
			diceAdd = stoi(childst, &pos);
		}else{
			diceAdd=0;
		}
	}
	//cout << diceCount << "  " << diceMaxNum << "  " << diceAdd << "  " << endl;
}
int main()
{
	Dice myD;
	string st;
	do
	{
		cin >> st;
		if (st[0] != 'q')
		{
			myD.input(st);
			myD.roll();
		}
	} while (st[0] != 'q'); //press q to quit
}