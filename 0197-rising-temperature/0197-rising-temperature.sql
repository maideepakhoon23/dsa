# Write your MySQL query statement below
select w.id as id from Weather w join Weather p on datediff(w.recordDate,p.recordDate)=1 where w.temperature>p.temperature