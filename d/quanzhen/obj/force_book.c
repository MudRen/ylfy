// force_book.c �ڹ��ķ�

inherit ITEM;

void create()
{
	set_name("�������", ({ "book", "shu" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����װ�飬������������Ļ��˲��ٴ������ŵ����ơ�\n");
		set("material", "paper");
		set("skill", ([
			"name":	"force",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost":	30,	// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	150	// the maximum level you can learn
		]) );
	}
}
int query_autoload() { return 1; }