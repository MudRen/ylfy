//bye enter

inherit ROOM;

void create()
{
        set("short", "ʯ����");
        set("long",@LONG
�����ֵ���ʾ���츮֮�����ֶ��ؽ��еķ��԰��
�ε�С�ź���ݹ�ɶ��ĸ��Ϻӡ����µ���ˮ����ƼȾ��
���˵Ĵ��̡�ż��һ��ֻ���ۻ����������źӱߵ���ź��
�������������Ϳ��Ե��ϴ���ˡ� 
LONG
        );

        set("outdoors", "/d/chengdu");

        set("exits", ([
                "west" : __DIR__"nanjie",
                "northeast" : __DIR__"funanhe3",
            ]));
        setup();
        replace_program(ROOM);       
}


