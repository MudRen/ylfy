// Room: /d/heimuya/zhaoze/pubupang.c
inherit ROOM;

void create()
{
        set("short", "�ٲ���");
        set("long", @LONG
ֻ���ٲ�������������һ�ˣ�ͷ�����ң��������£�����һ��ʯ�ϣ�
���Դ��������ٲ�ˮ���ļ��쳣��һк��ע��ˮ���������㣿��Ȼ���㣬
��������Ͼ�̶���
LONG
);
        set("exits", ([ 
  "southup" : __DIR__"shandian",
  "eastup" : __DIR__"lingding",
]));
    set("objects", ([
        __DIR__"npc/yuren" : 1,
    ]));

        set("outdoors", "pubupang");

        setup();
}
int valid_leave(object me, string dir)
{
        object ob=present("yu ren", environment(me));
        if (ob && living(ob) ){
            if (( present("hong juan",me) ) && dir == "southup" ) {
                    say("���˶�"+me->name()+"�ȵ�����������\n");
                    return notify_fail("���˺ȵ�����λ" + RANK_D->query_respect(me) + "��ֹ����\n");
            }
        }
        return ::valid_leave(me, dir);
}

