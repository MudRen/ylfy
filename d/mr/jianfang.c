#include <room.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������Ľ�ݼ���������⣬Ľ�ݼ�Ϊ���˸����࣬���ѴӸ�������
������׼����
LONG
        );
        set("no_sleep_room","1");

        set("exits",([
            "west" : __DIR__"wuchang",
]));
        set("objects",([
                "/clone/weapon/changjian":3,
                "/clone/weapon/gangdao":3,
                "/clone/cloth/junfu":3,
            ]));
       setup();

}
 
int valid_leave(object me, string dir)
{
        if ( present("jian 2",me) || present("blade 2",me) || present("junfu 2",me) || (present("jian",me) && present("blade",me)))
        {
        write("����ô�������ȥ����̫�ðɣ�\n");
        return notify_fail("");
        }
        if (me->query_temp("mark/bingqi") && (present("jian",me) || present("blade",me) || present("junfu",me)))
        {
          return notify_fail("�������һ�ѱ�����ȥ����ô����һ�ѣ�̫̰���˰ɡ�\n");
        }
        me->set_temp("mark/bingqi",1);
        call_out("del_tmp",1800,me);
        return ::valid_leave(me, dir);
}

void del_tmp(object me)
{
        if ( objectp(me) ) me->delete_temp("mark/bingqi");
}