// Room: /d/emei/shanmen.c ������ ɽ��
// create by host dec,12

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "������");
    set("long", @LONG
����������һ���ü�ʵʯ���̳ɵĿ��ʯ�ף����߽���ʯ����ƾ�����ͣ�
ңң���������Ҿ�����ѭʯ�׶��ϣ���ʯ����һ��޴����ʯ���������
����ʯ���������������顰�����صأ��������롱��
LONG
    );

    set("exits", ([
        "northdown":__DIR__"shijie3",
        "southup": __DIR__"jinding",
    ]));

    set("outdoors", "emei");
    set("objects",([
          CLASS_D("emei") + "/jingfeng" : 1,
    ]));
    setup();
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    myfam = (mapping)me->query("family");

    if ((!myfam || myfam["family_name"] != "������") && dir == "southup") {
        if(objectp(present("jing feng", environment(me))))
            return notify_fail("����˫�ֺ�ʮ��������ס��˵���������Ƕ������صأ�ʩ��������ذɡ�\n");
    }

    return ::valid_leave(me, dir);
}
