## STL标准库

#### STL六大部件

<img src="F:\C++代码资料\Fig-STL\2.png" style="zoom: 33%;" />

allocator<int>是vector内默认的空间分配器

<img src="F:\C++代码资料\Fig-STL\1.png" style="zoom: 50%;" />

```
容器的c.begin()y与c.end()属于 左闭右开区间
```

```c++
srd::vector<double> vec;
  for(auto elem:vec)
  {
      cout<<elem<<endl;
  }  
for(auto& elem:vec)
  {
      std::cout<<elem*3<<endl;
  }  
```

```c++
list<string> c;
list<string> :: iterator ite;
ite = find(c.begin(),c.end(),target);
list<string> c;
auto ite = find(c.begin(),c.end(),target);
```

#### STL容器分类

所有容器分为顺序式容器，与关联式容器两大类。

List是一个双向链表。

<img src="F:\C++代码资料\Fig-STL\3.png" style="zoom:50%;" />

**HashTable**使用了链地址法处理冲突。

**vector**每次扩充的容量都是以二倍扩充的，空间利用率相对低。

**list**每次只扩充一个结点，空间利用率相对较高，但查找起来较慢。

**dueque**每次扩充一个buffer大小的内存。

单向链表-**forward_list**只有push_front(),  **slist**与forward_list用法都相同，forward_list是c++11标准规定的

<img src="F:\C++代码资料\Fig-STL\4.png" style="zoom:50%;" />

如果容器内又自己封装的sort(),就用自己封装的sort()，如果没有就用全局的 ::sort

**dueque**

dueque是分段连续的

<img src="F:\C++代码资料\Fig-STL\5.png" style="zoom: 33%;" />

**stack** （容器适配器）

<img src="F:\C++代码资料\Fig-STL\6.png" style="zoom:50%;" />

**queue** （容器适配器）

<img src="F:\C++代码资料\Fig-STL\7.png" style="zoom: 50%;" />

deque包含stack与queue

**multiset** （可重复的set）

key就是value，value就是key。元素存入的时候自动排序，查找时间很短。

**multimap** （key是可重复的）

```c++
multimap<long,string> c;
c.insert(pair<long,string>(i,buf));
auto ptem = c.find(target);
cout<<*(ptem)<<endl;
```

**unordered_multiset**

<img src="F:\C++代码资料\Fig-STL\9.png" style="zoom: 33%;" />

#### 分配器

<img src="F:\C++代码资料\Fig-STL\10.png" style="zoom: 33%;" />

一般都是使用容器搭配分配器使用，一般没有将分配器单独使用情况

面向对象编程将data与method关联在一起。

Gp编程将data与method分开

<img src="F:\C++代码资料\Fig-STL\11.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\12.png" style="zoom:50%;" />

标准库算法所应用的迭代器是可以应用到连续空间，可以进行+1，+3这样进行跳转的条件，但链表非连续空间不能满足这个条件

 <img src="F:\C++代码资料\Fig-STL\13.png" style="zoom: 33%;" />

#### 模板

<img src="F:\C++代码资料\Fig-STL\14.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\15.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\16.png" style="zoom: 33%;" />

这里的foo对应泛化的版本，下面两个是特化的模板。（全特化）

**偏特化：**

<img src="F:\C++代码资料\Fig-STL\17.png" style="zoom:50%;" />

#### 分配器

<img src="F:\C++代码资料\Fig-STL\19.png" style="zoom:50%;" />

不提倡直接使用allocate分配器分配内存

<img src="F:\C++代码资料\Fig-STL\18.png" style="zoom: 33%;" />

**BC5与GCC**所附带的分配器与VC6相同，其底层最后都是由malloc（）与free（）去分配内存，由于malloc（）会带有overhead的额外开销，分配的内存小开销会比较大，分配的内存大，开销会较小。allocate第二个参数有默认值为0.

<img src="F:\C++代码资料\Fig-STL\20.png" style="zoom: 33%;" />

**GC2.9**中的alloc实现，其为16个结点分别挂载着链表，第一个结点挂载8个字节，第二个则管理16个字节空间，往后的结点依次挂载加8字节。如果给vec分配50个字节空间，则自动补成8的倍数是56，之后查找能挂载56个字节空间的结点，找到后如果没有挂载内存空间则再向操作系统申请。

