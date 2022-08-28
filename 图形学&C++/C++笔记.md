## Essential C++

### C++编程基础

#### 1.1如何撰写C++程序

头文件：用来声明该class所提供的各种操作行为。

程序代码文件：包含这些操作行为的实现内容。

iostream:输入输出库，包含相关的整套class，用以支持对终端和文件的输入输出。

```c++
#include <iostream>
#include <string>
using namespace std; //通过将库名称封装起来的方法，可以避免与应用程序发生命名冲突
int main()
{
	string user_name;
	cout << "Please enter your first name: "<<endl;
   //cout标准输出流对象，打印字符串
   //endl刷新缓冲区，并换行
	cin >> user_name;
	cout << '\n' << "Hello," << user_name;
	return 0;    //以return表示main（）程序到此结束
}
```

```c++
int num_tres(0);  //构造函数语法进行初始化，常用于一个对象需要多个初值进行初始化（如复数）
#include <complex> 
//complex是一个模板类 template class（模板类），template class允许我们在不指明数据程序类型情况下定义class，将complex类的成员绑定至double类型
complex<double> purei(0,7);
```

**命名空间:**

<img src="F:\C++代码资料\语法分享\114.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\语法分享\115.png" style="zoom:50%;" />

匿名命名空间：

```c++
namespace  //匿名命名空间，类似于static int d = 40;,只允许在该文件中访问
{
   int d =40;
}
```

命名空间取别名：

```c++
void test01()
{
    namespace newmaker = maker;
}
```

<img src="F:\C++代码资料\语法分享\117.png" style="zoom:50%;" />

为什么要有命名空间：

为了解决多人合作时，命名空间重命名的问题

##### using

```c++
namespace A
{
   int a=10;
   int b=20;
   int c=30;
}
void test01()
{
    using A::a;  //using声明让命名空间中某一个标识符可以重复使用
    cout<<a<<endl;
   //int a=100;  //using声明了某个变量，在该定义域内不可声明同名的变量


}
```

<img src="F:\C++代码资料\语法分享\118.png" style="zoom:67%;" />

```c++
#include <iostream>
#include <string>
using namespace std  //通过using编译指令，让下面的代码都可以使用iostream中命名空间里的标识符
```

#### 1.5使用Array与Vector容器

```c++
#include <vector>
const int seq_size = 18;
vector<int> elem_seq(seq_size);
ele_seq[0] = 1;
int b[7] = {1,2,3,4,5,6,7};
vector<int> elem_seq(b,b+7);
//括号里两个数都是实际内存位置，标记出了用以将vector初始化的元素范围
vector<int> *q [2] ={&fib,&cid} ;
```

![](F:\计算机图形学\fig\79.png)

![](F:\计算机图形学\fig\80.png)

#### 1.6指针

指针就是地址

<img src="F:\C++代码资料\Fig\1.png" style="zoom: 50%;" />

```c++
int main()
{
    int a = 10;
    int * p;  //什么类型的数据定义一个什么类型的指针
    p = &a;  //让指针记录变量a的地址
    cout<<p<<endl;
    cout<<&a<<endl;
    *p = 1000;     //指针前加*解引用，找到指针指向的内存中的数据
    cout<<a<<endl;  //输出均为1000
    cout<<*p<<endl;
}
```

```c++
sizeof(int *);
sizeof(float *);
sizeof(double *);
sizeof(char *); //在32位系统下，以上所有指针都占4个字节空间，64位系统下占八个字节

int * p =NULL;  //初始化指针，让其指向地址值为0的地址,空指针
int * p = 0 ; //初始化指针，让其指向地址值为0的地址
//空指针用途是初始化
//空指针指向内存编号为0的空间
//空指针不可解引用访问，内存中0-255为系统占用内存，用户访问会报错

if(p && *p!=1024){}
 //防止对空指针进行解引用操作，在解引用前先判断p指针地址是否为0，若为0，解引用前求值结果为false，不会对第二表达式求值，避免发生空指针访问异常
if(！p){} //检验指针是否为null，一般用NOT逻辑判断
```

```c++
int * p = （int *）0x1100; //将一块不知道是什么的内存直接指向它（野指针），（有可能装的是string类型）
cout<<*p<<endl;//访问野指针会报错,要尽量避免野指针，野指针很危险
```

```c++
int a = 10;
const int * p  = &a;
*p = 5; //wrong
p = &b;//可行
//常量指针：指针指向的值不可修改，指向可以改

int a = 10;
int * const p  = &a;
//指针常量：指针的指向不可以修改，指针指向的数值可以修改

const int * const p = &a;  //const修饰常量和指针，指向与数值都不可以改

```

```c++
int main()
{
int arr[6] = {1,2,3,4,5,6};
int * p = arr;
//指针指向数组中第一个元素
for(int i = 0;i<10;i++)
{
    cout<<*p<<endl;
    p++;      //指针访问数组中每一个元素
}
    System("pause");
    return 0;
} 
```

```c++
void swap(int * p,int * q)
{  }
swap(&a,&b);
```

<img src="F:\C++代码资料\Fig\2.png" style="zoom:50%;" />

#### 结构体

```c++
struct student   //定义结构体时候，结构体关键字struct不可省略
{
    string name;
    int age;
    int grade;
}
struct student  s1 ; //创建结构体变量时，关键字struct可以省略
s1.name = "jack";
s1.age = 8;
s1.grade = 80;

struct student s2 = {"李四",9,100}

struct student   //定义结构体时候，结构体关键字struct不可省略
{
    string name;
    int age;
    int grade;
}s3;    //定义结构体时,顺便创建结构体变量

//创建结构体数组
struct student students_arr[3]{
    {"张三",1,2}
    {"李四",3,4}
}
students_arr[1].name = "wangwu";

```

定义结构体变量时不需要写struct

结构体内可以定义函数

##### 结构体指针

```c++
struct student s={"zhangsan",1,2}
struct student * p = &s;   //struct可以省略，student结构体的指针就只能定义student不能定义int
cout<<p->s.name<<endl;  //通过结构体的指针访问结构体中的属性，用->
```

结构体的值传递与地址传递同之前讲的基本数据类型传递方式类似。

```c++

void printstu(const struct student *p) 
    //为了防止传递指针，结构体内数值被改变（误操作），可加上const
{
    cout<<p->stu.name<<endl;
}
int main()
{
struct student stu = {"lisi",1,2};
printstu(&stu);  
//向函数内传递结构体的指针，而不采用值传递（结构体如果有很多属性会占用内存空间），可节省使用内存空间
    return 0；
}
```

```c++
if(!vec.empty()&&vec[1]!=1) //检查Vector第一个元素是否为1
//转化为指针的写法：
if(p && p->empty() && ((*p[1]!=1)) //需要在判断Vec是否为空之前先判断p是否为空指针
```

在无返回值的函数中，以 return；代表函数无返回值。

**C++更加严格的类型转化**

<img src="F:\C++代码资料\语法分享\119.png" style="zoom:50%;" />

#### 引用：

```c++
int &p = q;   //这里&不是取地址符，而是引用的标识作用，相当于给q所在的这个空间取了个别名
    //应用操作，无法再令&p转而代表其他对象，必须从一而终。
    //引用创建时，一定要初始化（像const）
    //引用操作的必须是一个合法的内存空间。free之后的空间不能做引用

//面对所有p代表的对象的操作与对&p引用方法操作相同。
//通过引用操作传入函数中，复制的是对象的地址。
//将参数声明为引用的理由：
void swap（int &val1，int &val2）
1.希望直接对传入的对象进行修改
2.降低复制大型对象的额外负担
使用指针与引用区别是，使用指针时需要判断是否为空指针。而引用则不需要检查，其必定会代表某个对象。
```

```c++
void func(int &b)
{
    b=200;
}
void test02()
{
    int a=10;
    func(a);
}
```

引用就是给空间起别名，和c语言指针一样的特性，是语法更简洁

```c++
int main()
{
    int a= 1;
    int& pref = a;
    int b=10;
    pref = b;  //这里是赋值作用，引用不能更改他的指向
}
```

**数组引用：**

<img src="F:\C++代码资料\语法分享\123.png" style="zoom:50%;" />

**引用的本质**：

<img src="F:\C++代码资料\语法分享\125.png" style="zoom: 67%;" />

**指针的引用：**

<img src="F:\C++代码资料\语法分享\126.png" style="zoom: 67%;" />

