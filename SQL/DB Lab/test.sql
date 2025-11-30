-- exp7
create trigger total
befor insert on sales
for each row
BEGIN

declare unit_price decimal(10,2);
declare category varchar(20);

select unit_price, category into unit_price, category
from item
where item_id = new.item_id;

if category = 'books' then set tax_rate = .10;
elseif category = 'stationary' then set tax_rate = .20;
elseif category = 'chocolate' then set tax_rate = .30;
else set tax_rate = .5;
end if;

set new.unit_price = unit_price;
set new.total_price = new.qty_sold * unit_price;
set new.tax_amount = new.total_price * tax_rate;
set new.grand_total = new.total_price + new.tax_amount;

end//
delimiter ;

create trigger stock
after insert on sales
for each row 
BEGIN

update item
set qty_on_hand = qty_on_hand - new.qty_sold
where item_id = new.item_id;

end//
delimiter ;

-- exp8
