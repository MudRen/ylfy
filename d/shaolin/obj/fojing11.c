// fojing11.c
inherit ITEM;
string* titles = ({
    "������",
    "άĦ��",
    "������",
    "���Ͼ�",
});
void create()
{
     int i=random(sizeof(titles));
     string name=(string)titles[i];
    set_name(name, ({ "book" }));
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
            set("shaolin",1);
        set("long", "����һ��𾭡�\n");
        set("value", 500);
        set("material", "paper");
        set("skill", ([
            "name": "buddhism", // name of the skill
            "exp_required": 0,  // minimum combat experience required
            "jing_cost":    10, // jing cost every time study this
            "difficulty":   10, // the base int to learn this skill
            "max_skill":    50  // the maximum level you can learn
        ]) );
    }
}
int query_autoload() { return 1; }