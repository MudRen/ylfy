// forcebook.c

inherit ITEM;

void create()
{
	set_name( "�ڹ�����", ({ "force book", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ڹ����ţ���������ų�ǳ���ڹ��ķ���\n");
		set("value", 5000);
		set("material", "paper");
		set("skill", ([
			"name":	"force",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"jing_cost": 20, 	// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	30,	// the maximum level you can learn
		]) );
	}
}
int query_autoload() { return 1; }