char* &p1 = p； //p1是指针引用，p1相当于给p这片地址空间起的别名，打印p1相当于打印出了解引用的p

![](F:\C++代码资料\语法分享\128.png)

tmp=p，（实质是const char*tmp，解引用了tmp赋值为p）

<img src="F:\C++代码资料\语法分享\129.png" style="zoom:50%;" />

如果函数值当左值，该函数必须返回引用。

**常量的引用：**

```c++
int main()
{
    int a=10;
    int &ref = a;
    ref = 20;
    int &ref = a; //不能直接拿实际的数值取别名 ，别名顾名思义
    const int &ref = 10; //可以直接给const修饰的引用赋值 字面量 
                         //编译器将上面代码自动优化为  int temp = 10；
                         //                        const int &ref  = temp;
}
```

#### 动态内存管理：

堆内存（空闲内存）由new表达式完成，释放必须通过delete释void放。

默认由堆分配来的对象，均未初始化，初始化赋值后会分配其他地址

```c++
int *p = new int[24];
//p会被初始化为数组第一个元素的地址，数组中的每个元素都未经初始化
delete []p   //删除数组中所有对象 
```

#### 提供默认参数值：

```c++
void sort (vector<int> &vec,ofstream *of = 0)
{
    if(*of!=0)
    (*of)cout<<"11"<<endl;
}
 //希望用户不必传入输出用的stream，且有能力将输出信息关闭。但还希望想要看到这些信息的人可以产生他

void sort (ostream *of = 0，vector<int> &vec) //错误写法，默认值的解析是从右至左解析的，默认值得声明应放在最右侧，如果放在左侧就默认了右边得定义必须也全是默认值
  
一般来说函数的声明会放在头文件，我们称此头文件为NumerSeq.h
void sort (vector<int> &vec,ostream & = cout)
 
#include "NumerSeq.h"
void sort (vector<int> &vec,ostream &oS){}
```

#### 声明inline函数：

声明inline函数可以在函数调用处，将函数展开。面对一个inline函数，编译器可将调用操作改为以一份副本代替。

一般最适合声明成inline得函数，都 体积小，常被调用，所从事的计算不复杂。

inline函数的定义，常常被放在头文件中。

```c++
inline bool fibon(int pos,int &elem)
```

<img src="F:\C++代码资料\语法分享\130.png" style="zoom:67%;" />

<img src="F:\C++代码资料\语法分享\131.png" style="zoom:67%;" />

#### 函数的默认参数：

```c++
int myfunc(int a,int b=10)  // b=10是函数默认参数，但不一定是10
{
    return a+b;
}
void test01()
{
    cout<<myfunc(12,20)<<endl;  //调用函数时常用到形参某个值，但偶尔用到其他值时
    cout<<myfunc(10)<<endl;    /具有灵活性
}

int myfunc(int a,int b=10，int c =12，int d =30)  
    //函数默认参数后面必须都是默认参数（占位参数同理）
{
    return a+b;
}
//函数的声明和实现不能同时具有默认参数
```

**占位参数**

<img src="F:\C++代码资料\语法分享\132.png" style="zoom:50%;" />





#### 重载函数：

参数列表不同，但拥有相同得函数名称，以及相同得返回类型。

#### 定义模板函数：

```c++
template <typename T>
void display_maeeage(const strinf &msg, const vcetor<T> &vec){}
//定义的泛型函数，T类型在用户调用时才会被确认,相当于一个占位符
//模板函数也可以进行重载
```

```c++
函数指针：
const vector<int>* (*seq)(int);
//函数整体返回的是const vector<int>*；seq函数返回得是指针参数列表里为int，这个指针指向另一个指针，后者指向const vector，所以加上括号
const vector<int>* (*seq_arry[])(int)={ ,,,,,};
//*seq_arry是一个可以持有六个函数指针的数组
```

#### 设定头文件：

inline函数得定义必须放在头文件中。

```
extern是一个关键字，它告诉编译器存在着一个变量或者一个函数，如果在当前编译语句的前面中没有找到相应的变量或者函数，也会在当前文件的后面或者其它文件中定义，来看下面的例子：

#include "stdafx.h"
#include <iostream>
using namespace std;
 
extern int i;
extern void func();
int _tmain(int argc, _TCHAR* argv[])//typedef wchar_t     _TCHAR;#define _tmain      wmain
{
	i = 0;
	func();
	return 0;
}
 
int i;
 
void func()
{
	i++;
	cout << "i = " << i << endl;
//上面代码中变量i和函数func在文件末尾定义，所以变量需要使用extern关键字告诉编译器，变量在别的地方定义

首先，定义在其它文件中的函数和变量，可以使用两种方法调用：

 一、使用头文件调用，这时候，函数和变量必须在头文件中定义和声明。

 二、使用extern关键字调用，这时候函数和变量在.cpp或者.c文件中定义和声明
const vector<int>* (*seq)(int); 前加上 extern便成为一个声明，若放在头文件中定义，则会被解读为定义而不是声明
extern const vector<int>* (*seq)(int);
```

#### **泛型编程：**

find函数来查询返回array中指定的元素，

若对于数组进行处理array

``` c++
template<typename T>
T* find(const T * array,int size,const T &value)
{
    if(!array||size<1) //判断是否为空指针并判断数组大小是否为空
    {
        return 0 ;
    }
    for(int ix = 0 ; ix < size ; ++ix)
    {
     if(array[ix] == value)  //这里指针类型 带下标会指向下标位置的数组元素 
     {
         return &array[ix];  //返回一个下标位置的引用类型
     }   
    }
    return 0;
}
```

```c++
template<typename T>
T* find(const T * array,int size,const T &value)
{
    if(!array||size<1) //判断是否为空指针并判断数组大小是否为空
    {
        return 0 ;
    }
    for(int ix = 0 ; ix < size ; ++ix,++array)
 //这里的+array是指array这个指针加1，加1相当于array原本地址（1000）加上4byte（整形）就是加4（1004），变成了1004位置的元素
    {
     if(*array == value)
         //&array解引用
     {
         return array;
     }   
    }
    return 0;
}
```

```c++
template<typename T>
T* find(const T * array,const T *last,const T &value)
{} 
//这里我们也可以用last指针指向数组元素得最后一个结点得下一个结点（标兵节点）来取代size
```

若对于vector进行处理：

```c++
与数组不同的是，vector有可能为0。可以对于前后标兵结点封装为一个函数
template<typename T>
inline T* begin(const vector<T> &vec)
{vec.empty?0:&vec[0];}

template<typename T>
T* find(begin(svec),end(svec),const T &value)
```

list与vector和array不同，list元素以一组前后向指针相互连接，这里引出泛型（Iterator）指针。

#### 泛型指针：

```c++
template<typyname T,typyname IteratorType>
vector<string> ::iterator iter = svec.begin();
//iter被定义为一个iterator指向vector得初值
//vector一一片连续的内存存放元素
//list以双向链接，非连续内存来储存内容，每个元素包含三个字段（value,back指针（指向前一个元素）,front（指向下一个元素）
//deque与vector都以连续内存储存元素。不同的是，deque操作最前（末）端元素插入，删除效率更高
vector<int>::iterator it;
it = find(svec.begin();svec.begin();1024) //返回一个指向vetor得泛型指针
if(it!=ivec.end())  //找到了
```

##### C++容器的共通操作：

```
   1.== 和 != 运算符，都是返回true和false；

   2.赋值（=），是将一个容器赋值给另一个容器。

   3.empty都是返回的true和false；

   4.size都表示，容器内部，现在持有的元素个数。

   5.clear（）删除所有元素。

   6.begin()都是指向容器的第一元素。

   7.end()都是返回容器的最后一个元素的下一个位置；

   8.insert()，将单一或者某一个范围内的元素插入容器。

   9.erase(),都是将容器内的单一元素或者某个范围内的元素，删除。

```

```c++
产生特定大小的容器，为每个容器赋初值
vector<int> ivec(10,-1);
front()
back()
pop_front()
pop_back()
insert(iterator position,elemType value); 
//在position之前插入value,会返回一个泛型指向被插入的元素
insert(iterator position,int count,elemType value);//在position之前插入count个value

int ial[7] = {1,2,3,4,5,6,7} 
int ia2[4] = {1,2,3,4}
vector<int> list_ele(ial,ial+7);
list<string>::iterator it = find(list_ele.begjin(),list_ele.end(),55)
   //find返回一个55元素得位置（泛型指针）
list_ele.insert(it,ia2,ia2+4) //在·it位置元素前添加ia2整个数组，“ia2”是指向数组头节点的指针，ia2+4是指向数组尾节点的指针
list_ele.erase(iterator first,iterator last);//删除list_ele vector得[first，last）范围内的元素

list_ele.erase（itl，itl+2）；//错误：list不能使用指针的偏移运算
```

