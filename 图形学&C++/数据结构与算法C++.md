## 数据结构与算法

#### 时间复杂度

<img src="F:\C++代码资料\Fig-DS\4.png" style="zoom: 50%;" />

### 各种排序法：

##### 选择排序：时间复杂度O（n^2）,额外空间复杂度O（1）.

空间复杂度不涉及与之前存储的容器开辟同样为n的空间为O(1)

```c++
#include<iostream>
using namespace std;

void sel(int *arr,int len) //将指针作为参数传入
{
	if (len == 0||len==1)
	{
		return;
	}
	for (int i = 0; i < len-1; i++) //选择排序外层循环的最后一趟到最后一个元素之前的一个元素
	{
		int minIndex = i;       //作为记录当前最小值的可移动的索引
		for (int j = i+1;j<len;j++) 
		{
			minIndex = arr[minIndex] >= arr[j] ? minIndex : j;
		}
		swap(arr[minIndex], arr[i]);    //传入的arr都是数组元素的引用
	}

}
void swap( int& i, int& j) 
{
	int temp = j;
	j = i;
	i = temp;
}

int main() 
{
	int arr[] = {6,2,1,5,9,8};

	sel(arr,6);

	return 0;
}
```

##### 冒泡排序：时间复杂度O（n^2）,额外空间复杂度O（1）.

```c++
#include<iostream>
using namespace std;

void sel(int *arr,int len) 
{
	if (len == 0||len==1)
	{
		return;
	}
	for (int e = len-1; e>0; e--) 
	{
		for (int j = 0;j<e;j++) 
		{
			if (arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
		
	}

}
void swap( int& i, int& j) 
{
	int temp = j;
	j = i;
	i = temp;
}

int main() 
{
	int arr[] = {6,2,1,5,9,8};

	sel(arr,6);

	return 0;
}
```

##### 插入排序：

```c++
#include<iostream>
using namespace std;

void sel(int* arr, int len)
{
	if (len == 0 || len == 1)
	{
		return;
	}
	for (int i = 1;i<len;i++)
	{
		for (int j = i-1;j>=0&&arr[j]>arr[j+1]; j--)
		{
			swap(arr[j],arr[j+1]);
        }

	}

}
void swap(int& i, int& j)
{
	int temp = j;
	j = i;
	i = temp;
}

int main()
{
	int arr[] = { 6,2,1,5,9,8 };

	sel(arr, 6);

	return 0;
}
```

**二分：**

<img src="F:\C++代码资料\Fig-DS\5.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-DS\6.png" style="zoom: 33%;" />

<img src="F:\C++代码资料\Fig-DS\7.png" style="zoom: 33%;" />

求一组数的局部最小值也可以用二分法（无序）（二分到结束，不断求两边区间or中间局部最小值）

**根据  1.数据特殊状况  可采取优化**

​          **2.问题特殊情况**

<img src="F:\C++代码资料\Fig-DS\8.png" style="zoom:50%;" />

##### 用递归二分法求最大值：

```c++
#include <iostream>
#include <algorithm>
using namespace std;

int process(int* arr, int L, int R); //调用下面的process函数需要在前面先进行声明
int getmax(int* p, int len) 
{
	return process( p,0,len - 1);
	
}
int process(int *arr,int L,int R) 
{
	if (L == R) 
	{
		return *(arr+L);
	}
	int mid = L + ((R - L) >> 1);
	int leftmax = process(arr,L,mid);
	int rightmax = process(arr, mid+1, R);
	return max(leftmax, rightmax);
}

int main() 
{
	int arr[6] = {6,2,1,5,9,8};
	int Max = getmax(arr,6);
	cout << Max << endl;
	return 0;
}
```

##### Master公式：

<img src="F:\C++代码资料\Fig-DS\9.png" style="zoom:67%;" />

<img src="F:\C++代码资料\Fig-DS\10.png" style="zoom:50%;" />

<img src="F:\C++代码资料\Fig-DS\11.png" style="zoom:50%;" />

##### 归并排序：

<img src="F:\C++代码资料\Fig-DS\12.png" style="zoom: 67%;" />



<img src="F:\C++代码资料\Fig-DS\13.png" style="zoom: 50%;" />

**归并排序：**

