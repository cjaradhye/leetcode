select E.name
from Employee E
JOIN (
    select managerId from Employee 
    where managerId is not null
    group by managerId 
    having count(managerId)>=5) M
where E.id = M.managerId;