inherit ITEM;
void create()
{
    set_name( "��������", ({ "picture"}));
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "\n��������ѧϰ�����񽣵�ͼ�ס�\n");
        set("value", 1000);
        set("material", "paper");
        set("skill", ([
            "name": "liumai-shenjian",  // name of the skill
            "exp_required": 0,  // minimum combat experience required
            "jing_cost": 20+random(20),     // jing cost every time study this
            "difficulty":   40, // the base int to learn this skill
            "max_skill":    300,    // the maximum level you can learn
        ]) );
        set("no_drop", "�������������뿪�㡣\n");
                set("no_give", "�����������ܸ��ˡ�\n");
    }
}
int query_autoload() { return 1; }