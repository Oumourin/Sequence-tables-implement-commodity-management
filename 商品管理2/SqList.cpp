#include<iostream>
#include<string>
#include<vector>
#define _arrayLength 100		//sqList Max Length

using namespace std;
void findMenu();

vector<int> g_findVector;			//Result of finding vector
									//Class Definition
class CGoods
{
	friend ostream & operator << (ostream &out, const CGoods &CG);
	friend istream & operator >> (istream &in, CGoods &CG);
private:
	int m_goodsId;
	string m_goodsName;
	unsigned int m_goodsPrice;
	unsigned int m_goodsStateNum;
public:
	//Construction Function
	CGoods(int m_goodsId, string m_goodsName, unsigned int m_goodsPrice, unsigned int m_goodsStateNum)
	{
		this->m_goodsId = m_goodsId;
		this->m_goodsName = m_goodsName;
		this->m_goodsPrice = m_goodsPrice;
		this->m_goodsStateNum = m_goodsStateNum;
	}
	//NULL Construction Function
	CGoods()
	{}

	//Copy Construction Function
	CGoods(const CGoods &cg)
	{
		m_goodsId = cg.m_goodsId;
		m_goodsName = cg.m_goodsName;
		m_goodsPrice = cg.m_goodsPrice;
		m_goodsStateNum = cg.m_goodsStateNum;
	}
	//Getter Function
	int getGoodsId()
	{
		return m_goodsId;
	}

	string getGoodsName()
	{
		return m_goodsName;
	}

	unsigned int getGoodsPrice()
	{
		return m_goodsPrice;
	}

	unsigned int getGoodsStateNum()
	{
		return m_goodsStateNum;
	}

	//setter Function
	void setGoodsId(int goodsId)
	{
		this->m_goodsId = goodsId;
	}

	void setGoodsName(string goodsName)
	{
		this->m_goodsName = goodsName;
	}

	void setGoodsPrice(unsigned int goodsPrice)
	{
		this->m_goodsPrice = goodsPrice;
	}

	void setGoodsStateNum(unsigned int goodStateNum)
	{
		this->m_goodsStateNum = goodStateNum;
	}
};
//overload output
ostream & operator << (ostream &out, const CGoods &CG)
{
	//out << "商品编号:"<<CG.m_goodsId <<"  "<< "商品名:" <<"  "<<"CG.m_goodsName"<<"  "<< "单价:"<<"  "<<CG.m_goodsPrice <<"  "<< "库存数量:" <<CG.m_goodsStateNum<<"  "<< endl;
	out << CG.m_goodsId << "  " << CG.m_goodsName << "  " << CG.m_goodsPrice << "  " << CG.m_goodsStateNum;
	return out;
}
//overload input
istream & operator >> (istream &in, CGoods &CG)
{
	in >> CG.m_goodsId >> CG.m_goodsName >> CG.m_goodsPrice >> CG.m_goodsStateNum;
	return in;
}
//SqList Defination
class CsqList
{
private:
	CGoods m_cgSqList[_arrayLength];
	unsigned int m_listLength;
public:
	//init sqList
	void initSqList()
	{
		m_listLength = 0;
	}
	//getter
	CGoods * getCgSqList()
	{
		return m_cgSqList;
	}

	unsigned int getListLength()
	{
		return m_listLength;
	}

	//add goods to sqlist
	void addGoods(int addNum)
	{
		for (int i = 0; i < addNum; i++)
		{
			CGoods tempCG;
			cin >> tempCG;
			m_cgSqList[m_listLength] = tempCG;
			m_listLength++;
		}
	}

