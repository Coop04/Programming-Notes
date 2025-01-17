--  Create the required tables and perform the following queries on it.
create table Book(bookid int primary key,title varchar(50),publishername varchar(50),authorname varchar(50));

create table Book_copies(
bookid int,foreign key(bookid) references Book(bookid),
branchid int, foreign key(branchid) references Library_branch(branchid),
noofcopies int);

create table Book_loans(
bookid int,foreign key(bookid) references Book(bookid),
branchid int, foreign key(branchid) references Library_branch(branchid),
cardno int,foreign key(cardno) references Borrower(cardno),
dateout date,
duedate date);

create table Library_branch(branchid int primary key,branchname varchar(50),address varchar(50));

create table Borrower(cardno int primary key,name varchar(50),address varchar(50),phone varchar(15));

--  a)List the details for all books whose title ends with ‘R’.
select * from Book where title like '%R';
--  b) How many copies of the book titled “DBMS” are owned by the library branch whose name
--  is “ABC”.
select noofcopies from Book b join Book_copies bc on b.bookid = bc.bookid join Library_branch l on bc.branchid = l.branchid where b.title = 'DBMS' and l.branchname = 'ABC';
--  c) Retrieve the names of all borrowers who do not have any books checked out .
select br.name from Borrower br left join Book_loans bl on br.cardno = bl.cardno where bl.cardno = null;
--  d) For each book whose DueDate is 11th October 2022, retrieve the book title, the borrower's 
-- name, and the borrower's address.
select b.title,br.name,br.address from Book b join Book_loans bl on b.bookid = bl.bookid join Borrower br on bl.cardno = br.cardno where bl.duedate = '2022-10-11';
--  e) For each library branch, retrieve the branch name and the total number of books loaned out
--  from that branch.
select lb.branchname,count(*) from Library_branch lb join Book_loan bl on lb.branchid = bl.branchid group by lb.branchname;
--  Consider the table Account(Customer name, account number, date_last transaction, amount).
--  f) Write a PL/SQL function that will retrieve the account details when account no is given as 
-- input.
delimiter //
create function retr(acc int)
returns varchar(100) deterministic
begin
declare name varchar(50);
declare ano varchar(50);
declare tdate date;
declare amo int;
declare msg varchar (100);
select Customer_name,account_number,date_last_transaction,amount into name,ano,tdate,amo from Account where account_number = acc;
set msg =concat(name,', ',ano,', ',tdate,', ',amo);
return msg;
end//
delimiter ;
--  g) Write a PL/SQL block to perform the following action on the table using cursor .
--  i)if the last transaction is not on the current month insert the records into the table inactive 
-- customer
--  ii)otherwise check the balance amount and display the interest amount
--  i)if the balance amount is less than 50000 interest rate is 5% of the amount
--  ii)if it is between 250000 and 5 Lakhs interest rate is 10%
--  iii)if the amount is greater than 5 lakh interest rate is 15%
