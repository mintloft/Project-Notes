#  LeetCode刷题笔记

## 数组与矩阵

##### 🤞leetcode-283：移动零

给定一个数组 `nums`，编写一个函数将所有 `0` 移动到数组的末尾，同时保持非零元素的相对顺序。

**示例:**

```
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
```

**说明**:

1. 必须在原数组上操作，不能拷贝额外的数组。

2. 尽量减少操作次数。

   ```java
   class Solution {
      public void moveZeroes(int[] nums) {
   	   int index = 0;
          for(int num:nums)  //利用for-each循环取出非零元素从新赋值成一个新的数组
          {
               if(num!=0)
               {
               nums[index++] = num;
               }
          }
          while(index<nums.length)  //将其余数组中空值处赋值为0
          {
            nums[index++] = 0;
          }
      }      
   }
   ```

##### 🤞leetode-27. 移除元素

给你一个数组 `nums` 和一个值 `val`，你需要 **[原地](https://baike.baidu.com/item/原地算法)** 移除所有数值等于 `val` 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 `O(1)` 额外空间并 **[原地 ](https://baike.baidu.com/item/原地算法)修改输入数组**。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

```
示例 1：
输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
```

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
         int len = nums.size();
         vector<int> vec(len);   
          int left = 0;
          int right = len;       
          while(left<right)
          {
             if(nums[left]==val)
             {
               nums[left] = nums[right-1];
               right--;
             }
             else
             {
                 left++;
             } 
            
          } 
           return left;
    }
};
```



##### leetcode-566：改变矩阵维度   

在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。

重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。

如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。

**示例**：
<img src="file:///C:\Users\86131\Documents\Tencent Files\2058575551\Image\C2C\S%R{WMKE64GU1B1K614K{W2.png" alt="img" style="zoom: 50%;" />

```java
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
       int [][]numbers = new int[r][c];
       int []array = new int[r*c];
       int cnt = 0;
       if((nums.length*nums[0].length)!=r*c)
       {
          return nums;
       }
       
       for(int []num :nums)   //遍历一个二维数组
       {
           for(int element:num)
           {
              array[cnt++] = element;
           }
          
        }
       for(int i=0;i<r;i++)
       {
         for(int j=0;j<c;j++)
         {
            numbers[i][j]=array[i*c+j];
         }

       }
       return numbers;
    }
}
```

```c++
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
      int len = mat.size();
      int cap = mat[0].size();
      vector<vector<int>> remat(r,vector<int>(c)); //二维vector初始化的方式
    //若要给vector赋值，vector一定要初始化
       if (len * cap != r * c) {
            return mat;    //输出原始矩阵
        }
        int index = 0;
      for(int i=0;i<r;i++)
      {
         for(int j=0;j<c;j++)
         {
             remat[i][j] = mat[index/cap][index%cap];
             index++;
         }
      }
      return remat;
    }
};
```

##### leetcode-485：找出最长连续的1

给定一个二进制数组， 计算其中最大连续 1 的个数

<img src="file:///C:\Users\86131\Documents\Tencent Files\2058575551\Image\C2C\264R($D1B{L$(@)7]T9MKCT.png" alt="img" style="zoom: 67%;" />

```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
    int numbers[] = new int[nums.length];
    int j = 0;
    for(int i = 0;i<nums.length;i++)
    {
        
         if(nums[i]==1)
         {
             j++;
             if(i==nums.length-1)
             {
                 numbers[i] = j;
             }
        }
         else
         {
             numbers[i] = j;
             j=0;
         }
    }
    int b = numbers[0];
    for(int k = 1;k<numbers.length;k++)
    {
         
         if(numbers[k]>b)
         {
          b = numbers[k];
         }
         
    }
    return b;
    }
    
}
```

```c++
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
    int cap = nums.size();
    int ans = 0;
    int  k =0;
    for(int i =0 ;i<cap;i++)
    {
        if(nums[i]==1)
        {
            ans++;
        }
        else
        {
            ans = 0;
        }
        k = max(ans,k);
    }
       return k;
    }
};
```

##### leetcode-240：有序矩阵查找

编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

**示例 1：**

输入：matrix = 

[[1,4,7,11,15],

[2,5,8,12,19],

[3,6,9,16,22],

[10,13,14,17,24],

[18,21,23,26,30]]   , target = 5

输出：true

```java
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
    if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return false;
    int m = matrix.length, n = matrix[0].length;
    int row = 0, col = n - 1;
    while (row < m && col >= 0) {
        if (target == matrix[row][col]) return true;
        else if (target < matrix[row][col]) col--;
        else row++;
    }
    return false;
    }
}
```

```c++
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return false; 
//如果是二维矩阵用到了列的情况，上面的判断不加下面会报空指针异常
         int r = 0;
         int c = matrix[0].size()-1;
         while(r<matrix.size()&&c>=0)
         {
             int num = matrix[r][c];
             if(matrix[r][c]==target)
             {
                  return true;
             }
             else if(matrix[r][c]>target)
             {
                 c--;
       //先对列从右向左进行自减操作
             }
             else
             {
                 r++;
        //再对行上到下递增
             }
         }
         return false;
    }
};

```

##### **leetcode-378：有序矩阵Kth**

给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是 排序后 的第 k 小元素，而不是第 k 个 不同 的元素。

你必须找到一个内存复杂度优于 O(n2) 的解决方案。

**思路：取矩阵最左值，右值作为二分的 L，R。 此题 二分范围变化的条件是根据矩阵中间值的 （索引 + 1）（因为是第几个值K th  =》 cnt）与k的大小关系判断去变化矩阵的最左值与最右值的范围。中间值的索引加1是通过两层for实现的**   

**循环的结束条件是:  l==r ，在cnt>k或cnt=k时，r 可能比 L 大一点但是  matrix【i】【j】<=mid<matrix【i】【j+1】  ，为了令循环结束   令  r = mid-1 不断趋近L, 使得 l<=r**

```c++
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = matrix[0][0];
        int r = matrix[n-1][m-1];
        while(l<=r)
        {
           int mid = l+(r-l)/2;
           int cnt = 0;
           for(int i = 0;i<n;i++)
           {
               for(int j = 0;j<m && matrix[i][j]<=mid;j++)
               {
                   cnt++;
               }
           }
             if(cnt<k)
             {
                l = mid+1;
             }
             else
             {
                r = mid-1;
             }
        }
        return l;
    }
};
```

##### leetcode-645：错误的集合

集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。

给定一个数组 nums 代表了集合 S 发生错误后的结果。

请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

**使用词频的Hash法相对容易处理，与数组发生缺失与重复的序列无关，只通过词频取两个数字**

```c++
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> hash;
        vector<int> vec(2,0);
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(auto k:nums)
        {
            hash[k]++;
        }
        for(int i =1;i<=nums.size();i++)
        {
            int count = hash[i];
            if(count==2)
            {
               vec[0] = i;
            }
            if(count==0)
            {
                vec[1] = i;
            }
        }
        
        return vec;
    }
};
```

##### leetcode-287：寻找重复数

给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。

假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。

你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

```
示例 1：
输入：nums = [1,3,4,2,2]
输出：2
```

**我们可以把从1-n无序的数抽象成一个环形链表，按着环形链表找交点的方式去寻找重复数**

```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int slow = nums[0];
      int fast = nums[nums[0]];
      while(slow!=fast)
      {
         slow = nums[slow];
         fast = nums[nums[fast]];
      }
      fast = 0;           //注意到达交点后，让快指针为0
      while(slow!=fast)
      {
         slow = nums[slow];        //到达交点后快慢指针按步长为1前进
         fast = nums[fast];
      }
      return slow;
    }
};
```

##### leetcode-667：数组相邻差值的个数

给你两个整数 n 和 k ，请你构造一个答案列表 answer ，该列表应当包含从 1 到 n 的 n 个不同正整数，并同时满足下述条件：

假设该列表是 answer = [a1, a2, a3, ... , an] ，那么列表 [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] 中应该有且仅有 k 个不同整数。
返回列表 answer 。如果存在多种答案，只需返回其中 任意一种 。

**思路：对于序列[1,n] 和 k，只需要从序列的首尾交替取k个数，然后按照最后一个数递增或递减。**

**例如n=9，k=5，我们只需要从序列的首尾交替取5个数即可。**

**nums: 1,9,2,8,3**
**diff:  8,7,6,5**
**现在已经有4个不同的相邻差，接下来的数自然递增可以了。**

**nums: 1,9,2,8,3,4,5,6,7**
**diff:  8 7 6 5 1 1 1 1**  

```c++
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> vec(n); 
        int l = 1;
        int r = n;
         for(int i = 0 ; i < k ; i++)    
        //想要k个临近差，就首尾交替取K个数，中间有k-1个临近差，第k个临近差是1（第k+1个数与第k个数相减）1与前面的临近差大小不同
         {
            vec[i] = i%2==0 ? l++:r-- ;
         }
         for(int i = k;i<n;i++)
         {
   //从第k个数开始,只是按k的奇偶性去递增即可.比如 上一次 是l++结束了，这回该r--了，这回还是按l++之后依次递增
             vec[i] = k%2==0 ? r--:l++ ;
         }
         return vec;
    }
};
```

##### **leetcode-697：数组的度**

给定一个非空且只包含非负数的整数数组 nums，数组的 度 的定义是指数组里任一元素出现频数的最大值。

你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

```
示例 2：
输入：nums = [1,2,2,3,1,4,2]
输出：6
解释：
数组的度是 3 ，因为元素 2 重复出现 3 次。
所以 [2,2,3,1,4,2] 是最短子数组，因此返回 6 。
```

```
示例 1：
输入：nums = [1,2,2,3,1]
输出：2
解释：
输入数组的度是 2 ，因为元素 1 和 2 的出现频数最大，均为 2 。
连续子数组里面拥有相同度的有如下所示：
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组 [2, 2] 的长度为 2 ，所以返回 2 。
```

**思路：滑动窗口**

```c++
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // 定义统计哈希表和最大频数
        unordered_map<int, int> mp;
        int max_fre = 0;
        // 统计频数，并计算最大频数
        for(int i = 0; i < nums.size(); i ++) {
            mp[nums[i]] ++;
            max_fre = max(max_fre, mp[nums[i]]);
        } 
        // 清除之前的map，重构map
        mp.erase(mp.begin(), mp.end());
        // 定义窗口和满足频数的最短长度
        int ans = nums.size();
        int left = 0, right = 0;
        while(right < nums.size()) {
            mp[nums[right]] ++;
   // 当map中的频数最大的数的频数从0递增到maxfre后，不断收缩左边界，不断计算滑动窗口的最小距离
            while(mp[nums[right]] == max_fre) 
            {
                ans = min(ans, right - left + 1);
                mp[nums[left ++]] --;  
 //窗口左边界到达最左侧频数最大的数时，递减这个数的频数后，频数小于max_fre（内层循环结束）。继续移动滑动窗口右边界去寻找下一个递增到maxfre的数的最小窗口长度
            }
            right ++;
        }
        return ans;
    }
};

```

##### **leetcode-565：数组的嵌套**

索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到最大的集合S并返回其大小，其中 S[i] = {A[i], A[A[i]], A[A[A[i]]], ... }且遵守以下的规则。

假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]... 以此类推，不断添加直到S出现重复的元素。

```
示例 1:
输入: A = [5,4,0,3,1,6,2]
输出: 4
解释: 
A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
其中一种最长的 S[K]:
S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
```

```c++
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
       int cnt ;
       int c = 0;
        for(int i = 0;i<nums.size();i++)
        {
            cnt = 0 ;
            for(int j = i ;nums[j]!=-1;)  
   //对数组中每一个元素作为抽象链表的头进行枚举，终止条件是下一个结点指向的val是曾经标记过的元素
            {
               cnt++;       
          //cnt记录每次枚举出的集合的长度
               int t = nums[j];
               nums[j] = -1;
          //将存在过集合中的元素标记为-1
               j=t;
         //将上一个数组的元素赋值成下一个数组的索引
            }
          c = max(c,cnt);
        }
          return c;
    }
};
```

**leetcode-769：分隔数组**

给定一个长度为 n 的整数数组 arr ，它表示在 [0, n - 1] 范围内的整数的排列。

我们将 arr 分割成若干 块 (即分区)，并对每个块单独排序。将它们连接起来后，使得连接的结果和按升序排序后的原数组相同。

返回数组能分成的最多块数量。

```
示例 2:
输入: arr = [1,0,2,3,4]
输出: 4
解释:
我们可以把它分成两块，例如 [1, 0], [2, 3, 4]。
然而，分成 [1, 0], [2], [3], [4] 可以得到最多的块数。
```

**思路：若前 i 个元素的最大值与 与 i 这个索引的数值相同，则可对前i个元素进行一次排序，最尾端一定与前面所有元素最大的值相同  则再进行一次排序。则中间出现一次分割可将数组分割为两块**

```c++
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       int c = 0;
       int ret = 0;
       for(int i = 0;i<arr.size();i++)
       {
           c = max(c,arr[i]);
           if(c==i)
           {
              ret++;
           }
       }
       return ret;
    }
};
```

##### **leetcode-10：对角元素相等的矩阵**

给你一个 m x n 的矩阵 matrix 。如果这个矩阵是托普利茨矩阵，返回 true ；否则，返回 false 。

如果矩阵上每一条由左上到右下的对角线上的元素都相同，那么这个矩阵是 托普利茨矩阵 。

<img src="F:\C++代码资料\Fig-DS\55.png" style="zoom:50%;" />

**思路：如此遍历保证对角线元素全部遍历到，且不超出索引：左下角与右上角不会与超出索引的元素发生对比**

```c++
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i =1;i<m;i++)
        {
            for(int j = 1;j<n;j++)
            {
                if(matrix[i][j]!=matrix[i-1][j-1])
                {
                     return false;
                }
            }
        }
        return true;
    }
};
```

**leetcode-14：最长公共前缀**

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

```
示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"
```

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         int len = 1e9;
         int count = 0;
         for(auto p:strs)
         {
           int z = p.size();
           len = min(len,z);
         }
         count = len;
         for(int i = len-1;i>-1;i--)
         {
            string res = strs[0];
            char ans = res[i];          
            for(auto q:strs)
            {               
                 if(q[i]!=ans)
                 {
                   count = i;
                    break;
                 }            
            }
         }
          return strs[0].substr(0,count);
    }
};
```

##### **leetcode-48：旋转图像**

给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int rowsize = matrix.size();
       int colsize = matrix[0].size();
        for(int i = 0;i<rowsize/2;i++)
        {
           for(int j = 0;j<colsize;j++)
           {
              swap(matrix[i][j],matrix[rowsize-i-1][j]);
           }
        }
        for(int i = 0;i<colsize;i++)
        {
           for(int j = 0;j<i;j++)
           {
              swap(matrix[i][j],matrix[j][i]);
           }
        }


    }
};
```

**第二重循环的含义，对于矩阵内每一个对角线元素（每个对角线元素的row都等于对角线元素的col），直接遍历该行row对角线元素col之前的每个元素，并进行swap(matrix【i】【j】,matrix【j】【i】)**

<img src="F:\C++代码资料\Fig-DS\58.png" style="zoom: 67%;" />

##### 剑指 Offer 03. 数组中重复的数字

找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

```
示例 1：
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
```

```c++
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         for(int i = 1;i<nums.size();i++)
         {
            if(nums[i]==nums[i-1])
            {
                return nums[i];
            }
         }
         return NULL;

    }
};
```

##### leetcode-48：除自身以外数组的乘积

给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请不要使用除法，且在 O(n) 时间复杂度内完成此题。

```
示例 1:
输入: nums = [1,2,3,4]
输出: [24,12,8,6]
```

```c++
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int n = nums.size();
         vector<int> vec(n,0);
         int k=1;
   //创建一个数组，首先令数组中每个数都为不包括该数左侧所有数的乘积，最左侧的数先赋值为1，因为左侧没数值了
         for(int i = 0;i<n;i++)
         {
            vec[i] = k;
            k*=nums[i];
         }
         k =1;
        //再令数组中每个数都为不包括该数得右侧所有数的乘积
         for(int i = nums.size()-1;i>=0;i--)
         {
            vec[i] *=k; 
            k*=nums[i];            
         }
         return vec;
    }
};
```

##### 剑指 Offer 40. 最小的第k个元素

输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

```
示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]
```

```c++
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
         sort(arr.begin(),arr.end());
         vector<int> vec(k,0);  //记得vector一定要初始化，不初始化无法vec[i] = arr[i];进行赋值
         for(int i =0;i<k;i++)
         {
           vec[i] = arr[i];  
         }
         return vec;
    }
};
```

##### 剑指 Offer 17. 打印从1到最大的n位数

输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

```
示例 1:
输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
```

```c++
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int x = pow(10,n);
        x = x-1;
        for(int i = 1;i<=x;i++)
        {
            res.push_back(i);
        }
        return res;
    }
};
```

##### leetcode-31：下一个排列

整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。

例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。

**示例 1：**

```
输入：nums = [1,2,3]
输出：[1,3,2]
```

**示例 2：**

```
输入：nums = [3,2,1]
输出：[1,2,3]
```

<img src="F:\C++代码资料\Fig-DS\86.png" style="zoom:50%;" />

**思路：**

**用最后的序列举例，从序列最后向前遍历，直到nums[j]>nums[j-1]时停止，替换原序列中的4与4后面的序列中略大于4的数6，替换后再将6后面的序列逆序reverse反转。**

**如果序列本身就是从大到小排列的，则直接对数组进行反转就可以**

```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
           if(nums.size()==0)
           {
               return ;
           }
           int j = nums.size()-1;
           while(j>0)   //循环只对nums[j]<=nums[j-1]时有效
           {
               if(nums[j]<=nums[j-1])
               {
                    j--;
               }
               else
               {
                   int start = j-1;
                   while(j<nums.size()&&nums[start]<nums[j])
                   {
                     j++;
                   }
                   j--;
                   int temp = nums[j];
                   nums[j] = nums[start];
                   nums[start] = temp;
                  reverse(nums.begin()+start+1,nums.end());
                  return;   //进入else后执行结束直接跳出循环
           }
               }
   //序列本身就是从大到小排列的，则直接对数组进行反转..进入循环后没进else不会返回或对数组发生改变
            reverse(nums.begin(),nums.end());
    }
};
```

##### 剑指 Offer 29. 顺时针打印矩阵

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

**示例 1：**

```
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
```

```c++
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0) return vector<int>();
        int n = matrix[0].size();
        int up = 0;
        int down = m-1;     //设置矩阵的四个边界
        int right = n-1;
        int left = 0;
        int cur = 0;
        int sumlo = m*n;
        vector<int> vec(sumlo);
      //当数组中元素个数与matrix相等时结束循环
      //模拟顺时针遍历过程：
        while(cur<sumlo)
        {
           for(int i = left;i<=right;i++)
           {
              vec[cur++] = matrix[up][i];  
           }
             up++;  //上边界下移
             if(cur==sumlo)
             {
                 break;  
             }
            for(int i = up;i<=down;i++)
            {
               vec[cur++] = matrix[i][right];  
            }
             right--; //右边界右移
             if(cur==sumlo)
             {
                 break;
             }
            for(int i = right;i>=left;i--)
            {
               vec[cur++] = matrix[down][i];  
            }
             down--;
             if(cur==sumlo)
             {
                 break;
             }
             for(int i = down;i>=up;i--)
            {
               vec[cur++] = matrix[i][left];  
            }
             left++;   
//一圈遍历矩阵中最后向上移动的一条边，不需要在判断if(cur==sumlo)，因为while中条件可自行判断
        }
        return vec;
    }
};
```

<img src="F:\C++代码资料\Fig-DS\94.png" style="zoom: 50%;" />

##### 剑指 Offer 61. 扑克牌中的顺子

难度简单249

从**若干副扑克牌**中随机抽 `5` 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

**示例 1:**

```
输入: [1,2,3,4,5]
输出: True
```

**思路：**简单的理解就是，这个数组中0可以当任何数用，所以当牌不连续的时候，它就可以替补一下，进而达到顺的要求。    先对整个数组排序，最后判断最大值与最小值之差是否比5小（5-1=4，4-0=4）.如果有大小王（大小王数值为0），就将最小值指针向前移动，保证减不到大小王。

```c++
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int joker = 0;
        for(int i = 1;i<n;i++)
        {
          if(nums[i-1]==0)    joker++;
          else if(nums[i-1]==nums[i]) return false;
        }
        return nums[4]-nums[joker]<5;
    }
};
```



## 链表

##### leetcode-203：删除链表结点

给你一个链表的头节点 `head` 和一个整数 `val` ，请你删除链表中所有满足 `Node.val == val` 的节点，并返回 **新的头节点** ：

<img src="file:///C:\Users\86131\Documents\Tencent Files\2058575551\Image\C2C\A@3I2P@YYAISE7D{%]H{0JV.png" alt="img" style="zoom:50%;" />

方法1：

```java
package Solution2;     //力扣·203题
                               //方法二：使用虚拟头节点
public class Solution3 {
	 public ListNode removeElements(ListNode head, int val) {
             ListNode dummyNode = new ListNode(-1);
             dummyNode.next = head;           //虚拟节点之后的第一个节点是head
             ListNode prev = dummyNode;
             while(prev.next!=null) 
             {
            	 if(prev.next.val == val)
            	 {
            		 prev.next = prev.next.next; //力扣上可以不用将delNode的内存释放
            	 }
            	 else//因为要删除全部等于val的值，所以要先if保证下一个结点的数值不为val，才可继续遍历
            	 {
            		 prev = prev.next;
            	 }
             }
            return head; 
	    }


}
```

```c++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
           ListNode *dummynode = new ListNode(-1);
           dummynode->next = head;
           ListNode *prev = dummynode ;
            while(prev->next!=NULL)
            {
               
               if(prev->next->val==val)
               {
                prev->next=prev->next->next;
               }
               else
               {
                   prev = prev->next;
               }
                
            }
          return dummynode->next;
    }
};
```

方法2：（递归）  递归方法不需要创建虚拟结点

<img src="F:\java学习资料\数据结构笔记\image\1.png" style="zoom:50%;" />

<img src="F:\java学习资料\数据结构笔记\image\2.png" alt="2" style="zoom:50%;" />

<img src="F:\java学习资料\数据结构笔记\image\3.png" alt="3" style="zoom:50%;" />

<img src="F:\java学习资料\数据结构笔记\image\4.png" alt="4" style="zoom:50%;" />

<img src="F:\java学习资料\数据结构笔记\image\5.png" alt="5" style="zoom:50%;" />

```java
public class Solution {
	 public ListNode removeElements(ListNode head, int val) {
	if(head==null)    //此处是“基本问题”，递归的终止条件与链表为空时的条件
    {
        return null;
    }
    head.next = removeElements(ListNode head.next, int val);    
    return head.val == val ? haed.next.val : haed.val;
}
```

**使用递归在链表中添加结点：**

<img src="F:\java学习资料\数据结构笔记\image\6.png" style="zoom:33%;" />

问 ：可不可以不返回头节点?

答： 不可以，否则递归函数的结果不能和前面的链表连接起来。

```java
public class Solution {
	 public ListNode addElements(ListNode head, int index，int var) {
	if(index==0)    //此处是“基本问题”，递归的终止条件与链表为空时的条件
    {
        return new ListNode(var);
    }
    head.next = addElements(ListNode head.next, index-1,int val);    
    return head;
}
```

##### 🤞leetcode-206：反转链表 

给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表

方法1：（非递归实现）

<img src="file:///C:\Users\86131\AppData\Roaming\Tencent\Users\2058575551\QQ\WinTemp\RichOle\@$%VP2151$18%Z6N25I{N69.png" alt="img" style="zoom:33%;" />

```java
class Solution {
    public ListNode reverseList(ListNode head) {
     ListNode prev = null;
     ListNode cur = head; //既要有prev也要有next还有cur。没有prev则找不到一轮循环移动后的上一个节                             点，没有next则不能将cur指针移动到下一结点
     while(cur!=null)
     {
        ListNode next = cur.next; //思路：相当于先用next指针把cur的后一个节点先存起来，再修改cur的                                     next所指的，再移动cur到next指针处
        cur.next = prev;
        prev = cur;
        cur = next;
     }
      return prev;
        
      注意这里返回的是prev，不是cur，出循环后头结点是prev
          
    }
}
```

```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* cur = head;
       ListNode *prev = NULL;
       while(cur!=NULL)
       {
       ListNode *next_prt = cur->next; 
       cur->next = prev;
       prev = cur;
       cur = next_prt;
       }
       return prev;
        //注意结束时cur运动到Null，所以应该返回prev
    }
};
```

方法2：（递归实现）

<img src="file:///C:\Users\86131\Documents\Tencent Files\2058575551\Image\C2C\3A7YC9{MDLX0BIBTRQJ@6L3.png" alt="img" style="zoom: 50%;" />

<img src="F:\java学习资料\数据结构笔记\image\7.png" style="zoom:50%;" />

**递归的宏观语义：**

1.处理基本问题/递归终止条件

```java
 head==null||head.next==null
```

2.将2-5结点进行翻转（其中间包括一步步从5到45到345到2345的微观反转）【此时2指向null】

3.再将2与1建立连接

```java
head.next.next = head;
head.next = null;
```

```java
//递归方法代码实现：
class Solution {
    public ListNode reverseList(ListNode head) {
    if(head==null||head.next == null)
    {
        return head;
    }
    ListNode rev = reverseList(head.next); //将1后面反转的链表存在rev中
    head.next.next = head;
    head.next = null;
    return rev;
    }
}
```

##### **🤞BM2** **链表内指定区间反转**

将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转，要求时间复杂度 O(n)*，空间复杂度 O(1)*。


要求：时间复杂度 O(n) ，空间复杂度 O(n）

进阶：时间复杂度 O(n)，空间复杂度 O(1)

**示例1**

输入：

```
{1,2,3,4,5},2,4
```

返回值：

```
{1,4,3,2,5}
```

**思路：**先按着链表反转的最基本的方式，将链表从m到n位置反转（n-m+1）次（基础的链表反转如果链表长度为3，就要进行三次反转）并切割开，并用之前标记过切割位置的节点进行重新连接

**注：需使用虚拟节点，否则如果反转头点，则返回值不准确**

```c++
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        ListNode* dummynode = new ListNode(-1);
        dummynode->next = head;
        ListNode* firstTail = dummynode;
        for(int i=1;i<m;i++)
        {
            firstTail = firstTail->next;
        }
        int index = 0;
        int len = n-m;
        ListNode* cur = firstTail->next;
        ListNode* secondTail = cur;
        ListNode* prev = nullptr;
        while(index<(len+1))
        {
            ListNode* Next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = Next;
            index++;
        }
        firstTail->next = prev;
        secondTail->next = cur;
        return dummynode->next;
    }
};
```



##### 🤞leetcode-160：相交链表

给你两个单链表的头节点 `headA` 和 `headB` ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 `null` 。

**思路：**

要求时间复杂度为 O(N)，空间复杂度为 O(1)。如果不存在交点则返回 null。设 A 的长度为 a + c，B 的长度为 b + c，其中 c 为尾部公共部分长度，可知 a + c + b = b + c + a。当访问 A 链表的指针访问到链表尾部时，令它从链表 B 的头部开始访问链表 B；同样地，当访问 B 链表的指针访问到链表尾部时，令它从链表 A 的头部开始访问链表 A。这样就能控制访问 A 和 B 两个链表的指针能同时访问到交点。如果不存在交点，那么 a + b = b + a，以下实现代码中 l1 和 l2 会同时为 null，从而退出循环。

自己答案：

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
  public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode dummyHeadA = new ListNode(-1);
        ListNode dummyHeadB = new ListNode(-1);
        dummyHeadA.next = headA;
        dummyHeadB.next = headB;
        ListNode curA = headA;
        ListNode curB = headB;
        ListNode prevA = dummyHeadA.next;
        ListNode prevB = dummyHeadB.next;
        while(prevA != prevB) 
       //这里条件不能加||prevA.next!=null||prevB.next!=null因为会直接丢失正常返回的非null解
       //或者加上prevA.next==null||prevB.next==null也不对因为会丢失返回为null解
       //条件prevA != prevB两种条件均包含
        {  
            if(curA.next!=null)
            {
               curA = curA.next;
            }
            else
            {
               prevB = prevB.next;
            }
           if(curB.next!=null)
           {
               curB = curB.next;
           }
           else
           { 
               prevA = prevA.next;
           }           
        }
      
           return prevA;
    }
}
```

