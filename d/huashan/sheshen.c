// sheshen.c
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
    set("long", @LONG
����һ�μ�խ���յ�ɽ�£�����������ƣ�����Ԩ���޵ס��粻С��
��һʧ�����ȥ��ֻ������ͷ���Ҳ����������и�Сɽ��(dong)��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
      "northdown" : __DIR__"canglong",
      "east" : "/d/xiaoyao/pubu",
    ]));
    
    set("objects",([
              CLASS_D("huashan")+"/linghu":1,
    ]));
        set("item_desc",([
        "dong"  :   "һ���ڲ������Сɽ����\n",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "huashan" );
        setup();
}
void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}
int do_enter(string arg)
{
    object me;
    mapping fam;
    me = this_player();
    if( !arg || arg=="" ) return 0;
    if( arg=="dong" )
    {
        if( (fam = me->query("family")) && fam["family_name"] == "ؤ��" ) 
        {
            message("vision",
                me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��\n",
                environment(me), ({me}) );
            me->move("/d/gaibang/underhs");
                    message("vision",
                me->name() + "�Ӷ������˽�����\n",
                        environment(me), ({me}) );
            return 1;
        }
        else 
            return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
    }
}   