```c++
#include <iostream>
#include <algorithm>
using namespace std;


void emerage(int* p, int L, int M, int R);
void process(int *arr,int L,int R) 
{
	if (L == R) 
	{
		return ;
	}
	int mid = L + ((R - L) >> 1);
	process(arr,L,mid);
	process(arr,mid+1,R);
	emerage(arr,L,mid,R);
}
void emerage(int *p,int L,int M ,int R) 
{
	
	int *help = new int[R-L+1];
	int i = 0;
	int cur1 = L;
	int cur2 = M + 1;
	while (cur1<=M && cur2<=R) 
	{
		help[i++] = p[cur1] < p[cur2] ? p[cur1++] : p[cur2++];
	}
	while (cur1 <= M )
	{
	   help[i++] = p[cur1++];
	}
	while (cur2 <= R)
	{
	   help[i++] = p[cur2++];
	}
	
	for (int j = 0;j<R-L+1;j++)  //j必须保证在左右两个递归分支都遍历R-L+1
	{
		p[L+j] = help[j];  //L+j是左右两个递归分支的起点
    }


}
int main() 
{
	int arr[6] = {6,2,1,5,9,8};
	
	process(arr, 0, 5);
	for (int i = 0;i<6; i++) { cout << arr[i] << endl; }
	
	return 0;
}
```

<img src="F:\C++代码资料\Fig-DS\14.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-DS\15.png" style="zoom:80%;" />

**最小和问题解法：**

```c++
#include <iostream>
#include <algorithm>
using namespace std;


void emerage(int* p, int L, int M, int R);
int process(int *arr,int L,int R) 
{
	if (L == R) 
	{
		return ;
	}
	int mid = L + ((R - L) >> 1);
	return process(arr,L,mid)+
	process(arr,mid+1,R)+
	emerage(arr,L,mid,R);
}
int emerage(int *p,int L,int M ,int R) 
{
	
	int *help = new int[R-L+1];
    int i= 0；
	int cur1 = 0;
	int cur2 = M + 1;
    int res = 0;
	while (cur1<=M && cur2<=R) 
	{
        res = p[cur1] < p[cur2] ? (r- p2+1)*p[cur1] :0;
		help[i++] = p[cur1] < p[cur2] ? p[cur1++] : p[cur2++];
	}
	while (cur1 <= M )
	{
	   help[cur1++] = p[cur1++];
	}
	while (cur2 <= R)
	{
	   help[cur1++] = p[cur2++];
	}


	for (int i = 0;i<R-L+1;i++) 
	{
		p[L+i] = help[i];
    } 
   
    return res;

}
int main() 
{
	
}
```

##### 快速排序：

![](F:\C++代码资料\Fig-DS\19.png)

快排1.0，2.0版本，时间复杂度是O（n^2）

3.0版本需要先进行一步在数组中取随机值与最右侧交换，时间复杂度是O（nlogn）

快排的空间复杂度是logn级别的

<img src="F:\C++代码资料\Fig-DS\16.png" style="zoom: 33%;" />

<img src="F:\C++代码资料\Fig-DS\17.png" style="zoom: 33%;" />

<img src="F:\C++代码资料\Fig-DS\18.png" style="zoom:50%;" />

```c++
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int& k, int& q)
{
	int temp = k;
	k = q;
	q = temp;
}
int* parti(int* p, int L, int R)
{
	int less = L - 1;
	int more = R;
	while (L < more)
	{
		if (p[L] < p[R])
		{
			swap(p[L++], p[++less]);
		}
		else if (p[L] > p[R])
		{
			swap(p[L], p[--more]);
		}
		else
		{
			L++;
		}
	}
	swap(p[R], p[more]);
	int arr2[] = { less + 1,more };
    //more不用加1，因为在循环结束后，分界值与右边界第一个值互换了
    //在递归函数两个子过程里less+1与more这两个与分界值相等的区域分别做-1，+1操作。
	return arr2;

}
void quicksort(int* arr, int L, int R)
{
	if (L < R) 
    {    
 //快排2.0版本，时间复杂度是O（n^2）,3.0版本需要先进行一步在数组中取随机值与最右侧交换，时间复杂度是O（nlogn）
		int* loc = parti(arr, L, R);
		quicksort(arr, L, loc[0] - 1);
		quicksort(arr, loc[1] + 1, R);
	}
}

int main() 
{
	int arr[6] = {6,2,1,5,9,8};
	quicksort(arr, 0, 5);
	for (int i = 0;i<6;i++) { cout<<arr[i] << endl; };
	return 0;
}

```

##### 异或：

0与任何数异或都等于这个数本身，两个相同数异或为0

异或满足交换律，结合律

一组数进行异或操作得到的数与这组数的顺序无关

<img src="F:\C++代码资料\Fig-DS\3.png" style="zoom:67%;" />

下图交换了arr[i]与arr[j]的数值

<u>前提条件：i与j的地址不同</u>，地址相同进行异或会变成

<img src="F:\C++代码资料\Fig-DS\1.png"  />

<img src="F:\C++代码资料\Fig-DS\2.png" style="zoom:67%;" />

**问：一组数，其中两种数为奇数个，其他的数种都为偶数，求这两种数是多少：**