标准答案：

```java
public class Solution {

  public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

  

    ListNode curA = headA;

    ListNode curB = headB;

    while(curA!=curB)

    { 

     curA = (curA==null)?headB:curA.next;

     curB = (curB==null)?headA:curB.next;

    }

   return curA;

  }

}
```

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        while(curA!=curB)
        {
          curA = curA!=NULL ? curA->next: headB;
          curB = curB!=NULL ? curB->next: headA;
 //这一定是当前指针curA移动到Null处再移动到headB端，因为结点数等于移动的次数加1，等式是a + c + b = b + c + a  三个长度做等号
        }
        return curB;
    }
};
```

##### 🤞leetcode-21：合并两个有序链表

将两个升序链表合并为一个新的 **升序** 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的

**迭代**

```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
      //这里使用虚拟结点也是因为原先的头节点不是新的头结点了
    }
};
```

**递归**

**宏观语义：**

1.递归终止条件/基本问题：

```
    if(l1==null)
    {
     return l2;
    }
     if(l2==null)
    {
      return l1;
    }
```

2.**微观语义**：

 当

```
l1.val<l2.val
```

时当前函数返回 l1 此时 的结点；并且下一次调用自身函数要传入参数是

```
(l1.next,l2)
```

即下一次调用自身函数时选择 l1 再大一点的下一个结点与当前做比较的 l2 结点作为参数。

3.**宏观语义**：

l1 与 l2 结点的 val做 对比，选择一个val小的 的结点将其返回作为新生成的归并后的链表。

答案：

```java
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
     if(l1==null)
    {
     return l2;
    }
     if(l2==null)
    {
      return l1;
    }
     if(l1.val<l2.val)
    {
       l1.next =  mergeTwoLists(l1.next,l2);
       return l1; 
    }
     else
     {
        l2.next =  mergeTwoLists(l1,l2.next);
        return l2; 
     }
    }
}
```

##### 🤞leetcode-19：删除链表的倒数第 N 个结点

给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

**进阶：**你能尝试使用一趟扫描实现吗？

**快慢指针法：**

设预先指针 pre 的下一个节点指向 head，设前指针为 start，后指针为 end，二者都等于 pre
start 先向前移动n步
之后 start 和 end 共同向前移动，此时二者的距离为 n，当 start 到尾部时，end 的位置恰好为倒数第 n 个节点

。

```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
     
       ListNode prev = head;
       ListNode cur = head;
       for(int i = 0 ; i<n ; i++ )
       {
         cur = cur.next;
       }
       if(cur==null)         
//为了防止调用空指针cur异常，【假设用例要删除的是头节点，而恰好整个链表头节点只有一个，则迭代n次后cur指向第n个结点的next为空】所以加 if(cur==null)条件
//涉及到删除类型的题目都可以加上虚拟头节点，循环内判断条件可以后加为了避免发生空指针异常，先把循环体写出来
       {
         return head.next;
       }
       while(cur.next!=null)
       {
         cur = cur.next;
         prev = prev.next;
       }
       prev.next = prev.next.next;
       return head;
    }
}
```

<u>所以较为安全的方法是建立一个虚拟头节点：</u>建立完虚拟头节点则不需要判断空指针情况

```java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
       ListNode dummyNode = new ListNode(-1);
       dummyNode.next = head;      //不要忘记建立虚拟头节点与头结点之间联系！！！！
       ListNode prev = dummyNode;
       ListNode cur = dummyNode;
       for(int i = 0 ; i<n ; i++ )
       {
          cur = cur.next;
       }
       ;
       while(cur.next!=null)
       {
          cur = cur.next;
          prev = prev.next;
       }
       prev.next = prev.next.next;·
       return dummyNode.next;
    }
}
```

```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummynode = new ListNode(-1);
        dummynode->next = head;
        ListNode* cur = dummynode;
      //总结：删除结点的类型题适合设置一个虚拟结点
        ListNode* prev = NULL;
       for(int i = 0;i<n;i++)
       {
          cur = cur->next;
       }
       prev = dummynode;
       while(cur->next!=NULL)
       {
        cur = cur->next;
        prev = prev->next;
       }

       prev->next = prev->next->next;
      
       return dummynode->next;
   //设置虚拟节点，最后返回结果一定为dummynode->next，因为如果删除头结点，则不可以返回一个head。
    }
};
```

##### 🤞**BM8** **链表中倒数最后k个结点**

输入一个长度为 n 的链表，设链表中的元素的值为 ai ，返回该链表中倒数第k个节点。

如果该链表长度小于k，请返回一个长度为 0 的链表。

数据范围：0 \leq n \leq 10^50≤*n*≤105，0 \leq a_i \leq 10^90≤*a**i*≤109，0 \leq k \leq 10^90≤*k*≤109

要求：空间复杂度 O(n)*O*(*n*)，时间复杂度 O(n)*O*(*n*)

进阶：空间复杂度 O(1)*O*(1)，时间复杂度 O(n)*O*(*n*)

其中蓝色部分为该链表的最后2个结点，所以返回倒数第2个结点（也即结点值为4的结点）即可，系统会打印后面所有的节点来比较。

输入：

```
{1,2,3,4,5},2
```

返回值：

```
{4,5}
```

说明：

```
返回倒数第2个节点4，系统会打印后面所有的节点来比较。
```

```c++
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code her
        ListNode* nextNode = pHead;
        ListNode* cur = pHead;
        while(nextNode&&k>0)
        {
            nextNode = nextNode->next;
            k--;
        }
      //这里要保证k如果大于整个链表长度，返回null
        if(k>0)
        {
            return nullptr;
        }
        while(nextNode)
        {
            nextNode = nextNode->next;
            cur = cur->next;
        }
        
        return cur;
        
    }
};
```



##### leetcode-24：两两交换链表中的结点

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

**你不能只是单纯的改变节点内部的值**，而是需要实际的进行节点交换。

<img src="file:///C:\Users\86131\Documents\Tencent Files\2058575551\Image\C2C\I%J{%$G]H[~96UME[}IVKQY.png" alt="img" style="zoom: 67%;" />

三指针：（类似于反转链表）  确定好第三个节点的位置比较重要，第三个节点是在dummy head上的，画图分析比较清晰

<img src="file:///C:\Users\86131\Documents\Tencent Files\2058575551\Image\C2C\77C52402B2BF2F5F9A9090EA2590ADAE.png" alt="img" style="zoom: 33%;" />

```java
class Solution {
    public ListNode swapPairs(ListNode head) {
       ListNode dummyNode = new ListNode(-1);
       dummyNode.next = head;
       ListNode pprev = dummyNode;
    while(pprev.next!=null && pprev.next.next!=null)
       {  
          ListNode cur = pprev.next.next;
          ListNode prev = pprev.next;
          pprev.next = cur;
          prev.next =  cur.next;
          cur.next = prev;
          pprev = prev;
        }
          return dummyNode.next;
    }
}
```

```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      ListNode* cur = head;
      ListNode* dummynode = new ListNode(-1);
      dummynode->next = head;
      ListNode* prev = dummynode;
      ListNode* Next;
      while(cur!=NULL&&cur->next!=NULL)
//偶数个结点：要先判断cur不为空。因为最后一次cur会运动到null。奇数个结点：要判断cur不为空
      {
       Next = cur->next;
       cur->next = Next->next;
       Next->next = cur;
       cur = cur->next;
       prev->next = Next;
       prev = Next->next;
      }
      return dummynode->next;
 //这里使用虚拟节点是因为两两交换后，原先的头节点就不是新的头节点了，需要返回dummynode.next
    }
};
```

##### 🤞leetcode-445：链表求和

给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。你可以假设除了数字 0 之外，这两个数字都不会以零开头。

进阶：如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

**提示：**

- 链表的长度范围为` [1, 100]`
- `0 <= node.val <= 9`
- 输入数据保证链表代表的数字无前导 0

错误解：由于没有考虑到题干下面的 提示的第一条，只做简单相加数据的位数可以超出整型的范围

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
  
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    int number = 0;
    int sum =  printSum(l1)+printSum(l2);
    String s = "" + sum;
    int sumlength = s.length()-1;
    ListNode dummyNode = new ListNode(-1);
    ListNode prev = dummyNode;
    while(sumlength>=0)
    {
       prev.next = new ListNode(sum / (int)(Math.pow(10,sumlength)));
        //Math.pow(10,sumlength)的输出类型是double型
       sum = sum % (int)(Math.pow(10,sumlength));
       sumlength--;
       prev = prev.next;
    }
       return dummyNode.next; 
    }
    public int printSum(ListNode n1)
    {
        ListNode cur = n1;
        int number = 0; 
        while(cur!=null)
        {
          number = number*10+cur.val;
          cur = cur.next;
        }
        return number;
    }
}
```

**正确解：**

求链表之和，**是从尾端开始进行遍历求解**：适合巧妙**使用栈的LIFO性质**，对链表从尾部进行加减操作

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
  
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
       Stack<Integer> Stack1 = new Stack<>();
       Stack<Integer> Stack2 = new Stack<>();
       while(l1!=null)
       {
         Stack1.push(l1.val); 
         l1 = l1.next;
       }
       while(l2!=null)
       {
        Stack2.push(l2.val); 
        l2 = l2.next;
       }
       int crash = 0;
       ListNode dummyNode = new ListNode(-1);
       ListNode nextNode = null;  //因为第一个结点初始化没有next，第一个结点的next需要指向null
       while(!Stack1.isEmpty()||!Stack2.isEmpty()||crash>0) 
        //注意crash不为0，还可以往前进位计算
       //停止条件是Stack1与Stack2都为空，且crash为0
       {
          int a = Stack1.isEmpty()? 0 : Stack1.pop(); 
          int b = Stack2.isEmpty()? 0 : Stack2.pop();
          int cur = (a+b+crash);
          crash = (a+b+crash)/10; //进位条件是三个部分相加除以10
          cur %= 10;   //当前结点的val是三部分相加mod10
          ListNode curNode = new ListNode(cur);
          dummyNode.next = curNode; //不断在dummyNode与上一次插入的节点之间插入新的节点
          curNode.next = nextNode;
          nextNode = curNode;
       }
       return dummyNode.next;
    }
}
```

```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
           ListNode * dummynode = new ListNode(-1);
           ListNode *curA = l1;
           ListNode *curB = l2;
           ListNode *curC = nullptr;  //要初始化为null，才能保证第一次insert
           stack<int> st1;
           stack<int> st2;
           int sum;
           int remain;
           int crash=0;
           while(curA!=nullptr)
           {
               st1.push(curA->val);
               curA = curA->next;
           }
           while(curB!=nullptr)
           {
               st2.push(curB->val);
               curB = curB->next;
           }
           while(!st1.empty()||!st2.empty()||crash!=0)
            //条件为||或，只要有一个不满足就要循环
           {
             int val1 = st1.empty()?0:st1.top();
             int val2 = st2.empty()?0:st2.top();
             if(!st1.empty())
             {
                st1.pop();
             }
             if(!st2.empty())
             {
                 st2.pop();
             }
            //取栈顶值与弹出都要先判断栈是否为空，
           // 因为while里的大条件是栈有一个为空也会进行循环
             sum = val1 + val2 + crash;
             remain = sum % 10;
             crash = sum/10;
             ListNode *curNode = new ListNode(remain);
             dummynode->next = curNode;
             curNode->next = curC;
             curC = dummynode->next; 
           }
            return dummynode->next;

    }
};
```

s.empty();         //如果栈为空则返回true, 否则返回false;
s.size();          //返回栈中元素的个数
s.top();           //返回栈顶元素, 但不删除该元素
**s.pop();           //弹出栈顶元素, 但不返回其值**
s.push();          //将元素压入栈顶

##### 🤞leetcode-234：回文链表

请判断一个链表是否为回文链表。

**示例 1:**

适合放在vector中用双指针法，使用一块连续的地址去存储离散的列表，可以从头与尾端同时遍历，时间复杂度为O（n）

```
输入: 1->2
输出: false
```

```java
class Solution {
     public boolean isPalindrome(ListNode head) {
	 ArrayList<Integer> numbers = new ArrayList<Integer>(); // ArrayList底层是数组。
     ListNode cur = head;
     while(cur!=null)
     {
        numbers.add(cur.val);  //将元素逐个放入ArrayList
        cur = cur.next;
     }
        int i = 0;
        int j = numbers.size()-1;
     while(i<j)              //前后双指针
         
       注意这里i与j不能用不等号比较，不等号会漏掉数组长度为偶数时的情况  
         
    {
        int valA = numbers.get(i);
        int valB = numbers.get(j);
        if(valA != valB)
        {
           return false;
        }    
         i++;
         j--;
    }
     return true;
}
}
```

```c++
class Solution {
public:
    bool isPalindrome(ListNode* head) {
      vector<int> vec;
      ListNode *cur = head;
      while(cur!=nullptr)
      {
          vec.push_back(cur->val);
          cur = cur->next;
      }
      cur = head;
      for(int i  = 0,j = vec.size()-1;i<j;i++,j--)
      {
            if(vec[i]!=vec[j])
            {
                 return false;
            }
      }
      return true;
    }
};
```

另一种方法还可以切成两半，把后半段反转，然后比较两半是否相等：

*之前自己的错误做法，将原链表反转，再与head比较行不通，因为反转以后原链表的结构已经发生了改变，而且没有办法找到原链表。*

```java
public boolean isPalindrome(ListNode head) {
    if (head == null || head.next == null) return true;
    ListNode slow = head, fast = head.next;
    while (fast != null && fast.next != null) {
        slow = slow.next;       //slow移动一步，fast移动两步
        fast = fast.next.next;
    }
    if (fast != null) slow = slow.next;  // 偶数节点，让 slow 指向下一个节点
    cut(head, slow);                     // 切成两个链表
    return isEqual(head, reverse(slow));   //将前一段链表与反转后的链表比较逐个元素
}

private void cut(ListNode head, ListNode cutNode) {
    while (head.next != cutNode) {    //移动到慢指针之前切开链表
        head = head.next;
    }
    head.next = null;
}

private ListNode reverse(ListNode head) {
    ListNode newHead = null;
    while (head != null) {
        ListNode nextNode = head.next;
        head.next = newHead;
        newHead = head;
        head = nextNode;
    }
    return newHead;
}

private boolean isEqual(ListNode l1, ListNode l2) {
    while (l1 != null && l2 != null) {
        if (l1.val != l2.val) return false;
        l1 = l1.next;
        l2 = l2.next;
    }
    return true;
}
```

##### leetcode-328：奇偶链表

给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。

示例 1:

```
输入: 1->2->3->4->5->NULL
输出: 1->3->5->2->4->NULL
```

```java
	  public ListNode oddEvenList(ListNode head) {
	      if(head==null||head.next==null){return head;}
      //若果不设置虚拟头结点,做链表题第一步一定先判断头结点与头结点的下一个结点是否为空，为空返回head。
     //并且把这个条件放在定义指针前面
           ListNode cur = head;   //设立当奇节点
	       ListNode pre = head.next;
         while(cur!=null&&cur.next!=null&&cur.next.next!=null)
     //第二部在迭代位置涉及到引用问题想清楚保证不发生空指针异常
	       {
	           ListNode Next = cur.next; //设立偶结点
	           cur.next = Next.next;  // 连接奇结点与下一个奇结点
	           Next.next= cur.next.next; //连接偶结点与下一个偶结点
	           cur = cur.next;  //将奇节点移动一次
	       }
	          cur.next = pre; //将奇链与偶链相连接
	       return head;
	    }
```

```c++
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
        {
             return head;
        }
   //针对两种情况：只有头节点  或  头节点为null的两种情况都返回head
        ListNode *prev = head->next;
        ListNode *cur = head;
        ListNode *Next;
        while(cur!=nullptr&&cur->next!=nullptr&&cur->next->next!=nullptr )
        {
            Next = cur->next;
            cur->next = Next->next;   
            Next->next = Next->next->next;
            cur = cur->next; 
        }
        cur->next = prev;
        return head;
    }
};
```

##### leetcode-725：分隔链表

给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。返回一个符合上述规则的链表的列表。

举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]

```java
class Solution {
  public ListNode[] splitListToParts(ListNode head, int k) {
      //不能加if语句判断head为null返回null，因为要返回的是一个列表
       ListNode cur = head;
       int N = 0;
       while(cur!=null)
       {
          N++;
          cur = cur.next;
       }
       int size = N / k; //求出平均列表中一个元素位置有多大
       int mod = N % k;  //求出余数
       cur = head;    
       ListNode[] Nodes = new ListNode[k];
        for(int j = 0; cur!=null && j < k ; j++)
         //这里注意容易落条件cur!=null，如果cur为null，列表中剩余位置都是null即可
        {
          Nodes[j] = cur;
          int curSize = size + (mod-- > 0 ? 1 : 0); //将余数均匀分配到列表中前几个元素上
          for(int i = 0;i < curSize - 1;i++) 
         //注意是curSize - 1，因为从cur开始，cur已经算一个元素了
          {
            cur = cur.next;
          }
          ListNode Next = cur.next;
          cur.next = null;       //断开结点
          cur = Next;
        }
        return Nodes;
    }
}
```

总结：涉及到删除类型的题目都可以加上虚拟头节点。

​           涉及到返回的新链表头结点发生改变的需要加上头节点

循环内判断条件可以后加为了避免发生空指针异常，先把循环体写出来，再写出避免空指针异常的条件。

##### leetcode-2:两数相加

给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

```
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
```

```c++
class Solution {
     public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        int carry = 0, newVal = 0;
        while (p1 != nullptr || p2 != nullptr || carry > 0) {
            newVal = (p1 == nullptr ? 0: p1->val) + (p2 == nullptr ? 0: p2->val) + carry; 
            carry = newVal / 10;
            newVal %= 10;
            p->next = new ListNode(newVal);
            p1 = p1 == nullptr? nullptr: p1->next;
            p2 = p2 == nullptr? nullptr: p2->next;
            p = p->next;
        }
        return dummy->next;
    }
};
```

##### 🤞leetcode-82:删除排序链表中重复的节点

给定一个已排序的链表的头 `head` ， *删除原始链表中所有重复数字的节点，只留下不同的数字* 。返回 *已排序的链表* 。

```
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
```

```c++
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        ListNode* dummy = new ListNode(-1);
        dummy->next = head; 
        ListNode* cur = dummy;
        while(cur->next!=nullptr)
        {
           if(cur->next->val==cur->val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
```

##### 🤞**BM16** **删除有序链表中重复的元素-II**

给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
例如：
给出的链表为1 \to 2\to 3\to 3\to 4\to 4\to51→2→3→3→4→4→5, 返回1\to 2\to51→2→5.
给出的链表为1\to1 \to 1\to 2 \to 31→1→1→2→3, 返回2\to 32→3.

数据范围：链表长度 0 \le n \le 100000≤*n*≤10000，链表中的值满足 |val| \le 1000∣*v**a**l*∣≤1000

要求：空间复杂度 O(n)*O*(*n*)，时间复杂度 O(n)*O*(*n*)

进阶：空间复杂度 O(1)*O*(1)，时间复杂度 O(n)*O*(*n*)

输入：

```
{1,2,2}
```

返回值：

```
{1}
```

输入：

```
{}
```

返回值：

```
{}
```

```c++
class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        int preVal = INT_MIN;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        ListNode* pre = dummy;
        while(head!=nullptr)
        {
           if(head->val!=preVal)
           {
               pre = cur;
               cur->next = head;
               cur = cur->next;
               preVal = head->val;
           }
            else
            {
                cur = pre;
                cur->next = nullptr;    
            }
            head = head->next;
        }
      
        return dummy->next;
    }
};
```

##### 🤞leetcode-23:合并k个升序链表

给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

```
示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
```

```c++
class Solution {
public:
    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    priority_queue<ListNode*, vector<ListNode*>, comp> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push(node);
     //lists中也有可能有空的节点，不能加入堆
        }
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while (!q.empty()) {
            ListNode* node = q.top();
            q.pop();
            tail->next = node; 
            tail = tail->next;
            if (node->next) q.push(node->next);
        }
        return head->next;
    }
};
```

##### 🤞leetcode-148: 排序链表

给你链表的头结点 `head` ，请将其按 **升序** 排列并返回 **排序后的链表** 。

<img src="F:\C++代码资料\Fig-DS\63.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-DS\30.jpg" style="zoom: 25%;" />

```c++
class Solution {
public:
 ListNode* merge(ListNode* LNode,ListNode* RNode)
    {
        if(!LNode&&!RNode)
        {
            return LNode;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* flag = dummy;
        while(LNode&&RNode)
        {
           if(LNode->val>RNode->val)
           {
               flag->next = RNode;
               RNode = RNode->next;
           }
           else
           {
                flag->next = LNode;
                LNode = LNode->next;
           }
           flag = flag->next;
        }
        flag->next = LNode?LNode:RNode;
           return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
        {
            return head;
        }
       ListNode* fast = head->next;
       ListNode* slow = head;
       while(fast && fast->next)
       {
          slow = slow->next;
          fast = fast->next->next;
       }
       fast = slow->next;
       slow->next = nullptr;
       slow = head;
       return merge(sortList(fast),sortList(slow));
   //注意这里是递归的，用到的是归并排序     
    
    }
   
};
```

##### 🤞leetcode-141: 环形链表

给你一个链表的头节点 `head` ，判断链表中是否有环。

```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *prev = head;
        ListNode *cur = head;
        if(!head)
        {
           return false;
        }
        while(cur!=NULL&&cur->next!=NULL)
            
      注意这里（只需要判断跑得快得那个指针就行）应该要保证cur此时不为null，cur->next才不会为空
      以及 cur->next此时不为null，cur->next->next才不会为空
            
        {
           cur = cur->next->next;
           prev = prev->next;
           if(cur==prev)
           {
              return true;
           } 
        }
        return false;
    }
};
```

##### 🤞leetcode-142: 环形链表II

给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。

 <img src="F:\C++代码资料\Fig-DS\71.png" style="zoom: 50%;" />

**注：此题与上一题的区别是只判断链表是都带环循环结束后，快慢指针不一定同时在交点上，但此题返回交点结点就用set不用快慢指针**

```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> vis;
        if(!head) return NULL;
        ListNode* flag = head;
        while(flag!=NULL)
        {
            if(vis.find(flag)!=vis.end())
            {
                return flag;
            }
            vis.insert(flag);//必须先将链表存入set再去遍历下一个节点
            flag = flag->next;  
          
            这里注意flag节点要继续向后遍历
            
        }
           return NULL;
    }
};
```

##### 剑指 Offer 06. 从尾到头打印链表

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

**示例 1：**

```
输入：head = [1,3,2]
输出：[2,3,1]
```

```c++
class Solution {
public:
    vector<int> vec;  //vector可以不进行初始化，接push_back
    vector<int> reversePrint(ListNode* head) {
          if(head)
          {
              reversePrint(head->next);
              vec.push_back(head->val);
          }
          return vec;
    }
};
```

##### 剑指 Offer 35. 复杂链表的复制

请实现 `copyRandomList` 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 `next` 指针指向下一个节点，还有一个 `random` 指针指向链表中的任意节点或者 `null`。

<img src="F:\C++代码资料\Fig-DS\92.png" style="zoom: 50%;" />

**思路：哈希表  unordered_map<Node*,Node*> hash 用来记录原链表结点与复制以后的链表的结点之间的映射，用于查找不在链表中的节点并去创建这个结点**

```c++
class Solution {
public:
    unordered_map<Node*,Node*> hash; 
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        if(!hash.count(head))
        {
          Node* newnode = new Node(head->val);
          hash[head] = newnode;
          newnode->next =  copyRandomList(head->next);
          newnode->random = copyRandomList(head->random);
        }
       return hash[head];
    }
};
```



## 哈希表

##### leetcode-387:字符串中的第一个唯一字符

给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

```
示例：
s = "leetcode"
返回 0
s = "loveleetcode"
返回 2
```

```java
class Solution {
    public int firstUniqChar(String s) {
    int[] numbers = new int [26];
    for(int i = 0; i<s.length();i++)
    {                                  //注意是'a',因为a是字符的ASCII值
       numbers[s.charAt(i) - 'a']++;  //s.charAt(i) - 'a' 相当于哈希函数将键转化为索引
    }                                //这个字母索引处的频率++
    for(int j = 0;j<s.length();j++)
    {
       if(numbers[s.charAt(j) - 'a'] == 1)
       {
           return j;
       }
    }
        return -1;
    }
}
```

##### leetcode-217：存在重复元素

给定一个整数数组，判断是否存在重复元素。

如果存在一值在数组中出现至少两次，函数返回 `true` 。如果数组中每个元素都不相同，则返回 `false` 。

```java
class Solution {
    private HashMap<Integer,Integer> res = new HashMap<>();
    public boolean isContain(int []nums)
    {
      for(int i = 0; i<nums.length; i++) //取数组长度可以直接用 .length，而字符串是 .length()
       {
           if(res.containsKey(nums[i]))  //HashMap键值对看是否包含元素用containsKey
                                        //看集合大小用 res.keySet.size()
           {
                  return true; 
           }
          res.put(nums[i],nums[i]);
       }
       return false;
    }
    
    public boolean containsDuplicate(int[] nums) {
        return  (new Solution()).isContain(nums) == true ? true : false;
    } 
}
```

```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> hash;
        for(int i =0;i<nums.size();i++)
        {
            if(hash.find(nums[i])!=hash.end())
            {
                return true;
            }
            hash.insert({nums[i],i});
        }
        return false;
    }
};
```

##### 🤞leetcode-1:两数之和

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

**暴力解法枚举：**

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
      HashMap<Integer,Integer> res = new HashMap<>();
      for(int i = 0;i<nums.length;i++)
      {
         res.put(i,nums[i]);
      }
      for(int j = 0;j<nums.length;j++)
      {
        for(int k =0;k<nums.length;k++)
        {
           if(j==k)
           {
                continue;
           }
           if(res.get(j)+res.get(k)==target)
           {
                int[] numbers = {j,k}; 
                return numbers;
           }
        }
      } 
      return new int[0];
    }
}
```

