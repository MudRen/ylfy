#include <ansi.h>
#include <room.h>

inherit ROOM;

int do_strike(string arg);

void create()
{
         set("short","���䳡");
         set ("long",@long
���������䳡��Ľ�ݼҵĵ��ӡ��Ҷ���������ϰ�书�������䳡��һ�ǣ�
��һ��ר�����������ľ׮(zhuang)�������Ӷ�Χ������������
long);
        set("exits",([
                "west" : __DIR__"yanziwu",
                "east" : __DIR__"jianfang",
        ]));
        set("item_desc", ([
                "zhuang" : "����һ��ľ׮���ܹ��������ֹ������������������һ�������\n",
        ]));
         set("objects",([
             __DIR__"npc/guanjia" : 1,
]));
        setup();
}

void init()
{
        add_action("do_strike", "strike");            
        add_action("do_strike","hit");
        add_action("do_strike","ji");
        add_action("do_strike","da");
}

int do_strike(string arg)
{
        object me;
        int jingcost, maxlevel, level;

        me = this_player();

        if ( !living(this_player()) || arg != "zhuang" )
                return 0;
        if ( (level = me->query_skill("parry", 1)) < 30 )
                return notify_fail("ƾ�����ڵ��мܹ����޷����ľ׮��������\n");
        maxlevel = 120;
        if (me->query("family/family_name")!="����Ľ��")
                maxlevel = 50;
        if (level >= maxlevel)
                return notify_fail("�����ľ׮���صش�������Ǵ��ľ׮�Ѿ��޷�ʹ��Ļ����м�����ˡ�\n");
        jingcost = level / 4 + random(level / 4);
        if (me->query("jing") <= jingcost) {
                write("��̫���ˣ��Ѿ�û����������ľ׮�ˣ�\n");
                return 1;
        }
        me->receive_damage("jing", jingcost);
        write("�����ľ׮���صش�������ö���Ļ����м������ٽ���\n");
        if (!random(5)) tell_room(this_object(),
                me->name() + "�������صػ���ľ׮��\n", ({ me }));
        me->improve_skill("parry", me->query("int"));       
        return 1;
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "����Ľ��") && dir == "east" &&
                objectp(present("guanjia", environment(me))))
           return notify_fail("�ܼҺȵ������Ǳ����صأ������Ҵ���\n");

        return ::valid_leave(me, dir);
}
