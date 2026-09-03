# Write your MySQL query statement below
SELECT a.query_name , 
ROUND(AVG(a.rating/a.position),2)as quality,
ROUND( AVG( 
    (SELECT COUNT(b.query_name) from Queries b WHERE rating<3 and a.query_name = b.query_name)
    / 
    (SELECT COUNT(c.query_name) from Queries c where c.query_name = a.query_name ) 
    ) *100 , 2) 
    as poor_query_percentage 
FROM Queries a 
GROUP BY query_name ;