**使用哈希表将时间复杂度降至O(1)**

**总结：利用了哈希表时间复杂度为O（1）的性质，可以利用哈希表快速查找到相加为target的元素，获取其索引**

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
      HashMap<Integer,Integer> res = new HashMap<>();
     for(int i = 0;i<nums.length;i++)   
     {
         if(res.containsKey(target - nums[i]))
     //没放入一个key值，都用containsKey（）接口查找有没有元素与nums[i]加起来等于target的元素
         {
             return new int[] {res.get(target - nums[i]),i};
         }
         res.put(nums[i],i);
    //巧妙利用哈希表将nums[i]作为键，i作为val。这样可以通过键nums[i]获得索引的数值
     }
       return new int [0];  //返回数组值为空
}
}
```

~~~c++
**c++:**

**注：c++中哈希表的find返回的是指向的（指针）迭代器，指向的是key；如果哈希表中没有find到这个key，则返回一个指向end（）的迭代器**

**insert（{ ，}）；**

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hashtable;
        vector<int> vec;
        for(int i = 0;i<nums.size();i++)
        {
            if(hashtable.find(target-nums[i])!=hashtable.end())
            {
               auto it = hashtable.find(target-nums[i]);
               vec.push_back(i);
               vec.push_back(it->second);
                return vec;
            }
           hashtable.insert({nums[i],i});
        }
        return vec;
    }
};
```
~~~

```java

```

##### **🤞BM50** **两数之和**

给出一个整型数组 numbers 和一个目标值 target，请在数组中找出两个加起来等于目标值的数的下标，返回的下标按升序排列。

（注：**返回**的数组下标从1开始算起，保证target一定可以由数组里面2个数字相加得到）

数据范围：2\leq len(numbers) \leq 10^52≤*l**e**n*(*n**u**m**b**e**r**s*)≤105，-10 \leq numbers_i \leq 10^9−10≤*n**u**m**b**e**r**s**i*≤109，0 \leq target \leq 10^90≤*t**a**r**g**e**t*≤109

要求：空间复杂度 O(n)*O*(*n*)，时间复杂度 O(nlogn)*O*(*n**l**o**g**n*)

输入：

```
[3,2,4],6
```

返回值：

```
[2,3]
```

说明：

```
因为 2+4=6 ，而 2的下标为2 ， 4的下标为3 ，又因为 下标2 < 下标3 ，所以返回[2,3]            
```



```c++
class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        map<int,int> hash;
        vector<int> res;
        for(int i = 0;i<numbers.size();i++)
        {
            if(hash.find(target-numbers[i])!=hash.end())
            {
                res.push_back(hash[target-numbers[i]]+1);
                res.push_back(i+1);
            }
            else
            {
               hash[numbers[i]] = i; 
            }
        }
        return res;
        
    }
};
```

#### [242. 有效的字母异位词](https://leetcode.cn/problems/valid-anagram/)

难度简单648

给定两个字符串 `*s*` 和 `*t*` ，编写一个函数来判断 `*t*` 是否是 `*s*` 的字母异位词。

**注意：**若 `*s*` 和 `*t*` 中每个字符出现的次数都相同，则称 `*s*` 和 `*t*` 互为字母异位词。

**示例 1:**

```
输入: s = "anagram", t = "nagaram"
输出: true
```

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
         for(int i = 0;i<s.size();i++)
         {
             record[s[i]-'a']++;
         }
         for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                return false;
            }
        }
        // record数组所有元素都为零0，说明字符串s和t是字母异位词
        return true;
    }
    
};
```



##### leetcode-594最长和谐子序列

和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。

现在，给你一个整数数组 nums ，请你在所有可能的子序列中找到最长的和谐子序列的长度。

数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。

**总结：利用了哈希表擅长处理 <u>频率</u> 的相关问题的特点，使用哈希表计算出k与k+1子序列的频率**

```java
ass Solution {
     public int findLHS(int[] nums) {
    HashMap<Integer,Integer> res = new HashMap<>();
    int number = 0;
    for(int i = 0;i<nums.length;i++)  //返回的是一个序列的长度，所以把长度放在value处
    {
      res.put(nums[i],res.getOrDefault(nums[i],0)+1); 
       //这里val代表的频率需要在put的时候就要记录好，put以后没有其他操作能改
      //getOrDefault（）方法：得到哈希表的键为nums[i]的元素的val值，如果还没有val就令为0
    }
   for(int k:res.keySet())
   {   
       if(res.containsKey(k+1))  //需要先保证有k+1这个键才能get(k+1)
       {
           number = Math.max(number,res.get(k)+res.get(k+1));
        //get(k)与res.get(k+1)代表着取出来的两个键相差1，拿出所有相差1的键去比较，取最大的value
       //a = Math.max(a , .....)不断比较出一组数中最大的一个值
       }
    }
   return number;
}
}
```

```c++
class Solution {
public:
    int findLHS(vector<int>& nums) {
     map<int,int> hash;
     int res = 0;
    for(int num:nums)   //c++中for each可对vector进行
    {
       hash[num]++;
    } 
    for(auto[key,val]:hash)  //c++中利用auto进行的for each循环
    {
       if(hash.count(key+1)>0)   
       {
          res = max(res,val+hash[key+1]);
       }
    }
       return res;

    }
};
```

##### leetcode-594最长连续序列

给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

 示例 1：

```
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
```

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> num_set = new HashSet<Integer>();  //可以使用set去重复
        for (int num : nums) {
            num_set.add(num);
        }

        int longestStreak = 0;

        for (int num : num_set) {
            if (!num_set.contains(num - 1)) {  //找到这个集合中连续数列最小的那个
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.contains(currentNum + 1)) { 
                    currentNum += 1;         //通过最小的遍历寻找其他比它大的
                    currentStreak += 1;
                }

                longestStreak = Math.max(longestStreak, currentStreak);
            }         //比较所有连续数列集合的最长的数列
        }

        return longestStreak;
    }
}
```

**总结：**

HashSet的方法：

      contains（）
    
     add（）


​     
​      clear()
​    
​      从此 set 中移除所有元素。
​    
​      clone()
​    
​      返回此 HashSet 实例的浅表副本：并没有复制这些元素本身。
​    
​      isEmpty()


      如果此 set 不包含任何元素，则返回 true。
    
      Iterator<E> iterator()
    
      返回对此 set 中元素进行迭代的迭代器。
    
      remove(Object o)
    
      如果指定元素存在于此 set 中，则将其移除。
    
      size()
    
      返回此 set 中的元素的数量（set 的容量）。

​     HashSet可以用来去重复
​    
​     当一组连续数列无从下手时我们可以从最小值一端进行递增遍历

**c++**

```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         sort(nums.begin(),nums.end());
         int res = 1,ans = 1;    //最少得是1
         if(nums.empty()) return 0; 
         for(int i = 1;i<nums.size();i++)
         {
            if(nums[i-1]==nums[i]-1)
            {
               res++;
               ans= ans>res? ans:res;  //实时记录最大连续数组
            }
            else if(nums[i-1]==nums[i])
            {
              continue;
            }
            else
            {
                res = 1;
            }
            
         }
         return ans;
    }
};
```

##### leetcode-594 无重复字符的最长子串

给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

<img src="F:\C++代码资料\Fig-DS\37.jpg" style="zoom:33%;" />

```
示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int i = 0,j = 0,ans = 0;
        while(j < s.size())
        {
            if (map.find(s[j]) != map.end()&&i <= map[s[j]]) // 如果这个窗口存在相同元素
                i = map[s[j]] + 1; 
    //如果之前的字符串中包含这个元素,缩小窗口,将左指针右移
            if (j - i + 1 > ans) // 判断窗口的长度是否大于结果集
                ans = j - i + 1; // 记录结果
            map[s[j]] = j; // 覆盖元素位置
 //如果不含有相同元素，向map中插入元素，含有相同元素，将原先的部分的val值覆盖
            j++;
        }
        return ans;
    }
};
```

```c++

```

##### leetcode-560 和为k的子数组

给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

```
示例 1：
输入：nums = [1,1,1], k = 2
输出：2
```

```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> hash;
        hash[0] = 1;
        int pre = 0;
        int count = 0;
        for(auto num:nums)
        {
           pre = pre+num;
     //哈希表中装载的是一个nums的前缀和
           if(hash.find(pre-k)!=hash.end())
           {
              count += hash[pre-k];  
    //多个元素为0的情况，对应key的val值不一定为1，那么这个key所组成和为k的数组一定有多种
           }
           hash[pre]++; 
      //不能写等于1，要考虑到哈希表中有多个元素为0的情况，对应key的val值不一定为1
        }
        return count;
    }
};
```

##### leetcode-448  找到数组中消失的数字

给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。

```
示例 1：
输入：nums = [4,3,2,7,8,2,3,1]
输出：[5,6]
```

**题目中说长度为n的nums数组的所有整数都在范围[1, n]内，要找出所有消失的整数。那么可以让每个数字各就各位，使得nums[i] = i + 1。第二次遍历时候没有符合这个条件的就是消失的数字，都加入到res中即可**

```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> vec;
         for(int i =0;i<nums.size();i++)
         {
             while(nums[i]!=nums[nums[i]-1])
             {
                 swap(nums[i],nums[nums[i]-1]);
             }
        //相当于不断循环交换数组链表的相邻的两个结点，最后会保证nums[i]==nums[nums[i]-1]
         }
         for(int i =0;i<nums.size();i++)
         {
            if(nums[i]!=i+1)
            {
               vec.push_back(i+1);
            } 
          //再选出不合规则nums[i]==i+1但满足nums[i]==nums[nums[i]-1]的结点
         return vec;
    }
};
```

##### leetcode-49  字母异位分组

给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。

```
示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> hash;
      //设计出一个key为排序字符串后的key，data为排序字符串前的字符串集合
        vector<vector<string>> vec;
        for(int i = 0;i<strs.size();i++)
        {
            string key = strs[i]; 
            sort(key.begin(),key.end());
            hash[key].emplace_back(strs[i]); 
        }
        for(auto it = hash.begin();it!=hash.end();it++)
        { 
             vec.emplace_back(it->second);
        }
        return vec;
    }
};
```

##### leetcode-169:多数元素

给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

```c++
示例 1：
输入：nums = [3,2,3]
输出：3
```

擂台方法：哈希表记录每一次大于上一个的元素

```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
         map<int,int> hash;
         int ans = 0;
         int cnt = 0;
         for(int i = 0;i<nums.size();i++)
         {
             hash[nums[i]]++;
            if(hash[nums[i]]>ans)
            {
               ans = hash[nums[i]];
               cnt = nums[i];
            }
         }
         return cnt;
    }
};
```

##### leetcode-347:前k个高频元素

给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

```
示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
```

```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         map<int,int> map;
        for(auto& num:nums)
        {
           map[num]++;
        }
        struct mycomp
        {
        bool operator()(pair<int,int>& p1,pair<int,int>& p2)        
           {return  p1.second>p2.second;  }    //小顶堆适配器比较是大于号
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,mycomp> q;
   //将map中的pair依次存入堆中，小顶堆堆按key的频率比较大小
        for(auto& a:map)
        {
            q.push(a);
    //如果堆中元素为k+1个，则第k+1个频率最小的元素一定在堆顶，则弹出堆。不断循环到最后保证堆中的k个元素为频率前k大的元素
            if(q.size()>k)
            {
              q.pop();
            }
        }
       vector<int> res;
        while(!q.empty())
        {
           res.push_back(q.top().first);
           q.pop();
        }
        return  res; 
    }

};
```

##### leetcode-438. 找到字符串中所有字母异位词

给定两个字符串 `s` 和 `p`，找到 `s` 中所有 `p` 的 **异位词** 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

**异位词** 指由相同字母重排列形成的字符串（包括相同的字符串）。

**示例 1:**

```
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
```

```c++
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vecS(26);
        vector<int> vecP(26);
        vector<int> ans;
         int slen = s.size();
         int plen = p.size();    
        if(slen<plen)
         {
            return vector<int>();
         }
         for(int i = 0;i<p.size();i++)
         {
             vecS[s[i]-'a']++;
             vecP[p[i]-'a']++;
         }
   
         if(vecS==vecP)
         {
            ans.push_back(0);
         }
//在统计完p与s字符串得子集后，对于使用一个长度为plen大小得滑动窗口，从左到右滑动，统计字母出现的频次匹配字符串     
         for(int i =0;i<slen-plen;i++)
         {
             vecS[s[i]-'a']--;
             vecS[s[i+plen]-'a']++;
             if(vecS==vecP)
             {
               ans.push_back(i+1);
             }
         }
         return ans;
         
    }
};
```

##### leetcode-149. 直线上最多的点数

给你一个数组 `points` ，其中 `points[i] = [xi, yi]` 表示 **X-Y** 平面上的一个点。求最多有多少个点在同一条直线上。

**示例 1：**

```
输入：points = [[1,1],[2,2],[3,3]]
输出：3
```

**思路：使用哈希表，枚举出记录 每个点与其他点 的斜率，每枚举完一个点后清除整个哈希表（避免重复）再去枚举下一个点与其他点 的斜率**

```c++
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        if(len==1) return 1; //单独的点返回1
        if(len<3)  //总长度小于三个点，直接返回2
        {
           return 2;
        }
        int res = 0;
        for(int i = 0;i<len;i++)
        {
           unordered_map<double,int> hash; 
           for(int j = 0;j<len;j++)
           {
              if(i!=j)
              {
                 long long dx = points[i][0] - points[j][0]; 
                 long long dy = points[i][1] - points[j][1];
                 double key =   dy*1.0/dx;  //这里注意要乘1.0才能把得到的int数值转换为double
                  if(hash.count(key))
                  {
                    hash[key]++;
                  }
                  else
                  {
                    hash[key]=2;
                  }
                 res = max(res,hash[key]);
              }      
           }
        }
        return res;
    }
};
```

**BM50** **两数之和**

给出一个整型数组 numbers 和一个目标值 target，请在数组中找出两个加起来等于目标值的数的下标，返回的下标按升序排列。

（注：**返回**的数组下标从1开始算起，保证target一定可以由数组里面2个数字相加得到）

数据范围：2\leq len(numbers) \leq 10^52≤*l**e**n*(*n**u**m**b**e**r**s*)≤105，-10 \leq numbers_i \leq 10^9−10≤*n**u**m**b**e**r**s**i*≤109，0 \leq target \leq 10^90≤*t**a**r**g**e**t*≤109

要求：空间复杂度 O(n)*O*(*n*)，时间复杂度 O(nlogn)*O*(*n**l**o**g**n*)

输入：

```
[3,2,4],6
```

返回值：

```
[2,3]
```

说明：

```
因为 2+4=6 ，而 2的下标为2 ， 4的下标为3 ，又因为 下标2 < 下标3 ，所以返回[2,3]            
```

```c++
class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        map<int,int> hash;
        vector<int> res;
        for(int i = 0;i<numbers.size();i++)
        {
            if(hash.find(target-numbers[i])!=hash.end())
            {
                res.push_back(hash[target-numbers[i]]+1);
                res.push_back(i+1);
            }
            else
            {
               hash[numbers[i]] = i; 
            }
        }
        return res;
        
    }
};
```



### 滑动窗口

#### leetcode-209. 长度最小的子数组

难度中等1319

给定一个含有 `n` 个正整数的数组和一个正整数 `target` **。**

找出该数组中满足其和 `≥ target` 的长度最小的 **连续子数组** `[numsl, numsl+1, ..., numsr-1, numsr]` ，并返回其长度**。**如果不存在符合条件的子数组，返回 `0` 。

**示例 1：**

```
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
```

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int i = 0;
        int len = INT32_MAX;
          for(int j = 0;j<nums.size();j++)
          {
             sum = sum + nums[j];
             while(sum>=target)
             {
                len = (j-i+1<len) ? j-i+1:len;
                sum -= nums[i++];      
             }

          }
           return len==INT32_MAX ? 0:len ;
    }
};
```

#### leetcode-239. 滑动窗口最大值

难度困难1690

给你一个整数数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 `k` 个数字。滑动窗口每次只向右移动一位。

返回 *滑动窗口中的最大值* 。

**示例 1：**

```
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**使用堆**：

```c++
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         priority_queue<pair<int,int>> q;
          //默认是大顶堆
         vector<int> vec;
         int n  = nums.size();
        //遍历小于滑动窗口大小范围得到堆中数据
         for(int i=0;i<k;i++)
         {
            q.emplace(nums[i],i);
         }
         vec.push_back(q.top().first);
         for(int i = k;i < n;i++)
         {
            q.emplace(nums[i],i);
   //将堆中在滑动窗口外得最大值弹出，有可能有多个大值在窗口外，在滑动窗口内不是最大值得数对整体无影响
            while(q.top().second<=i-k)
       //使用while是因为在滑动窗口移动过程中可能出现移动一步出现两个最大值情况
            {
                q.pop();
            }
           //取得滑动窗口内的最大值
            vec.push_back(q.top().first);
         }
         return vec;
    }
};
```

#### leetcode-76. 最小覆盖子串

给你一个字符串 `s` 、一个字符串 `t` 。返回 `s` 中涵盖 `t` 所有字符的最小子串。如果 `s` 中不存在涵盖 `t` 所有字符的子串，则返回空字符串 `""` 。

**注意：**

- 对于 `t` 中重复字符，我们寻找的子字符串中该字符数量必须不少于 `t` 中该字符数量。
- 如果 `s` 中存在这样的子串，我们保证它是唯一的答案。

**示例 1：**

```
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
```

**思路：**

**先得到最小窗口得大小，cnt记录遍历得string s存入到的哈希表是否达到窗口t_hash.size();的大小。**

**同时再不断去收缩窗口得左边界。**

**最后不断截取收缩的最小的窗口，如果string t首尾两个字符出现在s的一头一尾，则条件应改为cnt==k时截取整个t**

```c++
class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char,int> t_hash;
       unordered_map<char,int> hash_s ;
       int n = s.size();
      
       string res="";
       for(auto c:t)
       {
         t_hash[c]++;
       }
        int k = t_hash.size();
       for(int i =0,j = 0,cnt=0;i<n;i++)
       {
           if(++hash_s[s[i]]==t_hash[s[i]])
           {
               cnt++;
           }
   
           while(hash_s[s[j]]>t_hash[s[j]])
           {
               hash_s[s[j++]]--;
           }
           if(cnt==k)
           { 
              if(res.empty()||(i-j+1)<res.size())
              {
                res = s.substr(j,i-j+1);
              }
           }
       }
       return res;
    }
};
```

**易出问题点：**

<img src="F:\C++代码资料\Fig-DS\91.png" style="zoom:50%;" />

#### [剑指 Offer 57 - II. 和为s的连续正数序列](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/)

难度简单463

输入一个正整数 `target` ，输出所有和为 `target` 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

**示例 1：**

```
输入：target = 9
输出：[[2,3,4],[4,5]]
```

**思路：设连续正整数序列的左边界 ii 和右边界 jj ，则可构建滑动窗口从左向右滑动。循环中，每轮判断滑动窗口内元素和与目标值 targettarget 的大小关系，若相等则记录结果，若大于 targettarget 则移动左边界 ii （以减小窗口内的元素和），若小于 targettarget 则移动右边界 jj （以增大窗口内的元素和）。**

**初始化： 左边界 i=1 ，右边界 j = 2，元素和s=3 ，结果列表 res ；**

**循环： 当 i≥j 时跳出；**

**当s>target 时： 向右移动左边界 i=i+1 ，并更新元素和 s ；**
**当s<target 时： 向右移动右边界 j=j+1 ，并更新元素和 s ；**
**当s=target 时： 记录连续整数序列，并向右移动左边界 i=i+1 ；**
**返回值： 返回结果列表 res ；**

```c++
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
         int i = 1 ,j = 2, s =3;
         vector<vector<int>> res;
         while(i<j)
         {
            if(s==target)
            {
                vector<int> ans;
                for(int k = i;k<=j;k++)
                {
                   ans.push_back(k);
                }
                 res.push_back(ans);
            }
            if(s>=target)
            {
                s-=i;
                i++;
            }
            if(s<target)
            {
               j++;
               s+=j;
            }
         }
         return res;
    }
};
```

### 桶思想

##### leetcode-621:任务调度器

给你一个用字符数组 tasks 表示的 CPU 需要执行的任务列表。其中每个字母表示一种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。在任何一个单位时间，CPU 可以完成一个任务，或者处于待命状态。

然而，两个 相同种类 的任务之间必须有长度为整数 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。

你需要计算完成所有任务所需要的 最短时间 。

```
示例 1：
输入：tasks = ["A","A","A","B","B","B"], n = 2
输出：8
解释：A -> B -> (待命) -> A -> B -> (待命) -> A -> B
     在本示例中，两个相同类型任务之间必须间隔长度为 n = 2 的冷却时间，而执行一个任务只需要一个单位时间，所以中间出现了（待命）状态。
```

**思路：**

https://leetcode.cn/problems/task-scheduler/solution/tong-zi-by-popopop/

**最后一种情况：桶已经被排满**

<img src="F:\C++代码资料\Fig-DS\84.png" style="zoom:50%;" />

**也就是说，我们执行任务所需的时间，就是任务的数量**

所以，最后返回值只需要计算两个数的大小： 

1.在未达到桶的最大容量时，需要包含冷却时间，所以  此时任务的数量 <  (n+1)*(mamax-1)+cnt（即计算冷却时间的值），所以取最大值才是正确的值

2.达到桶容纳的最大数量以后，就是最后一种情况，执行任务时间就是任务的数量，这时最大值是 任务的数量，为最终正确的结果

```c++
class Solution {
public:
       
    int leastInterval(vector<char>& tasks, int n) {
         int len = tasks.size();
         if(n==0||len==0) return len;
          vector<int> vec(26);
          int mamax = 0;
         for(char c:tasks)
         {
             vec[c-'A']++;
             mamax = max(mamax,vec[c-'A']);
         }
          int cnt = 0;
          for(int i=0;i<26;i++)
          {
              if(vec[i]==mamax)
              {
                  cnt++;
              }
          }
          return  max(len,(n+1)*(mamax-1)+cnt);

    }
};
```

## 栈与队列

##### leetcode-20:用栈实现队列匹配

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。

```
示例 1：

输入：s = "()"
输出：true

```

```java
import java.util.Stack;
class Solution {
    public boolean isValid(String s) {
        Stack<Character> res = new Stack<>();
        for(int i =0;i<s.length();i++)
        {
            char selectChar = s.charAt(i); 
            if(selectChar == '('||selectChar =='{'||selectChar =='[')
            {
                res.push(selectChar);
            }
           else
           {
               if(res.isEmpty())         //先来直接判断栈是否为空
               {
                     return false;
               }
                char charTop = res.pop(); //用来弹出栈顶元素，并且根据弹出的元素做判断
               if(selectChar ==')' && charTop!='(')
               {
                      return false;
               }
                if(selectChar ==']' && charTop!='[')
               {
                      return false;
               }
                if(selectChar =='}' && charTop!='{')
               {
                      return false;
               }
           }

        }
        //  直接return true是不对的，如果输入"[，{，[，],}";则栈中还有字符，则不匹配
        return res.isEmpty();   //所以应该以 res是否为空来进行判断
    }  //匹配要保证栈里没有剩余元素，所有元素匹配完毕
}
```

```c++
class Solution {
public:
    bool isValid(string s) {
       stack<int> stk;
       for(int i = 0;i<s.size();i++)
       {
          if(s[i]=='('||s[i]=='{'||s[i]=='[')
          {
              stk.push(s[i]);
          }
          else
          {
              if(stk.empty())
              {
                return false;
              }
              int topnum = stk.top();
              stk.pop();
              if(topnum=='['&&s[i]!=']')
              {
                   return false;
              }
              if(topnum=='('&&s[i]!=')')
              {
                   return false;
              }
              if(topnum=='{'&&s[i]!='}')
              {
                  return false;
              }
           }
                 

       }
       return stk.empty();
      //如果只输入一个‘【’，则最后只要判断栈是否为空就可以了，不为空就是false
    }
};
```

<img src="F:\C++代码资料\Fig-DS\28.jpg" style="zoom: 25%;" />

##### 🤞leetcode-232:用栈实现队列

**（把测试用例的过程调试，或用未通过的测试用例在代码里走一遍流程）**

请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false

Stack 操作：

.isEmpty（）， 判断是否为空

 .size()           ,得到栈大小

```java
class MyQueue {
     /** Initialize your data structure here. */
     private Stack<Integer> res1; //输入栈
     private Stack<Integer> res2; //输出栈,整数是Integer
     //要先声明成员变量再使用构造函数初始化
   
    public MyQueue() {  
     res1 = new Stack<>();
     res2 = new Stack<>();
      
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {  //入队
      res1.push(x);
     }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {     //出队
    // int size = res1.size();   //这里获得栈的长度要用size（）
    //  for(int i=0;i<size;i++)  //为什么使用size遍历方法不通过？
         //因为如果经过两次pop，在一次push后输入栈中的元素就空了
        //因为如果经过两次peek，在一次peek后输入栈中的元素就空了，所以此处缺少 if(res2.isEmpty())           条件判断输入栈为空
    //  {
    //    int k = res1.pop();
    //     res2.push(k); 
    // }
    //   return res2.pop();
       if(res2.isEmpty())  //在输出栈为空情况下，将所有输入栈元素压入输出栈
       {
           while(!res1.isEmpty())
           {
               res2.push(res1.pop());
           }
       }
        return res2.pop();
    }
    
    /** Get the front element. */
    public int peek() {       //获得队首元素
     //  int size = res1.size();  //为什么使用size遍历方法不通过？
         //因为如果经过两次peek，在一次peek后输入栈中的元素就空了，所以此处缺少 if(res2.isEmpty())           条件判断输入栈为空
    //   for(int i=0;i<size;i++)
    //   {
    //      int k = res1.pop();
    //      res2.push(k); 
    //   }
    //     return res2.peek();
      if(res2.isEmpty())
      {
         while(!res1.isEmpty())
         {
             res2.push(res1.pop());
         }
      }
     return res2.peek();
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return res1.isEmpty() && res2.isEmpty();  //两个栈同时为空才算为空
                        //因为当把所有元素压入输出栈进行pop操作以后，输入栈就为空了
    }
}
```

```c++
class MyQueue {
public:
   stack<int> inStk;
   stack<int> outStk;
    MyQueue() {

    }
    
    void push(int x) {
        inStk.push(x);
    }
    
    int pop() {
       int topnum;
       if(outStk.empty())  
   //一顶在outstk为空时，再把instk中的数值压入outstack，否则就是之前入out栈的老元素还没有清空就会被新进来得元素覆盖掉栈顶的元素
       {
    //这里判断是否题干有要求队列为空时执行pop返回-1        
         while(!inStk.empty())
        {
          topnum = inStk.top(); 
          outStk.push(topnum);
          inStk.pop();
        }
       }
       
       topnum = outStk.top();
       outStk.pop();
      return topnum;
    }
    
    int peek() {
        int num;
        if(outStk.empty()) 
      //在instk非空时，outstk为空了，也要返回队首元素，所以还是要把instk中得值压入栈中
        {
    //这里判断是否题干有要求队列为空时执行peek返回-1        
           while(!inStk.empty())
        {
          num = inStk.top(); 
          outStk.push(num);
          inStk.pop();
        }
        }
         return outStk.top();
    }
    
    bool empty() {
          if(inStk.empty()&&outStk.empty())
          {
              return true;
          }
          return false;
    }
};
```