#### 使用泛型算法：

```c++
#include <algorithm>
find() //线性搜索，效率低于binary_search()
binary_search() //用于有序的搜索，找到返回true，找不到返回false
count()  //返回数值相符的元素数目
search()//对比容器中是否含有某个子序列，如果有则返回一个人iterator指向子序列起始处，不存在则指向末尾  
```

```c++
//使得比较操作参数化
copy(vec.begin(),vec.end(),temp.begin());
sort(temp.begin(),temp.end());
bool less_than(int v1, int v2)
{
    return v1<v2? true:false;
}
vector<int> filter(bigvec,value,less_than(int ,int )){} //占位符
//用户可以传入数值value，放在less_than的二号位，让bigvec中的数值与value比较
```

#### Function Object

```c++
Function Object 实现了我们原本以独立函数加以定义的事物
头文件：
  #include<functional>
  sort(vec.begin(),vec.end(),greater<int>() );
//默认情况下sort（）会进行升序排序，我们传入greater_than function object元素会以降序排序
其中greater<int>()会产生一个未命名的 class template object传给sort（）
    binary_search(vec.begin(),vec.end(),elem,greater<int>() );
//binary_search的搜索对象先按传入的function object先进行降序排序
transform( fib.begin(),fib.end(), //转换的元素范围
pell.begin(),  //要应用于转换操作上的所指元素
fib_plus.begin(),//所指位置用来存放转换结果
plus<int>() ) //想要应用的转换操作
```

#### Function Object Adapter

```c++
bind adapter会将function object的参数绑定至特定值，使二元function object转化为一元function object
bind1st 会将指定值绑定至第一操作数
bind2nd 会将指定值绑定至第二操作数
```

修改后的filter使用了bind2nd adapter：

```c++
vector<int> nvec(const vector<int> &vec,int val,less<int> &lt)
{
    vector<int> nvec;
    vector<int>:: const_iterator iter = vec.begin();
    while((iter = find_if(iter,vec.end,bind2nd(lt,val)))!=vec.end())
    {
        //如果iter处元素比val小就放进nvec
        nvec.push_back(*iter); //将iter位置解引用放进nvec
        ++iter;
    }
    return nvec;
}
```

另一种adapter是所谓的negator，它对function object的真伪值取反。

not1：可对unary function object的真伪值取反

not2：可对binary function object的真伪值取反

```c++
 //找出所有大于等于val的元素
while((iter = find_if(iter,vec.end,not1(bind2nd(lt,val))))!=vec.end())
  {}
```

如果找出所有小于val的元素，另一种方法是先对vec进行升序排序，再找到第一个大于val元素的位置，截去该位置到vec的末尾。

```c++
vector<int> sub_vec(const vector<int> &vec,int val)
{
    vector<int> nvec(vec);
    sort(nvec.begin(),nvec.end());
    vector<int>::iterator iter = find_if(nvec.begin(),nvec.end(),bind2nd(greater<int>(),val));
    nvec.erase(iter,nvec.end());
    return nvec;
}
    
```

#### 使用Map，Set：

```c++
#include<map>
#include<string>
map<string,int> words;
words["valunteer"] = 2; //在map中插入元素

map<string,int>:: iterator it = map.begin();
cout<<"key:"<<it->first<<"value:"<<it->second<<endl;

map的查询方法： words.find("balubteer"); 查询key
              words.count("bvareer"); 查询key在map中的个数，一般来说map中仅存在单种key
    

#include<set
#include<string>
map<string> words;
words.count("tword"); //查询set中元素
words.insert();  //插入单一元素
words.insert(vec.begin(),vec.end()); //插入指定范围元素
```

#### 使用Iterator Inserter：

![](F:\C++代码资料\Fig\20201201185552659.png)

\# 欲使用上述三种adapter，首先必须包含[iterator](![img](file:///C:\Users\Administrator\AppData\Roaming\Tencent\QQTempSys\%W@GJ$ACOF(TYDYECOKVDYB.png)https://so.csdn.net/so/search?q=iterator&spm=1001.2101.3001.7020)头文件：

\#  #include <iterator>

\# 这些adapter并不能用在array上。array并不支持元素插入操作。

\# insertion adapter作用

<img src="F:\C++代码资料\Fig\3.png" style="zoom:67%;" />

<img src="F:\C++代码资料\Fig\4.png" style="zoom: 80%;" />

![](F:\C++代码资料\Fig\5.png)

![](F:\C++代码资料\Fig\6.png)

```c++
while((iter = findif(iter,vec.end(),bind2nd(less_than<int>(),val))))
{
    * it++ = * iter++;
//将源端至目的端容器一一赋值
//从左向右读入，先对iter++（进行地址递增操作，再利用*进行解引用）
}
```

### 基于对象的编程风格：

##### 如何实现一个class

![](F:\C++代码资料\Fig\45.png)

前置声明：只将class的名字告诉编译器，并未提供其他任何信息。前置声明是我们得以进行类指针的定义

```c++
class stack；

stack *pt；

class stack

{
public:
  bool empty();
private:
}
stack::empty(){}
::是类运算解析运算符，若在类外定义要加::
 在类内定义member function，这个member function会被自动是为inline函数
   class定义与inline函数一般放在与class同名的头文件中
```

![](F:\C++代码资料\Fig\18.png)

如果p对象内部有int m_A属性，int的大小占用4个字节

##### 构造函数与析构函数

~~~c++
class  Triangular{
    public:
    Triangular();
    Triangular(int len);
}
Triangular t; //调用Triangular类的默认构造器
Triangular t = 8;//调用单参数的Triangular类构造器
##### 

```c++
class  Triangular{
    public:
    Triangular();
    Triangular(int len);
    private:
    _lenth ;
    _beg_pos;
    _next ;
}
Triangular t; //调用Triangular类的默认构造器
Triangular t = 8;//调用单参数的Triangular类构造器
Triangular t(); //C++兼容于C，对C而言，并没有调用构造器，是一个返回一个Triangular类的函数 
构造器定义的方法：
1.
    Triangular::Triangular()
{
    _lenth = 1;
    _beg_pos = 1;
    _next = 0;
}
2.
    class  Triangular{
    public:
    Triangular(int len = 1,int bp = 1);
}
3.
      Triangular::Triangular(int len,int bp)
{
    _lenth = len > 0 ? len:1;
    _beg_pos = _beg_pos > 0 ? _beg_pos:1;
    _next = _beg_pos - 1;
}
4.
    拷贝构造函数调用：
    1.使用一个已经创建完毕的对象初始化一个新对象
     Triangular::Triangular（const Triangular &rhs）: 
      //Triangular构造函数复制了一份先前定义过的Triangular的副本
     //但是又不希望对rhs修改，所以加上引用以及const
    _lenth(rhs._lenth)， _beg_pos(rhs._beg_pos),_next(rhs._next){}
~~~

<img src="F:\C++代码资料\Fig\10.png"  />

###### 2.值传递：

<img src="F:\C++代码资料\Fig\11.png" style="zoom: 67%;" />

值传递的本质是复制一份传递对象的副本，所以在值传递过程中（非地址传递），也会调用拷贝构造函数

###### 3.返回局部对象:

<img src="F:\C++代码资料\Fig\12.png" style="zoom: 80%;" />

在test03中p的地址实际上是doWork2空间回收后p1对象拷贝出的另一个地址（并不是p1地址）

<img src="F:\C++代码资料\Fig\13.png" style="zoom: 67%;" />

<img src="F:\C++代码资料\Fig\14.png" style="zoom:80%;" />

m_Height在类内部定义时是一个整型的指针

<img src="F:\C++代码资料\Fig\15.png" style="zoom: 50%;" />

##### 析构函数：

在class名称前面加上 ~ ，它没有任何参数与返回值

```c++
class Matrix
{
    
}
~Matrix（）
{
    delete pmat;
}
我们通过Matrix的构造器与析构实现了堆区的内存管理
```

![](F:\C++代码资料\Fig\7.png)

![](F:\C++代码资料\Fig\8.png)

##### 默认的成员逐一初始化：

```c++
class  Triangular{
    public:
    Triangular();
    Triangular(int len);
    ....
    
