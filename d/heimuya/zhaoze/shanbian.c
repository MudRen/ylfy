// Room: /d/heimuya/zhaoze/shanbian.c
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
�����òʺ�󴫳�һ�������
    ֻ���������Ǹ���ɽ���򡱵�������
        �ǳؾ㻵��Ӣ�۰��ڣ�
        ���������ཻ����
        ����˥����Ϊ����
        �ƼҲ�����Ұܣ���̬�����Ʊ�ġ�
        ����Ҳ����ز�٣�Ҳ����ز
LONG
);
        set("exits", ([ 
  "north" : __DIR__"shanbian1",
  "west" : __DIR__"penquan",
]));
    set("objects", ([
        __DIR__"npc/jiaozi" : 1,
    ]));

        set("outdoors", "shanbian");

        setup();
}
int valid_leave(object me, string dir)
{
        object ob=present("jiao zi", environment(me));
        if (ob && living(ob) ){
            if ( ( present("hong juan",me) ) && dir == "north" ) {
                    say("���Ӷ�"+me->name()+"�ȵ�����������\n");
                    return notify_fail("���Ӻȵ�����λ" + RANK_D->query_respect(me) + "��ֹ����\n");
            }
        }
        return ::valid_leave(me, dir);
}

