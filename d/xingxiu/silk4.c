// /d/xingxiu/silk4.c
// Jay 3/17/96
inherit ROOM;
void create()
{
        set("short", "˿��֮·");
          set("long", @LONG
����һ����ԭ������֮����̵���������һ���޼ʵĴ�ɳĮ��
��˵���ﳣ�е��˳�û��������ͨ��һƬ�����ɽ�����������ͨ
����ԭ��·��·����һ��ʯ��(shibei)��ʯ������һ����(hole)��
LONG );
        set("outdoors", "xingxiuhai");
        set("exits", ([
                "east" : __DIR__"silk3",
                "west" : __DIR__"shamo1",
                "northwest" : __DIR__"shanjiao",
                "southwest" : "/d/xueshan/caoyuan" ,
        ]));
        set("item_desc", ([
                "shibei" : "�������򣬶�����ԭ��˭�����У���ɱ���ۡ�����ɽ��������\n",
        ]));
        setup();
}
void init()
{
        add_action("do_push", "enter");
}
int valid_leave(object me, string dir)
{
    if ((dir == "west")&& !userp(me)) return 0;
    return 1;
}
int do_push(string arg)
{
    object me;
    mapping fam;
    me = this_player();
    if( !arg || arg=="" ) return 0;
    if( arg=="hole" )
    {
        if( (fam = me->query("family")) && fam["family_name"] == "ؤ��" ) 
        {
            message_vision("$N����ؤ�����ǹ���һ�������������˽�ȥ��\n",me );
            me->move("/d/gaibang/underxx");
                    message("vision",me->name() + "�Ӷ������˽�����\n",
                        environment(me), ({me}) );
            return 1;
        }
        else 
            return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
    }
    return 0;
}   