    private:
    int _lenth ;
    int _beg_pos;
    int _next ;
    double * p_mat
    ....
}
```

```c++
{
Triangular tri1(10);
Triangular tri2 = tri1;
//tri1中的成员变量都会依次复制到tri2中，便是默认的成员逐一初始化
}
//在代码段执行结束后，堆区数据释放，两个对象的p_mat指针是经过地址的复制后，指向堆区的同一块内存空间，在tri1释放后，tri2又要释放一次会出现异常，如何解决问题呢
使用copy constructor
    Triangular::Triangular（const Triangular &rhs）: 
      //Triangular构造函数复制了一份先前定义过的Triangular的副本
      _lenth(rhs._lenth)， _beg_pos(rhs._beg_pos),_next(rhs._next){ p_mat = new double(elem) }  //创建一数值大小与tri1相同的新的堆内存空间
    
```

![](F:\C++代码资料\Fig\9.png)



```c++
const int a=10;  //常量区，一旦初始化，不可以修改
void test()
{
    int *p = (int*)&a;  //a为const修饰的整型，取地址要先转化为int*
}
int main()
{
    extern const int c ;  //使用别的文件的全局const变量需要声明
    //局部的const变量可以通过指针间接修改，不可以直接修改
}
```

##### extern

c++中全局变量具有内部链接属性，除非在定义const全局变量处加上extern关键字，该全局变量才具备外部链接属性，可以在别的文件使用这个变量时加上extern后进行声明

##### 编译器优化

 <img src="F:\C++代码资料\语法分享\121.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\语法分享\120.png" style="zoom: 67%;" />

##### 编译器不能优化的情况：

1.其他变量给const修饰的局部变量赋值

<img src="F:\C++代码资料\语法分享\122.png" style="zoom: 50%;" />

2.自定义的数据类型

```c++
struct Maker
{
    Maker()
    {
        a = 10;
    }
    int a;
}
void test()
{
    const Maker ma;
    cout<<ma.a<<endl;
    Maker *p =  (Maker*)&ma;
    *p = 100;   //ma.a此时的数值为100，没有优化，不能优化自定义数据类型
}
```

<img src="F:\C++代码资料\语法分享\122.png" style="zoom:50%;" />

```c++
class  Triangular{
    public:
    int length() const{ return _length}
    //class设计者在member function身上标注const，告诉编译器这个member function不会更改class object的内容
    private：
   .... 
}
```

```c++
class val_class
{
    public:
    val_class(const Big_class &v)
        :_val(v){}
    Big_class & val() const {return _val;}
    private:
    Big_class _val;
}
问题：成员函数val返回一个引用类型，虽然没有直接改变 _val值，但相当于把_val公开出去，允许程序在别的地方修改
 可以按着成员函数可以根据const重载，提供两份成员函数定义：
class val_class
{
    public:
    const Big_class & val() const{return _val;}
    Big_class & val()  {return _val;}
}
```

```c++
class  Triangular{
    public:
    Triangular();
    Triangular(int len);
    void next_reset() const {_next = _beg_pos - 1;}
    
    private:
    int _lenth ;
    int _beg_pos;
    mutable int _next ;
//_next只是用来实现iterator的机制，本身并不属于数列抽象概念，加上mutable以后，对_next的改变不会破坏Triangular的常量性
}
```

##### const与mutable

**const：**

1.c语言：

<img src="F:\C++代码资料\Fig\21.png" style="zoom:67%;" />

普通函数是可以修改对象属性的，但常对象不允许函数修改属性，所以常对象只能调用常函数

<img src="F:\C++代码资料\Fig\22.png" style="zoom:50%;" />

##### this指针

<img src="F:\C++代码资料\Fig\23.png" style="zoom: 50%;" />

this指针系在member function内指向其调用者（一个对象）

this指针可以让我们访问调用者的一切，若想返回自身，则简单对this做提领操作  return *this；

若对对象进行复制操作，用if语句判断两个对象是否相同

```
 if（this ！= &rhs）
```

<img src="F:\C++代码资料\Fig\25.png" style="zoom:50%;" />

<img src="F:\C++代码资料\Fig\26.png" style="zoom:50%;" />

以值的方式 <u>返回*this,</u> 链式调用，每次返回都是一个  <u>新的对象</u>

如果this所指本对象为NULL，报错：

<img src="F:\C++代码资料\Fig\28.png" style="zoom:50%;" />

<img src="F:\C++代码资料\Fig\29.png" style="zoom:50%;" />

空指针p可以访问函数体内部不带member_value的成员函数，不会报错

空指针p也可以访问函数体内部带member_value的成员函数，但会报异常因为this需要指向member_value（不能为空）,但是空指针this为空

##### 静态成员与静态成员函数

static表示data member是唯一，可共享的member

static member function可直接由类调用，只能访问静态data member

在类的外部进行static member function的定义时，（已经在类的内部声明了static member function），则无需加上关键字static。

<img src="F:\C++代码资料\Fig\16.png" style="zoom:67%;" />

```c++
Person p；

通过类名访问：

func是一个静态函数

Person：：func（）；
```

<img src="F:\C++代码资料\Fig\17.png" style="zoom:67%;" />

##### 嵌套类型

```
typedef existing_type new_name;
```

typedef可以为某个类型设置一个不同的名称

```c++
class A {
public:
    class B {
    public:
        explicit B(void):idx(3){}
        B(const B&b)  {
            idx = 4;    // 不被调用
        }
    private:
        int idx=0;
    };
    B getB()
    {   return A::B();   }
};
void test2(){
    A a;
    A::B b = a.getB();  // b.idx 最终的值为 3
}
 //B为A的嵌套类型，在外部声明 A::B b = a.getB();
```

A 作为一个类对象包含 手B这个类成员，A 这个类对象在构造时优先构造 B 这个类对象，再构造自身，而析构的顺序则相反

##### 友元

全局函数做友元：

<img src="F:\C++代码资料\Fig\19.png" style="zoom: 50%;" />

成员函数作友元：

<img src="F:\C++代码资料\Fig\20.png" style="zoom:50%;" />



##### 运算符重载操作

<img src="F:\C++代码资料\Fig\30.png" style="zoom: 150%;" />

##### 通过成员函数重载+号：

```c++
Person operator+（Person &p）
{
    Person temp;
    temp.m_A = this->m_A + p.m_A;    
    temp.m_B = this->m_B + p.m_B;
    return temp;
}
```

<u>**运算符重载也可以发生函数重载**</u>

<img src="F:\C++代码资料\Fig\31.png" style="zoom: 67%;" />

<img src="F:\C++代码资料\Fig\32.png" style="zoom: 50%;" />

##### 利用全局函数实现左移运算符重载

不能利用成员函数实现左移运算符，是因为若使用成员函数实现，p与cout的位置会互换

##### 访问类中私有属性则利用友元技术

<img src="F:\C++代码资料\Fig\33.png" style="zoom: 50%;" />

```c++
ostream & operator<<(ostream &out,Person &p)
{
    out<<"m_A="<<p.m_A<<"m_A="<<p.m_B;
    return out;
}
//返回ostream类型的out以达到左移运算符的链式编程
```

##### 利用成员函数实现递增运算符重载

###### 重载前置++运算符

```c++
MyInteger & operator++()
 //前置++  返回值  不可以选用真实值：如图，前置进行完第一次++如果返回一个真实值后，再进行第二次递增操作时，真实值对象相当于先进行一次前浅拷贝再执行cout输出，那么原先的myint对象仍然为1，所以46行输出2，47行输出为1
{
    m_Num++;
    return *this;
    //利用成员函数永远比利用全局运算符参数列表少一个参数
}
//(使用&引用运算符，&p = *this，对引用&p对操作与对this对象自身操作相同)
```

前置++  返回值  不可以选用真实值：如图，前置进行完第一次++如果返回一个真实值后（46行），再进行第二次递增操作时，真实值对象相当于先进行一次前浅拷贝再执行cout输出，那么原先的myint对象仍然为1，所以46行输出2，47行输出为1

<img src="F:\C++代码资料\Fig\34.png" style="zoom: 50%;" />

![](F:\C++代码资料\Fig\35.png)

**返回引用类型实则在这个函数执行结束后，栈空间将被释放即引用类型被释放，局部变量被释放。所以需要返回一个真实值，返回的真实值经过浅拷贝操作，得到的是另一个地址的MyInterger的对象。**

<img src="F:\C++代码资料\Fig\36.png" style="zoom:50%;" />

程序员针对堆区的内存数据需要自行释放，并进行深拷贝：

```c++
Person p1 = 10;
Person p2 = 2;
p1 = p2;
```

<img src="F:\C++代码资料\Fig\37.png" style="zoom:67%;" />

<img src="F:\C++代码资料\Fig\38.png" style="zoom:50%;" />

```
如果将p2赋值给p1，需要先清空p2自身的内存。为了解决浅拷贝会重复删除堆区的内存提供深拷贝。最后返回自身this指针以便可以完成连等的操作
连等操作即三个对象连等赋值，如果不返回自身  *this  对象在进行第一个赋值操作后返回一个空值则无法进行第二个赋值操作
```

<img src="F:\C++代码资料\Fig\40.png" style="zoom:50%;" />

##### 仿函数

```c++
class MyAdd()
{
   public:
   int operator()(int num1,int num2)
   {
       return num1+num2;
   }
}
//仿函数非常灵活没有固定的写法
```

<img src="F:\C++代码资料\Fig\41.png" style="zoom:50%;" />

<img src="F:\C++代码资料\Fig\42.png" style="zoom:50%;" />

匿名函数对象使用完立即释放，第二个小括号相当于重载的函数对象

<img src="F:\C++代码资料\Fig\43.png" style="zoom: 80%;" />

##### 指针指向Class  Member Function

```c++
typedef void (num_sequence::*PtrType)(int); //给PtrType声明起别名，下面一行给PtrType起别名
PtrType pm = 0;
//PtrType是num_sequence类定义下的指针，指向num_sequence类的member function
//定义一个指针，指向member function中的fibonacci（）,我们这样写：
    PtrType pm = &num_sequence::fibonacci;
