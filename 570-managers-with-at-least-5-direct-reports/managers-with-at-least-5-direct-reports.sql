# Write your MySQL query statement below

SELECT name 
FROM Employee
WHERE id IN(
SELECT managerId
from Employee
GROUP BY managerId
Having COUNT(*) >= 5);