	bool checkEmpty()
	{
		if (m_listLength == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//output all sqlist
	void toString()
	{
		if (checkEmpty())
		{
			cout << "表为空" << endl;
			return;
		}
		cout << "商品编号" << "  " << "商品名" << "  " << "单价" << "  " << "库存数量" << endl;
		for (int i = 0; i < m_listLength; i++)
		{
			cout << m_cgSqList[i] << endl;
		}
	}

	//output special goods 
	void toString(int subPoint)
	{
		if (checkEmpty())
		{
			cout << "表为空" << endl;
			return;
		}
		if (subPoint >= m_listLength)
		{
			cout << "越界访问！" << endl;
			return;
		}
		cout << "商品编号" << "  " << "商品名" << "  " << "单价" << "  " << "库存数量" << endl;
		cout << m_cgSqList[subPoint] << endl;
	}

	//output vector goods
	void toString(vector<int> findVector)
	{
		if (checkEmpty())
		{
			cout << "表为空" << endl;
			return;
		}
		cout << "商品编号" << "  " << "商品名" << "  " << "单价" << "  " << "库存数量" << endl;
		for (int i = 0; i < findVector.size(); i++)
		{
			cout << m_cgSqList[findVector[i]] << endl;
		}
	}
	//Function Declaration
	bool findGoods(string targetString);		//find by Name
	bool findGoods(unsigned int m_goodsPrice);		//find by Price
	bool findGoodsByNum(unsigned int m_goodsStateNum);		//find by StateNum
	void sortByName();		//sort by Name
	void sortByPrice(CGoods[], unsigned int start, unsigned int end);		//sort by Price
	void sortByStateNum();		//sort by StateNum
	unsigned int findInterface(int flagSwitch);		//find Function's interface
	void sortInterface(int flagSwitch);		//sort Function's interface
	void delGoods();
	void delGoods(int subTab);
};

bool CsqList::findGoods(string targetString)
{
	if (checkEmpty())
	{
		cout << "表为空" << endl;
		return false;
	}
	bool flagFind = false;
	g_findVector.clear();		//clear vector
	for (int i = 0; i < m_listLength; i++)
	{
		if (targetString == m_cgSqList[i].getGoodsName())
		{
			g_findVector.push_back(i);
			flagFind = true;
		}
	}
	return flagFind;		//Not Found return false
}

bool CsqList::findGoods(unsigned int targetPrice)
{
	if (checkEmpty())
	{
		cout << "表为空" << endl;
		return false;
	}
	bool flagFind = false;
	g_findVector.clear();		//clear vector
	for (int i = 0; i < m_listLength; i++)
	{
		if (targetPrice == m_cgSqList[i].getGoodsPrice())
		{
			g_findVector.push_back(i);
			flagFind = true;
		}
	}
	return flagFind;		//Not Found return false
}

bool CsqList::findGoodsByNum(unsigned int targetStateNum)
{
	if (checkEmpty())
	{
		cout << "表为空" << endl;
		return false;
	}
	bool flagFind;
	g_findVector.clear();		//clear vector
	for (int i = 0; i < m_listLength; i++)
	{
		if (targetStateNum == m_cgSqList[i].getGoodsStateNum())
		{
			g_findVector.push_back(i);
			flagFind = true;
		}
	}
	return flagFind;		//Not Found return false
}

void CsqList::sortByName()
{
	if (checkEmpty())
	{
		cout << "表为空" << endl;
		return;
	}
	for (int i = 0; i < m_listLength; i++)
	{
		bool sortFlag = true;
		for (int j = 0; j < m_listLength - i - 1; j++)
		{
			if (m_cgSqList[j].getGoodsName() > m_cgSqList[j + 1].getGoodsName())
			{
				CGoods tempGoods;
				tempGoods = m_cgSqList[j];
				m_cgSqList[j] = m_cgSqList[j + 1];
				m_cgSqList[j + 1] = tempGoods;
				sortFlag = false;
			}
		}
		if (sortFlag)
		{
			break;
		}
	}
	toString();
}

void CsqList::sortByPrice(CGoods cg[], unsigned int start, unsigned int end)
{
	if (cg == NULL || start >= end)
	{
		return;
	}
	unsigned int keyInt = cg[start].getGoodsPrice();
	CGoods tempGoods = cg[start];
	int i = start;
	int j = end;
	while (i < j)
	{
		while (i < j&&keyInt <= cg[j].getGoodsPrice())
		{
			j--;
		}
		if (i < j)
		{
			cg[i++] = cg[j];
		}
		while (i < j&&cg[i].getGoodsPrice() <= keyInt)
		{
			i++;
		}
		if (i < j)
		{
			cg[j--] = cg[i];
		}
		cg[i] = tempGoods;
		sortByPrice(cg, start, i - 1);
		sortByPrice(cg, i + 1, end);
	}
}


void CsqList::sortByStateNum()
{
	if (checkEmpty())
	{
		cout << "表为空" << endl;
		return;
	}
	unsigned int subPoint;
	CGoods tempGoods;
	for (int i = 0; i < m_listLength; i++)
	{
		subPoint = i;
		for (int j = i + 1; j < m_listLength; j++)
		{
			if (m_cgSqList[j].getGoodsStateNum() < m_cgSqList[subPoint].getGoodsStateNum())
			{
				subPoint = j;
			}
		}
		if (i != subPoint)
		{
			tempGoods = m_cgSqList[i];
			m_cgSqList[i] = m_cgSqList[subPoint];
			m_cgSqList[subPoint] = tempGoods;
		}
	}
	toString();
}

void CsqList::sortInterface(int flagSwitch)
{
	switch (flagSwitch)
	{
	case 1: {
		sortByName();
	}break;
	case 2: {
		if (checkEmpty())
		{
			cout << "表为空" << endl;
			return;
		}
		sortByPrice(m_cgSqList, 0, m_listLength - 1);
		toString();
	}break;
	case 3: {
		sortByStateNum();
	}break;
	case 4:
		return;
	default: {
		cout << "选择错误！" << endl;
	} break;
	}
}

unsigned int CsqList::findInterface(int flagSwitch)
{
	bool flagFind;
	switch (flagSwitch)
	{
	case 1: {
		string tempString;
		cout << "输入要查找的商品名:";
		cin >> tempString;
		flagFind = findGoods(tempString);
	}break;
	case 2: {
		unsigned int tempInt;
		cout << "输入要查找的商品价格:";
		cin >> tempInt;
		flagFind = findGoods(tempInt);
	}break;
	case 3: {
		unsigned int tempInt;
		cout << "输入要查找的商品数量:";
		cin >> tempInt;
		flagFind = findGoods(tempInt);
	}break;
	case 4: {
		cout << "返回上级" << endl;
		return 0;
	}
	default: {
		cout << "选择错误！" << endl;
		flagFind = false;
	}
			 break;
	}
	if (!flagFind)
	{
		cout << "未找到符合条件的商品！" << endl;
		return 0;
	}
	else
	{
		cout << "找到符合条件的商品，商品序号为：" << flagFind << endl;
		cout << "商品信息如下：" << endl;
		toString(g_findVector);
	}
	return flagFind;		//return Tab
}

void CsqList::delGoods()
{
	bool subTab;
	bool delTab;
	int tempFlag;
	findMenu();
	cout << "请选择查找删除对象方法：" << endl;
	cin >> tempFlag;
	subTab = findInterface(tempFlag);
	
	if (subTab)
	{
		char tempChar;
		cout << "是否确认删除上述项目？确认键入Y/y：";
		cin >> tempChar;
		if (tempChar=='Y'||tempChar=='y')
		{
			int goodsTab;
			for (int i = 0; i < g_findVector.size(); i++)
			{
				goodsTab = g_findVector[i] - i;
				for (int j=goodsTab ; j < m_listLength; j++)
				{
					m_cgSqList[j] = m_cgSqList[j + 1];
				}
				m_listLength--;
			}
		}
		cout << "删除完毕！" << endl;
	}
}

void CsqList::delGoods(int subTab)
{
	if (checkEmpty())
	{
		cout << "表为空" << endl;
		return;
	}
	if (subTab>=m_listLength)
	{
		cout << "越界访问！" << endl;
		return;
	}
	for (int i = subTab; i < m_listLength; i++)
	{
		m_cgSqList[i] = m_cgSqList[i + 1];
	}
	m_listLength--;
	cout << "删除完毕！" << endl;
}


void mainMenu()
{
	cout << "===================================" << endl;
	cout << "==============功能菜单=============" << endl;
	cout << "============1、添加商品============" << endl;
	cout << "============2、查找商品============" << endl;
	cout << "============3、商品排序============" << endl;
	cout << "============4、指定输出============" << endl;
	cout << "============5、打印全部============" << endl;
	cout << "============6、删除商品============" << endl;
	cout << "============7、退出程序============" << endl;
	cout << "===================================" << endl;
}

void findMenu()
{
	cout << "===================================" << endl;
	cout << "==============功能菜单=============" << endl;
	cout << "============1、名字查找============" << endl;
	cout << "============2、价格查找============" << endl;
	cout << "============3、库存查找============" << endl;
	cout << "============4、返回上级============" << endl;
	cout << "===================================" << endl;
}

void sortMenu()
{
	cout << "===================================" << endl;
	cout << "==============功能菜单=============" << endl;
	cout << "============1、名字排序============" << endl;
	cout << "============2、价格排序============" << endl;
	cout << "============3、库存排序============" << endl;
	cout << "============4、返回上级============" << endl;
	cout << "===================================" << endl;
}

int main()
{
	CsqList sqList;
	sqList.initSqList();
	int flagSwitch;
	int subTab;
	while (true)
	{
		mainMenu();
		cin >> flagSwitch;
		switch (flagSwitch)
		{
		case 1:
		{
			int tempSum;
			cout << "请输入要添加的数量" << endl;
			cin >> tempSum;
			cout << "请按以下格式添加：" << endl;
			cout << "商品编号" << " " << "商品名" << " " << "单价" << " " << "库存数量" << endl;
			sqList.addGoods(tempSum);
		}break;
		case 2:
		{
			int tempFlag;
			findMenu();
			cout << "请选择查找方法：" << endl;
			cin >> tempFlag;
			subTab = sqList.findInterface(tempFlag);
		}break;
		case 3:
		{
			int tempFlag;
			sortMenu();
			cout << "请选择排序方法：" << endl;
			cin >> tempFlag;
			sqList.sortInterface(tempFlag);
		}break;
		case 4:
		{
			int tempFlag;
			cout << "输入要输出的序号：" << endl;
			cin >> tempFlag;
			sqList.toString(tempFlag);
		}break;
		case 5:
			sqList.toString();
			break;
		case 6:
		{
			cout << "选择删除方法：1、通过条件查找删除 2、通过序号删除" << endl;
			int tempFlag;
			cin >> tempFlag;
			if (tempFlag==1)
			{
				sqList.delGoods();
			}
			if (tempFlag==2)
			{
				int sqTab;
				cout << "输入要删除的序号：" << endl;
				cin >> sqTab;
				sqList.delGoods(sqTab);
			}
			else
			{
				cout << "输入错误！！！" << endl;
			}
		}break;
		case 7:
			return 0;
		default:
			break;
		}
	}
}