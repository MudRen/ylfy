inherit ITEM;

void create()
{
	set_name("����", ({ "hailuo" }) );
	set_weight(10);
	if( !clonep() ) {
		set("unit", "��");
		set("value", 100);
		set("long", 
"���е�һ�б��ද��,�ں�̲�ϳ��ܼ�����\n");
	}
	setup();
}