##### leetcode-225:用队列实现栈

请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：

void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

**使用单队列实现**

LinkedList中的remove方法：删除尾节点

LinkedList中的add方法：向链表添加尾节点

LinkedList中的isEmpty（）方法：判断链标是否为空

LinkedList中的peek（）方法：获取链表中的最后一个元素

```java
class MyStack {

    /** Initialize your data structure here. */
    private Queue<Integer> Queue1;
    
    public MyStack() {
        Queue1 = new LinkedList<Integer>();
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        Queue1.add(x);                     //先在队列尾添加一个节点
        for(int i = 1;i<Queue1.size();i++)
        {
         Queue1.add(Queue1.remove());     //在对队列尾处的结点进行n-1次的出队和入队，这时元素出现                                             在队首
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
       return  Queue1.remove();    //移除最新入队的元素，也就是栈顶元素
    }
    
    /** Get the top element. */
    public int top() {
      return Queue1.peek();        //查看最新入队的元素，也就是栈顶元素
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
      return Queue1.isEmpty();
    }
}
```

**总结：linkedlist的结构和操作类似于栈（stack）**

```c++
class MyStack {
public:
    MyStack() {

    }
    queue<int> que ;
    void push(int x) {
        que.push(x);
        while(que.front()!=x)
        {
          que.push(que.front());
          que.pop();
        }
    }
    
    int pop() {
        int res = que.front();
       if(!que.empty())
       {
           que.pop();
       }
       return res;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
         return que.empty();
    }
};

```

##### leetcode-155：最小值栈

设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。

```java
class MinStack {
    private Node head;
                                  //做题思路,先像链表那章题一样定义一个Node类，
                                 //要分两种情况分别定义两种构造函数，一种是当第一次插入时，之后的插                                 入都是插在第一次之前的，所以第一次插入的节点不需要next指针
                                  //使用头插法，每添加一个元素，在链表头结点前添加一个节点
                                  //这个结点包含min:整个链表的最小值，以及自身val
                                 // 出队直接令head = head.next;移动头结点指针
    
    public void push(int x) {
        if(head == null)         
            head = new Node(x, x);
        else 
            head = new Node(x, Math.min(x, head.min), head);
    }            //巧妙利用math包中的min方法求最小值

    public void pop() {
        head = head.next;
    }

    public int top() {
        return head.val;
    }

    public int getMin() {
        return head.min;
    }
    
    private class Node {
        int val;
        int min;
        Node next;
        
        private Node(int val, int min) {
            this(val, min, null);
        }
        
        private Node(int val, int min, Node next) {
            this.val = val;
            this.min = min;
            this.next = next;
        }
    }
}
```

```c++
class MinStack {
public:
    MinStack() {
        minstk.push(INT_MAX);  
        //注意注意！！这里要与最小值栈中的数值比较，一开始一定要先push进最大的数
    //对最小值辅助栈的操作，应该在构造函数里push进INT_MAX
    }
    stack<int> stk;
    stack<int> minstk;
    
    void push(int val) {
    stk.push(val);
     if(val<minstk.top())
     {
        minstk.push(val);
     }
     else
     {
      minstk.push(minstk.top());
     }
   }
    
    void pop() {
     if(!stk.empty())
     {
      stk.pop();
      minstk.pop();
     }
      
    }
    
    int top() {
       return stk.top();
    }
    
    int getMin() {
         return minstk.top();
    }
};
```

##### leetcode-739：数组中元素与下一个比它大的元素之间的距离

请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

**错误代码   原因： 没考虑到两日温度一样的情况**

```java
 //错误代码 ：
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
     HashMap<Integer,Integer> res = new HashMap<>();
      
     for(int i = 0; i<temperatures.length;i++) //记录从当前温度到下一个循环的元素个数
     {    
         int cnt = 0;
          for(int j = i ;temperatures[i]>=temperatures[j]&&j<temperatures.length-1;j++)
          {
             cnt++;
           }
         res.put(temperatures[i],cnt);
     }
     int[] numbers = new int[res.keySet().size()];  //将哈希表中的数值放在数组中
     for(int i = 0;i<numbers.length;i++)
     {
          numbers[i] = res.get(temperatures[i]);   //错误原因： 没考虑到两日温度一样的情况
     }
      return numbers;
    }
}
```

**正确答案：单调栈**

```java
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
     Stack<Integer> inputStack = new Stack<>();
     int []numbers = new int[temperatures.length]; 
     for(int i = 0;i<temperatures.length;i++)
     {
         int temperature = temperatures[i];
        while(!inputStack.isEmpty()&&temperature>temperatures[inputStack.peek()])
         {   
 //在栈非空时判断下一个要压入栈中的元素是否依次比栈顶元素及栈顶以下元素值大，大的话则将栈顶元素弹出，取索引    之差，再将下一个比temperature小的元素弹出，取差值
             int temp = inputStack.pop();
             int preNode = i - temp;
             numbers[temp] = preNode; 
            //将差值赋值在被弹出的栈顶元素的索引处（输入输出数组长度相同）
         }
         inputStack.push(i);   //注意这里在栈里存储的为temperatures温度数组的索引
     }
         return numbers;
    }
}
```

```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      stack<int> stk;
      const int n = temperatures.size();
      vector<int> vec(n,0);
      for(int i = 0;i<n;i++)
      {
          while(!stk.empty()&&temperatures[i]>temperatures[stk.top()])
          {
            int prev = stk.top();
            stk.pop();
             vec[prev] = i-prev;
          }
        stk.push(i);
      }
      return vec;
    }
};
```

**栈中元素都对应tempture中的索引**

##### leetcode-739：循环数组中比当前元素大的下一个元素

给定一个循环数组 nums （ nums[nums.length - 1] 的下一个元素是 nums[0] ），返回 nums 中每个元素的 下一个更大元素 。

数字 x 的 下一个更大的元素 是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1 。

```
示例 1:
输入: nums = [1,2,1]
输出: [2,-1,2]
解释: 第一个 1 的下一个更大的数是 2；
数字 2 找不到下一个更大的数； 
第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
```

```java
class Solution {
    public int[] nextGreaterElements(int[] nums) {
         Stack<Integer> input = new Stack<>();
         int []numbers = new int[nums.length];
         Arrays.fill(numbers,-1);
         for(int i = 0;i<nums.length*2-1;i++)
         {
  //其实如果是循环数组这种情况，拿出最极端情况（原数组中的数字递减）可以看成是最多遍历了两遍的正常数组
            while(!input.isEmpty() && nums[i%(nums.length)]>nums[input.peek()])
            {
              int index = input.pop();
              numbers[index] = nums[i%(nums.length)];
            }
              input.push(i%(nums.length));
   //因为是循环数组一直在循环，所以栈中要一直push
        }
        return numbers;
    }
}
```

```c++
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> stk;
    const int res = nums.size();
    vector<int> vec(res,-1);
    for(int i=0;i<2*nums.size();i++)
    {
        while(!stk.empty()&&nums[i%res]>nums[stk.top()])
        {
           int first = stk.top(); 
           stk.pop();
           vec[first] = nums[i%res];
        }
        stk.push(i%res);
    }
    return vec;
    }
};
```

##### 剑指 Offer 31. 栈的压入、弹出序列

难度中等368

输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

**示例 1：**

```
输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
```

```c++
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
         stack<int> stk;
         int i = 0;
         for(int e:pushed)
         {
           stk.push(e);
           while(!stk.empty()&&stk.top()==popped[i])
            {
               stk.pop();
               i++;
            }   
        }
        return stk.empty();  
    }
};
```

##### **leetcode-42：接雨水**

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

**使用单调栈**

```
示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
```

```c++
class Solution {
public:
    int trap(vector<int>& height) {
       stack<int> stk; 
       int ans = 0;
       for(int i = 0;i<height.size();i++)
       {
          while(!stk.empty() && height[i]>height[stk.top()])
          {
              int cur = stk.top();
              stk.pop();
              if(stk.empty()) break;
              int l =stk.top();
              int r = i;    
              int h = min(height[l],height[r])-height[cur];
              ans+= (r-l-1)*h;
          }
          stk.push(i);
       }
             return  ans;
    }
};
```

##### 剑指 Offer 59 - II. 队列的最大值

难度中等376

请定义一个队列并实现函数 `max_value` 得到队列里的最大值，要求函数`max_value`、`push_back` 和 `pop_front` 的**均摊**时间复杂度都是O(1)。

若队列为空，`pop_front` 和 `max_value` 需要返回 -1

**示例 1：**

```
输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
```

```c++
class MaxQueue {
private:
deque<int> due;  
queue<int> que;
public:
    MaxQueue() {

    }
    
    int max_value() {
       if(due.empty()) return -1;
       return due.front();
    }
    
    void push_back(int value) {
         while(!due.empty()&&value>due.back())  due.pop_back();
         due.push_back(value);
         que.push(value);
    }
    
    int pop_front() {
        if(que.empty()) return -1;  //注意pop要判断空
         int ans = que.front();
         if(ans==due.front()) due.pop_front();
         que.pop();
         return ans;
    }
};

```

##### leetcode-394. 字符串解码

给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: `k[encoded_string]`，表示其中方括号内部的 `encoded_string` 正好重复 `k` 次。注意 `k` 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 `k` ，例如不会出现像 `3a` 或 `2[4]` 的输入。

**示例 1：**

```
输入：s = "3[a]2[bc]"
输出："aaabcbc"
```

```c++
class Solution {
public:
    string decodeString(string s) {
       int lenS = s.size();
       stack<int> numstk;
       stack<string> strstk;
       int num = 0;
       string str =""; 
      for(int i = 0;i<lenS;i++)
      { 
          if(s[i]>='0'&&s[i]<='9')
          {
            num = num * 10 + (s[i] - '0');
          }
         else if(s[i]=='[')
          {
            numstk.push(num);
            strstk.push(str);
            str="";
            num = 0;
          }
  //如果是匹配到‘]’，先将‘[’之前得字符与数字先出栈，数字是多少则‘[’之前得字符就要加几次‘[]’内的字符
          else if(s[i]==']')
          {
            int numtop = numstk.top();
            numstk.pop();
            while(numtop>0)
            {
              strstk.top()+=str;
              numtop--;
            }  
            str = strstk.top();
            strstk.pop();
          }
          else
          {
            str+=s[i]; //‘[]’内的字符
          }
      }
      return str;
    }
};
```

##### leetcode-84. 柱状图中最大的矩形

给定 *n* 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

<img src="F:\C++代码资料\Fig-DS\90.png" style="zoom: 50%;" />

**单调栈**

<img src="F:\C++代码资料\Fig-DS\33.jpg" style="zoom: 33%;" />

```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
         vector<int> left(n);
         vector<int> right(n);
         stack<int> stk1;
         stack<int> stk2;
         for(int i = 0;i<heights.size();i++)
         {
            while(!stk1.empty()&&heights[stk1.top()]>=heights[i])
            {
                stk1.pop();
            }
               left[i] = (stk1.empty())?-1:stk1.top();
               stk1.push(i);              
         }
         for(int i = n-1;i>=0;i--)
         {
            while(!stk2.empty()&&heights[stk2.top()]>=heights[i])
            {
                stk2.pop();
            }
               right[i] = (stk2.empty()?n:stk2.top());
               stk2.push(i);    
         }
          int res = 0;
          for(int i = 0;i<heights.size();i++)
          {
             res = max(res,(right[i]-left[i]-1)*heights[i]); 
          }
               return res;
    }
};

```

##### leetcode-85. 最大矩形

给定一个仅包含 `0` 和 `1` 、大小为 `rows x cols` 的二维二进制矩阵，找出只包含 `1` 的最大矩形，并返回其面积。

**示例 1：**

```
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：6
解释：最大矩形如上图所示。
```

**思路：同84题思路是一样的，只不过要做一个二维的遍历，对矩阵逐层生成柱状图进行更新**

```c++
class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
         vector<int> left(n);
         vector<int> right(n);
         stack<int> stk1;
         stack<int> stk2;
         for(int i = 0;i<heights.size();i++)
         {
            while(!stk1.empty()&&heights[stk1.top()]>=heights[i])
            {
                stk1.pop();
            }
               left[i] = (stk1.empty())?-1:stk1.top();
               stk1.push(i);              
         }
         for(int i = n-1;i>=0;i--)
         {
            while(!stk2.empty()&&heights[stk2.top()]>=heights[i])
            {
                stk2.pop();
            }
               right[i] = (stk2.empty()?n:stk2.top());
               stk2.push(i);    
         }
          int res = 0;
          for(int i = 0;i<heights.size();i++)
          {
             res = max(res,(right[i]-left[i]-1)*heights[i]); 
          }
               return res;
    }
   
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int result = 0;
        // 初始化单层柱状图 
        vector<int> heights(n, 0); 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 更新单层柱状图
                if (matrix[i][j] == '1') heights[j] += 1;
                else heights[j] = 0;
            }
            // 送入单调栈方法获得结果
            result = max(result, largestRectangleArea(heights));
        }
        return result;
    }
};
```

## 二叉树

##### **🤞leetcode-104：二叉树的最大深度**

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

**说明:** 叶子节点是指没有子节点的节点。

```c++
class Solution {
public:
    int maxDepth(TreeNode* root) {
          if(root==NULL)   //根节点为空，基本条件也是递归结束条件
          {
             return 0;
          }
          return max(maxDepth(root->left), maxDepth(root->right))+1;
    //递归进行深度优先搜索，深度为左右结点的深度最大的加1
    }
};
```

##### **leetcode-110：平衡二叉树**

```c++
class Solution {
public:
    bool isBalanced(TreeNode* root) {
         return nodeNumber(root)>=0;
    }
    int nodeNumber(TreeNode* root)
    {
        if(root==NULL)
        {
          return 0;
        }
        int L = nodeNumber(root->left);
        int R = nodeNumber(root->right);
        //求深度不一定要在计算L，R数值+1，计算L,R需要判断返回值是不是-1
        if(L==-1||R==-1||abs(L-R)>1)
        {
            return -1;   
            //首先判断是不是平衡树，不是平衡树，或子节点不是平衡树都要返回-1
        }
        else
        {
            //返回深度搜索得到的深度信息
            return max(L,R)+1;
        }
    }
};
```

##### **leetcode-543：二叉树的直径**

给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

因为要返回一个 **最长** 的直径所以要用  **深度搜索DFS**

```c++
class Solution {
public:
   int length;
   int depth(TreeNode* root)
   {
      if(root==NULL)  //递归终止条件
      {
         return 0;
      }
      int L = depth(root->left);    //深搜：遍历左子树 
      int R = depth(root->right);   //深搜：遍历右子树
      length = max(L+R+1,length);   //加1是因为递归回自身节点时需要把自身节点的长度也加上
      //得到整体的最长路径是将每一个根节点得到的最长路径都与上其子节点得到的最长路径比较取最值
      //得到最长路径的大小
      return max(L, R)+1 ; 
      //递归  分别返回左子树与右子树的深度
   }

    int diameterOfBinaryTree(TreeNode* root) {
        length = 0;
        depth(root);
        return length-1; 
        //-1是因为取得是路径长度，而我们算出来的是节点长度

    }
};
```

##### **leetcode-226：反转二叉树**

给你一棵二叉树的根节点 `root` ，翻转这棵二叉树，并返回其根节点。

```c++
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    if(root==NULL)
    {
       return NULL;
    }
    TreeNode *leftTree = root->left; 
    // *** 在进行反转root->right之前需要先将反转之前的root->left缓存 ***
    root->left = invertTree(root->right);
    root->right = invertTree(leftTree);
    return root;
    }
};
```

##### **leetcode-617：合并二叉树**

给你两棵二叉树： root1 和 root2 。

想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。

返回合并后的二叉树。

注意: 合并过程必须从两个树的根节点开始。

```c++
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
       if(root1==NULL)
       {
          return root2;
       }
       if(root2==NULL)
       {
          return root1;
       }
       TreeNode *node = new TreeNode(root1->val+root2->val);
       //合并必须从根节点开始，所以下面跟的是node->left，node->right
       node->left = mergeTrees(root1->left,root2->left);
       node->right = mergeTrees(root1->right,root2->right);
       return node;
    }
};
```

##### **leetcode-112：路径总和**

给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 **根节点到叶子节点** 的路径，这条路径上所有节点值相加等于目标和 targetSum 。如果存在，返回 true ；否则，返回 false 。

```c++
class Solution {
public:
    int Sum;
    bool hasPathSum(TreeNode* root, int targetSum) {
          if(root==NULL) //节点为空返回0
          {
              return 0;
          }
        if(root.left==NULL&&root.right==NULL) //叶子结点要求左右子树均为0
        {
             return targetSum == root->val;
      //终止条件：最后的叶子节点上的值是否为剩余的targetSum
        }
        return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);
    }   
   //可以向左或向右遍历完全部路径 到最后的叶子节点上，每遍历一次，targetSum值减去当前结点的值
};  //只要满足一种情况总和等于targetSum，则返回true
```

##### **leetcode-101：对称二叉树**

给你一个二叉树的根节点 `root` ， 检查它是否轴对称。

**不对称有两种情况：一个结点为NULL，另一个不为NULL时，则不是对称的**

​                                  **两个结点val值不等，也是不对称的**

```c++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       return  isEqual(root,root);
    }
    bool isEqual(TreeNode *r1,TreeNode *r2)
    {
          if(!r1&&!r2)     //递归终止条件：当两个结点都为NuLL
          {
             return true;
          }
          if(!r1||!r2)   //一个结点为NULL，另一个不为NULL时，则不是对称的
          {
             return false;
          }
         return r1->val==r2->val && isEqual(r1->left,r2->right) &&isEqual(r1->right,r2->left);
        //先判断当前两个结点是否相等，再进入递归。只要一个结点不相等，递归结束所以要用&&连接
    }
};
```

##### **leetcode-437：III路径总和**

给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

**注：这道题与DFS不同点在于，每一个点都必须作为根进行遍历**

**1.先设计一个简单的基于根节点DFS的递归记录路径的函数**

**2.再对pathSum里对每一个结点递归记录路径**

```c++
//这道题与DFS不同点在于，每一个点都必须作为根进行遍历
class Solution {
public:
    int res;  //用于存储符合条件的路径数
    int pathSum(TreeNode* root, int targetSum) {
         if(root)  //递归停止条件，递归到叶子节点时
         {
           pathNumber(root,targetSum);   //进行二次递归，针对每一个点做为根结点以及左右孩子进行DFS
           pathSum(root->right,targetSum); 
           pathSum(root->left,targetSum);
         }
            return res;
    }
    void pathNumber(TreeNode* root, int targetSum)
    {
        if(!root)
        {
            return ;
        }
        if(root->val==targetSum)
        {
           res++;
        }
        pathNumber(root->right,targetSum-root->val);
        pathNumber(root->left,targetSum-root->val);
    }
     //这里的遍历只针对每一个根节点的
};
```

##### **leetcode-572：另一棵树的子树**

给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。

二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。

```c++
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot)     //递归终止条件：如果subroot递归到了null，证明一定与root有相同子树
        {
            return true;
        }
        if(!root)   //递归终止条件：root递归到结束只有一种情况即subroot与root完全相等才正确，如果subroot没有递归到头，或是root递归到结束了也没有相同子树则返回false。
        {
            return false;
        }
         return isEqual(root,subRoot)||isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);    //subRoot为子树所以，不断从root向下（逐渐拉开距离）递归
    }
    bool isEqual(TreeNode * root , TreeNode *subRoot)
    {
         if(!root&&!subRoot)
         {
          return true;
         }
         if(!root||!subRoot||root->val!=subRoot->val)
         {
          return false;
         }
         return isEqual(root->left,subRoot->left)&&isEqual(root->right,subRoot->right);
    }   //判断结构相等isEqual(root->left,subRoot->left)&&isEqual(root->right,subRoot->right)
};
```

##### 剑指 Offer 26. 树的子结构

难度中等599

输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

`   3  / \  4  5 / \ 1  2`
给定的树 B：

`  4  / 1`
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

**示例 1：**

```
输入：A = [1,2,3], B = [3,1]
输出：false
```

**示例 2：**

```
输入：A = [3,4,5,1,2], B = [4,1]
输出：true
```

```c++
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
           if(!B)
           {
               return false;
           }
           if(!A)
           {
               return false;
           }
           return  isEqual(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
    bool isEqual(TreeNode* A, TreeNode* B)
    {
       if(!B)
       {
         return true;
       }
       if(!A||A->val!=B->val)
       {
           return false;
       }
       return isEqual(A->left,B->left)&&isEqual(A->right,B->right);
    }
};
```



##### **leetcode-111：二叉树的最小深度**

给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

**说明：**叶子节点是指没有子节点的节点。

**两种情况： 1. 左右结点都有，则返回值需要比较左子树与右子树返回一个最小的加1**

​                    **2.只有一个孩子结点有值，则返回有数值的那个孩子结点数加1**

​                   

```c++
class Solution {
public:
    
    int minDepth(TreeNode* root) {
        if(!root)
        {
            return 0 ;
        }
        int L = minDepth(root->left);
        int R = minDepth(root->right);
        
        return  (root->left)&&(root->right) ?min(L,R)+1:L+R+1 ;
    }      //两种情况： 1. 左右结点都有，则返回值需要比较左子树与右子树返回一个最小的加1
      //              2. 只有一个孩子结点有值，则返回有数值的那个孩子结点数加1
};
```

##### **leetcode-404：左叶子节点之和**

给定二叉树的根节点 `root` ，返回所有左叶子之和

<u>此题不是求最长的路径所以不用DFS，求左叶子结点之和只要将向下递归的每一次得到叶子节点的val加在一起</u>

```c++
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
         return cal(root);
    }
    int cal(TreeNode *root)
    {
      
        if(!root)
        {
           return 0;
        }
       int var = 0 ;
       if(root->left!=nullptr)      //判定左叶子结点的条件
       {
           if(root->left->right==nullptr&&root->left->left==nullptr)
           {
               var = var+root->left->val;
           }
       }
   
       var += cal(root->left);
       var += cal(root->right);
       return var ;
    }
};
```

**总结：递归的最用单纯是将向下的每一次递归的和加起来，并返回，则不设置全局变量**

​           **递归如果有回溯功能或进行DFS，而需要另外一个全局变量储存数值即最后返回的数值，而每次递归返回的不是我们要的最终结果，需要设置全局变量**

##### **leetcode-687：最长同值路径**

给定一个二叉树的 root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。 这条路径可以经过也可以不经过根节点。

两个节点之间的路径长度 由它们之间的边数表示。

**与计算最长路径之和是同一类问题，但与DFS不同是，这里最长的路径需要判断是否与下一个节点数值相等，才能递增，不等的话就要打断对L，R的赋值。   因为这里要赋值给L,R的（递归进行的sort返回值）必须经过父节点与子节点的数值判等**

**相当于把DFS的深度递增操作 return max 与路径之和的相加递增操作   前再增加了   数值判等的条件判断**

```c++
class Solution {
public:
    int res;
    int longestUnivaluePath(TreeNode* root) {
         res=0;
         sort(root);
         return res;
    }
    int sort(TreeNode *root)
    {
         if(root==nullptr)
         {
              return 0;
         }
        int L = sort(root->left);
        int R = sort(root->right);
        if(root->left&&root->val==root->left->val)
        {
            L++;            //根节点数值与下一个节点值相等，同名路径加1
        }
        else
        {
           L=0;  
        }
        if(root->right&&root->val==root->right->val)
        {
           R++;             //根节点数值与下一个节点值相等，同名路径加1
        }
        else
        {
            R=0;
        }
         res = max(res,L+R);
         return max(L,R);
    }
};
```

##### **leetcode-124：二叉树的最大路径和**

路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。

```c++
class Solution {
public:
    int sun = INT_MIN;
    int calsun(TreeNode* root)
    {
         if(!root) return 0;
        //由于包含复数，所以取大于0的值
        int leftsum = max(calsun(root->left),0);
        int rightsum = max(calsun(root->right),0);
    //最长路径等于结点与结点左右结点的最大路径值之和
        int dcl = root->val + leftsum + rightsum;
        sun = max(sun,dcl);
   //对于结点两侧的路径进行dfs，分别得到结点的左右结点的最大路径值，不要忘记取大于0
          return root->val+max(leftsum,rightsum);
    
    }

    int maxPathSum(TreeNode* root) {
        int k =calsun(root);
        return sun;
    }
};
```

##### 剑指 Offer 34. 二叉树中和为某一值的路径

难度中等355

给你二叉树的根节点 `root` 和一个整数目标和 `targetSum` ，找出所有 **从根节点到叶子节点** 路径总和等于给定目标和的路径。

**叶子节点** 是指没有子节点的节点。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg)

```
输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]
```



```c++
class Solution {
public:
    vector<vector<int>> vec;
    vector<int> res;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
         if(!root)
         {
            return vec;  
         }else
         {
            dfs(root,target,0,res);
         }
         return vec;
        
    }
      void dfs(TreeNode* root, int target,int Sum,vector<int>& res)
      {
          Sum = Sum+root->val;
          res.push_back(root->val); 
          if(root->left)
        //根结点有左右叶子节点得继续进行递归，否则停止递归
          {
             dfs(root->left,target,Sum,res);
          } 
          if(root->right)
          {
             dfs(root->right,target,Sum,res);
          }
          if(target==Sum && !root->left && !root->right)
          {
             vec.push_back(res);
          }
       //一条分支递归结束后，pop掉这个叶子节点，从根节点去递归另一条分支
          res.pop_back();
      }
};

```



### 二叉树的前、中、后序遍历

##### 🤞**leetcode-144：二叉树的前序遍历**

给你二叉树的根节点 `root` ，返回它节点值的 **前序** 遍历。

**迭代实现：**

**使用栈结构，由于不需要按层就不用记录size，所以只要while（栈不为空）一层循环。先将根节点弹出栈，由于是前序遍历，所以再将右孩子压入栈，再将左孩子压入栈（这样优先弹出左孩子），再弹出左孩子，压入左孩子的两个孩子结点**

```c++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk; 
        if(root)stk.emplace(root);
        vector<int> vec;
        while(!stk.empty())
        {
            TreeNode *cur = stk.top();
            vec.emplace_back(cur->val);
            stk.pop();
            if(cur->right) stk.emplace(cur->right);
            if(cur->left)  stk.emplace(cur->left);
        }
        return vec;
    }
};
```

##### **🤞leetcode-144：二叉树的后序遍历**

给你一棵二叉树的根节点 `root` ，返回其节点值的 **后序遍历** 

递归实现：

从最简单的三个结点开始去想  sort(root->left);               三个语句的顺序。
                                                    sort(root->right);
                                                    vec.emplace_back(root->val);

```c++
class Solution {
public:
    vector<int> vec;
    vector<int> postorderTraversal(TreeNode* root) {
          sort(root);
          return vec;
    }
    void sort(TreeNode* root)
    {
         if(!root)
         {
             return ;
         }
          sort(root->left);
          sort(root->right);
          vec.emplace_back(root->val);
    }
};
```

##### **🤞leetcode-94：二叉树的中序遍历**

