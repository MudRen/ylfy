inherit ITEM;
void create()
{
        set_name( "�컨��", ({ "honghua_ling"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
                set("long", "����һ�������͵����ƣ�����컨���������֣��Ǻ컨���������ϵ�����\n");
		set("value", 100000);
		set("material", "iron");
	}
	setup();
}
void init()
{
        call_out("dest", 1800);
}
void dest()
{
	destruct(this_object());
}
