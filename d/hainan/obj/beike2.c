// beike2.c

inherit ITEM;

void create()
{
	set_name("��ʱ���", ({ "wucai beike","beike" }) );
	set_weight(10);
	if( !clonep() ) {
		set("unit", "��");
		set("value", 2000);
		set("long", 
"���Ǹ�Ư������ʱ��ǣ�Ӧ�ÿ���������Ǯ��\n");
	}
	setup();
}
