// sword_book.c



inherit ITEM;



void create()

{

          set_name("佻�����", ({ "sword book", "book" }));
	set_weight(600);

	if( clonep() )

		set_default_object(__FILE__);

	else {

		set("unit", "��");

                set("long", "����һ��佻����ɵĽ��ף���ķ����Ѿ������ˣ��������Ѿ������˺ܶ����ˡ�\n");
		set("value", 0);

		set("material", "paper");

		set("skill", ([

"name":                 "huanhua-jian",          

			"exp_required":	1000,			// minimum combat experience required

											// to learn this skill.

			"jing_cost":		20,				// jing cost every time study this

			"difficulty":	20,				// the base int to learn this skill

											// modify is jing_cost's (difficulty - int)*5%

                          "max_skill":    30                              // the maximum level you can learn
											// from this object.

		]) );

	}

}