```c++
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         int res = 0;
         int num = 0;
         vector<int> vec;
         for(int i=0;i<nums.size();i++)
         {
           res^=nums[i];
         }
         int eor = (res == INT_MIN ? res:res&(~res+1));
         //从这里分两堆，一堆是和eor与运算为1的，一堆数是和eor与运算为0的
         for(int i=0;i<nums.size();i++)
         {
             if(nums[i] & eor)
          //这里其实取得是在这个eor这一位上的不为0
       //以eor这一位上为1，或为0，将整个数组分为两堆
             {
               num^=nums[i];
             }
         }
         res^=num;
         vec.push_back(res);
         vec.push_back(num);
         return vec;
    }
};
```

#### 堆

![](F:\C++代码资料\Fig-DS\36.png)

一个数组，从0-6的序号，可以想象成一棵完全二叉树。

其中i是结点序号，左右孩子，父节点序号如图

<img src="F:\C++代码资料\Fig-DS\20.png" style="zoom: 67%;" />

大根堆：

在整个大根堆中，无论取堆的哪一个部分，根节点数值永远是最大值，小根堆亦然

<img src="F:\C++代码资料\Fig-DS\21.png" style="zoom:67%;" />

**heapinsert**

用户每新加入一个结点，都让这个结点去与其父结点（父节点计算方式:（i-1）/2）去比较，如果比父结点大则swap，这个过程叫heapinsert。

<img src="F:\C++代码资料\Fig-DS\22.png" style="zoom:67%;" />

<img src="F:\C++代码资料\Fig-DS\23.jpg" style="zoom: 33%;" />

```c++
void heapinsert(int *p , int index) 
{
	while (p[index]>p[(index-1)/2])  //包含到0索引以后自己和自己比也会停，并且父节点大于自己也会停
	{
		swap(p[index], p[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}
```

**heapify**

<img src="F:\C++代码资料\Fig-DS\24.png" style="zoom: 67%;" />

<img src="F:\C++代码资料\Fig-DS\25.jpg" style="zoom: 67%;" />

```c++
void swap(int& k, int& q)
{
	int temp = k;
	k = q;
	q = temp;
}
void heapify(int *p , int index,int heapsize) 
{
	int left = 2*index+1;
	while (left<heapsize) //循环结束条件是，根节点没有子树可交换时
	{
		int largest = p[left + 1] > p[left]&& left+1 < heapsize ? left+1 : left; 
		//在保证有右孩子的前提下（没有右孩子，证明left+1 = heapsize，直接让左孩子等于largest），比较左右孩子大小，取最大的那个结点的索引
		largest = p[index] > p[largest] ? index: largest; //将根节点数值与左右孩子中较大的一个比较
		if (largest == index)     //先进行索引交换，确定索引，再换value
		{
			break;   //如果最大值就是根节点，则停止，否则剩下的是多余操作占用时间复杂度
		}
		swap(p[index], p[largest]);
		index = largest;
		left = 2 * index + 1;
	}
}

int main() 
{
	int arr[6] = {6,2,1,5,9,8};

	for (int i = 0;i<6;i++) { cout<<arr[i] << endl; };
	return 0;
}
```

<img src="F:\C++代码资料\Fig-DS\35.png" style="zoom: 50%;" />

<u>用户要在堆里加一个数，只是进行heapinsert调整，变化的只是高度，所以是O（logN）级别的</u>

<u>用户删除最大值，并让剩下的数调整成堆，heapify过程，也只是设计高度变化，所以也是O（logN）级别的</u>

**堆排序：**

先依次构造成一个大根堆，每个根节点与--heapsize后的最后一个节点互换    再循环    对大根堆每个根节点与--heapsize后的最后一个节点互换，进行heapify

**时间复杂度：O（ nlogn）**

**空间复杂度：O（1）**

```c++
void heapsort(int *p,int size) 
{
	if (!p && size < 0) 
	{
		return;
	}
	for (int i = 0; i < size; i++)
	{
		heapinsert(p, i);
	}
	int heapsize = size;
	swap(p[0],p[--heapsize]);
	while (heapsize>0) 
	{
		heapify(p,0,heapsize);
		swap(p[0], p[--heapsize]);
	}

}
int main() 
{
	int arr[6] = {6,2,1,5,9,8};
	heapsort(arr,6);
	for (int i = 0;i<6;i++) { cout<<arr[i] << endl; };
	return 0;
}

```

另一种写法：可以让在heapify排序的更快

<img src="F:\C++代码资料\Fig-DS\37.png" style="zoom:50%;" />

<img src="F:\C++代码资料\Fig-DS\38.png" style="zoom:50%;" />

