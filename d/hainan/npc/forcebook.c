// literate.c

inherit ITEM;

void create()
{
        set_name("�����������", ({"jing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long", "һ���¾ɵ���װ�顣\n");
        set("material", "paper");
        set("skill", ([
                        "name": "bitao-shengong",
                        "exp_required": 1000,
                        "jing_cost": 100,
                        "difficulty": 100,
                        "max_skill": 120,
]) );
        }
}