**GC4.9**又改回最初的malloc的BC5的设计

#### 容器之间的实现与分类

<img src="F:\C++代码资料\Fig-STL\21.png" style="zoom:50%;" />

#### list

<img src="F:\C++代码资料\Fig-STL\25.png" style="zoom: 33%;" />

list最后一个结点之后指向的是一个虚拟的结点

<img src="F:\C++代码资料\Fig-STL\26.png" style="zoom: 33%;" />

<img src="F:\C++代码资料\Fig-STL\27.png" style="zoom: 33%;" />

<img src="F:\C++代码资料\Fig-STL\28.png" style="zoom:33%;" />

指针是退化的迭代器，迭代器是泛化的指针.

<img src="F:\C++代码资料\Fig-STL\29.png" style="zoom: 33%;" />

<img src="F:\C++代码资料\Fig-STL\30.png" style="zoom: 33%;" />

<img src="F:\C++代码资料\Fig-STL\31.png" style="zoom: 50%;" />

#### vector

<img src="F:\C++代码资料\Fig-STL\32.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\33.png" style="zoom: 50%;" />

GC2.9的vector：

<img src="F:\C++代码资料\Fig-STL\34.png" style="zoom:33%;" />

由于vetor的iterator是直接由指针构成的，不是一个单独的类，所以vector的iterator会传入萃取机中偏特化的红框中的版本 iterator_traits<T*>

GC4.9的vector：

<img src="F:\C++代码资料\Fig-STL\36.png" style="zoom: 50%;" />

#### array

array的迭代器放入萃取机中会特化到指typename是指针的traits

<img src="F:\C++代码资料\Fig-STL\38.png" style="zoom: 33%;" />



#### deque

<img src="F:\C++代码资料\Fig-STL\39.png" style="zoom: 50%;" />

当最后一个buffer用光时，扩充就需要新分配一个缓冲区并串接到map中最后一个结点的后面进行扩充

<img src="F:\C++代码资料\Fig-STL\40.png" style="zoom: 50%;" />

map挂载8个缓冲区，每次扩容一倍则每次扩展8个缓冲区，可进行增长

map_pointer是一个二级指针

**deque的迭代器：**

<img src="F:\C++代码资料\Fig-STL\41.png" style="zoom: 67%;" />

iterator_category迭代器制造出deque是分段“连续”的假象

<img src="F:\C++代码资料\Fig-STL\42.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\43.png" style="zoom: 33%;" />

<img src="F:\C++代码资料\Fig-STL\44.png" style="zoom:33%;" />

deque iterators的+=运算先判断+=后是否位于正确的缓冲区，不位于则切换至正确缓冲区并更新正确的元素

扩充缓冲区时，扩充到二倍后，会将元素copy移到两个buffer的中段，这样方便向左向右等量的扩充缓冲区

#### queue

<img src="F:\C++代码资料\Fig-STL\45.png" style="zoom: 50%;" />

queue与stack底层都使用deque作为底层容器调用这个容器的操作.

stack与queue都不允许遍历，同时也不提供迭代器.使用迭代器就失去了stack与queue的特性了

stack与queue都可以选择list与deque作为底层容器

<img src="F:\C++代码资料\Fig-STL\46.png" style="zoom: 50%;" />

stack与queue都不可选用set或map作为底层结构

#### 红黑树

<img src="F:\C++代码资料\Fig-STL\47.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\48.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\49.png" style="zoom: 33%;" />

<img src="F:\C++代码资料\Fig-STL\50.png" style="zoom: 33%;" />

#### 容器set与multiset

<img src="F:\C++代码资料\Fig-STL\51.png" style="zoom:50%;" />

<img src="F:\C++代码资料\Fig-STL\52.png" style="zoom: 50%;" />

set有一定的排列次序，不可以用迭代器取更改set值，所以使用 const iterator

multiset允许存放重复的value

#### map与multimap

<img src="F:\C++代码资料\Fig-STL\53.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\54.png" style="zoom: 50%;" />

multimap<long,string> c;

c.insert(pair<long,string>(i,buf));

multimap不可使用【】做insert.

