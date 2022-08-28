# Mysql笔记

<img src="D:\java学习资料\Mysql_image\1.png" style="zoom: 33%;" />

<img src="D:\java学习资料\Mysql_image\2.png" style="zoom: 67%;" />

<img src="D:\java学习资料\Mysql_image\3.png" style="zoom: 33%;" />

<img src="D:\java学习资料\Mysql_image\4.png" style="zoom: 50%;" />

<img src="D:\java学习资料\Mysql_image\5.png" style="zoom: 50%;" />

![](D:\java学习资料\Mysql_image\6.png)



<img src="D:\java学习资料\Mysql_image\7.png" style="zoom: 50%;" />

<img src="D:\java学习资料\Mysql_image\8.png" style="zoom:50%;" />

## 一.DQL

1.查询字段

```sql
SELECT name，age FROM employees;
```

细节问题：

1.鼠标选择要运行的程序部分，点击运行

2.在查询表中字段时，前面要先加上    

```sql
use test；  #test是要查询的表名。
```

2.查询常量值

```sql
SELECT 100;
SELECT 'John'; #SQL中查询字符与字符串不区分字符串与字符，只有一个字符型
```

3.查询表达式

```sql
SELECT 100*3; 
```

4.查询函数

```sql
SELECT VERSION();
```

5.起别名

<img src="D:\java学习资料\Mysql_image\9.png" style="zoom:50%;" />

```sql
SELECT firstname AS 名，lastname AS 姓 FROM employees;
SELECT firstname 名，lastname 姓 FROM employees; #AS也可以省略
SELECT salary AS "工资" FROM employees; #有命名冲突可以使用“”
```

6.去重

```sql
SELECT DISTINCT department_id FROM employees; #从表中查询到的部门编号有好多是重复的可以采用去重
```

7.“+”的作用

<img src="D:\java学习资料\Mysql_image\10.png" style="zoom:50%;" />

8.concat的作用

```sql
SELECT CONCAT('firstname','lastname') AS 姓名  #将'firstname','lastname'两个列合并拼接
FROM employees；
```

显示出表employees中全部的列，列名用逗号连接，列头显示成out_put:

```mysql
SELECT CONCAT('firstname','lastname','job_id',IFNULL('commission_pct',0)) AS out_put FROM emploees
#commission_pct这列中有空值，如果有null，那么一连接整个列都会显示成null，所以使用IFNULL语句，如果有null就将他转化成0
```

SQL语句编译顺序：

<img src="D:\java学习资料\Mysql_image\11.png" style="zoom: 33%;" />

![](D:\java学习资料\Mysql_image\12.png)

9.模糊查询：

查询出员工的姓氏中第三个字符为n，第五个字符为l的员工的工资：

```mysql
SELECT salary FROM emploees WHERE last_name LIKE '__n_l%'
```

查询出员工的姓氏中第二个字符为_的员工名：

```mysql
SELECT last_name FROM emploees WHERE last_name LIKE '_$_%' ESCAPE '$'
#_代表单个字符的通配符，%可代表多个字符的通配符，ESCAPE可以代表将任何符号转化为转义字符，$在变为转义字符以后后面的_的意义就不是通配符了，而是字符‘_’
```

<img src="D:\java学习资料\Mysql_image\13.png" style="zoom: 50%;" />

**<u>注：BETWEEN AND 包含边界</u>**

<img src="D:\java学习资料\Mysql_image\14.png" style="zoom:33%;" />

```mysql
SELECT last_name，job_id FROM emploees WHERE job_id IN ('IT_PROT','AD_VD','AD_PRES')
```

<u>**注：IN后面的括号不能带通配符，因为通配符是给LIKE用的**</u>

<img src="D:\java学习资料\Mysql_image\15.png" style="zoom: 50%;" />

<u>**注：不能用IS判断其他的值，IS只能与NULL或NOT NULL联用**</u>

```mysql
SELECT last_name，commission_pct FROM employees WHERE commission_pct IS NULL;
```

<img src="D:\java学习资料\Mysql_image\16.png" style="zoom:50%;" />

```mysql
SELECT last_name，commission_pct FROM employees WHERE commission_pct <=>NULL;
#<=>既可以判断null值也可以判断基础数据类型
```

<img src="D:\java学习资料\Mysql_image\17.png" style="zoom: 50%;" />

第一种与第二种是不一样的，第一张如果where中有一个为null，则不与题干等价。而第二种可以看出总有一个字段是不为null的则与题干等价。

