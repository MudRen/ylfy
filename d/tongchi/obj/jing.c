inherit ITEM;

void create()
{
        set_name( "��Ħ��",({ "damo jing","jing"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�����ش�Ħ�񹦵ľ��顣\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name":         "damo-force",      //name of the skill
                        "exp_required": 1000 ,        //minimum combat experience required
                        "jing_cost":    20+random(20),// jing cost every time study this
                        "difficulty":   20,           // the base int to learn this skill
                        "min_skill":    200,           // the minimum level you can learn
                        "max_skill":    500            // the maximum level you can learn
                ]) );
        }
}