```

```c++
const int num_sequence::num_seq;
vector<vector<int> > num_sequence::seq(num_seq);
num_sequence::PtrType
    num_sequence::func_tbl[num_seq] = {
    0,
    &num_sequence::fibonacci,
    &num_sequence::seqare,
    ...
}
//我们分别将6个函数以数组元素形式放在数组中，使用6个vector，每个vector存储一个数组，PtrType指向存储数组元素的vector，_pfm则指向产生数组元素的member function
```

```c++
num_seqence ns;
PtrType pm = &num_seqence::fibonacci;
//注：(ns.*pm)(pos)与ns.fibonacci(pos);相同
```

### 面向对象编程风格

父类被称为基类，子类被称为派生类

面向对象编程的最主要的两项特质是继承和多态。

多态让我们得以用一种与类型无关的方式操作这些类对象。

**默认情况下，member function的解析在编译时静态进行，要令其在运行时动态进行，我们要在他的声明前面加上  关键字 virtual （虚函数）**

```c++
class libmat
{
    public:
    libmat(){ cout<<1<<endl;}
    virtual ~libmat{cout<<2<<endl;}
    virtual void print() const{cout<<3<<endl;}
}
```

```c++
void print(const libmat &mat)  //我们定义一个函数print
{
    cout<<4<<endl;
    mat.print();
}
```

将libmat的派生类Book的对象传入print中，跟踪结果的操作流程：

```c++
limat() ->constructor
Book() ->constructor
Book::print() 
~Book() ->deconstructor
~limat() ->deconstructor
```

实现派生Book类：

```c++
#include "libmat.h"
class Book : public libmat
//定义的派生类后面紧跟着public与基类名称，唯一规则是类进行继承声明之前，其基类的定义已经存在
 (也是先行必须包含有其基类定义的头文件)
{
    public:
    Book(){ ... }
    virtual ~Book{cout<<7<<endl;}
    virtual void print() const{cout<<8<<endl;}
   
    protected: //被声明为protected的所有成员都可以被其派生类直接访问，却不允许一般的程序访问
        string _title；
}
```

![](F:\C++代码资料\Fig\46.png)

<img src="F:\C++代码资料\Fig\47.png" style="zoom: 80%;" />

以公共方式继承来的基类的member，只有基类中的public属性在子类中表现为public。通过保护继承来的，基类中的public，protected属性在子类中表现为protected。通过私有继承来的，基类中的public，protected属性在子类中表现为private。通过这三种方式继承的派生类都不可访问基类中的私有属性

**保护属性**，protected member在类外不可访问。

（Base有三个int类型的属性，Son有一个int类型的属性）

<img src="F:\C++代码资料\Fig\48.png" style="zoom:50%;" />

![](F:\C++代码资料\Fig\49.png)

![](F:\C++代码资料\Fig\50.png)

父类中的私有属性也被继承下去了，只是被编译器隐藏了访问不到

![](F:\C++代码资料\Fig\51.png)

![](F:\C++代码资料\Fig\52.png)

<img src="F:\C++代码资料\Fig\53.png" style="zoom: 80%;" />

![](F:\C++代码资料\Fig\54.png)

**同名的静态成员属性的处理：**

<img src="F:\C++代码资料\Fig\55.png" style="zoom: 80%;" />

通过子类SON的类名方式访问在BASE作用域下的m_A属性.

![](F:\C++代码资料\Fig\56.png)

调用父类带参func（）：SON::BASE ::func(100);

**多继承**

![](F:\C++代码资料\Fig\58.png)

![](F:\C++代码资料\Fig\59.png)

**菱形继承**

![](F:\C++代码资料\Fig\60.png)



![](F:\C++代码资料\Fig\61.png)



<img src="F:\C++代码资料\Fig\62.png" style="zoom: 67%;" />

![](F:\C++代码资料\Fig\63.png)

原因：我们仅需要一份的m_Age就够了，但是继承了两份

使用虚继承可以仅得到一份

```c++
class sheep : virtual public Animal { };
class tuo : virtual public Animal { };
class sheeptuo : public sheep , public tuo{ };

void test01()
{
    Sheeptuo st;
    st.Sheep::m_age = 18;
    st.Tuo::m_age = 28; //在发生虚继承以后，程序运行到这里，不管Sheep::m_age还是Tuo::m_age都变为28，即发生虚继承后m_age这份数据变成了共享
}
```

![](F:\C++代码资料\Fig\64.png)

<img src="F:\C++代码资料\Fig\66.png" style="zoom:67%;" />

重写：函数的返回类型，函数名，参数列表 完全一致称为重写.

**多态：**

<img src="F:\C++代码资料\Fig\67.png" style="zoom:67%;" />

![](F:\C++代码资料\Fig\68.png)

Animal类没有加virtual之前，占据存储空间为1，加了virtual以后占据空间为4，是因为在animal类内形成了一个虚函数（表）指针指向虚函数表，虚函数表存在这个&Animal：：speak的函数入口地址。Cat类的内部结构如果覆盖了父类的虚函数，则右Cat的vfptr指向的虚函数表里存在的是&Cat：：speak这个函数入口地址。

**虚析构与纯虚析构**：

<img src="F:\C++代码资料\Fig\69.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig\70.png" style="zoom: 50%;" />

父类Animal的析构函数没有清理堆区属性，子类的析构函数有这个操作

<img src="F:\C++代码资料\Fig\71.png" style="zoom: 80%;" />

在函数外部再定义纯虚析构函数，就不需要加virtual关键字了

<img src="F:\C++代码资料\Fig\72.png" style="zoom: 50%;" />

虚析构与纯虚析构都是解决子类赋值给父类后，父类的析构无法调用子类的析构函数，从而导致无法清理子类的堆内存 导致内存泄漏的问题。

<img src="F:\C++代码资料\Fig\74.png" style="zoom: 67%;" />

<img src="F:\C++代码资料\Fig\75.png" style="zoom: 50%;" />

**不带继承的多态：**

```c++
class num_sequence
{
    public:
    ...
        enum ns_type{
        ns_unset,ns_fibonacci,ns_pell,ns_lucas,ns_triangular,ns_square,ns_pentagonal
    }
   //将六个数列名称放在一个名为ns_typ的枚举类型中
    private:
    PteType _pmf;
    ns_type _isa;
}
```

```c++
class num_sequence
{
   static ns_type nstype(int num)
   {
       return num<=0 || num >= num_seq ? ns_unset : static_cast<ns_type>(num);
       //static_cast是一个特殊转换记号，可以将num转换为对应的ns_type枚举项，在被我们传给       set_sequence
    }
}
ns.set_sequence(num_sequence::ns_type(ix)); //num_sequence调用ns_type(ix)
```

##### 定义一个抽象基类

**static member function无法被声明为虚函数**

<u>虚函数要么有定义，要么可设为纯虚函数。</u>

```c++
virtual void gen_elems(int pos) = 0 ;
```

任何类如果声明了一个<u>纯虚函数</u>，那么由于接口的不完整性，程序无法为它产生任何对象。

**根据一般规则，凡基类定义有一个（多个）虚函数，应该将其destructor声明为virtual。**

**例：**

```c++
num_sequence *ps = new Fabonacci(12);
//本例ps调用的一定是Fabonacci中的析构函数，而不是num_sequence中的，
//正确情况是“根据实际对象的类型选择调用哪个析构函数”，析构操作在运行时进行，我们必须将基类num_sequence 的destructor声明为virtual
但不建议直接将这个基类的析构函数设置为 = 0; ,对于这类析构函数最好提供空白定义
```

派生类从基类继承而来的每个纯虚函数提供对应的实现，还必须声明他们的专属member

```c++
class Fabonacci:public num_sequence
{
    public:
    Fabonacci(){}
        virtual int elem(int pos) const;
    
}

