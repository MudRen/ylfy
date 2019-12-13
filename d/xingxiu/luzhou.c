// Room: /d/xingxiu/luzhou.c
// Jay 3.25/96
inherit ROOM;
void create()
{
        set("short", "ɳĮ����");
        set("long", @LONG
��ɳĮ�ľ�ͷ������һ�����ޡ���ľ������һ�ۿ���������̨����һ
��ľ��(cup)ר���ڿʵ����˺�ˮ��������һ��ϵء�
LONG
        );
        set("resource/water", 1);
        set("exits", ([
                "northeast" :"/d/gaochang/huijiang2",
                "southwest" : __DIR__"nanjiang3",
        "south"     : "/d/npc/m_weapon/lianbianshi",
        ]));
        set("item_desc", ([
                "cup" :   "��ԥʲô����ľ��Ҩ��ˮ��(drink)ѽ��\n",
        ]));        set("objects", ([
            __DIR__"obj/donkey" : 1,
            __DIR__"obj/hamigua" : 2,
        ]));
        setup();
}
void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{
        int current_water;
    int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = me->max_water_capacity();
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"ſ�ڿ������ľ�̨����ľ��Ҩ��һ��ˮ�ȡ�\n"
            , environment(me), ({me}) );
            write("�����һ�ھ��д���ɽ������������ѩˮ����ֱ���ۻ���\n");
        }
        else write("���Ų�ҪǮ��ˮ����ô�ȣ�\n");
        return 1;
}