map的【】如果找到中括号中key所对应data，则传回来，如果找不到，则将key与对应data插入

<img src="F:\C++代码资料\Fig-STL\55.png" style="zoom: 50%;" />

中括号里封装insert

#### 散列表hashtable

<img src="F:\C++代码资料\Fig-STL\56.png" style="zoom:33%;" />

<img src="F:\C++代码资料\Fig-STL\57.png" style="zoom: 50%;" />

![](F:\C++代码资料\Fig-STL\58.png)

<img src="F:\C++代码资料\Fig-STL\59.png" style="zoom: 50%;" />

计算hashcode的hash function里的参数 const char*传入偏特化版本：

<img src="F:\C++代码资料\Fig-STL\60.png" style="zoom: 33%;" />

#### unordered容器

<img src="F:\C++代码资料\Fig-STL\61.png" style="zoom:33%;" />

无序容器，用法和之前的容器相同 ，c++11出现的容器。

将0-32767变化范围的100万个元素放入到unordered_set中，map中buket的个数一定会大于元素种类的个数，所以set的size会自动扩容到62233的大小，如果是multi_set的size大小一定是200万因为允许重复的元素出现

#### 算法

<img src="F:\C++代码资料\Fig-STL\62.png" style="zoom: 33%;" />

#### 迭代器

<img src="F:\C++代码资料\Fig-STL\63.png" style="zoom: 50%;" />

五种迭代器之间的分类是通过struct的继承方式的

<img src="F:\C++代码资料\Fig-STL\64.png" style="zoom: 33%;" />

<img src="F:\C++代码资料\Fig-STL\66.png" style="zoom:33%;" />

<img src="F:\C++代码资料\Fig-STL\67.png" style="zoom: 33%;" />

<img src="F:\C++代码资料\Fig-STL\68.png" style="zoom: 50%;" />

typetraits属于标准库的一部分，不属于STL的一部分，可用于判断例如 复数的type就不重要不需要拷贝赋值函数，而其他的type重要就需要拷贝赋值

<img src="F:\C++代码资料\Fig-STL\69.png" style="zoom: 67%;" />

<img src="F:\C++代码资料\Fig-STL\70.png" style="zoom: 33%;" />

#### 内存管理

<img src="F:\C++代码资料\Fig-STL\71.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\72.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\73.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\74.png" style="zoom:50%;" />

<img src="F:\C++代码资料\Fig-STL\75.png" style="zoom: 67%;" />

<img src="F:\C++代码资料\Fig-STL\76.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\77.png" style="zoom:33%;" />

<img src="F:\C++代码资料\Fig-STL\80.png" style="zoom:50%;" />

<img src="F:\C++代码资料\Fig-STL\81.png" style="zoom: 50%;" />

Complex类型如果delete没有加[],也会回收掉整体的内存，加了中括号只是会析构三次，不加析构一次，由于cookie记录的长度没有随之改变，所以delete不会有内存泄漏。

string如果不加中括号结点之前的部分会被顺利清掉，结点指针指向的部分只会清除掉一个，会发生内存泄漏。

<img src="F:\C++代码资料\Fig-STL\82.png" style="zoom:33%;" />

析构三次与构造函数三次是相反的.

<img src="F:\C++代码资料\Fig-STL\83.png" style="zoom:50%;" />

<img src="F:\C++代码资料\Fig-STL\84.png" style="zoom: 33%;" />

<img src="F:\C++代码资料\Fig-STL\85.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\86.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\87.png" style="zoom:33%;" />

<img src="F:\C++代码资料\Fig-STL\88.png" style="zoom:33%;" />

Array的operator new 全局的operator new 普通的operator new都可以重载

<img src="F:\C++代码资料\Fig-STL\91.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-STL\92.png" style="zoom:50%;" />

<img src="F:\C++代码资料\Fig-STL\93.png" style="zoom:50%;" />

构造函数接收到int后抛出异常：

<img src="F:\C++代码资料\Fig-STL\94.png" style="zoom:50%;" />

是由于防止 new出来的对象的空间，但是对像有没有完全构建好就会抛出异常

<img src="F:\C++代码资料\Fig-STL\95.png" style="zoom:50%;" />
