// qibook.c
inherit ITEM;
void create()
{
    set_name("���", ({ "bo juan", "bo", "juan" }));
    set_weight(50);
    set("no_drop", "�������������뿪�㡣\n");
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long",
            "����һ�����飬���ź������˵����������\n");
        set("value", 500);
        set("material", "silk");
        set("skill", ([
            "name": "force",    // name of the skill
            "exp_required": 0,  // minimum combat experience required
            "jing_cost":    10, // jing cost every time study this
            "difficulty":   20, // the base int to learn this skill
            "max_skill":    19  // the maximum level you can learn
        ]) );
    }
}
int query_autoload() { return 1; }