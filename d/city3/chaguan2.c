//bye enter

inherit ROOM;

void create()
{
        set("short", "��ݶ�¥");
        set("long", @LONG
������������˶��Ǹ���֮ʿ,˵����������,�໥��̸
�Ÿ�������ĵá��ƿ�����,��ĿԶ��,�ɶ��������˵ķ��
�����۵�,����΢��,�����������,����һ���ϵȵ�"������"
����,����!
LONG
        );

        set("exits", ([
                "down" : __DIR__"chaguan",
        ]));
        set("objects", ([
                __DIR__"obj/chair" : 3,
        ]));

        setup();
        replace_program(ROOM);
}


