//bye enter

inherit ROOM;

void create()
{
        set("short", "����¥��¥");
        set("long",@LONG
����������¥�ϣ���ĿԶ���������ɶ������������۵͡�ֻ
�����Ϻ���������ƵĻ���ȫ�ǣ�̫�����ں��棬�������Ӱ��
�����Աߵ����������дУ�������Ҳ��ø�������������¥��
ǽ�Ͽ���ǰ������ī�����µ�ʫ�䡣
LONG
        );

        set("exits", ([
                "down" : __DIR__"wangjianglou1",
            ]));
        set("objects", ([
            __DIR__"npc/youke" : 2,
        ]));

        setup();
        replace_program(ROOM);       
}