int Fabonacci:: elem(int pos) const
{ 
    if(pos>_elems.size())
    {
        Fabonacci::gen_elems();
   //由于是在Fabonacci类的函数里调用gen_elems();，所以十分明确，使用类解析符掩盖了虚函数机制
    }
    
    
    return elems[pos-1];


}
//elem派生类的虚函数在类外定义时，不用指明关键字visual
```

一般来说继承来的public与protected成员，可以看成是派生类自身拥有的成员。基类的private member无法让派生类使用。

当派生类有某个member function与基类中的重名时，便会掩盖住基类的那份member function，如果要在派生类使用继承来的member function（不是virtual），必须利用class scope运算符加以限定。目前可以令基类所有函数都为virtual。

```c++
ostream& operator<<(ostream &os , const num_sequence &ns)
{
    return ns.print(os);
}
//由于print是一个虚函数，在num_sequence的派生类里都有单独的定义，所以动态绑定返回ns.print(os);
```

```c++
class num_sequence
{
    public:
    ...
    protected:
    num_sequence(int len,int bp, vector<int>& re):_length(len),_beg_pos(bp),_relems(re){}
    int _length;
    int _beg_pos;
    vector<int>  &_relems;
   //定义一个指向vector<int>的引用类型，不定义指针类型的原因是 如果使用指针还要先判断指针是否为空指针
  //成员变量如果是引用类型，一定要先将这个引用类型初始化，一旦进行初始化，则无法指向任何对象
  //而指针我们可以先令他初始化为null，稍后再令它指向某个有效的地址
}
```

num_sequence作为一个抽象基类，不能产生任何对象，所以这个抽象基类的构造器定义为protected而不是public，把基类的性质交给派生类的子对象继承。

派生类的初始化，必须先调用基类的构造器，再调用派生类自己的构造器。

**一种做法是** ：**派生类的构造器**，**不仅**要为派生类提供初始化操作，**还要**为其基类提供初始化操作。

**另一种做法是** ： 让父类提供默认构造器，但这里，我们要让  _relems  改为指针，（因为要**先调用**基类构造器自身赋初值，**再调用**派生类构造器赋初值，而引用类型只能初始化一次），在每次访问vector内容前，都要先判断这个指针是否为null空指针。

例：

```c++
inline Fibonacci::
    Fibonacci(int len, int beg_pos):num_sequence(len,beg_pos,_elems)
{}
```



```c++
num_sequence::num_sequence(int len = 1,int bp = 1;vector<int>*pe = 0)
:_length(len),_beg_pos(bp),_pelems(pe)
```

将一个Fibonacci对象作为另一个Fibonacci对象的初值时：

```c++
Fibonacci fib1(10);
Fibonacci fib2 = fib1;
//如果Fibonacci定义了一个复制构造器，以上会调用复制构造器
Fibonacci::Fibonacci(const Fibonacci &rhs) : num_sequence(rhs)
{} //在成员初始化列表中传递给基类的复制构造器，如果基类未定义复制构造器，基类的默认成员初始化会起来执行
本例也不需要定义Fibonacci的Copy构造器，默认行为成员逐一初始化也能达到同样的效果
赋值运算符重载也同理不必另行定义，默认行为也可以达到同样效果。
    Copy构造器 与 赋值运算符重载 在涉及深拷贝时要另行定义
```

为派生类定义赋值运算符重载：

```c++
Fibonacci& Fibonacci:: operator= (const Fibonacci &rhs)
{
    if(this!=&rhs)
    {
        num_sequence:: operator= (rhs);
    }
    return *this;
}
```

**在派生类中定义一个虚函数：**

如果覆盖基类所提供的虚函数，派生类提供的定义函数的原型必须完全符合基类声明的函数原型。

“返回类型必须完全吻合”这一规则有一个例外----当基类的虚函数返回某个基类形式时：

```c++
class num_sequence
{
    public:
    virtual num_sequence * clone() = 0;
}

class Fibonacci:public num_sequence
{
    public:
        Fibonacci * clone(){Fibonacci: new Fibonacci(*this);}
}

```

**基类的静态解析：**

虚函数机制不会出现预期行为的两种情况：

1.基类的构造函数与析构函数内。

2.但我们使用的是基类的对象，而非基类对象的引用与指针时。

在基类的构造器中，派生类的虚函数不会被调用。

<img src="F:\C++代码资料\Fig\44.png" style="zoom:67%;" />

```c++
void print(Libmat object,const Libmat *pointer,const Libmat &reference)
{
    object.print();
    pointer->print();
    reference.print();
}
```

我们为基类声明一个实际对象，分配出了容纳这个实际对象的内存空间，稍后传入的如果是一个派生类对象，没有足够的内存防止派生类各个data member。

```c++
int main()
{
    AudioBook iwish("jack Irons");
    print(iwish,&iwish,iwish);
}
//只有iWish中的“基类子对象”被复制到"为参数object保留的内存中"，而其他的（Book与AudioBook的成分）被切掉了，另外两个参数（*pointer，与 &reference）则被初始化为iwish所在的内存地址，这是他们能够指向完整 AudioBook 对象的原因。
```

### IO流

#### 标准输入流

<img src="F:\C++代码资料\语法分享\154.png" style="zoom:50%;" />

<img src="F:\C++代码资料\语法分享\156.png" style="zoom: 67%;" />

<img src="F:\C++代码资料\语法分享\157.png" style="zoom:50%;" />

<img src="F:\C++代码资料\语法分享\158.png" style="zoom: 50%;" />

```c++
int main()
{
    //输入as
    char c = cin.get();  //a
    cout<<c<<endl;
     char c = cin.get(); //s
    cout<<c<<endl;
     char c = cin.get(); //换行
    cout<<c<<endl;
     char c = cin.get();  //阻塞
    cout<<c<<endl;
    char c1 = '0';
    cin.get(c1);   //c1依然可以获取
    cout<<c1<<endl;
    char ch1,ch2,ch3.ch4;
    cin.get(ch1).get(ch2).get(ch3).get(ch4);
    cout<<ch1<<ch2<<ch3<<ch4<<endl;
}
```

```c++
void test02()
{
    char buf[1024] = {0};
    cin.get(buf,1024);  //读取缓冲区，换行不拿走
    cout<<buf<<endl;
}
```

```c++
char c = cin.getline();  //按行读取缓冲区，换行拿走
cin.ignore(3);  //参数N表忽略N个字符，无参数表忽略一个字符
char c = cin.peek();  //偷窥用户输入的第一个数字
cin.clear();  //重置标志位
cin.sync();  //清空缓冲区

char c2 = cin.get();  //输入hello
cout<<c<<endl;
cin.put_back(c);  //放回
char buf[1024] = {0};
cin.getline(buf,1024);  //放回后读出的仍然是hello，不防放回读出llo
cout<<buf<<endl;
```

#### 标准输出流

<img src="F:\C++代码资料\语法分享\159.png" style="zoom: 67%;" />

<img src="F:\C++代码资料\语法分享\160.png" style="zoom:50%;" />

<img src="F:\C++代码资料\语法分享\161.png" style="zoom: 67%;" />

<img src="F:\C++代码资料\语法分享\162.png" style="zoom:50%;" />

<img src="F:\C++代码资料\语法分享\163.png" style="zoom:50%;" />

#### 读写文件

<img src="F:\C++代码资料\Fig\76.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig\77.png" style="zoom:80%;" />

<img src="F:\C++代码资料\Fig\78.png" style="zoom:67%;" />

<img src="F:\C++代码资料\Fig\79.png" style="zoom: 50%;" />

```c++
#include <fstream>
ifstream ifs;
ifs.open("123.txt",ios::in);
if(!ifs.is_open())
{
    cout<<"文件打开失败"<<endl;
    return;  //如果文件打开失败，直接return返回
}
//读数据
第一种：
char[1024] buf = {0};
while(ifs>>buf)
{
    cout<<buf<<endl;
}
第二种：
 char[1024] buf = {0};