给定一个二叉树的根节点 `root` ，返回它的 **中序** 遍历。

```c++
class Solution {
public:
   vector<int> vec;
    vector<int> inorderTraversal(TreeNode* root) {
           sort(root);
           return vec;
    }
     void sort(TreeNode* root)
    {
         if(!root)
         {
             return ;
         }
          sort(root->left);
          vec.emplace_back(root->val);
          sort(root->right);
          
    }
};
```

##### leetcode-105：从前序与中序遍历序列构造二叉树

给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

**思路：按先序遍历重建二叉树，每一个根节点以左的半个树的节点的先序遍历数组上的依次的节点，根节点右孩子节点的节点是先序遍历数组中的根节点序号+（先序遍历数组中的根节点序号减去以该结点为根节点最左侧结点序号）+1**

<img src="F:\C++代码资料\Fig-DS\35.jpg" style="zoom:33%;" />

```c++
class Solution {
public:
      map<int,int> hash;
     TreeNode*  newtree(vector<int>& preorder, vector<int>& inorder,int preorderleft,int preorderright,int inorderleft,int inorderright)
  //先确定下来以该结点为根节点的先序，中序的边界
     {
           if(preorderleft>preorderright)
           {
               return nullptr;
           }
          int inorderroot = hash[preorder[preorderleft]];
  
          int lrsize = inorderroot-inorderleft;
   //此结点序号减去以此结点为子树最左侧结点的序号的长度       
         // 得到左子树中的节点数目
          // 递归地构造左子树，并连接到根节点
  
          TreeNode* Node = new TreeNode(preorder[preorderleft]);   
          Node->left = newtree(preorder,inorder,preorderleft+1,preorderleft+lrsize,inorderleft,inorderroot-1);
           Node->right = newtree(preorder,inorder,preorderleft+lrsize+1,preorderright,inorderroot+1,inorderright);
           return Node;
     }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int n = inorder.size();
         for(int i=0;i<inorder.size();i++)
         {
            hash[inorder[i]] = i;
              // 构造哈希映射，帮助我们快速定位根节点

         }
        
          return newtree(preorder,inorder,0,n-1,0,n-1);
    }
};
```







##### leetcode-637：循环数组中比当前元素大的下一个元素

给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。

**注：队列每pop一个元素，push进两个元素，所以一般是树先遍历完了，队还没有清空，所以外层循环加上while（！queue.empty()）**

 **示例 1：**

```
输入：
    3
   / \
  9  20
    /  \
   15   7
输出：[3, 14.5, 11]
解释：
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 
```

```java
class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
     Queue<TreeNode> que = new LinkedList<>();
     List<Double> averageList = new ArrayList<Double>();
     que.add(root);
     while(!que.isEmpty())
     {
       double sum = 0;
       int size = que.size();
       for(int i = 0;i<size;i++)  
  //使用层序遍历，每一次将一层的元素压入队列中以后都将队列中一层中的元素个数作为size保存一次，再遍历size次，将队列排空，将下一层的元素都压入队列。
       {
         TreeNode node = que.remove();
         sum += node.val;
         if(node.left!=null)
         {
          que.add(node.left);
         }
         if(node.right!=null)
         {
          que.add(node.right);
         }
       }
       averageList.add(sum/size);
     }
       return averageList;

    }
}
```

```c++
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
         queue<TreeNode*> que;
         vector<double> vec;
         que.push(root);
         while(!que.empty()) //外层循环的条件是队列不为空，有可能树已经遍历完了但是队列不为空
         {
            double size = que.size();
            TreeNode* temp;
            double sum = 0;   //记住设置一个变量一定与初始化为0！！！！！
            for(int i = 0;i<size;i++)
            {
                temp = que.front();
                sum += temp->val;
                que.pop();
                if(temp->left)
                {
                  que.push(temp->left);
                }
                if(temp->right)
                {
                  que.push(temp->right);
                }
            }
             vec.push_back(sum/size);
         }
            return  vec;
    }
};
```

##### **🤞leetcode-102：二叉树的层序遍历**

给你二叉树的根节点 `root` ，返回其节点值的 **层序遍历** 。 （即逐层地，从左到右访问所有节点）。

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> vec;
      if(!root) return vec;  
       //注意这里一定要判断一下非空，为空的话后面会报空指针异常
      queue<TreeNode*> que;
      que.push(root);
      while(!que.empty())
      {
          int st = que.size(); 
          vector<int> res; 
         for(int i = 0;i<st;i++)
         {
           TreeNode* temp =  que.front();
           res.push_back(temp->val);
           que.pop();
            if(temp->left)
            {
               que.push(temp->left);
            }
            if(temp->right)
            {
               que.push(temp->right);
            }
         }
            vec.push_back(res);
      }
        return vec;
    }
};

```



##### **leetcode-513：找左下角的值**

给定一个二叉树的 **根节点** `root`，请找出该二叉树的 **最底层 最左边** 节点的值。

假设二叉树中至少有一个节点。

**思路：找最左边结点，相当于标记每一层最左侧结点，也就是在给每一层更新每一层的size时，取到这个队列的头节点**

```c++
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        int var = 0;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            TreeNode* first = que.front();
            var  = first->val;
            for(int i = 0;i<size;i++)
            {
             TreeNode* cur = que.front(); 
             que.pop();
             if(cur->left)
             {
                que.push(cur->left);
             }
              if(cur->right)
             {
                que.push(cur->right);
             }
            }
        }
             return var;
    }
};
```

##### **leetcode-114：二叉树展开成链表**

给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。

```c++
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
       stack<TreeNode*> stk;
       stk.push(root);
       while(!stk.empty())
       {
           TreeNode* temp = stk.top();
           stk.pop();           
          if(temp->right) stk.push(temp->right);
          if(temp->left) stk.push(temp->left);
          if(!stk.empty()&&!temp->left)
          {
            temp->right = stk.top();
          }
     //在上一个元素弹出之后，栈不为空并且其左孩子不存在的情况下才将栈顶元素拼接到右孩子处
     //如果左孩子存在则无需进行拼接，后续进行调整就可以
       }
       TreeNode* p = root;
     //遍历并调整整个树，使其左孩子都变为右孩子
      while(p->left||p->right)
      {
         if(p->left)
         {
         p->right = p->left;
         p->left = nullptr;
         }
         p = p->right;
      }
      return;
    }
};
```

##### 剑指 Offer 32 - II. 从上到下打印二叉树 II

难度简单232

从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

例如:
给定二叉树: `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

```c++
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> levelOrder(TreeNode* root) {
         if(!root)
         {
            return ret;
         }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
           int numsize = que.size();
           ret.push_back(vector<int>());
           for(int i = 1;i<=numsize;i++)
           {
              TreeNode* node = que.front();
              ret.back().push_back(node->val);
              que.pop();
             if(node->left) que.push(node->left);  
       //要保证队列不能进入空结点，进入空节点后上面的判断会出现空指针异常，先判断node->left不为空
             if(node->right) que.push(node->right);
           }
        }
        return ret;
    }
};
```

##### 剑指 Offer 32 - III. 从上到下打印二叉树 III

请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

例如:
给定二叉树: `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```

返回其层次遍历结果：

```
[
  [3],
  [20,9],
  [15,7]
]
```

```c++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> vec;
       if(!root) return vec;
       queue<TreeNode*> que;
       que.push(root);
       int i = 0;
       while(!que.empty())
       {
          int quesize = que.size();
          vector<int> res;
          for(int i = 0;i<quesize;i++)
          {
             TreeNode* quetop = que.front();
             que.pop(); 
             res.push_back(quetop->val);
             if(quetop->left) que.push(quetop->left);
             if(quetop->right) que.push(quetop->right);
          }
          if(i%2==0) 
          {
              vec.push_back(res);
          }
          else
          {
              reverse(res.begin(),res.end());
              vec.push_back(res);
          }
          i++;
       }
       return vec;
    }
};

```

##### 剑指 Offer 68 - II. 二叉树的最近公共祖先

难度简单459

给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

[百度百科](https://baike.baidu.com/item/最近公共祖先/8918834?fr=aladdin)中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（**一个节点也可以是它自己的祖先**）。”

例如，给定如下二叉树: root = [3,5,1,6,2,0,8,null,null,7,4]

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/15/binarytree.png)

 

**示例 1:**

```
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
```

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
   //先递归整个树，由下至上得到所有左子树，右子树，下面分几种情况讨论：
   //当一个节点左右子树都为null时，这个节点赋为null
        if(left==NULL&&right==NULL) return NULL;
  //当一个根只有左子树为null时，最终公共节点结果应跑到right那一边，最终返回得也是right那边的节点，最远是root->right，近一些的情况往下递归即可
        if(left==NULL) return right;
  //与上面情况同理
        if(right==NULL) return left; 
    //当left与right都有值时最后返回最近根root
        return root;
    }
};
```



### BST

##### **leetcode-669：修剪二叉排序树**

给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。通过修剪二叉搜索树，使得所有节点的值在[low, high]中。修剪树 不应该 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 可以证明，存在 唯一的答案 。

所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

**思路：因为是二叉排序树，所以已经按照中序遍历的顺序排列好了结点，只需要从尾到头递归扫描一遍二叉排序树，根据条件更改节点就好了**

```c++
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)
        {
            return nullptr; 
        }
        root->left = trimBST(root->left,low,high);
        root->right =trimBST(root->right,low,high);
        if(root->val>high)
        {
            return root->left;
        }
        if(root->val<low)
        {
            return root->right;
        }
       return root;
    }
};
```

##### **leetcode-104：循环数组中比当前元素大的下一个元素**

给定一个二叉搜索树的根节点 `root` ，和一个整数 `k` ，请你设计一个算法查找其中第 `k` 个最小元素（从 1 开始计数）。

```c++
class Solution {
public:
    vector<int> vec;
    int kthSmallest(TreeNode* root, int k) {
         sort(root,k);
         int ele = vec[k-1];
         return ele;
    }
     void sort(TreeNode* root, int k)
     {
          if(!root)
          {
             return ;
          }
          sort(root->left,k);
          vec.emplace_back(root->val);
          sort(root->right,k);
     }
};
```

##### **leetcode-538：循环数组中比当前元素大的下一个元素**

给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。

```c++
class Solution {
    int sum;
public:
    TreeNode* convertBST(TreeNode* root) {
       if(!root)
       {
          return nullptr;
       }
    root->right = convertBST(root->right);
    sum += root->val;   //从树的右侧开始求前缀和，先递归到最右侧（最大值）
    root->val = sum; 
    root->left = convertBST(root->left);  //一棵子树左侧结点等于其所有右侧结点（val大于他的）之和
    return root;
    }
};
```

##### **leetcode-104：循环数组中比当前元素大的下一个元素**

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

**说明:** 叶子节点是指没有子节点的节点。

**示例：**
给定二叉树 `[3,9,20,null,null,15,7]`，

```
    3
   / \
  9  20
    /  \
   15   7
```

返回它的最大深度 3

```java
class Solution {
    public int maxDepth(TreeNode root) {
      if(root==null)
      {
        return 0;
       }
      int leftDepth = maxDepth(root.left);
      int rightDepth = maxDepth(root.right);
      
      return Math.max(leftDepth,rightDepth)+1;
    }
}
```

##### **leetcode-235：二叉搜索树的最近共同祖先**

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

```c++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            
            if(q->val>root->val&&p->val>root->val)
            {
                return lowestCommonAncestor(root->right,p,q);;
            }
           if(q->val<root->val&&p->val<root->val)
            {
                return lowestCommonAncestor(root->left,p,q);
            }
            
       return root;

            
    }
};
```

**思路：当两个结点同时在根节点一侧，则向那个方向递归。**

​           **如果一个在左边，一个在右边。或者根为空，都返回根节点本身。**

最后递归最后尽量不用把返回的值放在if语句块里，最好单独拿出来。

**如以下情况：**

```
 if(!root)
            {
                 return root;
            }
            if((p->val<root->val)&&(q->val>root->val))
            {
                return root;
            }
            if((p->val>root->val)&&(q->val<root->val))
            {
                return root;
            }
            if(p->val==root->val)
            {
                return root;
            }            
            if(q->val==root->val)
            {
               return root;
            }
```

##### **leetcode-108：从有序数组中构造平衡的二叉查找树**

给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。

高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树】

**思路：就是不断将数组二分，并找到每个数组二分之后的mid结点作为根节点，就可以构造出平衡的二叉查找树。**

```c++
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int R = nums.size()-1;
        int L = 0;      
        return sort(nums,L,R);
    }
    TreeNode* sort(vector<int>& nums,int L,int R)
    {
       if(L>R)
       {
          return nullptr;
       }
       int mid = L+(R-L)/2;
       TreeNode* Node = new TreeNode(nums[mid]);
       Node->left = sort(nums,L,mid-1);
       Node->right = sort(nums,mid+1,R);
       return Node;
    }
```

##### **leetcode-653：两数之和输入BST**

给定一个二叉搜索树 `root` 和一个目标结果 `k`，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 `true`。

```c++
class Solution {
public:
    vector<int> vec;
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr)
        {
            return false;
        }
        sort(root);
       int L=0;
       int R=vec.size()-1; 
       
      while(L<R)
      {
          int sum = vec[R]+vec[L]; 
          if(sum==k)
          {
              return true;
          }
          else if(sum>k)
          {
              R--;
          }
          else
          {
              L++;
          }
      }
      return false;

    }
    void sort(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
           sort(root->left);
           vec.push_back(root->val);
           sort(root->right);
    }
};
```

##### **leetcode-653：将有序链表转换成BST**

给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

           0
          / \
        -3   9
       /   /
     -10  5
```c++
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        return binary(head,nullptr);
    }
    TreeNode* binary(ListNode* left,ListNode*right)
    {
        if(left==right)  //left==right相当于left与上一次递归得到的根节点mid相同，则终止
        {
            return nullptr;
        }
        ListNode* mid = searchMid(left,right);
        TreeNode* Node = new TreeNode(mid->val);
        Node->left =  binary(left,mid);
        Node->right = binary(mid->next,right);
        return Node;
    }
    ListNode* searchMid(ListNode* left,ListNode* right)
    {
        ListNode* prev = left;
        ListNode* cur = left;
 //快慢指针同时从头节点移动，right作为右边界（上一次递归的根节点）（相当于最右边界null不能取），同时满足链表结点为奇数个：cur!=right，链表结点为偶数个：cur->next!=right才能保证prev到达mid中点       
        while(cur!=right&&cur->next!=right)
        {
            prev = prev->next;
            cur = cur->next->next;
        }
         return prev;
    }
     
};
```

##### **leetcode-653：验证二叉搜索树**

给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：

节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。

```c++
class Solution {
public:
   
    bool helper(TreeNode* root,long long dmin,long long dmax)
    {
        if(!root)     //结束条件与初始条件，能够遍历完叶子系欸DNA证明二叉搜索树成立
        {
            return true;
        }
        if(root->val>=dmax||root->val<=dmin)
        {
           return false;
        }
             
       return helper(root->left,dmin,root->val)&&helper(root->right,root->val,dmax);

    }
     bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
};
```

##### 剑指 Offer 33. 二叉搜索树的后序遍历序列

难度中等532

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 `true`，否则返回 `false`。假设输入的数组的任意两个数字都互不相同。

参考以下这颗二叉搜索树：

```
     5
    / \
   2   6
  / \
 1   3
```

**示例 1：**

```
输入: [1,6,3,2,5]
输出: false
```

<img src="F:\C++代码资料\Fig-DS\88.png" style="zoom:50%;" />

```c++
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        stack<int> stk;
        int pre = INT_MAX;
      //由于是BST的后续，所以可以倒叙遍历数组找规律
        for(int i = postorder.size()-1;i>=0;i--)
        {
            if(postorder[i]>pre)
            {
                return false;
            }
            while(!stk.empty()&&stk.top()>postorder[i])
            {
                 pre = stk.top();
                 stk.pop();
            }
            stk.push(postorder[i]);
        }
        return true;
    }       
};
```

##### leetcode-297. 二叉树的序列化与反序列化

序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。

请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

**提示:** 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 [LeetCode 序列化二叉树的格式](https://leetcode.cn/faq/#binary-tree)。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

<img src="F:\C++代码资料\Fig-DS\93.png" style="zoom: 50%;" />



```c++
class Codec {
public:
    string res; 
    void rialize(TreeNode* root)
    {
         if(!root)
         {
            res+="None,";  //如果序列化到这个节点为null，那么下面的语句应为else
         }else
         {
         res+=to_string(root->val)+",";
            //to_string用于将数值转化为string
         rialize(root->left);
         rialize(root->right);
         }
         
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        rialize(root);
        return res;
    }
    //将每个字符串分别取出构造回二叉树
    TreeNode* deser(queue<string>& que)
    {
         if(que.front()=="None")
         {
             que.pop();
            return NULL;
         }
         TreeNode* newnode = new TreeNode(stoi(que.front()));
        //stoi()函数用于将string转化为int
         que.pop();
         newnode->left = deser(que);
         newnode->right = deser(que);
         return newnode; 
    }
    
    // Decodes your encoded data to tree.
    //将字符串去逗号，按结点数值分字符串储存在队列中
    TreeNode* deserialize(string data) {
        queue<string> que;
        string ans;
        for(int i = 0;i<data.size();i++)
        {
           if(data[i]==',')
           {
              que.push(ans);
              ans = "";
           }
           else
           {
              ans.push_back(data[i]);
           }
        }
           return deser(que);
    }
};
```

##### 剑指 Offer 36. 二叉搜索树与双向链表

难度中等534

输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

 <img src="F:\C++代码资料\Fig-DS\101.png" style="zoom: 67%;" />

思路：由于是按着有序顺序排序，树为BST，所以按中序遍历树结构

```c++
class Solution {
private:
Node* pre;
Node* head;   //定义一个前驱结点和一个头结点，一个当前节点
Node* cur;
public:
    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        dfs(root);
    //递归结束后，令头节点的左孩子指向尾节点（pre）
        head->left = pre;
     //令尾结点右指针指向head
        pre->right = head;
        return head; 
    }

     void dfs(Node* root)
     {
        if(!root)
        {
           return;
        }
        dfs(root->left);
        if(pre)
        {
         //当递归到下一个节点，前驱结点存在时，令前驱结点右孩子指针指向后继结点
           pre->right = root;  
        }
        else  
      //当前驱节点无指向时，则递归到了左下方，整个树最左下方的结点为头节点
        {
           head = root;   //记录唯一的头节点
        }
        cur = root;  
        cur->left = pre;  //将当前结点的左孩子指针指向前驱节点
        pre = cur;    //前驱结点后移
        dfs(cur->right);
     }

};

```

### API设计

#### 208. 实现 Trie (前缀树)

Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补完和拼写检查。

请你实现 Trie 类：

Trie() 初始化前缀树对象。
void insert(String word) 向前缀树中插入字符串 word 。
boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。

```
示例：
输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]
解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
```

```c++
class Trie {

private:
 Trie* next[26] = {nullptr};
 bool isEnd = false; 
public:
    Trie() {

    }
    
    void insert(string word) {
       Trie* root = this;
       for(char ch:word)
       {
           char w = ch - 'a';
        if(root->next[w]==nullptr)  root->next[w] = new Trie();
        root = root->next[w];
       }
         root->isEnd = true;
    }
    
    bool search(string word) {
         Trie* root = this;
         for(char ch:word)
         {
             ch = ch-'a';
            if(root->next[ch]==nullptr) return false; 
             root = root->next[ch];
         }
         return root->isEnd;
    }
    
    bool startsWith(string prefix) {
          Trie* root = this;
         for(char ch:prefix)
         {
             ch = ch-'a';
            if(root->next[ch]==nullptr) return false; 
             root = root->next[ch];
         }
         return true;
    }
};
```

#### 146. LRU 缓存

请你设计并实现一个满足 [LRU (最近最少使用) 缓存](https://baike.baidu.com/item/LRU) 约束的数据结构。

实现 `LRUCache` 类：

- `LRUCache(int capacity)` 以 **正整数** 作为容量 `capacity` 初始化 LRU 缓存
- `int get(int key)` 如果关键字 `key` 存在于缓存中，则返回关键字的值，否则返回 `-1` 。
- `void put(int key, int value)` 如果关键字 `key` 已经存在，则变更其数据值 `value` ；如果不存在，则向缓存中插入该组 `key-value` 。如果插入操作导致关键字数量超过 `capacity` ，则应该 **逐出** 最久未使用的关键字。

函数 `get` 和 `put` 必须以 `O(1)` 的平均时间复杂度运行。

**示例：**

```
输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
```



```c++
class LRUCache {
private:
     int cap;
     list<pair<int,int>> cache;
     unordered_map<int, list<pair<int,int>>::iterator> map;

public:
    LRUCache(int capacity):cap(capacity) {

    }
      //get操作，得到cache中的value，并且将pair置于cache最前面
    int get(int key) {
        if(map.find(key) == map.end())  return -1;
        auto key_value = *map[key];  //提领iterator的元素pair
        cache.erase(map[key]);
        cache.push_front(key_value);   
        map[key] = cache.begin();  //调整维护map的iterator
        return key_value.second;
    }
    
    void put(int key, int value) {
       //put操作，当key不存在，且cache已满时，cache清除掉内存尾的元素
       if(map.find(key)==map.end()) 
       {
            if(cache.size()==cap)
            {
               map.erase(cache.back().first);
               cache.pop_back();
            }
       }
       else
       {
              cache.erase(map[key]);         
       }
          cache.push_front({key,value});
          map[key] = cache.begin();    //维护map[key]的iterator
    }
};
```



### **快速排序：**

#### leetcode-75：荷兰国旗问题

给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

必须在不使用库的sort函数的情况下解决这个问题。

 示例 1：

输入：nums = [2,0,2,1,1,0]
输出：[0,0,1,1,2,2]

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int R = nums.size();
        int L = 0;
        sort(nums,  L,  R);
          
    }
     
     void swap(int &a,int &b)
     {
      int temp = a;
      a = b;
      b = temp;
     }

   void sort(vector<int>& nums,int L,int R)
    {
      int less = L - 1;
      int more  = R;  
    
        while(L<more)
        {
           if(nums[L] == 0)
           {
               swap(nums[L++],nums[++less]);
           }
           else if(nums[L]==2)
           {
               swap(nums[L],nums[--more]);
           }
           else
           {
               L++;
           }
        }
       
    
         }  
      
    
};
```

#### leetcode-215：**Kth Element**

难度中等1494

给定整数数组 `nums` 和整数 `k`，请返回数组中第 `**k**` 个最大的元素。

请注意，你需要找的是数组排序后的第 `k` 个最大的元素，而不是第 `k` 个不同的元素。

 **示例 1:**

```
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
```

```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       int heapsize = nums.size();
       int number = heapsize-1;
       if(heapsize==1)
       {
           return nums[0];
       }
       for(int i = heapsize-1;i>=0;i--)
       {
        heapify(nums, heapsize, i);
       }
       for(int j = 0;j < k; j++)
       {
          swap(nums[0],nums[--heapsize]);
          heapify(nums, heapsize, 0);
       }
       return nums[number-k+1];


    }
   void swap(int &a,int &b)
   {
     int temp = a;
     a = b;
     b = temp;
   }
   void heapify(vector<int>& vec,int heapsize,int index)
   {
       int largest;
       int left = 2*index+1;
        while(left<heapsize)
        {
           largest = (left+1<heapsize)&&vec[left]<vec[left+1] ? left+1:left;
   //要将left+1<heapsize放在前面，因为若为【2，1】，不会进vec[left]<vec[left+1]导致超出索引
           largest = vec[index]<vec[largest]? largest:index;
          if(largest == index)
          {
              break;
          }
           swap(vec[largest],vec[index]);
           index = largest;
           left = 2*index+1;
        }

   }


};
```

**调库**

```c++
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int, vector<int>, less<int>> maxHeap;
      //堆即是优先队列
        for (int x : nums)
            maxHeap.push(x);
        for (int _ = 0; _ < k - 1; _ ++)
            maxHeap.pop();
        return maxHeap.top();
    }
};

```

### 归并排序

#### leetcode-4. 寻找两个正序数组的中位数

难度困难5574

给定两个大小分别为 `m` 和 `n` 的正序（从小到大）数组 `nums1` 和 `nums2`。请你找出并返回这两个正序数组的 **中位数** 。

算法的时间复杂度应该为 `O(log (m+n))` 。

**示例 1：**

```
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
```

**处理逻辑：**

1. 合并 nums1，nums2 为第三个数组
2. 排序第三个数组
3. 按下标，找出中位数

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         int m = nums1.size();
         int n = nums2.size();
         vector<int> vec(m+n);
         int i = 0 ;
         int j = 0;
         int k = 0;
        while(i < m && j < n)
        {
          vec[k++] = (nums1[i]>nums2[j]? nums2[j++]:nums1[i++]);
        }
        while(i<m)
        {
          vec[k++] = nums1[i++];
        }
        while(j<n)
        {
           vec[k++] = nums2[j++];
        }
        if((m+n)%2==0)
        {
           return (vec[(m+n)/2] + vec[(m+n)/2-1])/2.0; 
          //注意这里返回的是double，所以初除2.0
        }
        return vec[(m+n)/2];
    } 
};
```

#### 剑指 Offer 51. 数组中的逆序对

难度困难787

在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

**示例 1:**

```
输入: [7,5,6,4]
输出: 5
```

<img src="F:\C++代码资料\Fig-DS\36.jpg" style="zoom: 33%;" />

**思路：使用归并排序，在排序合并的同时统计逆序对数，在统计对数（合并）时，如果左数组中一个元素大于右数组中一个元素构成逆序对，那么由于是递归过程，左数组已经是有序的了，那么左数组中在这个元素后面的元素一定也构成逆序对，所以  cnt+=mid-i+1;**

```c++
class Solution {
public:
    //利用归并排序解答，在合并的时候，当左边的大于右边，就计算逆序数。
    //计算公式； mid-left+1
    //定义一个全局的计数器变量
    int cnt = 0;
    int reversePairs(vector<int>& vec) {
         margesort(vec,0,vec.size()-1);
         return cnt;
    }
    void margesort(vector<int>& vec,int left,int right)
    {
        //当只有一个节点的时候，直接返回，退出递归
          if(left>=right)
          {
             return;
          }  
          int mid = (right+left)/2;
          margesort(vec,left,mid);
        //左拆分
          margesort(vec,mid+1,right);
        //右拆分
          marge(vec,left,mid,right);
        //合并
    }
    void marge(vector<int>& vec,int left,int mid,int right)
    {
         vector<int> temp(right-left+1);
         int i = left;
        //定义一个指针，指向第一个数组的第一个元素
         int j = mid+1;
        //定义一个指针，指向第二个数组的第一个元素
         int t = 0;
         //定义一个指针，指向临时数组的第一个元素
         while(i<=mid&&j<=right)
         {
            if(vec[i]<=vec[j])
            {
              temp[t++] = vec[i++];
            }
            else
            {
                //当左边数组的大与右边数组的元素时，就对当前元素以及后面的元素的个数进行统计，
                //此时这个数就是，逆序数
                //定义一个计数器，记下每次合并中存在的逆序数。
               cnt+=mid-i+1;
               temp[t++] = vec[j++]; 
            }
         }
         while(i<=mid)
         {
            temp[t++] = vec[i++]; 
         }
        while(j<=right)
        {
            temp[t++] = vec[j++];
        }
         //将新数组中的元素，覆盖nums旧数组中的元素。
        //此时数组的元素已经是有序的
        for(int i = 0;i<temp.size();i++)
        {
            vec[left+i] = temp[i];
        }

    }
};
```



### 字符串

**leetcode-242：有效的字符异位词**

给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

**思路：应用哈希表的思想，开辟一个26个key的数组相当于hash表（因为只要小写字母），若出现次数相同，则两次遍历后哈希表的词频都为1**

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
         int number[26]={0};
         if(s.size()!=t.size())
         {
             return false;
         }
          for(int i = 0 ; i<s.size();i++)
          {
               number[s[i]-'a']++; //小写字母的ASCII值相减
               number[t[i]-'a']--;
          }
          for(int i = 0;i<26;i++)
          {
              if(number[i]!=0)
              {
                  return false;
              }
          }

          return true;
    }
};
```

