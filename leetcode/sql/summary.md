**leetcode sql 题目总结**

176 第二高的薪水

```sql
-- 最大的去掉，剩下的就最大了
select max(Salary) as SecondHighestSalary  from Employee where Salary < (select max(Salary) from Employee);
-- 利用ifnull
# Write your MySQL query statement below
select ifnull((select distinct Salary  from Employee order by Salary desc limit 1,1),null) as SecondHighestSalary;
-- 子查询
# Write your MySQL query statement below
select (select distinct Salary  from Employee order by Salary desc limit 1,1) as SecondHighestSalary;
-- 为什么下面的不行
# Write your MySQL query statement below
select distinct ifnull(Salary,null) as SecondHighestSalary  from Employee order by Salary desc limit 1,1;
```

570 至少有5名直接下属的经理

```sql
-- 自连接
# Write your MySQL query statement below
select Name from Employee where Id in (select distinct ManagerId from Employee group by ManagerId having count(ManagerId) >= 5);
```

196 删除重复的电子邮箱

```sql
-- 利用自连接把不符合的直接删除即可
# Write your MySQL query statement below
delete p1 from Person p1,Person p2 WHERE p1.Email = p2.Email AND p1.Id > p2.Id;
```

184 部门中工资最高的员工

```sql
SELECT
    Department.name AS 'Department',
    Employee.name AS 'Employee',
    Salary
FROM
    Employee
        JOIN
    Department ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId , Salary) IN
    (   SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
	)
;
```

1322 广告效果

```sql
# Write your MySQL query statement below
SELECT ad_id AS 'ad_id', 
    ROUND(
         IFNULL(
             SUM(action='Clicked') / SUM(action IN ('Clicked', 'Viewed')) * 100
             , 0)
         , 2) 
        AS 'ctr'
FROM Ads
GROUP BY ad_id
ORDER BY ctr DESC, ad_id ASC 
;
```

182 查找重复的电子邮箱

```sql
# Write your MySQL query statement below
select Email from Person group by Email having count(Id) >= 2;
```

183 从不订购的用户

```sql
# Write your MySQL query statement below
select Name as Customers from Customers where Id not in(select c.Id from Customers c,Orders o where o.CustomerId = c.id);
```

177 第N高的薪水

```sql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  set N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT salary FROM employee ORDER BY salary DESC LIMIT N, 1
  );
END
```

619 只出现一次的最大数字

```sql
# Write your MySQL query statement below
select max(num) num from (select num from my_numbers group by num having count(num) = 1) t;
```

1667 修复表中的名字

```sql
# Write your MySQL query statement below
select user_id, concat(upper(left(name,1)),lower(substr(name,2))) as name from Users order by user_id;
```

574 当选者

```sql
# Write your MySQL query statement below
select Name from Candidate where id = (select CandidateId from Vote group by CandidateId order by count(CandidateId) desc limit 0,1);
```

595 大的国家

```sql
# Write your MySQL query statement below
select name,population, area from World where area >= 3000000 or population >= 25000000;
```

181 超过经理收入的员工

```sql
# Write your MySQL query statement below
select e.Name as Employee from Employee e,Employee ee where ee.id = e.ManagerId and e.Salary > ee.Salary;
```

180 连续出现的数字

```sql
SELECT DISTINCT
    l1.Num AS ConsecutiveNums
FROM
    Logs l1,
    Logs l2,
    Logs l3
WHERE
    l1.Id = l2.Id - 1
    AND l2.Id = l3.Id - 1
    AND l1.Num = l2.Num
    AND l2.Num = l3.Num
;
```

1853 转换日期格式

```sql
# Write your MySQL query statement below
select DATE_FORMAT(day,'%W, %M %e, %Y') as day from days;
```

175 组合两个表

```sql
# Write your MySQL query statement below
select FirstName,LastName,City,State from Person p left join Address ad on p.PersonId = ad.PersonId;
```

1015 合作过至少三次的演员和导演

```sql
# Write your MySQL query statement below
select actor_id,director_id from ActorDirector group by actor_id,director_id having count(*) >= 3;
```

1045 买下所有产品的用户

```sql
# Write your MySQL query statement below
select  Customer_id from Customer group by Customer_id 
having count(distinct(product_key)) = (select count(*) from product);
```