while(ifs.getline(char,sizeof(buf))
{
    cout<<buf<<endl;
}
ifs.close();      
      
```

<img src="F:\C++代码资料\Fig\80.png" style="zoom: 67%;" />

```c++
...
#include <fstream>    
class Person
{
    public:
    char m_name[1024];
    int m_age;
}
void test()
{
    ofstream ofs("Person.txt", ios::out|ios::binary);
    Person p = {"jack",18};
    ofs.write((const char*)&p,sizeof(Person));
}
ofs.close();
```

<img src="F:\C++代码资料\Fig\81.png" style="zoom: 67%;" />

<img src="F:\C++代码资料\Fig\82.png" style="zoom: 67%;" />

```c++
#include <fstream>
ifstream ifs("Person.txt", ios::in|ios::binary);
ifs.read((const char*)(&p),sizeof(Person));
cout<<"年龄："<<p.m_age<<"名字："<<p.m_name<<endl;
ifs.close();
```

### 模板

1、函数和类是通用的，里面的数据类型有多种的状态

2、模板有 函数 和 类

#### **使用函数模板**

```c++
template<class T>
void swap(T& a,T& b)       //第一次编译
{
    T temp = a;
    a = b;
    b = temp;
}
void test02()
{
    int a=1;
    int b=2;
    swap(a,b);  //编译器进行第二次编译
    /*
    void swap(int& a,int& b)       //第二次编译，将虚拟数据类型转化为实际调用的数据类型
{      
    int temp = a;
    a = b;
    b = temp;
}
    */
    swap<int>(a,b);  //显示的指定类型，告诉编译器就传int类
}
```

隐式转换：

```c++
template<class T>
//也可以写成 template<typename T>
T func(T a,T b)       //第一次编译
{
    T temp = a+b;
    return temp;
}
void test03()
{
    int a = 10;
    double b = 10.2;
    //如果参数列表显式声明，实参可以进行隐式转换
    //如果转换成功调用，转换不成功，报错
    count<<func<int>(a,b)<<endl;  //实参可传入double，int，传入“”则报错
}
```

隐式转换报错的情况：

```c++
template<class T>
//也可以写成 template<typename T>
T func(T& a,T& b)       //第一次编译
{
    T temp = a;
    a = b;
    b = temp;
}
void test03()
{
    int a = 10;
    double b = 10.2;
    count<<func<int>(a,b)<<endl;  //在这里会报错，引用类型无法进行隐式转换
}
```

普通函数可以进行隐式类型转换

普通定义的函数模板无法进行隐式类型转换

显示声明的函数模板可进行隐式类型转换

**普通函数与函数模板的调用规则**

<img src="F:\C++代码资料\语法分享\133.png" style="zoom:67%;" />

#### 类模板

<img src="F:\C++代码资料\语法分享\134.png" style="zoom:67%;" />

**类模板的默认类型**

```c++
template<class NameType,class AgeType=int>  //类模板的默认类型
class Maker2
{
    public:
       Maker(NameType name,AgeType age)
       {
           this->name = name;
           this->age = age;
       }
    public:
        NameType name;
        AgeType age;
};

void test()
{
    //如果<>里有默认类型，可以少写默认类型
    Maker2<string> m("jack",2);
    //以传入的类型为主
    Maker2<string,double> m("jack",2.22);
}
```

注意：默认类型后面的泛型类型也必须有默认类型

**复数的加减运算**

```c++
template<class T>  
class Maker2
{
    public:
       Maker2(T r,T i)
       {
           a = r;
           b = i;
       }
       Maker2 operator+(T& c)
       {
           Maker2 tmp(this->a+c.a,this->b+c.b);
           return tmp;
       }
    private:
        T a;
        T b;
};
```

**类模板作为函数参数：**

1.指定传入的数据类型

```c++
void func(Maker<string,int>&m)
{
    m.printerMaker();
}
```

2.参数模板化

```c++
template<class T1,class T2>
void func(Maker<T1,T2>&m)
{
    m.printerMaker();   //二次编译在此时，在调用的时候进行二次编译
}
```

3.整个类模板化

```c++
template<class T>
void func(T& m)
{
    m.printerMaker();
}
```

**模板的继承**

```c++
template<class T>
class Father
{
    public:
    Father()
    {
        m=20;
    }
    private:
       T m;
}
//普通类继承类模板：
  class Son : public Father<int>   //要告诉编译器父类的泛型数据具体类型是什么
  {
      public:
      
  }
//类模板继承类模板
  template<class T1,class T2>
  class Son2 : public Father<T2>
  {
      
  }
void test()
{
    Son2(int,string) s;   ////类模板继承类模板，要告诉编译器父类泛型数据具体类型是什么
}
```

**类模板的类外实现**

要写成函数模板

```c++
template<class NameType,class AgeType>  
class Maker2
{
    public:
       Maker(NameType name,AgeType age);
     
    public:
        NameType name;
        AgeType age;
};

void test()
{
    
    Maker2<string> m("jack",2);

    Maker2<string,double> m("jack",2.22);
}

Maker<class NameType,class AgeType>::Maker(NameType name,AgeType age)
{
    
}
  template<class NameType,class AgeType>  
  void Maker<class NameType,class AgeType>::printMaker()
  {
      
  }
    
```

**类模板分文件**

<img src="F:\C++代码资料\语法分享\134.png" style="zoom: 67%;" />

把具体类外实现的模板的cpp文件放在 .h文件中

![](F:\C++代码资料\语法分享\135.png)

#### 类模板与友元

1.友元的类内实现：

```c++
template<class NameType,class AgeType>  
class Maker2
{
    friend void printMaker(Maker<class NameType,class AgeType>& m)
    {
        cout<<p.name<<p.age<<endl;
    }
    public:
       Maker(NameType name,AgeType age)
       {
           this->name = name;
           this->age = age;
       }
    public:
        NameType name;
        AgeType age;
};

void test()
{
   
    Maker2<string> m("jack",2);
    printMaker(m);     //友元类内实现
}
```

2.友元的类外实现

```c++
template<class NameType,class AgeType>
class Maker2;

template<class NameType,class AgeType>
void printMaker(Maker<class NameType,class AgeType>& m);
//声明了友元的函数模板，还要继续往上声明参数中的模板类
template<class NameType,class AgeType>  
class Maker2
{
    //1.在函数和括号之间加上<>
    friend void printMaker<>(<class NameType,class AgeType>& m);
    //此时友元函数声明在类内，他必须要知道是否有printMaker函数实体，要在前面先声明函数模板
    public:
       Maker(NameType name,AgeType age)
       {
           this->name = name;
           this->age = age;
       }
    public:
        NameType name;
        AgeType age;
};

template<class NameType,class AgeType>   //友元在类外要写成函数模板
void printMaker(Maker<class NameType,class AgeType>& m)
    {
        cout<<p.name<<p.age<<endl;
    }

void test()
{
    Maker2<string> m("jack",2);
    printMaker(m);     //友元类外实现
}
```

**模板数组：**

```c++
#pragma once
template<class T>
class MyArr
{
public:
	MyArr() 
	{
	}
	MyArr(int capcity) 
	{
		this->mCapcity = capcity;
		this->mSize = 0;
		this->p = new T[capcity];
	};
	//拷贝构造
	MyArr(const MyArr& m) 
	{
		if (this->p!=nullptr)
		{
			delete[]this->p;
			this->p = nullptr;
		}
		this->mCapcity = m.mCapcity;
		this->mSize = m.mSize;
		this->p = new T[m.mCapcity];
		for (size_t i = 0; i < this->mSize; i++)
		{
			p[i] = m.p[i];
		}
		return *this;
	}
	//重载
	T& operator[](int index)
	{
		return this->p[index];
	}
	//尾插
	void push_back(const T& val) 
	{
		if (this->mSize = this->mCapcity)
		{
			return;
		}
		this->p[this->mSize] = val;
		this->mSize++;
	}

	~MyArr() 
	{
		if (this->mCapcity!=NULL)
		{
			delete[]p;
			p = nullptr;
		}
	}
	int getsize()
	{
		return this->mSize;
	}

private:
	T* p;
	int mSize;
	int mCapcity;
};
```

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "MyArr.hpp"
#include<string>
class Maker 
{
public:
	Maker() {}
	Maker(string name,int age) 
	{
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;
};

void test() 
{
	MyArr<Maker> myarr(4);
	Maker m1("jack",18);
    Maker m2("jac",1);
    Maker m3("ja",181);
    Maker m4("j",1811);
	myarr.push_back(m1);
    myarr.push_back(m2);
    myarr.push_back(m3);
    myarr.push_back(m4);
}
```

### c++的类型转换

<img src="F:\C++代码资料\语法分享\136.png" style="zoom: 67%;" />

#### 1.静态转换

**static_cast**

```c++
1.基础类型转换
  void test01()
{
    char a = 'a';
    double d = static_cast<double>(a);
}  
2.有类的指针或引用的转换
class Father
{
  
};
class Son : public Father
{
     
};
Father *f = NULL;
SON *s = NULL;
//向下转，不安全
SON *s = static_cast<Father*>(f);
//向上转安全
Father *f = static_cast<Son*>(s);
//没有继承的类之间指针不能转换
3.引用转换
  Father f;
  Son s;
  Father& ref_f = f;
  Son& ref_s = s;
  //向上转安全
  static_cast<Father&>(ref_s);
  //向下转，不安全
  static_cast<SON&>(ref_f);
```

####  2.动态转换

**dynamic_cast**

基础类型不能使用动态转换

```c++
//向上转安全
Father *f = NULL;
SON *s = NULL;
Father *f = dynamic_cast<Son*>(s);
//向下转，不安全,**dynamic_cast**会进行检查
//SON *s = dynamic_cast<Father*>(f);
//发生多态时，向下转换，动态转换就可以
class Father2
{
    public:
    virtual void func(){}
}; 
class SON2:public Father2
{
    public:
    virtual void func(){}
}
void test()
{
    Father *f = new SON;
    dynamic_cast<SON2*>(f); //发生多态时，向下转换，动态转换就可以
}
```

#### 3.常量转换

**const_cast**

<img src="F:\C++代码资料\语法分享\138.png" style="zoom: 80%;" />

不能对非指针，非引用使用的变量const_cast去除他的const

<img src="F:\C++代码资料\语法分享\139.png" style="zoom: 67%;" />

#### **4.重新解释转换**

**reinterpret_cast**

<img src="F:\C++代码资料\语法分享\140.png" style="zoom: 67%;" />

```c++
void test()
{
    int a = 10;
    int* p = reinterpret_cast<int*>(a);
    Father* f = NULL;
    Other* o = reinterpret_cast<other*>(f);
}
```

### 异常

<img src="F:\C++代码资料\语法分享\142.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\语法分享\143.png" style="zoom:67%;" />

<img src="F:\C++代码资料\语法分享\144.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\语法分享\147.png" style="zoom: 67%;" />

<img src="F:\C++代码资料\语法分享\145.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\语法分享\148.png" style="zoom: 67%;" />

<img src="F:\C++代码资料\语法分享\149.png" style="zoom: 67%;" />

#### **严格的类型匹配：**

不能存在类型转换问题

<img src="F:\C++代码资料\语法分享\151.png" style="zoom: 50%;" />

#### 栈解旋

在抛出异常的函数中，抛出异常后，但函数没有结束，这时栈上申请的对象都会被释放，这就叫栈解旋

<img src="F:\C++代码资料\语法分享\152.png" style="zoom: 67%;" />

```c++
class Maker
{
    Maker()
    {
        cout<<"构造"<<endl;
    }
    Maker(Maker& m)
    {
        cout<<"Maker是拷贝构造函数"<<endl;
    }
    ~Maker()
    {
        cout<<"析构"<<endl;
    }
};
void func()
{
    Maker m ;
    throw m;  //这个m是Maker m拷贝一份的
    cout<<"函数已结束"<<endl;
}
void test()
{
    try
    {
        func();
    }
    catch(Maker)
    {
        cout<<"接收到一个Maker的异常类型"<<endl;
    }
}
int main()
{
   test();
   system("pause");
   return;
}
```

#### 异常的生命周期

**产生三个对象情况：**

```c++
class Maker
{
    Maker()
    {
        cout<<"构造"<<endl;
    }
    Maker(Maker& m)
    {
        cout<<"Maker是拷贝构造函数"<<endl;
    }
    ~Maker()
    {
        cout<<"析构"<<endl;
    }
};
void func()
{
    //产生了三个对象
    Maker m ; //第一个对象是在异常接收之前被释放的
    throw m;  //产生第二个对象，是第一个对象拷贝过来的
    cout<<"函数已结束"<<endl;
}
void test()
{
    try
    {
        func();
    }
    catch(Maker) //第三个对象是第二个对象拷贝过来的
    {
        cout<<"接收到一个Maker的异常类型"<<endl;
        //第二，三个对象在catch结束生命周期
    }
}
int main()
{
   test();
   system("pause");
   return;
}
```

**产生两个对象情况：**

```c++
class Maker
{
    Maker()
    {
        cout<<"构造"<<endl;
    }
    Maker(Maker& m)
    {
        cout<<"Maker是拷贝构造函数"<<endl;
    }
    ~Maker()
    {
        cout<<"析构"<<endl;
    }
};
void func()
{
    //产生了两个对象
    throw Maker();  //产生第1个对象，匿名对象
    cout<<"函数已结束"<<endl;
}
void test()
{
    try
    {
        func();
    }
    catch(Maker) //第二个对象
    {
        cout<<"接收到一个Maker的异常类型"<<endl;
        //第一，二个对象在catch结束生命周期
    }
}
int main()
{
   test();
   system("pause");
   return;
}
```

**产生一个对象情况：**

```c++
void func()
{
    //产生了1个对象
    throw Maker();  //产生1个对象，匿名对象
    cout<<"函数已结束"<<endl;
}

void test()
{
    try
    {
        func();
    }
    catch(Maker& m1) 
    {
        cout<<"接收到一个Maker的异常类型"<<endl;
    }
 //引用能够被栈区的匿名对象赋值   
}
```

**注意：**

```c++
void func()
{
    //编译器不允许对栈区的匿名对象进行取地址操作，catch处用指针的时候用指针注意要抛出在堆区创建的匿名对象
    //throw Maker();  
    throw new Maker();
    //编译器允许对堆区的匿名对象进行取地址操作
    cout<<"函数已结束"<<endl;
}

void test()
{
    try
    {
        func();
    }
    catch(Maker* m1) 
    {
        cout<<"接收到一个Maker的异常类型"<<endl;
        delete m1;
    }
}
```

#### 异常的多态

```c++
class Father
{
    public:
    virtual void printM()
    {
      
    }
}
class SonNull:public Father
{
    public:
    virtual void printM()
    {
        cout<<"空指针异常"<<endl;
    }
}
class SonOut:public Father
{
    public:
     virtual void printM()
    {
        cout<<"越位溢出"<<endl;
    }
}
void func(int a, int b)
{
    if(a==0)
    {
      throw SonNull();    
    }
    if(b==0)
    {
       throw SonOut(); 
    }
    
}
void test()
{
    try
    {
       func();
    }
    catch(Father& f)
    {
        f.printM();
    }
}
```

#### 系统的标准异常类

```c++
#include <stdexcept>
#include <string>
class MyOut_of:public exception
{
    public:
    MyOut_of(const char* errorinfo)
    {
         this->m_Info = string(errorinfo);
    }
    MyOut_of(const string errorinfo)
    {
         this->m_Info = errorinfo;
    }
    public:
    string m_Info;
    const char* what() const
    {
        return m_Info.c_str(); //把string转换成char*
    }
};
class Maker
{
  public:
    Maker(int age)
    {
        if(age<0||age>150)
        {
            throw MyOut_of("自己的异常类，年龄不在范围内");
        }
        else
        {
           this->m_age = age;
        }
    }
    public:
    int m_age;
};
void test()
{
    try
    {
       Maker m(200);    
    }
    catch(MyOut_of& ex)
    {
        ex.what();
    }
}
```