<img src="D:\java学习资料\Mysql_image\18.png" style="zoom:50%;" />

IS NULL用来判断是否为null，如果是返回1，否则返回0

<img src="D:\java学习资料\Mysql_image\19.png" style="zoom:50%;" />

```mysql
SELECT * FROM employees ORDER BY salary DESC;
#DESC:降序 ASC：升序 ，不写默认降序
```

<img src="D:\java学习资料\Mysql_image\20.png" style="zoom:50%;" />

按员工年薪降序（表达式）进行排序：

```mysql
SELECT * ，salary*（IFNULL(commission_pct,0)+1）AS 年薪 FROM employees ORDER BY salary*（IFNULL(commission_pct,0)+1）DESC;
```

按员工姓名长度降序（函数）进行排序：

```mysql
SELECT LENGTH(last_name) FROM employees ORDER BY  LENGTH(last_name)  DESC;
```

按多个字段进行排序：

```mysql
SELECT ageFROM employees ORDER BY  LENGTH(last_name)  DESC， LENGTH(first_name）ASC;
#多字段进行排序，先对last_name长度进行降序，在last_name长度相同时按first_name长度进行升序排序                                                            
```

<img src="D:\java学习资料\Mysql_image\21.png" style="zoom:50%;" />

一般都是先筛选完字段，在进行排序，所以ORDER BY一般放在最后

<img src="D:\java学习资料\Mysql_image\23.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\24.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\25.png" style="zoom:50%;" />

UTF-8字符集中汉字占三个字节，单个英文字母占一个字节，JDK中汉字占两个字节

![](D:\java学习资料\Mysql_image\26.png)

```mysql
SELECT CONCAT(UPPER(SUBSTR(last_name,1,1)),'_',LOWER(SUBSTR(last_name,2))) OUT_PUT FROM emploees;
```

<img src="D:\java学习资料\Mysql_image\27.png" style="zoom:50%;" />

```mysql
SELECT INSTR('666777888','666') AS out_put;
#INSTR返回666第一次出现的索引位置
SELECT LENGTH( TRIM ('   777   ')) AS out_put;
#TRIM去除两边的部分
SELECT TRIM（‘aa’ FROM ‘aa666aa788aaaaaaa’）AS out_put;
#去除两边的a
```

<img src="D:\java学习资料\Mysql_image\28.png" style="zoom: 50%;" />

```mysql
SELECT REPLACE (‘aa666aa788’,'aa','bb'）AS out_put;
#将aa666aa788中的aa换成bb
```

<img src="D:\java学习资料\Mysql_image\29.png" style="zoom:50%;" />

如果本身长度超出了lpad要填充完的长度，就从右边截断

<img src="D:\java学习资料\Mysql_image\30.png" style="zoom:50%;" />

TRUNCATE代表保留几位小数,ROUND代表四舍五入,MOD(a，b)得到的数的正负要看被除数a的正负

<img src="D:\java学习资料\Mysql_image\32.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\33.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\34.png" style="zoom:50%;" />

![](D:\java学习资料\Mysql_image\35.png)

![](D:\java学习资料\Mysql_image\36.png)

```mysql
SELECT last_name,DATE FORMATE(hiredate,'%C月/%D日  %Y年') AS 入职日期 FROM employees WHERE commission_pct IS NOT NULL;
```

<img src="D:\java学习资料\Mysql_image\37.png" style="zoom:50%;" />

```mysql
SELECT last_name,commission_pct,IF(commission_pct IS NULL,'没','有') AS 备注 FROM employees;
```

<img src="D:\java学习资料\Mysql_image\38.png" style="zoom:50%;" />

```mysql
SELECT salary，department_id, CASE department_id WHEN 30 THEN salary*1.1  WHEN 40 THEN salary*1.2 ELSE salary END AS 新工资 FROM employees；
```

<img src="D:\java学习资料\Mysql_image\39.png" style="zoom:50%;" />

switch应用于等值判断，多重if应用于区间

<img src="D:\java学习资料\Mysql_image\40.png" style="zoom:50%;" />

```mysql
SELECT salary，CASE WHEN salary>20000 THEN 'A ' WHEN salary>15000 THEN 'B' ELSE 'C' END AS 工资级别 FROM employees；
```

![](D:\java学习资料\Mysql_image\41.png)

COUNT（）用来统计非null的个数

<img src="D:\java学习资料\Mysql_image\42.png" style="zoom:50%;" />

