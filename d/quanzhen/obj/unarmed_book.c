inherit ITEM;

void create()
{
	set_name( "����ȭ��", ({ "book","quan pu" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���ǿ���ȭ�ף����滭��һЩ�׷����ӵ���ʽ���������š�\n");
		set("material", "paper");
		set("skill", ([
                        "name": "kongming-quan", 
			"exp_required":	10000,	// minimum combat experience required
			"jing_cost": 25, 	// jing cost every time study this
			"difficulty":	40,	// the base int to learn this skill
			"max_skill":	150,	// the maximum level you can learn
		]) );
	}
}
int query_autoload() { return 1; }
