//bye enter

inherit ROOM;

void create()
{
        set("short", "Сͤ");
        set("long",@LONG
�����Ǹ��������µ�Сͤ�������ǵ��������ϲ������
��������������ϰϰ���ҿɸ�������������������գ�
LONG
        );

        set("exits", ([
                "southwest" : __DIR__"funanhe2",
            ]));
        setup();
        replace_program(ROOM);       
}