分组函数像求和，求最大值都比较智能，能忽略null值

和distinct搭配，SELECT COUNT（DINSTINCT salary），,COUNT(salary) FROM employees；

DINSTINCT 相当于去重在相加

<img src="D:\java学习资料\Mysql_image\43.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\44.png" style="zoom:50%;" />

COUNT(*)用来统计行数

MYISAM引擎下，有一个计数器便于直接获取所有行数，所以COUNT（*）效率高

INNODB引擎下COUNT(字段）稍微低一些，因为COUNT（字段）需要判断当前是否为null

<img src="D:\java学习资料\Mysql_image\45.png" style="zoom:50%;" />

COUNT(1)的意思是在右侧列补上一列1，统计有n行1，n为表格一共有多少行

SELECT AVG(salary)，employees_id FROM employees;不能这样去写，因为AVG是分组函数得到的值是一个，而employees_id 是一共有n个列，所以最好不能放到一起

ROUND（，2）保留两位小数

<img src="D:\java学习资料\Mysql_image\46.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\47.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\48.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\49.png" style="zoom:50%;" />

```mysql
SELECT MAX(salary),employees_id FROM employees GROUP BY employees_id;
#要GROUP BY分组的那一列要放在SELECT 旁边，这样才能显示出哪一组哪一组的最高工资
SELECT COUNT(*),location_id FROM employees GROUP BY location_id;
```

<img src="D:\java学习资料\Mysql_image\50.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\51.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\52.png" style="zoom:50%;" />

```mysql
SELECT MIN(salary),manager_id FROM employees WHERE manager_id>102 GROUP BY manager_id MIN(salary)>5000;
```

<img src="D:\java学习资料\Mysql_image\53.png" style="zoom:50%;" />

<u>**注：能用具体表里做条件的筛选的，就用where放在GROUP BY前面,不能就用Having**</u>

<img src="D:\java学习资料\Mysql_image\54.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\55.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\56.png" style="zoom:50%;" />

```mysql
SELECT name，boyname From boys，beauty WHERE beauty.id = boys.id;
```

<img src="D:\java学习资料\Mysql_image\57.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\58.png" style="zoom:50%;" />

```mysql
SELECT e.last_name,e.job_id,j.job_title FROM employees  e,job.j WHERE e.job_id=j.job_id;
#如果起了表的别名，就不能使用原有的表名去限定，起了别名以后会生成一个视图
```

<img src="D:\java学习资料\Mysql_image\59.png" style="zoom:50%;" />

```mysql
SELECT department_name,city FROM locations l,departments WHERE l.locations_id =  department_id AND city LIKE '_o%';
```

<img src="D:\java学习资料\Mysql_image\60.png" style="zoom: 50%;" />

```mysql
SELECT last_name,department_name,city FROM employees e,dempartments d,locations l WHERE e.departments_id = d.departments_id AND d.locations_id =l.locations_id;
```

可以把部门，员工，地点表想象成三层的树状结构。

<img src="D:\java学习资料\Mysql_image\61.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\62.png" style="zoom:50%;" />

<u>**非等值连接**</u>    在where处使用BETWEEN AND的形式

<u>**自连接**</u>

```mysql
SELECT e.employees__id,e.last_name,m.employees__id,m.last_name FROM employees e, employees m WHERE e. manager_id = m.employees__id;
```

<img src="D:\java学习资料\Mysql_image\63.png" style="zoom: 50%;" />

<img src="D:\java学习资料\Mysql_image\64.png" style="zoom: 67%;" />

<img src="D:\java学习资料\Mysql_image\65.png" style="zoom: 67%;" />

<img src="D:\java学习资料\Mysql_image\66.png" style="zoom: 67%;" />

<img src="D:\java学习资料\Mysql_image\68.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\69.png" style="zoom: 67%;" />

<img src="D:\java学习资料\Mysql_image\71.png" style="zoom:50%;" />

**distinct可以与聚合（统计）函数搭配使用，实现去重的统计.**

<img src="D:\java学习资料\Mysql_image\72.png" style="zoom:50%;" />

**经过group by以后的字段与分组函数一同查询后才比较规则.**

<img src="D:\java学习资料\Mysql_image\73.png" style="zoom: 67%;" />

<img src="D:\java学习资料\Mysql_image\74.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\76.png" style="zoom:50%;" />

**聚合函数一定要加GROUP BY，HAVING属于分组之后再分组，一般将再分组的条件的关键词也放在SELECT里**

#### **sql99语法**

<img src="D:\java学习资料\Mysql_image\77.png" style="zoom: 67%;" />

<img src="D:\java学习资料\Mysql_image\78.png" style="zoom:50%;" />

```mysql
SELECT job_title,last_name FROM employees e INNER JOIN job j ON e.job_id = j.job_id WHERE e.last_name LIKE "%e%";
```

<img src="D:\java学习资料\Mysql_image\79.png" style="zoom:50%;" />

```mysql
SELECT CITY,COUNT(*) 部门个数 FROM departments d INNER JOIN locations l ON d.location_id = l.location_id GROUP BY city HAVING COUNT(*)>3;
#只要有使用聚合函数（count （）。。。。）的地方进行再分组的位置一定有GROUP BY，因为HAVING再分组以后在SELECT中显示的属性一定要与他旁边的属性整齐一致，所以要有GROUP BY对他旁边的属性再分组
```

<img src="D:\java学习资料\Mysql_image\80.png" style="zoom:50%;" />

**COUNT(*)>3代表两表部门编号相同并连接在一起后大于3行的员工个数**

<img src="D:\java学习资料\Mysql_image\81.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\82.png" style="zoom:50%;" />

**两次连接 INNER JOIN ON 与INNER JOIN ON之间需要分开写**

**内连接：等值，非等值，自连接都是取得是 交集  部分**

<img src="D:\java学习资料\Mysql_image\83.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\84.png" style="zoom:50%;" />

```mysql
 SELECT d.*,employees_id  FROM departments d LEFT OUTER JOIN employees e ON d.department_id = e.department_id WHERE e.employees_id IS NULL;
 #SELECT选择哪个表格中的字段，主表就是那个表格，另一个就是从表。左外连接中主表出现在左侧，从表出现在右侧。FROM后面跟的是主表，LEFT OUTER JOIN 后面跟的是从表，如果是右外则相反。
```

<img src="D:\java学习资料\Mysql_image\86.png" style="zoom:50%;" />

**交叉连接就是用sql99中的CROSS JOIN 代替92中的逗号，就是笛卡尔乘积**

<img src="D:\java学习资料\Mysql_image\87.png" style="zoom:50%;" />

**左外连接的where子句中由于查询的是跟A表匹配的B的key为空的，所以B的key为空的那一部分B表为从表显示在右侧，所以WHERE中填的是B.key IS NULL; B中的主键就是KEY显示在Mysql中应该是小钥匙的形状（非空）**

**主表一般为 主从表显示之后没有空着的那部分表**

<img src="D:\java学习资料\Mysql_image\88.png" style="zoom:50%;" />

```mysql
SELECT e.*,d.department_name,d.department_id FROM departments d LEFT  JOIN emplyees e ON e.department_id = d.department_id  WHERE department_name IN('SAL','IT') ;
#这道简单的题为什么要采用外连接？因为部门名为 SAL 与IT的两个部门有可能存在部门名相同，部门id不同。部门id不同，员工信息可能为空的情况，所以采用外连接将信息展示的更全面一些
```

<img src="D:\java学习资料\Mysql_image\89.png" style="zoom:33%;" />

<img src="D:\java学习资料\Mysql_image\90.png" style="zoom: 50%;" />

<img src="D:\java学习资料\Mysql_image\91.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\92.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\93.png" style="zoom:50%;" />

**<u>注：因为使用了大于号，所以只能使用标量子查询，所以不加MIN（）会报错</u>**

**标量子查询只能一行一列**

<img src="D:\java学习资料\Mysql_image\94.png" style="zoom:50%;" />

**\**>ALL( , ,)意味着大于括号内最大的 值****

**\>ANY( , , , )意味着大于括号内最小的值**

<img src="D:\java学习资料\Mysql_image\96.png" style="zoom:50%;" />

```mysql
SELECT DISTINCT department_id FROM departments WHERE location_id in(1400,1700)；

SELECT last_name FROM employees WHERE department_id IN(SELECT DISTINCT department_id FROM departments WHERE location_id in(1400,1700)
);

#因为内层返回的是很多个department_id列表,而在外层再嵌套一个IN代表着这些列表值（部门编号）里的员工都算上可以放在一起
#可以理解成IN（A,B）括号内的是A or B。
#IN（   ）可以替换成 = ANY（   ）
#NOT IN(   )也可以替换成 <>ALL(   )
```

<img src="D:\java学习资料\Mysql_image\97.png" style="zoom:50%;" />

```mysql
SELECT DINSTINCT salary FROM employees WHERE job_id = 'IT_PROG'
#不要忘记加上DINSTINCT
SELECT employees_id,last_name,job_id,sarlary FROM employees WHERE  salary<ALL( SELECT DINSTINCT salary FROM employees WHERE job_id = 'IT_PROG') AND job_id<>'IT_PROG';

#子查询后面不能忘记加上 AND job_id<>'IT_PROG'; 因为需要保证自身不是和‘IT_PROG'相同的job_id

```

<img src="D:\java学习资料\Mysql_image\98.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\100.png" style="zoom:50%;" />

```mysql
SELECT (SELECT department_name FROM departments d INNER JOIN employees e ON d.department_id = e.department_id WHERE  e.employees_id = 102 ) 部门号
#SELECT后的子查询必须是单行单列的
```

<img src="D:\java学习资料\Mysql_image\101.png" style="zoom:50%;" />

**题干：查询每个部门的平均工资和工资等级**：

<img src="D:\java学习资料\Mysql_image\102.png" style="zoom:50%;" />

```mysql
SELECT  ag_dep .* , g.grade_level FROM (SELECT AVG（salary），department_id FROM employees GROUPY BY department_id) ag_dep INNER JOIN job_grades g ON ag_dep .AVG（salary）BETWEEN lowest_sal AND highest_sal;
#正常的sql语句都是子查询先执行，但是EXISTS是先执行外查询，再进行过滤
```

**正常的sql语句都是子查询先执行，但是EXISTS是先执行外查询，再进行过滤**

<img src="D:\java学习资料\Mysql_image\104.png" style="zoom:50%;" />

```mysql
SELECT department_name FROM departments d WHERE EXISTS(SELECT * FROM employees WHERE e.departments_id = d.departments_id);
```

<img src="D:\java学习资料\Mysql_image\105.png" style="zoom:50%;" />

**limit 后面的offset为起始索引可选也可省略，size表示要显示的条目数（并不是终止索引）**

<img src="D:\java学习资料\Mysql_image\106.png" style="zoom:50%;" />

**已知页数与size求起始索引：**

<img src="D:\java学习资料\Mysql_image\107.png" style="zoom:50%;" />

**LIMIT是在ORDER BY以后最后执行的**。

<img src="D:\java学习资料\Mysql_image\108.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\109.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\111.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\110.png" style="zoom:50%;" />

默认升序排序，完了取第一条数据

<img src="D:\java学习资料\Mysql_image\112.png" style="zoom:50%;" />

```mysql
SELECT d.* FROM departments d WHERE department_id = (SELECY department_id FROM employees WHERE GROUP BY department_id ORDER BY AVG(salary) ASC LIMIT 1);
```

<img src="D:\java学习资料\Mysql_image\113.png" style="zoom:50%;" />

```mysql
SELECT d.*,ag FROM deparyments d INNER JOIN (SELECY AVG(sarlary) department_id FROM employees WHERE GROUP BY department_id ORDER BY AVG(salary) ASC LIMIT 1) ag_dep ON d. department_id =ag_dep. department_id;
#使用先按平均工资升序排列，再用LIMIT 1 --- 取平均工资中最少的工资，得到id 的子查询方式
```

<img src="D:\java学习资料\Mysql_image\114.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\115.png" style="zoom:50%;" />

在1988-1-1后： WHERE DATEDIFF(borndate,1988-1-1)>0;

<img src="D:\java学习资料\Mysql_image\116.png" style="zoom:33%;" />

```mysql
SELECT COUNT(*) 个数,sex，major_id FROM student GROUP BY sex,manager_id;
```

##### 查询专业编号与张翠山一样的学生的最低分

<img src="D:\java学习资料\Mysql_image\117.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\118.png" style="zoom:50%;" />

考虑有的学生没有分数，所以使用外连接实现

##### 要学会使用COUNT(**)，COUNT(**)代表查询到的结果的总行数

<img src="D:\java学习资料\Mysql_image\119.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\120.png" style="zoom:50%;" />

<img src="D:\java学习资料\Mysql_image\121.png" style="zoom:50%;" />

两个表所查询的信息一致：

<img src="D:\java学习资料\Mysql_image\123.png" style="zoom: 50%;" />


<img src="D:\java学习资料\Mysql_image\122.png" style="zoom:50%;" />
