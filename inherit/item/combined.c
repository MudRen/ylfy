//combined_item.c

#include <dbase.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

static int amount;

void setup()
{
}

int query_amount()
{
	return amount;
}

void destruct_me()
{
	destruct(this_object());
}

void set_amount(int v)
{
	if( v < 0 )
		error("combine:set_amount less than 1.\n");
	
	if( v==0 ) 
	{
		//为了防止玩家在钱庄利用延时复制金钱！
		//将物件移走并destruct
		::move(VOID_OB);
		call_out("destruct_me", 1);
	}
	else
	{
		amount = v;
		this_object()->set_weight(v * (int)query("base_weight"));
	}
}

void add_amount(int v)
{
	set_amount(amount+v);
}

string short()
{
	return chinese_number(query_amount()) + query("base_unit") + ::short();
}

varargs int move(mixed dest, int silent)
{
	object env, *inv;
	int i, total;
	string file;

	if( ::move(dest, silent) )
	{
		env = environment();
		file = base_name(this_object());
		inv = all_inventory(env);
		total = (int)query_amount();
		for(i=0; i<sizeof(inv); i++)
		{
			if( inv[i]==this_object() )
				continue;

			// 跳过重量达到一定的物件防止溢出
			if ( inv[i]->weight() > 900000000 )
				continue;

			// 重量达到一定则跳出本次累算
			if ( this_object()->weight() > 900000000 )
				break;
			
			if( base_name(inv[i])==file )
			{
				total += (int)inv[i]->query_amount();
				destruct(inv[i]);
			}
		}
		
		set_amount(total);
		
		return 1;
	}
}