// salt.c
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
	set_name(HIW "��" NOR, ({ "illicit salt","salt" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","���������в���ȱ�ٵ�������Ʒ�������˰׻������Σ���·𿴵��˰׻��������ӣ�\n");
		set("unit", "Щ");
		set("base_unit", "��");
		set("base_weight", 1000);
		set("base_value", 100);
	}
	set_amount(1);
	setup();
	call_out("lost",30);
}
int lost()
{
	if (environment())
	if (environment()->is_character()){
		add_amount(-1);
		tell_object(environment(),"���"+this_object()->name()+"©��!\n");
		new(base_name(this_object()))->move(environment(environment()));
        }else{
          if (query_amount()>2)
                add_amount(-query_amount()/2);
          else
                add_amount(-1);
         }
	call_out("lost",30);
	return 1;
}
void init()
{
	object	room;

	room=environment();
	while (room){
		if (room->is_character()){
			room->set_temp("illicit",1);
			return;
		}
		room=environment(room);
	}
}