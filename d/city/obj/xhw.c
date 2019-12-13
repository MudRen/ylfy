// xhw.c ������
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("������", ({"xiaohuawan", "wan"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���������۵������衣\n");
                set("unit", "��");
                set("value", 200);
                set("food_remaining", 1);
                set("food_supply", -100);
        }
}
void init()
{
          add_action("do_eat","eat");
}
int do_eat(string arg)
{
	if( !( environment())->is_character() ) return 0;
	if( !this_object()->id(arg) ) return notify_fail("��Ҫ��ʲô��\n");
	if( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if( (int)this_player()->query("food") < (int)this_player()->max_food_capacity() )
		return notify_fail("�����ڲ���Ҫ"+this_object()->name()+"��\n");
		message_vision("$N��" + name() + "�Եøɸɾ�����\n", this_player());
	this_player()->set("food", 0);
			destruct(this_object());
		return 1;
}
int query_autoload() { return 1; }