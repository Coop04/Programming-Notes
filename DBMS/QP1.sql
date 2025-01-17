--  Event (eventid, name, description,city)
--  Participant (playerid, name, eventid, gender, year)
--  Prizes (prizeid, prize-money, eventid, rank,year)
--  Winners (prizeid, playerid)
--  1. Choose appropriate primary keys for each table.
--  2.  Choose foreign keys wherever needed.
--  3. Prize-money is of format  xxxx.xx  and maximum prize that can be awarded is 1500.00 and
--  minimum  prize awarded is 500.00
--  4. Names across all tables are inserted have their first character in capitals.
--  5. Playerid should contain at least one digit character.
--  6.  Event names cannot be repeated.
--  7. Rank can take any of these values only - 1, 2, 3.

--  QUESTIONS
--  4. Retrieve the names of the persons who have won the highest number of 1st, 2nd and 3rd 
-- prizes.
--  5. Retrieve the name of events where all prize winners are females.
--  6. Retrieve the name of the person who has won 1st prize of an event for maximum number 
-- of successive years. Give the event name also along with the name of the player and period 
-- for which he has won it. 
-- 7. Create a view to retrieve the names of all participants who won 1st prizes along with their 
-- event names.

create table Event(eventid int primary key,name varchar(50),description varchar(50),city varchar(50));

create table Participant(playerid int primary key,name varchar(50),eventid int,foreign key (eventid) references Event(eventid),gender enum('male','female'),year int);

create table Prizes(prizeid int primary key auto_increment,
eventid int,
foreign key (eventid) references Event(eventid),
rusk enum('1','2','3'),
year int,prize_money decimal(6,2) check (prize_money between 500.00 and 1500.00));

-- Insert values into the Event table
INSERT INTO Event (eventid, name, description, city) VALUES
(1, 'TechFest', 'Annual Tech Event', 'New York'),
(2, 'Hackathon', '24-Hour Coding Challenge', 'San Francisco'),
(3, 'ArtExhibit', 'Modern Art Showcase', 'Los Angeles'),
(4, 'MusicFest', 'Live Music Festival', 'Chicago');

-- Insert values into the Participant table
INSERT INTO Participant (playerid, name, eventid, gender, year) VALUES
(1, 'Alice Johnson', 1, 'female', 2023),
(2, 'Bob Smith', 2, 'male', 2023),
(3, 'Charlie Brown', 3, 'male', 2024),
(4, 'Diana Prince', 1, 'female', 2024),
(5, 'Evan Harris', 4, 'male', 2024);

-- Insert values into the Prizes table
INSERT INTO Prizes (prizeid, eventid, rusk, year, prize_money) VALUES
(1, 1, '1', 2023, 1000.00),
(2, 1, '2', 2023, 750.00),
(3, 2, '1', 2023, 1500.00),
(4, 3, '1', 2024, 1300.00),
(5, 4, '3', 2024, 500.00);

INSERT INTO Winners (prizeid, playerid) VALUES
(1, 1),  -- Alice Johnson won 1st prize in TechFest 2023
(2, 4),  -- Diana Prince won 2nd prize in TechFest 2023
(3, 2),  -- Bob Smith won 1st prize in Hackathon 2023
(4, 3),  -- Charlie Brown won 1st prize in ArtExhibit 2024
(5, 5),  -- Evan Harris won 3rd prize in MusicFest 2024
(6, 1);  -- Alice Johnson won 3rd prize in TechFest 2023

--  1. Retrieve the name of the person who has won the highest amount of prize.
select p.name from Participant p join Prizes pr on pr.eventid = p.eventid order by pr.prize_money desc limit 1;

--  2. Retrieve the name of the events which do not have 3 prize winners.
select e.name from Event e left join Prizes p on e.eventid = p.eventid group by e.name having count(p.rusk)<3;

--  3. Retrieve the name of all 2nd prize winners along with the event name.
-- select e.name,p.name 
-- from Event e 
-- join Participant p on e.eventid = p.eventid 
-- join Prizes pr on pr.eventid=p.eventid 
-- join Winners w on w.prizeid = pr.prizeid where pr.rusk = '2';

SELECT p.name, e.name AS event_name 
FROM Participant p
JOIN Winners w ON p.playerid = w.playerid
JOIN Prizes pr ON w.prizeid = pr.prizeid
JOIN Event e ON pr.eventid = e.eventid
WHERE pr.rank = '2';

--  9. Write a PL/SQL procedure for to insert names of all prize winners with the event and the 
-- rank into the relation Result using cursor.  



mysql> select * from Event ;
+---------+------------+--------------------------+---------------+
| eventid | name       | description              | city          |
+---------+------------+--------------------------+---------------+
|       1 | TechFest   | Annual Tech Event        | New York      |
|       2 | Hackathon  | 24-Hour Coding Challenge | San Francisco |
|       3 | ArtExhibit | Modern Art Showcase      | Los Angeles   |
|       4 | MusicFest  | Live Music Festival      | Chicago       |
+---------+------------+--------------------------+---------------+
4 rows in set (0.01 sec)

mysql> select * from Participant;  
+----------+---------------+---------+--------+------+
| playerid | name          | eventid | gender | year |
+----------+---------------+---------+--------+------+
|        1 | Alice Johnson |       1 | female | 2023 |
|        2 | Bob Smith     |       2 | male   | 2023 |
|        3 | Charlie Brown |       3 | male   | 2024 |
|        4 | Diana Prince  |       1 | female | 2024 |
|        5 | Evan Harris   |       4 | male   | 2024 |
+----------+---------------+---------+--------+------+
5 rows in set (0.00 sec)

mysql> select * from Prizes;
+---------+---------+------+------+-------------+
| prizeid | eventid | rusk | year | prize_money |
+---------+---------+------+------+-------------+
|       1 |       1 | 1    | 2023 |     1000.00 |
|       2 |       1 | 2    | 2023 |      750.00 |
|       3 |       2 | 1    | 2023 |     1500.00 |
|       4 |       3 | 1    | 2024 |     1300.00 |
|       5 |       4 | 3    | 2024 |      500.00 |
|       6 |       1 | 3    | 2023 |      500.00 |
+---------+---------+------+------+-------------+
5 rows in set (0.00 sec)

mysql> select * from Winners;
+---------+----------+
| prizeid | playerid |
+---------+----------+
|       1 |        1 |
|       6 |        1 |
|       3 |        2 |
|       4 |        3 |
|       2 |        4 |
|       5 |        5 |
+---------+----------+