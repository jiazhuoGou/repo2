#include<iostream>
#include<vector>
#include<string>
#include<typeinfo>
#include<array>
#include<algorithm>
#include<cassert>
#include<filesystem>
#include<fstream>
#include<iomanip>

#include "../include/Circle.h"
#include "../include/Employee.h"
#include "../include/Date.h"
#include "../include/Helper.h"
#include "../include/Rectangle.h"
#include "../include/Shape.h"

using namespace std;

namespace fs = filesystem;

void print(array<int, 5> &arr);
constexpr int factorial(int n)
{
	if (n == 0)
	{
		return 1;	// error
	}
	else
	{
		return n * factorial(n-1);
	}
	
}

int Employee::numberOfObjects = 0;

int main(void)
{
	
	cout << "alohaworld" << endl;
	//auto c1 = Circle{2.3};	//	用匿名对象做拷贝列表初始化
	//Circle c2{3.2};	// 直接列表初始化

	Circle c3{};	// 直接列表初始化，调用默认构造函数
	//c3 = Circle{4.5};	// 用匿名对象赋值

	//cout << "哈哈啊咯" << c3.getArea() << endl;
	//cout << c1.getArea() << endl;
	//cout << Circle{12}.getArea() << endl;

	//Circle *p3 = &c3;
	//cout << "用指针 " << p3->getArea() << endl; 
	//Circle *pObj = new Circle{100.1};
	//cout << "用new创建对象 " << pObj->getArea() << endl; 
	
	//delete pObj;
	

	/**
	 * 对象数组
	 */
	//auto C = new Circle[3] {1.1, 1.2, 1.3};
	//Circle C1[] {1.1, 1.2, 1.3};
	/*for(auto c1 : C1)
	{
		//cout << c1.getArea() << endl;
	}*/

	/**
	 * @brief 对象作为函数参数
	 * 
	 */
	/*
	c1.print(C[1]);
	c1.print(C[1]);
	c1.print(&C[1]);
	c1.setRadius(C[2].getRadisu());
	//cout << c1.getRadisu() << endl;
*/
	// string类
	string s{"hello"};
	s.assign(" alohaw ord    ");
	s.append("!");
	// 移除空格
	s.erase(0, s.find_first_not_of(" \t\n\r"));	//删除前面的空格
	s.erase(s.find_last_not_of(" \t\n\r")+1);	// 删除后面的空格
	s += "1";
	cout << s << endl;
	string str{"1234"};
	int x = stoi(str);
	cout << typeid(x).name() << endl;
	array<int, 5> arr {2,3,7,9,100};
	array arr2{99,7,26,13,12};
	array a2{'a', 'b', 'c'};
	cout << typeid(arr).name() << endl;
	cout << typeid(a2).name() << endl;
	//cout << abi::__cxa_demangle(typeid(a2).name(), NULL, NULL, NULL)<<endl;	// 显示正常的类型名
	// 交换两个数组
	arr.swap(arr2);	// 2个数组的值被交换
	print(arr);
	print(arr2);
	// 求数组大小
	cout << arr.size() << endl;
	cout << arr.max_size() << endl;
	sort(arr.begin(), arr.end());
	print(arr);

	// 断言测试
	// 用递归计算factorial，用assert检查3的阶乘
	int f = factorial(3);
	cout << "阶乘: " << f << endl;

	// 将factorial变成常量表达式，用static_assert检查3的阶乘
	static_assert(factorial(3) == 6, "should be 6" );
	
	// 创建factorial(4)大小的数组
	array<int, factorial(4)> a;
	cout << a.size() << endl;

	// 不可变对象
	/*
	Employee e;
	e.setBirthday(Date(1999, 1, 1));
	cout << e.toString() << endl;
	e.getBirthday()->setYear(1998);
	cout << e.toString() << endl;*/

	// 析构函数
	cout << "----------析构函数--------" << endl;
	{
		Employee e1;
		cout << e1.toString() << endl;
	}
	Employee *e2 = new Employee("john", Gender::male, Date(1990, 3, 2));
	cout << e2->toString() << endl;
	
	{
		Employee *e3 = new Employee("alice", Gender::famale, Date(1980, 4, 2));	//	这个作用域之后，e3并没有被消除？是因为在堆上要手动删吗
		Employee e4{"tom", Gender::famale, Date(2010, 4, 1)};	// 看来是这样的，根据打印信息, 这个e4是在栈上，出了这个域就被删了
		delete e3;	//	同时如果要删除e3，也要在该作用域内
	}
	delete e2;
	cout << "\n";

	// 深拷贝
	//cout << "----------深拷贝--------" << endl;
	cout << "----------deep copy--------" << endl;
	Employee e1{"Alex", Gender::male, {1998, 5, 1}};
	Employee e3{e1};
	cout << e1.toString() << endl;
	cout << e3.toString() << endl;
	cout <<  "after add copy functoin" << endl;
	Employee e4{e1};	// 生日对象是2个对象了，不在共用
	cout << e4.toString() << endl;
	cout << "\n";

	cout << "----------vector--------" << endl;
	vector words1{"aloha", "world", "welcom!"};
	PRINT(words1);
	words1.erase(words1.end()-1);	//	删除最后一个元素
	PRINT(words1);
	words1.push_back("cqupt");
	PRINT(words1);
	vector<string> words2 {words1.begin()+1, words1.end()};
	PRINT(words2);


	cout << "----------Inherit--------" << endl;
	//Shape s1{Color::blue, false};
	Circle c4{3.9, Color::green, true};
	Rectangle r1{4.0, 1.0, Color::white, true};

	//cout << s1.toString() << endl;
	cout << c4.toString() << endl;
	cout << r1.toString() << endl;
	cout << r1.getArea()  << endl;

	Shape *shape = &c4;	//	向上转型，子类重写过父类的虚函数，该调用子类重写的
	cout << shape->toString() << endl;
	cout << typeid(Shape).name() << endl;
	cout << "\n";

	cout << "----------filesystem--------" << endl;
	fs::path p2{R"(../resource/test.cpp)"};
	fs::path p1 {("/home/goujz/Documents/CPPSTUDY/resource/test.cpp")};
	fs::path p3 {("/home/goujz/Documents/CPPSTUDY")};
	cout << "p1 is : " << p1 << endl;
	// 输出默认文件分隔符
	cout << "default separator : " << fs::path::preferred_separator << endl;
	cout << "p2 is  : " << p2 << endl;	// p2能正常打印
	// 判断是否是常规文件，是就输出文件大小
	if (fs::is_regular_file(p2) )
	{	// 使用相对路径在这判断有问题, 绝对路径没问题
		cout << p2 << " 's size :  " << fs::file_size(p2) << endl;
	}
	else if (fs::is_directory(p3))
	{	// 是目录，列出出其子目录
		cout << p3 << "is not directory, includes: " << endl;
		for(auto &e: fs::directory_iterator(p3))
		{
			cout << "   " << e.path() << endl;
		}
	}
	else if (fs::exists(p1))
	{
		cout << p1 << "is a special file" << endl;
		cout << p1 << " 's size :  " << fs::file_size(p1) << endl;
	}
	else
	{
		cout << p1 << "does not exits" << endl;
	}
	
	// 展示path类中用于分解路径成分的函数
	fs::path p4 {R"(/home/goujz/Documents/CPPSTUDY/resource/test.cpp)"};
	if(p4.empty())
	{
		cout << "path : " << p4 << "is empty" << endl;
	}
	if(!fs::exists(p4))
	{
		cout << "path : " << p4 << " does not exist" << endl;
		exit(0);
	}
	cout << "root name() : " << p4.root_name() << "\n"
		<< "root path() : " << p4.root_path() << "\n"
		<< "relative path() : " << p4.relative_path() << "\n" 
		<< "parent path() : " << p4.parent_path() << "\n"
		<< "file name() : " << p4.filename() << "\n"
		<< "stem() : " << p4.stem() << "\n"
		<< "extension() : " << p4.extension() 
		<< endl;
	
	// 展示磁盘总大小和剩余大小
	fs::path p5{"/"};
	cout << "total space : " << fs::space(p5).capacity << endl;
	cout << "free space : " << fs::space(p5).free << endl;

	/* 文件流 */
	// fs::path p6 {"../resource/test_empty.cpp"};
	// 写文件
	fs::path p6 {"/home/goujz/Documents/CPPSTUDY/resource/score.txt"};
	ofstream output{p6};
	double lileiScore{90.5}, hanmeimeiScore{94.6};
	output << "LiLei " << lileiScore << endl;
	output << "Hanmeimei score : " << hanmeimeiScore << endl;
	output.close();
	cout << "size of " << p6 << "is : " << fs::file_size(p6) << endl;

	// 读文件
	fs::path fp7 {"/home/goujz/Documents/CPPSTUDY/resource/score2.txt"};
	ifstream input{fp7};
	if(input.fail())
	{
		cout << "can't open file " << fp7 << endl;
		return 0;
	}
	string name{""};
	double score{0.0};
	char in_x;
	for(; !input.eof(); )
	{
		input.get(in_x);
		cout << in_x;
	}
	input.close();

	// 填充字符，设置域宽
	cout << setprecision(2) << 3.14159 << endl << flush;
	// 当设置的浮点数总的有效数少了，这个double发生了四舍五入
	cout << setfill('*') << setprecision(5) << setw(10) << 3.14159 << endl;





	//system("pause");
	return 0;
}


void print(array<int, 5> &arr)
{
	for(auto it = arr.begin(); it != arr.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n";
}