**leetcode-409：最长回文串**

给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。

在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。

```
示例 1:
输入:s = "abccccdd"
输出:7
解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
```

```c++
class Solution {
public:
    int longestPalindrome(string s) {
      map<char,int>num_map;
       int count=0;
       int number=0;
       for(int i = 0;i<s.size();i++)
       {
           num_map[s[i]]++;
       }
       for(auto p:num_map)
       {
          if(p.second>1)
          {
             count += (p.second%2==0)? p.second:p.second-1;
          }
          if(p.second%2==0)
          {
             number+=p.second;
          }
       }
       if(number<s.size()||s.size()==1) //在偶数的val小于整体个数时，或size为1时，count+1
       {
          count = count+1;
       }
       
       return count;
    }
};
```

**leetcode-205：同构字符串**

给定两个字符串 s 和 t ，判断它们是否是同构的。

如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。

每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

**思路：使用两个hash映射使两个字符串双双建立映射关系，如果一个里出现对应关系后，后来发生了破坏对应关系，则false**

```c++
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> s_t;
        map<char,char> t_s;
        for(int i=0;i<s.size();i++)
        {
            int a = s[i]; 
            int b= t[i];
if((s_t.count(s[i])&&s_t[s[i]]!=t[i])||(t_s.count(t[i])&&t_s[t[i]]!=s[i]))
           {
               return false;
           }
            s_t[s[i]] = t[i];
            t_s[t[i]] = s[i];
        }
        return true;
    }
};
```

**leetcode-9：回文数**

给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。

**示例 2：**

```
输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
```

```c++
class Solution {
public:
    bool isPalindrome(int x) {
       vector<int> vec;
       int a;
       if(x<0)
       {
        return false;
       }
       while(x!=0)
       {
         a = x%10;
         x = x/10; 
         vec.emplace_back(a);
       }
           int L = 0;
           int R  = vec.size();
           for(L=0,R =  vec.size()-1;L<R;L++,R--)
           {
              if(vec[L]!=vec[R])
              {
                  return false;
              }
           }
           return true;
           
    }
};

```

**leetcode-647：回文子串**

给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

回文字符串 是正着读和倒过来读一样的字符串。

子字符串 是字符串中的由连续字符组成的一个序列。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

**思路：**

**记：  枚举所有得回文中心：2 * n - 1**

​         **左右边界为  l = i / 2, r = i / 2 + i % 2，分别向左右扩张。**

```
示例 1：
输入：s = "abc"
输出：3
解释：三个回文子串: "a", "b", "c"
```

```c++
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
  //一共是2 * n - 1;种情况，i为偶数的时候l与r相同（为单回文中心的情况）
  //i为奇数时，l与r相差1，（为双回文中心的情况）
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
};
```

**leetcode-696：计数二进制子串**

给定一个字符串 s，统计并返回具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是成组连续的。

重复出现（不同位置）的子串也要统计它们出现的次数。

<img src="F:\C++代码资料\Fig-DS\26.jpg" style="zoom: 33%;" />

```
示例 1：

输入：s = "00110011"
输出：6
解释：6 个子串满足具有相同数量的连续 1 和 0 ："0011"、"01"、"1100"、"10"、"0011" 和 "01" 。
注意，一些重复出现的子串（不同位置）要统计它们出现的次数。
另外，"00110011" 不是有效的子串，因为所有的 0（还有 1 ）没有组合在一起。
```

```c++
class Solution {
public:
    int countBinarySubstrings(string s) {
      int n = s.size();
      int ptr = 0;
      int ans = 0;
      int last=0;
      while(ptr<n)
      {
         int count = 0;
         char c = s[ptr];
         while(s[ptr]==c)
        {
           count++;
           ptr++;
        }
         ans+=min(last,count);
         last = count;
      }

        return ans;
    }
};
```

**leetcode-696：最长回文子串**

给你一个字符串 `s`，找到 `s` 中最长的回文子串。

**示例 1：**

```
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
```

```c++
//中心扩展法
class Solution {
public:
    string longestPalindrome(string s) {
       int len = s.size();
       int end = 0;
       int start = 0;
       int long_len = 0;
        for(int i = 0;i<len;i++)
        {
             int m_len1 = expend(s,i,i);
             int m_len2 = expend(s,i,i+1);
             long_len = max(max(m_len1,m_len2),long_len);
             if(long_len>end-start+1)
             {
                start = i-(long_len-1)/2;
                end = i+(long_len)/2;
             }
        }
        return s.substr(start,long_len);
    }
    private:
    int expend(string s,int l,int r)
    {
       while(l>=0&&r<s.size()&&s[l]==s[r]) 
       {
          l--;
          r++;
       }
        return r-l-1;   
        //正常应该是r-l+1的，但是最后一次r与l多扩充了两个字符距离，导致返回结果变为r-l再减去1就够了
    }
};
```

#### 剑指 Offer 58 - I. 翻转单词顺序

输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

```
示例 1：
输入: "the sky is blue"
输出: "blue is sky the"
```

**逆序双指针求解：**

```c++
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
             int right = i;
            while(i>=0&&s[i]!=' ')
            {
                i--;
            }
            ans += s.substr(i+1,right-i)+" ";
            }
            
        }
        return ans.substr(0,ans.size()-1);;
    }
};
```

#### 剑指 Offer 05. 替换空格

请实现一个函数，把字符串 `s` 中的每个空格替换成"%20"。

**示例 1：**

```
输入：s = "We are happy."
输出："We%20are%20happy."
```

```c++
class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for(int i = 0;i<s.size();i++)
        {
           if(s[i]==' ')
           {
               ans.append("%20");
           }
           else
           {
               ans.push_back(s[i]);
           }
        }
        return ans;
    }
};
```

**字符串string的append（“ ”）；操作可向字符串内添加元素**

#### 剑指 Offer 45. 把数组排成最小的数

输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

**示例 1:**

```
输入: [10,2]
输出: "102"
```

**思路：此题本质上还是一个排序过程，我们可采用冒泡排序，在排序中不断比较两个数字拼成的字符串的大小，不断交换组成一个小的数字**

```c++
class Solution {
public:
    string minNumber(vector<int>& nums) {
          int n = nums.size();
          for(int i = n-1;i>0;i--)
          {
             for(int j= 0;j<i;j++)
             {
                 if(iscompare(nums[j],nums[j+1]))
                 {
                    swap(nums[j],nums[j+1]);
                 }
             }
          }
          string res= "";
          for(int i = 0;i<n;i++)
          {
            //to_string（）与to_string（）相加用于将两个数字拼成一个字符串
             res+= to_string(nums[i]); 
          }
          return res;
    }
    bool iscompare(int a, int b)
    {
        //to_string（）与to_string（）相加用于将两个数字拼成一个字符串
         string s = to_string(a)+to_string(b);
         string k = to_string(b)+to_string(a);
         if(s>k){ return 1;}
        //字符串可以直接比较大小
         return 0;
    }
};
```

#### 剑指 Offer 58 - II. 左旋转字符串

难度简单264

字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

**示例 1：**

```
输入: s = "abcdefg", k = 2
输出: "cdefgab"
```

```c++
class Solution {
public:
    string reverseLeftWords(string s, int n) {
         reverse(s.begin(),s.begin()+n);
         reverse(s.begin()+n,s.end());
         reverse(s.begin(),s.end());
         return s;
    }
};
```

#### 剑指 Offer 67. 把字符串转换成整数

写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。

首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。

当我们寻找到的第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号；假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。

该字符串除了有效的整数部分之后也可能会存在多余的字符，这些字符可以被忽略，它们对于函数不应该造成影响。

注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换。

在任何情况下，若函数不能进行有效的转换时，请返回 0。

**说明：**

假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231, 231 − 1]。如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

**示例 1:**

```
输入: "42"
输出: 42
```

**示例 2:**

```
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
```

**示例 3:**

```
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
```

**示例 4:**

```
输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。
```

**示例 5:**

```
输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (−231) 。
```

<video id="video" controls="" preload="none" poster="">
      <source id="mp4" src="F:\C++代码资料\Fig-DS\把字符串转换成整数.mp4">
      </video>

```c++
class Solution {
public:
    int strToInt(string str) {
    int flag = 1;   //flag用来记录数字的符号
    int len =str.size();
    int i =0;
    while(str[i]==' ')
     //  模拟 :  (直接开始分三种情况考虑)
     //过滤掉整个字符串中的空格字符
    {
       i++;
    }
    if(i==len||(!isdigit(str[i])&&str[i]!='+'&&str[i]!='-'))
    //当i已经到达字符串末尾时，或字符串第i个字符不是数字也不是+或-时直接返回 0
    {
         return 0;
    }
    //当i到达的位置是+或-时，改变符号，并继续利用i模拟
    if(str[i]=='-'||str[i]=='+')
    {
        if(str[i]=='-')
        {
           flag =-1;
        }
       i++;
    }
     long cnt = 0;
      //当i到达len时，或出现不为数字的字符时停止模拟
     while(i<len && isdigit(str[i]))
     {
          cnt = cnt*10+(str[i]-'0');
          i++;
        //根据题目说的超出范围并且符号为+或-时分别返回INT_MAX，INT_MIN
          if(cnt>INT_MAX && flag==1)
          {
              return INT_MAX;
          }
          if(cnt>INT_MAX && flag==-1)
          {
              return INT_MIN;
          }
     }
        return cnt*flag;

    }
};
```



### 双指针

##### **leetcode-167：有序数组的 Two Sum**

给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。

```
示例 1：

输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
```

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
         int l = 0;
         int r = numbers.size()-1;
         vector<int> vec;
         while(l<r)
         {
           if(target>numbers[l]+numbers[r])
           {
                l++;
           }
            if(target<numbers[l]+numbers[r])
            {
               r--;     
            }
            if(target==numbers[l]+numbers[r])
            {
              vec.push_back(l+1);
              vec.push_back(r+1);  //因为最后返回结果索引要加1
              return vec;
            }
         }
        return {-1,-1};
    }
};
```

##### **leetcode-633：平方数之和**

给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。

```
示例 1：

输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5
```

<img src="F:\C++代码资料\Fig-DS\52.png" style="zoom: 50%;" />

**根据这一点我们对传入的c，取sqrt，即为right+1指针边界（right+1取不到，right能取到）**

```c++
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = (int)sqrt(c);  //定义long型数据，由于数据量 0 <= c <= 2^31 - 1
        long sum;
        while(left<=right)
        {
           sum = left*left+right*right;
           if(sum<c)
           {
               left++;
           }
           if(sum>c)
           {
               right--;
           }
            if(sum==c)
            {
                return true;
            }
        }
        return false;
    }
};
```

##### **leetcode-345：反转字符串中元音字母**

给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。

元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现。

```
示例 1：

输入：s = "hello"
输出："holle"
```

```c++
class Solution {
public:
    string reverseVowels(string s) {
       int l = 0;
       int n = s.size()-1;
       int r = n;
       while(l<r)
       {
          while(l<n&&s[l]!='a'&&s[l]!='e'&&s[l]!='i'&&s[l]!='o'&&s[l]!='u'&&s[l]!='A'&&s[l]!='E'&&s[l]!='I'&&s[l]!='O'&&s[l]!='U')
          {
              l++;
          }
      while(r>0&&s[r]!='a'&&s[r]!='e'&&s[r]!='i'&&s[r]!='o'&&s[r]!='u'&&s[r]!='A'&&s[r]!='E'&&s[r]!='I'&&s[r]!='O'&&s[r]!='U'){
                r--;
            }
          if(l<r)  //这里要注意l有可能会递增到大于r（hello），所以需要再判断一次
          {
            swap(s[r],s[l]);  //c++中有swap的模板库
            l++;             //交换完以后两边在进行递增
            r--;
          }
         
       }
        return s;
    }
  
};
```

##### **leetcode-680：验证回文字符串**

给定一个非空字符串 `s`，**最多**删除一个字符。判断是否能成为回文字符串。

**示例 1:**

```
输入: s = "aba"
输出: true
```

```c++
class Solution {
public:
    bool checkPalindrome(const string& s, int low, int high) {
        for (int i = low, j = high; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;
        while (low < high) {
            char c1 = s[low], c2 = s[high];
            if (c1 == c2) {
                ++low;
                --high;
            } else {
                return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);    
         //这样如果字符串有一边删除后还是不符合回文串，另一边如果满足删除后符合回文串还会返回true
            }
        }
        return true;
    }
};


```

**错误： 通不过 "abeikieiba"**

```
class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        int cnt = 0;
        while(l<r)
        {
            while(l<r&&s[l]==s[r])
           {
               l++;
               r--;
           }
           if(s[l]!=s[r])
           {
             if(s[l+1]==s[r])
             {
              l++;
              cnt++;
              continue;
             }
             if(s[r-1]==s[l])
             {
              r--;
              cnt++;
              continue;
             }
             return false;
            
           } 
         
        }
        return cnt<=1;
    }
};
```

##### leetcode-141：环形链表

给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。

```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *prev = head;
        ListNode *cur = head;
        if(!head)
        {
           return false;
        }
        while(cur!=NULL&&cur->next!=NULL)
        {
           cur = cur->next->next;
           prev = prev->next;
           if(cur==prev)
           {
              return true;
           } 
        }
        return false;
    }
};
```

##### **leetcode-88：合并两个有序数组**

给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

**双指针：**

```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                cur = nums2[p2++];
            } else if (p2 == n) {
                cur = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                cur = nums1[p1++];
            } else {
                cur = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = cur;  
            //找到下一个大的元素之后，向后移动一个元素，赋值时要为p1 + p2 - 1
        }
        for (int i = 0; i != m + n; ++i) {
            nums1[i] = sorted[i];
        }
    }
};
```

##### **leetcode-11：盛水最多的容器**

给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int sum = 0;
        int res = 0;
        while(l<r)
        {
            sum =  min(height[r],height[l])*(r-l);   //这里注意是横轴长是r-l
            res = max(res,sum);
            if(height[r]<height[l])
            {
                 r--;
            }
            else
            {
                 l++;
            }
        }
        return res;
    }
};
```

##### leetcode-15：三数之和

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

**这道题核心是去重**

```
示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
```

```c++
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res=new ArrayList();
        for(int i=0;i<nums.length;i++){
            int tem=-nums[i];
            List<List<Integer>> temList = twoSum(nums,i+1,tem);
  //若将排序后的数组从最小到最大，从最小的值开始寻找前面两个数之和等于这个数相反数，那么值需要遍历一次
            if(temList.size()>0){
                List<List<Integer>> temRes=new ArrayList(temList);
                for(List<Integer> list1:temRes){
                    list1.add(nums[i]);
                    res.add(list1);
                }
                while(i<nums.length-1&&nums[i]==nums[i+1]){
                    i++;
                }
                //这里还是去重
            }
        }
        return res;

    }

    /**
     * 这个是两数之和的进阶版本，加了一个start参数
     * @param nums
     * @param start
     * @param target
     * @return
     */
    public List<List<Integer>> twoSum(int[] nums, int start,int target) {
        List<List<Integer>> res=new ArrayList();
        int left=start;
        int right=nums.length-1;
        while(left<right){
            int leNum=nums[left];
            int rigNum=nums[right];
            int sum=leNum+rigNum;
            if(sum==target){
                List<Integer> tem=new ArrayList<>();
                tem.add(leNum);
                tem.add(rigNum);
                res.add(tem);
                //跳过所有重复的元素
                while(left<right&&nums[left]==leNum){
                    left++;
                }
                while(left<right&&nums[right]==rigNum){
                    right--;
                }
            }else if(sum<target){
                //跳过所有重复的元素
                while(left<right&&nums[left]==leNum){
                    left++;
                }
            }else if(sum>target){
                //跳过所有重复的元素
                while(left<right&&nums[right]==rigNum){
                    right--;
                }
            }

        }
        return res;
    }

}
```

##### leetcode-253：会议室

给你一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi] ，返回 所需会议室的最小数量 。

```
示例 1：
输入：intervals = [[0,30],[5,10],[15,20]]
输出：2
```

```
上车下车问题：
开会也可以理解成坐公交，都是占用某个资源。
就拿题目给的第一组数组来分析。

intervals = [[0,30],[5,10],[15,20]]
第一个人从0上车，从30下车；
第二个人从5上车，10下车。。。

我们的问题转化为最多车上有几个人（也就是最多有多少会议室）。

显然：上车，车上人数+1；下车，车上人数-1
我们把intervals拆解一下

上车：[0, 1], [5, 1], [15, 1]
下车：[10, -1], [20, -1], [30, -1]
```

**所以我们设计一个哈希表，这个哈希表只关注时间结点的头和尾，在遍历这个哈希表时我们也只关注时间结点头和尾，计算出整个车厢的在时间结点的头的头与尾时最多的人数**

```c++
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
       map<int,int> m;
        for(auto& itr : intervals){
            m[itr[0]]++;
            m[itr[1]]--;
        }
        int ans = 0, cnt = 0;
        for(auto& item : m){
            cnt += item.second;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
```

##### leetcode-581：最短无序连续子数组

给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。

请你找出符合题意的 最短 子数组，并输出它的长度。

```
示例 1：
输入：nums = [2,6,4,8,10,9,15]
输出：5
解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
```

<img src="F:\C++代码资料\Fig-DS\66.png" style="zoom:50%;" />

```c++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxnum = nums[0];
        int minnum = nums[n-1];
        int  begin = 0;
        int end = -1;
        for(int i = 0;i<n;i++)
        {
            if(nums[i]>= maxnum)
            {
               maxnum = nums[i];
             //通过if语句这样也可以实现选取得到最大值
            }
            else
            {
             end = i;
    //end指针从最左端开始遍历数组，直到最右端，找到右端有序递增子数组的左边界
   //如果遍历到的数比上一个数（也就是递增出来的前面数序列里的最大值）小,那就标记这个数作为无序的点，如果找到的是递增的有序的则不需要标记
            }
            if(nums[n-i-1]<=minnum)
            {
               minnum = nums[n-i-1];
            }
            else
            {
               begin = n-i-1;
            }
        }
        return end-begin+1;
    }
};

```

##### leetcode-56：合并区间

以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

```
示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
```

```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
       //首先按第一列把整个二维数组顺序排序
        int n = intervals.size();
        vector<vector<int>> vec;
        for(int i = 0;i<n;)
        {
            int j = i+1;
            int t = intervals[i][1];
            while(j<n&&intervals[j][0]<=t)  //合并区间
       //在下一个区间的左端 小于或等于 当前区间右端时，合并区间，
      //并不断遍历下一个区间左值与当前合并后区间的右值大小关系判断是否合并
            {
               t = max(t,intervals[j][1]);
               j++;
            }
             vec.push_back({intervals[i][0],t});
              i=j;
            //当轮最大区间合并完成后，移动i指针在进行遍历下一个小区间
        }
        return vec;
    }
};
```

##### 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

**示例：**

```
输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
```

```c++
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l<r)
        {
             while(l<r&&(nums[l]&1)==1) l++;
             while(l<r&&(nums[r]&1)==0) r--;
             swap(nums[l],nums[r]);
        }
        return nums;
    }
};
```

##### 剑指 Offer 11. 旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。

给你一个可能存在 **重复** 元素值的数组 `numbers` ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回旋转数组的**最小元素**。例如，数组 `[3,4,5,1,2]` 为 `[1,2,3,4,5]` 的一次旋转，该数组的最小值为 1。 

注意，数组 `[a[0], a[1], a[2], ..., a[n-1]]` 旋转一次 的结果为数组 `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]` 。

**示例 1：**

```
输入：numbers = [3,4,5,1,2]
输出：1
```

```c++
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if(numbers.size()==1)
        {
           return  numbers[0];
        }
        int left = 0,right = numbers.size()-1;
        while(left<right)
        {
           if(numbers[left+1]<numbers[left])
           {
              return numbers[left+1];
           }
          if(numbers[right]<numbers[right-1])
           {
              return numbers[right];
           }
           left++;
           right--;
        }
        return numbers[0];
    }
};
```

### 二分查找

##### **🤞BM17** **二分查找-I**

请实现无重复数字的升序数组的二分查找

给定一个 元素升序的、无重复数字的整型数组 nums 和一个目标值 target ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标（下标从 0 开始），否则返回 -1

数据范围：0 \le len(nums) \le 2\times10^50≤*l**e**n*(*n**u**m**s*)≤2×105 ， 数组中任意值满足 |val| \le 10^9∣*v**a**l*∣≤109

进阶：时间复杂度 O(\log n)*O*(log*n*) ，空间复杂度 O(1)*O*(1)

输入：

```
[-1,0,3,4,6,10,13,14],13
```

返回值：

```
6
```

说明：

```
13 出现在nums中并且下标为 6     
```

```c++
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param target int整型 
     * @return int整型
     */
    int search(vector<int>& nums, int target) {
        // write code here
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return -1;
    }
};
```



**leetcode-69：x的平方根**

给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

<img src="F:\C++代码资料\Fig-DS\27.jpg" style="zoom: 33%;" />

```c++
class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int ans =-1;
        if(x==0)
        {
         return 0;
        }
        if(x==1)
        {
          return 1; 
        }
        while(l<=r)
        {
         int mid = l+(r-l)/2;
         
         if((long long)mid*mid<=x)  //数据量大小为2^31,mid与mid相乘得到的数据类型为long long型
          {               //此时mid*mid<x有可能为最终值，但mid*mid>x一定不是最终值
            l = mid+1;
           ans = mid;
           }
          else
            {
             r = mid-1;  //mid*mid>x一定不是最终值,右边界不需要为mid
            }
        }
        return ans;
    }
    
};
```

**leetcode-744：比目标字母大的最小字母**

给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。

在比较时，字母是依序循环出现的。举个例子：

如果目标字母 target = 'z' 并且字符列表为 letters = ['a', 'b']，则答案返回 'a'

```c++
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
         int l = 0;
         int r =letters.size();
         while(l<r)
         {
           int mid = l+(r-l)/2;
           if(letters[mid]<=target)
           {
              l = mid+1;
           }
  //寻找比目标字母大的最小字母，如果letters[mid]<=target，证明mid不在考虑范围内所以 l = mid+1;
           else
           {
               r = mid;
 //letters[mid]>target,letters[r]可能为最终结果。循环l=mid+1直到l==r时退出
           }
         }
         return letters[l]>target?letters[l]:letters[0];
    }
};
```

**leetcode-540：有序数组中的单一元素**

给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。

请你找出并返回只出现一次的那个数。

你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。

**思路：**

**直接将数组`nums` 中的所有值 异或(`^`)起来，因为两个相同的值的异或值为 0，因此异或的结果一定是只会出现一次的数字。**

```
示例 1:

输入: nums = [1,1,2,3,3,4,4,8,8]
输出: 2
```

```c++
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
         int ans = 0;
         for(int i =0 ;i<nums.size();i++)
         {
             ans^=nums[i];
         }
         return ans;
    }
};
```

**leetcode-278：有序数组中的单一元素**

你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

```c++
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        while(l<r)
        {
           int mid = l+(r-l)/2;
            if(!isBadVersion(mid))
            {
             l = mid+1;
            }
            if(isBadVersion(mid))
            {
               r = mid; 
            }
        }
        return l;
    }
};
```

**总结：**

**模板一：**

题干：给你一个非负整数 x ，计算并返回 x 的 算术平方根 。由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。   

**思路：这种方法适用于去检索的数可以等于检索的值，或小于检索的值，(l <= h)相当于在【l，h】的闭区间内去进行检索，如果mid等于被检索的值直接返回；如果mid小于被检索的值，左边界不断进行 mid+1 去逼近右边界，如果逼近到 mid等于被检索的值 则直接返回mid ,如果左边界没有逼近到被检索的值   则就需要最终直接返回为右边界** 

```c++
public int mySqrt(int x) {
    if (x <= 1) {
        return x;
    }
    int l = 1, h = x;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        int sqrt = x / mid;
        if (sqrt == mid) {
            return mid;
        } else if (mid > sqrt) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return h;
}
```

**模板二：**

题干：给你一个排序后的字符列表 letters ，列表中只包含小写英文字母。另给出一个目标字母 target，请你寻找在这一有序列表里比目标字母大的最小字母。

**核心：使用模板二的形式  实则 本质上一定要判断 letters[mid] 是   小于等于target时是取到了真正的目标值，还是 letters[mid] 是大于等于target时  是取到了真正的目标值**

**思路：这种方法适用于去检索的数大于要检索的值，检索范围是【l,r）左闭右开区间，在letters[mid]<=target时，证明在这个范围内的数均不满足条件，所以  l = mid+1;   ，而letters[mid]>target时，r边界有可能满足条件，所以让 r = mid;，让 l左边界 不断的进行 mid+1 去逼近这个值，如果最后这个边界等于要检索的值，则最后逼近到 l 与 r只差1（l<r）时，l = mid+1;  l 则会变成 右边界 r，所以函数整体返回 l(左边界)**

```c++
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
         int l = 0;
         int r =letters.size();
         while(l<r)
         {
           int mid = l+(r-l)/2;
           if(letters[mid]<=target)
           {
              l = mid+1;
           }
  //寻找比目标字母大的最小字母，如果letters[mid]<=target，证明mid不在考虑范围内所以 l = mid+1;
           else
           {
               r = mid;
 //letters[mid]>target,letters[r]可能为最终结果。循环l=mid+1直到l==r时退出
           }
         }
         return letters[l]>target?letters[l]:letters[0];
    }
};
```

**leetcode-153：旋转数组中的最小数字**

已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

**思路：如果nums[mid]比数组最右侧的数小，则放弃mid以右侧的部分 ，但mid上的数值也有可能为数组中最小值，所以令r = mid;   如果mid比最右侧的数值大，则放弃mid以左侧部分以及mid自己，则 l= mid+1；循环中条件是  l<r .最终返回的数值是nums[l]**

```c++
示例 1：

输入：nums = [3,4,5,1,2]
输出：1
解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
```

```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
           int l = 0;
           int r = nums.size()-1;
           while(l<r)
           {        
             int mid = l+(r-l)/2;
             if(nums[mid]<nums[r])
             {
                r = mid;
             }
             else
             {
                l = mid+1; 
             }
             
           }
           return nums[l];
    }
};
```

**leetcode-34：在排序数组中查找元素的第一个和最后一个位置**

给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

```
示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
```

