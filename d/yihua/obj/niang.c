inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("�ٻ���", ({ "baihua niang","niang" }));
        set_weight(1000);
        if( clonep() )
          set_default_object(__FILE__);
        else {
        set("long",
            "����һ�빬���ðٻ�����ʮ��ʱ������İٻ���!\n");
        set("unit", "��");
        set("value", 0);
        set("food_supply", 60);
        set("max_liquid", 20);
        }
        set("liquid", ([
            "name" : "�ٻ���",
            "remaining" : 50,
       	    "type" : "water"
        ]) );
        set("liquid_type", "water");
        setup();
}
int query_autoload() { return 1; }