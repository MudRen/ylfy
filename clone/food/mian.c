// mian.c
inherit ITEM;
void create()
{
	set_name("��", ({ "mian" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ���������ڵ����档\n");
		set("unit", "��");
		set("value", 1000);
		set("remaining", 100);//ԭ����2
		set("food_supply", 250);
		set("water_supply", 100);//ԭ����10
        }
    setup();
}
void init()
{
	add_action("do_eat", "eat");
}
int do_eat(string arg)
{
object me = this_player();		
object ob;		
int food;
    if( !this_object()->id(arg) ) return 0;
if( !objectp(ob = present(arg, me)) )
return notify_fail("ʲô?\n");			
    if( this_player()->is_busy() )
        return notify_fail("����һ��������û����ɡ�\n");
    if(   (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
     return notify_fail("���Ѿ���̫���ˣ���Ҳ�Բ����ˡ�\n");
    set("value", 0);
food=(int)(this_player()->max_food_capacity()*2/3);
this_player()->add("food", food);
    if((int)this_player()->query("water") < (int)this_player()->max_water_capacity()-(int)query("water_supply"))
    this_player()->add("water", (int)query("water_supply"));
    if( this_player()->is_fighting() ) this_player()->start_busy(2);
    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N�������棬���̻��ʵس�������\n", this_player());
	} 
	else 
	{ 
   		 message_vision("$N������������ʣ�µ����������ˡ�\n",this_player());
   		 message_vision("$N��������һ�ӣ�Ĩ��Ĩ�죬�޵������㣡\n",this_player());
		destruct(this_object());
	}
	return 1;
}
int query_autoload() { return 1; }