```c++
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
    
        int l = 0, r = nums.size() - 1; //二分范围
        while( l < r)			        //查找元素的开始位置
        {
            int mid = (l + r )/2;
            if(nums[mid] >= target) r = mid;
            else l = mid + 1;
   //左边界的查找：nums[mid] >= target 时，target有可能为mid索引上，所以令 r = mid; 如果不在索引上循环的判断语句也不会进入else .进入else判断语句后，，不断让l去逼近target的左边界，在最后一次循环时，l会被赋值为这一串target的左边界。
        }
        if( nums[r] != target) return {-1,-1};  //查找失败
        int L = r;
        l = 0, r = nums.size() - 1;     //二分范围
        while( l < r)                   //查找元素的结束位置
        {
            int mid = (l + r + 1)/2;
            if(nums[mid] <= target ) l = mid;
            else r = mid - 1;
   //右边界的查找：nums[mid] <= target ,target有可能为mid索引上，所以令 l = mid; 如果不在索引上循环的判断语句也不会进入else。。进入else判断语句后，，不断让r去不断逼近target的右边界，在最后一次循环时，r会被赋值为这一串target的右边界。。
 ************//注意：如果需要让r不断逼近的过程中，需要令mid赋值为(l + r + 1)/2;**************
        }
        return {L,r};
    }
};
```

**leetcode-671：二叉树第二小的节点**

给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。

更正式地说，即 root.val = min(root.left.val, root.right.val) 总成立。

给出这样的一个二叉树，你需要输出所有节点中的 第二小的值 。

如果第二小的值不存在的话，输出 -1 。

```c++
class Solution {
    Set<Integer> set = new HashSet<>();
    public int findSecondMinimumValue(TreeNode root) {
        dfs(root);
        if (set.size() < 2) return -1;
        int first = Integer.MAX_VALUE, second = Integer.MAX_VALUE;
        for (int i : set) {     
            //这个部分也可以利用for each循环放入数组中，然后利用Arrays.sort排序取第二小的
            if (i <= first) {
                second = first;
                first = i;
            } else if (i <= second) {
                second = i;
            }
        }
        return second;
    }
    void dfs(TreeNode root) {
        if (root == null) return;
        set.add(root.val);
        dfs(root.left);
        dfs(root.right);
    }
}
```

**leetcode-33：搜索旋转排序数组**

整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。 

```c++
示例 1：
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
```

**思路：**

如上述代码所示，我们根据 nums[mid] 与 target 的大小关系，可以得知 target 是在 mid 的左边还是右边，从而来调整左右边界 lo 和 hi。

但是，对于旋转数组，我们无法直接根据 nums[mid] 与 target 的大小关系来判断 target 是在 mid 的左边还是右边，因此需要「分段讨论」。

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
     int l = 0;
     int r = nums.size()-1;    
     while(l<=r)
     {
       int mid = l + (r-l)/2;
       if(nums[mid]==target)
       {
          return  mid;
       }
       if(nums[mid]>=nums[l])
       {
           if(nums[l]<=target&&target<nums[mid])
           {
               r = mid-1;
           }
           else
           {
               l = mid+1;
           }
       }
       else
       {
           if(nums[mid]<target&&target<=nums[r])
           {
                 l = mid+1;
           }
           else
            {
                  r = mid-1;
            }   
        }
       }
       return -1; 
     }  
};

```

##### 剑指 Offer 53 - II. 0～n-1中缺失的数字

一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

```
示例 1:
输入: [0,1,3]
输出: 2
```

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l<=r)
        {
            int m =(l+r)/2;
            if(nums[m] == m)
            {
                l = m+1;
            }
            else{
                r =m-1;
            }

        }
        return l;
    }
};
```

### 位运算

基础知识：

 x & 0s = 0 和 x & 1s = x 

 x | 0s = x 和 x | 1s = 1s 

res = a^b    ,    res&(~res+1)  这个操作取得是a与b二进制位最右侧的1。

n&（n-1）求的是转化为二进制后包含1的数量

<< 运算符优先级高于异或 “ ^ ”

自加自减运算符优先级高于左移右移运算符

uni |= (n&1)  这个操作可以按从右至左的顺序依次取出n中的元素

mask |= 1<<(str[j]-'a');  将符号转化为二进制构造出一个二进制字符串

**总结：位运算最好都加上括号**

<img src="F:\C++代码资料\Fig-DS\53.png" style="zoom:50%;" />



**leetcode-461：汉明距离**

两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。

给你两个整数 x 和 y，计算并返回它们之间的汉明距离。

```
示例 1：
输入：x = 1, y = 4
输出：2
解释：
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
上面的箭头指出了对应二进制位不同的位置。
```

```c++
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x^y;
        int cnt=0;
        while(z)
        {
           if((z&1)==1)
           {
             cnt=cnt+1;
           }
           z>>=1;    //移位等
         //位运算每次对上次的结果移动一位
           
        }
        return cnt;
    }
};
```

**leetcode-136：只出现一次的元素**

给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

```
示例 1:
输入: [2,2,1]
输出: 1
```

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int res = 0;
        for(auto num:nums)   //对智能指针做for-each循环
        {
           res = res^num;
        }
        return res;
    }
};
```

**leetcode-286：丢失的数字**

给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

```
示例 1：

输入：nums = [3,0,1]
输出：2
解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
```

```c++
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int res = 0;
      for(int i = 0;i<nums.size();i++)
      {
         res = res^nums[i];
      }
      for(int i = 0;i<=nums.size();i++)
      {
          res=res^i;
      }
      return res;
    }
};
```

🤞**leetcode-286：只出现一次的数字III**

给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

 进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？

```
示例 1：

输入：nums = [1,2,1,3,2,5]
输出：[3,5]
解释：[5, 3] 也是有效的答案。
```

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
          //这里其实取得是在这个最右侧位上的数不为0
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

**leetcode-190：颠倒比特位**

颠倒给定的 32 位无符号整数的二进制位。

```c++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t uni = 0;
        
        for(int i =0;i<32;i++)
        {
          uni |= (n&1)<<31-i ;
   //先将n的从右往左1到32位  （与1取交）分别赋值在uni的从左往右第 1到32位
          n>>=1;
     //再将n做左移运算
        }
        return uni;
    }
};
```

**不用额外变量交换两个数：**

```c++
a = a ^ b;
b = a ^ b;
a = a ^ b;
```

**leetcode-231：2的幂**

给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。

如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。

**思路：使用n&（n-1）求得转化为二进制后包含1的数量，若为2的幂，包含1的数量都只有一个**

<img src="F:\C++代码资料\Fig-DS\54.png" style="zoom:50%;" />

```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return   n>0&&(n&(n-1))==0; 
    }
};
```

**leetcode-342：4的幂**

给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x

```c++
class Solution {
public:
    bool isPowerOfFour(int n) {
       if(n<1){return false;}
       if(n==1){return true;}
       if(n%4==0){ return isPowerOfFour(n/4);}
       else {return false;}
    }
};
```

**leetcode-693：交替位二进制数**

给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。

```c++
class Solution {
public:
    bool hasAlternatingBits(int n) {
          long a =  n^(n>>1);
          return (a&(a+1))==0;
    }
};
```

**leetcode-476：数字的补数**

对整数的二进制表示取反（0 变 1 ，1 变 0）后，再转换为十进制表示，可以得到这个整数的补数。

例如，整数 5 的二进制表示是 "101" ，取反后得到 "010" ，再转回十进制表示得到补数 2 。
给你一个整数 num ，输出它的补数。

**思路：思路很简单**
**输入为 5 是 101**
**输出为 2 是 010**
**上下两个加起来就是 111 即2的3次方-1**

**输入为 8 是 1000**
**输出为 7 是 0111**
**上下两个加起来就是 1111 即2的4次方-1**

```c++
class Solution {
public:
    int findComplement(int num) {
        long a =1;
         while(true)
         {
            if(num>=a)
            {
               a<<=1;
            }
            else
            {
              return a - num - 1;
            }
         }
    }
};
```

**leetcode-338：比特位计数**

给你一个整数 `n` ，对于 `0 <= i <= n` 中的每个 `i` ，计算其二进制表示中 **`1` 的个数** ，返回一个长度为 `n + 1` 的数组 `ans` 作为答案。

**动态规划：第i个位置的数比i&(i-1)位置的数差1的关系**

```c++
class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> vec(n+1);
       for(int i = 1;i<=n;i++)
       {
          vec[i] = vec[i&(i-1)]+1;     
        }
           return vec;
    }
};
```

**leetcode-371：两整数之和**

给你两个整数 `a` 和 `b` ，**不使用** 运算符 `+` 和 `-` ，计算并返回两整数之和。

**示例 1：**

```
输入：a = 1, b = 2
输出：3
```

```c++
class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0)  
         //直到进位数为0时停止进位
        {
          unsigned int carry = (unsigned int)(a & b)<<1; 
            //进位的数不能为负数所以加unsigned int
        //进位为a与b取与运算，得到不等于1的位数后，向前进位
          a = a ^ b;  
        //进位后，a与b进行异或运算，a储存的是每进行一次进位后相加得到的数
          b = carry;
        //b储存进位的数
        }
        return a;
    }
};
```

**leetcode-318：最大单词长度乘积**

给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j]) 的最大值，并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。

```
示例 1：

输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
输出：16 
解释：这两个单词为 "abcw", "xtfn"。
```

```c++
class Solution {
public:
    int maxProduct(vector<string>& words) {
         vector<int> vec;
         int ans = 0;
         for(int i=0;i<words.size();i++ )
         {
             string str = words[i];
             int mask = 0;
             for(int j = 0;j<words[i].size();j++)
             {
                 mask |= 1<<(str[j]-'a');
      //将str的每一个元素对映成二进制型1下标，再与上一次循环得到的下标进行或等操作
      //    a:1
        //  ab:11
          //abc:111
          //abcd:1111
          //abce:1011
      //把单词转换成二进制这样的下标的int型整数再进行与操作，如果得到为0，证明两个单词没有共同的字母
             }
             vec.push_back(mask);
         }
         for(int i = 0 ;i<vec.size();i++)
         {
             for(int j=i+1;j<vec.size();j++)
             {
                if((vec[i]&vec[j])==0)
                {
                  ans = max(int(words[i].size()*words[j].size()),ans);
             //size返回的数值是一个无符号整型，所以在进行max运算时要强制转换为int型
                }
             }
         }
         return ans;
    }
};
```

##### 剑指 Offer 65. 不用加减乘除做加法

写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

```
示例:
输入: a = 1, b = 1
输出: 2
```

```c++
class Solution {
public:
    int add(int a, int b) {
        while(b)
        {
          int carry = a & b;  //计算进位的位置
          a = a^b;        //异或 计算本位
          b = (unsigned)carry<<1; 
      //该进位的向前移动,unsigned用符号位记录数字避免溢出
        }
        return a;
    }
};
```

##### 剑指 Offer 15. 二进制中1的个数

编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 [汉明重量](http://en.wikipedia.org/wiki/Hamming_weight)).）。

```
示例 1：
输入：n = 11 (控制台输入 00000000000000000000000000001011)
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
```

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n>0)
        {
           n&=n-1;
           ret++;
        }
        return ret;
    }
};
```

**观察这个运算：n&(n - 1)其预算结果恰为把 n的二进制位中的最低位的 1变为 0 之后的结果。**

##### 剑指 Offer 56 - I. 数组中数字出现的次数

一个整型数组 `nums` 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

**示例 1：**

```
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
```

**示例 2：**

```
输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
```

```c++
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> vec;
        int res = 0;
        for(int i = 0;i<nums.size();i++)
        {
            res^= nums[i];
        }
       int eor =  res&(~res+1);
       int num = 0;
       for(int i = 0;i<nums.size();i++)
       {
          if(eor&nums[i])
          {
             num^=nums[i];
          }
       }
        res ^= num; 
        vec.push_back(num);
        vec.push_back(res);
        return vec;   
    }
};
```

##### 剑指 Offer 56 - II. 数组中数字出现的次数 II

难度中等352

在一个数组 `nums` 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

**示例 1：**

```
输入：nums = [3,4,3,3]
输出：4
```

```c++
class Solution {
private:
unordered_map<int,int> hash;
public:
    int singleNumber(vector<int>& nums) {
        int k =0;
        for(auto& num:nums)
        {
           hash[num]++;
        }
        for(auto&[num,freq]:hash)
        {
           if(freq==1)
           {
                k = num;
              break;
           }
        }
           return k;
    }
};
```

##### 剑指 Offer 16. 数值的整数次方

实现 [pow(*x*, *n*)](https://www.cplusplus.com/reference/valarray/pow/) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。

**示例 1：**

```
输入：x = 2.00000, n = 10
输出：1024.00000
```

```c++
class Solution {
public:
    double fastpow(double x, int n)
    {
         double res = 1.0;  //如果n<0,返回的值是一个浮点型，所以用double去接收
         if(n<0) x = 1.0/x;
   //注意
         while(n)
         {         
           if(n&1) res*=x;
           x*=x;
           n/=2; 
      //不断右移n，再右移的过程中x不断自乘，碰见1乘上自乘完的x
         }
         return res;
    }

    double myPow(double x, int n) {
       return fastpow(x,n);
    }
};
```



### DFS

#### **leetcode-200：岛屿的数量**

给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

```c++
示例 1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1
```

```c++
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};
```

#### 剑指 Offer 13. 机器人的运动范围

难度中等525

地上有一个m行n列的方格，从坐标 `[0,0]` 到坐标 `[m-1,n-1]` 。一个机器人从坐标 `[0, 0] `的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

**示例 1：**

```
输入：m = 2, n = 3, k = 1
输出：3
```

```c++
class Solution {
public:
    
    int movingCount(int m, int n, int k) {
        vector<vector<bool>>vec(m,vector<bool>(n,0));
         return moving(m,n,0,0,vec,k);
    }
    int moving(int m,int n,int x,int y,vector<vector<bool>>&vec,int k)
    {
        if(x>=m||y>=n||vec[x][y]||cal(x)+cal(y)>k)
        {
          return 0;
        }
      vec[x][y] = true;
      return 1+moving(m,n,x+1,y,vec,k)+moving(m,n,x,y+1,vec,k);
    }
    int cal(int k)
    {   
       int val = 0;
       while(k!=0)
       {
         val+=k%10;
         k/=10; 
       }
       return val;
    }
};
```

#### **leetcode-78：子集**

给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

```
示例 1：
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

```c++
class Solution { 
    public: 
        vector<vector<int>> res; 
        vector<int> temp;
        void backtrack(vector<int>& nums,vector<int>&path,int start)
         {
        res.push_back(path);
        for(int i=start;i<nums.size();i++)
        {
             if( i>start && nums[i]==nums[i-1])//剪枝去重
                continue;
            temp.push_back(nums[i]);
            backtrack(nums,path,i+1);
            //子集元素不能重复，所以加1
            temp.pop_back();
        }
    }

vector<vector<int>> subsets(vector<int>& nums) {

    backtrack(nums, temp, 0);      
    return res;
}
};
```

子集为空的情况就是push了n次，pop了n次，子集为空。其他情况则为dfs到头以后，重新进行回溯

#### **leetcode-22：括号生成**

数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

```
示例 1：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
```

**其实此题可以看成有n对括号的排列组合问题，有多少种方法**

```c++
class Solution {
public:
    void track(vector<string>& vec,string& str,int open,int close,int n)
    {
        if(str.size()==2*n)   //n对括号，一共2n个括号字符
        {
           vec.push_back(str);
           return;
        }
        if(open<n)     //"("最多n个
        {
           str.push_back('(');
           track(vec,str,open+1,close,n);
           str.pop_back();
       }
        if(close<open)  //为了保持匹配‘（’与‘）’相同个数，所以close<open
       {
           str.push_back(')');
           track(vec,str,open,close+1,n);
           str.pop_back();
       }
    }
    vector<string> generateParenthesis(int n) {
     vector<string> vec;
     string str;
     track(vec,str,0,0,n);
     return vec;
    }
};

```

#### leetcode-79：单词搜索

给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用

<img src="F:\C++代码资料\Fig-DS\70.png" style="zoom:50%;" />

```c++
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(dfs(board,word,0,i,j)) return true;
     //遍历网格中的任意一个格子，都可以作为单词的起点，若一个子分支返回true，则搜索成功
        return false;        
    }
    int dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1}; //方向数组
    bool dfs(vector<vector<char>>& board, string& word,int u,int x,int y)
    {
        if(board[x][y] != word[u]) return false; //当中间走过的任意一个字符与word[u]不相等false
        if(u == word.size() - 1)   return true;  //递归终止条件
        char t = board[x][y];
        board[x][y] = '.';  //由于单词不能包含重复的单元格，所以对走过的标记进行标记
        for(int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i]; //4个i可以遍历完成单元格四个方向
    //这里要使用a，b，不能使用x,y自增，因为最后递归回到这里最初格子时要将board[x][y]赋值回t
            //出界或者走到已经搜索过的位置
   if(a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.')  continue;
            if(dfs(board,word,u+1,a,b)) return true;
 //u用于记录从头开始走过的总长度，每走过一步都有四种方向的走法 
 //DFS递归过程中，保持如果中间所有递归过程返回为true，则能传递回true
 //若中间任意一个子节点返回为false，，则最终结果为false
        }
        board[x][y] = t;
        return false;
    }
};
```

#### leetcode-494：目标和

给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

```
示例 1：
输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

```c++
class Solution {
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        backtrack(nums,target,0,0);
        return count;
    }
    void backtrack(vector<int>& nums, int target,int u,int sum)
    {
          if(u==nums.size())
          {
              if(sum==target)
              {
                  count++;
              }
          }
          else
          {
                backtrack(nums,target,u+1,sum+nums[u]);
                backtrack(nums,target,u+1,sum-nums[u]);
          }
    }
};
```

#### leetcode207：课程表

你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

```
示例 1：
输入：numCourses = 2, prerequisites = [[1,0]]
输出：true
解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
```

<img src="F:\C++代码资料\Fig-DS\32.jpg" style="zoom: 25%;" />

**邻接表每个节点代表每个课程序号，箭头指出的为需要先修结点这门课的课程序号**

```c++
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> gra(numCourses);
        vector<int> vec(numCourses);
         //构造一个邻接表
        for(auto p:prerequisites)
        {
            gra[p[1]].push_back(p[0]);
        }
        //逐个结点纵向DFS邻接表
        for(int i =0;i<numCourses;i++)
        {
           if(!DFS(gra,vec,i)) return false;
        }
         return true;
    }
    //使用DFS判断图中是否有环
    bool DFS(vector<vector<int>>& gra,vector<int>& vec,int j)
    {
        if(vec[j]==-1) return true;
        if(vec[j]==1) return false;
        vec[j] = 1;   //将走过的路径标记为1
     //DFS该邻接表结点的这一层所有元素
        for(auto& ele:gra[j])
        {
       //如果其中一层中含有环，则不断跳出递归返回false
           if(!DFS(gra,vec,ele)) return false;
        }
     //如果该结点所在这一邻接表的一层没有环，则标记为-1
        vec[j] = -1;
        return true;
    }
};

```

#### 剑指 Offer 64. 求1+2+…+n

求 `1+2+...+n` ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

**示例 1：**

```
输入: n = 3
输出: 6
```

**递归**

```c++
class Solution {
public:
    int sumNums(int n) {
         return n==0?0:n+sumNums(n-1);
    }
};
```

#### leetcode-301. 删除无效的括号

难度困难745

给你一个由若干括号和字母组成的字符串 `s` ，删除最小数量的无效括号，使得输入的字符串有效。

返回所有可能的结果。答案可以按 **任意顺序** 返回。

**示例 1：**

```
输入：s = "()())()"
输出：["(())()","()()()"]
```

```c++
class Solution {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
   //help之前的部分主要判断有多少多余的左括号 or 右括号  
      int lre = 0;
      int rre = 0;
      for(int i = 0;i<s.size();i++)
      {
         if(s[i]=='(')
         {
            lre++;
         }
         if(s[i]==')')
         {
            if(lre==0)
            {
                rre++;
            }
            else
            {
               lre--;
            }
         }
      }
           help(s,0,lre,rre);
           return res;
    }
       void help(string s,int start,int lre,int rre)
       {
           if(lre==0 && rre==0)
           {
               if(isValid(s))
               {
 //如果只按着非法括号的个数进行删减，那么假设一种情况 (lre==0 && rre==0) 时，只是将字符串里的左右括号的个数删减到了正常值，并不代表删减对了正确的位置，所以还要检查字符串的合理性
                   res.push_back(s);
               }
           }
          for(int i = start; i < s.size();i++)
          {
              if(i!=start && s[i]==s[i-1])     
              {
     //如果i不处在开始的位置
    例：“（     （（（        ））”
         //如果i为这三个位置，删除这三个位置中的哪个括号都是等效的，所以可以进行剪支操作             
                   continue;
              }  
               if((lre+rre)>(s.size()-i))
               {
                   return;
               }
  //回溯删除当前位置括号后重新组成一个字符串，并将重组的字符串的每个位置的括号继续进行删除
       //首先要判断lre或rre是否大于0，如果不大于零，则不需要删除这个位置的括号
             if(lre>0&&s[i]=='(')  help(s.substr(0,i)+s.substr(i+1),i,lre-1,rre);
             if(rre>0&&s[i]==')') help(s.substr(0,i)+s.substr(i+1),i,lre,rre-1);
          }
       }
        bool isValid(string s)
        {
           int cnt = 0;
           for(int i = 0;i<s.size();i++)
           {
              if(s[i]=='(')
              {
                cnt++;
              }
              if(s[i]==')')
               {
                  cnt--;
                  if(cnt<0)
                  {
                      return false;
                  }
               }
           }
            return cnt==0;
        }


};
```



### 动态规划：

#### leetcode70：爬楼梯

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

```c++
示例 1：
输入：n = 2
输出：2
解释：有两种方法可以爬到楼顶。
1 阶 + 1 阶
2 阶
```

<img src="F:\C++代码资料\Fig-DS\56.png" style="zoom:50%;" />

```c++
class Solution {
public:
    int climbStairs(int n) {
       int p = 0,q = 0, r=1;
       for(int i = 1;i<=n;i++)
       {
          p = q;        //p代表f（x-2）时的状态
          q = r;       // q代表f（x-1）时的状态
          r = p+q;
       }
        return r;
    }
};
```

#### leetcode53：最大子数组和

给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

```
示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int pre = 0, maxnum = nums[0];
       for(const auto &x:nums)
       {
          pre = max(pre+x,x);      //f（i-1）+nums[i]与nums[i]取最大值
                        //前面的和加上自身x如果比自身x小，则取自身相当于截去前面f（i-1）长度元素
          maxnum = max(maxnum,pre) //对于经过（每一个位置）的i为最后一个元素的状态求一个全局的最大值
       }
       return maxnum;
    }
};
```

<img src="F:\C++代码资料\Fig-DS\57.png" style="zoom:50%;" />

#### leetcode121：买卖股票的最佳时机

给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

```
示例 1：
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
```

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_int = 1e9;
        int inf = max_int;
        int ans = 0;
        for(int i=0;i<prices.size();i++)
        {
 //思路：最大利润等于数组中每个值减去数组中  当前（这个值之前） 最小的一个值 ，取最大
            ans = max(prices[i]-inf,ans );
            inf = min(inf,prices[i]);
        }
        return ans;
    }
};
```

#### leetcode32：最长有效括号

给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

```
示例 1：
输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
```

```c++
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for(int i= 0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
               stk.push(i);
            }
            else
            {
                stk.pop();
                if(stk.empty())
                {
                 stk.push(i);
                }
                else
                {
                  ans = max(ans,i-stk.top());
  //使用单调栈的方法：每次统计的都是这个字符串每一段连续的有效括号序列的最长长度
                }
            }
        }
        return ans;
    }
};
```

#### leetcode-62：不同的路径

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

<img src="F:\C++代码资料\Fig-DS\60.png" style="zoom:50%;" />

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> vec(m,vector<int>(n));
      for(int i = 0;i<n;i++)
      {
         vec[0][i] = 1;
      }
       for(int i = 0;i<m;i++)
      {
         vec[i][0] = 1;
      }
       for(int i =1;i<m;i++)
       {
         for(int j = 1;j<n;j++)
         {
            vec[i][j] = vec[i-1][j]+vec[i][j-1]; 
              //根据转移状态方程
         }
       }
       return vec[m-1][n-1];
    }
};
```

#### leetcode-64：最小路径和

给定一个包含非负整数的 `*m* x *n*` 网格 `grid` ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

**说明：**每次只能向下或者向右移动一步。

<img src="F:\C++代码资料\Fig-DS\61.png" style="zoom:50%;" />

```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
     int m = grid.size();
     int n = grid[0].size();
     if(m==0||n==0)   return 0;
     vector<vector<int>> vec(m,vector<int>(n));
     vec[0][0] = grid[0][0];
     for(int i = 1;i<m;i++)
     {
        vec[i][0]=vec[i-1][0]+grid[i][0];
  //根据转移状态方程，横行和竖着一列，里面的转移状态dp矩阵最小路径只有 vec[i-1][0]+grid[i][0];
 //其他情况下都经过必经之路 vec[i-1][0]，且路径更长而且原矩阵每一个值都是正数
       //所以横行vec[i-1][0]+grid[i][0]; 为最小路径
     }
     for(int i = 1;i<n;i++)
     {
        vec[0][i]=vec[0][i-1]+grid[0][i];
     }
     for(int i = 1;i<m;i++)
     {
       for(int j = 1;j<n;j++)
       {
         vec[i][j] = min(vec[i-1][j],vec[i][j-1])+grid[i][j];
        //根据转移状态方程
       }
     }
      return  vec[m-1][n-1];
    }
};
```

#### leetcode-152：乘积最大子数组

给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

测试用例的答案是一个 32-位 整数。

子数组 是数组的连续子序列。

```
示例 1:
输入: nums = [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6
```

**转移状态方程：**

![](F:\C++代码资料\Fig-DS\62.png)

```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxF(nums) , minF(nums) ;
        for(int i =1;i<nums.size();i++)
        {
            maxF[i] = max(maxF[i-1]*nums[i],max(nums[i],nums[i]*minF[i-1])); 
            minF[i] = min(maxF[i-1]*nums[i],min(nums[i],nums[i]*minF[i-1])); 
        }
        return *max_element(maxF.begin(),maxF.end());
    }
};
```

#### leetcode-198：打家劫舍

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

```
示例 1：
输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 
```

<img src="F:\C++代码资料\Fig-DS\64.png" style="zoom:50%;" />