```c++
void heapsort(int *p,int size) 
{
	if (!p && size < 0) 
	{
		return;
	}
	//for (int i = 0; i < size; i++)
	//{
	//	heapinsert(p, i);
	//}
    
    for(int i=size-1;i>=0;i--)
    {
        heapify(p,i,size);
    }
   //从最后一层叶子节点，一直到根节点，根节点也要做heapify过程。这种方法可代替逐个heapinsert的方法，且相对于heapinsert的时间复杂度为O（n）
  //heapinsert
    int heapsize = size;
	swap(p[0],p[--heapsize]);
	while (heapsize>0) 
	{
		heapify(p,0,heapsize);
		swap(p[0], p[--heapsize]);
	}

}
int main() 
{
	int arr[6] = {6,2,1,5,9,8};
	heapsort(arr,6);
	for (int i = 0;i<6;i++) { cout<<arr[i] << endl; };
	return 0;
}
```

<img src="F:\C++代码资料\Fig-DS\39.png" style="zoom: 67%;" />

思路：利用小根堆，设k=6，索引0-6之后每将一个数放进小根堆，便将小根堆的根节点（最小值）弹出去，赋值给数组。

<img src="F:\C++代码资料\Fig-DS\40.png" style="zoom:67%;" />

**heap的扩容：添加N个元素，扩容了（logN）次，单次扩容代价O（N），总代价O（N*logN），均摊代价O（N*logN）/ N**

<img src="F:\C++代码资料\Fig-DS\41.png" style="zoom:80%;" />

<img src="F:\C++代码资料\Fig-DS\42.png" style="zoom: 67%;" />

**桶排序：**

（非比较类排序）

桶排序与计数排序都是非比较类排序

<img src="F:\C++代码资料\Fig-DS\44.png" style="zoom: 80%;" />

<img src="F:\C++代码资料\Fig-DS\43.png" style="zoom:80%;" />

1.先让每个数的位数对齐，然后构造一个辅助数组，按个位数大小进行排序

2.再按着十位数的大小排序

3.再按着百位数的大小排序

**优化后的桶排序：**

<img src="F:\C++代码资料\Fig-DS\45.png" style="zoom:80%;" />

1.先让每个数的位数对齐，然后构造一个辅助数组（数组中每个索引代表个位数的大小），计算出个位数数字的词频放在对应索引处

2.再将这个数组每个位置上的数替换成这个索引前面所有的词频相加之和

3.构造一个新数组，用用户输入的数组从尾到头进行遍历，每出现一次个位数对应索引上的前缀词频-1，并将计算好的数值放在新数组对应索引处

4.循环以上操作直到 i > 数组最大值的位数后排序结束

```c++
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

void swap(int& k, int& q)
{
	int temp = k;
	k = q;
	q = temp;
}

void radixsort(int *p,int L,int R,int digit) 
{
	int radix = 10;
	int* bulket = new int[R-L+1];
	for (int i = 1;i<=digit;i++)   //记得要有等于号是“>=”!!!
	{
		int* count = new int[radix] {0,0,0,0,0,0,0,0,0,0};
		for (int j = L; j <= R; j++)
		{
			int k = (p[j]/(int)(pow(10,i-1))) % 10; //分别取个十百位的模
			count[k]++; //对应词频递增
        }
		for (int k = 1; k < radix; k++)
		{
			count[k] = count[k] + count[k - 1];  //生成对应前缀和
		}
		for (int t = R; t>=L; t--)
		{
			int y = (p[t] /(int)(pow(10, i-1))) % 10;
			bulket[count[y] - 1] = p[t];
			count[y]--;  //记得桶弹出后要维护词频递减！！！
		}
		for (int u = 0; u <=R; u++)
		{
			p[u] = bulket[u];
		}
	}


}
int main() 
{
	int arr[6] = {600,21,12,54,95,86};
	radixsort(arr,0,5,3);
	for (int i = 0;i<6;i++) { cout<<arr[i] << endl; };
	return 0;
}

```

#### 排序算法总结：

<img src="F:\C++代码资料\Fig-DS\46.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-DS\47.png" style="zoom:67%;" />

**基于比较的排序，没有算法能达到时间复杂度在O（N*logN）。**

**时间复杂度O（N*logN）的排序算法，没有算法能达到空间复杂度在O（N）以下且稳定。**

快排是相对于 归并，堆排序 速度最快的算法但是牺牲了稳定性与空间复杂度。归并排序是三个算法之中稳定性最高的算法但是牺牲了空间复杂度。堆排序是三个算法中空间复杂度最低的算法，但是牺牲了稳定性。

![](F:\C++代码资料\Fig-DS\48.png)

![](F:\C++代码资料\Fig-DS\49.png)

**1.实现综合排序：**

<img src="F:\C++代码资料\Fig-DS\50.png" style="zoom:67%;" />

**2.稳定性**

c++底层库进行排序算法，使用基础类型数据用快排放弃稳定性。数据量比较大时候底层库进行排序算法默认应用归并，保证排序的稳定性

稳定性就是指数据大小相同时，怎么排序能保证这些相同的数值的相对位置不变