<img src="F:\C++代码资料\Fig-DS\65.png" style="zoom:50%;" />

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
  //边界情况一定要提前考虑好，size为0返回0，只有一个房子最大是那一间
        if(nums.size()==1)
        {
            return nums[0];
        }
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
     //边界情况：只有一个房子最大是那一间，两个房子则两个之间选择一个最大的
 //由于转移状态方程 ：dp[i] = max(dp[i-2]+nums[i],dp[i-1]); 所以从i=2开始循环，把dp[0]与dp[1]
 //先找好
        for(int i=2;i<n;i++)
        {
           dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp[n-1]; 
    }
};
```

#### leetcode-96：不同的二叉搜索树

给你一个整数 `n` ，求恰由 `n` 个节点组成且节点值从 `1` 到 `n` 互不相同的 **二叉搜索树** 有多少种？返回满足题意的二叉搜索树的种数。

<img src="F:\C++代码资料\Fig-DS\67.png" style="zoom:50%;" />

**卡塔兰数：**

<img src="F:\C++代码资料\Fig-DS\68.png" style="zoom:50%;" />

```c++
class Solution {
public:
    int numTrees(int n) {
      long long C=1;  
      //下面计算得到的卡塔兰数可能会大于int的范围，所以使用long long去接收
      for(int i = 0;i<n;i++)
      {
          C = C*2*(2*i+1)/(i+2);
      }
      return C;
    }
};
```

#### leetcode-139：单词拆分

给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

```
示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
```

**背包问题：**

```
设dp[]数组表示字符串的0至i这一截匹配成功。

那么dp[i]=dp[i-word.size()]&&word==s.substr(i-word.size(),word.size())

即0至i这一截的匹配成功取决于：
0至i-word.size()这一截是否匹配成功以及s的i-word.size()至i这一截与word是否相等。


["leet","code"]
这两组成的leetcode跟codeleet不是一个东西。

而常规的背包
[2,3]
2+3=3+2
即[2,3]跟[3,2]这是两种相同的组合。

在这题中，倘若先遍历硬币再遍历背包必然会导致种类缺失，最终造成考虑不周

因此，此题必须先考虑遍历背包容量

```

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> hash;
    int n = s.size();
    vector<bool> dp(n+1,false);
    dp[0] = 1;
    for(int i =0;i<wordDict.size();i++)
    {
        hash.insert(wordDict[i]);
    }
     for(int i =1;i<=s.size();i++)
     {
        for(int j = 0;j<i;j++)
        {
           if(dp[j]&&hash.find(s.substr(j,i-j))!=hash.end())
           {
               dp[i] = true;
               break;
           }
        }
     }
       return dp[n];
    }
};
```

```
为什么第二层循环要 for(int j = 0;j<i;j++)？

在i之前要遍历一遍所有之前为true的dp数组中的值，可能会出现下面的情况：
```

<img src="F:\C++代码资料\Fig-DS\31.jpg" style="zoom:33%;" />

#### leetcode221：最大正方形

在一个由 `'0'` 和 `'1'` 组成的二维矩阵内，找到只包含 `'1'` 的最大正方形，并返回其面积。

 <img src="F:\C++代码资料\Fig-DS\72.png" style="zoom: 50%;" />

思路：

<img src="F:\C++代码资料\Fig-DS\73.png" style="zoom:50%;" />

<img src="F:\C++代码资料\Fig-DS\74.png" style="zoom:50%;" />

**外面包围一层绿色的哨兵元素，都赋值为0，为的是保证不为0的dp【1】【...】与dp【...】【1】行列维度减1后都可赋值为1**

<img src="F:\C++代码资料\Fig-DS\76.png" style="zoom: 50%;" />

```c++
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int l = matrix[0].size();
        if(r==0||l==0) return 0;
        vector<vector<int>> dp(r+1,vector<int>(l+1,0));
        int res = 0;
        for(int i=1;i<=r;i++)
        {
       //dp状态矩阵都赋值为0，刨去哨兵元素从1开始将状态矩阵赋值
            for(int j =1;j<=l;j++)
            {
                if(matrix[i-1][j-1]=='0')   continue;
             //如果原矩阵中元素为0,则跳过
                 dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1])) + 1;
                 res = max(res,dp[i][j]);
            }
        }
        return res*res;
    }
};
```

#### 剑指 Offer 10- I. 斐波那契数列

写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

```c++
class Solution {
public:
    int fib(int n) {
        int Mod = 1e9+7;
        int q = 0, p=0,r =1;
        if(n<2) return n;
 //F(0) = 0,F(1) = 1是初值，所以从i=2开始到n。q，p，r轮番更替
        for(int i=2;i<=n;i++)
        {
           q=p;
           p=r;
           r = (q+p)%Mod;
        }
        return r;
    }
};
```

#### leetcode300：最长递增子序列

给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

```
示例 1：
输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
```

<img src="F:\C++代码资料\Fig-DS\77.png" style="zoom:50%;" />

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = 1; 
     //将每个i扫过的值都赋为1，便于计算如果后面有大于这个数的取得max最大值+1为2
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
     //取vector得最大值要进行*max_element()操作
    }
};
```

**背包问题**：

<img src="F:\C++代码资料\Fig-DS\83.png" style="zoom: 50%;" />

#### leetcode-279：完全平方数

给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

```
示例 1：
输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4
```

**完全背包DP**

<img src="F:\C++代码资料\Fig-DS\78.png" style="zoom:50%;" />

```c++
class Solution {
public:
    int numSquares(int n) {
         vector<int> dp(n+1);
       // dp[i] 表示数字i最少可以由几个完全平方数相加构成
         for(int i=1;i<=n;i++)
         {
     //先逐步算出1到n-1每个数的可以最少由几个完全平方数相加构成
             dp[i] = i;
         // 最坏的情况: 所有被加起来的完全平方数都是1
            for(int j = 1;i-j*j>=0;j++)
            {
//最少完全平方数就是由到target目标数之前最大的完全平方数，而 （目标数-最大的完全平方数）其最少可以由多少个完全平方数组成的个数加上这个最大完全平方数本身个数（1）则为最小完全平方数        
                dp[i] = min(dp[i],dp[i-j*j]+1);
            }
         }
         return dp[n];
    }
};
```

#### leetcode-337：打家劫舍III

<img src="F:\C++代码资料\Fig-DS\79.png" style="zoom: 50%;" />

<img src="F:\C++代码资料\Fig-DS\80.png" style="zoom: 50%;" />

```c++
class Solution {
public:
    vector<int> dfs(TreeNode* cur)
    {
         if(cur==nullptr)   return {0,0};
         vector<int> left = dfs(cur->left);
         vector<int> right = dfs(cur->right);
         vector<int> dp(2,0);
        
      为什么dp[0]与dp[1]要服从这个顺序 ？  ？
          
         dp[0] = max(left[0],left[1])+max(right[0],right[1]);
         dp[1] = cur->val+left[0]+right[0];
         return dp;
    }

    int rob(TreeNode* root) {
         vector<int> res = dfs(root);
         return max(res[0],res[1]); 
    }
};
```

#### leetcode-322：零钱兑换

给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

```
示例 1：
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
```

<img src="F:\C++代码资料\Fig-DS\82.png" style="zoom: 50%;" />

**此题和完全平方数状态转移方程类似**

<img src="F:\C++代码资料\Fig-DS\81.png" style="zoom:50%;" />

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    // 数组大小为 amount + 1，初始值也为 amount + 1
    vector<int> dp(amount + 1, amount + 1);
    // base case
    dp[0] = 0;   //n=0时，dp[0]=0
    // 外层 for 循环在遍历所有状态的所有取值
    for (int i = 0; i < dp.size(); i++) {
        // 内层 for 循环在求所有选择的最小值
        for (int coin : coins) {
            // 子问题无解，跳过
            if (i - coin < 0) continue;
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}
};

```

#### leetcode-416：分割等和子集

给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

```
示例 1：
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。
```

**状态转移方程：**

<img src="F:\C++代码资料\Fig-DS\87.png" style="zoom:50%;" />

```c++
class Solution {
public:
    bool canPartition(vector<int>& nums) {
         int len  = nums.size();
         int sum = 0;
         for(int k:nums)
         {
            sum += k;
         }
         if((sum&1) == 1) return false;
        // 特判：由于要拆分成两个大小相等部分，如果总和是奇数，就不符合要求
         sum /= 2;
         vector<vector<bool>> dp(len,vector<bool>(sum+1,false));
    //dp[i][j]代表在0-i闭区间范围的元素中，是否可以组成总和为j
         if(nums[0]<=sum)
         {
         // 先填表格第 0 行，第 1 个数只能让容积为它自己的背包恰好装满
            dp[0][nums[0]] = true;
         }
         for(int i = 1;i<len;i++)
         {
            for(int j =0;j<=sum;j++)
            { 
      //如果j>nums[i] ,  那么证明在dp[i][j]的状态，与dp[i-1][j]的状态相同
             dp[i][j] = dp[i-1][j];
             if(j-nums[i]==0)
             {
                 dp[i][j]=true;
                 continue;
             }
         //状态转移方程：
             if(nums[i]<j)
             {
                 dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
             }
            }
         }
         return dp[len-1][sum];
    }
};
```

#### leetcode309：最佳买卖股票时机含冷冻期

给定一个整数数组`prices`，其中第 `prices[i]` 表示第 `*i*` 天的股票价格 。

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

- 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。

**注意：**你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

**示例 1:**

```
输入: prices = [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
```

<img src="F:\C++代码资料\Fig-DS\89.png" style="zoom: 50%;" />

```
DP[i][j]：i代表第i天，持有股票j=1，不持有j=0，  DP[i][j]代表第i天持有或不持有股票的 最大利润。
```

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
          if(prices.size()==0)
          {
             return 0;
          }
          int len = prices.size();
          vector<vector<int>> dp(len,vector<int>(2));
          dp[0][0] = 0;
          dp[0][1] = -prices[0];
          for(int i = 1;i<len;i++)  //注意赋值完0位置后，从1开始遍历
          {
             dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
             dp[i][1] = max(dp[i-1][1], ((i-2>=0)?dp[i-2][0]:0)-prices[i])
            //如果i-2<0,证明前一天也就是第0天利润只能为0                    
          }
        return max(dp[len-1][0],dp[len-1][1]);
    }
};
```

#### 剑指 Offer 47. 礼物的最大价值

在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

**示例 1:**

```
输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
```

```c++
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       for(int i = 1;i<m;i++) grid[i][0] += grid[i-1][0];
       for(int i = 1;i<n;i++) grid[0][i] += grid[0][i-1];
       for(int i = 1;i<m;i++)
       {
          for(int j = 1;j<n;j++)
          {
             grid[i][j] += max(grid[i-1][j],grid[i][j-1]);
          }
       }
        return grid[m-1][n-1];
    }
};
```

#### 剑指 Offer 46. 把数字翻译成字符串

给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

**示例 1:**

```
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
```

**思路：本质上就是一个跳台阶问题，只不过加了一个跳的条件。**

**跳的条件：两位字符范围是否在“10”与“25”内，在的话，就跳台阶。**

<img src="F:\C++代码资料\Fig-DS\95.png" style="zoom: 50%;" />

```c++
class Solution {
public:
    int translateNum(int num) {
       string s = to_string(num);
       int a = 1,b =1;
     //a代表f(i-1),b代表f(i-2)，c代表f(i)
       for(int i = s.size()-2;i>-1;i--)
       {
          int c = (s.substr(i,2)>="10"&&s.substr(i,2)<="25")? a+b:a ;
          b = a;
          a = c;
       }
       return a;
    }
};
```

#### leetcode-72： 编辑距离

给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符

```c++
示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
```

<img src="F:\C++代码资料\Fig-DS\97.png" style="zoom:50%;" />

**定义dp：**

`dp[i][j]` 代表 `word1` 中前 `i` 个字符，变换到 `word2` 中前 `j` 个字符，最短需要操作的次数

![](F:\C++代码资料\Fig-DS\98.png)

**思路：每一次状态转换  只考虑word1 变化成 word2；word1或word2 中最后一个字符的 替换，删除，或插入 操作**

```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
      int m = word1.size();
      int n = word2.size();
      vector<vector<int>> vec(m+1,vector<int>(n+1,0));
       for (int i = 0; i <= word1.size(); i++) vec[i][0] = i;
       for (int j = 0; j <= word2.size(); j++) vec[0][j] = j;
      for(int i = 1;i<=m;i++)
      {
          for(int j = 1;j<=n;j++)
          {
             
             if(word1[i-1]==word2[j-1])
  //如果第word1里第i个字符与word2里第j个字符相等，则与word1前i-1个字符转化到word2前j-1个字符的操作次数相同，不需要额外其他操作
             {
                 vec[i][j]=vec[i-1][j-1];
             }    
             else
             {
                 vec[i][j] = min(vec[i-1][j-1],min(vec[i][j-1],vec[i-1][j]))+1;
  // word1前i个字符转化到word2前j个字符的最小操作数，取 增删改 三个操作数的最小值
             }  
          }
      }
      return vec[m][n];
    }
};
```

#### 剑指 Offer 49. 丑数

我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

**示例:**

```
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
```

<img src="F:\C++代码资料\Fig-DS\99.png" style="zoom: 50%;" />

```c++
class Solution {
public:
    int nthUglyNumber(int n) {
      int a = 0,b = 0,c = 0;
      vector<int> dp(n);
      dp[0] = 1;
      for(int i = 1;i<n;i++)
      {
        int num1 = dp[a]*2;
        int num2 = dp[b]*3;
        int num3 = dp[c]*5; 
        int minnum = min(num3,min(num1,num2));
        if(minnum==num1) 
        {
           dp[i] = num1;
           a++;
        }  
        if(minnum==num2)
        {
           dp[i] = num2;
           b++;
        }
         
        if(minnum==num3)
        {
           dp[i] = num3;
           c++;
        } 
      }
      return dp[n-1];
    }
};
```

#### 剑指 Offer 60. n个骰子的点数

把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

**示例 1:**

```
输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
```

<img src="F:\C++代码资料\Fig-DS\102.png" style="zoom:50%;" />

**状态转移方程：**n代表骰子个数，x代表点数和。f(n,x)代表n个骰子得到点数为x的概率，转移方程代表n个骰子掷出点数为x的概率是   第n-1个骰子分别掷出点数  为 x-i （i=1-6）的概率（每个需要乘上权重1/6）之和。

<img src="F:\C++代码资料\Fig-DS\103.png" style="zoom: 50%;" />

```c++
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> dp(6,1.0/6);
   //只有一个骰子时，6个可能的和 每个概率为1/6
        for(int i = 2;i<=n;i++)
   //遍历从2-6个骰子个数
        {
            vector<double> vec(5*i+1,0);
            for(int j = 0;j<dp.size();j++)
            {
               for(int k = 0;k<6;k++)
               {
      //dp数组的每个位置都有可能再有6种加法运算
                  vec[j+k] += dp[j]/6.0;
               }
            }
            dp = vec;
        }
        return dp;
    }
};
```



### 贪心算法

#### leetcode55：跳跃游戏

给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。

```c++
示例 1：
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
```

```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_num = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(max_num<i)   return false; 
            // 如果i > max，说明这个位置跳不到，return false，可能中间就return false了
             max_num = max(max_num,i+nums[i]);
            //更新最远距离
        }
        return true;
    }
};
```

#### leetcode406：根据身高重建队列

假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

```
示例 1：
输入：people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
输出：[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
解释：
编号为 0 的人身高为 5 ，没有身高更高或者相同的人排在他前面。
编号为 1 的人身高为 7 ，没有身高更高或者相同的人排在他前面。
编号为 2 的人身高为 5 ，有 2 个身高更高或者相同的人排在他前面，即编号为 0 和 1 的人。
编号为 3 的人身高为 6 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
编号为 4 的人身高为 4 ，有 4 个身高更高或者相同的人排在他前面，即编号为 0、1、2、3 的人。
编号为 5 的人身高为 7 ，有 1 个身高更高或者相同的人排在他前面，即编号为 1 的人。
因此 [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] 是重新构造后的队列。
```

<img src="F:\C++代码资料\Fig-DS\85.png" style="zoom: 67%;" />

```c++
class Solution {
public:
    //用于sort比较大小的适配器：
    // 先将 身高（0索引）按从大到小排好，若同一身高下再对前面的人数按从小到大排列
    static bool cmp(vector<int> a,vector<int> b)
    {
        if(a[0]==b[0])  return a[1]<b[1] ;
        return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
           sort(people.begin(),people.end(),cmp); 
            //按一定规则排序这里的适配器必须是static类型的
           vector<vector<int>> res;
           for(int i = 0;i<people.size();i++)
           {
               int index = people[i][1];
  //将前面排列好的vector: 较大的值在前面先插入，较小的vector后插入到较大vector前，这样可以保证：较大vector的第二个索引上的数依然满足不会发生变化
     //分别有序插入构造出新的重建队列
               res.insert(res.begin()+index,people[i]);
           }
          return res;
    }
};
```





### 排列组合

##### leetcode17：电话号码的字母组合

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

<img src="F:\C++代码资料\Fig-DS\59.png" style="zoom: 67%;" />

```
示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

```c++
class Solution {
public:
      string tmp;
      vector<string> vec;
      vector<string> board={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      void DFS(int pos,string digits) 
    {
        if(pos==digits.size())
        {
           vec.push_back(tmp);
           return;
        //回溯终止
        }
         int res = digits[pos]-'0';
      //记录要回溯到的board中第几个数字代表的字符串
        for(int i = 0;i<board[res].size();i++)
        {
      //在每一个digits数字的位置，排列组合出所有可能的字符串
           tmp.push_back(board[res][i]);
           DFS(pos+1,digits);
           tmp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
       if(digits.size()==0) return vec;
       DFS(0,digits);
       return vec;
    }
     
};
```

##### leetcode46：全排列

给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

```
示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

```c++
class Solution {
public:
    vector<vector<int>> vec;
    vector<int> res;
    vector<bool> bol;
    void DFS(vector<int>& nums)
    {
        if(res.size()==nums.size())
        {
           vec.push_back(res);
           return;
        }
        for(int i = 0;i<nums.size();i++)
        {
             if(!bol[i])
             {
               bol[i] = true;  
         //用来标记当前以i为下标的元素已使用过，下一次递归时跳过本元素
               res.push_back(nums[i]);
               DFS(nums);
               res.pop_back();
               bol[i] = false;
        //该轮位置循环结束后，枚举第二种元素在该位置的组合方式，当前元素可用于下一轮递归，所以取消标记
             }  
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())  return vec ;
        int n = nums.size();
        bol.resize(n,false);
        DFS(nums);
        return vec;
    }
};
```

##### leetcode39：组合总和

给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

```
示例 1：
输入：candidates = [2,3,6,7], target = 7
输出：[[2,2,3],[7]]
解释：
2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
7 也是一个候选， 7 = 7 。
仅有这两种组合。
```

<img src="F:\C++代码资料\Fig-DS\69.png" style="zoom:50%;" />

```c++
class Solution {
public:
        vector<vector<int>> vec;
        vector<int> res;
     void combine(vector<int>& candidates,int u,int target)
     {
        if(target<0)  return ;
        if(target==0)
        {
          vec.push_back(res);
          return;   
        }
         
          for(int i=u;i<candidates.size();i++)
       //这里循环的u是精髓，减支了每个分支u之前的部分，避免了重复
          {
              if(candidates[i]<=target)
              {
                res.push_back(candidates[i]);
                combine(candidates,i,target-candidates[i]);
            //由于数组中数可以重复，所以第二个参数传入i
                res.pop_back();
              }
 //相当于对第一个数，所有包含第一个数的情况都搜索一遍后。遍历到第二个数时，选择从第二个数开始计算包含第二个数但不包含第一个数的所有集合
        
          }  


     }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combine(candidates,0,target);
        return vec;
    }
};
```

##### 剑指 Offer 38. 字符串的排列

输入一个字符串，打印出该字符串中字符的所有排列。

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

**示例:**

```
输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
```

**思路：先对字符串进行sort排序后，相同的字符就在一起了，便于在排列组合时对字符串中相同的字符进行减支，去重操作**

```c++
class Solution {
public:
     vector<string> res;
     vector<int> vec; 
    void dfs(string& str,int cnt,int n,const string& s)
    {
          if(cnt==n)
          {
             res.push_back(str);
             return;
          }
          for(int i = 0;i<n;i++)
          {
            if(vec[i]||(i>0 && !vec[i-1] && s[i]==s[i-1]))
  //vec用于标记该字符是否在这次排列中使用过，i>0 &&!vec[i-1] && s[i]==s[i-1] 代表由于排序后前一个字符与后一个字符相同，且前一个字符恢复了未标记前的状态，这时由于对该同样的字符排列组合过，可进行减支，去重   
            {
               continue;
            }
            vec[i] = true;
            str.push_back(s[i]);
            dfs(str,cnt+1,n,s);
            str.pop_back();
            vec[i] = false;
          }

    } 
     
    vector<string> permutation(string s) {
         int n = s.size();
         vec.resize(n);
         string str;
         sort(s.begin(),s.end());
         dfs(str,0,n,s);
         return res;
    }


};
```

### 数学推理

##### 剑指 Offer 62. 圆圈中最后剩下的数字

0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

**示例 1：**

```
输入: n = 5, m = 3
输出: 3
```

```c++
                       //思路：从最后一轮层层反推到第一轮
class Solution {
public:
    int lastRemaining(int n, int m) {
        int ans = 0;
        for(int i =2;i<=n;i++)
        {
//最初数的位置可由最后一轮进行反推，最后一轮剩2个数，公式就是 pos = （上一轮pos+每次删除的第几个数）%上一轮剩余数字个数
           ans = (ans+m)%i;
        }
        return ans;
    }
};
```

##### 剑指 Offer 43. 1～n 整数中 1 出现的次数

输入一个整数 `n` ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

**示例 1：**

```
输入：n = 12
输出：5
```

**限制：**

- `1 <= n < 2^31`

**思路**

1.当 cur=0 时： 此位 1 的出现次数只由高位 high 决定，计算公式为：high×digit 

2.当 cur=1 时： 此位 1 的出现次数由高位 high 和低位 low 决定，计算公式为：high×digit+low+1

3.当 cur=2,3,⋯,9 时： 此位 1的出现次数只由高位 high 决定，计算公式为：(high+1)×digit

```c++
class Solution {
public:
    int countDigitOne(int n) {
         long digit = 1;   //注意这道题这里数据量是1 <= n < 2^31，不使用long会溢出
         int cur = n%10;
         int high = n/10;
         int low = 0;
         int res= 0;
         while(high!=0||cur!=0)
         {
            if(cur == 0)
            {
               res += high*digit;
            }
            else if(cur == 1)
            {
               res += high*digit+1+low;
            }
            else
            {
                res += (high+1)*digit;
            }
        //这里的细节：顺序很重要
            low += digit*cur;
            cur =  high % 10;          
            high/=10;
            digit*=10;
            
         }
         return res;
    }
};
```

##### 剑指 Offer 14- I. 剪绳子

给你一根长度为 `n` 的绳子，请把绳子剪成整数长度的 `m` 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 `k[0],k[1]...k[m-1]` 。请问 `k[0]*k[1]*...*k[m-1]` 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

**示例 1：**

```
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
```

```c++
class Solution {
public:
    int cuttingRope(int n) {
     //根据数学专家我们可以知道，分成多段长度为3的绳子相乘的积最大。
     if(n<=3)    // 题目要求至少分成两段，对于小于等于3的返回n-1
     {
         return n-1;
     }
     int modnum = n%3;
     int num = n/3;
     // 余数分三种情况：余数只能为0，1，2时
     if(modnum==0)   //余数为0
     {
         return pow(3,num);
     }
     if(modnum==1)   // 为1，将一个3*1转变为2*2
     {
         return pow(3,num-1)*4; 
     }
         // 余为2
         return pow(3,num)*2;
     
    }
};
```

##### 剑指 Offer 14- II. 剪绳子 II

给你一根长度为 `n` 的绳子，请把绳子剪成整数长度的 `m` 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 `k[0],k[1]...k[m - 1]` 。请问 `k[0]*k[1]*...*k[m - 1]` 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

**示例 1：**

```
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
```

```c++
class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3)
        {
           return n-1;
        }
        int a = n/3;
        int b = n%3;
        if(b==0)
        {
           return powf(3,a);
        }
        if(b==1)
        {
           return powf(3,a-1)*4%1000000007;
        }
           return powf(3,a)*2%1000000007;
    }
        long powf(int m,int n)
        { 
            long val = 1;
           for(int i = 0;i<n;i++)
           {
              val=val*m%1000000007;
         //这种取模的情况数据量较大，需要用long去接收
           }
           return val;
        }
};
```

##### leetcode-202. 快乐数

编写一个算法来判断一个数 `n` 是不是快乐数。

**「快乐数」** 定义为：

- 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
- 然后重复这个过程直到这个数变为 1，也可能是 **无限循环** 但始终变不到 1。
- 如果这个过程 **结果为** 1，那么这个数就是快乐数。

如果 `n` 是 *快乐数* 就返回 `true` ；不是，则返回 `false` 。

**示例 1：**

```
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

**示例 2：**

```
输入：n = 2
输出：false
```

**思路：快慢指针，程序会以next(slow) == next(next(fast)) 为结束条件，但快慢指针相等时，不一定都为1，都为1的时候返回true**

```c++
class Solution {
public:
    bool isHappy(int n) {
    int slow = n;
    int fast = n;
     do
     {
        slow = next(slow);
        fast = next(next(fast));
     }while(slow!=fast);
      
      return slow==1;
    }
    int next(int n)
    {
     int temp = 0;
      while(n!=0)
     {
        int bin = n%10;
        n/=10;
        temp += bin*bin;
     }
     return temp;
    }
};
```

##### leetcode-970. 强整数

给定三个整数 `x` 、 `y` 和 `bound` ，返回 *值小于或等于 `bound` 的所有 **强整数** 组成的列表* 。

如果某一整数可以表示为 `xi + yj` ，其中整数 `i >= 0` 且 `j >= 0`，那么我们认为该整数是一个 **强整数** 。

你可以按 **任何顺序** 返回答案。在你的回答中，每个值 **最多** 出现一次。

**示例 1：**

```
输入：x = 2, y = 3, bound = 10
输出：[2,3,4,5,7,9,10]
解释： 
2 = 20 + 30
3 = 21 + 30
4 = 20 + 31
5 = 21 + 31
7 = 22 + 31
9 = 23 + 30
10 = 20 + 32
```

```c++
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> s;
        int ans = 0;
        for(int i = 0;;i++)
        {
            int k = pow(x,i);
           if(k>bound) break;
           for(int j=0;;j++)
           {
              int z = pow(y,j);    
              if(k+z>bound) break;
              s.insert(k+z);
              if(y==1) break;
            //当y为1时，只枚举一次y得幂次就好了
           }
            if(x==1) break;
             //当x为1时，只枚举一次x得幂次就好了
        }    
         return vector<int>(s.begin(),s.end());

    }
};
```

##### 剑指 Offer 44. 数字序列中某一位的数字

数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。

**示例 1：**

```
输入：n = 3
输出：3
```

<video id="video" controls="" preload="none" poster="">
      <source id="mp4" src="F:\C++代码资料\Fig-DS\数字序列中某一位的数字.mp4" type="video/mp4">
      </video>

```c++
class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1;
        long count = 9,start=1;
        while(n>count)
        {
           n-=count;
           start*=10;
           digit+=1;     //计算当前数字的宽度位数
           count = digit*start*9;   
     // 9是第9位，10~99共180位，计算当前digit对应的位数
        }
      //举个例子，9是第9位，10~99共180位，189位就是99中的后一个9
        long res = start + (n-1)/digit;  
     //计算当前数字是多少
        int cnt = (n-1)%digit;
     //计算第n位在当前数字中的位置
        string str = to_string(res);
        int ans = str[cnt]-'0' ;
        return ans; 
    }
};
```

